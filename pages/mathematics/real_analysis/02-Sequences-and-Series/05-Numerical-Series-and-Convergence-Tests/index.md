---
layout: default
title: "2.5: Numerical Series and Convergence Tests"
permalink: /pages/mathematics/real_analysis/02-sequences-and-series/05-numerical-series-and-convergence-tests/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/real_analysis/02-sequences-and-series/' | relative_url }}">Chapter 2: Sequences and Series</a>
  <div class="eyebrow">Mathematics / Real Analysis / 2.5</div>
  <h1>2.5: Numerical Series and Convergence Tests</h1>
</div>

<article class="article" markdown="1">

# 05 — Numerical Series and Convergence Tests

## Introduction

An infinite series arises when we attempt to add the terms of a sequence indefinitely. Given a real sequence, we may formally write

$$
a_1+a_2+a_3+\cdots=\sum_{n=1}^{\infty}a_n.
$$

Unlike a finite sum, an infinite sum cannot be evaluated simply by carrying out a prescribed number of additions. Instead, its meaning is established through a limit: we add the first few terms, then progressively more terms, and ask whether the resulting sequence of *partial sums* approaches a finite number.

This observation connects the theory of infinite series directly to the theory of sequences. It also leads to a central question: **under what conditions does an infinite series converge, and how can we determine its behaviour without explicitly calculating its sum?**

We begin with convergence, divergence, and absolute convergence; develop the algebra of series; and then establish the principal convergence tests. Throughout the chapter, the geometric, harmonic, and exponential series provide the fundamental illustrations.

---

## 5.1. Infinite Series and Partial Sums

**Definition 5.1 (Infinite series and partial sums).** Let

$$
(a_n)_{n\geq 1}=(a_1,a_2,a_3,\ldots)
$$

be a sequence of real numbers. Its associated *series* is the sequence of partial sums

$$
S_N:=\sum_{n=1}^{N}a_n=a_1+a_2+\cdots+a_N,
\qquad N\in\mathbb N.
$$

The expression

$$
\sum_{n=1}^{\infty}a_n
$$

is used for the infinite series and, when it converges, for its sum.

**Definition 5.2 (Convergence of a series).** The series converges to a real number if the sequence of its partial sums has a finite limit. In symbols,

$$
\sum_{n=1}^{\infty}a_n=S
\quad\Longleftrightarrow\quad
\lim_{N\to\infty}S_N
=\lim_{N\to\infty}\sum_{n=1}^{N}a_n=S\in\mathbb R.
$$

If the sequence of partial sums has no finite limit, the series *diverges*.

It is important to distinguish the original sequence of terms from its sequence of partial sums:

$$
\underbrace{(a_n)_{n\geq 1}}_{\text{terms}}
\qquad\text{and}\qquad
\underbrace{(S_N)_{N\geq 1}}_{\text{partial sums}}.
$$

Convergence of the terms themselves does not imply convergence of the series. What matters is the limiting behaviour of the **accumulated sums**.

### 5.1.1. Modes of divergence

A series may fail to converge in different ways. Its partial sums may tend to positive infinity,

$$
\lim_{N\to\infty}S_N=+\infty,
$$

or to negative infinity,

$$
\lim_{N\to\infty}S_N=-\infty.
$$

Alternatively, the partial sums may oscillate, or more generally fail to approach either a finite or an infinite limit. All of these are forms of **ordinary divergence**.

A change to finitely many terms can change the numerical value of a convergent series, but it cannot change whether the series converges or diverges. Thus, convergence tests may be applied from any sufficiently large index onwards.

---

## 5.2. Basic Convergence and Divergence Conditions

### 5.2.1. The Cauchy criterion

A series converges precisely when sufficiently late partial sums are arbitrarily close to one another.

**Theorem 5.1 (Cauchy criterion for series).** The real series

$$
\sum_{n=1}^{\infty}a_n
$$

converges if and only if

$$
\forall\varepsilon>0\;\exists N_\varepsilon\in\mathbb N
\;\text{such that}\;
\left|\sum_{k=m+1}^{n}a_k\right|<\varepsilon
\quad\text{whenever }n>m\geq N_\varepsilon.
$$

**Proof.** By definition,

$$
S_n-S_m
=\sum_{k=1}^{n}a_k-\sum_{k=1}^{m}a_k
=\sum_{k=m+1}^{n}a_k.
$$

