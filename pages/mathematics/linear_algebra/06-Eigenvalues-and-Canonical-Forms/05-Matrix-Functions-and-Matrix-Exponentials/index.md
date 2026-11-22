---
layout: default
title: "6.5: Matrix Functions and Matrix Exponentials"
permalink: /pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/05-matrix-functions-and-matrix-exponentials/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/05-matrix-functions-and-matrix-exponentials/' | relative_url }}">← Matrix Functions and Matrix Exponentials</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 6.5</div>
  <h1>Matrix Functions and Matrix Exponentials</h1>
</div>

<article class="article" markdown="1">

# 6.5 — Matrix Functions and Matrix Exponentials

The canonical forms developed in §§6.2–6.4 allow us to apply functions to a matrix. For diagonal matrices this means evaluating a function at each eigenvalue. For non-diagonalisable matrices, **derivatives** of the function appear along the superdiagonals of Jordan blocks. The matrix exponential is the central example, especially for linear differential equations.

Throughout, matrices are square over $\mathbb C$, unless otherwise specified. Statements involving real matrices remain real whenever their defining series have real coefficients.

## 6.5.1 — Polynomial functions and similarity

If $p(t)=\sum_{j=0}^d c_jt^j$, define

$$
p(A)=\sum_{j=0}^d c_jA^j.
$$

For any invertible $P$ and $J=P^{-1}AP$, the identity

$$
A^k=PJ^kP^{-1}
$$

implies

$$
\boxed{p(A)=Pp(J)P^{-1}.}
$$

This principle extends from polynomials to functions defined by convergent power series, and motivates the use of a canonical form in functional calculus.

**Proposition 6.5.1 (Reduction modulo the minimal polynomial).** If $p=q m_A+r$ with $\deg r<\deg m_A$, then

$$
p(A)=r(A).
$$

*Proof.* The defining identity $m_A(A)=0$ gives

$$
p(A)=q(A)m_A(A)+r(A)=r(A).
$$

Thus every polynomial of $A$ can be represented by one of degree below $\deg m_A$.

## 6.5.2 — Powers of Jordan blocks

Write a Jordan block as

$$
J_r(\lambda)=\lambda I_r+N_r,\qquad N_r^r=0.
$$

Because the two summands commute, the ordinary binomial theorem applies:

$$
\boxed{
J_r(\lambda)^k
=\sum_{j=0}^{\min(k,r-1)}\binom{k}{j}\lambda^{k-j}N_r^j,
\qquad k\in\mathbb N_0.
}
$$

If $\lambda\neq0$, the analogous formula holds for any integer $k$, using the generalised binomial coefficients and the finite sum $j=0,\ldots,r-1$.

**Example 6.5.2.** For

$$
J=J_3(\lambda)=\begin{pmatrix}\lambda&1&0\\0&\lambda&1\\0&0&\lambda\end{pmatrix},
$$

we have

$$
\boxed{
J^k=\begin{pmatrix}
\lambda^k&k\lambda^{k-1}&\binom{k}{2}\lambda^{k-2}\\
0&\lambda^k&k\lambda^{k-1}\\
0&0&\lambda^k
\end{pmatrix}
}
$$

for $k\ge2$, and the original finite-sum formula covers $k=0,1$ and $\lambda=0$ without interpreting negative powers of zero.

**Proposition 6.5.3 (Powers through Jordan form).** If $A=PJP^{-1}$, then

$$
A^k=P\operatorname{diag}\big(J_{r_1}(\lambda_1)^k,\ldots,J_{r_q}(\lambda_q)^k\big)P^{-1}.
$$

This explains why nontrivial Jordan blocks introduce **polynomial factors in $k$** multiplying the geometric factors $\lambda^k$.

## 6.5.3 — Power series and the matrix exponential

**Definition 6.5.4 (Exponential).** For any $A\in M_n(\mathbb C)$ and $t\in\mathbb C$,

$$
\boxed{e^{tA}=\exp(tA)=\sum_{k=0}^\infty\frac{t^kA^k}{k!}.}
$$

