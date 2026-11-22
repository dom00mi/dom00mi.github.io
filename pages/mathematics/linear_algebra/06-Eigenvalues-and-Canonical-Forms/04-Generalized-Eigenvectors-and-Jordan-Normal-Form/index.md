---
layout: default
title: "6.4: Generalized Eigenvectors and Jordan Normal Form"
permalink: /pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/04-generalized-eigenvectors-and-jordan-normal-form/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/04-generalized-eigenvectors-and-jordan-normal-form/' | relative_url }}">← Generalized Eigenvectors and Jordan Normal Form</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 6.4</div>
  <h1>Generalized Eigenvectors and Jordan Normal Form</h1>
</div>

<article class="article" markdown="1">

# 6.4 — Generalized Eigenvectors and Jordan Normal Form

Not every operator admits a basis of ordinary eigenvectors. Nevertheless, when its characteristic polynomial splits, it admits a basis made from **chains of generalised eigenvectors**. In that basis its matrix has **Jordan normal form**: a direct sum of simple blocks. This provides a classification of matrices up to similarity, extending diagonalisation.

We assume throughout that $V$ is finite dimensional over a field $K$ and that the characteristic polynomial of $T\in\operatorname{End}(V)$ splits over $K$. In particular, the discussion always applies over $\mathbb C$. A real matrix whose characteristic polynomial does not split over $\mathbb R$ need not have a real Jordan form consisting of the blocks below.

## 6.4.1 — Why ordinary eigenspaces are insufficient

Consider

$$
A=\begin{pmatrix}2&1\\0&2\end{pmatrix}.
$$

Its characteristic polynomial is $(t-2)^2$, but

$$
E_2(A)=\ker(A-2I)=\operatorname{span}\left\{\begin{pmatrix}1\\0\end{pmatrix}\right\}
$$

has dimension $1$. The eigenvector $v_1=(1,0)^{\mathsf T}$ cannot be completed to an ordinary eigenbasis, but the vector $v_2=(0,1)^{\mathsf T}$ satisfies

$$
(A-2I)v_2=v_1,\qquad (A-2I)v_1=0.
$$

Thus $v_2$ is not itself an eigenvector, yet a second application of $A-2I$ annihilates it. The ordered pair $(v_1,v_2)$ contains the additional information that diagonalisation misses.

## 6.4.2 — Generalised eigenspaces

**Definition 6.4.1.** A nonzero vector $v$ is a **generalised eigenvector** for $\lambda$ if

$$
(T-\lambda I)^kv=0
$$

for some positive integer $k$. In finite dimension $n=\dim V$, the associated **generalised eigenspace** is

$$
\boxed{G_\lambda(T)=\ker(T-\lambda I)^n.}
$$

An ordinary eigenvector is a generalised eigenvector with $k=1$. The generalised eigenspace contains the ordinary eigenspace:

$$
E_\lambda(T)=\ker(T-\lambda I)
\subseteq\ker(T-\lambda I)^2\subseteq\cdots\subseteq G_\lambda(T).
$$

**Lemma 6.4.2 (Invariance and stabilisation).** Each $\ker(T-\lambda I)^k$ is $T$-invariant. Moreover the ascending sequence of kernels stabilises by the $n$th power:

$$
\ker(T-\lambda I)^n=\ker(T-\lambda I)^{n+1}=\cdots.
$$

*Proof.* Set $N=T-\lambda I$. Since $T$ commutes with $N$, if $N^kv=0$, then $N^k(Tv)=T(N^kv)=0$. For stabilisation, the dimensions of the nested kernels can increase at most $n$ times. If $\ker N^k=\ker N^{k+1}$ at one stage, and $N^{k+2}v=0$, then $Nv\in\ker N^{k+1}=\ker N^k$, hence $v\in\ker N^{k+1}$; induction then forces equality at all later powers. $\square$

**Remark 6.4.3.** If $\lambda$ is not an eigenvalue, then $T-\lambda I$ is invertible and every kernel above is zero. Thus the generalised eigenspace is nontrivial only for characteristic roots.

