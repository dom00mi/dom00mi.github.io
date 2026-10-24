
---
layout: default
title: "Introduction to Partial Differential Equations"
permalink: /pages/mathematics/pdes/intro-to-pdes/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/pdes/' | relative_url }}">← Mathematical Analysis</a>
  <div class="eyebrow">Mathematics / PDEs / 01</div>
  <h1>Introduction to Partial Differential Equations</h1>
  <p class="lead">Foundations and Properties — .</p>
</div>

<article class="article" markdown="1">


# Chapter 01 — Introduction to Partial Differential Equations

## 1. What Is a Partial Differential Equation?

Let

$$
x=(x_1,\ldots,x_n)\in\mathbb{R}^n,
$$

and consider a real-valued function

$$
u:U\longrightarrow\mathbb{R},
$$

where $U\subseteq\mathbb{R}^n$ is an open set.

A **partial differential equation (PDE)** is an equation involving the unknown function $u$, its independent variables, and finitely many partial derivatives of $u$.

In its general form, a PDE can be written as

$$
F\left(
x,u,
\frac{\partial u}{\partial x_1},
\ldots,
\frac{\partial u}{\partial x_n},
\frac{\partial^2u}{\partial x_1^2},
\frac{\partial^2u}{\partial x_1\partial x_2},
\ldots
\right)=0,
$$

where $F$ is a given function and $u$ is the unknown.

The objective is to determine functions $u$ that satisfy the equation, possibly together with additional conditions imposed on the boundary of the domain or at an initial time.

### Definition 1.1 — Classical Solution

A function $u:U\to\mathbb{R}$ is called a **classical solution** of a PDE if it possesses the required continuous partial derivatives and satisfies the differential equation at every point of its domain.

For a PDE of order $m$, one typically seeks a solution in the class

$$
u\in C^m(U).
$$

Additional conditions may be imposed to obtain a particular solution.

For example, a **Dirichlet boundary condition** specifies the value of the unknown function along the boundary:

$$
u(x)=g(x),
\qquad x\in\partial U.
$$

A **Neumann boundary condition** specifies its normal derivative:

$$
\frac{\partial u}{\partial n}(x)=h(x),
\qquad x\in\partial U.
$$

Here, $\partial U$ denotes the boundary of $U$, and $n$ is the outward unit normal, whenever it is defined.

For time-dependent problems, we may also prescribe an initial condition such as

$$
u(x,0)=u_0(x).
$$

These additional conditions play a fundamental role in determining whether a PDE admits a solution and whether that solution is unique.

---

## 2. Classification by Order and Linearity

### Definition 1.2 — Order of a PDE

The **order** of a PDE is the highest order of partial differentiation appearing in the equation.

For example,

$$
u_x+u_y=0
$$

is a first-order PDE, whereas

$$
u_{xx}+u_{yy}=0
$$

is a second-order PDE.

Throughout these notes, we use the shorthand notation

$$
u_{x_i}=\frac{\partial u}{\partial x_i},
\qquad
u_{x_ix_j}
=\frac{\partial^2u}{\partial x_i\partial x_j}.
$$

### Definition 1.3 — Linear PDE

A PDE is called **linear** if the unknown function $u$ and all its derivatives appear linearly, with coefficients depending only on the independent variables.

A general linear PDE of order $m$ may be written as

$$
Lu=f,
$$

where $L$ is a linear differential operator.

For example,

$$
u_x+y\,u_y=1
$$

is linear, whereas

$$
u_x+u\,u_y=0
$$

is nonlinear because the unknown function $u$ multiplies one of its derivatives.

### Definition 1.4 — Homogeneous and Non-Homogeneous PDEs

For a linear PDE written as

$$
Lu=f,
$$

we distinguish between:

- **Homogeneous equations**, when $f=0$.
- **Non-homogeneous equations**, when $f\neq0$.

Equivalently, a linear equation is homogeneous precisely when the zero function is a solution.

For instance,

$$
u_x+u_y=0
$$

is homogeneous, while

$$
u_x+y\,u_y=1
$$

is non-homogeneous.

---

## 3. Examples of Partial Differential Equations

The following examples illustrate the different types of PDEs.

### Example 1.1 — Linear Homogeneous First-Order PDE

Consider

$$
\boxed{u_x+u_y=0.}
$$

This equation is:

- First-order, because only first derivatives appear.
- Linear, because $u$ and its derivatives enter linearly.
- Homogeneous, because the right-hand side is zero.

### Example 1.2 — Linear Non-Homogeneous First-Order PDE

Consider

$$
\boxed{u_x+y\,u_y=1.}
$$

This equation is:

- First-order.
- Linear, with variable coefficient $y$.
- Non-homogeneous, because the right-hand side is nonzero.

### Example 1.3 — Nonlinear First-Order PDE

Consider

$$
\boxed{u_x+u\,u_y=0.}
$$

This is a first-order nonlinear PDE because the term $u\,u_y$ involves a product of the unknown function and one of its derivatives.

### Example 1.4 — The Wave Equation

Consider

$$
\boxed{u_{tt}-u_{xx}=t+x^2.}
$$

This equation is:

- Second-order.
- Linear.
- Non-homogeneous.

It is a forced, one-dimensional wave equation.

### Example 1.5 — The Eikonal Equation

Consider

$$
\boxed{(u_x)^2+(u_y)^2=f(x,y).}
$$

This is a first-order nonlinear PDE.

When $f(x,y)=1$, the equation takes the form

$$
|\nabla u|^2=1.
$$

The eikonal equation appears in geometrical optics, wavefront propagation, and optimal control.

---

## 4. General Linear Second-Order PDEs

Our initial focus will be on **linear second-order partial differential equations**.

In two independent variables, the general equation can be expressed as

$$
\boxed{
A(x,y)u_{xx}
+2B(x,y)u_{xy}
+C(x,y)u_{yy}
+D(x,y)u_x
+E(x,y)u_y
+G(x,y)u
=f(x,y).
}
$$

The terms involving second derivatives form the **principal part**:

$$
A(x,y)u_{xx}
+2B(x,y)u_{xy}
+C(x,y)u_{yy}.
$$

The remaining terms are called lower-order terms.

Assume that at least one of $A$, $B$, or $C$ is nonzero at the point under consideration, so that the equation is genuinely second-order there.

The classification of the equation depends on the sign of

$$
\Delta=AC-B^2.
$$

### Definition 1.5 — Elliptic, Parabolic, and Hyperbolic PDEs

At a given point, a second-order linear PDE in two variables is classified as follows:

| Condition | Classification |
|---|---|
| $AC-B^2>0$ | Elliptic |
| $AC-B^2=0$ | Parabolic |
| $AC-B^2<0$ | Hyperbolic |

Equivalently, one may use the discriminant $B^2-AC$, in which case the signs are reversed.

### 4.1 Elliptic Equations

If

$$
AC-B^2>0,
$$

the PDE is called **elliptic**.

A fundamental example is Laplace's equation:

$$
\boxed{u_{xx}+u_{yy}=0.}
$$

Here,

$$
A=1,\qquad B=0,\qquad C=1,
$$

and therefore

$$
AC-B^2=1>0.
$$

Laplace's equation describes many equilibrium and steady-state phenomena.

### 4.2 Parabolic Equations

If

$$
AC-B^2=0,
$$

the PDE is called **parabolic**.

The classical example is the heat equation:

$$
\boxed{u_t-u_{xx}=0.}
$$

Using $(x,t)$ as the independent variables, we have

$$
A=-1,\qquad B=0,\qquad C=0,
$$

so that

$$
AC-B^2=0.
$$

The heat equation describes diffusion and the evolution of temperature over time.

### 4.3 Hyperbolic Equations

If

$$
AC-B^2<0,
$$

the PDE is called **hyperbolic**.

A fundamental example is the wave equation:

$$
\boxed{u_{tt}-u_{xx}=0.}
$$

Taking $(x,t)$ as the independent variables gives

$$
A=-1,\qquad B=0,\qquad C=1,
$$

and hence

$$
AC-B^2=-1<0.
$$

Hyperbolic equations are closely associated with wave propagation and the transmission of disturbances.

---

## 5. Classification in Higher Dimensions

We now extend the discussion to functions depending on $n$ independent variables.

A general linear second-order PDE may be written as

$$
\boxed{
\sum_{i=1}^{n}\sum_{j=1}^{n}
a_{ij}(x)\frac{\partial^2u}{\partial x_i\partial x_j}
+
\sum_{i=1}^{n}b_i(x)\frac{\partial u}{\partial x_i}
+c(x)u=f(x).
}
$$

The principal part is

$$
\sum_{i=1}^{n}\sum_{j=1}^{n}
a_{ij}(x)u_{x_ix_j}.
$$

Since mixed partial derivatives commute for sufficiently smooth functions, we may take the principal coefficient matrix to be symmetric:

$$
M(x)=
\begin{pmatrix}
a_{11}(x)&\cdots&a_{1n}(x)\\
\vdots&\ddots&\vdots\\
a_{n1}(x)&\cdots&a_{nn}(x)
\end{pmatrix}.
$$

The eigenvalues of $M$ determine the signature of the principal part.

### 5.1 Elliptic Equations

