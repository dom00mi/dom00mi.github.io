---
layout: default
title: "3.3: Matrix Rank Nullity and Solvability"
permalink: /pages/mathematics/linear_algebra/03-matrices-and-linear-systems/03-matrix-rank-nullity-and-solvability/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/03-matrices-and-linear-systems/03-matrix-rank-nullity-and-solvability/' | relative_url }}">← Matrix Rank Nullity and Solvability</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 3.3</div>
  <h1>Matrix Rank Nullity and Solvability</h1>
  <p class="lead">Placeholder topic for Matrix Rank Nullity and Solvability. (TBD)</p>
</div>

<article class="article" markdown="1">

# 03 — Matrix Rank, Nullity, and Solvability

> **From elimination to structure.** Gaussian elimination tells us *how* to solve a system of linear equations. Rank and nullity explain *why* a system has no solution, exactly one solution, or a family of solutions. The essential link is that every matrix represents a linear transformation, and the number of independent constraints is measured by its rank.

In the preceding chapter, we transformed systems of linear equations into row-echelon and reduced row-echelon forms. Here, we develop the algebraic language underlying those computations: matrices over a field, matrix operations, column and row spaces, rank, kernels, nullity, and precise criteria for solvability. We shall also distinguish the properties inherited from the scalar field from those that *do not* survive matrix multiplication.

Throughout, unless otherwise stated, the scalar field is the real numbers. Most algebraic arguments remain valid over an arbitrary field.

---

## 3.1. Linear Systems in Matrix Form

**Definition 3.1 (Matrix).** Let the entries of an array belong to a field, denoted by the symbol below. An **m-by-n matrix** is a rectangular array with m rows and n columns:

$$
\mathbb F\text{ is a field (for example }\mathbb R\text{ or }\mathbb C\text{)},
\qquad
A=(a_{ij})\in\mathbb{F}^{m\times n}.
$$

Explicitly,

$$
A=
\begin{pmatrix}
a_{11}&a_{12}&\cdots&a_{1n}\\
a_{21}&a_{22}&\cdots&a_{2n}\\
\vdots&\vdots&\ddots&\vdots\\
a_{m1}&a_{m2}&\cdots&a_{mn}
\end{pmatrix}.
$$

A system of m linear equations in n unknowns,

$$
\begin{aligned}
a_{11}x_1+\cdots+a_{1n}x_n&=b_1,\\
&\vdots\\
a_{m1}x_1+\cdots+a_{mn}x_n&=b_m,
\end{aligned}
$$

can be written compactly as

$$
\boxed{A\mathbf{x}=\mathbf{b}},
\qquad
\mathbf{x}=\begin{pmatrix}x_1\\\vdots\\x_n\end{pmatrix},
\qquad
\mathbf{b}=\begin{pmatrix}b_1\\\vdots\\b_m\end{pmatrix}.
$$

The **augmented matrix** is obtained by adjoining the right-hand side as an additional column:

$$
[A\mid\mathbf b]=
\left(\begin{array}{cccc|c}
a_{11}&a_{12}&\cdots&a_{1n}&b_1\\
a_{21}&a_{22}&\cdots&a_{2n}&b_2\\
\vdots&\vdots&\ddots&\vdots&\vdots\\
a_{m1}&a_{m2}&\cdots&a_{mn}&b_m
\end{array}\right).
$$

Every elementary row operation acts on the *entire* augmented matrix. It therefore transforms the equations without changing their common solution set.

**Definition 3.2 (Matrix–vector product).** For a matrix with n columns and a vector with n entries, define

$$
(A\mathbf{x})_i=\sum_{j=1}^{n}a_{ij}x_j,
\qquad i=1,\ldots,m.
$$

If the columns of the matrix are denoted by the following vectors,

$$
A=\begin{pmatrix}\mathbf a_1&\mathbf a_2&\cdots&\mathbf a_n\end{pmatrix},
$$

then matrix multiplication may also be understood as a linear combination of columns:

$$
\boxed{A\mathbf{x}=x_1\mathbf a_1+\cdots+x_n\mathbf a_n.}
$$

This formula will become the key to understanding solvability.

---

## 3.2. Matrices and the Algebraic Structure of Fields

Before studying rank, it is worth identifying the scalar arithmetic on which matrix operations depend.

### 3.2.1. The field axioms

**Definition 3.3 (Field).** A **field** is a set equipped with addition and multiplication satisfying the usual rules of arithmetic. For all scalars in the field, the following properties hold.

**Additive properties:**

$$
\begin{aligned}
a+b&=b+a &&\text{(commutativity)},\\
(a+b)+c&=a+(b+c) &&\text{(associativity)},\\
a+0&=a &&\text{(additive identity)},\\
a+(-a)&=0 &&\text{(additive inverse)}.
\end{aligned}
$$

**Multiplicative properties:**

$$
\begin{aligned}
ab&=ba &&\text{(commutativity)},\\
(ab)c&=a(bc) &&\text{(associativity)},\\
a\cdot1&=a &&\text{(multiplicative identity)},\\
a\cdot a^{-1}&=1\quad(a\ne0)
&&\text{(multiplicative inverse)}.
\end{aligned}
$$

The two operations are connected by **distributivity**:

$$
\boxed{a(b+c)=ab+ac.}
$$

We also require the two identities to be distinct:

$$
0\ne1.
$$

