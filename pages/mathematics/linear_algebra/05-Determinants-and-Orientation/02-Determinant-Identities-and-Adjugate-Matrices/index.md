---
layout: default
title: "5.2: Determinant Identities and Adjugate Matrices"
permalink: /pages/mathematics/linear_algebra/05-determinants-and-orientation/02-determinant-identities-and-adjugate-matrices/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/02-determinant-identities-and-adjugate-matrices/' | relative_url }}">← Determinant Identities and Adjugate Matrices</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 5.2</div>
  <h1>Determinant Identities and Adjugate Matrices</h1>
</div>

<article class="article" markdown="1">

# 5.2: Determinant Identities and Adjugate Matrices

This section establishes determinant identities, elimination methods, the Cauchy–Binet formula, minors, cofactors, Laplace expansion, adjugates and Cramer’s rule.


## 5.2.1 Fundamental determinant identities

The characterisation theorem gives the main computational rules almost immediately.

**Theorem 5.2.1 (Determinant identities).** For $A\in M_n(\mathbb{F})$:

**(D1) Normalisation and transpose.**

$$
\det(I_n)=1,
\qquad
\det(A^{\mathsf T})=\det(A).
$$

**(D2) Linear dependence.** If a row or column is a linear combination of the others, then

$$
\det(A)=0.
$$

In particular, a zero row, two equal rows, or two proportional rows force the determinant to vanish; analogous assertions hold for columns.

**(D3) Interchanging rows.** Swapping two distinct rows yields $A'$ with

