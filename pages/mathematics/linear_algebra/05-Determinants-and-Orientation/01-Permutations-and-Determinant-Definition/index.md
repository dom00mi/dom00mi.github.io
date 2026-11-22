---
layout: default
title: "5.1: Permutations and Determinant Definition"
permalink: /pages/mathematics/linear_algebra/05-determinants-and-orientation/01-permutations-and-determinant-definition/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/01-permutations-and-determinant-definition/' | relative_url }}">← Permutations and Determinant Definition</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 5.1</div>
  <h1>Permutations and Determinant Definition</h1>
</div>

<article class="article" markdown="1">

# 5.1: Permutations and Determinant Definition

This section introduces permutations, transpositions, parity and the Leibniz determinant formula, then proves the alternating multilinear characterisation.

## 5.1.1 The algebraic problem of invertibility

A square matrix $A\in M_n(\mathbb{F})$ is called **nonsingular** if it has an inverse, and **singular** otherwise. Recall from the preceding chapters that the following conditions are equivalent:

1. $A$ is invertible.
2. Every system $A\mathbf{x}=\mathbf{b}$, with $\mathbf{b}\in\mathbb{F}^n$, has exactly one solution.
3. The homogeneous system $A\mathbf{x}=\mathbf{0}$ has only the trivial solution.
4. $\operatorname{rank}(A)=n$, or equivalently $\operatorname{nullity}(A)=0$.
5. Both the rows and the columns of $A$ are linearly independent.
6. The reduced row-echelon form of $A$ is $I_n$.
7. The linear map $\mathbf{x}\mapsto A\mathbf{x}$ is an isomorphism of $\mathbb{F}^n$.

We seek a scalar-valued function satisfying

$$
\boxed{\det(A)\ne 0\quad\Longleftrightarrow\quad A\text{ is invertible}.}
$$

For small matrices, the familiar expressions are

$$
\det\begin{pmatrix}a\end{pmatrix}=a,
\qquad
\det\begin{pmatrix}a&b\\c&d\end{pmatrix}=ad-bc.
$$

For a $3\times3$ matrix, the analogous expression has six terms. In general, a determinant of order $n$ has $n!$ terms in its defining expansion. To understand where these terms and their signs come from, we first study permutations.

## 5.1.2 Permutations, transpositions, parity and inversions

### 5.1.2.1 Permutations of a finite set

**Definition 5.1.1 (Permutation).** Let

$$
N_n=\{1,2,\ldots,n\}.
$$

A **permutation** of $N_n$ is a bijection

$$
\sigma:N_n\longrightarrow N_n.
$$

Its **one-line notation** is the rearrangement

$$
\bigl(\sigma(1),\sigma(2),\ldots,\sigma(n)\bigr),
$$

or, equivalently, its **two-line notation** is

$$
\sigma=
\begin{pmatrix}
1&2&\cdots&n\\
\sigma(1)&\sigma(2)&\cdots&\sigma(n)
\end{pmatrix}.
$$

The set of all permutations of $N_n$ is denoted by $S_n$, the **symmetric group** on $n$ letters. Its group operation is composition.

**Example 5.1.1.** The permutation

$$
\sigma=
\begin{pmatrix}
1&2&3\\
2&3&1
\end{pmatrix}
$$

sends $1\mapsto2$, $2\mapsto3$, $3\mapsto1$. Its one-line notation is $(2,3,1)$.

**Lemma 5.1.1 (Number of permutations).** The symmetric group has order

$$
\boxed{|S_n|=n!}.
$$

**Proof.** We have $n$ possible images for $1$, then $n-1$ images for $2$, and so on. The final element has only one unused image. The multiplication principle gives

$$
|S_n|=n(n-1)\cdots2\cdot1=n!.
$$

### 5.1.2.2 Transpositions

**Definition 5.1.2 (Transposition).** A **transposition** is a permutation that exchanges two distinct elements while fixing every other element. It is usually written $(i\ j)$.

For instance, the transposition $(1\ 2)\in S_6$ is

$$
\begin{pmatrix}
1&2&3&4&5&6\\
2&1&3&4&5&6
\end{pmatrix}.
$$

**Lemma 5.1.2.** Every permutation is a product of transpositions, with the identity regarded as a product of zero transpositions.

**Proof (induction on $n$).** The assertion is immediate when $n=1$ or $n=2$. Suppose it holds for permutations of $N_{n-1}$, and let $\sigma\in S_n$.

If $\sigma(n)=n$, then $\sigma$ restricts to a permutation of $N_{n-1}$ and the induction hypothesis applies. Otherwise, write $k=\sigma(n)\ne n$ and compose $\sigma$ on the left with the transposition $\tau=(k\ n)$. Then