The real and complex numbers are fields. The rational numbers are another example. More generally, the integers modulo a prime form a finite field, so Gaussian elimination is not inherently restricted to real-valued equations: division by a *nonzero* pivot is possible in any field.

The distinction between a field and a matrix algebra matters. A matrix is built *using* field elements, but the collection of all square matrices is generally **not itself a field**.

### 3.2.2. Addition and scalar multiplication of matrices

For matrices of the same size and for a scalar, define these operations entrywise:

$$
(A+B)_{ij}=a_{ij}+b_{ij},
\qquad
(\lambda A)_{ij}=\lambda a_{ij}.
$$

These operations inherit the familiar properties of the scalar field:

$$
\begin{aligned}
A+B&=B+A,\\
(A+B)+C&=A+(B+C),\\
A+0&=A,\\
A+(-A)&=0,\\
\lambda(A+B)&=\lambda A+\lambda B,\\
(\lambda+\mu)A&=\lambda A+\mu A,\\
(\lambda\mu)A&=\lambda(\mu A),\\
1A&=A.
\end{aligned}
$$

**Proposition 3.1.** The set of all m-by-n matrices over a field, with matrix addition and scalar multiplication, is a vector space over that field. Its dimension is mn.

**Proof.** Each vector-space axiom holds entrywise because it holds in the underlying field. In addition, the matrices having a single entry equal to 1 and every other entry equal to 0 form a basis, with exactly mn elements. Thus,

$$
\dim_{\mathbb F}\!\left(\mathbb F^{m\times n}\right)=mn.
$$

The natural correspondence between an m-by-n matrix and its mn entries therefore identifies matrix space with an ordinary coordinate vector space. ∎

### 3.2.3. Matrix multiplication and composition

For compatible dimensions, matrix multiplication is defined by

$$
A\in\mathbb F^{m\times r},
\qquad
B\in\mathbb F^{r\times n},
\qquad
AB\in\mathbb F^{m\times n},
$$

with

$$
\boxed{(AB)_{ij}=\sum_{k=1}^{r}a_{ik}b_{kj}.}
$$

The entry in row i and column j is the dot product of row i of the first matrix with column j of the second matrix (without complex conjugation).

This definition is not arbitrary. Matrix multiplication represents the **composition of linear maps**. If a matrix B first maps a vector into an intermediate space, and A subsequently maps the result into another space, their combined action is

$$
\mathbf{x}\longmapsto B\mathbf{x}
\longmapsto A(B\mathbf{x})=(AB)\mathbf{x}.
$$

Thus the rightmost matrix acts first.

**Theorem 3.1 (Algebraic properties of matrix multiplication).** Whenever the dimensions are compatible,

$$
\begin{aligned}
(AB)C&=A(BC)&&\text{(associativity)},\\
A(B+C)&=AB+AC&&\text{(left distributivity)},\\
(A+B)C&=AC+BC&&\text{(right distributivity)},\\
I_mA&=A=AI_n&&\text{(identity)},\\
\lambda(AB)&=(\lambda A)B=A(\lambda B).
\end{aligned}
$$

Here the two identity matrices have sizes appropriate to the rectangular matrix A.

**Proof (associativity).** Let A, B and C have compatible sizes. The entry at position (i,j) of the two associations is

$$
\begin{aligned}
((AB)C)_{ij}
&=\sum_{k}\left(\sum_{\ell}a_{i\ell}b_{\ell k}\right)c_{kj}\\
&=\sum_{\ell}a_{i\ell}\left(\sum_k b_{\ell k}c_{kj}\right)\\
&=(A(BC))_{ij}.
\end{aligned}
$$

We have only rearranged finite sums and scalar products, which is justified by the field axioms. Distributivity follows similarly, or directly from the linearity of the maps represented by the matrices. ∎

### 3.2.4. Why matrix multiplication is not commutative

For ordinary scalars, multiplication is commutative. For matrices, it generally is not:

$$
\boxed{AB\ne BA\quad\text{in general}.}
$$

**Example 3.1.** Consider the real matrices

$$
A=\begin{pmatrix}1&2\\3&4\end{pmatrix},
\qquad
B=\begin{pmatrix}5&6\\7&8\end{pmatrix}.
$$

Direct multiplication gives

$$
AB=\begin{pmatrix}19&22\\43&50\end{pmatrix},
\qquad
BA=\begin{pmatrix}23&34\\31&46\end{pmatrix}.
$$

The results differ because the order of composition matters. Both displayed matrices are invertible, so even invertible matrices need not commute. For rectangular matrices, one order of multiplication may even be undefined.

**Consequences.** Ordinary algebraic manipulations must respect the order of factors. For example,

$$
(A+B)^2=A^2+AB+BA+B^2,
$$

rather than the scalar binomial expansion unless A and B commute. Likewise,

$$
(A+B)(A-B)=A^2-AB+BA-B^2.
$$

It simplifies to the usual difference of squares only when

$$
AB=BA.
$$

### 3.2.5. Are matrices a field?

For square matrices of order n, matrix addition and multiplication form an **associative ring with identity**, and indeed an **algebra over the scalar field**. But, for n greater than 1, this algebra is **not a field**:

1. Multiplication is generally noncommutative.
2. Some nonzero matrices are not invertible.
3. Products of two nonzero matrices can be zero.

To see the third point, take

$$
P=\begin{pmatrix}1&0\\0&0\end{pmatrix},
\qquad
Q=\begin{pmatrix}0&0\\0&1\end{pmatrix}.
$$

