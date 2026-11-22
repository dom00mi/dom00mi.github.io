---
layout: default
title: "4.2: Matrix Representations of Linear Maps"
permalink: /pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/02-matrix-representations-of-linear-maps/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/02-matrix-representations-of-linear-maps/' | relative_url }}">← Matrix Representations of Linear Maps</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 4.2</div>
  <h1>Matrix Representations of Linear Maps</h1>
</div>

<article class="article" markdown="1">

# 4.2: Matrix Representations of Linear Maps

A linear map is independent of coordinates, but an ordered basis allows us to describe its action using a matrix. The crucial point is that the matrix depends on the **chosen bases**, whereas the underlying map does not. This section derives that correspondence, studies how the algebra of linear maps becomes matrix arithmetic, and explains elementary matrices as operators on rows and columns.

## 4.2.1 Coordinates relative to an ordered basis

Let $V$ be a finite-dimensional vector space over $\mathbb F$, with ordered basis $\mathcal B=(v_1,\ldots,v_n)$. Every $v\in V$ has a unique expression

$$
v=x_1v_1+\cdots+x_nv_n.
$$

**Definition 4.2.1 (Coordinate vector).** The coordinate vector of $v$ relative to $\mathcal B$ is

$$
[v]_{\mathcal B}=\begin{pmatrix}x_1\\\vdots\\x_n\end{pmatrix}\in\mathbb F^n.
$$

The **synthesis (coordinate) isomorphism** and its inverse are

$$
\phi_{\mathcal B}:\mathbb F^n\longrightarrow V,
\qquad
\phi_{\mathcal B}\!\begin{pmatrix}x_1\\\vdots\\x_n\end{pmatrix}
=\sum_{j=1}^{n}x_jv_j,
$$

$$
\phi_{\mathcal B}^{-1}(v)=[v]_{\mathcal B},
\qquad \phi_{\mathcal B}(e_j)=v_j,
$$

where $e_j$ is the $j$-th standard coordinate vector. Thus a choice of basis is precisely a choice of a linear isomorphism between $V$ and $\mathbb F^n$.

**Proposition 4.2.2 (Bases and coordinate isomorphisms).** Ordered bases of an $n$-dimensional space correspond bijectively to isomorphisms $V\to\mathbb F^n$. Given a basis, use its coordinate map; given an isomorphism $\psi:V\to\mathbb F^n$, use $(\psi^{-1}(e_1),\ldots,\psi^{-1}(e_n))$ as the corresponding basis.

## 4.2.2 A linear map is determined by its values on a basis

**Theorem 4.2.3 (Linear extension).** Let $\mathcal B=(v_1,\ldots,v_n)$ be a basis of $V$, and take any vectors $w_1,\ldots,w_n\in W$. There exists a unique linear map $T:V\to W$ satisfying

$$
T(v_j)=w_j\qquad (j=1,\ldots,n).
$$

*Proof.* For $v=\sum_j x_jv_j$, put

$$
T(v)=\sum_{j=1}^{n}x_jw_j.
$$

The unique basis expansion makes this well-defined. Direct calculation gives

$$
T(\lambda u+\mu v)=\lambda T(u)+\mu T(v).
$$

If $S$ is any other linear map satisfying $S(v_j)=w_j$, then

$$
S(v)=\sum_j x_jS(v_j)=\sum_j x_jw_j=T(v),
$$

so $S=T$. $\square$

**Example 4.2.4.** If $T:\mathbb R^2\to\mathbb R^2$ satisfies

$$
T\!\begin{pmatrix}1\\0\end{pmatrix}=\begin{pmatrix}-1\\1\end{pmatrix},
\qquad
T\!\begin{pmatrix}0\\1\end{pmatrix}=\begin{pmatrix}-4\\4\end{pmatrix},
$$

then

$$
T\!\begin{pmatrix}3\\-2\end{pmatrix}
=3\begin{pmatrix}-1\\1\end{pmatrix}
-2\begin{pmatrix}-4\\4\end{pmatrix}
=\begin{pmatrix}5\\-5\end{pmatrix}.
$$

The matrix method packages exactly this calculation.

## 4.2.3 The matrix associated with a linear map

Let $T:V\to W$ be linear, with ordered bases

