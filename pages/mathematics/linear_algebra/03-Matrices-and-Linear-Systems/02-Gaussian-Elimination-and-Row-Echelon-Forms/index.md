---
layout: default
title: "3.2: Gaussian Elimination and Row Echelon Forms"
permalink: /pages/mathematics/linear_algebra/03-matrices-and-linear-systems/02-gaussian-elimination-and-row-echelon-forms/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/linear_algebra/03-matrices-and-linear-systems/02-gaussian-elimination-and-row-echelon-forms/' | relative_url }}">← Gaussian Elimination and Row Echelon Forms</a>
  <div class="eyebrow">Mathematics / Linear Algebra / 3.2</div>
  <h1>Gaussian Elimination and Row Echelon Forms</h1>
</div>

<article class="article" markdown="1">

# 02 — Gaussian Elimination and Row-Echelon Forms

Solving a system of linear equations is one of the fundamental tasks of linear algebra. Such systems arise whenever several quantities are connected by linear constraints, whether in geometry, mechanics, numerical analysis, optimisation, or mathematical modelling. The central difficulty is not usually to verify a proposed solution, but to determine **all** solutions systematically—and to recognise when no solution exists.

**Gaussian elimination** provides an algorithm for doing precisely this. By performing a small collection of reversible operations, we replace the original system with an equivalent one whose structure is easier to understand. The resulting *row-echelon form* makes back-substitution possible; a further reduction, known as **Gauss–Jordan elimination**, produces *reduced row-echelon form* and reveals the leading and free variables directly.

This chapter develops the method from the underlying equations, proves that elementary operations preserve the solution set, and then uses augmented matrices to study systems with a unique solution, infinitely many solutions, or no solution.

---

## 2.1. Systems of Linear Equations

**Definition 2.1 (Linear equation).** A linear equation in the unknowns indexed from 1 to n is an equation of the form

$$
a_1x_1+a_2x_2+\cdots+a_nx_n=b,
$$

where the coefficients and the constant term are real numbers. A **linear combination** of the unknowns is an expression of the form

$$
a_1x_1+a_2x_2+\cdots+a_nx_n.
$$

The unknowns appear only to the first power: products between unknowns, powers greater than one, and nonlinear functions of the unknowns are not permitted.

Consider a system of m linear equations in n unknowns:

$$
\begin{cases}
a_{11}x_1+a_{12}x_2+\cdots+a_{1n}x_n=b_1,\\
a_{21}x_1+a_{22}x_2+\cdots+a_{2n}x_n=b_2,\\
\qquad\vdots\\
a_{m1}x_1+a_{m2}x_2+\cdots+a_{mn}x_n=b_m.
\end{cases}
\tag{2.1}
$$

Its unknowns can be collected into the column vector

$$
\mathbf{x}=\begin{pmatrix}x_1\\x_2\\\vdots\\x_n\end{pmatrix}\in\mathbb{R}^n.
$$

**Definition 2.2 (Solution and solution set).** A vector

$$
\mathbf{c}=\begin{pmatrix}c_1\\c_2\\\vdots\\c_n\end{pmatrix}\in\mathbb{R}^n
$$

is a **solution** of (2.1) if substituting each component for the corresponding unknown satisfies **every** equation. Equivalently,

$$
\sum_{j=1}^{n}a_{ij}c_j=b_i,
\qquad i=1,\ldots,m.
$$

The **solution set** consists of all such vectors. Two systems are **equivalent** if they have exactly the same solution set.

There are three possible outcomes: a system has **one solution**, **infinitely many solutions**, or **no solution**. The purpose of elimination is to determine which possibility occurs and, in the consistent cases, describe the solutions explicitly.

### Matrix formulation

Write the coefficient matrix, unknown vector, and right-hand side as

$$
A=\begin{pmatrix}
a_{11}&a_{12}&\cdots&a_{1n}\\
a_{21}&a_{22}&\cdots&a_{2n}\\
\vdots&\vdots&\ddots&\vdots\\
a_{m1}&a_{m2}&\cdots&a_{mn}
\end{pmatrix},\qquad
\mathbf{x}=\begin{pmatrix}x_1\\\vdots\\x_n\end{pmatrix},\qquad
\mathbf{b}=\begin{pmatrix}b_1\\\vdots\\b_m\end{pmatrix}.
$$