Then

$$
P\ne0,\qquad Q\ne0,\qquad PQ=0.
$$

Thus cancellation is not automatically valid for matrix multiplication. For example, from an equality of the form

$$
AB=AC
$$

we cannot in general conclude that B equals C; that conclusion is valid if A is invertible. The special case of 1-by-1 matrices is naturally identified with the underlying field itself.

The invertible n-by-n matrices, taken on their own, **do** form a group under multiplication, called the *general linear group*:

$$
\operatorname{GL}_n(\mathbb F)
=\{A\in\mathbb F^{n\times n}:A\text{ is invertible}\}.
$$

For n greater than 1 this group is generally noncommutative (nonabelian). In the 1-by-1 case, it is the multiplicative group of the nonzero field elements.

**Summary of the distinction:** scalar addition and multiplication form a field; same-sized matrices form a vector space under addition and scalar multiplication; square matrices form a generally noncommutative unital algebra under matrix addition and matrix multiplication.

### 3.2.6. Transposes and further identities

The transpose interchanges rows and columns:

$$
(A^T)_{ij}=a_{ji}.
$$

It satisfies

$$
\begin{aligned}
(A+B)^T&=A^T+B^T,\\
(\lambda A)^T&=\lambda A^T,\\
(AB)^T&=B^TA^T.
\end{aligned}
$$

Notice the reversal of multiplication order in the last identity. A matrix is **symmetric** when it equals its transpose. Over the complex numbers, the conjugate transpose is written using an asterisk or dagger; it is important not to confuse transpose with conjugate transpose.

---

## 3.3. Matrices as Linear Transformations

**Definition 3.4 (Linear transformation associated with a matrix).** A matrix determines a function between coordinate spaces:

$$
T_A:\mathbb F^n\longrightarrow\mathbb F^m,
\qquad
T_A(\mathbf x)=A\mathbf x.
$$

This map is **linear** because, for any vectors and scalars,

$$
\begin{aligned}
T_A(\alpha\mathbf u+\beta\mathbf v)
&=A(\alpha\mathbf u+\beta\mathbf v)\\
&=\alpha A\mathbf u+\beta A\mathbf v\\
&=\alpha T_A(\mathbf u)+\beta T_A(\mathbf v).
\end{aligned}
$$

Viewed in this way, a linear system asks a geometric question: **does the target vector belong to the image of this map, and how many input vectors map to it?**

The output vectors produced by the map form its **image**:

$$
\operatorname{Im}(A)=\{A\mathbf x:\mathbf x\in\mathbb F^n\}.
$$

The input vectors mapped to zero form its **kernel**:

$$
\ker(A)=\{\mathbf x\in\mathbb F^n:A\mathbf x=0\}.
$$

These objects measure two fundamentally different aspects of a matrix: how large a space its outputs can fill, and how many independent directions of input are invisible to the transformation.

---

## 3.4. Column Space, Row Space, and Matrix Rank

### 3.4.1. Column and row spaces

**Definition 3.5 (Column space).** For the columns of a matrix, define

$$
\operatorname{Col}(A)
=\operatorname{span}\{\mathbf a_1,\ldots,\mathbf a_n\}
\subseteq\mathbb F^m.
$$

The column space is exactly the image of the corresponding linear transformation, since any matrix–vector product is a linear combination of its columns:

$$
\boxed{\operatorname{Col}(A)=\operatorname{Im}(A).}
$$

**Definition 3.6 (Row space).** The row space is the subspace spanned by the rows of A, regarded as vectors in the n-dimensional coordinate space:

$$
\operatorname{Row}(A)\subseteq\mathbb F^n.
$$

**Definition 3.7 (Rank).** The rank of A is the dimension of its column space:

$$
\boxed{\operatorname{rank}(A)=\dim\operatorname{Col}(A).}
$$

Equivalently, rank is the maximum number of linearly independent columns.

The rank can never exceed either matrix dimension:

$$
\boxed{0\le\operatorname{rank}(A)\le\min\{m,n\}.}
$$

A matrix has **full column rank** when its rank equals n and **full row rank** when its rank equals m. A square matrix has **full rank** when its rank equals its order.

### 3.4.2. Rank from row-echelon form

**Theorem 3.2 (Pivot-count characterization).** The rank of a matrix equals the number of pivots in any row-echelon form of the matrix.

**Proof.** Elementary row operations amount to left multiplication by invertible elementary matrices. If E is invertible, then

$$
EA\mathbf x=0
\quad\Longleftrightarrow\quad
A\mathbf x=0.
$$

Hence a linear dependence relation among the columns of A holds if and only if the same relation holds among the columns of EA. In particular, elementary row operations preserve column rank.

Now let R be an echelon form of A. Its pivot columns are linearly independent: in a nontrivial combination of pivot columns, consider the rightmost pivot column with a nonzero coefficient and inspect its pivot row. Every non-pivot column is a linear combination of the pivot columns, as is especially clear after continuing to reduced row-echelon form. The pivot columns therefore form a basis of the column space of R. If there are r pivots, then

$$
\operatorname{rank}(R)=r
=\operatorname{rank}(A).
$$

This proves the claim. ∎

**Important distinction.** Row operations preserve the rank and the linear relations among columns, but they need not preserve the *actual column space as a subset of the output space*. In contrast, invertible row operations preserve the actual row space. The pivot **positions** in the reduced matrix identify which columns of the **original** matrix form a column-space basis.