$$
\mathcal B=(v_1,\ldots,v_n),\qquad \mathcal C=(w_1,\ldots,w_m).
$$

Since each $T(v_j)$ belongs to $W$, it has a unique $\mathcal C$-coordinate expansion,

$$
T(v_j)=\sum_{i=1}^{m}a_{ij}w_i\qquad (j=1,\ldots,n).
$$

**Definition 4.2.5 (Representing matrix).** The matrix of $T$ relative to $\mathcal B$ in the domain and $\mathcal C$ in the codomain is

$$
\boxed{[T]_{\mathcal C\leftarrow\mathcal B}
=\bigl( [T(v_1)]_{\mathcal C}\ \cdots\ [T(v_n)]_{\mathcal C}\bigr)
=(a_{ij})\in M_{m\times n}(\mathbb F).}
$$

The arrow makes the convention explicit: coordinates enter in basis $\mathcal B$ and leave in basis $\mathcal C$. Authors also write $\operatorname{Rep}_{\mathcal B,\mathcal C}(T)$ or $[T]_{\mathcal C,\mathcal B}$.

**Theorem 4.2.6 (Fundamental coordinate identity).** For every $v\in V$,

$$
\boxed{[T(v)]_{\mathcal C}
=[T]_{\mathcal C\leftarrow\mathcal B}\,[v]_{\mathcal B}.}
$$

*Proof.* Write $v=\sum_j x_jv_j$. Then

$$
\begin{aligned}
T(v)
&=\sum_jx_jT(v_j)
=\sum_jx_j\sum_i a_{ij}w_i\\
&=\sum_i\left(\sum_j a_{ij}x_j\right)w_i.
\end{aligned}
$$

Hence the $i$-th coordinate of $T(v)$ is $\sum_j a_{ij}x_j$, exactly the $i$-th entry of the matrix product. $\square$

Equivalently, the coordinate transformations satisfy

$$
\phi_{\mathcal C}^{-1}\circ T\circ\phi_{\mathcal B}
=T_{\mathrm{coord}},
\qquad T_{\mathrm{coord}}(x)=[T]_{\mathcal C\leftarrow\mathcal B}x.
$$

This is the content of the commutative diagram

$$
\begin{array}{ccc}
V & \xrightarrow{\ T\ } & W \\
\big\downarrow\scriptstyle{[\cdot]_{\mathcal B}} && \big\downarrow\scriptstyle{[\cdot]_{\mathcal C}}\\
\mathbb F^n&\xrightarrow{\ [T]_{\mathcal C\leftarrow\mathcal B}\ }&\mathbb F^m.
\end{array}
$$

Either path takes $v$ to the same $\mathcal C$-coordinate vector.

## 4.2.4 Standard-coordinate matrices

For $T:\mathbb F^n\to\mathbb F^m$, let both bases be standard. Since $[e_j]$ is the $j$-th unit column,

$$
[T]=\bigl[T(e_1)\ \cdots\ T(e_n)\bigr].
$$

If

$$
T(x_1,\ldots,x_n)=
\left(\sum_{j=1}^n a_{1j}x_j,\ldots,\sum_{j=1}^na_{mj}x_j\right),
$$

then $[T]=(a_{ij})$ and $T(x)=Ax$. In particular, the standard-basis matrix of

$$
T(x,y)=(x+2y,\ x-y)
$$

is

$$
A=\begin{pmatrix}1&2\\1&-1\end{pmatrix},
\qquad
\begin{pmatrix}x+2y\\x-y\end{pmatrix}
=A\begin{pmatrix}x\\y\end{pmatrix}.
$$

Conversely, any $A\in M_{m\times n}(\mathbb F)$ defines a unique linear map $x\mapsto Ax$ relative to standard coordinates.

## 4.2.5 Full example with two nonstandard bases

Consider the bases of $\mathbb R^2$ and $\mathbb R^3$ respectively:

$$
\mathcal B=\left(\begin{pmatrix}2\\0\end{pmatrix},\begin{pmatrix}1\\4\end{pmatrix}\right),
\qquad
\mathcal C=\left(
\begin{pmatrix}1\\0\\0\end{pmatrix},
\begin{pmatrix}0\\-2\\0\end{pmatrix},
\begin{pmatrix}1\\0\\1\end{pmatrix}\right).
$$