Consequently,

$$
|S_n-S_m|
=\left|\sum_{k=m+1}^{n}a_k\right|.
$$

The stated condition is exactly the Cauchy criterion for the sequence of partial sums. Since every Cauchy sequence of real numbers converges, the result follows. ∎

The theorem is a complete characterisation of convergence. In practice, it is particularly useful for proving other convergence criteria.

### 5.2.2. The necessary condition and the divergence test

**Theorem 5.2 (Vanishing general term).** If a series converges, then its general term tends to zero:

$$
\sum_{n=1}^{\infty}a_n\text{ converges}
\quad\Longrightarrow\quad
\lim_{n\to\infty}a_n=0.
$$

**Proof.** Since

$$
a_n=S_n-S_{n-1},
$$

and both sequences of consecutive partial sums converge to the same limit, we have

$$
\lim_{n\to\infty}a_n
=\lim_{n\to\infty}S_n
-\lim_{n\to\infty}S_{n-1}
=S-S=0.
$$

This yields an immediate divergence criterion.

**Corollary 5.1 (Divergence test).** If the sequence of general terms does not tend to zero, the corresponding series diverges:

$$
\lim_{n\to\infty}a_n\neq0
\quad\text{or the limit does not exist}
\quad\Longrightarrow\quad
\sum_{n=1}^{\infty}a_n\text{ diverges}.
$$

The converse is **false**. A general term tending to zero is necessary but not sufficient for convergence, as the harmonic series will demonstrate.

### 5.2.3. Series with nonnegative terms

For a series whose terms are nonnegative, the partial sums have an additional structure: they form a monotone sequence.

**Theorem 5.3 (Nonnegative series criterion).** Suppose

$$
a_n\geq0\qquad\text{for every }n\in\mathbb N.
$$

Then

$$
\sum_{n=1}^{\infty}a_n\text{ converges}
\quad\Longleftrightarrow\quad
(S_N)_{N\geq1}\text{ is bounded above}.
$$

If the partial sums are not bounded above, they diverge to positive infinity.

**Proof.** We have

$$
S_{N+1}-S_N=a_{N+1}\geq0,
$$

so the partial sums are nondecreasing. Every convergent sequence is bounded, establishing one implication. Conversely, every nondecreasing sequence that is bounded above converges by the monotone convergence theorem. If it is unbounded, its limit is positive infinity. ∎

This theorem is the basis of the comparison principle and much of the integral test.

### 5.2.4. Absolute and conditional convergence

For signed series, it is useful to distinguish convergence of the original terms from convergence of their absolute values.

**Definition 5.3 (Absolute convergence).** The series

$$
\sum_{n=1}^{\infty}a_n
$$

is *absolutely convergent* if

$$
\sum_{n=1}^{\infty}|a_n|<\infty.
$$

It is *absolutely divergent* (or *not absolutely convergent*) if

$$
\sum_{n=1}^{\infty}|a_n|=+\infty.
$$

The series is *conditionally convergent* if the original series converges while the series of absolute values diverges:

$$
\sum_{n=1}^{\infty}a_n\text{ converges},
\qquad
\sum_{n=1}^{\infty}|a_n|=+\infty.
$$

**Theorem 5.4 (Absolute convergence implies convergence).** Every absolutely convergent real series converges in the ordinary sense:

$$
\sum_{n=1}^{\infty}|a_n|<\infty
\quad\Longrightarrow\quad
\sum_{n=1}^{\infty}a_n\text{ converges}.
$$

**Proof.** Since the series of absolute values converges, the Cauchy criterion gives, for sufficiently large indices,

$$
\sum_{k=m+1}^{n}|a_k|<\varepsilon.
$$

By the triangle inequality,

$$
\left|\sum_{k=m+1}^{n}a_k\right|
\leq\sum_{k=m+1}^{n}|a_k|
<\varepsilon.
$$

The Cauchy criterion therefore also holds for the original series. ∎

The reverse implication does not generally hold. In particular, **absolute divergence does not, by itself, imply ordinary divergence**: a series may still converge conditionally.

---

## 5.3. Fundamental Series

The following three families illustrate much of the theory and provide useful reference points for the convergence tests that follow.

### 5.3.1. Geometric series

**Definition 5.4 (Geometric series).** A geometric series has the form

