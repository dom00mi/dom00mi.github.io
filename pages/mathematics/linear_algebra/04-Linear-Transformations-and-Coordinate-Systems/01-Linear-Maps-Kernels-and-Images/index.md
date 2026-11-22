---
layout: default
title: "4.1: Linear Maps Kernels and Images"
permalink: /pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/01-linear-maps-kernels-and-images/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/01-linear-maps-kernels-and-images/' | relative_url }}">← Linear Maps Kernels and Images</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 4.1</div>
  <h1>Linear Maps Kernels and Images</h1>
</div>

<article class="article" markdown="1">

# 4.1: Linear Maps, Kernels and Images

The purpose of this chapter is to study **maps that preserve linear structure**. The notions of vector space, basis, linear independence and subspace have already been introduced in earlier chapters; we use them here without redefining them. Our focus is the mapping itself: how it acts, what information it preserves, which vectors it sends to zero, and which vectors it can reach.

## 4.1.1 Maps, domains, codomains and composition

Let $f:X\longrightarrow Y$ be a function. We call $X$ the **domain** and $Y$ the **codomain**, and write

$$
\operatorname{im}f=f(X)=\{f(x):x\in X\}\subseteq Y.
$$

The **graph** is the set

$$
\Gamma_f=\{(x,f(x)):x\in X\}\subseteq X\times Y.
$$

A map is **injective** if distinct inputs have distinct outputs, equivalently,

$$
 f(x_1)=f(x_2)\ \Longrightarrow\ x_1=x_2.
$$

It is **surjective** if every $y\in Y$ occurs as $f(x)$ for some $x\in X$, or, equivalently, $\operatorname{im}f=Y$. A map that is both injective and surjective is **bijective**.

**Definition 4.1.1 (Composition).** If $f:X\to Y$ and $g:Y\to Z$, the composition is

$$
(g\circ f)(x)=g(f(x)),\qquad g\circ f:X\longrightarrow Z.
$$

The order matters. For $f(x)=x^2$ and $g(x)=x+2$,

$$
(g\circ f)(x)=x^2+2,\qquad (f\circ g)(x)=(x+2)^2.
$$

Composition is associative: whenever the maps are composable,

$$
 h\circ(g\circ f)=(h\circ g)\circ f.
$$

**Definition 4.1.2 (Inverse map).** A map $g:Y\to X$ is the inverse of $f:X\to Y$ when

$$
 g\circ f=\operatorname{id}_X,\qquad f\circ g=\operatorname{id}_Y.
$$

Such an inverse exists exactly when $f$ is bijective, and is then unique. For example, $f(x)=x+2$ has inverse $f^{-1}(y)=y-2$. The identity and inverse relations concern arbitrary maps; linearity is an additional property.

## 4.1.2 Linear transformations and linear combinations

Let $V,W$ be vector spaces over the same field $\mathbb F$.

**Definition 4.1.3 (Linear map).** A function $T:V\to W$ is a *linear map*, also called a *homomorphism* or *linear transformation*, if for every $u,v\in V$ and $\lambda\in\mathbb F$,

$$
\begin{aligned}
T(u+v)&=T(u)+T(v),\\
T(\lambda v)&=\lambda T(v).
\end{aligned}
$$

Terminology varies: some authors reserve *linear transformation* or *linear operator* for a map $T:V\to V$. We will call such a map an **endomorphism** or **linear operator** when this distinction matters.

**Proposition 4.1.4 (Linear-combination criterion).** The following statements are equivalent:

1. $T$ preserves addition and scalar multiplication.
2. For all $u,v\in V$ and $\lambda,\mu\in\mathbb F$,

   $$
   T(\lambda u+\mu v)=\lambda T(u)+\mu T(v).
   $$

3. For every finite family $v_1,\ldots,v_s\in V$,

   $$
   T\!\left(\sum_{k=1}^{s}\lambda_kv_k\right)
    =\sum_{k=1}^{s}\lambda_kT(v_k).
   $$