Define $T:\mathbb R^2\to\mathbb R^3$ by the images

$$
T\!\begin{pmatrix}2\\0\end{pmatrix}=\begin{pmatrix}1\\1\\1\end{pmatrix},
\qquad
T\!\begin{pmatrix}1\\4\end{pmatrix}=\begin{pmatrix}1\\2\\0\end{pmatrix}.
$$

First express the images in the **codomain** basis:

$$
\begin{aligned}
\begin{pmatrix}1\\1\\1\end{pmatrix}
&=0\,w_1-\frac12w_2+1\,w_3,\\[3pt]
\begin{pmatrix}1\\2\\0\end{pmatrix}
&=1\,w_1-1\,w_2+0\,w_3.
\end{aligned}
$$

The columns are therefore the coordinate representations of $T(v_1)$ and $T(v_2)$:

$$
\boxed{[T]_{\mathcal C\leftarrow\mathcal B}
=\begin{pmatrix}0&1\\-\tfrac12&-1\\1&0\end{pmatrix}.}
$$

For $u=(4,8)$ we have $[u]_{\mathcal B}=(1,2)^{\mathsf T}$, so

$$
[T(u)]_{\mathcal C}
=\begin{pmatrix}0&1\\-\tfrac12&-1\\1&0\end{pmatrix}
\begin{pmatrix}1\\2\end{pmatrix}
=\begin{pmatrix}2\\-\tfrac52\\1\end{pmatrix}.
$$

Returning to ordinary coordinates gives $T(u)=2w_1-\tfrac52w_2+w_3=(3,5,1)$, also obtained directly by $T(v_1+2v_2)=(1,1,1)+2(1,2,0)$.

The lesson is that one should never confuse the **ordinary coordinates of an image** with its **coordinates in the selected codomain basis**.

## 4.2.6 Examples in polynomial and matrix spaces

**Example 4.2.7 (Differentiation).** With $\mathcal B=(1,x,x^2,x^3)$ in both domain and codomain, differentiation $D:\mathcal P_3\to\mathcal P_3$ has matrix

$$
[D]_{\mathcal B}=\begin{pmatrix}
0&1&0&0\\
0&0&2&0\\
0&0&0&3\\
0&0&0&0
\end{pmatrix}.
$$

Each column is the coordinate vector of the derivative of the corresponding basis polynomial. In this case $D^4=0$; the matrix is nilpotent.

**Example 4.2.8 (Integration).** With $\mathcal B=(1,x,x^2)$ and $\mathcal C=(1,x,x^2,x^3)$, the zero-constant antiderivative $J:\mathcal P_2\to\mathcal P_3$ is represented by

$$
[J]_{\mathcal C\leftarrow\mathcal B}
=\begin{pmatrix}
0&0&0\\
1&0&0\\
0&\tfrac12&0\\
0&0&\tfrac13
\end{pmatrix}.
$$

This is a $4\times3$ matrix because the output space has dimension four and the input space has dimension three.

**Example 4.2.9 (Transpose).** Identify $M_2(\mathbb R)$ with $\mathbb R^4$ using the ordered basis $(E_{11},E_{12},E_{21},E_{22})$. Transposition $\tau(A)=A^{\mathsf T}$ is represented by

$$
[\tau]=\begin{pmatrix}
1&0&0&0\\
0&0&1&0\\
0&1&0&0\\
0&0&0&1
\end{pmatrix}.
$$

This makes $\tau^2=\operatorname{id}$ evident from $[\tau]^2=I_4$.

## 4.2.7 From linear maps to matrices, and back

**Theorem 4.2.10.** With bases $\mathcal B$ of $V$ and $\mathcal C$ of $W$ fixed, the map

$$
\Phi_{\mathcal B,\mathcal C}:\mathcal L(V,W)\longrightarrow M_{m\times n}(\mathbb F),
\quad T\longmapsto[T]_{\mathcal C\leftarrow\mathcal B}
$$

is a linear isomorphism. Therefore

$$
\boxed{\dim\mathcal L(V,W)=(\dim V)(\dim W)=mn.}
$$