## 6.4.3 — Primary decomposition: different eigenvalues do not interact

Suppose

$$
\chi_T(t)=\prod_{j=1}^s(t-\lambda_j)^{a_j},
\qquad\lambda_i\neq\lambda_j\ (i\neq j).
$$

Define

$$
f_j(t)=(t-\lambda_j)^{a_j},\qquad
q_j(t)=\frac{\chi_T(t)}{f_j(t)}.
$$

The polynomials $q_1,\ldots,q_s$ have greatest common divisor $1$. Thus Bézout's polynomial identity provides $h_1,\ldots,h_s\in K[t]$ such that

$$
\sum_{j=1}^s h_j(t)q_j(t)=1.
\tag{6.4.1}
$$

**Theorem 6.4.4 (Primary or generalised eigenspace decomposition).** Under the splitting assumption,

$$
\boxed{V=G_{\lambda_1}(T)\oplus\cdots\oplus G_{\lambda_s}(T),}
$$

and

$$
\boxed{\dim G_{\lambda_j}(T)=a_j.}
$$

*Proof (spanning).* Define $P_j=h_j(T)q_j(T)$. Cayley–Hamilton and (6.4.1) imply

$$
I=\sum_{j=1}^s P_j.
$$

Also,

$$
f_j(T)P_j=f_j(T)h_j(T)q_j(T)
=h_j(T)\chi_T(T)=0,
$$

so $\operatorname{im}P_j\subseteq\ker f_j(T)=G_{\lambda_j}(T)$. Every vector is therefore a sum of vectors from the generalised eigenspaces.

*Proof (directness).* The polynomial $P_j(t)$ is congruent to $1$ modulo $f_j(t)$ and to $0$ modulo $f_k(t)$ for $k\neq j$ (by the Bézout identity). Therefore $P_j$ acts as the identity on $G_{\lambda_j}$ and as zero on $G_{\lambda_k}$ for $k\neq j$. Applying $P_j$ to a relation $v_1+\cdots+v_s=0$, with $v_k\in G_{\lambda_k}$, gives $v_j=0$. Hence the sum is direct.

The restriction of $T$ to $G_{\lambda_j}$ has the sole eigenvalue $\lambda_j$ and hence characteristic polynomial $(t-\lambda_j)^{\dim G_{\lambda_j}}$. Comparing the characteristic polynomial of the block direct sum with the given factorisation proves $\dim G_{\lambda_j}=a_j$. $\square$

**Corollary 6.4.5.** The operators $P_j$ in the proof are polynomial projections:

$$
P_j^2=P_j,\quad P_iP_j=0\ (i\neq j),\quad
\sum_jP_j=I,\quad TP_j=P_jT.
$$

They project onto generalised eigenspaces, just as the spectral projectors of §6.2 project onto ordinary eigenspaces in the diagonalisable case.

## 6.4.4 — Chains of kernels and ranges: the Fitting decomposition

For an arbitrary operator $N:V\to V$, the sequences

$$
V\supseteq\operatorname{im}N\supseteq\operatorname{im}N^2\supseteq\cdots
$$

and

$$
\{0\}\subseteq\ker N\subseteq\ker N^2\subseteq\cdots
$$

are nested. In dimension $n$ they stabilise by the $n$th power. Set

$$
R_\infty(N)=\operatorname{im}N^n,\qquad
K_\infty(N)=\ker N^n.
$$

**Theorem 6.4.6 (Fitting decomposition).**

$$
\boxed{V=R_\infty(N)\oplus K_\infty(N).}
$$

The restriction of $N$ to $R_\infty(N)$ is invertible, while its restriction to $K_\infty(N)$ is nilpotent.

*Proof.* Since $\operatorname{im}N^{n+1}=\operatorname{im}N^n$, the restriction $N:R_\infty(N)\to R_\infty(N)$ is surjective and thus bijective in finite dimension. If $v$ belongs to both $R_\infty(N)$ and $K_\infty(N)$, then $N^nv=0$ but $N^n$ is injective on $R_\infty(N)$, forcing $v=0$. Finally, rank–nullity applied to $N^n$ gives