*Proof.* The first property gives the second by applying scalar and additive preservation; induction on $s$ gives the third. Taking $s=2$ with suitable coefficients recovers the two axioms. In particular, the zero-summand case is compatible with $T(0_V)=0_W$. $\square$

**Corollary 4.1.5.** Every linear map satisfies

$$
T(0_V)=0_W,\qquad T(-v)=-T(v),\qquad T(u-v)=T(u)-T(v).
$$

*Proof.* Since $T(0_V)=T(0\cdot v)=0\cdot T(v)=0_W$, the remaining identities follow from linearity. $\square$

This simple test excludes translations: $x\mapsto x+1$ is not linear, since it does not preserve the zero vector. The map $x\mapsto x^3$ is bijective over $\mathbb R$ but is not linear, showing that bijectivity alone is insufficient for linear isomorphism.

## 4.1.3 A catalogue of linear and nonlinear maps

The following illustrations emphasise that the spaces involved need not be coordinate spaces.

**Example 4.1.6 (Scalar and coordinate maps).** The map $T:\mathbb R\to\mathbb R$, $T(x)=mx$, is linear for any fixed $m$, and

$$
T:\mathbb R^2\to\mathbb R,\qquad T(x,y)=x+y
$$

is linear as well. More generally, a fixed $m\times n$ matrix $A$ induces a linear map $T_A:\mathbb F^n\to\mathbb F^m$ by $T_A(x)=Ax$. In contrast, $h(x,y)=(5x-2y,xy)$ is nonlinear: its second coordinate fails to preserve addition.

**Example 4.1.7 (Embedding and projection).** These maps are linear:

$$
\iota:\mathbb R^2\to\mathbb R^3,\quad \iota(x,y)=(x,y,0),
$$

$$
\pi:\mathbb R^3\to\mathbb R^2,\quad \pi(x,y,z)=(x,y).
$$

The embedding is injective but not surjective; the projection is surjective but not injective. The projection to the $x$-axis,

$$
\Pi_x(x,y)=(x,0),
$$

is a linear operator on $\mathbb R^2$ satisfying $\Pi_x^2=\Pi_x$.

**Example 4.1.8 (Rotations, dilations and reflections).** In $\mathbb R^2$, a rotation through $\theta$ is the map

$$
R_\theta(x,y)=\bigl(x\cos\theta-y\sin\theta,\ x\sin\theta+y\cos\theta\bigr).
$$

It is linear. So is the dilation $D_s(v)=sv$, and for $s\ne0$ the dilation is invertible. Reflection across any line through the origin is also linear and invertible. These are examples of **automorphisms**, linear isomorphisms from a space to itself.

**Example 4.1.9 (Polynomials, differentiation and integration).** For $\mathcal P_n(\mathbb R)$, the real polynomials of degree at most $n$, differentiation gives

$$
D:\mathcal P_n\to\mathcal P_n,\qquad D(p)=p',
$$

which is linear because $(\lambda p+\mu q)'=\lambda p'+\mu q'$. The map

$$
J:\mathcal P_2\to\mathcal P_3,\qquad
J(a_0+a_1x+a_2x^2)=a_0x+\frac{a_1}{2}x^2+\frac{a_2}{3}x^3
$$

is also linear. It chooses the antiderivative having constant term zero. The translation-of-argument operator

$$
S:\mathcal P_5\to\mathcal P_5,\qquad (Sp)(x)=p(x-1)
$$

is an automorphism with inverse $(S^{-1}p)(x)=p(x+1)$. For instance,

$$
S(x^3+2x)=x^3-3x^2+5x-3.
$$

**Example 4.1.10 (Maps between function and matrix spaces).** The maps

$$
\tau:M_2(\mathbb R)\to M_2(\mathbb R),\qquad \tau(A)=A^{\mathsf T}
$$

and