$$
(\tau\circ\sigma)(n)=\tau(k)=n.
$$

The permutation $\tau\circ\sigma$ fixes $n$, so it is a product of transpositions by induction. Since $\tau^{-1}=\tau$,

$$
\sigma=\tau\circ(\tau\circ\sigma)
$$

is also a product of transpositions. $\square$

The decomposition need not be unique. For example, the rearrangements

$$
(1,2,3)\longrightarrow(2,1,3)\longrightarrow(2,3,1)
$$

and

$$
(1,2,3)\longrightarrow(3,2,1)\longrightarrow(3,1,2)
$$

both involve two transpositions.

### 5.1.2.3 Even and odd permutations

Before assigning a sign to a permutation, we need to know that the parity of its transposition count does **not** depend on the chosen factorisation.

**Theorem 5.1.1 (Well-defined parity).** If a permutation is expressed as a product of $p$ transpositions and also as a product of $q$ transpositions, then $p$ and $q$ have the same parity.

**Proof (the Vandermonde product).** Consider the polynomial

$$
\Phi(X_1,\ldots,X_n)
=\prod_{1\le i<j\le n}(X_j-X_i)
$$

in the polynomial ring $\mathbb{Z}[X_1,\ldots,X_n]$. For example,

$$
\Phi(X_1,X_2,X_3)
=(X_2-X_1)(X_3-X_1)(X_3-X_2).
$$

Interchanging any two variables changes the sign of $\Phi$: the factor involving the exchanged pair changes sign, while the remaining factors are merely reordered or exchanged in pairs. Thus each transposition acts on $\Phi$ by multiplication by $-1$.

If $\sigma$ is a product of $p$ transpositions, permuting the variables according to $\sigma$ transforms $\Phi$ into $(-1)^p\Phi$. If the same permutation is also a product of $q$ transpositions, its action is also $(-1)^q\Phi$. Hence

$$
(-1)^p\Phi=(-1)^q\Phi.
$$

Since $\Phi$ is a nonzero polynomial over $\mathbb{Z}$, it follows that $(-1)^p=(-1)^q$. Therefore $p$ and $q$ have the same parity. $\square$

Using integer polynomials in this proof makes the parity argument valid independently of the characteristic of the coefficient field used later.

**Definition 5.1.3 (Sign of a permutation).** The **sign**, or **signature**, is the map

$$
\operatorname{sgn}:S_n\longrightarrow\{+1,-1\},
$$

with

$$
\operatorname{sgn}(\sigma)=
\begin{cases}
+1,&\sigma\text{ is a product of an even number of transpositions},\\
-1,&\sigma\text{ is a product of an odd number of transpositions}.
\end{cases}
$$

In particular, $\operatorname{sgn}(\mathrm{id})=1$ and every transposition has sign $-1$.

**Proposition 5.1.1 (Sign is a homomorphism).** For all $\sigma,\tau\in S_n$,

$$
\boxed{\operatorname{sgn}(\sigma\circ\tau)
=\operatorname{sgn}(\sigma)\operatorname{sgn}(\tau).}
$$

**Proof.** Concatenate any transposition factorisations of $\sigma$ and $\tau$. The total number of transpositions is the sum of their lengths, so their signs multiply. $\square$

### 5.1.2.4 Inversions and a practical sign test

**Definition 5.1.4 (Inversion).** If the one-line notation of $\sigma$ is

$$
\bigl(\sigma(1),\ldots,\sigma(n)\bigr),
$$

an **inversion** is a pair of indices $(i,j)$ such that

$$
i<j\qquad\text{and}\qquad\sigma(i)>\sigma(j).
$$

Let $\operatorname{inv}(\sigma)$ denote the number of inversions. Then

$$
\boxed{\operatorname{sgn}(\sigma)=(-1)^{\operatorname{inv}(\sigma)}.}
$$

Indeed, exchanging two entries changes the inversion count by an odd integer; since the identity has zero inversions, this is consistent with the transposition definition of parity.

**Example 5.1.2.** Consider

$$
\sigma_1=
\begin{pmatrix}
1&2&3&4&5\\
5&3&4&1&2
\end{pmatrix}.
$$

The successive inversion contributions are $4,2,2,0,0$, whence

$$
\operatorname{inv}(\sigma_1)=4+2+2=8,
\qquad \operatorname{sgn}(\sigma_1)=+1.
$$

For

$$
\sigma_2=
\begin{pmatrix}
1&2&3&4&5\\
3&1&2&5&4
\end{pmatrix},
$$

there are $2+0+0+1+0=3$ inversions, so $\operatorname{sgn}(\sigma_2)=-1$.

**Example 5.1.3 (All permutations of three letters).** The even and odd permutations of $S_3$ are