The entire system is then represented by

$$
\boxed{A\mathbf{x}=\mathbf{b}}.
\tag{2.2}
$$

The matrix A has m rows and n columns. There is no requirement that the number of equations equal the number of unknowns.

## 2.2. Augmented Matrices

The unknowns need not be copied at every stage of a calculation. All information required for elimination is contained in the **augmented matrix** (also called a Gaussian array):

$$
[A\mid\mathbf{b}]
=\left[\begin{array}{cccc|c}
a_{11}&a_{12}&\cdots&a_{1n}&b_1\\
a_{21}&a_{22}&\cdots&a_{2n}&b_2\\
\vdots&\vdots&\ddots&\vdots&\vdots\\
a_{m1}&a_{m2}&\cdots&a_{mn}&b_m
\end{array}\right].
\tag{2.3}
$$

The vertical separator distinguishes the coefficients from the constants. Each matrix row represents one equation, and each of the first n columns corresponds to one unknown.

For instance, the system

$$
\begin{cases}
x_1+2x_2=4,\\
x_2-x_3=0,\\
x_1+2x_3=4
\end{cases}
$$

has augmented matrix

$$
\left[\begin{array}{ccc|c}
1&2&0&4\\
0&1&-1&0\\
1&0&2&4
\end{array}\right].
$$

The entries are manipulated row by row, with exactly the same operations that would have been applied to the original equations.

## 2.3. Elementary Row Operations

There are three operations from which Gaussian elimination is constructed.

**Definition 2.3 (Elementary row operations).** If the rows of an augmented matrix are labelled as below, the permitted operations are:

1. **Non-zero row scaling (E1):** multiply every entry of a row by a non-zero scalar.

   $$
   R_i\longleftarrow\lambda R_i,
   \qquad \lambda\in\mathbb{R}\setminus\{0\}.
   $$

2. **Row interchange (E2):** exchange any two distinct rows.

   $$
   R_i\longleftrightarrow R_j.
   $$

3. **Row replacement (E3):** replace one row by itself plus a multiple of a different row.

   $$
   R_j\longleftarrow R_j+\lambda R_i,
   \qquad i\neq j,\quad\lambda\in\mathbb{R}.
   $$

The same operation must be applied to **every entry of the affected row, including its right-hand-side constant**. In particular, multiplying a row by zero is not permitted.

### Theorem 2.4 (Elementary operations preserve solutions)

Any system obtained from another by a finite sequence of elementary row operations has exactly the same solution set.

**Proof.** It suffices to consider one operation at a time.

**(i) Row interchange.** Exchanging two equations changes only their order. A vector satisfies all the original equations if and only if it satisfies the reordered equations.

**(ii) Non-zero row scaling.** Consider one equation and multiply both sides by a scalar different from zero:

$$
\sum_{k=1}^{n}a_{ik}x_k=b_i
\quad\Longleftrightarrow\quad
\lambda\sum_{k=1}^{n}a_{ik}x_k=\lambda b_i.
$$

The implication holds in both directions, because division by the non-zero scalar recovers the original equation.

**(iii) Row replacement.** Suppose the system contains two equations

$$
\sum_{k=1}^{n}a_{ik}x_k=b_i,
\qquad
\sum_{k=1}^{n}a_{jk}x_k=b_j.
$$

Replace the second by itself plus a multiple of the first:

$$
\sum_{k=1}^{n}(a_{jk}+\lambda a_{ik})x_k=b_j+\lambda b_i.
$$

Every solution of the original pair satisfies this new equation. Conversely, if the first equation and the new equation hold, subtracting the first equation multiplied by the same scalar recovers the original second equation:

$$
\begin{aligned}
&\sum_{k=1}^{n}(a_{jk}+\lambda a_{ik})x_k
-\lambda\sum_{k=1}^{n}a_{ik}x_k\\
&\qquad=(b_j+\lambda b_i)-\lambda b_i
\quad\Longrightarrow\quad
\sum_{k=1}^{n}a_{jk}x_k=b_j.
\end{aligned}
$$

Thus the operations are reversible and preserve all solutions. Applying them successively preserves the solution set at every stage.  □

The inverse operations are explicit:

