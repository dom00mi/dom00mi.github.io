---
layout: default
title: "4.3: Change of Basis and Similarity"
permalink: /pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/03-change-of-basis-and-similarity/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/03-change-of-basis-and-similarity/' | relative_url }}">← Change of Basis and Similarity</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 4.3</div>
  <h1>Change of Basis and Similarity</h1>
</div>

<article class="article" markdown="1">

# 4.3: Change of Basis and Similarity

A linear map is intrinsic, yet its matrix generally changes when we change coordinates. This section develops the **transition matrix**, proves the general transformation rule for maps between different spaces, and then specialises to **similarity** for an operator on one space. The distinction between matrix **equivalence** and **similarity** is essential.

## 4.3.1 Why the matrix changes when the basis changes

Let $V$ have dimension $n$ over a field $\mathbb F$. Consider two **ordered** bases

$$
\mathcal B=(v_1,\ldots,v_n),\qquad
\mathcal B'=(v'_1,\ldots,v'_n).
$$

The vector $v\in V$ is unchanged by our choice of basis, but its coordinate columns $[v]_{\mathcal B}$ and $[v]_{\mathcal B'}$ need not agree. A transition matrix encodes the precise relationship between them.

We choose the following **unambiguous convention** throughout:

$$
\boxed{P_{\mathcal B\leftarrow\mathcal B'}
\text{ takes coordinates in }\mathcal B'
\text{ to coordinates in }\mathcal B.}
$$

This notation records the direction of coordinate conversion explicitly, avoiding the ambiguity of saying only “from basis $\mathcal B$ to basis $\mathcal B'$”.

## 4.3.2 Transition matrices and coordinate changes

**Definition 4.3.1 (Change-of-basis matrix).** The transition matrix is

$$
\boxed{P_{\mathcal B\leftarrow\mathcal B'}
=\bigl([v'_1]_{\mathcal B}\ \cdots\ [v'_n]_{\mathcal B}\bigr).}
$$

In other words, its $j$-th column is the coordinate vector of the **new** basis vector $v'_j$ expressed in the **old** basis $\mathcal B$. If

$$
v'_j=\sum_{i=1}^n p_{ij}v_i,
$$

then $P_{\mathcal B\leftarrow\mathcal B'}=(p_{ij})$.

**Theorem 4.3.2 (Coordinate transformation).** For every $v\in V$,

$$
\boxed{[v]_{\mathcal B}
=P_{\mathcal B\leftarrow\mathcal B'}[v]_{\mathcal B'},
\qquad
[v]_{\mathcal B'}
=P_{\mathcal B\leftarrow\mathcal B'}^{-1}[v]_{\mathcal B}.}
$$

*Proof.* Write $v=\sum_jx'_jv'_j$. Expanding each $v'_j$ in the old basis gives

$$
\begin{aligned}
v&=\sum_jx'_j\sum_i p_{ij}v_i
=\sum_i\left(\sum_jp_{ij}x'_j\right)v_i.
\end{aligned}
$$

Therefore the old coordinates are $P_{\mathcal B\leftarrow\mathcal B'}x'$. The matrix is invertible because it represents the identity map with respect to two bases, and the identity map is an isomorphism. $\square$

**Proposition 4.3.3 (Transition composition and inverses).** For any three ordered bases $\mathcal A,\mathcal B,\mathcal C$ of the same space,

$$
\boxed{P_{\mathcal A\leftarrow\mathcal C}
=P_{\mathcal A\leftarrow\mathcal B}P_{\mathcal B\leftarrow\mathcal C},
\qquad
P_{\mathcal B\leftarrow\mathcal A}
=P_{\mathcal A\leftarrow\mathcal B}^{-1}.}
$$

This follows by applying the coordinate identity twice. In particular $P_{\mathcal B\leftarrow\mathcal B}=I_n$.

## 4.3.3 Transition matrices in ordinary $\mathbb R^n$ coordinates

Suppose the basis vectors are given in standard coordinates. Form the invertible **basis matrices**

$$
M_{\mathcal B}=\bigl(v_1\ \cdots\ v_n\bigr),\qquad
M_{\mathcal B'}=\bigl(v'_1\ \cdots\ v'_n\bigr).
$$

Since $v=M_{\mathcal B}[v]_{\mathcal B}=M_{\mathcal B'}[v]_{\mathcal B'}$, we obtain

$$
\boxed{P_{\mathcal B\leftarrow\mathcal B'}
=M_{\mathcal B}^{-1}M_{\mathcal B'}.}
$$

This gives a practical method: place the new basis vectors into columns, then express those columns in the old basis.

**Example 4.3.4 (Standard and nonstandard coordinates).** Take

$$
\mathcal B=\bigl((1,0),(0,1)\bigr),
\quad \mathcal B'=\bigl((2,1),(3,1)\bigr).
$$

Then

$$
P_{\mathcal B\leftarrow\mathcal B'}=
\begin{pmatrix}2&3\\1&1\end{pmatrix},
\qquad
P_{\mathcal B\leftarrow\mathcal B'}^{-1}
=\begin{pmatrix}-1&3\\1&-2\end{pmatrix}.
$$

For $v=(1,1)$,

$$
[v]_{\mathcal B}=\begin{pmatrix}1\\1\end{pmatrix},
\qquad
[v]_{\mathcal B'}=\begin{pmatrix}2\\-1\end{pmatrix},
$$

and indeed

$$
\begin{pmatrix}2&3\\1&1\end{pmatrix}
\begin{pmatrix}2\\-1\end{pmatrix}
=\begin{pmatrix}1\\1\end{pmatrix}.
$$

**Example 4.3.5 (Two nonstandard bases).** Now let

$$
\mathcal B=\bigl((1,0),(1,1)\bigr),\qquad
\mathcal B'=\bigl((2,1),(3,1)\bigr).
$$

As

$$
M_{\mathcal B}=\begin{pmatrix}1&1\\0&1\end{pmatrix},
\quad M_{\mathcal B'}=\begin{pmatrix}2&3\\1&1\end{pmatrix},
$$

we find

$$
\boxed{P_{\mathcal B\leftarrow\mathcal B'}
=\begin{pmatrix}1&-1\\0&1\end{pmatrix}
\begin{pmatrix}2&3\\1&1\end{pmatrix}
=\begin{pmatrix}1&2\\1&1\end{pmatrix}.}
$$

Its columns encode $v'_1=v_1+v_2$ and $v'_2=2v_1+v_2$.

## 4.3.4 Basis changes as compositions of coordinate maps

The coordinate isomorphisms of Part 4.2 are

$$
\phi_{\mathcal B}:\mathbb F^n\to V,
\qquad
\phi_{\mathcal B'}:\mathbb F^n\to V.
$$

The conversion from new to old coordinates is the composite

$$
\phi_{\mathcal B}^{-1}\circ\phi_{\mathcal B'}:\mathbb F^n\longrightarrow\mathbb F^n,
$$

and its standard matrix is exactly $P_{\mathcal B\leftarrow\mathcal B'}$. Thus

$$
P_{\mathcal B\leftarrow\mathcal B'}
=[\phi_{\mathcal B}^{-1}\circ\phi_{\mathcal B'}].
$$

This formulation works in **arbitrary finite-dimensional spaces**, even when their elements are polynomials, functions or matrices rather than ordinary coordinate columns.

## 4.3.5 The general change-of-basis formula for linear maps

Let $T:V\to W$ be linear. Choose an old and a new basis in **each** space:

$$
\begin{aligned}
&\mathcal B,\mathcal B'\text{ in }V,\\
&\mathcal C,\mathcal C'\text{ in }W.
\end{aligned}
$$

Write

$$
\begin{aligned}
A&=[T]_{\mathcal C\leftarrow\mathcal B},\\
A'&=[T]_{\mathcal C'\leftarrow\mathcal B'},\\
P&=P_{\mathcal B\leftarrow\mathcal B'},\\
Q&=P_{\mathcal C\leftarrow\mathcal C'}.
\end{aligned}
$$

The $n\times n$ matrix $P$ converts **new input coordinates to old input coordinates**, while the $m\times m$ matrix $Q$ converts **new output coordinates to old output coordinates**.

**Theorem 4.3.6 (General transformation law).**

$$
\boxed{A'=Q^{-1}AP.}
$$

*Proof.* For every $v\in V$,

$$
[T(v)]_{\mathcal C}=A[v]_{\mathcal B}
=AP[v]_{\mathcal B'}.
$$

But $[T(v)]_{\mathcal C}=Q[T(v)]_{\mathcal C'}=QA'[v]_{\mathcal B'}$. Hence

$$
QA'[v]_{\mathcal B'}=AP[v]_{\mathcal B'}
$$

for all coordinate columns $[v]_{\mathcal B'}$, so $QA'=AP$, proving the theorem. $\square$

The formula makes clear why we multiply by $P$ on the **right**, and by $Q^{-1}$ on the **left**: first convert the input coordinates, apply the old map matrix, then convert the output coordinates.

## 4.3.6 Worked example: changing both source and target bases

Consider

$$
T:\mathbb R^3\to\mathbb R^2,
\qquad T(x,y,z)=(x-y,x-z).
$$

Use standard bases initially. Then

$$
A=\begin{pmatrix}1&-1&0\\1&0&-1\end{pmatrix}.
$$

Let the new input basis exchange $e_1$ and $e_2$, and let the new output basis exchange $f_1$ and $f_2$. Thus

$$
P=\begin{pmatrix}0&1&0\\1&0&0\\0&0&1\end{pmatrix},
\qquad Q=\begin{pmatrix}0&1\\1&0\end{pmatrix},
\qquad Q^{-1}=Q.
$$

By the general formula,

$$
\begin{aligned}
A'&=Q^{-1}AP\\
&=\begin{pmatrix}0&1\\1&0\end{pmatrix}
\begin{pmatrix}1&-1&0\\1&0&-1\end{pmatrix}
\begin{pmatrix}0&1&0\\1&0&0\\0&0&1\end{pmatrix}\\[5pt]
&=\boxed{\begin{pmatrix}0&1&-1\\-1&1&0\end{pmatrix}}.
\end{aligned}
$$

Directly checking the columns confirms it: the new input basis vectors $(0,1,0)$, $(1,0,0)$ and $(0,0,1)$ have images $(-1,0)$, $(1,1)$ and $(0,-1)$. Expressed in the **swapped output basis**, these have coordinate columns $(0,-1)$, $(1,1)$ and $(-1,0)$.

## 4.3.7 Similarity: one operator, one basis changed twice

Now specialise to a **linear operator** $T:V\to V$. The same ordered basis is used for its domain and codomain. If $\mathcal B$ is changed to $\mathcal B'$, then the two transition matrices of the previous theorem coincide:

$$
Q=P=P_{\mathcal B\leftarrow\mathcal B'}.
$$

**Theorem 4.3.7 (Similarity transformation).** If

$$
A=[T]_{\mathcal B\leftarrow\mathcal B},\qquad
A'=[T]_{\mathcal B'\leftarrow\mathcal B'},
$$

then

$$
\boxed{A'=P^{-1}AP.}
$$

**Definition 4.3.8 (Similar matrices).** Two square $n\times n$ matrices $A$ and $A'$ over $\mathbb F$ are **similar** if there exists an invertible $P\in\mathrm{GL}_n(\mathbb F)$ such that

$$
A'=P^{-1}AP.
$$

Precisely, two matrices are similar if they represent the **same linear operator under different bases** (or, equivalently, represent conjugate operators on the coordinate space).

**Theorem 4.3.9.** Similarity is an equivalence relation:

- Reflexivity: $A=I^{-1}AI$.
- Symmetry: $A'=P^{-1}AP$ implies $A=(P^{-1})^{-1}A'P^{-1}$.
- Transitivity: $A'=P^{-1}AP$ and $A''=Q^{-1}A'Q$ imply $A''=(PQ)^{-1}A(PQ)$.

Thus similarity partitions square matrices into **similarity classes**, or orbits under the conjugation action $P\cdot A=P^{-1}AP$.

## 4.3.8 Worked example: the matrix can remain unchanged

Let

$$
T:\mathbb R^2\to\mathbb R^2,\qquad T(x,y)=(x+y,x-y),
$$

and choose

$$
\mathcal B=\bigl((1,0),(1,1)\bigr),\qquad
\mathcal B'=\bigl((2,1),(3,1)\bigr).
$$

From the images of the old basis vectors,

$$
T(1,0)=(1,1),\qquad T(1,1)=(2,0),
$$

we find

$$
A=[T]_{\mathcal B}=\begin{pmatrix}0&2\\1&0\end{pmatrix}.
$$

From Example 4.3.5,

$$
P=\begin{pmatrix}1&2\\1&1\end{pmatrix},\qquad
P^{-1}=\begin{pmatrix}-1&2\\1&-1\end{pmatrix}.
$$

Therefore,

$$
P^{-1}AP
=\begin{pmatrix}-1&2\\1&-1\end{pmatrix}
\begin{pmatrix}0&2\\1&0\end{pmatrix}
\begin{pmatrix}1&2\\1&1\end{pmatrix}
=\begin{pmatrix}0&2\\1&0\end{pmatrix}=A.
$$

This is also clear directly: $T(2,1)=(3,1)=v'_2$ and $T(3,1)=(4,2)=2v'_1$. It is entirely possible for the matrix of an operator to be the same in two different bases; such transition matrices **commute** with $A$.

## 4.3.9 Equivalent matrices versus similar matrices

There are **two different classification problems**.

**Definition 4.3.10 (Matrix equivalence).** Two $m\times n$ matrices $A$ and $B$ are **equivalent** if there are invertible matrices $P\in\mathrm{GL}_m(\mathbb F)$ and $Q\in\mathrm{GL}_n(\mathbb F)$ such that

$$
\boxed{B=P^{-1}AQ.}
$$

This corresponds to allowing **independent** changes of codomain and domain bases. By contrast, similarity is for **square matrices representing an operator**, and requires the **same** change of basis on both sides:

$$
\boxed{B=Q^{-1}AQ.}
$$

Equivalent matrices need not be similar. For example, the $1\times1$ matrices $(1)$ and $(2)$ over $\mathbb R$ are equivalent (choose different input and output scalings), but not similar: conjugation by a nonzero $1\times1$ scalar cannot change the entry.

**Theorem 4.3.11 (Normal form under equivalence).** If $A\in M_{m\times n}(\mathbb F)$ has rank $r$, then it is equivalent to the rectangular block matrix

$$
J_r=\begin{pmatrix}I_r&0\\0&0\end{pmatrix},
$$

with blocks sized to produce an $m\times n$ matrix. The rank $r$ is the **only** invariant of equivalence: two $m\times n$ matrices are equivalent exactly when they have the same rank.

*Proof.* Regard $A$ as the matrix of $T:\mathbb F^n\to\mathbb F^m$. Choose a basis $v_1,\ldots,v_{n-r}$ for $\ker T$ and extend it to a basis of the domain. By the map argument of Part 4.1, the images of the remaining $r$ basis vectors are independent and span $\operatorname{im}T$. Use these images as the first $r$ vectors of a codomain basis and extend to a full basis. Relative to the appropriately ordered bases, $T$ has $r$ unit columns followed by $n-r$ zero columns, giving $J_r$. Changes of bases are invertible; therefore the rank is preserved. $\square$

**Algorithmic counterpart.** Elementary row operations multiply by invertible matrices from the left; elementary column operations multiply by invertible matrices from the right. One may use both to reduce any $m\times n$ matrix to $J_r$. This reproduces the coordinate-free proof constructively.

## 4.3.10 Why rank is not enough for similarity

Under unrestricted equivalence, the only invariant is rank; but similarity contains more information because it preserves the action of the operator *on the same space*. For example,

$$
A=\begin{pmatrix}1&0\\0&2\end{pmatrix},\qquad
B=\begin{pmatrix}1&0\\0&3\end{pmatrix}
$$

have the same rank and so are equivalent, but they are **not similar**: their traces differ.

For similar $A$ and $B=P^{-1}AP$,

$$
\operatorname{tr}(B)=\operatorname{tr}(A),\qquad
\det(B)=\det(A),
$$

and their characteristic polynomials agree:

$$
\det(tI-B)
=\det\bigl(P^{-1}(tI-A)P\bigr)
=\det(tI-A).
$$

Thus eigenvalues (with algebraic multiplicities) are preserved whenever those notions are available. Rank, nullity, invertibility and the dimensions of the kernels of powers $A^k$ are also similarity invariants. These observations anticipate the subsequent chapter on determinants and later work on canonical forms.

## 4.3.11 Determinants of endomorphisms are basis-independent

The determinant of an operator may be defined by choosing any basis $\mathcal B$ and taking the determinant of its representing matrix. This is **well-defined** because similar matrices have the same determinant.

**Definition 4.3.12 (Determinant of a linear operator).** For $T:V\to V$ on a finite-dimensional space, write

$$
\det T:=\det[T]_{\mathcal B},
$$

where the right-hand side may be computed in any ordered basis.

*Proof of basis independence.* If $A' =P^{-1}AP$ for an invertible transition matrix $P$, then multiplicativity of the determinant (developed in the following chapter) gives

$$
\det A'=\det(P^{-1})\det A\det P=\det A.
$$

Consequently, for an operator on an $n$-dimensional space,

$$
\begin{aligned}
T\text{ injective}&\iff T\text{ surjective}\\
&\iff T\text{ bijective}\\
&\iff T\text{ invertible}\\
&\iff \det T\ne0.
\end{aligned}
$$

This is a forward reference to the determinant theory in Chapter 5, not a repetition of that chapter's construction of determinants.

## 4.3.12 Diagonalisability as a special kind of similarity

**Definition 4.3.13 (Diagonalisable matrix).** A square matrix $A\in M_n(\mathbb F)$ is diagonalisable over $\mathbb F$ if there exists an invertible $P$ such that

$$
P^{-1}AP=D,
$$

where $D$ is diagonal. An operator $T:V\to V$ is diagonalisable if it admits a basis in which its representing matrix is diagonal.

**Proposition 4.3.14 (Eigenbasis criterion).** A matrix $A$ is diagonalisable exactly when $\mathbb F^n$ has a basis of eigenvectors of $A$. If the columns of $P$ are eigenvectors $p_j$ with corresponding eigenvalues $\lambda_j$, then

$$
AP=P\,\operatorname{diag}(\lambda_1,\ldots,\lambda_n),
$$

and hence

$$
P^{-1}AP=\operatorname{diag}(\lambda_1,\ldots,\lambda_n).
$$

Conversely, such a similarity relation implies that each column of $P$ is an eigenvector. $\square$

**Example 4.3.15.** For

$$
A=\begin{pmatrix}2&1\\0&3\end{pmatrix},
$$

we have eigenvectors $(1,0)$ for eigenvalue $2$ and $(1,1)$ for eigenvalue $3$. Taking

$$
P=\begin{pmatrix}1&1\\0&1\end{pmatrix},\qquad
P^{-1}=\begin{pmatrix}1&-1\\0&1\end{pmatrix},
$$

we obtain

$$
\boxed{P^{-1}AP=\begin{pmatrix}2&0\\0&3\end{pmatrix}.}
$$

Diagonalisation replaces a complicated coordinate action by independent multiplication in eigenvector directions. Not every matrix is diagonalisable over a given field; full similarity classification leads to Jordan normal form and related canonical forms.

## 4.3.13 Endomorphisms and the algebra of linear operators

**Definition 4.3.16.** Write

$$
\operatorname{End}_{\mathbb F}(V)=\mathcal L(V,V)
$$

for the collection of all linear endomorphisms of $V$. It has pointwise addition and scalar multiplication, and its product is composition. In particular,

$$
\begin{aligned}
(RS)T&=R(ST),\\
R(S+T)&=RS+RT,\\
(R+S)T&=RT+ST,\\
\lambda(ST)&=(\lambda S)T=S(\lambda T).
\end{aligned}
$$

Hence $\operatorname{End}_{\mathbb F}(V)$ is an **associative unital algebra**, generally not a commutative algebra. The identity operator is its multiplicative identity.

**Theorem 4.3.17.** If $\dim V=n$ and an ordered basis $\mathcal B$ is fixed, then

$$
\boxed{\operatorname{End}_{\mathbb F}(V)\cong M_n(\mathbb F)}
$$

as associative algebras, via $T\mapsto[T]_{\mathcal B}$. Consequently,

$$
\dim\operatorname{End}_{\mathbb F}(V)=n^2.
$$

*Proof.* The map is bijective by the linear-extension theorem: given any $A=(a_{ij})$, prescribe $T(v_j)=\sum_i a_{ij}v_i$. It preserves addition and scalar multiplication by Part 4.2, preserves products because $[S\circ T]=[S][T]$, and takes the identity operator to $I_n$. $\square$

The invertible members of this algebra form $\mathrm{GL}(V)$, the **automorphism group** of $V$.

## 4.3.14 Automorphisms act on ordered bases

Let $\mathcal B=(v_1,\ldots,v_n)$ be an ordered basis and $S\in\mathrm{GL}(V)$. Then

$$
S\cdot\mathcal B=\bigl(S(v_1),\ldots,S(v_n)\bigr)
$$

is another ordered basis.

**Proposition 4.3.18 (Simple transitivity).** Given two ordered bases $\mathcal B$ and $\mathcal B'$ of $V$, there exists exactly one automorphism $S$ such that

$$
S(v_j)=v'_j\qquad(j=1,\ldots,n).
$$

*Proof.* Linear extension provides a unique map with these basis images, and the corresponding inverse is the linear extension of $v'_j\mapsto v_j$. Hence $S$ is an automorphism. $\square$

The action is **transitive** because any basis can be reached from any other, and **free** because an automorphism fixing every vector of a basis must be the identity. This is a structural reason that transition matrices are always invertible.

**Example 4.3.19 (Counting automorphisms over a finite field).** Let $\mathbb F_q$ be a finite field with $q$ elements. To form an ordered basis of $\mathbb F_q^n$, choose its first vector nonzero, its second outside the span of the first, and so on. Thus

$$
\boxed{|\mathrm{GL}_n(\mathbb F_q)|
=(q^n-1)(q^n-q)(q^n-q^2)\cdots(q^n-q^{n-1}).}
$$

In particular,

$$
|\mathrm{GL}_2(\mathbb F_q)|
=(q^2-1)(q^2-q)=q(q-1)^2(q+1).
$$

This counting argument uses the correspondence between invertible linear maps and ordered bases.

## 4.3.15 Inverse operators and inverses of compositions

**Theorem 4.3.20.** If $T:V\to V$ is invertible, then its inverse $T^{-1}$ is linear and

$$
TT^{-1}=T^{-1}T=I_V.
$$

If $S,T$ are invertible, then

$$
\boxed{(ST)^{-1}=T^{-1}S^{-1}.}
$$

The reversal of order is essential: applying $T$ and then $S$ must be undone by applying $S^{-1}$ and then $T^{-1}$.

**Example 4.3.21.** For $T(x,y)=(x+3y,x+2y)$,

$$
\boxed{T^{-1}(u,v)=(-2u+3v,\ u-v).}
$$

Indeed,

$$
\begin{aligned}
T\bigl(-2u+3v,u-v\bigr)
&=\bigl((-2u+3v)+3(u-v),\ (-2u+3v)+2(u-v)\bigr)\\
&=(u,v),
\end{aligned}
$$

and similarly $T^{-1}(T(x,y))=(x,y)$. In standard coordinates,

$$
[T]=\begin{pmatrix}1&3\\1&2\end{pmatrix},\qquad
[T^{-1}]=\begin{pmatrix}-2&3\\1&-1\end{pmatrix}=[T]^{-1}.
$$

## 4.3.16 Final synthesis

The three most important coordinate relations in this chapter are:

$$
\boxed{\begin{aligned}
[v]_{\mathcal B}&=P_{\mathcal B\leftarrow\mathcal B'}[v]_{\mathcal B'},\\[3pt]
[T]_{\mathcal C'\leftarrow\mathcal B'}&=Q^{-1}[T]_{\mathcal C\leftarrow\mathcal B}P,\\[3pt]
[T]_{\mathcal B'}&=P^{-1}[T]_{\mathcal B}P\qquad(T:V\to V).
\end{aligned}}
$$

The first changes **vector coordinates**, the second changes the matrix of a **map between two possibly different spaces**, and the third changes the matrix of an **operator on one space**.

These distinctions separate the intrinsic geometry of a linear map from its coordinate descriptions. They also explain why equivalence is classified by map rank, while similarity carries subtler invariants that motivate the study of determinants, eigenvalues, diagonalisation and canonical forms.


- [Exercises]({{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/03-change-of-basis-and-similarity/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/03-change-of-basis-and-similarity/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/03-change-of-basis-and-similarity/references/' | relative_url }})

[Back to Linear Transformations and Coordinate Systems]({{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/' | relative_url }})

</article>