The series converges absolutely for every fixed $A$ and $t$. Indeed, for any submultiplicative matrix norm,

$$
\sum_{k=0}^\infty\left\|\frac{t^kA^k}{k!}\right\|
\le\sum_{k=0}^\infty\frac{|t|^k\|A\|^k}{k!}=e^{|t|\|A\|}<\infty.
$$

Therefore entrywise convergence and termwise differentiation are justified, uniformly for $t$ on bounded sets.

**Example 6.5.5 (Diagonal matrix).** If $D=\operatorname{diag}(\lambda_1,\ldots,\lambda_n)$, then

$$
\boxed{e^{tD}=\operatorname{diag}(e^{t\lambda_1},\ldots,e^{t\lambda_n}).}
$$

If $A=PDP^{-1}$ is diagonalisable, it follows that

$$
\boxed{e^{tA}=P\operatorname{diag}(e^{t\lambda_1},\ldots,e^{t\lambda_n})P^{-1}.}
$$

## 6.5.4 — Fundamental identities of the matrix exponential

**Theorem 6.5.6.** For every square $A$, and scalars $s,t$,

$$
\begin{aligned}
e^{0A}&=I,\\
e^{(s+t)A}&=e^{sA}e^{tA},\\
(e^{tA})^{-1}&=e^{-tA},\\
\frac{d}{dt}e^{tA}&=Ae^{tA}=e^{tA}A.
\end{aligned}
$$

Moreover, for invertible $P$,

$$
e^{PAP^{-1}}=Pe^AP^{-1}.
$$

If $AB=BA$, then

$$
\boxed{e^{A+B}=e^Ae^B=e^Be^A.}
$$

*Proof.* The first identity is immediate from the series. The second follows by collecting terms in the Cauchy product of two absolutely convergent series (or by the binomial theorem for the commuting matrices $sA,tA$). Taking $s=-t$ gives the inverse. Termwise differentiation gives the derivative identity. Similarity follows by the series and $ (PAP^{-1})^k=PA^kP^{-1} $. Finally, the commuting case allows the binomial expansion of $(A+B)^k$. $\square$

**Warning.** The identity $e^{A+B}=e^Ae^B$ is **not generally true** when $A$ and $B$ do not commute. Matrix multiplication is noncommutative; the scalar exponential law needs this additional hypothesis.

**Corollary 6.5.7.** For any scalar $c$,

$$
e^{A+cI}=e^Ae^c.
$$

The scalar $e^c$ multiplies the identity matrix, so equivalently $e^{A+cI}=e^c e^A$.

## 6.5.5 — Exponential of a Jordan block

For $J_r(\lambda)=\lambda I+N_r$ with $N_r^r=0$, the scalar and nilpotent parts commute. Hence

$$
\begin{aligned}
e^{tJ_r(\lambda)}
&=e^{t\lambda I}e^{tN_r}\\
&=e^{\lambda t}\sum_{j=0}^{r-1}\frac{t^j}{j!}N_r^j.
\end{aligned}
$$

**Example 6.5.8 (A size-three block).**

$$
\boxed{
e^{tJ_3(\lambda)}
=e^{\lambda t}
\begin{pmatrix}
1&t&\frac{t^2}{2}\\
0&1&t\\
0&0&1
\end{pmatrix}.
}
$$

Consequently, for a matrix with Jordan form $A=PJP^{-1}$,

$$
\boxed{e^{tA}=Pe^{tJ}P^{-1},}
$$

where $e^{tJ}$ is block diagonal with one explicitly computable block for each Jordan block of $J$.

The appearance of factors $t,t^2/2!,\ldots$ is not a computational accident: it is the analytic signature of **generalised eigenvectors**.

## 6.5.6 — General analytic functions on Jordan blocks

Suppose $f$ is analytic in a neighbourhood of $\lambda$. Its Taylor series gives

$$
f(\lambda+z)=\sum_{j=0}^\infty\frac{f^{(j)}(\lambda)}{j!}z^j.
$$