$$
\begin{aligned}
R_i\leftrightarrow R_j&\quad\text{is its own inverse},\\
R_i\leftarrow\lambda R_i&\quad\text{is undone by }R_i\leftarrow\lambda^{-1}R_i,\\
R_j\leftarrow R_j+\lambda R_i&\quad\text{is undone by }R_j\leftarrow R_j-\lambda R_i.
\end{aligned}
$$

This is the reason Gaussian elimination is a reliable algorithm rather than a collection of algebraic guesses.

## 2.4. Gaussian Elimination: A Worked Example

Consider

$$
\begin{cases}
2x_1+3x_2+3x_3=5,\\
x_1-x_2-3x_3=-4,\\
3x_1+x_2-x_3=0.
\end{cases}
\tag{2.4}
$$

We first solve the system using the equations themselves, before repeating the procedure with an augmented matrix.

### Step 1: Select a first pivot

The second equation already has coefficient 1 in front of the first unknown. Interchanging the first two rows gives

$$
\begin{cases}
x_1-x_2-3x_3=-4,\\
2x_1+3x_2+3x_3=5,\\
3x_1+x_2-x_3=0.
\end{cases}
$$

### Step 2: Eliminate the first unknown below the pivot

Subtract twice the first equation from the second, and three times the first equation from the third:

$$
\begin{cases}
x_1-x_2-3x_3=-4,\\
5x_2+9x_3=13,\\
4x_2+8x_3=12.
\end{cases}
$$

The first column now contains zeros below the leading coefficient.

### Step 3: Select the second pivot

Divide the third row by 4 and interchange the second and third rows:

$$
\begin{cases}
x_1-x_2-3x_3=-4,\\
x_2+2x_3=3,\\
5x_2+9x_3=13.
\end{cases}
$$

Subtract five times the second equation from the third:

$$
\begin{cases}
x_1-x_2-3x_3=-4,\\
x_2+2x_3=3,\\
-x_3=-2.
\end{cases}
$$

We have reached a **triangular system**: the lowest equation contains just one unknown, the middle equation contains two, and the top equation contains all three.

### Step 4: Back-substitution

The bottom equation gives

$$
x_3=2.
$$

Using the middle equation,

$$
x_2=3-2x_3=3-4=-1.
$$

Finally,

$$
x_1=-4+x_2+3x_3=-4-1+6=1.
$$

Hence

$$
\boxed{\mathbf{x}=\begin{pmatrix}1\\-1\\2\end{pmatrix}}.
\tag{2.5}
$$

**Verification.** Substitution into the original equations yields

$$
\begin{aligned}
2(1)+3(-1)+3(2)&=5,\\
1-(-1)-3(2)&=-4,\\
3(1)+(-1)-2&=0.
\end{aligned}
$$

Every equation is satisfied.

### The same calculation using an augmented matrix

Each step can be written more compactly by suppressing the variables:

$$
\left[\begin{array}{ccc|c}
2&3&3&5\\
1&-1&-3&-4\\
3&1&-1&0
\end{array}\right]
\xrightarrow{R_1\leftrightarrow R_2}
\left[\begin{array}{ccc|c}
1&-1&-3&-4\\
2&3&3&5\\
3&1&-1&0
\end{array}\right].
$$

Next, eliminate the entries beneath the first pivot:

$$
\left[\begin{array}{ccc|c}
1&-1&-3&-4\\
2&3&3&5\\
3&1&-1&0
\end{array}\right]
\xrightarrow[\,R_3\leftarrow R_3-3R_1\,]{\,R_2\leftarrow R_2-2R_1\,}
\left[\begin{array}{ccc|c}
1&-1&-3&-4\\
0&5&9&13\\
0&4&8&12
\end{array}\right].
$$

Normalize and move the next pivot into position:

$$
\left[\begin{array}{ccc|c}
1&-1&-3&-4\\
0&5&9&13\\
0&4&8&12
\end{array}\right]
\xrightarrow{R_3\leftarrow\frac14R_3}
\left[\begin{array}{ccc|c}
1&-1&-3&-4\\
0&5&9&13\\
0&1&2&3
\end{array}\right].
$$

Now interchange the second and third rows:

$$
\left[\begin{array}{ccc|c}
1&-1&-3&-4\\
0&5&9&13\\
0&1&2&3
\end{array}\right]
\xrightarrow{R_2\leftrightarrow R_3}
\left[\begin{array}{ccc|c}
1&-1&-3&-4\\
0&1&2&3\\
0&5&9&13
\end{array}\right].
$$