$$
\det(A')=-\det(A).
$$

**(D4) Scaling a row.** Replacing one row by $\lambda$ times that row yields

$$
\det(A')=\lambda\det(A).
$$

**(D5) Adding a multiple of another row.** For $i\ne j$, the operation

$$
R_i\longleftarrow R_i+\lambda R_j
$$

preserves the determinant:

$$
\det(A')=\det(A).
$$

**(D6) Linearity in an individual row.** If row $i$ is $\mathbf u+\mathbf v$, then

$$
\det(R_1,\ldots,\mathbf u+\mathbf v,\ldots,R_n)
=\det(R_1,\ldots,\mathbf u,\ldots,R_n)
+\det(R_1,\ldots,\mathbf v,\ldots,R_n).
$$

Each row statement also has a column analogue.

**Proof.** Normalisation was established above. Transposition preserves the determinant by reindexing the Leibniz sum using $\sigma^{-1}$ and observing that $\operatorname{sgn}(\sigma^{-1})=\operatorname{sgn}(\sigma)$.

The linear-dependence claim follows from multilinearity and alternation: expand the dependent row as a linear combination of other rows; every term has a repeated row. Swapping rows changes sign by Lemma 5.1.3. Scaling a row extracts the scalar by multilinearity. Finally,

$$
\begin{aligned}
\det(\ldots,R_i+\lambda R_j,\ldots,R_j,\ldots)
={}&\det(\ldots,R_i,\ldots,R_j,\ldots)\\
&+\lambda\det(\ldots,R_j,\ldots,R_j,\ldots)
\end{aligned}
$$

and the second term is zero. $\square$

### 5.2.1.1 Elementary matrices

An **elementary matrix** is obtained by performing a single elementary row operation on $I_n$. Its determinant is determined by the type of operation:

| Elementary operation | Determinant of the elementary matrix |
|:--|:--:|
| Interchange $R_i$ and $R_j$ | $-1$ |
| Multiply $R_i$ by $\lambda\ne0$ | $\lambda$ |
| Replace $R_i$ by $R_i+\lambda R_j$, $i\ne j$ | $1$ |

For example,

$$
\det\begin{pmatrix}
1&0&0\\0&\lambda&0\\0&0&1
\end{pmatrix}=\lambda,
\qquad
\det\begin{pmatrix}
0&1&0\\1&0&0\\0&0&1
\end{pmatrix}=-1,
$$

and

$$
\det\begin{pmatrix}
1&0&0\\\lambda&1&0\\0&0&1
\end{pmatrix}=1.
$$

### 5.2.1.2 Scalar multiplication of the whole matrix

Multiplying the **whole** matrix by $\lambda$ multiplies **every** one of its $n$ rows by $\lambda$. Consequently,

$$
\boxed{\det(\lambda A)=\lambda^n\det(A).}
$$

This differs from scaling just one row, which contributes only one factor of $\lambda$.

## 5.2.2 Triangular matrices and computation by elimination

**Lemma 5.2.1 (Triangular determinant).** If $U=(u_{ij})$ is an upper-triangular matrix, then

$$
\boxed{\det(U)=\prod_{i=1}^{n}u_{ii}.}
$$

The same formula holds for lower-triangular matrices.

**Proof.** In the Leibniz formula for an upper-triangular matrix, a term

$$
\prod_{i=1}^{n}u_{i,\sigma(i)}
$$

can be nonzero only if $\sigma(i)\ge i$ for every $i$, because all entries below the diagonal vanish. Summing these inequalities and using the fact that $\sigma$ is a permutation gives

$$
\sum_{i=1}^{n}\sigma(i)=\sum_{i=1}^{n}i.
$$

The inequalities must therefore all be equalities, so $\sigma$ is the identity. Only the diagonal term remains. For lower-triangular matrices, apply the transpose identity. $\square$

### 5.2.2.1 The elimination algorithm

To evaluate $\det(A)$:

1. Apply Gaussian elimination to transform $A$ into an upper-triangular matrix $U$.
2. Keep a count $s$ of row interchanges.
3. Keep track of any row scalings by nonzero scalars $\lambda_1,\ldots,\lambda_t$.
4. Multiply the diagonal entries of $U$, then compensate for the row operations.

The resulting formula is

$$
\boxed{
\det(A)=(-1)^s
\frac{\prod_{i=1}^{n}u_{ii}}
{\prod_{k=1}^{t}\lambda_k}.
}
$$

In the common version of Gaussian elimination using only row swaps and adding multiples of rows, no row scaling occurs. The formula simplifies to

$$
\det(A)=(-1)^s\prod_{i=1}^{n}u_{ii}.
$$

A zero diagonal entry after triangularisation immediately gives determinant zero.

### 5.2.2.2 Example: elimination without interchanges

**Example 5.2.1.** Let

$$
A=\begin{pmatrix}
1&2&2\\
3&5&3\\
2&-6&1
\end{pmatrix}.
$$

Use determinant-preserving row additions:

$$
\begin{aligned}
\begin{pmatrix}
1&2&2\\3&5&3\\2&-6&1
\end{pmatrix}
&\xrightarrow{\substack{R_2\gets R_2-3R_1\\R_3\gets R_3-2R_1}}
\begin{pmatrix}
1&2&2\\0&-1&-3\\0&-10&-3
\end{pmatrix}\\[6pt]
&\xrightarrow{R_3\gets R_3-10R_2}
\begin{pmatrix}
1&2&2\\0&-1&-3\\0&0&27
\end{pmatrix}.
\end{aligned}
$$

No swaps or scalings occurred, so

$$
\boxed{\det(A)=1\cdot(-1)\cdot27=-27.}
$$

### 5.2.2.3 Example: tracking row interchanges

**Example 5.2.2.** Consider

$$
B=\begin{pmatrix}
3&2&0\\1&0&-1\\2&1&3
\end{pmatrix}.
$$

Swap the first and second rows, then eliminate the first-column entries:

$$
\begin{aligned}
B&\xrightarrow{R_1\leftrightarrow R_2}
\begin{pmatrix}
1&0&-1\\3&2&0\\2&1&3
\end{pmatrix}\\[5pt]
&\xrightarrow{\substack{R_2\gets R_2-3R_1\\R_3\gets R_3-2R_1}}
\begin{pmatrix}
1&0&-1\\0&2&3\\0&1&5
\end{pmatrix}.
\end{aligned}
$$

Swap rows two and three, then eliminate:

$$
\begin{aligned}
\begin{pmatrix}
1&0&-1\\0&2&3\\0&1&5
\end{pmatrix}
&\xrightarrow{R_2\leftrightarrow R_3}
\begin{pmatrix}
1&0&-1\\0&1&5\\0&2&3
\end{pmatrix}\\[5pt]
&\xrightarrow{R_3\gets R_3-2R_2}
\begin{pmatrix}
1&0&-1\\0&1&5\\0&0&-7
\end{pmatrix}.
\end{aligned}
$$

There were **two** row swaps, so the two sign changes cancel:

$$
\boxed{\det(B)=(-1)^2(1)(1)(-7)=-7.}
$$

## 5.2.3 Multiplicativity, inverses and similarity

The determinant is not additive as a function of matrices, but it is **multiplicative**. This is fundamental to its interpretation as a numerical invariant of linear transformations.

**Theorem 5.2.2 (Multiplicativity).** For any $A,B\in M_n(\mathbb F)$,

$$
\boxed{\det(AB)=\det(A)\det(B).}
$$

**Proof (using uniqueness of alternating multilinear forms).** Fix $A$ and define

$$
D(\mathbf b_1,\ldots,\mathbf b_n)
=\det(A\mathbf b_1,\ldots,A\mathbf b_n).
$$

Because $A$ acts linearly on each argument and the determinant is alternating and multilinear, $D$ is itself alternating and multilinear. The uniqueness argument from Theorem 5.1.2, without imposing normalisation, says that such a function must equal its value on the standard basis times the determinant:

$$
D(\mathbf b_1,\ldots,\mathbf b_n)
=D(\mathbf e_1,\ldots,\mathbf e_n)
\det(\mathbf b_1,\ldots,\mathbf b_n).
$$

But

$$
D(\mathbf e_1,\ldots,\mathbf e_n)=\det(A).
$$

Taking $\mathbf b_1,\ldots,\mathbf b_n$ to be the columns of $B$ therefore gives

$$
\det(AB)=\det(A)\det(B).
$$

$\square$

**Corollary 5.2.1 (Inverse determinant).** If $A$ is invertible, then

$$
1=\det(I_n)=\det(AA^{-1})
=\det(A)\det(A^{-1}).
$$

Therefore,

$$
\boxed{\det(A^{-1})=\frac{1}{\det(A)}.}
$$

**Corollary 5.2.2 (Similarity invariance).** If

$$
B=P^{-1}AP,
\qquad P\in GL_n(\mathbb F),
$$

then

$$
\begin{aligned}
\det(B)
&=\det(P^{-1})\det(A)\det(P)\\
&=\frac{1}{\det(P)}\det(A)\det(P)\\
&=\det(A).
\end{aligned}
$$

Hence

$$
\boxed{A\sim B\quad\Longrightarrow\quad\det(A)=\det(B).}
$$

The determinant is therefore an invariant of **similarity**, meaning it does not depend on the basis used to represent an endomorphism.

### 5.2.3.1 Permutation matrices and the sign homomorphism

For $\sigma\in S_n$, let $P_\sigma$ be the permutation matrix defined by

$$
P_\sigma\mathbf e_j=\mathbf e_{\sigma(j)}.
$$

Such a matrix has exactly one entry equal to $1$ in each row and in each column, and every other entry is $0$. Its determinant is

$$
\boxed{\det(P_\sigma)=\operatorname{sgn}(\sigma).}
$$

Furthermore,

$$
P_\sigma P_\tau=P_{\sigma\circ\tau},
$$

so multiplicativity recovers the permutation-sign identity:

$$
\operatorname{sgn}(\sigma\circ\tau)
=\operatorname{sgn}(\sigma)\operatorname{sgn}(\tau).
$$

## 5.2.4 The Cauchy–Binet formula

The product formula above is the **square-matrix case** of the more general Cauchy–Binet identity. In the source material, the name *Cauchy–Binet* is attached to the identity for two square matrices. The general result also applies to products whose two factors are rectangular, provided their product is square.

**Theorem 5.2.3 (Cauchy–Binet).** Let $1\le r\le m$, $A\in M_{r\times m}(\mathbb F)$, and $B\in M_{m\times r}(\mathbb F)$. For each subset $I=\{i_1<\cdots<i_r\}\subseteq\{1,\ldots,m\}$, let $A_{:,I}$ be the $r\times r$ submatrix of $A$ formed from columns indexed by $I$, and let $B_{I,:}$ be the $r\times r$ submatrix of $B$ formed from rows indexed by $I$. Then

$$
\boxed{
\det(AB)=\sum_{\substack{I\subseteq\{1,\ldots,m\}\\|I|=r}}
\det(A_{:,I})\,\det(B_{I,:}).
}
$$

**Proof.** Write $C=AB$, so that

$$
c_{ij}=\sum_{k=1}^{m}a_{ik}b_{kj}.
$$

Expand the determinant of $C$ by the Leibniz formula and distribute the products:

$$
\begin{aligned}
\det(AB)
&=\sum_{\sigma\in S_r}\operatorname{sgn}(\sigma)
\prod_{i=1}^{r}\left(\sum_{k_i=1}^{m}a_{i k_i}b_{k_i,\sigma(i)}\right)\\
&=\sum_{k_1,\ldots,k_r=1}^{m}
\left(\prod_{i=1}^{r}a_{i k_i}\right)
\left(\sum_{\sigma\in S_r}\operatorname{sgn}(\sigma)
\prod_{i=1}^{r}b_{k_i,\sigma(i)}\right).
\end{aligned}
$$

The inner sum is the determinant of the matrix with rows $k_1,\ldots,k_r$ selected from $B$ in that order. If two indices coincide, this determinant is zero. Thus only tuples of **distinct** indices contribute.

For any fixed $r$-element subset $I=\{i_1<\cdots<i_r\}$, collect all $r!$ orderings $k_j=i_{\tau(j)}$ with $\tau\in S_r$. Reordering the selected rows changes their determinant by $\operatorname{sgn}(\tau)$. Their combined contribution is

$$
\begin{aligned}
&\left(\sum_{\tau\in S_r}\operatorname{sgn}(\tau)
\prod_{j=1}^{r}a_{j,i_{\tau(j)}}\right)\det(B_{I,:})\\
&\qquad=\det(A_{:,I})\det(B_{I,:}).
\end{aligned}
$$

Summing over all such subsets proves the formula. $\square$

**Square case.** If $m=r=n$, the only admissible subset is $I=\{1,\ldots,n\}$. Hence

$$
\boxed{\det(AB)=\det(A)\det(B),\qquad A,B\in M_n(\mathbb F).}
$$

This is precisely the identity proved above. Alternatively, if $A$ and $B$ are invertible, write each as a product of elementary matrices. Since $\det(EC)=\det(E)\det(C)$ for any elementary matrix $E$, repeated application establishes multiplicativity. If either factor is singular, $AB$ is also singular and both sides vanish.

**Example 5.2.3 (Rectangular product).** Let

$$
A=\begin{pmatrix}1&0&2\\0&1&3\end{pmatrix},
\qquad
B=\begin{pmatrix}1&2\\3&4\\5&6\end{pmatrix}.
$$

The product and its determinant are

$$
AB=\begin{pmatrix}11&14\\18&22\end{pmatrix},
\qquad\det(AB)=11\cdot22-14\cdot18=-10.
$$

Cauchy–Binet gives the same result by summing the three choices of two columns of $A$ and the corresponding two rows of $B$:

$$
\begin{aligned}
\det(AB)
&=\det\begin{pmatrix}1&0\\0&1\end{pmatrix}
\det\begin{pmatrix}1&2\\3&4\end{pmatrix}\\
&\quad+\det\begin{pmatrix}1&2\\0&3\end{pmatrix}
\det\begin{pmatrix}1&2\\5&6\end{pmatrix}\\
&\quad+\det\begin{pmatrix}0&2\\1&3\end{pmatrix}
\det\begin{pmatrix}3&4\\5&6\end{pmatrix}\\
&=(-2)+3(-4)+(-2)(-2)=-10.
\end{aligned}
$$

The full formula is useful because it connects determinants of products to determinants of maximal square submatrices; this also underlies many rank inequalities.


## 5.2.5 Determinants, rank and invertibility

We return to the question that motivated the chapter. The determinant gives an exact algebraic test for nonsingularity.

**Theorem 5.2.4 (Determinant–rank criterion).** For an $n\times n$ matrix $A$ over a field,

$$
\boxed{\det(A)=0\quad\Longleftrightarrow\quad\operatorname{rank}(A)<n.}
$$

**Proof.** If $\operatorname{rank}(A)<n$, its rows are linearly dependent. One row can therefore be expressed as a linear combination of the others (after choosing a dependence relation with a nonzero coefficient). Property (D2) gives $\det(A)=0$.

Conversely, suppose $\det(A)=0$. Reduce $A$ to upper-triangular form $U$ by row swaps and row additions; each of these operations changes the determinant by at most a sign. Consequently,

$$
\det(U)=\pm\det(A)=0.
$$

Since $\det(U)=u_{11}\cdots u_{nn}$ and $\mathbb F$ is a field, at least one diagonal entry vanishes. An upper-triangular $n\times n$ matrix with a zero diagonal entry is singular, equivalently has rank below $n$. Elementary row operations preserve rank, so $\operatorname{rank}(A)=\operatorname{rank}(U)<n$. $\square$

**Corollary 5.2.3 (Invertibility criterion).** For $A\in M_n(\mathbb F)$, the following statements are equivalent:

$$
\boxed{
\begin{gathered}
\det(A)\ne0
\quad\Longleftrightarrow\quad
\operatorname{rank}(A)=n\\
\Longleftrightarrow\quad
\ker(A)=\{\mathbf0\}
\quad\Longleftrightarrow\quad
A^{-1}\text{ exists}.
\end{gathered}
}
$$

By the rank–nullity theorem,

$$
\operatorname{rank}(A)+\operatorname{nullity}(A)=n.
$$

Hence $\det(A)\ne0$ is also equivalent to $\operatorname{nullity}(A)=0$.

### 5.2.5.1 Consequences for linear systems

For the square system

$$
A\mathbf x=\mathbf b,
\qquad A\in M_n(\mathbb F),
$$

we have:

- If $\det(A)\ne0$, there is **exactly one solution for every** $\mathbf b$, namely $\mathbf x=A^{-1}\mathbf b$.
- If $\det(A)=0$, the homogeneous system has nonzero solutions. For a given $\mathbf b$, the system therefore has **either no solution or infinitely many solutions** when $\mathbb F$ is infinite (for example, $\mathbb R$ or $\mathbb C$).

Over a finite field, the second case has multiple solutions when it is consistent, but not infinitely many.

In particular,

$$
\det(A)\ne0
\quad\Longleftrightarrow\quad
\text{the linear map }\mathbf x\mapsto A\mathbf x
\text{ is bijective}.
$$

**Example 5.2.4 (A singular coefficient matrix).** Consider

$$
A=\begin{pmatrix}1&2\\2&4\end{pmatrix}.
$$

Here $\det(A)=4-4=0$, so the columns are dependent. The system

$$
\begin{cases}
x+2y=3,\\
2x+4y=6
\end{cases}
$$

has infinitely many real solutions:

$$
(x,y)=(3-2t,t),\qquad t\in\mathbb R.
$$

With the second right-hand side replaced by $7$, however, the two equations become inconsistent. The determinant detects the failure of uniqueness, while the **augmented rank condition** determines which of these two possibilities occurs:

$$
A\mathbf x=\mathbf b\text{ is solvable}
\quad\Longleftrightarrow\quad
\operatorname{rank}(A)=\operatorname{rank}([A\mid\mathbf b]).
$$

This is the same solvability criterion developed in the earlier rank-and-solvability chapter.

## 5.2.6 Minors, cofactors and Laplace expansion

**Definition 5.2.1 (Minor and cofactor).** Let $A=(a_{ij})\in M_n(\mathbb F)$, with $n\ge2$. Denote by $A^{(i\mid j)}$ the $(n-1)\times(n-1)$ matrix obtained by deleting row $i$ and column $j$. The **minor** and **cofactor** corresponding to $a_{ij}$ are respectively

$$
\boxed{M_{ij}=\det(A^{(i\mid j)}),
\qquad C_{ij}=(-1)^{i+j}M_{ij}.}
$$

The sign pattern of the cofactor matrix alternates in a checkerboard arrangement:

$$
\begin{pmatrix}
+&-&+&\cdots\\
-&+&-&\cdots\\
+&-&+&\cdots\\
\vdots&\vdots&\vdots&\ddots
\end{pmatrix}.
$$

**Example 5.2.5.** For

$$
A=\begin{pmatrix}3&2&1\\1&4&7\\2&3&8\end{pmatrix},
$$

the minor obtained by deleting row $1$ and column $2$ is

$$
M_{12}=\det\begin{pmatrix}1&7\\2&8\end{pmatrix}
=8-14=-6.
$$

Therefore

$$
\boxed{C_{12}=(-1)^{1+2}M_{12}=6.}
$$

**Theorem 5.2.5 (Laplace expansion).** For any fixed row $i$ or column $j$,

$$
\boxed{\det(A)=\sum_{j=1}^{n}a_{ij}C_{ij}}
\qquad\text{(expansion along row }i\text{)},
$$

and

$$
\boxed{\det(A)=\sum_{i=1}^{n}a_{ij}C_{ij}}
\qquad\text{(expansion along column }j\text{)}.
$$

**Proof.** Consider the row expansion. In the Leibniz formula, group terms according to the unique column $j=\sigma(i)$ selected in row $i$. Deleting this row and column leaves all permutations of the remaining $n-1$ indices, so the grouped contribution is $a_{ij}\det(A^{(i\mid j)})$ multiplied by the sign needed to bring column $j$ to position $i$. That sign is $(-1)^{i+j}$. Consequently, the sum of the terms with $\sigma(i)=j$ is $a_{ij}C_{ij}$, and summing over $j$ gives the first identity. The column identity follows by the same argument, or by applying the row formula to $A^{\mathsf T}$ and using $\det(A)=\det(A^{\mathsf T})$. $\square$

For a $3\times3$ matrix, expansion along the **first row** takes the familiar form

$$
\begin{aligned}
\det\begin{pmatrix}
a_{11}&a_{12}&a_{13}\\
a_{21}&a_{22}&a_{23}\\
a_{31}&a_{32}&a_{33}
\end{pmatrix}
={}&a_{11}\begin{vmatrix}a_{22}&a_{23}\\a_{32}&a_{33}\end{vmatrix}\\
&-a_{12}\begin{vmatrix}a_{21}&a_{23}\\a_{31}&a_{33}\end{vmatrix}\\
&+a_{13}\begin{vmatrix}a_{21}&a_{22}\\a_{31}&a_{32}\end{vmatrix}.
\end{aligned}
$$

Expansion along the **first column** yields

$$
\begin{aligned}
\det(A)={}&a_{11}\begin{vmatrix}a_{22}&a_{23}\\a_{32}&a_{33}\end{vmatrix}\\
&-a_{21}\begin{vmatrix}a_{12}&a_{13}\\a_{32}&a_{33}\end{vmatrix}\\
&+a_{31}\begin{vmatrix}a_{12}&a_{13}\\a_{22}&a_{23}\end{vmatrix}.
\end{aligned}
$$

**Example 5.2.6.** Using a row containing a zero, one obtains

$$
\begin{aligned}
\det\begin{pmatrix}2&1&0\\3&-1&4\\1&2&5\end{pmatrix}
&=2\begin{vmatrix}-1&4\\2&5\end{vmatrix}
-\begin{vmatrix}3&4\\1&5\end{vmatrix}\\
&=2(-13)-11=-37.
\end{aligned}
$$

The Laplace expansion is particularly useful for symbolic determinants and matrices with sparse rows or columns. Dense numerical determinants are generally better computed by elimination.

## 5.2.7 The adjugate matrix and the inverse formula

**Definition 5.2.2 (Adjugate).** The **cofactor matrix** of $A$ is $C=(C_{ij})$. Its transpose is the **adjugate**:

$$
\boxed{\operatorname{adj}(A)=C^{\mathsf T}=(C_{ji})_{i,j=1}^{n}.}
$$

In particular, for a $2\times2$ matrix,

$$
A=\begin{pmatrix}a&b\\c&d\end{pmatrix},
\qquad
\operatorname{adj}(A)=\begin{pmatrix}d&-b\\-c&a\end{pmatrix}.
$$

The cofactor matrix itself is $\begin{pmatrix}d&-c\\-b&a\end{pmatrix}$: **the transpose in the definition matters**.

**Theorem 5.2.6 (Adjugate identity).** For every square matrix $A$,

$$
\boxed{A\operatorname{adj}(A)=\operatorname{adj}(A)A=\det(A)I_n.}
$$

**Proof.** The $(i,j)$ entry of $A\operatorname{adj}(A)$ is

$$
\bigl(A\operatorname{adj}(A)\bigr)_{ij}
=\sum_{k=1}^{n}a_{ik}C_{jk}.
$$

If $i=j$, this is the expansion of $\det(A)$ along row $i$. If $i\ne j$, this is the expansion along row $j$ of the matrix obtained from $A$ by replacing row $j$ by row $i$; that matrix has two identical rows, so its determinant is zero. Hence $A\operatorname{adj}(A)=\det(A)I_n$. Applying the analogous column argument proves $\operatorname{adj}(A)A=\det(A)I_n$. $\square$

**Corollary 5.2.4 (Adjugate inverse formula).** Over a field, $A$ is invertible if and only if $\det(A)\ne0$. In that case,

$$
\boxed{A^{-1}=\frac{1}{\det(A)}\operatorname{adj}(A).}
$$

This directly constructs the inverse and supplies a second proof that nonzero determinant implies invertibility.

**Remark (commutative rings).** The Leibniz formula, Laplace expansion, and adjugate identity require only commutative addition and multiplication, so they also hold for matrices with entries in any **commutative ring** $R$ with identity. In that setting, $A\in M_n(R)$ is invertible over $R$ precisely when $\det(A)$ is a *unit* in $R$. For instance, an integer matrix admits an integer inverse if and only if its determinant is $+1$ or $-1$.

## 5.2.8 Cramer's rule

**Theorem 5.2.7 (Cramer's rule).** Let $A\in M_n(\mathbb F)$ be invertible, and let $A_j(\mathbf b)$ denote the matrix obtained by replacing column $j$ of $A$ by $\mathbf b$. The unique solution of $A\mathbf x=\mathbf b$ has coordinates

$$
\boxed{x_j=\frac{\det(A_j(\mathbf b))}{\det(A)},
\qquad j=1,\ldots,n.}
$$

**Proof.** Write the columns of $A$ as $\mathbf a_1,\ldots,\mathbf a_n$. Since $\mathbf b=A\mathbf x=\sum_{k=1}^{n}x_k\mathbf a_k$, multilinearity in column $j$ gives

$$
\det(A_j(\mathbf b))
=\sum_{k=1}^{n}x_k\det(A_j(\mathbf a_k)).
$$

For every $k\ne j$, the matrix $A_j(\mathbf a_k)$ contains two equal columns, so its determinant is zero. The remaining term is $x_j\det(A)$, and the displayed formula follows by division. $\square$

**Example 5.2.7.** Consider

$$
\begin{pmatrix}2&1\\1&-1\end{pmatrix}
\begin{pmatrix}x_1\\x_2\end{pmatrix}
=\begin{pmatrix}5\\1\end{pmatrix}.
$$

The coefficient determinant is $-3$. Replacing the first and second columns in turn gives

$$
\det\begin{pmatrix}5&1\\1&-1\end{pmatrix}=-6,
\qquad
\det\begin{pmatrix}2&5\\1&1\end{pmatrix}=-3.
$$

Therefore $x_1=2$ and $x_2=1$. The formula is conceptually valuable, though elimination or factorisation is generally preferable for numerical systems.



- [Exercises]({{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/02-determinant-identities-and-adjugate-matrices/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/02-determinant-identities-and-adjugate-matrices/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/02-determinant-identities-and-adjugate-matrices/references/' | relative_url }})

[Back to Determinants and Orientation]({{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/' | relative_url }})

</article>
