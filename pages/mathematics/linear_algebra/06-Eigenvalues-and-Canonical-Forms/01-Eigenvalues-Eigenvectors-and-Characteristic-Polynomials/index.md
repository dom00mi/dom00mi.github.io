---
layout: default
title: "6.1: Eigenvalues Eigenvectors and Characteristic Polynomials"
permalink: /pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/01-eigenvalues-eigenvectors-and-characteristic-polynomials/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/01-eigenvalues-eigenvectors-and-characteristic-polynomials/' | relative_url }}">← Eigenvalues Eigenvectors and Characteristic Polynomials</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 6.1</div>
  <h1>Eigenvalues Eigenvectors and Characteristic Polynomials</h1>
</div>

<article class="article" markdown="1">

# 6.1 — Eigenvalues, Eigenvectors, and Characteristic Polynomials

An endomorphism may act on a vector in a complicated way, yet certain directions are preserved: on these directions the action is multiplication by a scalar. These **eigenvectors** and **eigenvalues** are the starting point for understanding an operator up to similarity. Throughout, let $K$ denote a field and let $V$ be a nonzero finite-dimensional vector space over $K$, unless stated otherwise. The notation for vector spaces and linear maps is as in the preceding chapters.

## 6.1.1 — Eigenvalues and eigenvectors

**Definition 6.1.1 (Eigenpair).** Let $T:V\to V$ be linear. A scalar $\lambda\in K$ is an **eigenvalue** if there exists a **nonzero** vector $v\in V$ such that

$$
T(v)=\lambda v,\qquad v\neq 0.
$$

Such a vector $v$ is an **eigenvector** corresponding to $\lambda$. For a matrix $A\in M_n(K)$ the analogous equation is

$$
Av=\lambda v,\qquad v\in K^n\setminus\{0\}.
$$

The qualification $v\neq0$ is essential: the zero vector satisfies $T(0)=\lambda 0$ for *every* scalar and therefore cannot distinguish eigenvalues. By contrast, the scalar $\lambda=0$ is allowed; it is an eigenvalue precisely when $T$ is non-injective.

**Lemma 6.1.2 (Scalar multiples).** If $v$ is an eigenvector of $T$ for $\lambda$ and $c\in K$ is nonzero, then $cv$ is an eigenvector for the same eigenvalue.

*Proof.* By linearity,

$$
T(cv)=cT(v)=c\lambda v=\lambda(cv),\qquad cv\neq0.
$$

The restriction $c\neq0$ corrects the common shorthand that *every* scalar multiple is an eigenvector: the zero multiple is not. $\square$

**Example 6.1.3 (Diagonal action).** For

$$
T(x,y)=(2x,3y),\qquad
A=\begin{pmatrix}2&0\\0&3\end{pmatrix},
$$

we obtain

$$
A\begin{pmatrix}1\\0\end{pmatrix}
=2\begin{pmatrix}1\\0\end{pmatrix},\qquad
A\begin{pmatrix}0\\1\end{pmatrix}
=3\begin{pmatrix}0\\1\end{pmatrix}.
$$

Thus the coordinate axes are eigenvector directions. This illustrates why diagonal matrices are particularly easy to understand.

**Example 6.1.4 (An upper-triangular action).** The map

$$
T(x,y)=(2x+y,3y)
$$

has the eigenpairs

$$
T(1,0)=2(1,0),\qquad T(1,1)=3(1,1).
$$

The eigenvectors need not lie on coordinate axes even when the eigenvalues appear on a matrix diagonal.

## 6.1.2 — Left and right eigenvectors

**Definition 6.1.5.** An ordinary column eigenvector is a **right eigenvector**. A nonzero row vector $w^{\mathsf T}$ is a **left eigenvector** of $A$ for $\lambda$ when

$$
w^{\mathsf T}A=\lambda w^{\mathsf T}.
$$

Taking transposes yields

$$
A^{\mathsf T}w=\lambda w.
$$

Thus left eigenvectors of $A$ are transpose-related to right eigenvectors of $A^{\mathsf T}$. Since