Eliminate the remaining entry below the second pivot:

$$
\left[\begin{array}{ccc|c}
1&-1&-3&-4\\
0&1&2&3\\
0&5&9&13
\end{array}\right]
\xrightarrow{R_3\leftarrow R_3-5R_2}
\left[\begin{array}{ccc|c}
1&-1&-3&-4\\
0&1&2&3\\
0&0&-1&-2
\end{array}\right].
$$

Multiplying the last row by minus one gives

$$
\boxed{
\left[\begin{array}{ccc|c}
1&-1&-3&-4\\
0&1&2&3\\
0&0&1&2
\end{array}\right]
}.
\tag{2.6}
$$

This is a **row-echelon form** of the augmented matrix. The staircase pattern of its first non-zero entries is what makes back-substitution straightforward.

## 2.5. Row-Echelon Form

**Definition 2.5 (Leading entry and pivot).** The *leading entry* of a non-zero row is its first non-zero entry, read from left to right. The location of a leading entry is a **pivot position**, and a column containing a pivot is a **pivot column**.

**Definition 2.6 (Row-echelon form).** A matrix is in **row-echelon form (REF)** if:

1. Every row consisting entirely of zeros lies below all non-zero rows.
2. The leading entry in each non-zero row is strictly to the right of the leading entry in the row above it.
3. Every entry below a leading entry is zero.

In this chapter we follow the **normalised echelon convention**, whereby each leading entry is also scaled to 1. Some texts use *row-echelon form* without requiring this normalisation; both conventions describe the same staircase structure and support back-substitution.

A typical normalised echelon pattern is

$$
\left[\begin{array}{ccccc}
\boxed{1}&*&*&*&*\\
0&0&\boxed{1}&*&*\\
0&0&0&\boxed{1}&*\\
0&0&0&0&0
\end{array}\right].
$$

Here the boxes indicate leading ones and each asterisk represents an arbitrary entry. In particular, pivot columns need **not** be consecutive, and a matrix may have zero rows.

For example,

$$
\left[\begin{array}{ccccc}
1&2&1&3&2\\
0&1&4&-1&3\\
0&0&1&2&4\\
0&0&0&1&-5
\end{array}\right]
$$

is in REF, while

$$
\left[\begin{array}{cccc}
1&-1&0&2\\
0&0&1&4\\
0&0&0&0
\end{array}\right]
$$

is also in REF: the second pivot occurs in the third column, not the second.

An REF is **not generally unique**. Different choices of pivots and row operations may yield different echelon matrices, although all resulting systems remain equivalent.

### Back-substitution in echelon form

A system in REF can be solved from the bottom non-zero row upwards. First solve for its leading variable, regarding all non-leading variables as freely chosen. Substitute this expression into the preceding row and continue until every leading variable has been determined.

Gaussian elimination is therefore the combination of **forward elimination** (constructing REF) and **back-substitution** (extracting the solutions).

## 2.6. Gaussian Elimination in General

For an arbitrary augmented matrix

$$
\left[\begin{array}{cccc|c}
a_{11}&a_{12}&\cdots&a_{1n}&b_1\\
a_{21}&a_{22}&\cdots&a_{2n}&b_2\\
\vdots&\vdots&\ddots&\vdots&\vdots\\
a_{m1}&a_{m2}&\cdots&a_{mn}&b_m
\end{array}\right],
$$

proceed recursively across the **coefficient columns**.

1. **Find a pivot column.** Starting at the current column and restricting attention to unprocessed rows, select the first column with a non-zero entry. If a column has only zeros in those rows, skip it.
2. **Move a pivot into place.** Swap the current row with a lower row having a non-zero entry in the selected column.
3. **Normalise the pivot, if desired.** Divide the pivot row by its leading coefficient so that the pivot is 1.
4. **Clear below the pivot.** Add appropriate multiples of the pivot row to all rows beneath it.
5. **Advance right and down.** Repeat on the remaining rows and columns until there are no further pivots in the coefficient part.
6. **Interpret the resulting system.** Detect contradictions, identify the leading variables, and solve by back-substitution when the system is consistent.

To see the central elimination step in general, suppose the first available pivot has been scaled to 1:

$$
\left[\begin{array}{cccc|c}
1&a_{12}&\cdots&a_{1n}&b_1\\
a_{21}&a_{22}&\cdots&a_{2n}&b_2\\
\vdots&\vdots&\ddots&\vdots&\vdots\\
a_{m1}&a_{m2}&\cdots&a_{mn}&b_m
\end{array}\right].
$$

Using the row replacements

$$
R_i\longleftarrow R_i-a_{i1}R_1,
\qquad i=2,\ldots,m,
$$

we obtain

$$
\left[\begin{array}{cccc|c}
1&a_{12}&\cdots&a_{1n}&b_1\\
0&\widetilde a_{22}&\cdots&\widetilde a_{2n}&\widetilde b_2\\
\vdots&\vdots&\ddots&\vdots&\vdots\\
0&\widetilde a_{m2}&\cdots&\widetilde a_{mn}&\widetilde b_m
\end{array}\right].
$$

The same idea now applies to the lower-right block. If its first coefficient column consists entirely of zeros, we move farther to the right to find the next non-zero column. Every new pivot lies strictly below and to the right of the previous one, so this procedure terminates after finitely many steps.

**Important.** A non-zero entry in the augmented *right-hand side* cannot be used as a coefficient pivot to solve for a variable. If all coefficient entries in a row vanish but its constant does not, the row represents a contradiction, as we shall see below.

## 2.7. Gauss–Jordan Elimination and Reduced Row-Echelon Form

Gaussian elimination is sufficient to solve a linear system: once REF has been reached, back-substitution completes the task. Gauss–Jordan elimination continues the row operations until the solutions can be read directly.

**Definition 2.7 (Reduced row-echelon form).** A matrix is in **reduced row-echelon form (RREF)** if:

1. It is in normalised row-echelon form.
2. Each pivot is the only non-zero entry in its column; in particular, all entries **above** every leading 1 vanish.

Thus a pivot column in RREF consists of zeros everywhere except for a single 1.

Return to the REF from (2.6):

$$
\left[\begin{array}{ccc|c}
1&-1&-3&-4\\
0&1&2&3\\
0&0&1&2
\end{array}\right].
$$

First clear the entries above the last pivot:

$$
\left[\begin{array}{ccc|c}
1&-1&-3&-4\\
0&1&2&3\\
0&0&1&2
\end{array}\right]
\xrightarrow[\,R_1\leftarrow R_1+3R_3\,]{\,R_2\leftarrow R_2-2R_3\,}
\left[\begin{array}{ccc|c}
1&-1&0&2\\
0&1&0&-1\\
0&0&1&2
\end{array}\right].
$$

Then clear the entry above the pivot in the second column:

$$
\left[\begin{array}{ccc|c}
1&-1&0&2\\
0&1&0&-1\\
0&0&1&2
\end{array}\right]
\xrightarrow{R_1\leftarrow R_1+R_2}
\boxed{
\left[\begin{array}{ccc|c}
1&0&0&1\\
0&1&0&-1\\
0&0&1&2
\end{array}\right]
}.
\tag{2.7}
$$

The coefficient part is the identity matrix, so the solution is immediately visible:

$$
x_1=1,\qquad x_2=-1,\qquad x_3=2.
$$

For any given matrix, **the RREF is unique**, even though the sequence of operations used to obtain it need not be.

### A further example of reduction

Consider the echelon matrix

$$
\left[\begin{array}{ccccc}
1&2&1&3&2\\
0&1&4&-1&3\\
0&0&1&2&4\\
0&0&0&1&-5
\end{array}\right].
$$

We eliminate entries **above** the fourth pivot, then the third, and then the second. The result is

$$
\boxed{
\left[\begin{array}{ccccc}
1&0&0&0&119\\
0&1&0&0&-58\\
0&0&1&0&14\\
0&0&0&1&-5
\end{array}\right]
}.
$$

Interpreted as an augmented matrix for four unknowns, the first four columns represent the coefficients and the last represents the constants. The resulting unique solution is therefore

$$
\boxed{(x_1,x_2,x_3,x_4)=(119,-58,14,-5)}.
$$

As always, the meaning of the columns must be fixed before interpreting the reduced matrix.

## 2.8. Leading Variables and Free Variables

**Definition 2.8 (Leading and free variables).** In the echelon form of an augmented system, a **leading variable** corresponds to a pivot column of the coefficient matrix. Every other unknown is a **free variable**.

