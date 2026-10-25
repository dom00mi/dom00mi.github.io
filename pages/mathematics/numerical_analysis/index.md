---
layout: default
title: "Numerical Analysis"
permalink: /pages/mathematics/numerical_analysis/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/' | relative_url }}">Back to Mathematics</a>
  <div class="eyebrow">Mathematics / Numerical Analysis</div>
  <h1>Numerical Analysis</h1>
  <p class="lead">A structured introduction to numerical algorithms, approximation, error analysis, numerical linear algebra, and ODE solvers.</p>
</div>

<article class="article" markdown="1">

## Course structure

### Chapter 1 - Foundations of Numerical Analysis

- [1.1: Introduction to Numerical Algorithms]({{ '/pages/mathematics/numerical_analysis/01-foundations-of-numerical-analysis/01-introduction-to-numerical-algorithms/' | relative_url }})
- [1.2: Numbers and Computer Representation]({{ '/pages/mathematics/numerical_analysis/01-foundations-of-numerical-analysis/02-numbers-and-computer-representation/' | relative_url }})
- [1.3: Floating-Point Arithmetic and Roundoff Errors]({{ '/pages/mathematics/numerical_analysis/01-foundations-of-numerical-analysis/03-floating-point-arithmetic-and-roundoff-errors/' | relative_url }})
- [1.4: Error Analysis, Stability, and Conditioning]({{ '/pages/mathematics/numerical_analysis/01-foundations-of-numerical-analysis/04-error-analysis-stability-and-conditioning/' | relative_url }})

### Chapter 2 - Fixed-Point Methods and Convergence