$$
\det(\lambda I-A^{\mathsf T})
=\det((\lambda I-A)^{\mathsf T})
=\det(\lambda I-A),
$$

$A$ and $A^{\mathsf T}$ have the same eigenvalues, though their right eigenvectors need not be equal. Over $\mathbb C$, a **left adjoint eigenvector** is sometimes written $w^*A=\lambda w^*$; this is a different convention involving conjugate transpose, and one should keep the distinction in mind.

## 6.1.3 — Eigenspaces, kernels, and singularity

**Definition 6.1.6 (Eigenspace).** The eigenspace corresponding to a scalar $\lambda$ is

$$
E_\lambda(T)=\{v\in V:T(v)=\lambda v\}
=\ker(T-\lambda I).
$$

Its nonzero elements are the eigenvectors for $\lambda$. The eigenspace contains the zero vector as well.

**Proposition 6.1.7.** For any $\lambda\in K$, the set $E_\lambda(T)$ is stable under linear combinations. It is nonzero if and only if $\lambda$ is an eigenvalue.

*Proof.* If $T(u)=\lambda u$ and $T(v)=\lambda v$, then

$$
T(au+bv)=aT(u)+bT(v)=\lambda(au+bv).
$$

The remaining claim follows directly from the definition. $\square$

**Theorem 6.1.8 (Eigenvalue criterion).** Suppose $V$ has dimension $n$ and $A$ represents $T$ in a basis. For $\lambda\in K$ the following are equivalent:

$$
\begin{aligned}
&\lambda\text{ is an eigenvalue of }T;\\
&\ker(T-\lambda I)\neq\{0\};\\
&T-\lambda I\text{ is not invertible};\\
&A-\lambda I\text{ is singular};\\
&\det(\lambda I-A)=0.
\end{aligned}
$$

*Proof.* The eigenvalue equation is equivalent to $(T-\lambda I)v=0$ with $v\neq0$. In finite dimension the corresponding operator is invertible exactly when its kernel is zero, equivalently when its representing matrix has nonzero determinant. $\square$

**Example 6.1.9 (A full eigenspace).** If $T=2I$ on $K^2$, then every nonzero vector is an eigenvector for the only eigenvalue, $2$, and

$$
E_2(T)=K^2.
$$

**Example 6.1.10 (Projection).** The projection

$$
\pi(x,y,z)=(x,y,0)
$$

has eigenspaces

$$
E_1(\pi)=\left\{\begin{pmatrix}x\\y\\0\end{pmatrix}:x,y\in K\right\},
\qquad
E_0(\pi)=\left\{\begin{pmatrix}0\\0\\z\end{pmatrix}:z\in K\right\}.
$$

The trivial space $V=\{0\}$, if included, has no eigenvalues because it contains no nonzero vectors.

## 6.1.4 — Characteristic polynomial

**Definition 6.1.11.** For $A\in M_n(K)$ define the **characteristic polynomial**

$$
\boxed{\chi_A(t)=\det(tI_n-A).}
$$

For an operator $T$ we set $\chi_T=\chi_A$ using any basis. This is well-defined, as proved below. With this sign convention $\chi_A$ is **monic** of degree $n$; the alternative convention $\det(A-tI)$ differs by the factor $(-1)^n$.

From the determinant expansion, its coefficients are polynomials in the entries of $A$:

$$
\chi_A(t)=t^n-c_1t^{n-1}+c_2t^{n-2}-\cdots+(-1)^n c_n,
$$

where $c_1=\operatorname{tr}(A)$ and $c_n=\det(A)$. In particular,

$$
\boxed{\chi_A(\lambda)=0\iff\lambda\text{ is an eigenvalue of }A.}
$$

**Example 6.1.12 (The general $2\times2$ case).** For

$$
A=\begin{pmatrix}a&b\\c&d\end{pmatrix},
$$

we have

