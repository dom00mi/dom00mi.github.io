---
layout: default
title: "1.2: Dot Products Norms and Angles"
permalink: /pages/mathematics/linear_algebra/01-vectors-and-euclidean-geometry/02-dot-products-norms-and-angles/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/01-vectors-and-euclidean-geometry/02-dot-products-norms-and-angles/' | relative_url }}">← Dot Products Norms and Angles</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 1.2</div>
  <h1>Dot Products Norms and Angles</h1>
  <p class="lead">Placeholder topic for Dot Products Norms and Angles. (TBD)</p>
</div>

<article class="article" markdown="1">

# 1.2 — Dot Products, Norms and Angles

Vector addition describes how displacements combine, but it does not by itself tell us whether two vectors are perpendicular or how far apart two points lie. To recover Euclidean geometry from coordinates, we introduce a scalar-valued operation that links algebra to the measurement of lengths and angles: the **dot product**.

Throughout this section, vectors belong to $\mathbb{R}^n$, with its usual Euclidean structure. Abstract inner products, which extend these ideas to general real and complex vector spaces, will be treated systematically in Chapter 7.

## 1.2.1 The Euclidean dot product

**Definition 1.2.1 (Dot product).** For $\mathbf{u}=(u_1,\ldots,u_n)$ and $\mathbf{v}=(v_1,\ldots,v_n)$, define

$$
\boxed{\mathbf{u}\cdot\mathbf{v}=\sum_{i=1}^{n}u_iv_i.}
$$

Unlike addition or the cross product, the dot product returns a **real number**. Its value is independent of whether the vectors are written as tuples or columns.

**Example 1.2.1.** For $\mathbf{u}=(1,-2,3)$ and $\mathbf{v}=(4,0,-1)$,

$$
\mathbf{u}\cdot\mathbf{v}=4+0-3=1.
$$

**Proposition 1.2.1 (Dot-product identities).** For $\mathbf{u},\mathbf{v},\mathbf{w}\in\mathbb{R}^n$ and $\lambda\in\mathbb{R}$,

$$
\begin{aligned}
\mathbf{u}\cdot\mathbf{v}&=\mathbf{v}\cdot\mathbf{u},\\
(\mathbf{u}+\mathbf{v})\cdot\mathbf{w}
&=\mathbf{u}\cdot\mathbf{w}+\mathbf{v}\cdot\mathbf{w},\\
(\lambda\mathbf{u})\cdot\mathbf{v}
&=\lambda(\mathbf{u}\cdot\mathbf{v}),\\
\mathbf{u}\cdot\mathbf{u}&\geq 0,
\qquad \mathbf{u}\cdot\mathbf{u}=0\iff\mathbf{u}=\mathbf{0}.
\end{aligned}
$$

**Proof.** Symmetry, additivity, and homogeneity follow by rearranging a finite sum of real numbers. Finally,

$$
\mathbf{u}\cdot\mathbf{u}=\sum_{i=1}^{n}u_i^2,
$$

which is nonnegative and vanishes precisely when every component is zero. $\square$

These properties are the prototype of the axioms for a real **inner product**. They are more significant than the particular coordinate formula: the geometry of lengths and angles follows from them.

## 1.2.2 Norm and distance

**Definition 1.2.2 (Euclidean norm).** The length of $\mathbf{u}$ is

$$
\boxed{\|\mathbf{u}\|=\sqrt{\mathbf{u}\cdot\mathbf{u}}
=\sqrt{u_1^2+\cdots+u_n^2}.}
$$

A vector is a **unit vector** when its norm equals one. For $\mathbf{u}\neq\mathbf{0}$, its normalization is

$$
\widehat{\mathbf{u}}=\frac{\mathbf{u}}{\|\mathbf{u}\|},
\qquad \|\widehat{\mathbf{u}}\|=1.
$$