- [2.1: Heron's Algorithm and Fixed-Point Iterations]({{ '/pages/mathematics/numerical_analysis/02-fixed-point-methods-and-convergence/01-herons-algorithm-and-fixed-point-iterations/' | relative_url }})
- [2.2: Contraction Mappings and Banach Fixed-Point Theorem]({{ '/pages/mathematics/numerical_analysis/02-fixed-point-methods-and-convergence/02-contraction-mappings-and-banach-fixed-point-theorem/' | relative_url }})
- [2.3: Rates of Convergence and Error Estimates]({{ '/pages/mathematics/numerical_analysis/02-fixed-point-methods-and-convergence/03-rates-of-convergence-and-error-estimates/' | relative_url }})

### Chapter 3 - Numerical Root-Finding Methods

- [3.1: Bisection Method and Intermediate Value Theorem]({{ '/pages/mathematics/numerical_analysis/03-numerical-root-finding-methods/01-bisection-method-and-intermediate-value-theorem/' | relative_url }})
- [3.2: Newton's Method and Local Convergence]({{ '/pages/mathematics/numerical_analysis/03-numerical-root-finding-methods/02-newtons-method-and-local-convergence/' | relative_url }})
- [3.3: Variants of Newton's Method]({{ '/pages/mathematics/numerical_analysis/03-numerical-root-finding-methods/03-variants-of-newtons-method/' | relative_url }})

### Chapter 4 - Polynomial Interpolation and Approximation

- [4.1: Polynomial Approximation and Taylor Polynomials]({{ '/pages/mathematics/numerical_analysis/04-polynomial-interpolation-and-approximation/01-polynomial-approximation-and-taylor-polynomials/' | relative_url }})
- [4.2: Lagrange Interpolation and Vandermonde Matrices]({{ '/pages/mathematics/numerical_analysis/04-polynomial-interpolation-and-approximation/02-lagrange-interpolation-and-vandermonde-matrices/' | relative_url }})
- [4.3: Newton's Divided Differences]({{ '/pages/mathematics/numerical_analysis/04-polynomial-interpolation-and-approximation/03-newtons-divided-differences/' | relative_url }})
- [4.4: Interpolation Errors and Best Approximation]({{ '/pages/mathematics/numerical_analysis/04-polynomial-interpolation-and-approximation/04-interpolation-errors-and-best-approximation/' | relative_url }})

### Chapter 5 - Numerical Integration and Quadrature

- [5.1: Midpoint, Trapezoidal, and Simpson's Rules]({{ '/pages/mathematics/numerical_analysis/05-numerical-integration-and-quadrature/01-midpoint-trapezoidal-and-simpsons-rules/' | relative_url }})
- [5.2: Gaussian Quadrature]({{ '/pages/mathematics/numerical_analysis/05-numerical-integration-and-quadrature/02-gaussian-quadrature/' | relative_url }})
- [5.3: Composite Quadrature Formulas]({{ '/pages/mathematics/numerical_analysis/05-numerical-integration-and-quadrature/03-composite-quadrature-formulas/' | relative_url }})
- [5.4: Quadrature Error Analysis and Improper Integrals]({{ '/pages/mathematics/numerical_analysis/05-numerical-integration-and-quadrature/04-quadrature-error-analysis-and-improper-integrals/' | relative_url }})

### Chapter 6 - Foundations of Numerical Linear Algebra

- [6.1: Matrix Preliminaries and Blockwise Algebra]({{ '/pages/mathematics/numerical_analysis/06-foundations-of-numerical-linear-algebra/01-matrix-preliminaries-and-blockwise-algebra/' | relative_url }})
- [6.2: Triangular Matrices and Triangular Systems]({{ '/pages/mathematics/numerical_analysis/06-foundations-of-numerical-linear-algebra/02-triangular-matrices-and-triangular-systems/' | relative_url }})
- [6.3: Matrix Norms, Conditioning, and Orthogonality]({{ '/pages/mathematics/numerical_analysis/06-foundations-of-numerical-linear-algebra/03-matrix-norms-conditioning-and-orthogonality/' | relative_url }})
- [6.4: Self-Adjoint SPD Matrices and Spectral Theorem]({{ '/pages/mathematics/numerical_analysis/06-foundations-of-numerical-linear-algebra/04-self-adjoint-spd-matrices-and-spectral-theorem/' | relative_url }})

### Chapter 7 - Matrix Factorizations and Direct Methods

- [7.1: Gaussian Elimination]({{ '/pages/mathematics/numerical_analysis/07-matrix-factorizations-and-direct-methods/01-gaussian-elimination/' | relative_url }})
- [7.2: LU, LDU, and PLU Factorizations]({{ '/pages/mathematics/numerical_analysis/07-matrix-factorizations-and-direct-methods/02-lu-ldu-and-plu-factorizations/' | relative_url }})
- [7.3: Cholesky Factorization]({{ '/pages/mathematics/numerical_analysis/07-matrix-factorizations-and-direct-methods/03-cholesky-factorization/' | relative_url }})
- [7.4: QR and Schur Factorizations]({{ '/pages/mathematics/numerical_analysis/07-matrix-factorizations-and-direct-methods/04-qr-and-schur-factorizations/' | relative_url }})

### Chapter 8 - Iterative Methods for Linear Systems

- [8.1: Fixed-Point Formulation of Linear Systems]({{ '/pages/mathematics/numerical_analysis/08-iterative-methods-for-linear-systems/01-fixed-point-formulation-of-linear-systems/' | relative_url }})
- [8.2: Jacobi and Gauss-Seidel Methods]({{ '/pages/mathematics/numerical_analysis/08-iterative-methods-for-linear-systems/02-jacobi-and-gauss-seidel-methods/' | relative_url }})
- [8.3: Convergence and Iterative Refinement]({{ '/pages/mathematics/numerical_analysis/08-iterative-methods-for-linear-systems/03-convergence-and-iterative-refinement/' | relative_url }})

### Chapter 9 - Numerical Methods for ODEs

- [9.1: Initial Value Problems and Picard-Lindelof Theorem]({{ '/pages/mathematics/numerical_analysis/09-numerical-methods-for-odes/01-initial-value-problems-and-picard-lindelof-theorem/' | relative_url }})
- [9.2: Euler and Improved Euler Methods]({{ '/pages/mathematics/numerical_analysis/09-numerical-methods-for-odes/02-euler-and-improved-euler-methods/' | relative_url }})
- [9.3: Runge-Kutta Methods]({{ '/pages/mathematics/numerical_analysis/09-numerical-methods-for-odes/03-runge-kutta-methods/' | relative_url }})
- [9.4: Consistency, Stability, and Convergence of ODE Solvers]({{ '/pages/mathematics/numerical_analysis/09-numerical-methods-for-odes/04-consistency-stability-and-convergence-of-ode-solvers/' | relative_url }})

## Navigation

[Back to Mathematics]({{ '/pages/mathematics/' | relative_url }})

</article>

