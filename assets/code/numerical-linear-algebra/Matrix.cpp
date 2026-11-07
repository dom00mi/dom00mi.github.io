#include "numerics/Matrix.hpp"

#include <cmath>
#include <stdexcept>

namespace numerics {

Matrix::Matrix(std::size_t rows, std::size_t columns, double initial)
    : rows_(rows), columns_(columns), values_(rows * columns, initial) {
    if (rows == 0 || columns == 0) {
        throw std::invalid_argument("matrix dimensions must be positive");
    }
}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> rows)
    : rows_(rows.size()), columns_(rows.size() ? rows.begin()->size() : 0) {
    if (rows_ == 0 || columns_ == 0) {
        throw std::invalid_argument("matrix cannot be empty");
    }
    values_.reserve(rows_ * columns_);
    for (const auto& row : rows) {
        if (row.size() != columns_) {
            throw std::invalid_argument("all matrix rows must have equal lengths");
        }
        values_.insert(values_.end(), row.begin(), row.end());
    }
}

double& Matrix::operator()(std::size_t row, std::size_t column) {
    if (row >= rows_ || column >= columns_) {
        throw std::out_of_range("matrix index out of range");
    }
    return values_[row * columns_ + column];
}

double Matrix::operator()(std::size_t row, std::size_t column) const {
    if (row >= rows_ || column >= columns_) {
        throw std::out_of_range("matrix index out of range");
    }
    return values_[row * columns_ + column];
}

Matrix Matrix::identity(std::size_t dimension) {
    Matrix result(dimension, dimension);
    for (std::size_t i = 0; i < dimension; ++i) {
        result(i, i) = 1.0;
    }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(columns_, rows_);
    for (std::size_t i = 0; i < rows_; ++i) {
        for (std::size_t j = 0; j < columns_; ++j) {
            result(j, i) = (*this)(i, j);
        }
    }
    return result;
}

Matrix operator*(const Matrix& left, const Matrix& right) {
    if (left.columns() != right.rows()) {
        throw std::invalid_argument("incompatible matrix multiplication dimensions");
    }
    Matrix result(left.rows(), right.columns());
    for (std::size_t i = 0; i < left.rows(); ++i) {
        for (std::size_t k = 0; k < left.columns(); ++k) {
            const double value = left(i, k);
            for (std::size_t j = 0; j < right.columns(); ++j) {
                result(i, j) += value * right(k, j);
            }
        }
    }
    return result;
}

Vector operator*(const Matrix& matrix, const Vector& vector) {
    if (matrix.columns() != vector.size()) {
        throw std::invalid_argument("incompatible matrix-vector dimensions");
    }
    Vector result(matrix.rows(), 0.0);
    for (std::size_t i = 0; i < matrix.rows(); ++i) {
        for (std::size_t j = 0; j < matrix.columns(); ++j) {
            result[i] += matrix(i, j) * vector[j];
        }
    }
    return result;
}

double dot(const Vector& left, const Vector& right) {
    if (left.size() != right.size()) {
        throw std::invalid_argument("dot product vectors must have equal size");
    }
    double result = 0.0;
    for (std::size_t i = 0; i < left.size(); ++i) {
        result += left[i] * right[i];
    }
    return result;
}

double norm2(const Vector& vector) { return std::sqrt(dot(vector, vector)); }

}  // namespace numerics