**Definition 1.2.3 (Euclidean distance).** The distance between points $P,Q\in\mathbb{R}^n$ is the length of their displacement:

$$
\boxed{d(P,Q)=\|Q-P\|
=\sqrt{\sum_{i=1}^{n}(q_i-p_i)^2}.}
$$

**Example 1.2.2.** For $P=(1,2,-1)$ and $Q=(3,-1,5)$,

$$
Q-P=(2,-3,6),\qquad d(P,Q)=\sqrt{4+9+36}=7.
$$

**Proposition 1.2.2 (Homogeneity).** For every $\lambda\in\mathbb{R}$,

$$
\|\lambda\mathbf{u}\|=|\lambda|\,\|\mathbf{u}\|.
$$

**Proof.** Square both sides and use bilinearity:

$$
\|\lambda\mathbf{u}\|^2
=(\lambda\mathbf{u})\cdot(\lambda\mathbf{u})
=\lambda^2\|\mathbf{u}\|^2.
$$

Both lengths are nonnegative, so taking square roots gives the result. $\square$

## 1.2.3 The Cauchy–Schwarz inequality

The most fundamental inequality in Euclidean geometry is the following.

**Theorem 1.2.1 (Cauchy–Schwarz).** For any $\mathbf{u},\mathbf{v}\in\mathbb{R}^n$,

$$
\boxed{|\mathbf{u}\cdot\mathbf{v}|
\leq\|\mathbf{u}\|\,\|\mathbf{v}\|.}
$$

Equality holds if and only if the vectors are linearly dependent (that is, one is a scalar multiple of the other, including the zero-vector cases).

**Proof.** If $\mathbf{v}=\mathbf{0}$ the claim is immediate. Otherwise consider

$$
0\leq\|\mathbf{u}-t\mathbf{v}\|^2
=\|\mathbf{u}\|^2-2t(\mathbf{u}\cdot\mathbf{v})
+t^2\|\mathbf{v}\|^2
$$

for every $t\in\mathbb{R}$. Choosing

$$
t=\frac{\mathbf{u}\cdot\mathbf{v}}{\|\mathbf{v}\|^2}
$$

gives

$$
0\leq\|\mathbf{u}\|^2
-\frac{(\mathbf{u}\cdot\mathbf{v})^2}{\|\mathbf{v}\|^2}.
$$

Multiplying by $\|\mathbf{v}\|^2$ yields the inequality. Equality occurs exactly when $\mathbf{u}-t\mathbf{v}=\mathbf{0}$ for the chosen $t$, so the vectors are dependent. $\square$

The importance of this result is twofold: it makes an algebraic definition of angle possible, and it controls the geometric behaviour of the norm.

## 1.2.4 Angles and orthogonality

**Definition 1.2.4 (Angle).** For nonzero $\mathbf{u},\mathbf{v}\in\mathbb{R}^n$, their angle $\theta\in[0,\pi]$ is defined by

$$
\boxed{\cos\theta=
\frac{\mathbf{u}\cdot\mathbf{v}}
{\|\mathbf{u}\|\,\|\mathbf{v}\|}.}
$$

Cauchy–Schwarz guarantees that the quotient belongs to $[-1,1]$, so the angle is well defined. The angle with the zero vector is **undefined**, since it has no direction.

The sign of the dot product has a direct interpretation:

- $\mathbf{u}\cdot\mathbf{v}>0$: the angle is acute;
- $\mathbf{u}\cdot\mathbf{v}=0$: the angle is a right angle;
- $\mathbf{u}\cdot\mathbf{v}<0$: the angle is obtuse.

**Definition 1.2.5 (Orthogonality).** We write $\mathbf{u}\perp\mathbf{v}$ when

$$
\boxed{\mathbf{u}\cdot\mathbf{v}=0.}
$$

Under this algebraic definition, the zero vector is orthogonal to every vector, even though it has no associated direction or geometric angle.