$$
\dim R_\infty(N)+\dim K_\infty(N)=\dim V.
$$

This proves the direct sum, and $N^n$ is zero on $K_\infty(N)$ by its definition. $\square$

Taking $N=T-\lambda I$ makes the nilpotent part precisely the generalised eigenspace for $\lambda$.

## 6.4.5 — Nilpotence and Jordan chains

**Definition 6.4.7.** An operator $N$ is **nilpotent** when $N^r=0$ for some $r\ge1$. Its **nilpotency index** is the smallest such $r$.

A **Jordan chain of length $r$ for $\lambda$** consists of vectors $v_1,\ldots,v_r$ satisfying

$$
(T-\lambda I)v_1=0,
\qquad
(T-\lambda I)v_j=v_{j-1}\quad(2\le j\le r).
$$

The last vector $v_r$ generates the chain; its successive images are $v_{r-1},\ldots,v_1,0$. If the chain has length $r$ then $(T-\lambda I)^{r-1}v_r\neq0$ and $(T-\lambda I)^rv_r=0$.

**Definition 6.4.8 (Jordan block).** The **Jordan block of size $r$ for $\lambda$** is

$$
J_r(\lambda)=
\begin{pmatrix}
\lambda&1&0&\cdots&0\\
0&\lambda&1&\ddots&\vdots\\
\vdots&\ddots&\ddots&\ddots&0\\
0&\cdots&0&\lambda&1\\
0&\cdots&\cdots&0&\lambda
\end{pmatrix}=\lambda I_r+N_r,
$$

where $N_r$ has ones immediately **above** the main diagonal and zeroes elsewhere. This convention corresponds to the ordered chain $(v_1,\ldots,v_r)$. Reversing the chain order yields the equivalent convention with ones **below** the diagonal found in some sources.

**Example 6.4.9 (Differentiation).** Over a field of characteristic zero, on $P_2(K)$ the differentiation operator has the chain

$$
x^2\longmapsto2x\longmapsto2\longmapsto0.
$$

In the ordered basis $(2,2x,x^2)$, its representing matrix is

$$
[D]_{\mathcal B}=\begin{pmatrix}0&1&0\\0&0&1\\0&0&0\end{pmatrix}=J_3(0).
$$

**Example 6.4.10 (Shift).** The map $N(x,y,z)=(y,z,0)$ on $K^3$ has a chain

$$
e_3\longmapsto e_2\longmapsto e_1\longmapsto0
$$

and represents the same block $J_3(0)$ in the standard ordered basis $(e_1,e_2,e_3)$.

**Lemma 6.4.11.** If a nilpotent operator has a basis that is a union of Jordan chains, then its nilpotency index equals the length of the longest chain.

*Proof.* Every basis vector is killed by the longest chain length, so the entire operator is. The generator of a longest chain survives one fewer iteration, so no smaller exponent can annihilate the operator. $\square$

## 6.4.6 — Jordan normal form theorem

**Theorem 6.4.12 (Jordan normal form).** If $\chi_T$ splits over $K$, there is a basis in which $T$ has matrix

$$
\boxed{J=\operatorname{diag}\big(J_{r_1}(\lambda_{i_1}),\ldots,J_{r_q}(\lambda_{i_q})\big).}
$$

Equivalently, there exists an invertible $P$ such that

$$
\boxed{A=PJP^{-1}.}
$$

The Jordan blocks are **unique up to reordering**. Over an algebraically closed field, every matrix therefore has a Jordan normal form.

### Proof of existence: reduction to nilpotent operators

By Theorem 6.4.4,

$$
V=\bigoplus_{j=1}^sG_{\lambda_j}(T).
$$

On $G_{\lambda_j}$ the operator $N_j=T-\lambda_jI$ is nilpotent. Hence it suffices to show that **every nilpotent operator has a basis made from disjoint Jordan chains**.