$$
\operatorname{tr}:M_2(\mathbb R)\to\mathbb R,
\qquad \operatorname{tr}\!\begin{pmatrix}a&b\\c&d\end{pmatrix}=a+d
$$

are linear. Transposition is an automorphism: $\tau^2=\operatorname{id}$. The determinant map is *not* linear in the whole matrix argument. The map

$$
H:M_2(\mathbb R)\to\mathcal P_3,\qquad
H\!\begin{pmatrix}a&b\\c&d\end{pmatrix}=(a+b+2d)+cx^2+cx^3
$$

is linear and will provide a useful example of image and kernel.

**Example 4.1.11 (Trigonometric functions).** The coefficient map

$$
C:\operatorname{span}\{\cos t,\sin t\}\to\mathbb R^2,
\qquad C(a\cos t+b\sin t)=\begin{pmatrix}a\\b\end{pmatrix}
$$

is linear and bijective; its inverse sends a pair $(a,b)$ to $a\cos t+b\sin t$.

## 4.1.4 Operations on linear maps

**Proposition 4.1.12.** If $S,T:V\to W$ are linear and $\alpha,\beta\in\mathbb F$, then

$$
(\alpha S+\beta T)(v)=\alpha S(v)+\beta T(v)
$$

is linear. Thus $\mathcal L(V,W)$, the collection of linear maps from $V$ to $W$, carries the usual pointwise operations.

*Proof.* For $u,v\in V$ and $a,b\in\mathbb F$,

$$
\begin{aligned}
(\alpha S+\beta T)(au+bv)
&=\alpha\bigl(aS(u)+bS(v)\bigr)+\beta\bigl(aT(u)+bT(v)\bigr)\\
&=a(\alpha S+\beta T)(u)+b(\alpha S+\beta T)(v).
\end{aligned}
$$

The zero map is the additive identity. $\square$

**Proposition 4.1.13 (Composition preserves linearity).** If $T:U\to V$ and $S:V\to W$ are linear, then $S\circ T:U\to W$ is linear, since

$$
\begin{aligned}
(S\circ T)(\alpha u+\beta v)
&=S\bigl(\alpha T(u)+\beta T(v)\bigr)\\
&=\alpha(S\circ T)(u)+\beta(S\circ T)(v).
\end{aligned}
$$

Composition is associative but generally **not commutative**. For instance, the plane projection $\Pi_x$ and a nontrivial rotation need not commute. The operations on endomorphisms form an associative, generally noncommutative algebra.

## 4.1.5 Kernels and images

**Definition 4.1.14.** For a linear map $T:V\to W$, define its **kernel** (also called **null space**) and **image** (also called **range**) by

$$
\boxed{\ker T=\{v\in V:T(v)=0_W\},\qquad
\operatorname{im}T=\{T(v):v\in V\}.}
$$

The kernel is a subset of the *domain*, while the image is a subset of the *codomain*; it is important not to confuse $\operatorname{im}T$ with all of $W$.

**Proposition 4.1.15.** The kernel $\ker T$ is a subspace of $V$ and the image $\operatorname{im}T$ is a subspace of $W$.

*Proof.* If $T(u)=T(v)=0_W$, then for any $\lambda,\mu\in\mathbb F$,

$$
T(\lambda u+\mu v)=\lambda T(u)+\mu T(v)=0_W,
$$

so the kernel is closed under linear combinations. Likewise, any $w_1=T(u)$ and $w_2=T(v)$ in the image satisfy

$$
\lambda w_1+\mu w_2=T(\lambda u+\mu v)\in\operatorname{im}T.
$$

Both sets contain the appropriate zero vector. $\square$

**Proposition 4.1.16 (Images and preimages).** If $U\subseteq V$ is a subspace, then $T(U)$ is a subspace of $W$. If $Z\subseteq W$ is a subspace, then its preimage

$$
T^{-1}(Z)=\{v\in V:T(v)\in Z\}
$$

is a subspace of $V$. Here $T^{-1}(Z)$ denotes a *preimage of a set* and does not require that the map $T$ have an inverse.