### 3.4.3. Equality of row rank and column rank

**Theorem 3.3 (Row rank equals column rank).** For every matrix over a field,

$$
\boxed{\dim\operatorname{Row}(A)
=\dim\operatorname{Col}(A)
=\operatorname{rank}(A).}
$$

**Proof.** Reduce A to an echelon matrix R by elementary row operations. These operations preserve the row space, because each new row is a linear combination of the old rows and every operation is reversible. The nonzero rows of an echelon matrix are linearly independent: their leading entries occur in distinct, successively later columns. Thus the row-space dimension is the number of nonzero rows, equal to the pivot count. Theorem 3.2 shows that the same pivot count equals the dimension of the column space. ∎

An immediate consequence is that transposition preserves rank:

$$
\boxed{\operatorname{rank}(A^T)=\operatorname{rank}(A).}
$$

### 3.4.4. Example: detecting dependent columns

**Example 3.2.** Consider

$$
A=\begin{pmatrix}
1&2&3\\
2&4&6\\
1&1&2
\end{pmatrix}.
$$

Apply elementary row operations:

$$
\begin{aligned}
\begin{pmatrix}1&2&3\\2&4&6\\1&1&2\end{pmatrix}
&\xrightarrow{\substack{R_2\leftarrow R_2-2R_1\\R_3\leftarrow R_3-R_1}}
\begin{pmatrix}1&2&3\\0&0&0\\0&-1&-1\end{pmatrix}\\[6pt]
&\xrightarrow{\substack{R_2\leftrightarrow R_3\\R_2\leftarrow -R_2}}
\begin{pmatrix}1&2&3\\0&1&1\\0&0&0\end{pmatrix}.
\end{aligned}
$$

There are two pivots, so the rank is 2. Indeed, the original third column is the sum of the first two:

$$
\begin{pmatrix}3\\6\\2\end{pmatrix}
=
\begin{pmatrix}1\\2\\1\end{pmatrix}
+
\begin{pmatrix}2\\4\\1\end{pmatrix}.
$$

The two original pivot columns form a basis for the column space, even though the original third column is not independent of them.

---

## 3.5. Null Space and Nullity

**Definition 3.8 (Null space).** The null space, or kernel, of a matrix is the set of solutions to its associated homogeneous system:

$$
\mathcal N(A)=\ker(A)
=\{\mathbf x\in\mathbb F^n:A\mathbf x=0\}.
$$

**Proposition 3.2.** The null space is a vector subspace of the input space.

**Proof.** The zero vector belongs to the null space. If two vectors belong to it, then for any scalars,

$$
A(\alpha\mathbf u+\beta\mathbf v)
=\alpha A\mathbf u+\beta A\mathbf v=0.
$$

The null space is therefore closed under linear combinations. ∎

**Definition 3.9 (Nullity).** The nullity is the dimension of the null space:

$$
\boxed{\operatorname{nullity}(A)=\dim\ker(A).}
$$

Its value counts the independent free directions along which the input can move without altering the output.

### Example 3.3. A one-dimensional null space

Take

$$
A=\begin{pmatrix}1&2&3\\2&4&6\\1&1&2\end{pmatrix}.
$$

The reduced row-echelon form is

$$
\operatorname{rref}(A)
=\begin{pmatrix}1&0&1\\0&1&1\\0&0&0\end{pmatrix}.
$$

Consequently,

$$
\begin{cases}
x_1+x_3=0,\\
x_2+x_3=0.
\end{cases}
$$

Set the free variable equal to an arbitrary scalar. Then

$$
\mathbf x
=t\begin{pmatrix}-1\\-1\\1\end{pmatrix},
\qquad t\in\mathbb F.
$$

The null space is a line through the origin (over the real numbers), and

$$
\operatorname{rank}(A)=2,
\qquad
\operatorname{nullity}(A)=1.
$$

---

## 3.6. The Rank–Nullity Theorem

**Theorem 3.4 (Rank–Nullity).** For any linear transformation represented by an m-by-n matrix,

$$
T_A:\mathbb F^n\longrightarrow\mathbb F^m,
$$

we have

$$
\boxed{\operatorname{rank}(A)+\operatorname{nullity}(A)=n.}
$$

The dimension on the right-hand side is the **dimension of the domain**, or equivalently the number of columns of A—not the number of equations.

### Proof I: Gaussian elimination and free variables

Let the reduced row-echelon form of A have r pivot columns. Each pivot column determines a leading variable, so there are exactly

$$
n-r
$$

free variables. Any solution of the homogeneous system is determined uniquely once the free variables have been chosen. To construct a basis for the null space, set each free variable in turn equal to 1 and all other free variables equal to 0, then solve for the pivot variables. This gives n-r vectors.

These vectors are linearly independent: their free-variable coordinates form the standard coordinate vectors. They also span the null space, since every choice of free variables is a linear combination of those standard choices. Therefore,

$$
\operatorname{nullity}(A)=n-r.
$$

Because the number of pivots equals rank,

$$
\operatorname{rank}(A)=r.
$$

Adding the identities yields

$$
\boxed{\operatorname{rank}(A)+\operatorname{nullity}(A)=r+(n-r)=n.}
$$

∎

### Proof II: a basis adapted to the kernel

Let a basis of the kernel consist of k vectors:

$$
\mathbf v_1,\ldots,\mathbf v_k.
$$

Extend this to a basis of the entire domain:

$$
\mathbf v_1,\ldots,\mathbf v_k,
\mathbf w_1,\ldots,\mathbf w_{n-k}.
$$

The image vectors

$$
A\mathbf w_1,\ldots,A\mathbf w_{n-k}
$$

form a basis of the image of A. They span the image because every input is a combination of the chosen basis vectors and all the kernel vectors map to zero. They are independent because any linear combination of the w-vectors mapped to zero would belong to the kernel, contradicting the independence of the full domain basis unless all coefficients vanish.

The image therefore has dimension n-k, while the kernel has dimension k:

$$
\operatorname{rank}(A)=n-k,
\qquad
\operatorname{nullity}(A)=k.
$$

The result follows. ∎

**Interpretation.** The domain decomposes, in terms of dimension, into directions that produce independent outputs and directions that the map annihilates. Rank measures the first; nullity measures the second.

---

## 3.7. General Solution = Particular Solution + Homogeneous Solution

The preceding chapter showed how free variables produce parameterised families of solutions. We can now express this principle more structurally.

**Theorem 3.5 (General solution theorem).** Suppose the system below is consistent, and let a particular solution satisfy the second equation:

$$
A\mathbf x=\mathbf b,
\qquad
A\mathbf x_p=\mathbf b.
$$

Then the complete solution set is

$$
\boxed{\{\mathbf x_p+\mathbf z:\mathbf z\in\ker(A)\}.}
$$

Equivalently,

$$
\boxed{\text{General solution}
=\text{Particular solution}+\text{Homogeneous solution}.}
$$

**Proof.** Suppose x is any solution. By linearity,

$$
A(\mathbf x-\mathbf x_p)
=A\mathbf x-A\mathbf x_p
=\mathbf b-\mathbf b=0.
$$

Hence the difference lies in the kernel. Conversely, any kernel vector z satisfies

$$
A(\mathbf x_p+\mathbf z)
=A\mathbf x_p+A\mathbf z
=\mathbf b+0=\mathbf b.
$$

Thus the two descriptions of the solution set coincide. ∎

If a basis of the kernel is given by

$$
\mathbf v_1,\ldots,\mathbf v_k,
$$

then every solution is uniquely expressible as

$$
\boxed{\mathbf x=\mathbf x_p+t_1\mathbf v_1+\cdots+t_k\mathbf v_k,
\qquad t_1,\ldots,t_k\in\mathbb F.}
$$

Here the number of independent parameters is exactly the nullity:

$$
k=\operatorname{nullity}(A)=n-\operatorname{rank}(A).
$$

Over the real numbers, the solution set is an **affine subspace** of dimension k. It passes through the origin precisely when the right-hand side is zero (or, more generally, when zero is a solution). If the system is inconsistent, there is no particular solution and the solution set is empty.

---

## 3.8. The Fundamental Solvability Criterion

Rank describes the number of independent constraints, but consistency also depends on the right-hand side.

**Theorem 3.6 (Rouché–Capelli theorem / rank criterion).** A system is consistent if and only if the coefficient matrix and the augmented matrix have the same rank:

$$
\boxed{A\mathbf x=\mathbf b\ \text{is solvable}
\iff
\operatorname{rank}(A)=\operatorname{rank}([A\mid\mathbf b]).}
$$

Equivalently,

$$
\boxed{\mathbf b\in\operatorname{Col}(A).}
$$

**Proof.** Since a matrix–vector product is a linear combination of the columns of A, the equation has a solution if and only if the vector b lies in the span of those columns. Appending a column already in the column space does not increase its dimension, so the two ranks are equal. Conversely, equality of the ranks implies that the appended column does not enlarge the original column space, and hence belongs to it. ∎

Because appending one column can increase rank by at most one,

$$
\operatorname{rank}([A\mid\mathbf b])
\in\{\operatorname{rank}(A),\operatorname{rank}(A)+1\}.
$$

The second possibility signals inconsistency.

### 3.8.1. Consistency and the row-reduction test

If Gaussian elimination produces a row of the form

$$
\left(\begin{array}{cccc|c}0&0&\cdots&0&c\end{array}\right),
\qquad c\ne0,
$$

then the corresponding equation would assert

$$
0=c,
$$

which is impossible in a field. Conversely, if no such row appears in echelon form, back-substitution with arbitrary free variables provides at least one solution.

Thus row reduction and the rank criterion express the same solvability test in computational and structural languages.

---

## 3.9. How Rank Determines the Number of Solutions

Let the number of unknowns be n, and write the coefficient rank as r.

**Theorem 3.7 (Classification of solutions).** For a system over an infinite field, exactly one of the following occurs:

| Rank condition | Number of solutions | Interpretation |
|---|---|---|
| Rank of the augmented matrix exceeds r | None | The equations contradict one another |
| Both ranks equal r and r = n | Exactly one | Every variable is a pivot variable |
| Both ranks equal r and r is less than n | Infinitely many | There are n − r free variables |

The classification follows by combining the consistency criterion, the rank–nullity theorem and the general solution theorem.

**Corollary 3.1 (Uniqueness).** A *consistent* system has a unique solution if and only if the kernel is trivial:

$$
\boxed{\ker(A)=\{0\}
\iff\operatorname{rank}(A)=n.}
$$