We prove this assertion by induction on $n=\dim V$. It is immediate for $n=1$. Suppose $N\neq0$ and let $W=\operatorname{im}N$, a proper nonzero $N$-invariant subspace. By induction the restricted nilpotent map $N|_W$ has a chain basis. Write its chains, in the order from zero end to generator, as

$$
(w_{i,1},\ldots,w_{i,r_i}),
\quad Nw_{i,1}=0,\quad Nw_{i,j}=w_{i,j-1}
\qquad(1\le i\le q).
$$

Each generator $w_{i,r_i}$ belongs to $W=\operatorname{im}N$. Choose $u_i\in V$ with $Nu_i=w_{i,r_i}$. Then

$$
(w_{i,1},\ldots,w_{i,r_i},u_i)
$$

is a chain in $V$ one vector longer than the original chain. The vectors $u_i$ are linearly independent modulo $W$: if $\sum_i a_iu_i\in W$, applying $N$ shows $\sum_i a_iw_{i,r_i}\in N(W)$, whereas the distinct chain generators have independent images modulo $N(W)$; hence all $a_i=0$.

There may still be missing vectors in $\ker N$. The zero ends $w_{i,1}$ give a basis of $\ker N\cap W$, so extend these to a basis of $\ker N$ by adding vectors $z_1,\ldots,z_s$ outside $W$. Treat each $z_j$ as a chain of length one. The extended chains and the $z_j$ are linearly independent and their number of vectors is

$$
\dim W+q+s=\dim\operatorname{im}N+\dim\ker N=n.
$$

Therefore they form a Jordan-chain basis of $V$. Adding back the scalar $\lambda_j$ on each primary component completes the existence proof. $\square$

## 6.4.7 — How Jordan-block sizes are determined

Fix an eigenvalue $\lambda$, restrict to its generalised eigenspace, and let $N=T-\lambda I$. Put

$$
d_k=\dim\ker(N^k),\qquad d_0=0.
$$

For a Jordan block of length $r$, its contribution to $d_k$ is $\min(k,r)$. Therefore