A free variable may be assigned an arbitrary real value. The equations then determine the leading variables, provided no contradictory row is present.

The distinction becomes particularly important when the number of pivots is smaller than the number of unknowns. Such a consistent system has infinitely many solutions, which are conveniently described by introducing parameters.

### Example: one free variable

Consider

$$
\begin{cases}
x_1+x_2+2x_3=9,\\
2x_1+4x_2-3x_3=1,\\
4x_1+6x_2+x_3=19.
\end{cases}
$$

Starting from the augmented matrix, eliminate the first unknown below its pivot:

$$
\left[\begin{array}{ccc|c}
1&1&2&9\\
2&4&-3&1\\
4&6&1&19
\end{array}\right]
\xrightarrow[\,R_3\leftarrow R_3-4R_1\,]{\,R_2\leftarrow R_2-2R_1\,}
\left[\begin{array}{ccc|c}
1&1&2&9\\
0&2&-7&-17\\
0&2&-7&-17
\end{array}\right].
$$

Subtract the second row from the third and scale the second row:

$$
\xrightarrow[\,R_2\leftarrow\frac12R_2\,]{\,R_3\leftarrow R_3-R_2\,}
\left[\begin{array}{ccc|c}
1&1&2&9\\
0&1&-\frac72&-\frac{17}{2}\\
0&0&0&0
\end{array}\right].
$$

Subtract the second row from the first to obtain RREF:

$$
\boxed{
\left[\begin{array}{ccc|c}
1&0&\frac{11}{2}&\frac{35}{2}\\
0&1&-\frac72&-\frac{17}{2}\\
0&0&0&0
\end{array}\right]
}.
$$

There are pivots in the first and second coefficient columns, but not in the third. Hence the third unknown is free. Put

$$
x_3=t,\qquad t\in\mathbb{R}.
$$

The two remaining equations become

$$
\begin{aligned}
x_1&=\frac{35}{2}-\frac{11}{2}t,\\
x_2&=-\frac{17}{2}+\frac72t.
\end{aligned}
$$

Thus every solution has the form

$$
\boxed{
\mathbf{x}=\begin{pmatrix}\frac{35}{2}\\-\frac{17}{2}\\0\end{pmatrix}
+t\begin{pmatrix}-\frac{11}{2}\\\frac72\\1\end{pmatrix},
\qquad t\in\mathbb{R}
}.
\tag{2.8}
$$

The zero row represents the identity

$$
0=0,
$$

which imposes no additional restriction. Its presence does **not**, by itself, imply infinitely many solutions: infinitely many solutions arise here because the system is consistent **and** has a free variable.

### Example: two free variables

Consider the system

$$
\begin{cases}
x+y+z-w=1,\\
y-z+w=-1,\\
3x+6z-6w=6,\\
-y+z-w=1.
\end{cases}
$$

Elimination gives

$$
\left[\begin{array}{cccc|c}
1&1&1&-1&1\\
0&1&-1&1&-1\\
3&0&6&-6&6\\
0&-1&1&-1&1
\end{array}\right]
\xrightarrow[\,R_4\leftarrow R_4+R_2\,]{\,R_3\leftarrow R_3-3R_1\,}
\left[\begin{array}{cccc|c}
1&1&1&-1&1\\
0&1&-1&1&-1\\
0&-3&3&-3&3\\
0&0&0&0&0
\end{array}\right].
$$

After adding three times the second row to the third, we have two non-zero equations. Let

$$
z=s,\qquad w=t,\qquad s,t\in\mathbb{R}.
$$

The second equation gives

$$
y=-1+s-t,
$$

and substituting into the first yields

$$
x=2-2s+2t.
$$

The solution set is therefore

$$
\boxed{
\mathbf{x}=\begin{pmatrix}2\\-1\\0\\0\end{pmatrix}
+s\begin{pmatrix}-2\\1\\1\\0\end{pmatrix}
+t\begin{pmatrix}2\\-1\\0\\1\end{pmatrix},
\qquad s,t\in\mathbb{R}
}.
\tag{2.9}
$$

This representation separates one particular solution from the independent directions in which the free variables can vary.

### Pivot columns may skip variables

Suppose a system reduces to

$$
\left[\begin{array}{cccc|c}
1&-1&0&0&0\\
0&0&1&3&2\\
0&0&0&0&0
\end{array}\right].
$$