$$
\sum_{n=1}^{\infty}ar^{n-1}
=a+ar+ar^2+ar^3+\cdots,
$$

where the first term is the real number represented by the coefficient and the *common ratio* is the real number multiplying each term to produce the next:

$$
a_n=ar^{n-1},
\qquad
\frac{a_{n+1}}{a_n}=r
\quad\text{when }a_n\neq0.
$$

**Theorem 5.5 (Partial sums of a geometric series).** For

$$
S_N=\sum_{n=1}^{N}ar^{n-1},
$$

we have

$$
S_N=
\begin{cases}
Na, & r=1,\\[6pt]
\displaystyle a\frac{1-r^N}{1-r}, & r\neq1.
\end{cases}
$$

**Proof.** For a ratio different from one, multiply the finite sum by the ratio and subtract:

$$
\begin{aligned}
S_N &=a+ar+ar^2+\cdots+ar^{N-1},\\
rS_N&=ar+ar^2+\cdots+ar^{N},\\
(1-r)S_N&=a-ar^N=a(1-r^N).
\end{aligned}
$$

Dividing by the nonzero factor gives the stated identity. When the ratio equals one, all terms equal the first term, giving the other case. ∎

**Corollary 5.2 (Convergence of geometric series).** For a nonzero first term, the geometric series converges if and only if the modulus of the common ratio is smaller than one:

$$
\boxed{
\sum_{n=1}^{\infty}ar^{n-1}
=\frac{a}{1-r}
\quad\text{if }|r|<1.
}
$$

Indeed, when the ratio has modulus smaller than one,

$$
\lim_{N\to\infty}r^N=0,
$$

and the formula for the partial sums yields the result. If the ratio is at least one, the partial sums diverge towards the infinity determined by the sign of the first term. If the ratio is at most negative one, the series fails to converge because of oscillation. The zero series, obtained when its first term is zero, converges to zero for every ratio.

A useful alternative indexing is

$$
\sum_{n=0}^{\infty}ar^n=\frac{a}{1-r},
\qquad |r|<1,
$$

and, in particular,

$$
\sum_{n=1}^{\infty}r^n=\frac{r}{1-r},
\qquad |r|<1.
$$

The geometric series also has an exact *truncation error*. For the first sum above, after retaining the first few terms,

$$
R_N:=\sum_{n=N+1}^{\infty}ar^{n-1}
=\frac{ar^N}{1-r},
\qquad |r|<1.
$$

Thus, geometric convergence gives both an exact sum and a direct estimate of the error incurred by stopping at a finite partial sum.

### 5.3.2. Harmonic series

**Definition 5.5 (Harmonic series).** The harmonic series is

$$
\sum_{n=1}^{\infty}\frac1n
=1+\frac12+\frac13+\frac14+\cdots.
$$

Its terms tend to zero:

$$
\lim_{n\to\infty}\frac1n=0.
$$

Nevertheless, the sum diverges.

**Theorem 5.6 (Divergence of the harmonic series).** The harmonic series diverges to positive infinity:

$$
\sum_{n=1}^{\infty}\frac1n=+\infty.
$$

**Proof.** Group the terms between successive powers of two. For every positive integer,

$$
\sum_{k=2^{j-1}+1}^{2^j}\frac1k
\geq 2^{j-1}\frac1{2^j}
=\frac12.
$$

Consequently, for a partial sum ending at a power of two,

$$
\begin{aligned}
S_{2^m}
&=1+\sum_{j=1}^{m}\sum_{k=2^{j-1}+1}^{2^j}\frac1k\\[4pt]
&\geq1+\sum_{j=1}^{m}\frac12
=1+\frac m2.
\end{aligned}
$$

The right-hand side tends to positive infinity. Since the partial sums are increasing, the entire sequence of partial sums diverges to positive infinity. ∎

The harmonic series is therefore the fundamental demonstration that a vanishing general term does **not** guarantee convergence.

Now consider its alternating counterpart:

$$
\sum_{n=1}^{\infty}\frac{(-1)^{n-1}}{n}
=1-\frac12+\frac13-\frac14+\cdots.
$$

The magnitudes decrease monotonically to zero, so this series converges by the alternating series test, established later in the chapter. However,

$$
\sum_{n=1}^{\infty}\left|\frac{(-1)^{n-1}}n\right|
=\sum_{n=1}^{\infty}\frac1n
=+\infty.
$$