$$
\boxed{d_k-d_{k-1}=\#\{\text{Jordan blocks for }\lambda\text{ of length at least }k\}.}
$$

It follows that the number of blocks of **exactly** length $k$ is

$$
\boxed{b_k=2d_k-d_{k-1}-d_{k+1}.}
$$

**Proof of uniqueness.** Each $d_k$ is determined by the operator, not by its representing basis. The sequence of differences above therefore determines all block sizes and multiplicities uniquely. Conversely, the Jordan blocks determine every $d_k$. Thus two matrices in Jordan form are similar if and only if they have the same eigenvalues with the same multiset of block sizes for each eigenvalue. $\square$

**Corollary 6.4.13.** The geometric multiplicity of $\lambda$ equals the **number** of Jordan blocks for $\lambda$; the algebraic multiplicity equals the **sum of their sizes**:

$$
m_g(\lambda)=\#\{\lambda\text{-blocks}\},\qquad
m_a(\lambda)=\sum_{\lambda\text{-blocks}}\text{block length}.
$$

Diagonalisation occurs precisely when **all** Jordan blocks have length $1$.

## 6.4.8 — Partitions and the combinatorics of nilpotence

A nilpotent operator on an $n$-dimensional space is classified up to similarity by a **partition** of $n$: its Jordan-block lengths arranged in decreasing order.

**Example 6.4.14.** Consider the partition

$$
(3,3,2,1,1,1),\qquad 3+3+2+1+1+1=11.
$$

It corresponds to a nilpotent matrix similar to

$$
J_3(0)\oplus J_3(0)\oplus J_2(0)\oplus J_1(0)\oplus J_1(0)\oplus J_1(0).
$$

The associated kernel dimensions are

$$
d_1=6,\qquad d_2=9,\qquad d_3=11,
$$

and the successive differences are $(6,3,2)$: six chains have length at least one, three have length at least two, and two have length at least three. This is the **conjugate (transpose) partition**, which may be read from the transposed Young diagram.

The number of nilpotent similarity classes in $M_n(\mathbb C)$ therefore equals the number $p(n)$ of integer partitions of $n$. Its generating series is

$$
\sum_{n=0}^\infty p(n)q^n=\prod_{r=1}^\infty\frac{1}{1-q^r},\qquad |q|<1.
$$

## 6.4.9 — Worked Jordan-form examples

**Example 6.4.15 (A three-dimensional defective eigenvalue).** Let

$$
A=\begin{pmatrix}2&1&0\\0&2&0\\0&0&3\end{pmatrix}.
$$

Here $\chi_A(t)=(t-2)^2(t-3)$ and

$$
\dim\ker(A-2I)=1,\qquad \dim\ker(A-3I)=1.
$$

The eigenvalue $2$ has one block of size $2$, while $3$ has one block of size $1$. The displayed matrix is already in Jordan form:

$$
J=J_2(2)\oplus J_1(3).
$$

An eigenvector chain for $2$ is $e_1,e_2$, since $(A-2I)e_2=e_1$. The remaining vector $e_3$ is an eigenvector for $3$.

**Example 6.4.16 (Two blocks for one eigenvalue).** For

$$
A=\begin{pmatrix}4&1&0\\0&4&0\\0&0&4\end{pmatrix},
$$

we find

$$
\chi_A(t)=(t-4)^3,\quad
\dim\ker(A-4I)=2,\quad
\dim\ker(A-4I)^2=3.
$$

Hence the block sizes are $2$ and $1$ and

$$
J=J_2(4)\oplus J_1(4),\qquad m_A(t)=(t-4)^2.
$$

**Example 6.4.17 (Two matrices with the same characteristic polynomial).** The matrices

$$
A=\begin{pmatrix}0&0\\0&0\end{pmatrix},\qquad
B=\begin{pmatrix}0&1\\0&0\end{pmatrix}
$$

have the same characteristic polynomial $t^2$, but $A$ has two Jordan blocks of length $1$ and $B$ one block of length $2$. They are not similar.

## 6.4.10 — Minimal polynomial and the largest block

**Theorem 6.4.18.** Suppose the Jordan form of $A$ contains, for each eigenvalue $\lambda_j$, a largest Jordan block of length $r_j$. Then

$$
\boxed{m_A(t)=\prod_{j=1}^s(t-\lambda_j)^{r_j}.}
$$

*Proof.* On a block $J_r(\lambda)=\lambda I+N_r$, the polynomial $(t-\lambda)^r$ annihilates the block, whereas no smaller positive power does, because $N_r^{r-1}\neq0$. A polynomial annihilates a block diagonal matrix exactly when it annihilates every block; its minimal annihilating polynomial is therefore the least common multiple of their individual minimal polynomials. This is the displayed expression. $\square$

In particular, $A$ is diagonalisable if and only if each $r_j=1$, recovering the square-free minimal-polynomial test from §6.3.

## 6.4.11 — Jordan form and similarity classification

The characteristic polynomial supplies the eigenvalues and their total multiplicities; the minimal polynomial supplies each largest block size; and the successive dimensions $\dim\ker(A-\lambda I)^k$ supply the full block distribution. These are **similarity invariants**.

The Jordan canonical form gives a complete answer to the similarity problem when the characteristic polynomial splits. Nilpotent blocks are indecomposable building blocks, and the primary decomposition separates the distinct eigenvalues before these blocks are assembled. The next section uses this form to compute powers, exponentials, and analytic functions of matrices.


- [Exercises]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/04-generalized-eigenvectors-and-jordan-normal-form/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/04-generalized-eigenvectors-and-jordan-normal-form/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/04-generalized-eigenvectors-and-jordan-normal-form/references/' | relative_url }})

[Back to Eigenvalues and Canonical Forms]({{ '/pages/mathematics/linear_algebra/06-eigenvalues-and-canonical-forms/' | relative_url }})

</article>
