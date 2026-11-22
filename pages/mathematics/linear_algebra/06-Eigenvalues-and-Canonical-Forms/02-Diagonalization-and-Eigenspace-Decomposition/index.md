---
layout: default
title: "6.2: Diagonalization and Eigenspace Decomposition"
permalink: /pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/02-diagonalization-and-eigenspace-decomposition/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/02-diagonalization-and-eigenspace-decomposition/' | relative_url }}">← Diagonalization and Eigenspace Decomposition</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 6.2</div>
  <h1>Diagonalization and Eigenspace Decomposition</h1>
</div>

<article class="article" markdown="1">

# 6.2 — Diagonalization and Eigenspace Decomposition

Diagonalisation asks whether an operator can be described by independent scalar actions along a suitable basis. It is a classification problem **under similarity**, and therefore more restrictive than row or column equivalence. We retain the notation of §6.1, with $T:V\to V$ and $A$ a representing matrix.

## 6.2.1 — Independence of eigenvectors for distinct eigenvalues

**Theorem 6.2.1.** Let $v_1,\ldots,v_r$ be eigenvectors of $T$ corresponding to pairwise distinct eigenvalues $\lambda_1,\ldots,\lambda_r$. Then the vectors $v_1,\ldots,v_r$ are linearly independent.

*Proof (induction).* The assertion holds for one nonzero vector. Assume it holds for $r-1$ eigenvectors, and suppose

$$
c_1v_1+\cdots+c_rv_r=0.
\tag{6.2.1}
$$

Applying $T$ gives

$$
c_1\lambda_1v_1+\cdots+c_r\lambda_rv_r=0.
\tag{6.2.2}
$$

Subtract $\lambda_r$ times (6.2.1) from (6.2.2):

$$
\sum_{j=1}^{r-1}c_j(\lambda_j-\lambda_r)v_j=0.
$$

The induction hypothesis and distinctness of the eigenvalues imply $c_j=0$ for $j<r$. Equation (6.2.1) then yields $c_rv_r=0$, hence $c_r=0$. $\square$

*An alternative Vandermonde proof.* From $\sum_j c_jv_j=0$, applying $I,T,\ldots,T^{r-1}$ yields

$$
\begin{pmatrix}
1&1&\cdots&1\\
\lambda_1&\lambda_2&\cdots&\lambda_r\\
\vdots&\vdots&&\vdots\\
\lambda_1^{r-1}&\lambda_2^{r-1}&\cdots&\lambda_r^{r-1}
\end{pmatrix}
\begin{pmatrix}c_1v_1\\c_2v_2\\\vdots\\c_rv_r\end{pmatrix}=0.
$$

Its determinant is $\prod_{i<j}(\lambda_j-\lambda_i)\neq0$, so all $c_jv_j$, and thus all $c_j$, vanish. This reformulates the induction argument using the Vandermonde determinant developed in the determinant chapter.

**Corollary 6.2.2.** Eigenspaces for distinct eigenvalues form a direct sum:

$$
E_{\lambda_1}(T)+\cdots+E_{\lambda_s}(T)
=E_{\lambda_1}(T)\oplus\cdots\oplus E_{\lambda_s}(T).
$$

Consequently,

$$
\sum_{j=1}^s\dim E_{\lambda_j}(T)\le\dim V.
$$

The directness is proved by applying the preceding theorem to one vector chosen from each nonzero component of a hypothetical linear relation.

## 6.2.2 — What it means to diagonalise

**Definition 6.2.3.** A linear operator $T$ is **diagonalisable over $K$** if there is a basis of $V$ in which its matrix is diagonal. Equivalently, a matrix $A\in M_n(K)$ is diagonalisable over $K$ when there exist an invertible matrix $P\in\operatorname{GL}_n(K)$ and a diagonal matrix $D$ such that

$$
\boxed{P^{-1}AP=D}\qquad\Longleftrightarrow\qquad A=PDP^{-1}.
$$

**Theorem 6.2.4 (Eigenbasis criterion).** An operator $T$ is diagonalisable if and only if $V$ has a basis consisting of eigenvectors of $T$.

*Proof.* If $\mathcal B=(v_1,\ldots,v_n)$ is an eigenbasis with $T(v_j)=\lambda_jv_j$, then the $j$th column of its representing matrix is $\lambda_je_j$, giving

$$
[T]_{\mathcal B}=\operatorname{diag}(\lambda_1,\ldots,\lambda_n).
$$

Conversely, if the representing matrix is diagonal, its columns imply $T(v_j)=\lambda_jv_j$ for each basis vector. $\square$