$$
\begin{aligned}
\chi_A(t)&=\det\begin{pmatrix}t-a&-b\\-c&t-d\end{pmatrix}\\
&=(t-a)(t-d)-bc\\
&=t^2-(a+d)t+(ad-bc)\\
&=t^2-\operatorname{tr}(A)t+\det(A).
\end{aligned}
$$

This exhibits the trace and determinant as invariants encoded by the characteristic polynomial.

**Example 6.1.13 (Triangular matrices).** If $A$ is upper or lower triangular with diagonal entries $a_{11},\ldots,a_{nn}$, then

$$
\chi_A(t)=\prod_{j=1}^n(t-a_{jj}).
$$

The diagonal entries are exactly the eigenvalues, counted with algebraic multiplicities.

## 6.1.5 — Computing eigenvalues and eigenspaces

Consider the matrix from the supplied notes,

$$
A=\begin{pmatrix}2&2\\1&3\end{pmatrix}.
$$

The characteristic equation is

$$
\begin{aligned}
0&=\det(tI-A)
=\begin{vmatrix}t-2&-2\\-1&t-3\end{vmatrix}\\
&=(t-2)(t-3)-2\\
&=t^2-5t+4=(t-1)(t-4).
\end{aligned}
$$

The eigenvalues are $1$ and $4$. For $\lambda=1$ solve

$$
(A-I)\begin{pmatrix}x\\y\end{pmatrix}
=\begin{pmatrix}1&2\\1&2\end{pmatrix}
\begin{pmatrix}x\\y\end{pmatrix}=0.
$$

Therefore $x=-2y$ and

$$
E_1(A)=\operatorname{span}\left\{\begin{pmatrix}-2\\1\end{pmatrix}\right\}.
$$

For $\lambda=4$ we solve

$$
(A-4I)\begin{pmatrix}x\\y\end{pmatrix}
=\begin{pmatrix}-2&2\\1&-1\end{pmatrix}
\begin{pmatrix}x\\y\end{pmatrix}=0,
$$

which gives $x=y$ and

$$
E_4(A)=\operatorname{span}\left\{\begin{pmatrix}1\\1\end{pmatrix}\right\}.
$$

The method is systematic: first find the roots of $\chi_A$, then compute $\ker(A-\lambda I)$ for each root. We shall use these same eigenvectors to diagonalise the matrix in §6.2.

## 6.1.6 — Similarity and independence of coordinates

**Theorem 6.1.14 (Similarity invariance).** If

$$
B=P^{-1}AP,\qquad P\in\operatorname{GL}_n(K),
$$

then

$$
\begin{aligned}
\chi_B(t)
&=\det(tI-P^{-1}AP)\\
&=\det(P^{-1}(tI-A)P)\\
&=\det(P^{-1})\det(tI-A)\det(P)\\
&=\chi_A(t).
\end{aligned}
$$

Consequently, similar matrices have the same eigenvalues, characteristic polynomial, trace and determinant. In particular, $\chi_T$ does not depend on the basis used to represent $T$.

Their **coordinate eigenvectors** need not be the same: if $Av=\lambda v$, then

$$
B(P^{-1}v)=P^{-1}AP(P^{-1}v)=\lambda P^{-1}v.
$$

Thus an eigenvector is transformed by the coordinate change $P^{-1}$. Equality of characteristic polynomials is necessary but **not sufficient** for similarity (see §§6.2 and 6.4).

## 6.1.7 — The underlying field matters

The existence of an eigenvalue in $K$ depends on whether the characteristic polynomial has a root in $K$.

**Example 6.1.15 (A quarter-turn).** On $\mathbb R^2$ consider

$$
R=\begin{pmatrix}0&-1\\1&0\end{pmatrix},\qquad R(x,y)=(-y,x).
$$

Since

$$
\chi_R(t)=t^2+1,
$$

there are no real eigenvalues or nonzero real eigenvectors. Over $\mathbb C$, however,

$$
\lambda_+=i,\quad v_+=\begin{pmatrix}1\\-i\end{pmatrix};
\qquad
\lambda_-=-i,\quad v_-=\begin{pmatrix}1\\i\end{pmatrix},
$$