*Proof.* Closure follows from linearity in both cases: an image of a linear combination is the corresponding combination of images. In the preimage case, $T(u),T(v)\in Z$ implies $T(\lambda u+\mu v)\in Z$. $\square$

## 4.1.6 Injectivity, surjectivity and isomorphisms

**Theorem 4.1.17 (Kernel criterion).** A linear map $T:V\to W$ is injective if and only if

$$
\boxed{\ker T=\{0_V\}.}
$$

*Proof.* If $T(u)=T(v)$, then $T(u-v)=0_W$. A trivial kernel therefore implies $u-v=0_V$, hence $u=v$. Conversely, if $T$ is injective and $T(v)=0_W=T(0_V)$, then $v=0_V$. $\square$

**Theorem 4.1.18 (Isomorphisms).** The following are equivalent for a linear map $T:V\to W$:

1. $T$ is bijective.
2. There exists a linear map $S:W\to V$ such that $S\circ T=\operatorname{id}_V$ and $T\circ S=\operatorname{id}_W$.

In that case $S=T^{-1}$, $V$ and $W$ are called **isomorphic**, and we write $V\cong W$.

*Proof.* If $T$ is bijective, its set-theoretic inverse exists. For $w_1=T(v_1)$ and $w_2=T(v_2)$,

$$
T^{-1}(\lambda w_1+\mu w_2)
=T^{-1}\!\left(T(\lambda v_1+\mu v_2)\right)
=\lambda v_1+\mu v_2.
$$

Thus the inverse is linear. The converse follows immediately from the two identity compositions. $\square$

**Proposition 4.1.19.** The inverse of an isomorphism is an isomorphism, and the composition of two composable isomorphisms is an isomorphism. Consequently, isomorphism is an equivalence relation on the class of vector spaces under discussion: reflexivity follows from the identity, symmetry from inverses, and transitivity from composition.

**Theorem 4.1.20 (Dimension and isomorphism).** For finite-dimensional $V,W$,

$$
V\cong W\quad\Longleftrightarrow\quad\dim V=\dim W.
$$

*Proof.* An isomorphism sends any basis $v_1,\ldots,v_n$ of $V$ to a basis $T(v_1),\ldots,T(v_n)$ of $W$: injectivity gives independence, while surjectivity gives spanning. Hence the dimensions agree. Conversely, if both spaces have dimension $n$, choose ordered bases $(v_i)$ and $(w_i)$ and define $T(\sum_i a_iv_i)=\sum_i a_iw_i$. This gives a linear bijection. $\square$

**Corollary 4.1.21 (Coordinate realisation).** If $\dim V=n$, every choice of ordered basis $\mathcal B=(v_1,\ldots,v_n)$ determines an isomorphism

$$
\kappa_{\mathcal B}:V\longrightarrow\mathbb F^n,
\qquad
\kappa_{\mathcal B}\!\left(\sum_{i=1}^n a_iv_i\right)
=\begin{pmatrix}a_1\\\vdots\\a_n\end{pmatrix}.
$$

This is not the claim that $V$ literally equals $\mathbb F^n$: rather, choosing a basis provides a reversible, structure-preserving **coordinate description**. It lets us transport computations between coordinate vectors and abstract vectors.

**Example 4.1.22 (A polynomial dependence in coordinates).** In $\mathcal P_2(\mathbb R)$, using the ordered basis $(x^2,x,1)$, let

$$
p_1=x^2-3,\qquad p_2=2x^2+x+4,\qquad p_3=8x^2+3x+6.
$$

> **Source-note (coefficient correction).** The supplied extract lists $p_3=8x^2+4x+6$ but also claims $p_3=2p_1+3p_2$. Those assertions are incompatible. To retain the intended dependency example, the $x$-coefficient has been corrected from $4$ to $3$ here.

Their coordinate vectors are