**Corollary 6.2.5.** The matrix $A$ is diagonalisable precisely when it admits $n$ linearly independent eigenvectors. Put these vectors as the columns of $P$, in the same order as their eigenvalues on the diagonal of $D$:

$$
AP=PD,\qquad
P=\begin{pmatrix}|&&|\\v_1&\cdots&v_n\\|&&|\end{pmatrix}.
$$

Do not confuse this similarity equation with the more general two-sided equivalence $Q^{-1}AP$ from the chapter on change of basis: the **same** basis must be used on the domain and codomain of an endomorphism.

## 6.2.3 — A complete diagonalisation calculation

Take the example from §6.1:

$$
A=\begin{pmatrix}2&2\\1&3\end{pmatrix},\qquad
v_1=\begin{pmatrix}-2\\1\end{pmatrix},\quad
v_2=\begin{pmatrix}1\\1\end{pmatrix}.
$$

The associated eigenvalues are $1$ and $4$. Set

$$
P=\begin{pmatrix}-2&1\\1&1\end{pmatrix},\qquad
P^{-1}=\begin{pmatrix}-\frac13&\frac13\\\frac13&\frac23\end{pmatrix},\qquad
D=\begin{pmatrix}1&0\\0&4\end{pmatrix}.
$$

One checks directly that

$$
AP=
\begin{pmatrix}2&2\\1&3\end{pmatrix}
\begin{pmatrix}-2&1\\1&1\end{pmatrix}
=\begin{pmatrix}-2&4\\1&4\end{pmatrix}
=PD,
$$

and therefore

$$
\boxed{P^{-1}AP=\begin{pmatrix}1&0\\0&4\end{pmatrix}.}
$$

This same procedure applies to any $n\times n$ matrix: compute the eigenvalues, solve each homogeneous eigenvector system, check that the combined eigenvectors form a basis, and then assemble $P$ and $D$.

**Example 6.2.6 (An upper-triangular matrix).** For

$$
A=\begin{pmatrix}3&2\\0&1\end{pmatrix}
$$

we have $v_3=(1,0)^{\mathsf T}$ and $v_1=(1,-1)^{\mathsf T}$. Thus

$$
P=\begin{pmatrix}1&1\\0&-1\end{pmatrix},\qquad
P^{-1}=P,\qquad
P^{-1}AP=\begin{pmatrix}3&0\\0&1\end{pmatrix}.
$$

The off-diagonal entry $2$ can be removed by changing basis because the eigenvalues are distinct.

## 6.2.4 — Algebraic and geometric multiplicities

Recall that the algebraic multiplicity $m_a(\lambda)$ counts the occurrences of $\lambda$ as a characteristic root, while the geometric multiplicity $m_g(\lambda)$ is the dimension of $E_\lambda(T)$.

**Proposition 6.2.7.** For every eigenvalue $\lambda$,

$$
\boxed{1\le m_g(\lambda)\le m_a(\lambda).}
$$

*Proof.* Choose a basis $v_1,\ldots,v_g$ of $E_\lambda(T)$ and extend it to a basis of $V$. In this basis the matrix is block upper triangular:

$$
[T]_{\mathcal B}=
\begin{pmatrix}\lambda I_g&C\\0&B\end{pmatrix}.
$$

Consequently,

$$
\chi_T(t)=(t-\lambda)^g\det(tI-B).
$$

The factor $(t-\lambda)^g$ shows that the algebraic multiplicity is at least $g=m_g(\lambda)$. Nontriviality of $E_\lambda$ gives $g\ge1$. $\square$

**Theorem 6.2.8 (Complete criterion).** An operator on an $n$-dimensional space is diagonalisable over $K$ if and only if its characteristic polynomial splits over $K$ as

$$
\chi_T(t)=\prod_{j=1}^{s}(t-\lambda_j)^{a_j},
\qquad \lambda_i\neq\lambda_j\ (i\neq j),
$$

and

$$
\boxed{\dim E_{\lambda_j}(T)=a_j\quad\text{for every }j.}
$$

Equivalently,

$$
V=E_{\lambda_1}(T)\oplus\cdots\oplus E_{\lambda_s}(T).
$$

*Proof.* If $T$ is diagonal in an eigenbasis, each diagonal entry contributes one dimension to the corresponding eigenspace, so $m_g=m_a$. Conversely, eigenspaces of distinct eigenvalues form a direct sum, and under the stated assumptions their dimensions total $\sum_j a_j=n$. Their combined bases therefore yield an eigenbasis. $\square$