Replacing $z$ by the nilpotent matrix $N_r$ truncates the series exactly:

$$
\boxed{
f(J_r(\lambda))
=\sum_{j=0}^{r-1}\frac{f^{(j)}(\lambda)}{j!}N_r^j.
}
$$

**Theorem 6.5.9 (Jordan functional calculus).** If $A=PJP^{-1}$ and $f$ is analytic in neighbourhoods of all the eigenvalues, define

$$
\boxed{f(A)=Pf(J)P^{-1},}
$$

with $f(J)$ evaluated blockwise by the formula above. The definition agrees with polynomial evaluation, and with a convergent power-series definition whenever the latter is available.

*Justification.* On each Jordan block, Taylor expansion of $f$ at the eigenvalue involves the nilpotent part $N_r$, whose powers vanish at order $r$. Similarity transports the result to $A$. The formula is independent of the chosen Jordan basis because it agrees with Hermite polynomial interpolation modulo the minimal polynomial.

**Example 6.5.10 (Sine and cosine).** The entire matrix functions

$$
\cos A=\sum_{k=0}^\infty\frac{(-1)^kA^{2k}}{(2k)!},\qquad
\sin A=\sum_{k=0}^\infty\frac{(-1)^kA^{2k+1}}{(2k+1)!}
$$

satisfy, on a size-two Jordan block,

$$
\cos J_2(\lambda)
=\begin{pmatrix}\cos\lambda&-\sin\lambda\\0&\cos\lambda\end{pmatrix},
\qquad
\sin J_2(\lambda)
=\begin{pmatrix}\sin\lambda&\cos\lambda\\0&\sin\lambda\end{pmatrix}.
$$

The off-diagonal entries are the derivatives of the scalar functions at $\lambda$.

**Remark 6.5.11 (Rational functions and inverses).** If $r(t)=p(t)/q(t)$ and $q(A)$ is invertible, one may define $r(A)=p(A)q(A)^{-1}$. In particular, the **resolvent** $(zI-A)^{-1}$ exists when $z$ is not an eigenvalue and is a rational function of the entries of $zI-A$. It has poles at characteristic roots, with pole orders governed by the largest Jordan blocks.

## 6.5.7 — Trace, determinant, and the exponential

**Proposition 6.5.12.** For every complex square matrix,

$$
\boxed{\det(e^A)=e^{\operatorname{tr}A}.}
$$

*Proof.* By triangularisation, choose $A=PTP^{-1}$ with $T$ upper triangular and diagonal entries $\lambda_1,\ldots,\lambda_n$. Then $e^T$ is upper triangular with diagonal entries $e^{\lambda_1},\ldots,e^{\lambda_n}$. Similarity invariance of determinant gives

$$
\det(e^A)=\prod_{j=1}^n e^{\lambda_j}
=e^{\sum_j\lambda_j}=e^{\operatorname{tr}A}.
$$

This identity also holds for real matrices. $\square$

Thus $e^A$ is always invertible, even when $A$ is singular. For real $A$, its determinant is positive:

$$
\det(e^A)=e^{\operatorname{tr}A}>0.
$$

Not every invertible real matrix can therefore be the exponential of a real matrix.

## 6.5.8 — Rotations as exponentials

Let

$$
J=\begin{pmatrix}0&-1\\1&0\end{pmatrix},\qquad J^2=-I.
$$

Separating even and odd powers in the exponential series,

$$
\begin{aligned}
e^{\theta J}
&=\left(\sum_{k=0}^\infty\frac{(-1)^k\theta^{2k}}{(2k)!}\right)I
+\left(\sum_{k=0}^\infty\frac{(-1)^k\theta^{2k+1}}{(2k+1)!}\right)J\\
&=\cos\theta\,I+\sin\theta\,J\\
&=\boxed{\begin{pmatrix}\cos\theta&-\sin\theta\\\sin\theta&\cos\theta\end{pmatrix}}.
\end{aligned}
$$

Thus the rotation through angle $\theta$ is the exponential of its infinitesimal rotation generator $J$.

