#include "numerics/Sparse.hpp"

#include <algorithm>
#include <cmath>
#include <ostream>
#include <stdexcept>
#include <utility>

namespace numerics {

SparseVector::SparseVector(std::size_t dimension) : dimension_(dimension) {
    if (dimension == 0) {
        throw std::invalid_argument("sparse vector dimension must be positive");
    }
}

double SparseVector::at(std::size_t index) const {
    if (index >= dimension_) {
        throw std::out_of_range("sparse vector index out of range");
    }
    const auto entry = entries_.find(index);
    return entry == entries_.end() ? 0.0 : entry->second;
}

void SparseVector::set(std::size_t index, double value) {
    if (index >= dimension_) {
        throw std::out_of_range("sparse vector index out of range");
    }
    if (!std::isfinite(value)) {
        throw std::invalid_argument("sparse vector entry must be finite");
    }
    if (value == 0.0) {
        entries_.erase(index);
    } else {
        entries_[index] = value;
    }
}

Vector SparseVector::dense() const {
    Vector result(dimension_, 0.0);
    for (const auto& [index, value] : entries_) {
        result[index] = value;
    }
    return result;
}

void SparseVector::remove_zeros() {
    for (auto it = entries_.begin(); it != entries_.end();) {
        if (it->second == 0.0) {
            it = entries_.erase(it);
        } else {
            ++it;
        }
    }
}

SparseVector& SparseVector::operator+=(const SparseVector& other) {
    if (dimension_ != other.dimension_) {
        throw std::invalid_argument("sparse vector dimensions must agree");
    }
    for (const auto& [index, value] : other.entries_) {
        entries_[index] += value;
    }
    remove_zeros();
    return *this;
}

SparseVector& SparseVector::operator-=(const SparseVector& other) {
    if (dimension_ != other.dimension_) {
        throw std::invalid_argument("sparse vector dimensions must agree");
    }
    if (this == &other) {
        entries_.clear();
    } else {
        for (const auto& [index, value] : other.entries_) {
            entries_[index] -= value;
        }
        remove_zeros();
    }
    return *this;
}

SparseVector& SparseVector::operator*=(double scalar) {
    if (!std::isfinite(scalar)) {
        throw std::invalid_argument("scalar must be finite");
    }
    if (scalar == 0.0) {
        entries_.clear();
    } else {
        for (auto& [index, value] : entries_) {
            (void)index;
            value *= scalar;
        }
        remove_zeros();
    }
    return *this;
}

SparseVector operator+(SparseVector left, const SparseVector& right) { return left += right; }

SparseVector operator-(SparseVector left, const SparseVector& right) { return left -= right; }

SparseVector operator*(SparseVector vector, double scalar) { return vector *= scalar; }

SparseVector operator*(double scalar, SparseVector vector) { return vector *= scalar; }

std::ostream& operator<<(std::ostream& out, const SparseVector& vector) {
    out << '{';
    bool first = true;
    for (const auto& [index, value] : vector.entries_) {
        if (!first) out << ", ";
        out << index << ": " << value;
        first = false;
    }
    return out << '}';
}

CSRMatrix::CSRMatrix(std::size_t rows, std::size_t columns, std::vector<Triplet> entries)
    : rows_(rows), columns_(columns), row_offsets_(rows + 1, 0) {
    if (rows == 0 || columns == 0) {
        throw std::invalid_argument("CSR matrix dimensions must be positive");
    }
    for (const auto& item : entries) {
        if (item.row >= rows || item.column >= columns || !std::isfinite(item.value)) {
            throw std::invalid_argument("CSR triplet has invalid index or value");
        }
    }
    std::sort(entries.begin(), entries.end(), [](const Triplet& left, const Triplet& right) {
        return left.row < right.row || (left.row == right.row && left.column < right.column);
    });

    std::size_t index = 0;
    for (std::size_t row = 0; row < rows_; ++row) {
        while (index < entries.size() && entries[index].row == row) {
            const std::size_t column = entries[index].column;
            double sum = 0.0;
            while (index < entries.size() && entries[index].row == row &&
                   entries[index].column == column) {
                sum += entries[index++].value;
            }
            if (sum != 0.0) {
                column_indices_.push_back(column);
                values_.push_back(sum);
            }
        }
        row_offsets_[row + 1] = values_.size();
    }
}

Vector CSRMatrix::multiply(const Vector& vector) const {
    if (vector.size() != columns_) {
        throw std::invalid_argument("CSR matrix-vector dimensions do not agree");
    }
    Vector result(rows_, 0.0);
    for (std::size_t row = 0; row < rows_; ++row) {
        for (std::size_t k = row_offsets_[row]; k < row_offsets_[row + 1]; ++k) {
            result[row] += values_[k] * vector[column_indices_[k]];
        }
    }
    return result;
}

double CSRMatrix::at(std::size_t row, std::size_t column) const {
    if (row >= rows_ || column >= columns_) {
        throw std::out_of_range("CSR index out of range");
    }
    const auto first = column_indices_.begin() + static_cast<std::ptrdiff_t>(row_offsets_[row]);
    const auto last = column_indices_.begin() + static_cast<std::ptrdiff_t>(row_offsets_[row + 1]);
    const auto found = std::lower_bound(first, last, column);
    if (found == last || *found != column) return 0.0;
    return values_[static_cast<std::size_t>(found - column_indices_.begin())];
}

IterativeResult conjugate_gradient(const CSRMatrix& matrix, const Vector& rhs, double tolerance,
                                   std::size_t max_iterations) {
    if (matrix.rows() != matrix.columns() || rhs.size() != matrix.rows()) {
        throw std::invalid_argument("CG requires a square matrix matching rhs size");
    }
    if (!std::isfinite(tolerance) || tolerance <= 0.0 || max_iterations == 0) {
        throw std::invalid_argument("CG tolerance and iteration limit must be positive");
    }

    Vector x(rhs.size(), 0.0), r = rhs, p = r;
    double residual_squared = dot(r, r);
    const double threshold = tolerance * std::max(1.0, norm2(rhs));
    if (std::sqrt(residual_squared) <= threshold) {
        return {x, 0, std::sqrt(residual_squared), true};
    }

    for (std::size_t iteration = 0; iteration < max_iterations; ++iteration) {
        const Vector ap = matrix.multiply(p);
        const double denominator = dot(p, ap);
        if (denominator <= 0.0 || !std::isfinite(denominator)) {
            throw std::domain_error("CG requires a symmetric positive-definite matrix");
        }
        const double alpha = residual_squared / denominator;
        for (std::size_t i = 0; i < x.size(); ++i) {
            x[i] += alpha * p[i];
            r[i] -= alpha * ap[i];
        }
        const double next_squared = dot(r, r);
        const double residual = std::sqrt(next_squared);
        if (residual <= threshold) {
            return {std::move(x), iteration + 1, residual, true};
        }
        const double beta = next_squared / residual_squared;
        for (std::size_t i = 0; i < p.size(); ++i) {
            p[i] = r[i] + beta * p[i];
        }
        residual_squared = next_squared;
    }
    return {std::move(x), max_iterations, std::sqrt(residual_squared), false};
}

}
