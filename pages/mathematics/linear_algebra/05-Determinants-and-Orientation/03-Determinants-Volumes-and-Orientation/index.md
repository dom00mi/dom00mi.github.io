---
layout: default
title: "5.3: Determinants Volumes and Orientation"
permalink: /pages/mathematics/linear_algebra/05-determinants-and-orientation/03-determinants-volumes-and-orientation/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/03-determinants-volumes-and-orientation/' | relative_url }}">← Determinants Volumes and Orientation</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 5.3</div>
  <h1>Determinants Volumes and Orientation</h1>
</div>

<article class="article" markdown="1">

# 5.3: Determinants, Volumes and Orientation

This section interprets the determinant as signed volume and orientation, and explains why it is a basis-independent invariant of endomorphisms.


## 5.3.1 Determinants as signed volumes and orientation

Over $\mathbb R$, the determinant has a geometric meaning. If

$$
A=\begin{pmatrix}\mathbf a_1&\cdots&\mathbf a_n\end{pmatrix},
$$

then the columns span a parallelepiped. Its **unsigned $n$-dimensional volume** is

$$
\boxed{\operatorname{Vol}=|\det(A)|.}
$$

The sign of $\det(A)$ records orientation:

- $\det(A)>0$ means orientation is preserved.
- $\det(A)<0$ means orientation is reversed.
- $\det(A)=0$ means the columns are linearly dependent and the parallelepiped is degenerate.

For a linear transformation $T(\mathbf x)=A\mathbf x$ on $\mathbb R^n$, the absolute determinant gives the **volume scaling factor**:

$$
\operatorname{Vol}(A E)=|\det(A)|\operatorname{Vol}(E)
$$

for measurable sets $E$ (with ordinary Euclidean volume).

In particular, this is the linear prototype of the Jacobian factor in the multivariable change-of-variables formula:

$$
\int_{T(E)}f(\mathbf y)\,d\mathbf y
=\int_E f(T(\mathbf x))\,|\det(A)|\,d\mathbf x.
$$

For a differentiable, one-to-one coordinate transformation, $A$ is replaced locally by its Jacobian matrix $DT(\mathbf x)$, under the usual hypotheses of the change-of-variables theorem.

### 5.3.1.1 Areas and cross products

In $\mathbb R^2$, the columns $\mathbf u=(u_1,u_2)^{\mathsf T}$ and $\mathbf v=(v_1,v_2)^{\mathsf T}$ span a parallelogram of area

$$
\left|\det\begin{pmatrix}u_1&v_1\\u_2&v_2\end{pmatrix}\right|
=|u_1v_2-u_2v_1|.
$$

In $\mathbb R^3$, the scalar triple product of three vectors measures oriented volume:

$$
\det\begin{pmatrix}\mathbf u&\mathbf v&\mathbf w\end{pmatrix}
=\mathbf u\cdot(\mathbf v\times\mathbf w).
$$

A convenient formal mnemonic for the cross product is

$$
\mathbf u\times\mathbf v=
\begin{vmatrix}
\mathbf e_1&\mathbf e_2&\mathbf e_3\\
u_1&u_2&u_3\\
v_1&v_2&v_3
\end{vmatrix},
$$

where the first row is expanded **formally** in the basis vectors; strictly speaking this is not a scalar determinant, but a mnemonic for the component formula.



### 5.3.1.2 Orientation and changes of coordinates

An **ordered basis** $\mathcal B=(\mathbf v_1,\ldots,\mathbf v_n)$ of $\mathbb R^n$ is positively oriented relative to the standard basis precisely when

$$
\det\begin{pmatrix}\mathbf v_1&\cdots&\mathbf v_n\end{pmatrix}>0.
$$

Two ordered bases define the same orientation if the change-of-basis matrix has positive determinant. An exchange of two basis vectors reverses orientation. More generally, a composition of two orientation-reversing maps preserves orientation, since the product of two negative determinants is positive.

For example, the reflection $R=\operatorname{diag}(-1,1)$ has $\det(R)=-1$, whereas a planar rotation