*Proof.* Addition and scalar multiplication are represented entry by entry because the $j$-th column of $[S+T]$ is $[(S+T)(v_j)]$. Injectivity follows because the values on the domain basis determine a map. For surjectivity, let $A=(a_{ij})$ be any $m\times n$ matrix; prescribe $T(v_j)=\sum_i a_{ij}w_i$ and extend linearly by Theorem 4.2.3. Its matrix is exactly $A$. $\square$

A given **matrix**, however, does not determine a unique *abstract* map unless the domain, codomain and both bases have been specified. For example,

$$
H=\begin{pmatrix}1&0\\0&0\end{pmatrix}
$$

with standard bases represents the projection $(x,y)\mapsto(x,0)$, while with the swapped basis $((0,1),(1,0))$ for both source and target it represents $(x,y)\mapsto(0,y)$. The same numerical matrix describes different operators.

## 4.2.8 Matrix rank and nullity as invariants of the map

Let $A=[T]_{\mathcal C\leftarrow\mathcal B}$. The coordinate maps carry $\ker T$ to $\ker A$ and $\operatorname{im}T$ to the column space of $A$:

$$
\begin{aligned}
[v]_{\mathcal B}\in\ker A&\iff T(v)=0_W,\\
[\operatorname{im}T]_{\mathcal C}&=\operatorname{Col}(A).
\end{aligned}
$$

Consequently,

$$
\boxed{\operatorname{rank}(T)=\operatorname{rank}(A),\qquad
\operatorname{nullity}(T)=\operatorname{nullity}(A).}
$$

This gives the promised *coordinate-independent meaning* of matrix rank and nullity. We will not repeat the matrix rank–nullity proof from the previous chapter.

## 4.2.9 Matrix addition and scalar multiplication represent map operations

If $S,T:V\to W$ and the chosen bases are fixed, then

$$
\boxed{[S+T]=[S]+[T],\qquad[\lambda T]=\lambda[T].}
$$

Indeed, $(S+T)(v_j)=S(v_j)+T(v_j)$ and $(\lambda T)(v_j)=\lambda T(v_j)$. For example, if

$$
[S]=\begin{pmatrix}1&3\\2&0\end{pmatrix},\qquad
[T]=\begin{pmatrix}-2&-1\\2&4\end{pmatrix},
$$

then

$$
[S+T]=\begin{pmatrix}-1&2\\4&4\end{pmatrix}.
$$

Thus matrix addition is commutative and associative, the zero matrix represents the zero map, additive inverses are entrywise, and scalar multiplication distributes over addition. These are consequences of the corresponding operations on linear maps.

## 4.2.10 Matrix multiplication represents composition

Let $T:U\to V$ and $S:V\to W$, with chosen bases $\mathcal A,\mathcal B,\mathcal C$ respectively. The middle basis must be the same for both matrices. The fundamental identity gives

$$
\begin{aligned}
[(S\circ T)(u)]_{\mathcal C}
&=[S]_{\mathcal C\leftarrow\mathcal B}[T(u)]_{\mathcal B}\\
&=[S]_{\mathcal C\leftarrow\mathcal B}
[T]_{\mathcal B\leftarrow\mathcal A}[u]_{\mathcal A}.
\end{aligned}
$$

**Theorem 4.2.11 (Composition rule).**

$$
\boxed{[S\circ T]_{\mathcal C\leftarrow\mathcal A}
=[S]_{\mathcal C\leftarrow\mathcal B}
[T]_{\mathcal B\leftarrow\mathcal A}.}
$$

This explains both the order of multiplication and the dimension condition. If $G\in M_{m\times r}$ and $H\in M_{r\times n}$, then $GH\in M_{m\times n}$ has entries

$$
(GH)_{ij}=\sum_{k=1}^{r}g_{ik}h_{kj}.
$$

**Example 4.2.12 (A composition through three different dimensions).** Let

$$
H=\begin{pmatrix}4&6&8&2\\5&7&9&3\end{pmatrix},
\qquad
G=\begin{pmatrix}1&1\\0&1\\1&0\end{pmatrix}.
$$

They represent maps $\mathbb F^4\to\mathbb F^2$ and $\mathbb F^2\to\mathbb F^3$. The composite has matrix

$$
GH=\begin{pmatrix}
9&13&17&5\\
5&7&9&3\\
4&6&8&2
\end{pmatrix}.
$$

