---
layout: default
title: "1.1: Vectors in R2 R3 and Rn"
permalink: /pages/mathematics/linear_algebra/01-vectors-and-euclidean-geometry/01-vectors-in-r2-r3-and-rn/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/01-vectors-and-euclidean-geometry/01-vectors-in-r2-r3-and-rn/' | relative_url }}">← Vectors in R2 R3 and Rn</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 1.1</div>
  <h1>Vectors in R2 R3 and Rn</h1>
  <p class="lead">Placeholder topic for Vectors in R2 R3 and Rn. (TBD)</p>
</div>

<article class="article" markdown="1">


# Chapter 1 — Vectors and Euclidean Geometry

Let's start our linear algebra journey!

Linear algebra begins with an elementary but powerful observation: **displacements can be added and scaled**. An arrow in the plane is a useful picture of a vector, but its essential structure is algebraic. Once a vector is described by its coordinates, the same operations make sense in three, four, or arbitrarily many dimensions. Geometry is then reconstructed from these operations together with a notion of length and angle.

This chapter builds the bridge from familiar Euclidean geometry to the abstract viewpoint of vector spaces. We develop coordinate representations and vector arithmetic, introduce the dot product and the metric geometry it induces, examine the special role of orientation and the cross product in three dimensions, and conclude with equations for lines, planes, and their intersections.

## The guiding idea

Let $\mathbf{u},\mathbf{v}\in\mathbb{R}^n$ and $\alpha,\beta\in\mathbb{R}$. The expression

$$
\alpha\mathbf{u}+\beta\mathbf{v}
$$

is again a vector in $\mathbb{R}^n$. This simple closure property is the starting point for the much broader theory of vector spaces. A second operation,

$$
\mathbf{u}\cdot\mathbf{v}=\sum_{i=1}^{n}u_iv_i,
$$

allows us to measure lengths and angles. In three dimensions, a further operation $\mathbf{u}\times\mathbf{v}$ encodes the normal direction and oriented area of a parallelogram.

The distinction between these structures is important: **vector addition and scalar multiplication exist in every $\mathbb{R}^n$; the standard cross product is specific to three dimensions.**


# 1.1 — Vectors in $\mathbb{R}^2$, $\mathbb{R}^3$ and $\mathbb{R}^n$

The simplest geometric problems involve two related kinds of objects: **points**, which specify locations, and **vectors**, which specify displacements. A point describes *where* something is; a vector describes *how far and in which direction* to move. Choosing coordinates makes both objects numerical, but one should preserve this conceptual distinction. In particular, subtracting two points gives a displacement, whereas adding a displacement to a point gives another point.

We begin with arrows in the plane and ordinary three-dimensional space, then identify the algebraic structure that survives when there is no picture to draw.

## 1.1.1 Directed segments and free vectors

**Definition 1.1.1 (Directed segment).** Given points $A,B\in\mathbb{R}^n$, the directed segment from $A$ to $B$ is denoted by $\overrightarrow{AB}$. In Cartesian coordinates it is represented by

$$
\overrightarrow{AB}=B-A=(b_1-a_1,\ldots,b_n-a_n).
$$

Two directed segments represent the same **free vector** when they have the same coordinate differences. Thus a vector does not depend on its initial point: it may be translated without changing its value. The **zero vector** represents no displacement, and reversing a segment changes its sign:

$$
\overrightarrow{AA}=\mathbf{0},\qquad
\overrightarrow{BA}=-\overrightarrow{AB}.
$$

**Example 1.1.1.** If $A=(2,-1)$ and $B=(5,3)$, then

$$
\overrightarrow{AB}=(3,4).
$$

The same vector is represented by the arrow from $C=(-2,0)$ to $D=(1,4)$, since $D-C=(3,4)$.