$$
Q_\theta=\begin{pmatrix}
\cos\theta&-\sin\theta\\
\sin\theta&\cos\theta
\end{pmatrix}
$$

has determinant $\cos^2\theta+\sin^2\theta=1$ and therefore preserves area and orientation.


## 5.3.2 Endomorphisms and basis independence

### 5.3.2.1 Endomorphisms and their matrix representations

Let $V$ be a finite-dimensional vector space over $\mathbb F$, with

$$
\dim V=n.
$$

**Definition 5.3.1 (Endomorphism).** An **endomorphism** of $V$ is a linear map from $V$ to itself:

$$
T:V\longrightarrow V.
$$

The set of all endomorphisms is denoted by

$$
\operatorname{End}_{\mathbb F}(V)
=\{T:V\to V\mid T\text{ is linear}\}.
$$

It forms a vector space under addition and scalar multiplication of maps. Composition also equips it with an associative, unital **algebra** structure:

$$
(S\circ T)(\mathbf v)=S(T(\mathbf v)).
$$

In general, composition is **not commutative**:

$$
S\circ T\ne T\circ S.
$$

The invertible endomorphisms form the **general linear group**

$$
GL(V)=\{T\in\operatorname{End}_{\mathbb F}(V)\mid T\text{ invertible}\}.
$$

After choosing a basis of $V$, these correspond to the invertible matrices

$$
GL_n(\mathbb F)=\{A\in M_n(\mathbb F)\mid\det(A)\ne0\}.
$$

The determinant restricts to a group homomorphism

$$
\det:GL_n(\mathbb F)\longrightarrow\mathbb F^{\times},
$$

where $\mathbb F^{\times}=\mathbb F\setminus\{0\}$ is the multiplicative group of the field.

### 5.3.2.2 How matrices change with the basis

Choose a basis $\mathcal B=(\mathbf v_1,\ldots,\mathbf v_n)$ of $V$. The endomorphism $T$ is represented by the matrix $[T]_{\mathcal B}$ whose $j$-th column gives the coordinates of $T(\mathbf v_j)$ in the basis $\mathcal B$.

Suppose $\mathcal B'$ is another basis, and let $P$ be the change-of-coordinates matrix satisfying