## 6.5.9 — Linear systems of ordinary differential equations

Consider the constant-coefficient initial-value problem

$$
\frac{dy}{dt}=Ay(t),\qquad y(0)=y_0\in\mathbb C^n.
$$

**Theorem 6.5.13.** Its unique solution is

$$
\boxed{y(t)=e^{tA}y_0.}
$$

*Proof.* Termwise differentiation gives

$$
\frac{d}{dt}(e^{tA}y_0)=Ae^{tA}y_0=Ay(t),\qquad y(0)=Iy_0=y_0.
$$

For uniqueness, if $z(t)$ solves the same problem, differentiate $e^{-tA}z(t)$:

$$
\frac{d}{dt}(e^{-tA}z(t))
=-Ae^{-tA}z(t)+e^{-tA}Az(t)=0.
$$

The expression is constant and equals $y_0$ at $t=0$, so $z(t)=e^{tA}y_0$. $\square$

**Corollary 6.5.14 (Inhomogeneous system).** For

$$
y'(t)=Ay(t)+g(t),\qquad y(0)=y_0,
$$

with continuous $g$, the variation-of-constants formula is

$$
\boxed{y(t)=e^{tA}y_0+\int_0^t e^{(t-s)A}g(s)\,ds.}
$$

A differentiation check verifies the formula.

## 6.5.10 — Higher-order scalar equations and companion matrices

A scalar constant-coefficient differential equation can be converted into a first-order matrix system. Consider

$$
y^{(n)}+a_{n-1}y^{(n-1)}+\cdots+a_1y'+a_0y=0.
$$

Set

$$
X(t)=\begin{pmatrix}y(t)\\y'(t)\\\vdots\\y^{(n-1)}(t)\end{pmatrix}.
$$

Then

$$
X'(t)=CX(t),\qquad
C=\begin{pmatrix}
0&1&0&\cdots&0\\
0&0&1&\ddots&\vdots\\
\vdots&&\ddots&\ddots&0\\
0&\cdots&0&0&1\\
-a_0&-a_1&\cdots&-a_{n-2}&-a_{n-1}
\end{pmatrix},
$$

and the solution is

$$
X(t)=e^{tC}X(0).
$$

The characteristic polynomial of the companion matrix is exactly

$$
\chi_C(\lambda)=\lambda^n+a_{n-1}\lambda^{n-1}+\cdots+a_0.
$$

**Example 6.5.15.** The equation

$$
y''+3y'+2y=0
$$

is equivalent to

$$
X'=\begin{pmatrix}0&1\\-2&-3\end{pmatrix}X.
$$

The matrix has eigenvalues $-1$ and $-2$, so the scalar solutions take the form

$$
y(t)=c_1e^{-t}+c_2e^{-2t},
$$

with the coefficients determined by $y(0)$ and $y'(0)$. Repeated roots lead to Jordan blocks and therefore terms such as $te^{\lambda t}$ and, for higher blocks, $t^je^{\lambda t}$.

## 6.5.11 — Putting canonical forms to work

The same strategy now applies to a large class of matrix problems:

1. Find the characteristic polynomial and eigenvalues (§6.1).
2. Check whether the eigenspaces give a diagonal basis (§6.2).
3. Use the minimal polynomial to detect nontrivial Jordan structure (§6.3).
4. If necessary, construct generalised eigenvector chains and Jordan form (§6.4).
5. Evaluate powers or analytic functions block by block, and conjugate back to the original coordinates.

For diagonal matrices, applying $f$ acts entry by entry on the eigenvalues. For a Jordan block, the extra entries are controlled by derivatives of $f$. This is the central bridge from the algebra of eigenvectors to the analysis of differential equations and matrix evolution.


- [Exercises]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/05-matrix-functions-and-matrix-exponentials/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/05-matrix-functions-and-matrix-exponentials/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/05-matrix-functions-and-matrix-exponentials/references/' | relative_url }})

[Back to Eigenvalues and Canonical Forms]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/' | relative_url }})

</article>