and direct multiplication verifies $Rv_\pm=\lambda_\pm v_\pm$. More generally, a planar rotation by angle $\theta$ has

$$
R_\theta=\begin{pmatrix}\cos\theta&-\sin\theta\\\sin\theta&\cos\theta\end{pmatrix},\qquad
\chi_{R_\theta}(t)=t^2-2(\cos\theta)t+1,
$$

with complex eigenvalues $e^{\pm i\theta}$. It has real eigenvalues only when $\theta$ is an integer multiple of $\pi$.

**Remark 6.1.16 (Algebraic closure).** The fundamental theorem of algebra guarantees a root of every nonconstant complex polynomial; thus every operator on a nonzero finite-dimensional **complex** vector space admits an eigenvalue. Over an arbitrary field this need not hold, although a polynomial splits into linear factors over a suitable algebraic closure $\overline K$. Having eigenvalues over $\overline K$ does *not* by itself guarantee diagonalizability (see §6.2).

## 6.1.8 — Trace, determinant and algebraic multiplicity

Let $\lambda_1,\ldots,\lambda_n$ be all the roots of the characteristic polynomial in a splitting field, **repeated according to multiplicity**. Then

$$
\chi_A(t)=\prod_{j=1}^n(t-\lambda_j),\qquad
\boxed{\operatorname{tr}(A)=\sum_{j=1}^n\lambda_j},\qquad
\boxed{\det(A)=\prod_{j=1}^n\lambda_j}.
$$

One proof uses the comparison of coefficients with the monic characteristic polynomial. Alternatively, once $A$ is triangularised over the splitting field (the criterion is established in §6.2), both identities follow by reading its diagonal entries.

**Definition 6.1.17.** The **algebraic multiplicity** $m_a(\lambda)$ is the multiplicity of $\lambda$ as a root of $\chi_A(t)$. The **geometric multiplicity** is

$$
m_g(\lambda)=\dim E_\lambda(A)=\dim\ker(A-\lambda I).
$$

For an eigenvalue, $1\le m_g(\lambda)\le m_a(\lambda)$; the proof and its consequences for diagonalisation are given in §6.2.

## 6.1.9 — Eigenvalues under elementary operations on an operator

Suppose $Av=\lambda v$ with $v\neq0$. Then

$$
\begin{aligned}
(A+cI)v&=(\lambda+c)v,\\
(cA)v&=c\lambda v,\\
A^kv&=\lambda^kv\quad(k\ge0),\\
p(A)v&=p(\lambda)v\quad(p\in K[t]).
\end{aligned}
$$

If $A$ is invertible, then $\lambda\neq0$ and

$$
A^{-1}v=\lambda^{-1}v.
$$

These identities predict some eigenpairs of matrix functions. In §6.3 we will study polynomial identities that hold **on the entire space**, not merely on eigenvectors.

## 6.1.10 — The spectral question beyond the characteristic polynomial

Characteristic roots and their multiplicities are similarity invariants, but they do not completely classify operators. For example,

$$
A=\begin{pmatrix}0&0\\0&0\end{pmatrix},
\qquad B=\begin{pmatrix}0&1\\0&0\end{pmatrix}
$$

both satisfy $\chi(t)=t^2$, yet $A$ and $B$ are not similar: $A$ is the zero map and $B$ is not. Their eigenspaces have different dimensions, and their **generalised** eigenspaces will reveal still more information.

This leads to the progression of the remaining sections: eigenbases and diagonalisation (§6.2), polynomial identities (§6.3), Jordan chains (§6.4), and functions of an operator (§6.5).

- [Exercises]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/01-eigenvalues-eigenvectors-and-characteristic-polynomials/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/01-eigenvalues-eigenvectors-and-characteristic-polynomials/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/01-eigenvalues-eigenvectors-and-characteristic-polynomials/references/' | relative_url }})

[Back to Eigenvalues and Canonical Forms]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/' | relative_url }})

</article>