The consistency assumption is essential: a rectangular full-column-rank matrix can still have a target vector outside its image.

**Corollary 3.2 (Solvability for every right-hand side).** The system can be solved for *every* possible right-hand side in the output space if and only if

$$
\boxed{\operatorname{rank}(A)=m.}
$$

This condition says precisely that the map is surjective and its columns span the entire output space.

**Corollary 3.3 (Square matrices).** If A is n-by-n, the following conditions are equivalent:

$$
\begin{aligned}
&\operatorname{rank}(A)=n;\\
&\operatorname{nullity}(A)=0;\\
&\ker(A)=\{0\};\\
&A\text{ is invertible};\\
&A\mathbf x=\mathbf b\text{ has exactly one solution for every }\mathbf b.
\end{aligned}
$$

If these conditions hold, the unique solution is obtained using the inverse matrix:

$$
\mathbf x=A^{-1}\mathbf b.
$$

The inverse need not be computed explicitly to solve the system; row reduction is usually more direct.

### 3.9.1. Shape and rank are different questions

- If there are more unknowns than equations, a **consistent** system must have free variables, but consistency is not guaranteed.
- If there are more equations than unknowns, a system can still be consistent and uniquely solvable; some equations may be redundant.
- Even a square system can be singular or inconsistent for a given right-hand side.

Counting equations alone never determines solvability: we must count *independent* constraints and check the augmented right-hand side.

---

## 3.10. Worked Examples: Unique, Infinite, and No Solutions

### Example 3.4. A uniquely solvable square system

Consider

$$
\begin{cases}
x_1+2x_2=5,\\
3x_1+4x_2=11.
\end{cases}
$$

The augmented matrix reduces as follows:

$$
\begin{aligned}
\left(\begin{array}{cc|c}1&2&5\\3&4&11\end{array}\right)
&\xrightarrow{R_2\leftarrow R_2-3R_1}
\left(\begin{array}{cc|c}1&2&5\\0&-2&-4\end{array}\right)\\[5pt]
&\xrightarrow{R_2\leftarrow-\frac12R_2}
\left(\begin{array}{cc|c}1&2&5\\0&1&2\end{array}\right)\\[5pt]
&\xrightarrow{R_1\leftarrow R_1-2R_2}
\left(\begin{array}{cc|c}1&0&1\\0&1&2\end{array}\right).
\end{aligned}
$$

Thus,

$$
\mathbf x=\begin{pmatrix}1\\2\end{pmatrix},
\qquad
\operatorname{rank}(A)=2,
\qquad
\operatorname{nullity}(A)=0.
$$

Every column is a pivot column and there is no free variable.

### Example 3.5. A consistent system with one free variable

Consider the system

$$
\begin{cases}
2x+z=3,\\
x-y-z=1,\\
3x-y=4.
\end{cases}
$$

Its augmented matrix is

$$
\left(\begin{array}{ccc|c}
2&0&1&3\\
1&-1&-1&1\\
3&-1&0&4
\end{array}\right).
$$

The third equation equals the sum of the first two, so it is redundant. A reduced row-echelon form is

$$
\left(\begin{array}{ccc|c}
1&0&\frac12&\frac32\\
0&1&\frac32&\frac12\\
0&0&0&0
\end{array}\right).
$$

The variable z is free. Taking z equal to an arbitrary parameter t,

$$
\begin{aligned}
x&=\frac32-\frac12t,\\
y&=\frac12-\frac32t,\\
z&=t.
\end{aligned}
$$

Therefore,

$$
\boxed{\mathbf x=
\begin{pmatrix}\frac32\\\frac12\\0\end{pmatrix}
+t\begin{pmatrix}-\frac12\\-\frac32\\1\end{pmatrix},
\qquad t\in\mathbb R.}
$$

The rank is 2 and the nullity is 1. The solution set is an affine line in three-dimensional space.

### Example 3.6. A system with no solution

Consider

$$
\begin{cases}
x+3y=1,\\
2x+y=-3,\\
2x+2y=0.
\end{cases}
$$

Apply elimination:

$$
\begin{aligned}
\left(\begin{array}{cc|c}
1&3&1\\2&1&-3\\2&2&0
\end{array}\right)
&\xrightarrow{\substack{R_2\leftarrow R_2-2R_1\\R_3\leftarrow R_3-2R_1}}
\left(\begin{array}{cc|c}
1&3&1\\0&-5&-5\\0&-4&-2
\end{array}\right)\\[5pt]
&\xrightarrow{R_3\leftarrow R_3-\frac45R_2}
\left(\begin{array}{cc|c}
1&3&1\\0&-5&-5\\0&0&2
\end{array}\right).
\end{aligned}
$$

The last row says that zero equals 2, which is impossible. In rank language,

$$
\operatorname{rank}(A)=2,
\qquad
\operatorname{rank}([A\mid\mathbf b])=3.
$$

Thus the system is inconsistent. Observe that having three equations and two unknowns is **not**, by itself, what makes the system inconsistent; the contradiction between the coefficients and the constants is decisive.

### Example 3.7. A system with two free variables

Take the system

$$
\begin{cases}
x+y+z-w=1,\\
y-z+w=-1,\\
3x+6z-6w=6,\\
-y+z-w=1.
\end{cases}
$$

The third equation equals three times the first minus three times the second; the fourth is the negative of the second. Thus the system has only two independent equations. Its reduced augmented matrix is