A second-order PDE is **elliptic** at a point if all eigenvalues of $M$ are strictly positive or all are strictly negative.

Equivalently, the principal quadratic form

$$
Q(\xi)=\xi^\top M\xi
$$

is definite for every nonzero vector $\xi\in\mathbb{R}^n$.

### 5.2 Parabolic Equations

A commonly encountered parabolic principal part has one zero eigenvalue, while all the remaining eigenvalues have the same strict sign.

For example, the heat operator

$$
L=\partial_t-\Delta_x
$$

has a degenerate second-order coefficient matrix when time and space are considered together.

**Remark.** In higher dimensions, degeneracy of the principal matrix alone is not sufficient to characterize every parabolic PDE. The standard parabolic structure also involves a distinguished time variable and an appropriate first-order time derivative.

### 5.3 Hyperbolic Equations

An important class of hyperbolic equations has a principal matrix with exactly one eigenvalue of one sign and all remaining eigenvalues of the opposite sign.

For example, the multidimensional wave equation

$$
u_{tt}-\Delta_xu=0
$$

has one positive direction associated with time and negative directions associated with space.

**Remark.** This signature characterizes the familiar wave-type, or normally hyperbolic, case. More general notions of hyperbolicity exist, particularly for higher-order equations and systems.

---

## 6. The Three Fundamental Equations

We will study three classical PDEs as representatives of the main types of second-order equations.

### 6.1 Laplace's Equation — Elliptic

$$
\boxed{\Delta u=0,}
$$

where

$$
\Delta u
=
\sum_{i=1}^{n}\frac{\partial^2u}{\partial x_i^2}
$$

is the Laplace operator.

Laplace's equation arises in:

- Steady-state heat conduction.
- Electrostatic and gravitational potentials.
- Incompressible, irrotational fluid flow.
- Equilibrium problems in mathematical physics.

Its solutions are called **harmonic functions**.

### 6.2 The Heat Equation — Parabolic

$$
\boxed{u_t-\kappa\Delta u=0,\qquad\kappa>0.}
$$

The parameter $\kappa$ is the diffusion coefficient.

The heat equation models:

- Temperature diffusion in a material.
- Diffusion of chemical substances.
- Population dispersal.
- Other transport processes governed by diffusion.

A key feature of the heat equation is its smoothing behaviour: under suitable assumptions, irregular initial data can produce smoother solutions at positive times.

### 6.3 The Wave Equation — Hyperbolic

$$
\boxed{u_{tt}-c^2\Delta u=0,\qquad c>0.}
$$

Here, $c$ represents the wave propagation speed.

The wave equation describes:

- Vibrations of strings and membranes.
- Acoustic waves.
- Mechanical disturbances in elastic media.
- Electromagnetic wave propagation in suitable settings.

Unlike the heat equation, the wave equation exhibits finite propagation speed: disturbances travel through the domain rather than affecting every point instantaneously.

---

## 7. What Does It Mean to Solve a PDE?

One of the central difficulties in the theory of PDEs is that **there is no universal method for solving every equation**, even within the class of linear PDEs.

Different equations require different mathematical techniques.

For the classical equations introduced above, we will gradually develop tools such as:

- Separation of variables.
- Fourier series and Fourier transforms.
- The method of characteristics.
- Fundamental solutions and Green's functions.
- Energy estimates.
- Maximum principles.
- Weak formulations and functional-analytic methods.

Furthermore, many PDEs of practical and theoretical interest do not admit explicit solutions.

In such cases, the objective is not necessarily to obtain a closed-form expression, but rather to understand the mathematical properties of the solution.

Some of the most important questions are:

**Existence.** Does a solution exist under the prescribed conditions?

**Uniqueness.** If a solution exists, is it uniquely determined?

**Regularity.** How smooth is the solution?

**Stability.** How sensitive is the solution to changes in the initial data, boundary conditions, or coefficients?

**Qualitative behaviour.** Can we establish bounds, conservation laws, decay rates, or long-term asymptotic properties without knowing an explicit formula?

These questions form the foundation of modern PDE theory.

---

## 8. Summary

In this introductory chapter, we have:

1. Defined partial differential equations and classical solutions.
2. Distinguished equations according to their order, linearity, and homogeneity.
3. Introduced the general form of a linear second-order PDE.
4. Classified second-order equations as elliptic, parabolic, or hyperbolic.
5. Examined Laplace's equation, the heat equation, and the wave equation.
6. Motivated the study of existence, uniqueness, regularity, and stability.

The next step is to investigate these equations in greater detail and develop the analytical tools required to understand their solutions.

---

[← Back to PDEs]({{ '/pages/mathematics/pdes/' | relative_url }})