**Example 1.2.3.** For $\mathbf{u}=(1,2,-1)$ and $\mathbf{v}=(2,-1,0)$,

$$
\mathbf{u}\cdot\mathbf{v}=2-2=0,
$$

so the vectors are orthogonal.

**Theorem 1.2.2 (Law of cosines).** If $\theta$ is the angle between nonzero vectors $\mathbf{u}$ and $\mathbf{v}$, then

$$
\boxed{\|\mathbf{u}-\mathbf{v}\|^2
=\|\mathbf{u}\|^2+\|\mathbf{v}\|^2
-2\|\mathbf{u}\|\,\|\mathbf{v}\|\cos\theta.}
$$

**Proof.** Expand the square using bilinearity:

$$
\|\mathbf{u}-\mathbf{v}\|^2
=(\mathbf{u}-\mathbf{v})\cdot(\mathbf{u}-\mathbf{v})
=\|\mathbf{u}\|^2+\|\mathbf{v}\|^2-2\mathbf{u}\cdot\mathbf{v}.
$$

Substitute the definition of $\cos\theta$. $\square$

**Corollary 1.2.1 (Pythagoras).** If $\mathbf{u}\perp\mathbf{v}$, then

$$
\|\mathbf{u}+\mathbf{v}\|^2=\|\mathbf{u}\|^2+\|\mathbf{v}\|^2.
$$

The converse holds as well, because the missing cross term is $2\mathbf{u}\cdot\mathbf{v}$.

## 1.2.5 Triangle inequality and parallelogram law

**Theorem 1.2.3 (Triangle inequality).** For all $\mathbf{u},\mathbf{v}\in\mathbb{R}^n$,

$$
\boxed{\|\mathbf{u}+\mathbf{v}\|
\leq\|\mathbf{u}\|+\|\mathbf{v}\|.}
$$

**Proof.** By Cauchy–Schwarz,

$$
\begin{aligned}
\|\mathbf{u}+\mathbf{v}\|^2
&=\|\mathbf{u}\|^2+2\mathbf{u}\cdot\mathbf{v}+\|\mathbf{v}\|^2\\
&\leq\|\mathbf{u}\|^2+2\|\mathbf{u}\|\,\|\mathbf{v}\|+\|\mathbf{v}\|^2\\
&=(\|\mathbf{u}\|+\|\mathbf{v}\|)^2.
\end{aligned}
$$

Taking nonnegative square roots proves the claim. Equality holds precisely when the nonzero vectors point in the same direction; zero-vector cases also give equality. $\square$

Consequently,

$$
\bigl|\|\mathbf{u}\|-\|\mathbf{v}\|\bigr|
\leq\|\mathbf{u}-\mathbf{v}\|,
$$

the **reverse triangle inequality**.

**Proposition 1.2.3 (Parallelogram law).** For all $\mathbf{u},\mathbf{v}$,

$$
\boxed{\|\mathbf{u}+\mathbf{v}\|^2
+\|\mathbf{u}-\mathbf{v}\|^2
=2\|\mathbf{u}\|^2+2\|\mathbf{v}\|^2.}
$$

**Proof.** Expand both squares. The cross terms $+2\mathbf{u}\cdot\mathbf{v}$ and $-2\mathbf{u}\cdot\mathbf{v}$ cancel. $\square$

There is also a **polarization identity**, which recovers the dot product from the norm:

$$
\boxed{\mathbf{u}\cdot\mathbf{v}
=\frac{\|\mathbf{u}+\mathbf{v}\|^2
-\|\mathbf{u}-\mathbf{v}\|^2}{4}.}
$$

Thus, in a real Euclidean space, the inner product and the associated norm determine one another.

## 1.2.6 Orthogonal projections

**Definition 1.2.6 (Projection onto a vector).** For $\mathbf{v}\neq\mathbf{0}$, the orthogonal projection of $\mathbf{u}$ onto the line spanned by $\mathbf{v}$ is