$$
\left(\begin{array}{cccc|c}
1&0&2&-2&2\\
0&1&-1&1&-1\\
0&0&0&0&0\\
0&0&0&0&0
\end{array}\right).
$$

Taking z and w as parameters,

$$
\begin{aligned}
x&=2-2z+2w,\\
y&=-1+z-w.
\end{aligned}
$$

The full solution set is

$$
\boxed{
\mathbf x=
\begin{pmatrix}2\\-1\\0\\0\end{pmatrix}
+z\begin{pmatrix}-2\\1\\1\\0\end{pmatrix}
+w\begin{pmatrix}2\\-1\\0\\1\end{pmatrix},
\qquad z,w\in\mathbb R.}
$$

We have

$$
\operatorname{rank}(A)=2,
\qquad
\operatorname{nullity}(A)=4-2=2.
$$

The solution set is an affine plane in four-dimensional space.

---

## 3.11. Homogeneous Systems and Nontrivial Solutions

A homogeneous system has the form

$$
A\mathbf x=0.
$$

It is always consistent because the zero vector is a solution. The question is therefore whether nonzero solutions exist.

**Theorem 3.8.** A homogeneous system has a nontrivial solution if and only if its nullity is positive:

$$
\boxed{\exists\,\mathbf x\ne0:A\mathbf x=0
\iff\operatorname{rank}(A)<n.}
$$

**Proof.** The null space contains a nonzero vector exactly when its dimension is positive. By rank–nullity, that is equivalent to the number of columns exceeding the rank. ∎

In particular, over any field, a homogeneous system with more unknowns than equations necessarily has a nonzero solution, since

$$
m<n
\quad\Longrightarrow\quad
\operatorname{rank}(A)\le m<n.
$$

**Example 3.8.** The matrix

$$
A=\begin{pmatrix}1&2\\2&4\end{pmatrix}
$$

has rank 1, so its nullity is 1. Its homogeneous solutions are

$$
\mathbf x=t\begin{pmatrix}-2\\1\end{pmatrix},
\qquad t\in\mathbb F.
$$

Over the real numbers, this gives infinitely many solutions, including the zero vector.

**Remark on finite fields.** Over a finite field with q elements, a k-dimensional null space contains exactly

$$
q^k
$$

vectors. Consequently a consistent system has exactly q to the power of its nullity solutions, rather than infinitely many. The familiar **no solution / one solution / infinitely many solutions** trichotomy is specifically the infinite-field version of the more general classification.

---

## 3.12. The Left Null Space and Compatibility Conditions

There is a second, dual way to detect whether the right-hand side is compatible with the matrix.

**Definition 3.10 (Left null space).** Over the real numbers, the left null space is

$$
\ker(A^T)=\{\mathbf y\in\mathbb R^m:A^T\mathbf y=0\}.
$$

If the system has a solution, then every left-null vector satisfies a necessary compatibility condition:

$$
\begin{aligned}
A\mathbf x&=\mathbf b,\\
\mathbf y^TA&=0
\quad\Longrightarrow\quad
\mathbf y^T\mathbf b
=\mathbf y^TA\mathbf x=0.
\end{aligned}
$$

**Theorem 3.9 (Orthogonality solvability criterion).** For a real matrix, the system is solvable if and only if the right-hand side is orthogonal to every vector in the left null space:

$$
\boxed{A\mathbf x=\mathbf b\ \text{is solvable}
\iff
\mathbf y^T\mathbf b=0
\text{ for every }\mathbf y\in\ker(A^T).}
$$

**Proof.** Necessity follows from the displayed calculation. For sufficiency, the fundamental orthogonality relation in finite-dimensional Euclidean space gives

$$
\operatorname{Col}(A)=\bigl(\ker(A^T)\bigr)^\perp.
$$

Thus orthogonality to the entire left null space places b in the column space of A, which is precisely the condition for solvability. ∎

This theorem clarifies why a contradiction can arise during elimination: a combination of the original equations can eliminate every unknown while leaving a nonzero right-hand side.

**Example 3.9.** Return to the inconsistent system of Example 3.6, with

$$
A=\begin{pmatrix}1&3\\2&1\\2&2\end{pmatrix},
\qquad
\mathbf b=\begin{pmatrix}1\\-3\\0\end{pmatrix}.
$$

The vector

$$
\mathbf y=\begin{pmatrix}-2\\-4\\5\end{pmatrix}
$$

belongs to the left null space, because

$$
A^T\mathbf y=0.
$$

But

$$
\mathbf y^T\mathbf b=-2+12=10\ne0.
$$

Therefore b cannot belong to the column space. This provides an independent proof of inconsistency without completing the augmented row reduction.

For complex matrices, the analogous orthogonality criterion uses the **conjugate transpose** and the Hermitian inner product. Over an arbitrary field, one may formulate the compatibility condition using the algebraic dual rather than an inner product.

---

## 3.13. Further Properties of Rank

Rank is also constrained by the basic algebraic operations introduced earlier.

**Proposition 3.3 (Standard rank properties).** Whenever the expressions are defined,

$$
\begin{aligned}
\operatorname{rank}(A^T)&=\operatorname{rank}(A),\\
\operatorname{rank}(\lambda A)&=\operatorname{rank}(A)
\qquad (\lambda\ne0),\\
\operatorname{rank}(A+B)&\le\operatorname{rank}(A)+\operatorname{rank}(B),\\
\operatorname{rank}(AB)&\le\min\{\operatorname{rank}(A),\operatorname{rank}(B)\}.
\end{aligned}
$$