**Proposition 1.1.1 (Chasles' relation).** For any three points $A,B,C\in\mathbb{R}^n$,

$$
\overrightarrow{AB}+\overrightarrow{BC}=\overrightarrow{AC}.
$$

**Proof.** Using the coordinate representation,

$$
(B-A)+(C-B)=C-A.
$$

The intermediate point cancels. $\square$

## 1.1.2 Coordinate spaces

**Definition 1.1.2 (Euclidean coordinate space).** For $n\geq 1$,

$$
\mathbb{R}^n
=\bigl\{(x_1,x_2,\ldots,x_n):x_i\in\mathbb{R}\bigr\}.
$$

Its elements are ordered $n$-tuples. Equality is defined componentwise:

$$
\mathbf{x}=\mathbf{y}
\iff x_i=y_i\quad\text{for every }i=1,\ldots,n.
$$

Particular cases recover familiar geometry:

- $\mathbb{R}^1$ describes a real line;
- $\mathbb{R}^2$ describes a plane;
- $\mathbb{R}^3$ describes three-dimensional space;
- $\mathbb{R}^n$ describes an $n$-dimensional coordinate space, whether or not it is directly visualizable.

A vector may be written as an ordered tuple or as a column:

$$
\mathbf{x}=(x_1,\ldots,x_n)
\quad\longleftrightarrow\quad
\begin{pmatrix}x_1\\\vdots\\x_n\end{pmatrix}.
$$

The tuple and column conventions encode the same coordinates here; the column form will become especially useful when matrices are introduced.

## 1.1.3 Addition and scalar multiplication

**Definition 1.1.3 (Vector operations).** Let $\mathbf{u}=(u_1,\ldots,u_n)$, $\mathbf{v}=(v_1,\ldots,v_n)$ and $\lambda\in\mathbb{R}$. Define

$$
\begin{aligned}
\mathbf{u}+\mathbf{v}&=(u_1+v_1,\ldots,u_n+v_n),\\
\lambda\mathbf{u}&=(\lambda u_1,\ldots,\lambda u_n).
\end{aligned}
$$

Geometrically, vector addition follows the **head-to-tail rule**, equivalently the parallelogram rule. Multiplication by $\lambda$ changes a vector's length by $|\lambda|$ and reverses its direction if $\lambda<0$.

For example, for $\mathbf{u}=(2,-1,3)$ and $\mathbf{v}=(-1,4,0)$,

$$
\mathbf{u}+\mathbf{v}=(1,3,3),\qquad
2\mathbf{u}-\mathbf{v}=(5,-6,6).
$$

**Proposition 1.1.2 (Algebraic rules).** For all $\mathbf{u},\mathbf{v},\mathbf{w}\in\mathbb{R}^n$ and $\lambda,\mu\in\mathbb{R}$,

$$
\begin{aligned}
\mathbf{u}+\mathbf{v}&=\mathbf{v}+\mathbf{u},\\
(\mathbf{u}+\mathbf{v})+\mathbf{w}&=\mathbf{u}+(\mathbf{v}+\mathbf{w}),\\
\mathbf{u}+\mathbf{0}&=\mathbf{u},\qquad \mathbf{u}+(-\mathbf{u})=\mathbf{0},\\
\lambda(\mathbf{u}+\mathbf{v})&=\lambda\mathbf{u}+\lambda\mathbf{v},\\
(\lambda+\mu)\mathbf{u}&=\lambda\mathbf{u}+\mu\mathbf{u},\\
\lambda(\mu\mathbf{u})&=(\lambda\mu)\mathbf{u},\qquad 1\mathbf{u}=\mathbf{u}.
\end{aligned}
$$

**Proof.** Each identity follows from the corresponding real-number identity in each coordinate. For example, the $i$th component of $\lambda(\mathbf{u}+\mathbf{v})$ is

$$
\lambda(u_i+v_i)=\lambda u_i+\lambda v_i.
$$

Since this holds for every $i$, the vectors are equal. The remaining statements follow analogously. $\square$

These eight rules show that $\mathbb{R}^n$ is a **real vector space**. In later chapters we abstract these axioms and apply them to polynomials, matrices, and functions: a vector need not literally be an arrow.

**Corollary 1.1.1.** If $\lambda\mathbf{u}=\mathbf{0}$, then $\lambda=0$ or $\mathbf{u}=\mathbf{0}$.

**Proof.** If $\lambda\neq 0$, multiply by $1/\lambda$ and use the associative and identity rules. $\square$

## 1.1.4 Standard coordinate vectors

**Definition 1.1.4 (Standard coordinate vectors).** For $i=1,\ldots,n$, write

$$
\mathbf{e}_i=(0,\ldots,0,\underbrace{1}_{i\text{th position}},0,\ldots,0).
$$

Then every vector has the representation

$$
\boxed{\mathbf{x}=x_1\mathbf{e}_1+\cdots+x_n\mathbf{e}_n
=\sum_{i=1}^{n}x_i\mathbf{e}_i.}
$$

In three-dimensional geometry one sometimes uses $\mathbf{i},\mathbf{j},\mathbf{k}$ instead of $\mathbf{e}_1,\mathbf{e}_2,\mathbf{e}_3$.

**Proposition 1.1.3 (Uniqueness of standard coordinates).** If

$$
\sum_{i=1}^{n}a_i\mathbf{e}_i
=\sum_{i=1}^{n}b_i\mathbf{e}_i,
$$

then $a_i=b_i$ for every $i$.

**Proof.** The $i$th component of the left side is $a_i$, and the $i$th component of the right side is $b_i$. Equality of vectors forces equality of these components. $\square$

This is our first appearance of a **basis**: the vectors $\mathbf{e}_1,\ldots,\mathbf{e}_n$ generate every vector and give unique coefficients. Formal definitions of span, linear independence, and basis are deferred to Chapter 2.

## 1.1.5 Linear combinations and affine combinations

A **linear combination** of vectors $\mathbf{v}_1,\ldots,\mathbf{v}_m$ is an expression

$$
\lambda_1\mathbf{v}_1+\cdots+\lambda_m\mathbf{v}_m,
\qquad \lambda_i\in\mathbb{R}.
$$

Given two points $A,B$, the line through them is traced by

$$
X(t)=A+t(B-A)=(1-t)A+tB,\qquad t\in\mathbb{R}.
$$

The coefficients of $A$ and $B$ sum to one. Such an expression is an **affine combination** of points. Unlike an arbitrary linear combination, an affine combination of points is independent of the choice of coordinate origin.

For $0\leq t\leq 1$, $X(t)$ traces the line **segment** from $A$ to $B$. In particular,

$$
M=\frac{A+B}{2}
$$

is the midpoint, since $M=A+\tfrac12(B-A)$.

More generally, if $\lambda_1+\cdots+\lambda_m=1$, the expression

$$
P=\sum_{i=1}^{m}\lambda_iP_i
$$

is affine. If also every $\lambda_i\geq 0$, it is a **convex combination**, lying in the convex hull of the points.

## 1.1.6 Parallelism and dependence of two vectors

Two nonzero vectors are **parallel** when one is a scalar multiple of the other:

$$
\mathbf{u}\parallel\mathbf{v}
\iff \mathbf{u}=\lambda\mathbf{v}
\text{ for some }\lambda\neq 0.
$$

If $\lambda>0$, their directions agree; if $\lambda<0$, their directions are opposite. The zero vector has no distinguished direction; when discussing parallel geometric directions, we therefore assume the vectors are nonzero.

**Example 1.1.2.** The vectors $(2,-4,6)$ and $(-1,2,-3)$ are parallel, whereas $(2,-4,6)$ and $(1,0,1)$ are not.

## 1.1.7 Geometry beyond three dimensions

The same coordinate operations work in any dimension. One may use an $n$-tuple to represent a state of a system, values of several variables, or coefficients of a polynomial. Although $\mathbb{R}^4$ cannot be drawn faithfully in ordinary space, its vector arithmetic is just as rigorous as that of $\mathbb{R}^2$.

It is useful to distinguish three structures:

1. the **set of points** $\mathbb{R}^n$;
2. its **linear structure**, supplied by vector addition and scalar multiplication;
3. its **metric structure**, which measures lengths, distances, and angles and will be introduced in the next section.

A general vector space need not possess the third structure. This distinction is central when moving from Euclidean geometry to abstract linear algebra.

## Summary

Vectors are origin-independent displacements represented by $n$-tuples. Componentwise addition and scalar multiplication satisfy the vector-space axioms, while standard coordinate vectors yield unique expansions. The difference between linear and affine combinations allows us to describe geometric sets without confusing positions with displacements.


- [Exercises]({{ '/pages/mathematics/linear_algebra/01-vectors-and-euclidean-geometry/01-vectors-in-r2-r3-and-rn/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/01-vectors-and-euclidean-geometry/01-vectors-in-r2-r3-and-rn/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/01-vectors-and-euclidean-geometry/01-vectors-in-r2-r3-and-rn/references/' | relative_url }})

[Back to Vectors and Euclidean Geometry]({{ '/pages/mathematics/linear_algebra/01-vectors-and-euclidean-geometry/' | relative_url }})

</article>