**Corollary 6.2.9.** If $T$ has $n$ distinct eigenvalues in $K$, then it is diagonalisable. This is sufficient, **not necessary**: a scalar matrix has just one eigenvalue yet is diagonal already.

## 6.2.5 — Why diagonalisation can fail

**Example 6.2.10 (A nonzero nilpotent matrix).** Consider

$$
N=\begin{pmatrix}0&1\\0&0\end{pmatrix},\qquad N^2=0,\quad N\neq0.
$$

Its sole eigenvalue is $0$ with algebraic multiplicity $2$, but

$$
E_0(N)=\ker N=\operatorname{span}\left\{\begin{pmatrix}1\\0\end{pmatrix}\right\}
$$

has dimension $1$. Hence it is not diagonalisable. Alternatively, if it were similar to a diagonal matrix $D$, then $D^2=0$ would force $D=0$, contradicting $N\neq0$.

**Example 6.2.11 (Repeated eigenvalue, defective).** For

$$
A=\begin{pmatrix}2&1&0\\0&1&-1\\0&2&4\end{pmatrix},
$$

we obtain

$$
\chi_A(t)=(t-2)^2(t-3),\qquad
E_2(A)=\operatorname{span}\left\{\begin{pmatrix}1\\0\\0\end{pmatrix}\right\}.
$$

Therefore $m_g(2)=1<m_a(2)=2$ and $A$ is not diagonalisable.

**Example 6.2.12 (Repeated eigenvalue, still diagonalisable).** Let

$$
B=\begin{pmatrix}2&0&0\\0&1&1\\0&1&1\end{pmatrix}.
$$

Its eigenvalues are $2$ (twice) and $0$ (once). The eigenspaces are

$$
E_2(B)=\operatorname{span}\left\{
\begin{pmatrix}1\\0\\0\end{pmatrix},
\begin{pmatrix}0\\1\\1\end{pmatrix}\right\},
\qquad
E_0(B)=\operatorname{span}\left\{\begin{pmatrix}0\\1\\-1\end{pmatrix}\right\}.
$$

Their dimensions sum to $3$, so $B$ is diagonalisable.

**Example 6.2.13 (Real versus complex).** The real matrix

$$
R=\begin{pmatrix}0&-1&0\\1&0&0\\0&0&1\end{pmatrix}
$$

has eigenvalues $1,i,-i$. It is not diagonalisable **over $\mathbb R$**, since its characteristic polynomial does not split there; it is diagonalisable **over $\mathbb C$**, where the eigenvalues are distinct.

## 6.2.6 — Triangularisation and invariant subspaces

**Definition 6.2.14.** A subspace $W\subseteq V$ is **$T$-invariant** if $T(W)\subseteq W$. For a basis beginning with a basis of $W$, the representing matrix has block form

$$
[T]_{\mathcal B}=\begin{pmatrix}B&C\\0&D\end{pmatrix}.
$$

The upper-left block represents $T$ restricted to $W$; the lower-right block represents the induced operator on $V/W$. In general the upper-right block need not vanish. If both $W$ and a complementary subspace are invariant, the matrix is block diagonal.

**Theorem 6.2.15 (Triangularisation criterion).** An operator is representable by an upper-triangular matrix over $K$ if and only if its characteristic polynomial splits into linear factors over $K$.

*Proof.* For an upper-triangular matrix the characteristic polynomial is the product of $(t-a_{jj})$. Conversely, proceed by induction on $n=\dim V$. A root $\lambda\in K$ gives an eigenvector $v_1\neq0$. Extend $v_1$ to a basis; the matrix becomes

$$
\begin{pmatrix}\lambda&*\\0&B\end{pmatrix},
$$

and $\chi_T(t)=(t-\lambda)\chi_B(t)$. The polynomial $\chi_B$ also splits. By induction, change basis in the remaining $(n-1)$-dimensional quotient to make $B$ upper triangular, leaving the first basis vector intact. $\square$

In particular, **every complex matrix is triangularisable**. This does not imply that every complex matrix is diagonalisable: an upper-triangular matrix may possess non-removable superdiagonal entries.

## 6.2.7 — Spectral decomposition in the diagonalisable case

Suppose $T$ is diagonalisable, with *distinct* eigenvalues $\lambda_1,\ldots,\lambda_s$ and a direct sum decomposition into eigenspaces. There exist projection operators $\Pi_j$ satisfying

$$
\Pi_i\Pi_j=\delta_{ij}\Pi_j,\qquad
\sum_{j=1}^s\Pi_j=I,\qquad
T=\sum_{j=1}^s\lambda_j\Pi_j.
$$

One can construct the projections as polynomials in $T$:

$$
\boxed{\Pi_j=\prod_{k\neq j}\frac{T-\lambda_kI}{\lambda_j-\lambda_k}.}
$$

*Proof.* On any eigenvector $v$ belonging to $E_{\lambda_\ell}$, the polynomial on the right acts by $1$ when $\ell=j$ and by $0$ otherwise. Since eigenvectors form a basis, the right-hand side is the required projection. $\square$

This formula is the matrix analogue of Lagrange interpolation. It also yields, for every polynomial $p$,

$$
p(T)=\sum_{j=1}^s p(\lambda_j)\Pi_j.
$$

For the example of §6.2.3, the spectral projections are

$$
\Pi_1=\frac{4I-A}{3}=\frac13\begin{pmatrix}2&-2\\-1&1\end{pmatrix},
\qquad
\Pi_4=\frac{A-I}{3}=\frac13\begin{pmatrix}1&2\\1&2\end{pmatrix},
$$

and $A=\Pi_1+4\Pi_4$.

## 6.2.8 — Powers, inverses, and commuting maps

For $A=PDP^{-1}$ we have, whenever defined,

$$
A^k=PD^kP^{-1},\qquad
D^k=\operatorname{diag}(\lambda_1^k,\ldots,\lambda_n^k).
$$

If $A$ is invertible, this also holds for negative integer powers. If two diagonalisable operators **commute**, they admit a common eigenbasis (over a field where both diagonalise). To prove it, observe that an operator commuting with $T$ preserves each eigenspace of $T$, then diagonalise its restriction to each eigenspace.

Without commutativity, the sum or product of two diagonalisable matrices need not be diagonalisable. Scalar multiples, on the other hand, preserve diagonalisation immediately.

## 6.2.9 — Numerical connection: the method of powers

The eigenvector equation can be approached approximately by repeatedly applying the matrix. Suppose $A$ is diagonalisable and its eigenvalues can be ordered so that

$$
|\lambda_1|>|\lambda_2|\ge\cdots\ge|\lambda_n|,
$$

and the initial vector $v^{(0)}=\sum_j c_jv_j$ has $c_1\neq0$. Then

$$
A^kv^{(0)}=\lambda_1^k\left(c_1v_1+
\sum_{j=2}^n c_j\left(\frac{\lambda_j}{\lambda_1}\right)^kv_j\right).
$$

After normalisation, the direction approaches that of a dominant eigenvector, provided the usual nondegeneracy assumptions hold. The error in direction is asymptotically controlled by $|\lambda_2/\lambda_1|^k$. A basic iteration is

$$
w^{(k)}=\frac{v^{(k)}}{\|v^{(k)}\|},\qquad
v^{(k+1)}=Aw^{(k)}.
$$

Over $\mathbb R$ for a symmetric matrix, the Rayleigh quotient

$$
\rho(w)=\frac{w^{\mathsf T}Aw}{w^{\mathsf T}w}
$$

converges to the dominant eigenvalue under appropriate assumptions. For a general nonnormal matrix, convergence and eigenvalue estimation require more care.

**Example 6.2.16.** With

$$
A=\begin{pmatrix}3&0\\8&-1\end{pmatrix},\qquad
v^{(0)}=\begin{pmatrix}1\\1\end{pmatrix},
$$

unnormalised iterations begin

$$
v^{(1)}=\begin{pmatrix}3\\7\end{pmatrix},\qquad
v^{(2)}=\begin{pmatrix}9\\17\end{pmatrix},
$$

and approach the direction $(1,2)^{\mathsf T}$ associated with the dominant eigenvalue $3$. This is the consistent initial vector for the numerical output in the supplied material. A zero component in the dominant eigendirection prevents this convergence; repeated or equal-modulus leading eigenvalues also complicate the method.

The power method is conceptually useful, though practical eigenvalue solvers generally first reduce matrices to more structured forms and use more stable algorithms.

## 6.2.10 — Towards canonical forms

Diagonalisation captures the cases where ordinary eigenspaces fill the entire domain. When $m_g(\lambda)<m_a(\lambda)$, the missing directions can be recovered through **generalised eigenvectors**. To understand precisely which directions are missing, we first establish Cayley–Hamilton and the minimal polynomial in §6.3, and then construct Jordan chains in §6.4.


- [Exercises]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/02-diagonalization-and-eigenspace-decomposition/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/02-diagonalization-and-eigenspace-decomposition/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/02-diagonalization-and-eigenspace-decomposition/references/' | relative_url }})

[Back to Eigenvalues and Canonical Forms]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/' | relative_url }})

</article>