For the zero scalar,

$$
\operatorname{rank}(0A)=0.
$$

If P and Q are invertible matrices of compatible sizes, then

$$
\boxed{\operatorname{rank}(PAQ)=\operatorname{rank}(A).}
$$

**Proof of the product inequality.** The image of AB is contained in the image of A:

$$
\operatorname{Im}(AB)
=A\bigl(\operatorname{Im}(B)\bigr)
\subseteq\operatorname{Im}(A).
$$

Therefore its dimension cannot exceed the rank of A. Moreover, restricting the linear map A to the image of B cannot create more independent output directions than the dimension of that image. Hence the rank of AB also cannot exceed the rank of B. Combining these inequalities yields the claim. ∎

**Proof of the sum inequality.** Every output of A+B is a sum of one vector in the image of A and one vector in the image of B. Consequently,

$$
\operatorname{Im}(A+B)
\subseteq\operatorname{Im}(A)+\operatorname{Im}(B).
$$

Taking dimensions gives

$$
\operatorname{rank}(A+B)
\le\operatorname{rank}(A)+\operatorname{rank}(B).
$$

∎

**Remark.** The rank of a product need not equal the product of the ranks, nor the smaller of the two ranks. A nonzero matrix product can lose rank, and two nonzero matrices can even multiply to zero. Invertible factors, by contrast, do not change rank.

---

## 3.14. Four Fundamental Subspaces and the Dimension Identities

For a real m-by-n matrix, four naturally associated subspaces are:

| Subspace | Ambient space | Dimension |
|---|---|---|
| Column space | Output space | Rank of A |
| Row space | Input space | Rank of A |
| Null space | Input space | n − rank of A |
| Left null space | Output space | m − rank of A |

The two rank–nullity identities are

$$
\boxed{\operatorname{rank}(A)+\dim\ker(A)=n,}
$$

and, after applying the same theorem to the transpose,

$$
\boxed{\operatorname{rank}(A)+\dim\ker(A^T)=m.}
$$

In Euclidean coordinates, these subspaces satisfy the orthogonality relations

$$
\begin{aligned}
\operatorname{Row}(A)&=\bigl(\ker(A)\bigr)^\perp,\\
\operatorname{Col}(A)&=\bigl(\ker(A^T)\bigr)^\perp.
\end{aligned}
$$

The rank is therefore not merely a count of pivots. It is the common dimension of the row and column spaces, and it controls how the input and output spaces are divided into effective directions and annihilated directions.

---

## 3.15. Practical Algorithm for Solvability and Parameterisation

Given an m-by-n linear system, the following procedure combines the computational and theoretical viewpoints.

1. **Form the augmented matrix.** Write the coefficient matrix together with the target vector.
2. **Reduce by elementary row operations.** Bring the augmented matrix to row-echelon form, continuing to reduced row-echelon form if convenient.
3. **Count the coefficient pivots.** Their number is the rank of A.
4. **Inspect the augmented column.** If a row has all zero coefficients but a nonzero target entry, the system is inconsistent.
5. **If consistent, identify the free variables.** Their number is the nullity, equal to n minus the rank.
6. **Construct a particular solution.** For instance, set all free variables to zero and back-substitute.
7. **Solve the homogeneous system.** Turn on each free variable separately to construct a basis of the kernel.
8. **State the complete solution set.** Add the unrestricted linear combination of kernel-basis vectors to the particular solution.

The result is not just a numerical answer but a complete description of all possible solutions.

### The main implications at a glance

$$
\boxed{
\begin{gathered}
\operatorname{rank}(A)=r,
\qquad
\operatorname{nullity}(A)=n-r,\\[5pt]
A\mathbf x=\mathbf b\text{ is solvable}
\iff\operatorname{rank}(A)=\operatorname{rank}([A\mid\mathbf b]),\\[5pt]
\text{If solvable:}\quad
\mathbf x=\mathbf x_p+\mathbf z,
\quad \mathbf z\in\ker(A).
\end{gathered}
}
$$

---

## 3.16. Concluding Perspective

We began with systems of equations, for which Gaussian elimination provides a mechanical solution method, and arrived at a structural description of linear transformations. A matrix over a field carries two related algebraic structures: a vector-space structure under addition and scalar multiplication, and—when square—an associative multiplication that represents composition but is generally noncommutative. Within these structures, **rank** measures the independent output directions and **nullity** measures the freedom remaining in the input.

The rank–nullity theorem links these quantities, while the augmented-rank criterion determines whether a proposed right-hand side can be attained. Once solvability is established, every solution is obtained by adding an arbitrary homogeneous solution to any particular one. These principles provide the foundation for later discussions of invertibility, determinants, bases, dimension, orthogonality, and numerical linear algebra.


- [Exercises]({{ '/pages/mathematics/linear_algebra/03-matrices-and-linear-systems/03-matrix-rank-nullity-and-solvability/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/03-matrices-and-linear-systems/03-matrix-rank-nullity-and-solvability/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/03-matrices-and-linear-systems/03-matrix-rank-nullity-and-solvability/references/' | relative_url }})

[Back to Matrices and Linear Systems]({{ '/pages/mathematics/linear_algebra/03-matrices-and-linear-systems/' | relative_url }})

</article>