$$
[\mathbf v]_{\mathcal B}=P[\mathbf v]_{\mathcal B'}
$$

for every $\mathbf v\in V$. Then

$$
\boxed{[T]_{\mathcal B'}=P^{-1}[T]_{\mathcal B}P.}
$$

The matrices representing the same endomorphism in different bases are thus **similar**.

**Proposition 5.3.1 (Basis independence).** The scalar

$$
\det(T):=\det([T]_{\mathcal B})
$$

is independent of the chosen basis $\mathcal B$.

**Proof.** For a second basis $\mathcal B'$, similarity invariance gives

$$
\det([T]_{\mathcal B'})
=\det(P^{-1}[T]_{\mathcal B}P)
=\det([T]_{\mathcal B}).
$$

$\square$

This is the intrinsic reason that the determinant belongs to the transformation itself, not merely to one particular matrix representation.

### 5.3.2.3 Independent changes of domain and codomain

There is an important distinction between an endomorphism $T:V\to V$ and a general linear map $L:V\to W$.

For $T:V\to V$, we normally use the *same basis* in the source and target, so a basis change acts by conjugation:

$$
A\longmapsto P^{-1}AP.
$$

For $L:V\to W$, we may change the domain and codomain bases independently. The matrix then transforms as

$$
A\longmapsto Q^{-1}AP,
$$

with independent invertible matrices $P$ and $Q$ of compatible sizes.

Two matrices of the same size are equivalent under independent invertible row and column changes exactly when they have the same rank. For a square endomorphism under similarity, rank remains an invariant but is **not** the only one: determinant, trace, characteristic polynomial, and ultimately Jordan structure carry further information.

## 5.3.3 Volume forms and the determinant line

The determinant identities from Section 5.2 suggest a deeper construction: the determinant is an alternating multilinear function, and the space of all such functions in top degree is one-dimensional.

### 5.3.3.1 Volume forms

Let $V$ be an $n$-dimensional vector space over $\mathbb F$.

**Definition 5.3.2 (Volume form).** A **volume form** in this algebraic setting is an alternating $n$-linear map

$$
\omega:V^n\longrightarrow\mathbb F.
$$

The set of all such forms is denoted by

$$
\operatorname{Alt}^{n}(V;\mathbb F)
=\Lambda^n V^*.
$$

The determinant, interpreted in a chosen basis, is one such form.

**Theorem 5.3.1 (One-dimensionality of top-degree alternating forms).** If $\dim V=n$, then

$$
\boxed{\dim\Lambda^n V^*=1.}
$$

**Proof.** Fix a basis $\mathcal B=(\mathbf v_1,\ldots,\mathbf v_n)$. For arbitrary vectors

$$
\mathbf w_j=\sum_{i=1}^{n}a_{ij}\mathbf v_i,
$$

multilinearity yields

$$
\begin{aligned}
\omega(\mathbf w_1,\ldots,\mathbf w_n)
&=\sum_{i_1,\ldots,i_n}
\left(\prod_{j=1}^{n}a_{i_j,j}\right)
\omega(\mathbf v_{i_1},\ldots,\mathbf v_{i_n}).
\end{aligned}
$$

Alternation eliminates terms with repeated basis vectors. Every surviving term is a permutation of the basis and therefore equals its permutation sign times $\omega(\mathbf v_1,\ldots,\mathbf v_n)$. Hence

$$
\boxed{
\omega(\mathbf w_1,\ldots,\mathbf w_n)
=\det(A)\,\omega(\mathbf v_1,\ldots,\mathbf v_n),
}
$$

where $A=(a_{ij})$. Thus the entire form is determined by the **single scalar** $\omega(\mathbf v_1,\ldots,\mathbf v_n)$, showing that the dimension is at most one. The determinant form is nonzero and supplies a basis of this space, so the dimension is exactly one. $\square$

This one-dimensional space is often viewed as the **dual determinant line**; the determinant line itself is conventionally $\Lambda^n V$, also one-dimensional.

### 5.3.3.2 A note on characteristic two

In a field of characteristic different from $2$, an alternating multilinear form changes sign when two arguments are exchanged, and conversely skew-symmetry forces repeated arguments to vanish because $2$ is invertible.

In characteristic $2$, however,

$$
-1=1,
$$

and skew-symmetry alone does **not** imply alternation. For that reason we have consistently defined *alternating* by requiring vanishing whenever two arguments coincide. This definition works over every field.

### 5.3.3.3 Coordinate-free determinant of an endomorphism

Fix any nonzero alternating $n$-linear form $\omega$ on an $n$-dimensional vector space $V$. If $T:V\to V$ is an endomorphism, the function

$$
(\mathbf v_1,\ldots,\mathbf v_n)
\longmapsto
\omega(T\mathbf v_1,\ldots,T\mathbf v_n)
$$

is another alternating $n$-linear form. Since the space of such forms is one-dimensional, there is a unique scalar $c\in\mathbb F$ such that

$$
\omega(T\mathbf v_1,\ldots,T\mathbf v_n)
=c\,\omega(\mathbf v_1,\ldots,\mathbf v_n)
$$

for all $\mathbf v_1,\ldots,\mathbf v_n$. That scalar is exactly $\det(T)$. In particular, this characterisation is independent both of coordinates and of the choice of nonzero $\omega$.

If $S,T$ are endomorphisms, applying the relation first to $T$ and then to $S$ gives $\det(S\circ T)=\det(S)\det(T)$, another intrinsic proof of multiplicativity.

- [Exercises]({{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/03-determinants-volumes-and-orientation/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/03-determinants-volumes-and-orientation/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/03-determinants-volumes-and-orientation/references/' | relative_url }})

[Back to Determinants and Orientation]({{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/' | relative_url }})

</article>