$$
[p_1]=\begin{pmatrix}1\\0\\-3\end{pmatrix},\quad
[p_2]=\begin{pmatrix}2\\1\\4\end{pmatrix},\quad
[p_3]=\begin{pmatrix}8\\4\\6\end{pmatrix}
=2[p_1]+3[p_2].
$$

Because the coordinate map is injective,

$$
p_3=2p_1+3p_2.
$$

The conclusion holds in the polynomial space itself, not merely in the chosen coordinate representation.

## 4.1.7 Fibres: which inputs have the same image?

For $w\in W$, the **fibre** over $w$ is

$$
T^{-1}(\{w\})=\{v\in V:T(v)=w\}.
$$

**Proposition 4.1.23 (Fibre as a translate of the kernel).** If $w\in\operatorname{im}T$ and $v_0\in V$ satisfies $T(v_0)=w$, then

$$
\boxed{T^{-1}(\{w\})=v_0+\ker T
=\{v_0+k:k\in\ker T\}.}
$$

*Proof.* For $k\in\ker T$, $T(v_0+k)=w$. Conversely, if $T(v)=w$, then $T(v-v_0)=0_W$, so $v-v_0\in\ker T$. $\square$

Thus $T(u)=T(v)$ exactly when $u-v\in\ker T$. Each fibre is an **affine translate** of the kernel. This is the precise meaning behind the geometric picture of a linear map collapsing parallel families of vectors onto one output.

**Example 4.1.24 (Vertical lines).** For $\pi(x,y,z)=(x,y)$,

$$
\ker\pi=\{(0,0,z):z\in\mathbb R\},
$$

and the fibre over $(a,b)$ is

$$
\pi^{-1}(\{(a,b)\})=\{(a,b,z):z\in\mathbb R\}.
$$

It is a vertical line in $\mathbb R^3$, while the image is all of $\mathbb R^2$.

**Example 4.1.25 (Diagonal lines and planes).** For $h:\mathbb R^2\to\mathbb R$, $h(x,y)=x+y$, the fibre over $w$ is the line $x+y=w$, parallel to $\ker h=\operatorname{span}\{(1,-1)\}$. For $F:\mathbb R^3\to\mathbb R^2$, $F(x,y,z)=(x,x)$, the image is $\operatorname{span}\{(1,1)\}$ and each nonempty fibre is a plane $x=a$. The codomain is two-dimensional, but the range is only one-dimensional.

## 4.1.8 Worked examples of kernels and images

**Example 4.1.26.** Let $T:\mathbb R^2\to\mathbb R^2$ be defined by

$$
T(x,y)=(x+y,x+y).
$$

Then $T(x,y)=(0,0)$ precisely when $y=-x$, so

$$
\ker T=\operatorname{span}\{(1,-1)\}.
$$

Since $T(x,y)=(x+y)(1,1)$ and every scalar can occur as $x+y$,

$$
\operatorname{im}T=\operatorname{span}\{(1,1)\}.
$$

**Example 4.1.27 (Differentiation).** The map $D:\mathcal P_3\to\mathcal P_3$ has

$$
\ker D=\{c:c\in\mathbb R\}=\operatorname{span}\{1\},
$$

$$
\operatorname{im}D=\mathcal P_2(\mathbb R).
$$

Its nullity as a map is $1$ and its rank as a map is $3$. Here rank and nullity describe *a linear transformation*, not a new definition of the matrix invariants discussed in the preceding chapter.

**Example 4.1.28 (A map from matrices to polynomials).** For

$$
H\!\begin{pmatrix}a&b\\c&d\end{pmatrix}=(a+b+2d)+cx^2+cx^3,
$$

we have

$$
\operatorname{im}H=\operatorname{span}\{1,x^2+x^3\},
$$

$$
\ker H=\left\{\begin{pmatrix}a&b\\0&-\tfrac{a+b}{2}\end{pmatrix}:a,b\in\mathbb R\right\}.
$$

In particular, $\dim\operatorname{im}H=2$ and $\dim\ker H=2$.