Its leading variables are the **first and third** unknowns, whereas the second and fourth are free. Writing the free variables as parameters gives

$$
\mathbf{x}=\begin{pmatrix}s\\s\\2-3t\\t\end{pmatrix},
\qquad s,t\in\mathbb{R}.
$$

Leading variables are identified by **pivot positions**, not by the numerical order of the equations or by assuming the first several unknowns must be leading.

## 2.9. Unique, Infinite, and Empty Solution Sets

Gaussian elimination provides a complete classification of linear systems.

### Case I: A unique solution

If the system is consistent and **every coefficient column contains a pivot**, there are no free variables. The solution is uniquely determined.

For example,

$$
\left[\begin{array}{ccc|c}
1&0&0&1\\
0&1&0&-1\\
0&0&1&2
\end{array}\right]
$$

has the unique solution found in (2.5).

### Case II: Infinitely many solutions

If the system is consistent and **at least one coefficient column lacks a pivot**, there is at least one free variable. Because the free variable ranges over the real numbers, there are infinitely many solutions.

An identity row such as

$$
\left[\begin{array}{ccc|c}0&0&0&0\end{array}\right]
$$

merely expresses a redundant condition; it is the existence of free variables, not the zero row alone, that guarantees infinitely many solutions.

### Case III: No solution

If elimination produces a row of the form

$$
\left[\begin{array}{cccc|c}0&0&\cdots&0&c\end{array}\right],
\qquad c\neq0,
$$

then the corresponding equation is

$$
0=c,
$$

which is impossible. The system is **inconsistent**, and its solution set is empty.

**Example (inconsistent system).** Consider

$$
\begin{cases}
x_1+x_2+x_3=4,\\
x_2-x_3=3,\\
x_1+2x_3=2.
\end{cases}
$$

The augmented matrix reduces as follows:

$$
\left[\begin{array}{ccc|c}
1&1&1&4\\
0&1&-1&3\\
1&0&2&2
\end{array}\right]
\xrightarrow{R_3\leftarrow R_3-R_1}
\left[\begin{array}{ccc|c}
1&1&1&4\\
0&1&-1&3\\
0&-1&1&-2
\end{array}\right]
\xrightarrow{R_3\leftarrow R_3+R_2}
\left[\begin{array}{ccc|c}
1&1&1&4\\
0&1&-1&3\\
0&0&0&1
\end{array}\right].
$$

The bottom row reads

$$
0=1.
$$

Consequently,

$$
\boxed{\mathcal{S}=\varnothing}.
$$

No choice of the unknowns can satisfy all three original equations.

## 2.10. Homogeneous Systems

**Definition 2.9 (Homogeneous system).** A linear system is **homogeneous** when every constant term is zero:

$$
A\mathbf{x}=\mathbf{0}.
\tag{2.10}
$$

Every homogeneous system possesses the **trivial solution**

$$
\mathbf{x}=\mathbf{0}.
$$

Hence a homogeneous system is always consistent. It has either precisely the trivial solution or infinitely many solutions, depending on whether free variables occur.

### Example

Consider

$$
\begin{cases}
x_1+2x_2+3x_3=0,\\
x_1+4x_2+x_3=0.
\end{cases}
$$

The augmented matrix is

$$
\left[\begin{array}{ccc|c}
1&2&3&0\\
1&4&1&0
\end{array}\right]
\xrightarrow{R_2\leftarrow R_2-R_1}
\left[\begin{array}{ccc|c}
1&2&3&0\\
0&2&-2&0
\end{array}\right].
$$

Scale the second row and clear the entry above its pivot:

$$
\left[\begin{array}{ccc|c}
1&2&3&0\\
0&2&-2&0
\end{array}\right]
\xrightarrow{R_2\leftarrow\frac12R_2}
\left[\begin{array}{ccc|c}
1&2&3&0\\
0&1&-1&0
\end{array}\right]
\xrightarrow{R_1\leftarrow R_1-2R_2}
\left[\begin{array}{ccc|c}
1&0&5&0\\
0&1&-1&0
\end{array}\right].
$$

The first two variables are leading and the third is free. Taking

$$
x_3=t
$$

produces

$$
\boxed{
\mathbf{x}=t\begin{pmatrix}-5\\1\\1\end{pmatrix},
\qquad t\in\mathbb{R}
}.
$$