The first row of $GH$ is the sum of the two rows of $H$, the second equals the second row of $H$, and the third equals its first row.

**Proposition 4.2.13 (Associativity and distributivity).** Whenever all expressions are defined,

$$
(AB)C=A(BC),\qquad A(B+C)=AB+AC,\qquad (A+B)C=AC+BC.
$$

*Proof.* The first equality represents the associativity of composition:

$$
(R\circ S)\circ T=R\circ(S\circ T).
$$

The two distributive laws follow from the linearity of composition in each argument, with the appropriate domains and codomains. $\square$

**Noncommutativity.** In general $AB\ne BA$; one of the products may not even be defined. For example,

$$
\begin{pmatrix}1&2\\3&4\end{pmatrix}
\begin{pmatrix}5&6\\7&8\end{pmatrix}
=\begin{pmatrix}19&22\\43&50\end{pmatrix},
$$

while

$$
\begin{pmatrix}5&6\\7&8\end{pmatrix}
\begin{pmatrix}1&2\\3&4\end{pmatrix}
=\begin{pmatrix}23&34\\31&46\end{pmatrix}.
$$

This is not an anomaly of the coordinate formula: **composition of maps is itself generally noncommutative**.

## 4.2.11 Identities, zero maps and inverses

For the identity map on $V$, taking the same basis on both sides gives

$$
[\operatorname{id}_V]_{\mathcal B\leftarrow\mathcal B}=I_n.
$$

If $T:V\to W$ is an isomorphism and $\dim V=\dim W=n$, its representing matrix $A$ is invertible. Moreover,

$$
\boxed{[T^{-1}]_{\mathcal B\leftarrow\mathcal C}=A^{-1}.}
$$

For invertible $S,T:V\to V$,

$$
(ST)^{-1}=T^{-1}S^{-1},
$$

since $(ST)(T^{-1}S^{-1})=I$ and $(T^{-1}S^{-1})(ST)=I$.

The invertible operators form the **general linear group** $\mathrm{GL}(V)$ under composition; after fixing a basis, it corresponds to $\mathrm{GL}_n(\mathbb F)$.

## 4.2.12 Matrix units and the mechanics of multiplication

**Definition 4.2.14 (Matrix units).** The matrix $E_{ij}$ has a $1$ in position $(i,j)$ and $0$ elsewhere. If dimensions are compatible, left multiplication by $E_{ij}$ takes **row $j$** of the right-hand matrix and places it in **row $i$** of the result, with the other rows zero. Right multiplication takes **column $i$** of the left matrix and places it in **column $j$** of the result, with other columns zero.

For example,

$$
\underbrace{\begin{pmatrix}0&1\\0&0\\0&0\end{pmatrix}}_{E_{12}\in M_{3\times2}}
\begin{pmatrix}5&6\\7&8\end{pmatrix}
=\begin{pmatrix}7&8\\0&0\\0&0\end{pmatrix}.
$$

More generally, the effect of any left multiplier can be understood by decomposing it into sums of scaled matrix units. In particular, a row of $AB$ is a linear combination of rows of $B$ using the coefficients in the corresponding row of $A$.

**Proposition 4.2.15 (Elementary transformations).** Left multiplication by an elementary matrix implements one elementary **row** operation. Right multiplication implements the corresponding elementary **column** operation. In particular:

- a permutation matrix interchanges selected rows or columns;
- a diagonal elementary matrix rescales a row or column;
- $(I+\lambda E_{ij})$ with $i\ne j$ adds $\lambda$ times row $j$ to row $i$ on the left, and adds $\lambda$ times column $i$ to column $j$ on the right.

These matrices are invertible for the legal elementary operations, which explains why elementary row operations preserve the kernel and the rank of the associated linear system up to the appropriate coordinate identification.

## 4.2.13 Further structure of matrix units and elementary operators

Matrix units also satisfy the remarkably concise product rule

$$
\boxed{E_{ij}E_{k\ell}=\delta_{jk}E_{i\ell},}
$$

whenever all sizes are compatible, where $\delta_{jk}$ is $1$ if $j=k$ and $0$ otherwise. This is obtained immediately from the row-by-column definition of matrix multiplication. For any matrix $A=(a_{ij})$, we can write