| Even (sign $+1$) | Odd (sign $-1$) |
|:--|:--|
| $(1,2,3)$ | $(2,1,3)$ |
| $(2,3,1)$ | $(1,3,2)$ |
| $(3,1,2)$ | $(3,2,1)$ |

For $n\ge2$, exactly half of the $n!$ permutations are even and half are odd: composing with any fixed transposition pairs each even permutation with an odd one.

## 5.1.3 The determinant and the Leibniz formula

**Definition 5.1.5 (Determinant).** Let $A=(a_{ij})\in M_n(\mathbb{F})$. The **determinant** is the scalar

$$
\boxed{
\det(A)=\sum_{\sigma\in S_n}
\operatorname{sgn}(\sigma)
\prod_{i=1}^{n}a_{i,\sigma(i)}.
}
$$

The formula is also known as the **Leibniz formula**. Each summand selects exactly one entry from each row and one entry from each column. The sign records whether the corresponding selection of columns is an even or odd permutation.

We write

$$
\det(A)=|A|=
\begin{vmatrix}
a_{11}&a_{12}&\cdots&a_{1n}\\
a_{21}&a_{22}&\cdots&a_{2n}\\
\vdots&\vdots&\ddots&\vdots\\
a_{n1}&a_{n2}&\cdots&a_{nn}
\end{vmatrix}.
$$

The vertical bars in this notation mean **determinant**, not absolute value. Over $\mathbb R$, the determinant can be negative.

### 5.1.3.1 Determinants of order one, two, and three

For $n=1$, only the identity permutation occurs, giving

$$
\det\begin{pmatrix}a\end{pmatrix}=a.
$$

For $n=2$, the identity is even and the swap $(1\ 2)$ is odd. Consequently,

$$
\boxed{
\det\begin{pmatrix}a&b\\c&d\end{pmatrix}=ad-bc.
}
$$

For $n=3$, three permutations have positive sign and three have negative sign. Thus

$$
\boxed{
\begin{aligned}
\det\begin{pmatrix}
a&b&c\\ d&e&f\\ g&h&i
\end{pmatrix}
={}&aei+bfg+cdh\\
&-ceg-bdi-afh.
\end{aligned}
}
$$

Equivalently, in entry notation,

$$
\begin{aligned}
\det(A)={}&a_{11}a_{22}a_{33}
+a_{12}a_{23}a_{31}
+a_{13}a_{21}a_{32}\\
&-a_{13}a_{22}a_{31}
-a_{12}a_{21}a_{33}
-a_{11}a_{23}a_{32}.
\end{aligned}
$$

The familiar *rule of Sarrus* is a mnemonic for this $3\times3$ formula. It does **not** extend as a general rule to determinants of higher order.

### 5.1.3.2 Why direct expansion becomes impractical

Since $|S_n|=n!$, the Leibniz formula contains $n!$ summands before any cancellations. It is ideal for defining the determinant and proving structural properties, but inefficient for computing large determinants. We will instead exploit row operations and triangular matrices in Section 5.2.

## 5.1.4 Multilinearity, alternation and uniqueness

Write the columns of $A$ as $\mathbf a_1,\ldots,\mathbf a_n$, so that

$$
A=\begin{pmatrix}\mathbf a_1&\cdots&\mathbf a_n\end{pmatrix}.
$$

The determinant is naturally a function of $n$ column vectors:

$$
\det:(\mathbb{F}^n)^n\longrightarrow\mathbb{F}.
$$

### 5.1.4.1 Multilinearity

**Definition 5.1.6 (Multilinear function).** A function $D:(\mathbb{F}^n)^n\to\mathbb{F}$ is **multilinear** if it is linear in each argument separately, with all other arguments held fixed.

For instance, in column $j$ this reads

$$
\begin{aligned}
&D(\mathbf a_1,\ldots,\alpha\mathbf u+\beta\mathbf v,\ldots,\mathbf a_n)\\
&\quad=\alpha D(\mathbf a_1,\ldots,\mathbf u,\ldots,\mathbf a_n)
+\beta D(\mathbf a_1,\ldots,\mathbf v,\ldots,\mathbf a_n).
\end{aligned}
$$

**Proposition 5.1.2.** The determinant is multilinear in its columns, and likewise in its rows.

**Proof.** In every term of the Leibniz sum there is precisely one factor from each row, and precisely one factor from each column. Replacing a chosen column by $\alpha\mathbf u+\beta\mathbf v$ distributes each term into the corresponding linear combination. Summing over all permutations establishes linearity in that column. The same argument works for each column and each row. $\square$

**Example 5.1.4 (Splitting one column).** Since