Setting the parameter to zero recovers the trivial solution; every non-zero parameter yields a non-trivial solution.

## 2.11. General Solution = Particular Solution + Homogeneous Solution

The parameterisations above are instances of a general principle.

### Theorem 2.10 (Structure of a consistent system)

Suppose

$$
A\mathbf{x}=\mathbf{b}
$$

is consistent, and let one particular solution be denoted by

$$
A\mathbf{x}_p=\mathbf{b}.
$$

Then the complete solution set is

$$
\boxed{
\mathcal{S}=\{\mathbf{x}_p+\mathbf{h}:A\mathbf{h}=\mathbf{0}\}
=\mathbf{x}_p+\ker(A)
}.
\tag{2.11}
$$

In particular, if elimination leaves k free variables, there are vectors satisfying the associated homogeneous system such that every solution can be written

$$
\boxed{
\mathbf{x}=\mathbf{x}_p+t_1\mathbf{v}_1+\cdots+t_k\mathbf{v}_k,
\qquad t_1,\ldots,t_k\in\mathbb{R}
}.
\tag{2.12}
$$

Here the free-variable parameterisation provides k linearly independent direction vectors; if there are no free variables, the sum of direction vectors is absent.

**Proof.** Let the given vector be a particular solution, and suppose another vector is also a solution. Then

$$
A(\mathbf{x}-\mathbf{x}_p)
=A\mathbf{x}-A\mathbf{x}_p
=\mathbf{b}-\mathbf{b}=\mathbf{0}.
$$

Thus the difference is a solution of the associated homogeneous system. Conversely, if a vector satisfies the homogeneous system, then

$$
A(\mathbf{x}_p+\mathbf{h})
=A\mathbf{x}_p+A\mathbf{h}
=\mathbf{b}+\mathbf{0}=\mathbf{b}.
$$

This proves the first identity. The second follows from expressing the leading variables in terms of the free variables after elimination and collecting the constant terms and the coefficient of each parameter into column vectors.  □

The solution set of a homogeneous system passes through the zero vector. The solution set of a consistent non-homogeneous system is a **translation** of its associated homogeneous solution set by any particular solution.

## 2.12. A Practical Elimination Checklist

The complete method can now be summarised in a sequence of decisions.

1. **Form the augmented matrix:** write the coefficient matrix and append the constant column.
2. **Eliminate forward:** use row interchange, non-zero scaling, and row replacement to obtain row-echelon form.
3. **Check consistency:** any row having all zero coefficients but a non-zero constant means no solution.
4. **Locate the pivot columns:** identify the leading variables from pivots in the coefficient part, and identify every remaining unknown as free.
5. **Solve:** either use back-substitution from REF or continue with Gauss–Jordan elimination to RREF.
6. **Parameterise when necessary:** assign real parameters to the free variables and express each leading variable in terms of them.
7. **Verify:** substitute the result into the original system, particularly when several arithmetic operations were required.

The logical classification is

$$
\boxed{
\begin{array}{c}
\text{Contradictory row}\\
\Downarrow\\
\text{No solutions}
\end{array}
\qquad
\begin{array}{c}
\text{Consistent, no free variables}\\
\Downarrow\\
\text{Unique solution}
\end{array}
\qquad
\begin{array}{c}
\text{Consistent, at least one free variable}\\
\Downarrow\\
\text{Infinitely many solutions}
\end{array}
}.
$$

**Final remarks.** Gaussian elimination converts the problem of solving simultaneous equations into a systematic study of pivot positions. Row operations preserve the solution set; echelon form exposes its structure; back-substitution or Gauss–Jordan elimination determines the values of the leading variables. Above all, the method makes it possible to describe **every** solution, not merely to find one candidate that happens to work.

---



- [Exercises]({{ '/pages/mathematics/linear_algebra/03-matrices-and-linear-systems/02-gaussian-elimination-and-row-echelon-forms/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/linear_algebra/03-matrices-and-linear-systems/02-gaussian-elimination-and-row-echelon-forms/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/linear_algebra/03-matrices-and-linear-systems/02-gaussian-elimination-and-row-echelon-forms/references/' | relative_url }})

[Back to Matrices and Linear Systems]({{ '/pages/mathematics/linear_algebra/03-matrices-and-linear-systems/' | relative_url }})

</article>
