#include "numerics/Decompositions.hpp"

#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <stdexcept>
#include <utility>

namespace numerics {
namespace {

void require_square(const Matrix& matrix) {
    if (matrix.rows() != matrix.columns()) {
        throw std::invalid_argument("matrix must be square");
    }
}

double max_magnitude(const Matrix& matrix) {
    double scale = 0.0;
    for (std::size_t i = 0; i < matrix.rows(); ++i) {
        for (std::size_t j = 0; j < matrix.columns(); ++j) {
            if (!std::isfinite(matrix(i, j))) {
                throw std::invalid_argument("matrix entries must be finite");
            }
            scale = std::max(scale, std::abs(matrix(i, j)));
        }
    }
    return scale;
}

}  // namespace

LUFactorization lu_factorize(const Matrix& matrix) {
    require_square(matrix);
    Matrix lu = matrix;
    const std::size_t n = lu.rows();
    const double threshold = 1e-14 * max_magnitude(lu);
    std::vector<std::size_t> permutation(n);
    std::iota(permutation.begin(), permutation.end(), 0);

    for (std::size_t k = 0; k < n; ++k) {
        std::size_t pivot = k;
        for (std::size_t i = k + 1; i < n; ++i) {
            if (std::abs(lu(i, k)) > std::abs(lu(pivot, k))) {
                pivot = i;
            }
        }
        if (std::abs(lu(pivot, k)) <= threshold) {
            throw std::domain_error("singular or numerically rank-deficient matrix");
        }
        if (pivot != k) {
            for (std::size_t j = 0; j < n; ++j) {
                std::swap(lu(k, j), lu(pivot, j));
            }
            std::swap(permutation[k], permutation[pivot]);
        }
        for (std::size_t i = k + 1; i < n; ++i) {
            lu(i, k) /= lu(k, k);
            for (std::size_t j = k + 1; j < n; ++j) {
                lu(i, j) -= lu(i, k) * lu(k, j);
            }
        }
    }
    return {std::move(lu), std::move(permutation)};
}

Vector lu_solve(const LUFactorization& factorization, const Vector& rhs) {
    const Matrix& lu = factorization.combined;
    require_square(lu);
    const std::size_t n = lu.rows();
    if (rhs.size() != n || factorization.permutation.size() != n) {
        throw std::invalid_argument("LU and right-hand-side sizes do not match");
    }
    Vector y(n), x(n);
    for (std::size_t i = 0; i < n; ++i) {
        if (factorization.permutation[i] >= n) {
            throw std::invalid_argument("invalid LU permutation");
        }
        y[i] = rhs[factorization.permutation[i]];
        for (std::size_t j = 0; j < i; ++j) {
            y[i] -= lu(i, j) * y[j];
        }
    }
    for (std::size_t i = n; i-- > 0;) {
        double sum = y[i];
        for (std::size_t j = i + 1; j < n; ++j) {
            sum -= lu(i, j) * x[j];
        }
        x[i] = sum / lu(i, i);
    }
    return x;
}

Matrix cholesky(const Matrix& matrix) {
    require_square(matrix);
    const std::size_t n = matrix.rows();
    const double scale = max_magnitude(matrix);
    if (scale == 0.0) {
        throw std::domain_error("matrix is not positive definite");
    }
    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = 0; j < i; ++j) {
            if (std::abs(matrix(i, j) - matrix(j, i)) > 1e-12 * scale) {
                throw std::invalid_argument("Cholesky requires a symmetric matrix");
            }
        }
    }

    Matrix lower(n, n);
    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = 0; j <= i; ++j) {
            double value = matrix(i, j);
            for (std::size_t k = 0; k < j; ++k) {
                value -= lower(i, k) * lower(j, k);
            }
            if (i == j) {
                if (value <= 1e-14 * scale) {
                    throw std::domain_error("matrix is not positive definite");
                }
                lower(i, j) = std::sqrt(value);
            } else {
                lower(i, j) = value / lower(j, j);
            }
        }
    }
    return lower;
}

Vector cholesky_solve(const Matrix& lower, const Vector& rhs) {
    require_square(lower);
    const std::size_t n = lower.rows();
    if (rhs.size() != n) {
        throw std::invalid_argument("Cholesky and right-hand-side sizes do not match");
    }
    Vector y(n), x(n);
    for (std::size_t i = 0; i < n; ++i) {
        double sum = rhs[i];
        for (std::size_t j = 0; j < i; ++j) {
            sum -= lower(i, j) * y[j];
        }
        if (lower(i, i) <= 0.0) {
            throw std::domain_error("invalid Cholesky diagonal");
        }
        y[i] = sum / lower(i, i);
    }
    for (std::size_t i = n; i-- > 0;) {
        double sum = y[i];
        for (std::size_t j = i + 1; j < n; ++j) {
            sum -= lower(j, i) * x[j];
        }
        x[i] = sum / lower(i, i);
    }
    return x;
}

QRFactorization householder_qr(const Matrix& matrix) {
    if (matrix.rows() < matrix.columns()) {
        throw std::invalid_argument("Householder QR requires rows >= columns");
    }
    max_magnitude(matrix);  // Validate all entries.
    const std::size_t m = matrix.rows();
    const std::size_t n = matrix.columns();
    Matrix q = Matrix::identity(m);
    Matrix r = matrix;

    for (std::size_t k = 0; k < n; ++k) {
        Vector v(m - k);
        for (std::size_t i = k; i < m; ++i) {
            v[i - k] = r(i, k);
        }
        const double length = norm2(v);
        if (length == 0.0) {
            continue;
        }
        v[0] += std::copysign(length, v[0]);
        const double v_norm = norm2(v);
        for (double& item : v) {
            item /= v_norm;
        }

        // R <- H R, where H = I - 2*v*v^T.
        for (std::size_t j = k; j < n; ++j) {
            double projection = 0.0;
            for (std::size_t i = k; i < m; ++i) {
                projection += v[i - k] * r(i, j);
            }
            for (std::size_t i = k; i < m; ++i) {
                r(i, j) -= 2.0 * v[i - k] * projection;
            }
        }
        // Q <- Q H, accumulating the orthogonal factor.
        for (std::size_t i = 0; i < m; ++i) {
            double projection = 0.0;
            for (std::size_t j = k; j < m; ++j) {
                projection += q(i, j) * v[j - k];
            }
            for (std::size_t j = k; j < m; ++j) {
                q(i, j) -= 2.0 * projection * v[j - k];
            }
        }
    }
    return {std::move(q), std::move(r)};
}

Vector qr_least_squares(const Matrix& matrix, const Vector& rhs) {
    if (rhs.size() != matrix.rows()) {
        throw std::invalid_argument("least-squares right-hand-side size mismatch");
    }
    const QRFactorization qr = householder_qr(matrix);
    const std::size_t n = matrix.columns();
    const Vector projected = qr.q.transpose() * rhs;
    double scale = 0.0;
    for (std::size_t i = 0; i < n; ++i) {
        scale = std::max(scale, std::abs(qr.r(i, i)));
    }
    if (scale == 0.0) {
        throw std::domain_error("least-squares matrix is rank deficient");
    }

    Vector x(n);
    for (std::size_t i = n; i-- > 0;) {
        if (std::abs(qr.r(i, i)) <= 1e-12 * scale) {
            throw std::domain_error("least-squares matrix is rank deficient");
        }
        double sum = projected[i];
        for (std::size_t j = i + 1; j < n; ++j) {
            sum -= qr.r(i, j) * x[j];
        }
        x[i] = sum / qr.r(i, i);
    }
    return x;
}

}  // namespace numerics