$$
\begin{pmatrix}7\\4\\3\end{pmatrix}
=
\begin{pmatrix}3\\2\\1\end{pmatrix}
+
\begin{pmatrix}4\\2\\2\end{pmatrix},
$$

we have

$$
\begin{aligned}
\det\begin{pmatrix}1&7&1\\3&4&1\\2&3&0\end{pmatrix}
={}&\det\begin{pmatrix}1&3&1\\3&2&1\\2&1&0\end{pmatrix}\\
&+\det\begin{pmatrix}1&4&1\\3&2&1\\2&2&0\end{pmatrix}.
\end{aligned}
$$

Only one column is split; **in general the determinant is not additive as a function of entire matrices**:

$$
\boxed{\det(A+B)\ne\det(A)+\det(B)\quad\text{in general}.}
$$

### 5.1.4.2 Alternation

**Definition 5.1.7 (Alternating function).** A multilinear function $D$ is **alternating** if it vanishes whenever two of its arguments coincide:

$$
\mathbf a_i=\mathbf a_j\quad(i\ne j)
\quad\Longrightarrow\quad
D(\mathbf a_1,\ldots,\mathbf a_n)=0.
$$

**Proposition 5.1.3.** The determinant is alternating in its columns and in its rows.

**Proof.** Suppose columns $i$ and $j$ agree. Pair each permutation $\sigma$ in the Leibniz expansion with the permutation obtained by interchanging those two selected columns. The resulting terms have equal products and opposite signs. The terms therefore cancel in pairs, so $\det(A)=0$. The row statement follows by the same argument. $\square$

**Lemma 5.1.3 (Effect of swapping arguments).** If $D$ is alternating and multilinear, then swapping two arguments changes the sign:

$$
D(\ldots,\mathbf u,\ldots,\mathbf v,\ldots)
=-D(\ldots,\mathbf v,\ldots,\mathbf u,\ldots).
$$

**Proof.** Alternation and multilinearity give

$$
\begin{aligned}
0&=D(\ldots,\mathbf u+\mathbf v,\ldots,\mathbf u+\mathbf v,\ldots)\\
&=D(\ldots,\mathbf u,\ldots,\mathbf v,\ldots)
+D(\ldots,\mathbf v,\ldots,\mathbf u,\ldots),
\end{aligned}
$$

because the two terms with repeated arguments are zero. Rearranging proves the claim. $\square$

The alternating property is important even in fields of characteristic $2$: there, $-1=1$, so changing sign does not by itself guarantee that a function vanishes on repeated arguments.

### 5.1.4.3 The unique normalised alternating multilinear form

**Theorem 5.1.2 (Characterisation of the determinant).** There is exactly one map

$$
D:(\mathbb{F}^n)^n\longrightarrow\mathbb{F}
$$

with the following three properties:

1. $D$ is multilinear.
2. $D$ is alternating.
3. $D(\mathbf e_1,\ldots,\mathbf e_n)=1$, where $\mathbf e_1,\ldots,\mathbf e_n$ are the standard basis vectors.

That map is the determinant.

**Proof.** Existence follows from the previous propositions and $\det(I_n)=1$. For uniqueness, write each column in the standard basis:

$$
\mathbf a_j=\sum_{i=1}^{n}a_{ij}\mathbf e_i.
$$

Repeated multilinearity gives

$$
D(\mathbf a_1,\ldots,\mathbf a_n)
=\sum_{i_1=1}^{n}\cdots\sum_{i_n=1}^{n}
\left(\prod_{j=1}^{n}a_{i_j,j}\right)
D(\mathbf e_{i_1},\ldots,\mathbf e_{i_n}).
$$

Every term with repeated indices vanishes by alternation. Thus the only surviving index lists are permutations of $(1,\ldots,n)$. By Lemma 5.1.3 and the normalisation,

$$
D(\mathbf e_{\sigma(1)},\ldots,\mathbf e_{\sigma(n)})
=\operatorname{sgn}(\sigma).
$$

Consequently,

$$
D(\mathbf a_1,\ldots,\mathbf a_n)
=\sum_{\sigma\in S_n}
\operatorname{sgn}(\sigma)
\prod_{j=1}^{n}a_{\sigma(j),j}
=\det(A),
$$

where the final equality is the Leibniz formula, reindexed by inverse permutations. Hence $D$ is uniquely determined. $\square$

This theorem is one of the central conceptual results of the chapter: the determinant is not defined arbitrarily. Its algebraic properties force its formula.

- [Exercises]({{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/01-permutations-and-determinant-definition/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/01-permutations-and-determinant-definition/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/01-permutations-and-determinant-definition/references/' | relative_url }})

[Back to Determinants and Orientation]({{ '/pages/mathematics/linear_algebra/05-determinants-and-orientation/' | relative_url }})

</article>