**Example 4.1.29 (A three-to-two map).** Set

$$
T:\mathbb R^3\to\mathbb R^2,\qquad
T(x,y,z)=(x+y-2z,\ x+3y-4z).
$$

Solving $T(x,y,z)=(0,0)$ gives $y=z$ and $x=z$, so

$$
\ker T=\operatorname{span}\{(1,1,1)\}.
$$

Moreover,

$$
\operatorname{im}T
=\operatorname{span}\{(1,1),(1,3),(-2,-4)\}=\mathbb R^2,
$$

since the first two vectors are independent. Thus $T$ is surjective but not injective.

## 4.1.9 Rank and nullity *of a map*: structural consequences

We now use the **dimensions of the kernel and image** specifically in the language of mappings. This is the context needed here; the matrix rank–nullity theory and its general algorithms have already been treated in the preceding chapter.

**Definition 4.1.30.** For a finite-dimensional linear map $T:V\to W$,

$$
\operatorname{nullity}(T):=\dim\ker T,\qquad
\operatorname{rank}(T):=\dim\operatorname{im}T.
$$

**Theorem 4.1.31 (Dimension conservation for a linear map).** If $\dim V=n$, then

$$
\boxed{\dim\ker T+\dim\operatorname{im}T=\dim V.}
$$

*Map-theoretic proof.* Let $v_1,\ldots,v_k$ be a basis of $\ker T$ and extend it to a basis $v_1,\ldots,v_k,u_1,\ldots,u_{n-k}$ of $V$. Then

$$
T(u_1),\ldots,T(u_{n-k})
$$

is a basis of $\operatorname{im}T$. Indeed, every $T(v)$ is a combination of these images, since $T(v_i)=0$. If $\sum_j c_jT(u_j)=0$, then $\sum_j c_ju_j\in\ker T$; expressing it in the $v_i$ basis and using independence of the extended basis forces every $c_j=0$. Counting vectors yields the identity. $\square$

**Corollary 4.1.32 (Equal dimensions).** For $T:V\to W$ with $\dim V=\dim W=n\lt\infty$, the following are equivalent:

$$
\boxed{T\text{ injective}\iff T\text{ surjective}\iff T\text{ bijective}\iff T\text{ an isomorphism}.}
$$

A trivial kernel forces $\dim\operatorname{im}T=n$; surjectivity forces image dimension $n$, hence kernel dimension zero.

**Corollary 4.1.33 (Dimension restrictions).** If $\dim V=n$ and $\dim W=m$, then

- if $n>m$, no linear map $V\to W$ can be injective;
- if $n<m$, no linear map $V\to W$ can be surjective;
- if $n=m$, injectivity and surjectivity are equivalent.

In particular, a nonzero kernel records the information lost by the map, while the image measures the directions accessible in the codomain.

**Proposition 4.1.34 (Images of dependent sets).** A linear map sends any linearly dependent family to a linearly dependent family: if $\sum_i a_iv_i=0$ is a nontrivial dependence, then

$$
\sum_i a_iT(v_i)=T(0)=0.
$$

The converse need not hold: independent vectors can acquire dependent images when the map has a nontrivial kernel. However, an injective linear map preserves linear independence.

**Proposition 4.1.35 (A map and its induced quotient isomorphism).** The assignment

$$
\overline T:V/\ker T\longrightarrow\operatorname{im}T,
\qquad [v]\longmapsto T(v)
$$

is a well-defined linear bijection. It is well-defined because $v-v'\in\ker T$ if and only if $T(v)=T(v')$; it is injective by construction and surjective onto the image. Therefore,

$$
\boxed{V/\ker T\ \cong\ \operatorname{im}T.}
$$

This theorem formalises the fibres-as-classes intuition from the preceding examples; it is included as a consequence for maps, without reintroducing the general definition of a quotient vector space.

## 4.1.10 Additional consequences for one-to-one maps