$$
A=\sum_{i,j}a_{ij}E_{ij}.
$$

This provides a basis for the space of $m\times n$ matrices, and makes explicit why that space has dimension $mn$.

**Example 4.2.16 (Two different actions of elementary matrices).** For

$$
A=\begin{pmatrix}1&2&3\\4&5&6\\7&8&9\end{pmatrix},
\qquad E=I_3+2E_{13},
$$

we have

$$
EA=\begin{pmatrix}15&18&21\\4&5&6\\7&8&9\end{pmatrix},
$$

because row $1$ is replaced by row $1$ plus twice row $3$. On the other hand,

$$
AE=\begin{pmatrix}1&2&5\\4&5&14\\7&8&23\end{pmatrix},
$$

because column $3$ is replaced by column $3$ plus twice column $1$. Thus the same elementary matrix performs a *different* kind of operation depending on which side it multiplies.

**Example 4.2.17 (Rotation as a map matrix).** The rotation operator from Part 4.1 is represented in the standard basis of $\mathbb R^2$ by

$$
[R_\theta]=\begin{pmatrix}\cos\theta&-\sin\theta\\\sin\theta&\cos\theta\end{pmatrix}.
$$

Because composition of rotations adds angles, their matrices obey

$$
[R_\alpha][R_\beta]=[R_{\alpha+\beta}].
$$

This is a concrete manifestation of the rule that matrix products represent function composition.

## 4.2.14 Row operations, column operations and invertible factors

If $A\in M_{m\times n}(\mathbb F)$ and $P\in\mathrm{GL}_m(\mathbb F)$, the product $PA$ corresponds to *postcomposing* $T_A:\mathbb F^n\to\mathbb F^m$ with an invertible map of the codomain. If $Q\in\mathrm{GL}_n(\mathbb F)$, the product $AQ$ corresponds to *precomposing* with an invertible map of the domain:

$$
T_{PA}=T_P\circ T_A,\qquad
T_{AQ}=T_A\circ T_Q.
$$

Hence $PA$ and $AQ$ have the same map rank as $A$; $Q^{-1}$ transports $\ker A$ bijectively onto $\ker(AQ)$, and $P$ transports $\operatorname{im}A$ bijectively onto $\operatorname{im}(PA)$.

This distinction prepares the way for the different transformations of a representing matrix under a change of domain and/or codomain bases in Part 4.3.

## 4.2.15 Some useful identities from the map viewpoint

For compatible matrices,

$$
\begin{gathered}
AI=IA=A,\qquad A0=0,\qquad 0A=0,\\
(A+B)^{\mathsf T}=A^{\mathsf T}+B^{\mathsf T},\\
(\lambda A)^{\mathsf T}=\lambda A^{\mathsf T},\\
(AB)^{\mathsf T}=B^{\mathsf T}A^{\mathsf T},\\
\operatorname{rank}(AB)\le\min\{\operatorname{rank}(A),\operatorname{rank}(B)\}.
\end{gathered}
$$

The transpose identity reverses order; it is another reminder that composition and matrix multiplication are order-sensitive. The rank inequality follows by viewing $AB$ as the composite $T_A\circ T_B$: its image is contained in the image of $T_A$ and is the image under $T_A$ of a space of dimension at most $\operatorname{rank}(B)$.

## 4.2.16 Concluding principle

A matrix is the **coordinate representative of a linear map**, not a replacement for the map itself. Fixing bases turns the abstract theory into computation:

$$
\boxed{
\begin{aligned}
[T(v)]_{\mathcal C}&=[T]_{\mathcal C\leftarrow\mathcal B}[v]_{\mathcal B},\\
[S+T]&=[S]+[T],\\
[S\circ T]&=[S][T],\\
[T^{-1}]&=[T]^{-1}\quad\text{when defined}.
\end{aligned}}
$$

It remains to understand what happens to these arrays when the basis is changed. That is the subject of Part 4.3.


- [Exercises]({{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/02-matrix-representations-of-linear-maps/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/02-matrix-representations-of-linear-maps/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/02-matrix-representations-of-linear-maps/references/' | relative_url }})

[Back to Linear Transformations and Coordinate Systems]({{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/' | relative_url }})

</article>