Thus, the alternating harmonic series is **conditionally convergent**, not absolutely convergent.

### 5.3.3. Exponential series

The exponential function may be represented by the series

$$
\boxed{
 e^x=\sum_{n=0}^{\infty}\frac{x^n}{n!}
=1+x+\frac{x^2}{2!}+\frac{x^3}{3!}+\cdots,
\qquad x\in\mathbb R.
}
$$

Here the factorial is defined by

$$
0!=1,
\qquad
n!=1\cdot2\cdots n\quad(n\geq1).
$$

**Theorem 5.7 (Absolute convergence of the exponential series).** The exponential series converges absolutely for every real argument.

**Proof.** For a nonzero argument, set

$$
a_n=\frac{x^n}{n!}.
$$

Then

$$
\left|\frac{a_{n+1}}{a_n}\right|
=\frac{|x|^{n+1}}{(n+1)!}\frac{n!}{|x|^n}
=\frac{|x|}{n+1}
\longrightarrow0.
$$

The ratio test therefore proves absolute convergence. For a zero argument, the constant term is one and every subsequent term vanishes, so the conclusion is immediate. ∎

Absolute convergence also allows us to multiply two exponential series by the Cauchy product, yielding

$$
\begin{aligned}
e^x e^y
&=\sum_{n=0}^{\infty}\sum_{k=0}^{n}
\frac{x^k}{k!}\frac{y^{n-k}}{(n-k)!}\\[4pt]
&=\sum_{n=0}^{\infty}\frac1{n!}
\sum_{k=0}^{n}\binom nk x^k y^{n-k}\\[4pt]
&=\sum_{n=0}^{\infty}\frac{(x+y)^n}{n!}
=e^{x+y}.
\end{aligned}
$$

The geometric and exponential series exhibit absolute convergence, while the harmonic family illustrates both ordinary divergence and conditional convergence.

---

## 5.4. Algebra of Infinite Series

Finite sums obey familiar algebraic rules. For infinite series, these rules remain valid under suitable convergence assumptions.

### 5.4.1. Linearity

**Theorem 5.8 (Algebra of convergent series).** Suppose that

$$
\sum_{n=1}^{\infty}a_n=A,
\qquad
\sum_{n=1}^{\infty}b_n=B,
$$

and let the scalar be any real number. Then

$$
\sum_{n=1}^{\infty}\lambda a_n
=\lambda\sum_{n=1}^{\infty}a_n
=\lambda A,
$$

and

$$
\sum_{n=1}^{\infty}(a_n+b_n)
=\sum_{n=1}^{\infty}a_n
+\sum_{n=1}^{\infty}b_n
=A+B.
$$

Hence every linear combination of convergent series is convergent:

$$
\sum_{n=1}^{\infty}(\alpha a_n+\beta b_n)
=\alpha A+\beta B.
$$

**Proof.** The identities hold for every finite partial sum:

$$
\sum_{n=1}^{N}(\alpha a_n+\beta b_n)
=\alpha\sum_{n=1}^{N}a_n
+\beta\sum_{n=1}^{N}b_n.
$$

Taking limits and applying the algebra of convergent sequences establishes the result. ∎

These identities require the component series to converge. They cannot, in general, be used to assign a finite sum to a divergent series.

### 5.4.2. Multiplication: the Cauchy product

The product of two infinite series is not obtained by simply multiplying their terms with matching indices. The appropriate construction is the *Cauchy product*.

**Definition 5.6 (Cauchy product).** For two series indexed from zero,

$$
\sum_{n=0}^{\infty}a_n,
\qquad
\sum_{n=0}^{\infty}b_n,
$$

their Cauchy product is the series

$$
\sum_{n=0}^{\infty}c_n,
\qquad
c_n:=\sum_{k=0}^{n}a_kb_{n-k}.
$$

In expanded form,

$$
\begin{aligned}
c_0&=a_0b_0,\\
c_1&=a_0b_1+a_1b_0,\\
c_2&=a_0b_2+a_1b_1+a_2b_0.
\end{aligned}
$$

**Theorem 5.9 (Cauchy product theorem).** If both original series converge absolutely, then their Cauchy product converges absolutely and