**Theorem 4.1.36 (Equivalent injectivity tests).** Let $T:V\to W$ be linear and $\dim V=n<\infty$. The following statements are equivalent:

1. $T$ is injective.
2. $T:V\to\operatorname{im}T$ has a linear inverse.
3. $\ker T=\{0_V\}$.
4. $\operatorname{rank}(T)=n$.
5. For every basis $(v_1,\ldots,v_n)$ of $V$, the family $(T(v_1),\ldots,T(v_n))$ is a basis of $\operatorname{im}T$.

*Proof.* Injectivity means that each output in the image comes from exactly one input; the induced inverse is linear by the linearity of $T$. The kernel criterion proves (1) $\iff$ (3). The map-theoretic dimension formula gives (3) $\iff$ (4). If $T$ is injective, the images of independent basis vectors remain independent, and linearity makes them span $\operatorname{im}T$, proving (5). Conversely, if those images form a basis, a vector $v=\sum_j a_jv_j$ with $T(v)=0$ must have every coefficient $a_j=0$, proving injectivity. $\square$

Notice that the *codomain* does not need to have the same dimension as the domain for these equivalences. The inclusion $\iota:\mathbb R^2\to\mathbb R^3$ given by $(x,y)\mapsto(x,y,0)$ satisfies every condition, even though it is not surjective onto $\mathbb R^3$.

**Proposition 4.1.37 (Dimension bounds).** For a map $T:V\to W$ with $\dim V=n$ and $\dim W=m$,

$$
0\le\operatorname{rank}(T)\le\min\{n,m\}.
$$

If $n>m$, then $\operatorname{nullity}(T)\ge n-m$; if $n<m$, then $\dim\operatorname{im}T\le n<m$, so the map cannot be onto. For example, the projection $\mathbb R^3\to\mathbb R^2$ can be surjective but not injective, while the embedding $\mathbb R^2\to\mathbb R^3$ can be injective but not surjective.

**Example 4.1.38 (The zero map and a scalar operator).** The zero map $Z:V\to W$ has

$$
\ker Z=V,\qquad\operatorname{im}Z=\{0_W\},
$$

and the scalar operator $S_c:V\to V$, $S_c(v)=cv$, has a trivial kernel and full image when $c\ne0$. In particular, $S_{-4}:\mathbb R\to\mathbb R$ is an automorphism, whereas $S_0$ is the zero map.

**Example 4.1.39 (Images of basis vectors under the derivative).** Differentiation $D:\mathcal P_3\to\mathcal P_3$ sends

$$
(1,x,x^2,x^3)\longmapsto(0,1,2x,3x^2).
$$

The original family is independent, but its image family is dependent because it contains zero. This illustrates precisely what a nontrivial kernel allows; the nonzero images still span $\operatorname{im}D=\mathcal P_2$.

## 4.1.11 What the map perspective adds

Given a fixed linear map $T$, the objects $\ker T$ and $\operatorname{im}T$ do not require coordinates. If bases are subsequently chosen, their dimensions agree with the nullity and column rank of any representing matrix; this connection is established concretely in Part 4.2. In summary:

$$
\begin{aligned}
\ker T&=T^{-1}(\{0_W\}),\\
\operatorname{im}T&=T(V),\\
T\text{ injective}&\iff\ker T=\{0_V\},\\
T\text{ surjective}&\iff\operatorname{im}T=W,\\
T^{-1}(\{w\})&=v_0+\ker T\quad\text{when }T(v_0)=w.
\end{aligned}
$$

These descriptions lead naturally to matrix representations, which translate the same abstract map into an explicit, computable array of coordinates.


- [Exercises]({{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/01-linear-maps-kernels-and-images/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/01-linear-maps-kernels-and-images/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/01-linear-maps-kernels-and-images/references/' | relative_url }})

[Back to Linear Transformations and Coordinate Systems]({{ '/pages/mathematics/linear_algebra/04-linear-transformations-and-coordinate-systems/' | relative_url }})

</article>