$$
\boxed{\operatorname{proj}_{\mathbf{v}}\mathbf{u}
=\frac{\mathbf{u}\cdot\mathbf{v}}
{\mathbf{v}\cdot\mathbf{v}}\,\mathbf{v}.}
$$

The formula is derived by seeking a multiple $t\mathbf{v}$ such that the residual $\mathbf{u}-t\mathbf{v}$ is orthogonal to $\mathbf{v}$:

$$
(\mathbf{u}-t\mathbf{v})\cdot\mathbf{v}=0
\quad\Longrightarrow\quad
t=\frac{\mathbf{u}\cdot\mathbf{v}}{\|\mathbf{v}\|^2}.
$$

Hence every vector decomposes as

$$
\mathbf{u}=
\underbrace{\operatorname{proj}_{\mathbf{v}}\mathbf{u}}_{\text{parallel component}}
+
\underbrace{\bigl(\mathbf{u}-\operatorname{proj}_{\mathbf{v}}\mathbf{u}\bigr)}_{\text{orthogonal component}}.
$$

**Example 1.2.4.** Take $\mathbf{u}=(3,4)$ and $\mathbf{v}=(1,1)$. Then

$$
\operatorname{proj}_{\mathbf{v}}\mathbf{u}
=\frac{7}{2}(1,1)=\left(\frac72,\frac72\right),
$$

and the residual $(-\tfrac12,\tfrac12)$ is perpendicular to $(1,1)$.

**Theorem 1.2.4 (Nearest point on a line).** Among all vectors $t\mathbf{v}$, the one closest to $\mathbf{u}$ is its orthogonal projection onto $\mathbf{v}$.

**Proof.** Write $\mathbf{p}=\operatorname{proj}_{\mathbf{v}}\mathbf{u}$ and $\mathbf{r}=\mathbf{u}-\mathbf{p}$. For every $t$,

$$
\|\mathbf{u}-t\mathbf{v}\|^2
=\|\mathbf{r}+(\mathbf{p}-t\mathbf{v})\|^2
=\|\mathbf{r}\|^2+\|\mathbf{p}-t\mathbf{v}\|^2
\geq\|\mathbf{r}\|^2.
$$

The middle equality uses orthogonality. Equality is attained exactly at the projection. $\square$

## 1.2.7 The Gram determinant and planar area

For vectors $\mathbf{u},\mathbf{v}\in\mathbb{R}^n$, the square of the area of the parallelogram they span can be expressed using only dot products:

$$
\boxed{A^2
=\|\mathbf{u}\|^2\|\mathbf{v}\|^2
-(\mathbf{u}\cdot\mathbf{v})^2.}
$$

Indeed, if $\theta$ is the angle between nonzero vectors, the area is

$$
A=\|\mathbf{u}\|\,\|\mathbf{v}\|\sin\theta.
$$

Using $\sin^2\theta=1-\cos^2\theta$ yields the claimed formula. Equivalently,

$$
A^2=
\det\begin{pmatrix}
\mathbf{u}\cdot\mathbf{u}&\mathbf{u}\cdot\mathbf{v}\\
\mathbf{v}\cdot\mathbf{u}&\mathbf{v}\cdot\mathbf{v}
\end{pmatrix}.
$$

This expression is nonnegative by Cauchy–Schwarz. It anticipates **Gram matrices**, which appear later in the study of inner products and matrix decompositions.

- [Exercises]({{ '/pages/mathematics/linear_algebra/01-vectors-and-euclidean-geometry/02-dot-products-norms-and-angles/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/01-vectors-and-euclidean-geometry/02-dot-products-norms-and-angles/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/01-vectors-and-euclidean-geometry/02-dot-products-norms-and-angles/references/' | relative_url }})

[Back to Vectors and Euclidean Geometry]({{ '/pages/mathematics/linear_algebra/01-vectors-and-euclidean-geometry/' | relative_url }})

</article>
