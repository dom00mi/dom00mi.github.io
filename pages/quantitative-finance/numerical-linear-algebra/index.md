---
layout: default
title: Numerical Linear Algebra in C++
permalink: /pages/quantitative-finance/numerical-linear-algebra/
---

# Numerical Linear Algebra in C++

### Mathematical Foundations and C++ Implementations

This project explores numerical linear algebra algorithms
implemented in modern C++, with applications to scientific
computing and quantitative finance.

**Repository:** [numerical-linear-algebra-cpp](https://github.com/dom00mi/numerical-linear-algebra-cpp)

---

## 1. Introduction

Numerical linear algebra lies at the heart of computational
finance and scientific computing.

Many problems in quantitative finance can be expressed
through systems of linear equations, matrix factorisations,
eigenvalue problems, and numerical approximations.

The purpose of this project is to explore these methods
through practical C++ implementations.

---

## 2. Mathematical Background

Consider a system of linear equations:

$$
A\mathbf{x} = \mathbf{b},
$$

where

$$
A \in \mathbb{R}^{n \times n},
\qquad
\mathbf{x},\mathbf{b} \in \mathbb{R}^{n}.
$$

Our objective is to determine the vector $\mathbf{x}$
satisfying the system.

Different numerical methods can be employed depending
on the structure and properties of $A$.

---

## 3. C++ Implementation

### Matrix Operations — C++ Implementation

{% highlight cpp %}
{% include code/numerical-linear-algebra/Matrix.cpp %}
{% endhighlight %}

---

## 4. Applications in Quantitative Finance

Numerical linear algebra is essential for:

- Solving discretised partial differential equations.
- Numerical optimisation and calibration.
- Covariance matrix decomposition.
- Principal component analysis.
- Numerical methods for derivatives pricing.

---

## 5. Source Code

The complete implementation, documentation, and project
structure are available on GitHub.

[View the C++ Repository](https://github.com/dom00mi/numerical-linear-algebra-cpp)

---

**Note:** This project is part of an evolving collection
of educational and computational finance implementations.