$$
\boxed{
\left(\sum_{n=0}^{\infty}a_n\right)
\left(\sum_{n=0}^{\infty}b_n\right)
=\sum_{n=0}^{\infty}\sum_{k=0}^{n}a_kb_{n-k}.
}
$$

More generally, the same identity holds if both series converge and at least one converges absolutely (Mertens' theorem).

When both series are absolutely convergent, the sum of all pairwise absolute products is finite:

$$
\sum_{j=0}^{\infty}\sum_{k=0}^{\infty}|a_jb_k|
=\left(\sum_{j=0}^{\infty}|a_j|\right)
\left(\sum_{k=0}^{\infty}|b_k|\right)<\infty.
$$

We may therefore regroup the terms along diagonals of constant index sum, giving the Cauchy product formula. Without suitable convergence assumptions, such regrouping is not automatically justified.

---

## 5.5. Convergence Tests

Direct evaluation of partial sums is usually difficult. Convergence tests allow us to study an infinite series indirectly, by bounding its terms, comparing it with a known series, or analysing the asymptotic behaviour of consecutive terms.

### 5.5.1. The integral test

Integration provides a criterion for convergence of series whose terms are sampled from a positive, decreasing function.

**Theorem 5.10 (Integral test).** Let the starting index be a positive integer, and let

$$
f:[r,\infty)\longrightarrow(0,\infty)
$$

be a nonincreasing function. Then

$$
\boxed{
\sum_{n=r}^{\infty}f(n)\text{ converges}
\quad\Longleftrightarrow\quad
\lim_{N\to\infty}\int_r^N f(x)\,dx<\infty.
}
$$

The right-hand side is the corresponding improper integral. Its value need not equal the sum of the series; the test compares their convergence behaviour.

**Proof.** Since the function is nonincreasing, for every point in the interval between two successive integers,

$$
f(k+1)\leq f(x)\leq f(k),
\qquad k\leq x\leq k+1.
$$

Integrating over that unit interval gives

$$
f(k+1)\leq\int_k^{k+1}f(x)\,dx\leq f(k).
$$

Summing from the starting index to a finite upper index,

$$
\boxed{
\sum_{k=r+1}^{N+1}f(k)
\leq\int_r^{N+1}f(x)\,dx
\leq\sum_{k=r}^{N}f(k).
}
$$

Suppose first that the improper integral converges to a finite number. The left inequality bounds every partial sum of the series, apart from its initial term. These partial sums are nondecreasing and bounded above, so the series converges.

Conversely, suppose the series converges. The right inequality bounds the integral uniformly by the finite sum of the entire series. Because the function is positive, the truncated integrals are nondecreasing; hence their limit exists and is finite. ∎

**Remark (Conditions of applicability).** Both positivity and monotonicity are essential assumptions of this version of the test. A nonincreasing function is Riemann integrable on every finite interval within its domain, so the truncated integrals are well-defined.

#### Bounds on the sum and the remainder

The integral comparison gives more than a convergence test. If the function is positive and nonincreasing from one unit before the initial index, then, for a convergent series,

$$
\boxed{
\int_r^{\infty}f(x)\,dx
\leq\sum_{n=r}^{\infty}f(n)
\leq\int_{r-1}^{\infty}f(x)\,dx.
}
$$

The first bound follows by passing to the limit in the right-hand side of the integral comparison inequality. The second follows by applying the left-hand inequality with the starting index shifted down by one.

More generally, when the first terms up to an index have already been calculated, the remaining tail satisfies

$$
\boxed{
\int_{N+1}^{\infty}f(x)\,dx
\leq\underbrace{\sum_{n=N+1}^{\infty}f(n)}_{R_N}
\leq\int_N^{\infty}f(x)\,dx.
}
$$

These bounds connect convergence theory with the numerical approximation of infinite sums: they quantify the error remaining after truncation.

#### The p-series criterion

An important consequence of the integral test is the complete convergence classification of the *p-series*:

$$
\sum_{n=1}^{\infty}\frac1{n^p},
\qquad p\in\mathbb R.
$$

**Theorem 5.11 (Convergence of p-series).**

$$
\boxed{
\sum_{n=1}^{\infty}\frac1{n^p}
\begin{cases}
\text{converges}, & p>1,\\
\text{diverges}, & p\leq1.
\end{cases}
}
$$

**Proof.** For positive exponents, the function

$$
f(x)=x^{-p}
$$

is positive and decreasing on the half-line starting at one. Its integral is

$$
\int_1^N x^{-p}\,dx
=\begin{cases}
\displaystyle\frac{N^{1-p}-1}{1-p}, & p\neq1,\\[8pt]
\ln N, & p=1.
\end{cases}
$$

If the exponent is greater than one, the integral has the finite limit

$$
\lim_{N\to\infty}\int_1^N x^{-p}\,dx
=\frac1{p-1}.
$$

If the exponent is positive but no greater than one, the integral diverges to positive infinity. The integral test gives the corresponding conclusions for the series. Finally, when the exponent is nonpositive, the terms do not tend to zero, and the divergence test applies. ∎

Equivalently, for any real power,

$$
\sum_{n=1}^{\infty}n^{\alpha}
\text{ converges if and only if }\alpha<-1.
$$

The harmonic series corresponds to the boundary exponent one. Its divergence therefore also follows from the integral test, since

$$
\int_1^N\frac{dx}{x}=\ln N\longrightarrow+\infty.
$$

### 5.5.2. Direct comparison test

The comparison principle transfers known convergence or divergence properties between nonnegative series.

**Theorem 5.12 (Direct comparison).** Suppose that for all sufficiently large indices,

$$
0\leq a_n\leq b_n.
$$

Then:

1. If the series of larger terms converges, the series of smaller terms also converges:

   $$
   \sum_{n=1}^{\infty}b_n<\infty
   \quad\Longrightarrow\quad
   \sum_{n=1}^{\infty}a_n<\infty.
   $$

2. If the series of smaller terms diverges, the series of larger terms also diverges:

   $$
   \sum_{n=1}^{\infty}a_n=+\infty
   \quad\Longrightarrow\quad
   \sum_{n=1}^{\infty}b_n=+\infty.
   $$

**Proof.** Since finite initial segments do not affect convergence, assume the inequalities hold from the first index. Then

$$
0\leq\sum_{n=1}^{N}a_n
\leq\sum_{n=1}^{N}b_n.
$$

If the partial sums on the right are bounded, those on the left are also bounded and monotone, hence convergent. The second assertion follows by contraposition of the first, or directly from the inequalities. ∎

A convergent smaller series does not force the larger series to converge, and a divergent larger series does not force the smaller one to diverge. The direction of the inequalities matters.

### 5.5.3. Limit comparison test

Termwise inequalities may be difficult to establish, even when two sequences have essentially the same asymptotic size. The limit comparison test addresses this situation.

**Theorem 5.13 (Limit comparison).** Let the terms of two series be strictly positive for all sufficiently large indices, and suppose the limit

$$
L:=\lim_{n\to\infty}\frac{a_n}{b_n}
$$

exists in the extended nonnegative real numbers.

- If the limit is finite and strictly positive, the two series either both converge or both diverge:

  $$
  0<L<\infty
  \quad\Longrightarrow\quad
  \left(\sum a_n\text{ converges}
  \Longleftrightarrow\sum b_n\text{ converges}\right).
  $$

- If the limit is zero and the comparison series converges, the original series converges:

  $$
  L=0,\quad\sum b_n<\infty
  \quad\Longrightarrow\quad\sum a_n<\infty.
  $$

- If the limit is positive infinity and the comparison series diverges, the original series diverges:

  $$
  L=+\infty,\quad\sum b_n=+\infty
  \quad\Longrightarrow\quad\sum a_n=+\infty.
  $$

**Proof.** If the limit is finite and strictly positive, then for sufficiently large indices there exist positive constants bounding the ratio above and below:

$$
0<c\leq\frac{a_n}{b_n}\leq C<\infty.
$$

Thus

$$
cb_n\leq a_n\leq Cb_n,
$$

and direct comparison gives equivalence of convergence. If the limit is zero, we eventually have the first sequence bounded above by the comparison sequence. If the limit is positive infinity, we eventually have the reverse inequality. The remaining conclusions again follow from direct comparison. ∎

The zero and infinite limit cases yield only the stated one-way implications; they do not provide a complete equivalence.

### 5.5.4. Ratio test

The ratio test compares the magnitude of consecutive terms. It is especially natural for factorials, products, and exponentially scaled terms.

**Theorem 5.14 (Ratio test).** Let the series have nonzero terms from some index onwards. Suppose that the limit

$$
L:=\lim_{n\to\infty}\left|\frac{a_{n+1}}{a_n}\right|
$$

exists, allowing positive infinity. Then

$$
\boxed{
\begin{array}{ccl}
L<1 &\Longrightarrow& \text{absolute convergence},\\[3pt]
L>1 &\Longrightarrow& \text{divergence},\\[3pt]
L=1 &\Longrightarrow& \text{no conclusion}.
\end{array}
}
$$

**Proof.** Suppose the limit is smaller than one. Choose a fixed number strictly between that limit and one:

$$
L<\theta<1.
$$

By the definition of a limit, for all sufficiently large indices,

$$
|a_{n+1}|\leq\theta|a_n|.
$$

Iterating the inequality gives, for any fixed sufficiently large starting index,

$$
|a_{N+j}|\leq|a_N|\theta^j,
\qquad j\geq0.
$$

The right-hand side is the general term of a convergent geometric series. Direct comparison therefore proves absolute convergence.

If the ratio limit is greater than one, then eventually

$$
|a_{n+1}|\geq|a_n|>0.
$$

The term magnitudes cannot tend to zero, so the divergence test applies. ∎

The borderline value one is inconclusive. Indeed, for the harmonic series,

$$
\left|\frac{a_{n+1}}{a_n}\right|
=\frac{n}{n+1}\longrightarrow1,
$$

although the harmonic series diverges. In particular, an inequality strictly below one at each index is not enough: the ratios must eventually be bounded above by **one fixed constant** that is itself smaller than one.

The exponential series illustrates the decisive case of ratio limit zero:

$$
\lim_{n\to\infty}\left|
\frac{x^{n+1}/(n+1)!}{x^n/n!}
\right|
=\lim_{n\to\infty}\frac{|x|}{n+1}=0
\quad(x\neq0).
$$

### 5.5.5. Root test

The root test measures the exponential scale of the terms themselves.

**Theorem 5.15 (Root test).** Define

$$
L:=\limsup_{n\to\infty}\sqrt[n]{|a_n|}.
$$

Then

$$
\boxed{
\begin{array}{ccl}
L<1 &\Longrightarrow& \text{absolute convergence},\\[3pt]
L>1 &\Longrightarrow& \text{divergence},\\[3pt]
L=1 &\Longrightarrow& \text{no conclusion}.
\end{array}
}
$$

If the ordinary limit of the roots exists, it may be used in place of the upper limit.

**Proof.** If the upper limit is smaller than one, choose a fixed number satisfying

$$
L<\theta<1.
$$

Then, for all sufficiently large indices,

$$
\sqrt[n]{|a_n|}\leq\theta
\quad\Longrightarrow\quad
|a_n|\leq\theta^n.
$$

The geometric comparison proves absolute convergence.

If the upper limit is greater than one, there are infinitely many indices for which the root exceeds some fixed number greater than one. Hence the corresponding terms cannot tend to zero, and the series diverges. ∎

The root test is particularly useful when the general term is raised to a power depending on its index. As with the ratio test, the borderline value one requires a different argument.

### 5.5.6. Alternating series test (Leibniz criterion)

Not every useful convergence criterion relies on the absolute values of the terms. Alternating signs can produce cancellation even when the absolute-value series diverges.

An alternating series has one of the forms

$$
\sum_{n=1}^{\infty}(-1)^{n-1}a_n
=a_1-a_2+a_3-a_4+\cdots
$$

or

$$
\sum_{n=1}^{\infty}(-1)^na_n
=-a_1+a_2-a_3+a_4-\cdots,
$$

where the magnitudes are nonnegative.

**Theorem 5.16 (Leibniz test).** Suppose that

$$
a_n\geq0,
\qquad
a_{n+1}\leq a_n,
\qquad
\lim_{n\to\infty}a_n=0.
$$

Then the alternating series converges:

$$
\boxed{
\sum_{n=1}^{\infty}(-1)^{n-1}a_n
\text{ converges}.
}
$$

The same conclusion holds when the overall sign is reversed.

**Proof.** Let

$$
S_N=\sum_{n=1}^{N}(-1)^{n-1}a_n.
$$

The even-indexed partial sums are nondecreasing, because

$$
S_{2m+2}-S_{2m}=a_{2m+1}-a_{2m+2}\geq0.
$$

The odd-indexed partial sums are nonincreasing, because

$$
S_{2m+3}-S_{2m+1}=-a_{2m+2}+a_{2m+3}\leq0.
$$

Moreover, every even-indexed partial sum is no larger than the adjacent odd-indexed sum, and the two subsequences are bounded between the first two partial sums. Hence both subsequences converge. Finally,

$$
S_{2m+1}-S_{2m}=a_{2m+1}\longrightarrow0,
$$

so their limits are equal. The full sequence of partial sums therefore converges. ∎

The theorem also gives a practical estimate for the truncation error. If the complete alternating sum is denoted by its limit, then

$$
\boxed{
|S-S_N|\leq a_{N+1}.
}
$$

The error has the sign of the first omitted term. For the alternating harmonic series, the hypotheses hold because its magnitudes are decreasing and tend to zero; hence

$$
\sum_{n=1}^{\infty}\frac{(-1)^{n-1}}n
\text{ converges},
\qquad
|S-S_N|\leq\frac1{N+1}.
$$

As its absolute-value series is the divergent harmonic series, this convergence is conditional.

---

## 5.6. Choosing a Convergence Test

Each test is suited to a different structural feature of the general term. A useful approach is to proceed from the simplest necessary condition to a more specialised criterion:

1. **Check the general term.** If it does not tend to zero, the series diverges. If it does tend to zero, further work is needed.
2. **Check the signs.** For nonnegative terms, partial sums are monotone and comparison methods become available. For alternating signs, examine monotonic decay and apply the Leibniz criterion if possible.
3. **Recognise a standard family.** Geometric series provide an exact sum, while the p-series criterion—derived from the integral test—provides a basic convergence benchmark.
4. **Choose a comparison.** Use direct comparison for simple inequalities and limit comparison when only the asymptotic magnitude is apparent.
5. **Use the integral test for sampled decreasing functions.** The same argument can yield useful estimates of the sum and its truncation error.
6. **Use the ratio or root test for multiplicative or exponential structure.** Both prove absolute convergence when their decisive limit is below one; neither decides the borderline case.
7. **Distinguish ordinary from absolute convergence.** A series can converge conditionally even when the series of its absolute values diverges.

The relationships between the main convergence concepts can be summarised as

$$
\boxed{
\text{absolute convergence}
\;\Longrightarrow\;
\text{ordinary convergence}
\;\Longrightarrow\;
a_n\longrightarrow0.
}
$$

Neither implication can be reversed in general. The harmonic series disproves the reverse of the second implication, and the alternating harmonic series disproves the reverse of the first.

---

## Chapter Summary

An infinite series is understood through the limiting behaviour of its partial sums, linking the study of series to the fundamental principles of sequence convergence. The Cauchy criterion gives a complete description of convergence, while the vanishing-term condition provides a simple but one-sided test for divergence. Absolute convergence ensures ordinary convergence, although alternating signs can permit conditional convergence through cancellation.

The algebra of convergent series preserves linear combinations, while the Cauchy product requires additional attention to convergence. To analyse series whose sums cannot be computed directly, we developed integral and comparison methods, the ratio and root tests, and the Leibniz criterion. The geometric, harmonic, and exponential series show how these ideas interact: one admits an exact finite-limit formula, another exposes the insufficiency of vanishing terms, and the last illustrates strong absolute convergence.

The central lesson is that **the behaviour of an infinite sum depends not only on whether its terms vanish, but on how rapidly they vanish and how their signs interact**.


## Supporting material

- [Exercises]({{ '/pages/mathematics/real_analysis/02-sequences-and-series/05-numerical-series-and-convergence-tests/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/real_analysis/02-sequences-and-series/05-numerical-series-and-convergence-tests/solutions/' | relative_url }})
- [References]({{ '/pages/mathematics/real_analysis/02-sequences-and-series/05-numerical-series-and-convergence-tests/references/' | relative_url }})

## Subchapter navigation

[Previous: 2.4 - Compactness Limsup and Liminf]({{ '/pages/mathematics/real_analysis/02-sequences-and-series/04-compactness-limsup-and-liminf/' | relative_url }})

[Back to Chapter 2: Sequences and Series]({{ '/pages/mathematics/real_analysis/02-sequences-and-series/' | relative_url }})

[Next chapter: Functions and Continuity]({{ '/pages/mathematics/real_analysis/03-functions-and-continuity/' | relative_url }})

</article>

