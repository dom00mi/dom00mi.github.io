---
layout: default
title: "5.2: Riemann Integrability and Properties"
permalink: /pages/mathematics/real_analysis/05-integral-calculus/02-riemann-integrability-and-properties/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/real_analysis/05-integral-calculus/' | relative_url }}">Chapter 5: Integral Calculus</a>
  <div class="eyebrow">Mathematics / Real Analysis / 5.2</div>
  <h1>5.2: Riemann Integrability and Properties</h1>
  <p class="lead">Placeholder notes for Riemann Integrability and Properties.</p>
</div>

<article class="article" markdown="1">


# Chapter 3 — Darboux's Theorem, Criteria for Riemann Integrability, and Properties of the Integral

## Introduction

The preceding chapter introduced the Riemann integral through lower and upper sums. We now connect those formal definitions to the intuitive process of making the subintervals of a partition increasingly small. **Darboux's theorem** provides this connection and leads to practical tests for integrability. We then show that continuous and monotone functions are Riemann integrable and establish the integral's principal algebraic, order, and domain-splitting properties. These results also prepare us for the fundamental theorem of calculus, integration by parts, and substitution in the following chapter.

> **Notation.** Throughout, $\mathcal B([a,b])$ denotes bounded real-valued functions, $\mathcal P([a,b])$ denotes partitions, $\mathcal R([a,b])$ denotes Riemann integrable functions, and $L(f,P)$ and $U(f,P)$ are the lower and upper Darboux sums. The numbering of the statements and equations follows the source PDF.

## 3.1 — Darboux's Theorem and Its Applications

The idea behind Darboux's theorem is that every sufficiently fine partition—not merely some specially chosen partition—produces lower and upper sums arbitrarily close to the respective lower and upper Riemann integrals.

### Theorem 3.1 — Darboux's Theorem

Let $f\in\mathcal B([a,b])$. Then given any $\varepsilon>0$ there is a $\delta>0$ such that $w(P)<\delta$ for $P\in\mathcal P([a,b])$ implies

$$
\boxed{\underline{\int_a^b} f(x)\,dx-\varepsilon
<L(f,P)\leq\underline{\int_a^b} f(x)\,dx}
\tag{3.1}
$$

and

$$
\boxed{\overline{\int_a^b} f(x)\,dx
\leq U(f,P)<\overline{\int_a^b} f(x)\,dx+\varepsilon.}
\tag{3.2}
$$

The same estimates can be expressed in terms of nonnegative approximation errors.

### Remark 3.2 — Equivalent formulation of (3.1) and (3.2)

Note that (3.1) and (3.2) imply that for all $P\in\mathcal P([a,b])$ with $w(P)<\delta$ we have

$$
0\leq\underline{\int_a^b}f(x)\,dx-L(f,P)<\varepsilon,
$$

$$
0\leq U(f,P)-\overline{\int_a^b}f(x)\,dx<\varepsilon.
$$

Darboux's theorem shows that lower and upper integrals may be recovered as limits of sums along partitions whose widths tend to zero.

### Remark 3.3 — Lower and upper sums as limits

Darboux's theorem says that $w(P)\to0$ implies

$$
L(f,P)\longrightarrow\underline{\int_a^b}f(x)\,dx
\qquad\text{and}\qquad
U(f,P)\longrightarrow\overline{\int_a^b}f(x)\,dx,
$$

that is, the lower Riemann integral and the upper Riemann integral can be approached by shrinking $w(P)$.

**Proof of Theorem 3.1.** We prove only the statement concerning the upper integral, since the lower-integral argument is similar. Let $\varepsilon>0$. By the definition

$$
\overline{\int_a^b}f(x)\,dx
=\inf\{U(f,P):P\in\mathcal P([a,b])\},
$$

there exists $Q\in\mathcal P([a,b])$ for which

$$
\overline{\int_a^b}f(x)\,dx
\leq U(f,Q)
\leq\overline{\int_a^b}f(x)\,dx+\frac{\varepsilon}{2}.
$$

Suppose $Q$ has $j$ points, and choose $K>0$ such that $|f(x)|\leq K$ for all $x\in[a,b]$. Let $P\in\mathcal P([a,b])$ satisfy $w(P)<\delta$, where $\delta$ will be chosen below. Set

$$
\widetilde Q=P\cup Q.
$$

The partition $\widetilde Q$ has at most $j$ additional points compared with $P$. The refinement estimates (proved in the preceding chapter) give

$$
U(f,P)\leq U(f,\widetilde Q)+2jK\,w(P),
\qquad U(f,\widetilde Q)\leq U(f,Q).
\tag{3.3}
$$

It follows that

$$
\begin{aligned}
\overline{\int_a^b}f(x)\,dx
&\leq U(f,P)\\
&\leq U(f,\widetilde Q)+2jK\,w(P)\\
&\leq U(f,Q)+2jK\,w(P)\\
&<\overline{\int_a^b}f(x)\,dx+\frac\varepsilon2+2jK\delta.
\end{aligned}
$$

To obtain (3.2), it is enough to have $2jK\delta\leq\varepsilon/2$. Choose

$$
0<\delta\leq\frac{\varepsilon}{4jK}.
$$

Then every partition $P$ with $w(P)<\delta$ satisfies

$$
\overline{\int_a^b}f(x)\,dx
\leq U(f,P)
<\overline{\int_a^b}f(x)\,dx+\frac\varepsilon2+2jK\delta
\leq\overline{\int_a^b}f(x)\,dx+\varepsilon.
$$

This completes the proof. $\square$

The theorem yields a more convenient test for Riemann integrability: it is enough to find a single partition whose upper and lower sums differ by an arbitrarily small amount.

### Corollary 3.4 — Riemann's criterion for integrability

Let $f\in\mathcal B([a,b])$. Then $f\in\mathcal R([a,b])$ if and only if for every $\varepsilon>0$ there exists $P\in\mathcal P([a,b])$ such that

$$
\boxed{0\leq U(f,P)-L(f,P)<\varepsilon.}
$$

**Proof of Corollary 3.4.**

**$\Rightarrow$:** Suppose $f\in\mathcal R([a,b])$, and let $\varepsilon>0$. Darboux's theorem provides a partition $P\in\mathcal P([a,b])$ such that

$$
\begin{aligned}
\overline{\int_a^b}f(x)\,dx
&\leq U(f,P)<\overline{\int_a^b}f(x)\,dx+\frac\varepsilon2,\\
\underline{\int_a^b}f(x)\,dx
&\geq L(f,P)>\underline{\int_a^b}f(x)\,dx-\frac\varepsilon2.
\end{aligned}
\tag{3.4}
$$

Since $f$ is integrable, the two integrals equal $\int_a^b f(x)\,dx$. Multiplying the second inequality by $-1$, (3.4) becomes

$$
\int_a^b f(x)\,dx
\leq U(f,P)<\int_a^b f(x)\,dx+\frac\varepsilon2,
\tag{3.5}
$$

$$
-\int_a^b f(x)\,dx
\leq-L(f,P)<-\int_a^b f(x)\,dx+\frac\varepsilon2.
\tag{3.6}
$$

Adding (3.5) and (3.6) gives

$$
0\leq U(f,P)-L(f,P)<\varepsilon.
$$

**$\Leftarrow$:** Conversely, suppose that for every $\varepsilon>0$ there exists a partition $P$ satisfying

$$
0\leq U(f,P)-L(f,P)<\varepsilon.
\tag{3.7}
$$

We always have

$$
L(f,P)\leq\underline{\int_a^b}f(x)\,dx
\leq\overline{\int_a^b}f(x)\,dx\leq U(f,P).
\tag{3.8}
$$

Consequently,

$$
0\leq\overline{\int_a^b}f(x)\,dx
-\underline{\int_a^b}f(x)\,dx
\leq U(f,P)-L(f,P)<\varepsilon.
$$

As $\varepsilon$ is arbitrary, the difference of the upper and lower integrals must be zero, so

$$
\overline{\int_a^b}f(x)\,dx=\underline{\int_a^b}f(x)\,dx.
$$

Thus $f\in\mathcal R([a,b])$. $\square$

The limit formulation becomes particularly useful when we work with a whole sequence of successively finer partitions.

### Definition 3.5 — Limiting sequence of partitions (for $[a,b]$)

A sequence $\{P_n\}$ of partitions $P_n\in\mathcal P([a,b])$ will be called a **limiting sequence** for $[a,b]$ if $w(P_n)\to0$ as $n\to\infty$.

### Example 3.6 — Equally spaced partition of $[a,b]$

Partition $[a,b]$ into $n$ intervals of equal length, that is,

$$
P_n:=\left\{a+k\frac{b-a}{n}:k=0,1,2,\ldots,n\right\}.
$$

Then

$$
w(P_n)=\frac{b-a}{n}\longrightarrow0\qquad(n\to\infty).
$$

$\square$


### Theorem 3.7 — Upper and lower Riemann integral as limits

Let $\{P_n\}$ be a limiting sequence of partitions for $[a,b]$, and let $f\in\mathcal B([a,b])$. Then

$$
\boxed{\underline{\int_a^b}f(x)\,dx=\lim_{n\to\infty}L(f,P_n),
\qquad
\overline{\int_a^b}f(x)\,dx=\lim_{n\to\infty}U(f,P_n),}
\tag{3.9}
$$

and hence $f\in\mathcal R([a,b])$ if and only if

$$
\boxed{\lim_{n\to\infty}L(f,P_n)=\lim_{n\to\infty}U(f,P_n).}
\tag{3.10}
$$

**Proof of Theorem 3.7.** We prove the first limit in (3.9). Let $\{P_n\}\subset\mathcal P([a,b])$ be a limiting sequence. We must show that for each $\varepsilon>0$ there exists $N=N(\varepsilon)\in\mathbb N$ such that

$$
\underline{\int_a^b}f(x)\,dx-L(f,P_n)<\varepsilon
\qquad\text{for every }n\geq N.
$$

Fix $\varepsilon>0$. By Darboux's theorem (Theorem 3.1 and Remark 3.2), there exists $\delta>0$ such that any partition $P$ with $w(P)<\delta$ satisfies

$$
\underline{\int_a^b}f(x)\,dx-L(f,P)<\varepsilon.
\tag{3.11}
$$

Because $\{P_n\}$ is a limiting sequence, we can choose $N$ so that $w(P_n)<\delta$ for all $n\geq N$. Apply (3.11) with $P=P_n$ to obtain

$$
\underline{\int_a^b}f(x)\,dx-L(f,P_n)<\varepsilon
\qquad\text{for all }n\geq N.
$$

This proves the first limit, since $\varepsilon$ was arbitrary. The proof for the upper integral is analogous. Finally, the equivalence in (3.10) follows immediately from (3.9) and the definition of Riemann integrability. $\square$

We apply this theorem to equally spaced partitions and compute several integrals directly from their lower and upper sums.

### Example 3.8 — Bounded function with discontinuity

As in Example 2.12, let $f:[1,2]\to\mathbb R$ be given by

$$
f(x):=\begin{cases}
0,&x\neq\sqrt2,\\
1,&x=\sqrt2,
\end{cases}
$$

and for every $n\in\mathbb N$ let

$$
P_n:=\left\{1,1+\frac1n,\ldots,1+\frac{n-1}{n},2\right\}
=\left\{1+\frac{k}{n}:k=0,1,\ldots,n\right\}.
$$

Show that $\{P_n\}$ is a limiting sequence. Use Example 2.12 and Theorem 3.7 to show that $f$ is Riemann integrable on $[1,2]$ and that

$$
\int_1^2 f(x)\,dx=0.
$$

**Solution.** Example 2.12 gives $L(f,P_n)=0$ and $U(f,P_n)=1/n$. Since

$$
w(P_n)=\frac1n\longrightarrow0,
$$

$\{P_n\}$ is limiting, and Theorem 3.7 gives

$$
\underline{\int_1^2}f(x)\,dx
=\lim_{n\to\infty}L(f,P_n)=\lim_{n\to\infty}0=0,
$$

$$
\overline{\int_1^2}f(x)\,dx
=\lim_{n\to\infty}U(f,P_n)=\lim_{n\to\infty}\frac1n=0.
$$

Therefore the lower and upper integrals coincide:

$$
\underline{\int_1^2}f(x)\,dx
=\overline{\int_1^2}f(x)\,dx=0.
$$

By definition, $f\in\mathcal R([1,2])$ and

$$
\boxed{\int_1^2 f(x)\,dx=0.}
$$

$\square$

### Example 3.9 — Piecewise constant function

As in Example 2.13, let $f:[0,2]\to\mathbb R$ be defined by

$$
f(x):=\begin{cases}
0,&0\leq x\leq1,\\
7,&1<x\leq2,
\end{cases}
$$

and let

$$
P_{2n}:=\left\{0,\frac1n,\ldots,\frac{2n-1}{n},2\right\}
=\left\{\frac{k}{n}:k=0,1,\ldots,2n\right\},\qquad n\in\mathbb N.
$$

Find the lower and upper Riemann integrals on $[0,2]$. Determine whether $f$ is Riemann integrable and, if so, compute its integral.

**Solution.** Example 2.13 established

$$
L(f,P_{2n})=7\frac{n-1}{n},\qquad U(f,P_{2n})=7.
$$

Since $w(P_{2n})=1/n\to0$, this is a limiting sequence. Therefore

$$
\begin{aligned}
\underline{\int_0^2}f(x)\,dx
&=\lim_{n\to\infty}L(f,P_{2n})\\
&=\lim_{n\to\infty}7\frac{n-1}{n}
=\lim_{n\to\infty}7\left(1-\frac1n\right)=7,
\end{aligned}
$$

$$
\overline{\int_0^2}f(x)\,dx
=\lim_{n\to\infty}U(f,P_{2n})
=\lim_{n\to\infty}7=7.
$$

The integrals coincide, so $f\in\mathcal R([0,2])$, with

$$
\boxed{\int_0^2f(x)\,dx=7.}
$$

$\square$

### Example 3.10 — Integral of $x^2$

Let $b$ be a positive number. Show that $f(x)=x^2$ is Riemann integrable over $[0,b]$, and that

$$
\boxed{\int_0^b x^2\,dx=\frac{b^3}{3}.}
$$

**Solution.** Use the equally spaced partition

$$
P_n:=\left\{0,\frac bn,\frac{2b}{n},\ldots,\frac{(n-1)b}{n},b\right\}
=\left\{\frac{kb}{n}:k=0,1,\ldots,n\right\}.
$$

Since $w(P_n)=b/n\to0$, this is a limiting sequence for $[0,b]$, so Theorem 3.7 applies. As $x^2$ is increasing on $[0,b]$, the upper sum is

$$
\begin{aligned}
U(f,P_n)
&=\sum_{k=1}^{n}\left(\sup_{x\in[(k-1)b/n,\,kb/n]}x^2\right)\frac bn\\
&=\sum_{k=1}^{n}\left(\frac{kb}{n}\right)^2\frac bn
=\frac{b^3}{n^3}\sum_{k=1}^{n}k^2.
\end{aligned}
$$

Using the identity, which can be proved by induction,

$$
\sum_{k=1}^{n}k^2=\frac{n(n+1)(2n+1)}6,
\tag{3.12}
$$

we obtain

$$
\begin{aligned}
U(f,P_n)
&=\frac{b^3}{n^3}\frac{n(n+1)(2n+1)}6\\
&=\frac{b^3}{6}\left(2+\frac3n+\frac1{n^2}\right)
\longrightarrow\frac{b^3}{3}.
\end{aligned}
$$

By Theorem 3.7,

$$
\overline{\int_0^b}x^2\,dx=\frac{b^3}{3}.
\tag{3.13}
$$

Similarly,

$$
\begin{aligned}
L(f,P_n)
&=\sum_{k=1}^{n}\left(\inf_{x\in[(k-1)b/n,\,kb/n]}x^2\right)\frac bn\\
&=\sum_{k=1}^{n}\left(\frac{(k-1)b}{n}\right)^2\frac bn
=\frac{b^3}{n^3}\sum_{k=1}^{n}(k-1)^2.
\end{aligned}
$$

Set $j=k-1$. Then, using (3.12),

$$
\begin{aligned}
L(f,P_n)
&=\frac{b^3}{n^3}\sum_{j=0}^{n-1}j^2
=\frac{b^3}{n^3}\sum_{j=1}^{n-1}j^2\\
&=\frac{b^3}{n^3}\frac{(n-1)n(2n-1)}6\\
&=\frac{b^3}{6}\left(2-\frac3n+\frac1{n^2}\right)
\longrightarrow\frac{b^3}{3}.
\end{aligned}
$$

Hence

$$
\underline{\int_0^b}x^2\,dx=\frac{b^3}{3}.
\tag{3.14}
$$

Comparing (3.13) and (3.14), we see that $x^2\in\mathcal R([0,b])$ and

$$
\boxed{\int_0^b x^2\,dx=\frac{b^3}{3}.}
$$

$\square$
Numerical integration, also called *quadrature*, approximates an integral by a finite weighted sum of values of the integrand. In general, we seek to approximate

$$
\int_a^b f(x)\,dx
$$

with an expression of the form

$$
\sum_{j=0}^{m}w_j f(x_j),
$$

where the real numbers $w_j$ are **weights**, and the points $x_j\in[a,b]$ are **nodes**. As a simple illustration, the integral over $[0,1]$ can be approximated by

$$
\frac13\sum_{k=0}^{2}f\left(\frac k2\right)
=\frac13f(0)+\frac13f\left(\frac12\right)+\frac13f(1).
$$

This rule is exact for a constant integrand $f(x)=c$, since

$$
\frac13\sum_{k=0}^{2}f\left(\frac k2\right)
=\frac c3+\frac c3+\frac c3
=c=c(1-0)=\int_0^1c\,dx.
$$

Every lower or upper Darboux sum also gives a numerical integration rule. These simple choices are not generally the most efficient approximations, so we now examine two more useful quadrature formulas: **Simpson's rule** and the **midpoint (rectangular) rule**.

### Corollary 3.11 — Simpson's rule

Let $f:[a,b]\to\mathbb R$ be Riemann integrable, and let $Q_{2n}=\{y_0,\ldots,y_{2n}\}$ be the partition of $[a,b]$ given by

$$
y_k:=a+k\frac{b-a}{2n},\qquad k=0,1,2,\ldots,2n.
$$

Define **Simpson's rule** by

$$
\begin{aligned}
S(f,Q_{2n})
&:=\frac{b-a}{6n}\left[f(y_0)+4\sum_{k=1}^{n}f(y_{2k-1})
+2\sum_{k=1}^{n-1}f(y_{2k})+f(y_{2n})\right]\\
&=\frac{b-a}{6n}\big[f(y_0)+4f(y_1)+2f(y_2)+4f(y_3)+2f(y_4)+\cdots\\
&\hspace{95pt}\cdots+2f(y_{2n-2})+4f(y_{2n-1})+f(y_{2n})\big]\\
&=\frac{b-a}{6n}\sum_{k=1}^{n}\left[f(y_{2k-2})+4f(y_{2k-1})+f(y_{2k})\right].
\end{aligned}
\tag{3.15}
$$

Then

$$
\boxed{\lim_{n\to\infty}S(f,Q_{2n})=\int_a^bf(x)\,dx,}
\tag{3.16}
$$

that is, (3.15) defines an approximation of the Riemann integral of $f$ over the interval $[a,b]$.

The last line of (3.15) makes the rule particularly easy to interpret. The $k$th contribution is

$$
\frac{b-a}{n}\left[
\frac16f\left(a+(2k-2)\frac{b-a}{2n}\right)
+\frac46f\left(a+(2k-1)\frac{b-a}{2n}\right)
+\frac16f\left(a+2k\frac{b-a}{2n}\right)
\right].
$$

This corresponds to the interval

$$
\left[a+(2k-2)\frac{b-a}{2n},\quad a+2k\frac{b-a}{2n}\right]
$$

of length $(b-a)/n$. Its two endpoints are evaluated with weight $1/6$ each, and its midpoint with weight $4/6$.

**Proof of Corollary 3.11.** Introduce the equally spaced partition $P_n=\{x_0,\ldots,x_n\}$ with

$$
x_k:=a+k\frac{b-a}{n},\qquad k=0,1,\ldots,n.
$$

Since $x_k=y_{2k}$, every interval $[x_{k-1},x_k]=[y_{2k-2},y_{2k}]$ contains all three nodes $y_{2k-2}$, $y_{2k-1}$, and $y_{2k}$. We first show that

$$
\inf_{x\in[x_{k-1},x_k]}f(x)
\leq\frac{f(y_{2k-2})+4f(y_{2k-1})+f(y_{2k})}{6}
\leq\sup_{x\in[x_{k-1},x_k]}f(x).
\tag{3.17}
$$

Multiplying (3.17) by $x_k-x_{k-1}=(b-a)/n$ and summing over $k=1,\ldots,n$ gives

$$
L(f,P_n)\leq S(f,Q_{2n})\leq U(f,P_n).
\tag{3.18}
$$

As $n\to\infty$, we have $w(P_n)\to0$ and thus, by Theorem 3.7,

$$
\underline{\int_a^b}f(x)\,dx
\leq\lim_{n\to\infty}S(f,Q_{2n})
\leq\overline{\int_a^b}f(x)\,dx.
$$

Since $f\in\mathcal R([a,b])$, the lower and upper integrals coincide, proving (3.16).

It remains to verify (3.17). For each of the three nodes we have

$$
\begin{aligned}
\inf_{x\in[x_{k-1},x_k]}f(x)&\leq f(y_{2k-2})\leq\sup_{x\in[x_{k-1},x_k]}f(x),\\
\inf_{x\in[x_{k-1},x_k]}f(x)&\leq f(y_{2k-1})\leq\sup_{x\in[x_{k-1},x_k]}f(x),\\
\inf_{x\in[x_{k-1},x_k]}f(x)&\leq f(y_{2k})\leq\sup_{x\in[x_{k-1},x_k]}f(x).
\end{aligned}
$$

Taking the weighted average with weights $1/6,4/6,1/6$ preserves these bounds. That proves (3.17) and completes the proof. $\square$

### Example 3.12 — Application of Simpson's rule

Use Simpson's rule to show that

$$
\int_0^b x^2\,dx=\frac{b^3}{3}.
$$

**Solution.** From Example 3.10, $x^2\in\mathcal R([0,b])$, so Simpson's rule applies. Substituting the nodes $y_k=kb/(2n)$,

$$
\begin{aligned}
S(f,Q_{2n})
&=\frac b{6n}\sum_{k=1}^{n}\left[
\left(\frac{(2k-2)b}{2n}\right)^2
+4\left(\frac{(2k-1)b}{2n}\right)^2
+\left(\frac{2kb}{2n}\right)^2\right]\\
&=\frac{b^3}{24n^3}\sum_{k=1}^{n}\left[(2k-2)^2+4(2k-1)^2+(2k)^2\right]\\
&=\frac{b^3}{24n^3}\sum_{k=1}^{n}(24k^2-24k+8)\\
&=\frac{b^3}{3n^3}\sum_{k=1}^{n}(3k^2-3k+1)\\
&=\frac{b^3}{3n^3}\left[
\frac{3n(n+1)(2n+1)}6
-\frac{3n(n+1)}2+n\right]\\
&=\frac{b^3}{3n^3}\,n^3=\frac{b^3}{3}.
\end{aligned}
$$

Here we used (3.12) and the identity

$$
\sum_{k=1}^{n}k=\frac{n(n+1)}2.
\tag{3.19}
$$

Thus

$$
\int_0^b x^2\,dx
=\lim_{n\to\infty}S(f,Q_{2n})
=\lim_{n\to\infty}\frac{b^3}{3}
=\frac{b^3}{3}.
$$

$\square$

### Corollary 3.13 — Rectangular rule or midpoint rule

Let $f:[a,b]\to\mathbb R$ be Riemann integrable and let $P_n=\{x_0,x_1,\ldots,x_n\}$ be the partition of $[a,b]$ given by

$$
x_k:=a+k\frac{b-a}{n},\qquad k=0,1,2,\ldots,n.
$$

Define the **rectangular rule** (or **midpoint rule**) by

$$
\boxed{R(f,P_n):=\frac{b-a}{n}\sum_{k=1}^{n}
f\left(\frac{x_{k-1}+x_k}{2}\right)
=\frac{b-a}{n}\sum_{k=1}^{n}
f\left(a+\frac{(2k-1)(b-a)}{2n}\right).}
$$

The rectangular rule satisfies

$$
L(f,P_n)\leq R(f,P_n)\leq U(f,P_n),
$$

and thus

$$
\boxed{\lim_{n\to\infty}R(f,P_n)=\int_a^bf(x)\,dx.}
\tag{3.20}
$$

In this construction the interval is split into $n$ subintervals

$$
\left[a+(k-1)\frac{b-a}{n},\quad a+k\frac{b-a}{n}\right],
\qquad k=1,2,\ldots,n,
$$

each of length $(b-a)/n$. The midpoint of the $k$th subinterval is

$$
\frac12\left[\left(a+(k-1)\frac{b-a}{n}\right)
+\left(a+k\frac{b-a}{n}\right)\right]
=a+\frac{(2k-1)(b-a)}{2n}.
$$

The contribution to the rule is therefore the area of a rectangle whose width is the subinterval length and whose height is $f$ evaluated at that midpoint.

**Proof of Corollary 3.13.** Since

$$
\frac{x_{k-1}+x_k}{2}\in[x_{k-1},x_k],
$$

we have

$$
\inf_{x\in[x_{k-1},x_k]}f(x)
\leq f\left(\frac{x_{k-1}+x_k}{2}\right)
\leq\sup_{x\in[x_{k-1},x_k]}f(x).
\tag{3.21}
$$

Multiply by $x_k-x_{k-1}=(b-a)/n$ and sum over $k=1,\ldots,n$ to obtain

$$
L(f,P_n)\leq R(f,P_n)\leq U(f,P_n),\qquad n\in\mathbb N.
\tag{3.22}
$$

Taking limits and applying Theorem 3.7,

$$
\underline{\int_a^b}f(x)\,dx
\leq\lim_{n\to\infty}R(f,P_n)
\leq\overline{\int_a^b}f(x)\,dx.
\tag{3.23}
$$

Because $f\in\mathcal R([a,b])$, both bounding integrals have the same value. Hence (3.20) follows. $\square$

### Example 3.14 — Application of the rectangular rule

Use the rectangular rule to show that, for $b>0$,

$$
\int_0^b x^2\,dx=\frac{b^3}{3}.
$$

**Solution.** Example 3.10 established that $f(x)=x^2$ is integrable on $[0,b]$. With (3.12) and (3.19),

$$
\begin{aligned}
R(x^2,P_n)
&=\frac bn\sum_{k=1}^{n}\left[
\frac12\left(\frac{(k-1)b}{n}+\frac{kb}{n}\right)\right]^2\\
&=\frac bn\sum_{k=1}^{n}\left(\frac{(2k-1)b}{2n}\right)^2\\
&=\frac{b^3}{n^3}\sum_{k=1}^{n}\left(k^2-k+\frac14\right)\\
&=\frac{b^3}{n^3}\left[
\frac{n(n+1)(2n+1)}6
-\frac{n(n+1)}2+\frac n4\right]\\
&=\frac{b^3}{3}\left(1-\frac{1}{4n^2}\right).
\end{aligned}
$$

Thus

$$
\lim_{n\to\infty}R(x^2,P_n)
=\lim_{n\to\infty}\frac{b^3}{3}\left(1-\frac1{4n^2}\right)
=\frac{b^3}{3}.
$$

$\square$

> **Arithmetic correction.** The source notes print $1-1/(12n^2)$ inside the final parentheses. The preceding finite-sum calculation simplifies to $1-1/(4n^2)$; both forms yield the same limit, but only the latter is the exact finite-$n$ midpoint sum.

### Remark 3.15 — On Simpson's rule and the rectangular rule

Both Simpson's rule and the rectangular rule are much better approximations of the integral than $U(f,P_n)$ and $L(f,P_n)$.

Darboux's theorem also shows that the values of bounded functions at finitely many points do not affect their lower and upper integrals.

### Corollary 3.16 — “Almost equal” functions

Let $f,g\in\mathcal B([a,b])$, and suppose $f(x)\neq g(x)$ only at a finite number of points. Then

$$
\boxed{\underline{\int_a^b}f(x)\,dx=\underline{\int_a^b}g(x)\,dx,
\qquad
\overline{\int_a^b}f(x)\,dx=\overline{\int_a^b}g(x)\,dx.}
\tag{3.24}
$$

In particular, $f\in\mathcal R([a,b])$ if and only if $g\in\mathcal R([a,b])$.

### Example 3.17 — Integrals of “almost equal” functions

Consider $f:[1,2]\to\mathbb R$ defined by

$$
f(x):=\begin{cases}
0,&x\neq\sqrt2,\\
1,&x=\sqrt2.
\end{cases}
$$

Examples 2.12 and 3.8 showed that $f\in\mathcal R([1,2])$ and that $\int_1^2f(x)\,dx=0$. Corollary 3.16 gives a more direct argument. The constant function $g(x):=0$ is Riemann integrable and satisfies

$$
\int_1^2 g(x)\,dx=0(2-1)=0.
$$

Since $f(x)=g(x)$ for every $x\in[1,2]\setminus\{\sqrt2\}$, Corollary 3.16 yields $f\in\mathcal R([1,2])$ and

$$
\int_1^2f(x)\,dx=\int_1^2g(x)\,dx=0.
$$

$\square$

**Proof of Corollary 3.16.** We prove the equality of the lower integrals only; the upper-integral argument is analogous. Let $j$ be the number of points where $f(x)\neq g(x)$, and choose $K$ so that

$$
\sup_{x\in[a,b]}|f(x)|\leq K,
\qquad\sup_{x\in[a,b]}|g(x)|\leq K.
$$

For any partition $P$, we claim

$$
\boxed{|L(f,P)-L(g,P)|\leq4jK\,w(P).}
\tag{3.25}
$$

Indeed, there are at most $2j$ subintervals on which

$$
\inf_{x\in[x_{k-1},x_k]}f(x)
\neq\inf_{x\in[x_{k-1},x_k]}g(x).
\tag{3.26}
$$

On each such subinterval, the infima differ by no more than $2K$ in absolute value:

$$
\left|\inf_{x\in[x_{k-1},x_k]}f(x)
-\inf_{x\in[x_{k-1},x_k]}g(x)\right|\leq2K.
\tag{3.27}
$$

Since each affected interval has length at most $w(P)$, summing the maximum $2j$ nonzero contributions gives (3.25).

Now choose a limiting sequence $\{P_n\}\subset\mathcal P([a,b])$. The triangle inequality and (3.25) imply

$$
\begin{aligned}
&\left|\underline{\int_a^b}f(x)\,dx
-\underline{\int_a^b}g(x)\,dx\right|\\
&\quad\leq\left|\underline{\int_a^b}f(x)\,dx-L(f,P_n)\right|
+|L(f,P_n)-L(g,P_n)|
+\left|L(g,P_n)-\underline{\int_a^b}g(x)\,dx\right|\\
&\quad\leq\left|\underline{\int_a^b}f(x)\,dx-L(f,P_n)\right|
+4jK\,w(P_n)
+\left|L(g,P_n)-\underline{\int_a^b}g(x)\,dx\right|.
\end{aligned}
$$

By Theorem 3.7, the first and third terms approach zero. The middle term also tends to zero because $w(P_n)\to0$. Thus

$$
\left|\underline{\int_a^b}f(x)\,dx
-\underline{\int_a^b}g(x)\,dx\right|=0,
$$

which establishes the first equality in (3.24). $\square$

## 3.2 — Continuous and Monotone Functions Are Riemann Integrable

The next two theorems give efficient ways to verify integrability without directly comparing lower and upper sums. Familiar continuous functions—including polynomials, trigonometric functions, and exponentials—are immediately covered. Monotonicity supplies a second, independent sufficient condition, even when a function has discontinuities. Establishing integrability is essential before using a rule to calculate an integral.

**Notation.** Write $\langle c,d\rangle$ for any one of the intervals $(c,d)$, $[c,d]$, $[c,d)$, or $(c,d]$, where $-\infty\leq c<d\leq+\infty$. Let $C(\langle c,d\rangle)$ denote all continuous real-valued functions on that interval.

### Theorem 3.18 — Continuous on $[a,b]$ $\Rightarrow$ Riemann integrable on $[a,b]$

Any continuous function on a closed interval $[a,b]$ is Riemann integrable over $[a,b]$, that is,

$$
\boxed{C([a,b])\subset\mathcal R([a,b]).}
$$

**Proof of Theorem 3.18.** We proceed by contradiction. Suppose there exists $f\in C([a,b])$ with $f\notin\mathcal R([a,b])$. Riemann's criterion (Corollary 3.4) then ensures that some $\varepsilon_0>0$ satisfies

$$
U(f,P)-L(f,P)\geq\varepsilon_0
\qquad\text{for every }P=\{x_0,\ldots,x_n\}\in\mathcal P([a,b]).
\tag{3.28}
$$

Use the notation

$$
m_k(f):=\inf_{x\in[x_{k-1},x_k]}f(x),
\qquad M_k(f):=\sup_{x\in[x_{k-1},x_k]}f(x).
$$

Then (3.28) reads

$$
\sum_{k=1}^{n}\big[M_k(f)-m_k(f)\big](x_k-x_{k-1})
\geq\varepsilon_0.
\tag{3.29}
$$

Choose an index $k_0$ at which the oscillation is maximal:

$$
M_{k_0}(f)-m_{k_0}(f)
=\max_{1\leq k\leq n}\big[M_k(f)-m_k(f)\big].
$$

The sum in (3.29) is bounded above by this maximum oscillation multiplied by the total interval length:

$$
\begin{aligned}
\varepsilon_0
&\leq\sum_{k=1}^{n}\big[M_k(f)-m_k(f)\big](x_k-x_{k-1})\\
&\leq\big[M_{k_0}(f)-m_{k_0}(f)\big]
\sum_{k=1}^{n}(x_k-x_{k-1})\\
&=\big[M_{k_0}(f)-m_{k_0}(f)\big](b-a).
\end{aligned}
$$

Therefore,

$$
M_{k_0}(f)-m_{k_0}(f)\geq\frac{\varepsilon_0}{b-a}.
\tag{3.30}
$$

Because $f$ is continuous on the compact interval $[x_{k_0-1},x_{k_0}]$, it attains its infimum and supremum there. We may therefore choose $y,z\in[x_{k_0-1},x_{k_0}]$ such that

$$
f(y)=M_{k_0}(f),\qquad f(z)=m_{k_0}(f),
$$

and hence

$$
|f(y)-f(z)|\geq\frac{\varepsilon_0}{b-a}.
\tag{3.31}
$$

At the same time, both $y$ and $z$ lie in one subinterval, so

$$
|y-z|\leq x_{k_0}-x_{k_0-1}\leq w(P).
\tag{3.32}
$$

Now take a limiting sequence of partitions $\{P_m\}\subset\mathcal P([a,b])$. For each $m$, the previous construction provides points $y_m,z_m\in[a,b]$ with

$$
|y_m-z_m|\leq w(P_m)
\tag{3.33}
$$

and

$$
|f(y_m)-f(z_m)|\geq\frac{\varepsilon_0}{b-a}.
\tag{3.34}
$$

The sequence $\{y_m\}$ is bounded, so it has a convergent subsequence $\{y_{m_j}\}$, say

$$
y_{m_j}\longrightarrow x_0\in[a,b]\qquad(j\to\infty).
$$

Furthermore, by (3.33),

$$
|z_{m_j}-x_0|
\leq|z_{m_j}-y_{m_j}|+|y_{m_j}-x_0|
\longrightarrow0.
$$

Thus $z_{m_j}\to x_0$ as well. Continuity of $f$ implies

$$
f(y_{m_j})\longrightarrow f(x_0),
\qquad f(z_{m_j})\longrightarrow f(x_0).
$$

But taking limits in (3.34) gives

$$
0=\lim_{j\to\infty}|f(y_{m_j})-f(z_{m_j})|
\geq\frac{\varepsilon_0}{b-a}>0,
$$

a contradiction. Therefore every $f\in C([a,b])$ is Riemann integrable. $\square$

### Example 3.19 — Elementary examples illustrating the use of Theorem 3.18

**(a)** The functions $e^x$, $\cos x$, $\sin x$, and all polynomials

$$
p(x):=a_mx^m+a_{m-1}x^{m-1}+\cdots+a_1x+a_0
$$

are continuous on $\mathbb R$. Thus they are Riemann integrable over any closed interval $[a,b]$.

**(b)** The logarithm $\ln x$ is continuous on $\mathbb R_+:=\{x\in\mathbb R:x>0\}$. Thus the logarithm is Riemann integrable over any interval $[a,b]$ with $a>0$. $\square$

We next formalize the notion of a monotone function.

### Definition 3.20 — Monotone functions

**(i)** A function $f:\langle c,d\rangle\to\mathbb R$ is called **increasing** (or **monotonically increasing**) if $x<y$, $x,y\in\langle c,d\rangle$ implies $f(x)\leq f(y)$.

**(ii)** A function $f:\langle c,d\rangle\to\mathbb R$ is called **decreasing** (or **monotonically decreasing**) if $x<y$, $x,y\in\langle c,d\rangle$ implies $f(x)\geq f(y)$.

**(iii)** A function $f:\langle c,d\rangle\to\mathbb R$ is called **monotone** if (i) or (ii) holds. The set of all monotone functions on the interval $\langle c,d\rangle$ is denoted by $\mathcal M(\langle c,d\rangle)$.

### Example 3.21 — Monotone functions

**(a)** A constant function $f:\mathbb R\to\mathbb R$, $f(x)=C$ for every $x\in\mathbb R$, with fixed $C\in\mathbb R$, is monotone (both increasing and decreasing).

**(b)** The exponential function $e^x$ is increasing on any interval $\langle c,d\rangle$.

**(c)** The function $\sin x$ is not monotone on $[0,3\pi/2]$. However, $\sin x$ is increasing on $[0,\pi/2]$ and decreasing on $[\pi/2,3\pi/2]$.

**(d)** The logarithm $\ln x$ is increasing on $(0,\infty)$. $\square$

### Theorem 3.22 — Monotone on $[a,b]$ $\Rightarrow$ Riemann integrable on $[a,b]$

Any monotone function on $[a,b]$ is Riemann integrable on $[a,b]$, that is,

$$
\boxed{\mathcal M([a,b])\subset\mathcal R([a,b]).}
$$

### Remark 3.23 — Monotone on $[a,b]$ $\Rightarrow$ bounded on $[a,b]$

If $f$ is increasing then $f(a)\leq f(x)\leq f(b)$ for all $x\in[a,b]$, and if $f$ is decreasing then $f(a)\geq f(x)\geq f(b)$ for all $x\in[a,b]$. Thus increasing functions and decreasing functions are bounded, that is,

$$
\boxed{\mathcal M([a,b])\subset\mathcal B([a,b]).}
$$

**Proof of Theorem 3.22.** It is enough to prove the claim for an increasing function, since the decreasing case is analogous. Let $f$ be increasing. By Theorem 3.7, it suffices to produce a limiting sequence of partitions $\{P_n\}$ such that

$$
U(f,P_n)-L(f,P_n)\longrightarrow0.
$$

Divide $[a,b]$ into $n$ equal subintervals:

$$
P_n:=\left\{a,a+\frac{b-a}{n},a+\frac{2(b-a)}{n},\ldots,b\right\}
=\left\{a+\frac{k(b-a)}{n}:k=0,1,\ldots,n\right\}.
$$

Since $f$ is increasing,

$$
\sup_{x\in[x_{k-1},x_k]}f(x)=f(x_k),
\qquad\inf_{x\in[x_{k-1},x_k]}f(x)=f(x_{k-1}).
$$

Therefore

$$
\begin{aligned}
U(f,P_n)
&=\sum_{k=1}^{n}\left(\sup_{x\in[x_{k-1},x_k]}f(x)\right)(x_k-x_{k-1})\\
&=\sum_{k=1}^{n}f(x_k)\frac{b-a}{n}
=\frac{b-a}{n}\sum_{k=1}^{n}f(x_k),
\end{aligned}
$$

and

$$
\begin{aligned}
L(f,P_n)
&=\sum_{k=1}^{n}\left(\inf_{x\in[x_{k-1},x_k]}f(x)\right)(x_k-x_{k-1})\\
&=\sum_{k=1}^{n}f(x_{k-1})\frac{b-a}{n}
=\frac{b-a}{n}\sum_{k=1}^{n}f(x_{k-1}).
\end{aligned}
$$

Subtracting and cancelling the interior terms gives

$$
\begin{aligned}
U(f,P_n)-L(f,P_n)
&=\frac{b-a}{n}\sum_{k=1}^{n}f(x_k)
-\frac{b-a}{n}\sum_{k=1}^{n}f(x_{k-1})\\
&=\frac{b-a}{n}\big[f(x_n)-f(x_0)\big]\\
&=\frac{b-a}{n}\big[f(b)-f(a)\big]
\longrightarrow0\qquad(n\to\infty).
\end{aligned}
$$

By Theorem 3.7, $f\in\mathcal R([a,b])$. $\square$

**Note.** A monotone function need not be continuous, and a continuous function need not be monotone. Thus Theorems 3.18 and 3.22 are independent sufficient conditions for Riemann integrability.

### Example 3.24 — $\operatorname{sign}(x)$ is Riemann integrable

The sign function is defined by

$$
\operatorname{sign}(x):=\begin{cases}
-1,&x<0,\\
0,&x=0,\\
+1,&x>0.
\end{cases}
$$

It is monotone on $\mathbb R$ and hence Riemann integrable over any interval $[a,b]$. $\square$

### Example 3.25 — Step function

The step function $f:\mathbb R\to\mathbb R$ defined by

$$
f(x):=n\qquad\text{if }x\in[n,n+1),\quad n\in\mathbb Z,
$$

is monotone on $\mathbb R$ and hence Riemann integrable over any interval $[a,b]$. $\square$

The functions in Examples 3.24 and 3.25 are monotone but not continuous. Moreover, a monotone function may have infinitely many discontinuities, as the step function demonstrates.

> **Note.** If a function is neither monotone nor continuous, it may nevertheless be Riemann integrable. Therefore, showing that a function is neither continuous nor monotone is **not** sufficient to conclude that it is not Riemann integrable.

## 3.3 — Properties of the Integral

The structure of the Riemann integral is closely related to that of a vector space. We first recall the relevant algebraic definition, then apply it to spaces of real-valued functions. This will help us prove that Riemann integrable functions are closed under addition and scalar multiplication and that integration is a linear operation.

### Definition 3.26 — Real vector space / linear space

A set $V$ together with two associations, the addition $\oplus:V\times V\to V$, $(v,w)\mapsto v\oplus w$, and the scalar multiplication $\odot:\mathbb R\times V\to V$, $(\alpha,v)\mapsto\alpha\odot v$ is called a **linear space** (or **vector space**) over $\mathbb R$ if $(V,\oplus,\odot)$ satisfies the following conditions:

**(i)** The (additive) associative law holds true, namely

$$
(u\oplus v)\oplus w=u\oplus(v\oplus w)
\qquad\text{for all }u,v,w\in V.
$$

**(ii)** There exists an element $O\in V$ (called the neutral element) such that

$$
O\oplus v=v\oplus O=v
\qquad\text{for all }v\in V.
$$

**(iii)** For every $v\in V$, there exists an element $w\in V$ (called the inverse element to $v$) such that

$$
v\oplus w=w\oplus v=O.
$$

**(iv)** The addition is commutative, that is,

$$
v\oplus w=w\oplus v
\qquad\text{for all }v,w\in V.
$$

**(v)** We have $1\odot v=v$ for all $v\in V$.

**(vi)** If $\alpha,\beta\in\mathbb R$ and $v\in V$ then $(\alpha\beta)\odot v=\alpha\odot(\beta\odot v)$.

**(vii)** The distributive laws hold, that is, for all $\alpha,\beta\in\mathbb R$ and $v,w\in V$,

$$
(\alpha+\beta)\odot v=(\alpha\odot v)\oplus(\beta\odot v),
\qquad
\alpha\odot(v\oplus w)=(\alpha\odot v)\oplus(\alpha\odot w).
$$

The real numbers with their ordinary addition and multiplication provide the standard example. Another important example is the collection of all real-valued functions on an interval.

### Example 3.27 — Functions on $\langle c,d\rangle$ as a vector space

The real-valued functions on an interval $\langle c,d\rangle$ form a linear (vector) space under pointwise addition and pointwise scalar multiplication. Write

$$
\mathcal F(\langle c,d\rangle)
:=\{f:f:\langle c,d\rangle\to\mathbb R\text{ is a function}\}.
$$

For $f,g\in\mathcal F(\langle c,d\rangle)$, define pointwise addition by

$$
(f+g)(x):=f(x)+g(x),\qquad x\in\langle c,d\rangle,
\tag{3.35}
$$

and, for $\alpha\in\mathbb R$, define pointwise scalar multiplication by

$$
(\alpha f)(x):=\alpha f(x),\qquad x\in\langle c,d\rangle.
\tag{3.36}
$$

With these operations, $\mathcal F(\langle c,d\rangle)$ is a vector space. Indeed, $f+g$ and $\alpha f$ are again elements of $\mathcal F(\langle c,d\rangle)$, and the remaining axioms follow directly from the corresponding properties of real numbers. $\square$

### Example 3.28 — Continuous functions on $\langle c,d\rangle$ as a vector space

The set $C(\langle c,d\rangle)$ of continuous functions, with the usual pointwise addition (3.35) and pointwise scalar multiplication (3.36), is a vector (linear) space.

The crucial point is **closure**: for any $f,g\in C(\langle c,d\rangle)$, the sum $f+g$ is continuous; likewise, for $f\in C(\langle c,d\rangle)$ and $\alpha\in\mathbb R$, the function $\alpha f$ is continuous. The vector-space axioms then follow easily.

For example, by associativity of addition in $\mathbb R$,

$$
\big(f(x)+g(x)\big)+h(x)
=f(x)+\big(g(x)+h(x)\big)
$$

for every $x\in\langle c,d\rangle$ and $f,g,h\in C(\langle c,d\rangle)$. Hence

$$
(f+g)+h=f+(g+h)
\qquad\text{for all }f,g,h\in C(\langle c,d\rangle).
$$

The neutral element is the zero function $O(x):=0$, and the additive inverse of $f$ is $(-1)f$. The verification of the other axioms is left as an exercise. $\square$

We now ask whether the set $\mathcal R([a,b])$ of Riemann integrable functions is itself a vector space.

**Notation.** If $f:\langle c,d\rangle\to\mathbb R$ and $\langle c',d'\rangle\subset\langle c,d\rangle$ is a subinterval, then $f|_{\langle c',d'\rangle}$ denotes the restriction of $f$ to that subinterval.

The main rules can be organized into a single statement. Beyond giving us methods for evaluating integrals, they show that integration respects the structure of a vector space.

### Lemma 3.29 — Properties of the Riemann integral

Let $a<b$ and denote by $\mathcal R([a,b])$ the set of real-valued Riemann-integrable functions on $[a,b]$. The following properties hold.

**(i) Linearity and the integral as a linear functional.** The set $\mathcal R([a,b])$ is a real vector space under pointwise addition and scalar multiplication. In particular, if $f,g\in\mathcal R([a,b])$ and $\alpha,\beta\in\mathbb R$, then $\alpha f+\beta g\in\mathcal R([a,b])$ and

$$
\boxed{\int_a^b\bigl[\alpha f(x)+\beta g(x)\bigr],dx
=\alpha\int_a^bf(x)\,dx+\beta\int_a^bg(x)\,dx.}
$$

Consequently, the integration map

$$
\begin{aligned}
I_{[a,b]}:\mathcal R([a,b])&\longrightarrow\mathbb R,\\
f&\longmapsto I_{[a,b]}(f):=\int_a^bf(x)\,dx
\end{aligned}
$$

is a **linear functional**:

$$
\boxed{I_{[a,b]}(\alpha f+\beta g)
=\alpha I_{[a,b]}(f)+\beta I_{[a,b]}(g).}
$$

In particular, subtraction is compatible with integration:

$$
\int_a^b\bigl[f(x)-g(x)\bigr],dx
=\int_a^bf(x)\,dx-\int_a^bg(x)\,dx.
\tag{3.41}
$$

**(ii) Domain splitting and orientation.** Let $f:[a,b]\to\mathbb R$ be bounded and $c\in(a,b)$. Then $f\in\mathcal R([a,b])$ if and only if $f|_{[a,c]}\in\mathcal R([a,c])$ and $f|_{[c,b]}\in\mathcal R([c,b])$. When integrable,

$$
\boxed{\int_a^bf(x)\,dx=\int_a^cf(x)\,dx+\int_c^bf(x)\,dx.}
\tag{3.37}
$$

The standard conventions for equal or reversed integration limits are

$$
\boxed{\int_a^af(x)\,dx=0,
\qquad\int_b^af(x)\,dx=-\int_a^bf(x)\,dx.}
$$

With these conventions, the additivity relation extends to any $a,b,c$ in a common interval where $f$ is integrable:

$$
\boxed{\int_a^bf(x)\,dx+\int_b^cf(x)\,dx=\int_a^cf(x)\,dx.}
$$

**(iii) Bounds, positivity, and order.** If $f\in\mathcal R([a,b])$ and $m,M\in\mathbb R$ satisfy $m\leq f(x)\leq M$ for every $x\in[a,b]$, then

$$
\boxed{m(b-a)\leq\int_a^bf(x)\,dx\leq M(b-a).}
$$

In particular, if $f(x)\geq0$ for all $x\in[a,b]$, then $\int_a^bf(x)\,dx\geq0$. If $f,g\in\mathcal R([a,b])$ and $f(x)\leq g(x)$ for every $x\in[a,b]$, then

$$
\boxed{\int_a^bf(x)\,dx\leq\int_a^bg(x)\,dx.}
\tag{3.38}
$$

If $f(x)<g(x)$ at every point of $[a,b]$, the inequality between their integrals is strict. If $f\geq0$ and $[c,d]\subseteq[a,b]$, then

$$
0\leq\int_c^df(x)\,dx\leq\int_a^bf(x)\,dx.
$$

Finally, if $f\in C([a,b])$ is nonnegative and $\int_a^bf(x)\,dx=0$, then $f(x)=0$ for all $x\in[a,b]$.

**(iv) Modulus, products, and quotients.** If $f,g\in\mathcal R([a,b])$, then $|f|$, $fg$, and $|f|^p$ for every real $p\geq1$ are Riemann integrable. Moreover,

$$
\boxed{\left|\int_a^bf(x)\,dx\right|\leq\int_a^b|f(x)|\,dx.}
\tag{3.39}
$$

If, in addition, $\inf_{x\in[a,b]}|g(x)|=K>0$, then $f/g\in\mathcal R([a,b])$.

**(v) Cauchy–Schwarz inequality.** For $f,g\in\mathcal R([a,b])$,

$$
\boxed{\left|\int_a^bf(x)g(x)\,dx\right|
\leq\left(\int_a^b|f(x)|^2\,dx\right)^{1/2}
\left(\int_a^b|g(x)|^2\,dx\right)^{1/2}.}
\tag{3.40}
$$

**(vi) Hölder's inequality.** For $1\leq p,q\leq\infty$ satisfying $1/p+1/q=1$, define

$$
\|f\|_{p,[a,b]}:=\left(\int_a^b|f(x)|^p\,dx\right)^{1/p}
\quad(1\leq p<\infty),
\qquad
\|f\|_{\infty,[a,b]}:=\sup_{x\in[a,b]}|f(x)|.
$$

Then the corresponding Riemann-integrable functions satisfy

$$
\boxed{\int_a^b|f(x)g(x)|\,dx
\leq\|f\|_{p,[a,b]}\,\|g\|_{q,[a,b]}.}
$$

When $p=q=2$, this yields the Cauchy–Schwarz bound.

**(vii) Minkowski's inequality.** For $1\leq p<\infty$ and $f,g\in\mathcal R([a,b])$,

$$
\boxed{\left(\int_a^b|f(x)+g(x)|^p\,dx\right)^{1/p}
\leq\left(\int_a^b|f(x)|^p\,dx\right)^{1/p}
+\left(\int_a^b|g(x)|^p\,dx\right)^{1/p}.}
$$

Equivalently, $\|f+g\|_{p,[a,b]}\leq\|f\|_{p,[a,b]}+\|g\|_{p,[a,b]}$.

The same inequality holds for $p=\infty$ using the supremum norm.

The lemma collects both the integrability-preserving operations and the inequalities that make integral calculations manageable. For finite $p$, $\|\cdot\|_{p,[a,b]}$ is only a **seminorm** on the space of pointwise Riemann-integrable functions: changing a function at finitely many points does not change these integrals.

#### Beyond the Riemann integral

Linearity is not limited to Riemann integration. On a measure space $(E,\mu)$, the real-valued Lebesgue-integrable functions form a vector space $L^1(E,\mu)$ (identifying functions equal almost everywhere), and

$$
I_\mu(f):=\int_E f\,d\mu,
\qquad
I_\mu(\alpha f+\beta g)=\alpha I_\mu(f)+\beta I_\mu(g).
$$

The Lebesgue integral therefore defines a linear functional on $L^1(E,\mu)$. The Cauchy–Schwarz, Hölder, and Minkowski inequalities extend to Lebesgue integration and underpin the construction of $L^p$ spaces and, for $p=2$, the Hilbert-space viewpoint.

More general theories integrate vector-valued functions when the target space and integrability assumptions permit it; the resulting integration map remains linear on the subspace where the integral is finite. The Daniell approach, later generalized in abstract integration frameworks such as Bourbaki's, uses linearity together with order or continuity and normalization properties to characterize integration axiomatically. Such extensions require their own definitions and assumptions and are not part of the Riemann-integrability lemma above.

### Example 3.30 — Piecewise constant function

Let $f:[0,3]\to\mathbb R$ be defined by

$$
f(x):=\begin{cases}
2,&0\leq x\leq1,\\
5,&1<x\leq3.
\end{cases}
$$

The function is increasing, hence Riemann integrable. The domain splitting property gives

$$
\int_0^3f(x)\,dx=\int_0^1f(x)\,dx+\int_1^3f(x)\,dx.
$$

On $[1,3]$, the restriction $f|_{[1,3]}$ differs from the constant function $g(x):=5$ only at $x=1$. By Corollary 3.16, they have the same integral. Thus

$$
\begin{aligned}
\int_0^3f(x)\,dx
&=\int_0^1 2\,dx+\int_1^3 5\,dx\\
&=2(1-0)+5(3-1)=\boxed{12},
\end{aligned}
$$

where we used the constant-function formula

$$
\int_a^b C\,dx=C(b-a).
$$

$\square$

The product property in Lemma 3.29 provides another useful application: a function built by multiplying two integrable functions remains integrable.

### Example 3.32 — Product of functions

Show that $g:[0,3]\to\mathbb R$ defined by

$$
g(x):=\begin{cases}
2x^2,&0\leq x\leq1,\\
5,&1<x\leq3
\end{cases}
$$

is Riemann integrable over $[0,3]$.

**Solution.** Let $f$ be the function from Example 3.30, and define $h:[0,3]\to\mathbb R$ by

$$
h(x):=\begin{cases}
x^2,&0\leq x\leq1,\\
1,&1<x\leq3.
\end{cases}
$$

Then $g=fh$. Example 3.10 shows that $h|_{[0,1]}(x)=x^2$ is integrable on $[0,1]$. The constant function $\kappa(x)=1$ on $[1,3]$ is also integrable, and $h|_{[1,3]}$ agrees with $\kappa$ except at $x=1$. By Corollary 3.16, $h|_{[1,3]}\in\mathcal R([1,3])$. The domain splitting property therefore yields $h\in\mathcal R([0,3])$.

Since $f\in\mathcal R([0,3])$ by Example 3.30 and $h\in\mathcal R([0,3])$, the product property of Lemma 3.29 gives $g=fh\in\mathcal R([0,3])$.

Using domain splitting, linearity, and Corollary 3.16,

$$
\begin{aligned}
\int_0^3g(x)\,dx
&=\int_0^1g(x)\,dx+\int_1^3g(x)\,dx\\
&=\int_0^12x^2\,dx+\int_1^35\,dx\\
&=2\int_0^1x^2\,dx+\int_1^35\,dx\\
&=2\cdot\frac13+5(3-1)\\
&=\frac23+10=\boxed{\frac{32}{3}}.
\end{aligned}
$$

This uses the formulas from Examples 3.10 and 2.22,

$$
\int_0^b x^2\,dx=\frac{b^3}{3},
\qquad\int_a^b C\,dx=C(b-a).
$$

This approach is considerably simpler than evaluating limits of lower and upper sums directly. $\square$

The identities formerly listed separately as properties of linearity, modulus, order, and interval splitting are now grouped in Lemma 3.29. We retain the detailed derivations below, including the proof that $\mathcal R([a,b])$ is a vector space. These source proofs continue through the requested final PDF page (page 80).

### Proof of the first linear property

Let $f,g\in\mathcal R([a,b])$ and take any partition $P=\{x_0,x_1,\ldots,x_n\}$. Denote

$$
m_k(f):=\inf_{x\in[x_{k-1},x_k]}f(x),
\qquad M_k(f):=\sup_{x\in[x_{k-1},x_k]}f(x),
\tag{3.42}
$$

$$
m_k(g):=\inf_{x\in[x_{k-1},x_k]}g(x),
\qquad M_k(g):=\sup_{x\in[x_{k-1},x_k]}g(x),
\tag{3.43}
$$

and

$$
\begin{aligned}
m_k(f+g)&:=\inf_{x\in[x_{k-1},x_k]}\big[f(x)+g(x)\big],\\
M_k(f+g)&:=\sup_{x\in[x_{k-1},x_k]}\big[f(x)+g(x)\big].
\end{aligned}
\tag{3.44}
$$

The definitions of infimum and supremum imply

$$
m_k(f)+m_k(g)
\leq m_k(f+g)\leq M_k(f+g)
\leq M_k(f)+M_k(g).
\tag{3.45}
$$

Multiply by $x_k-x_{k-1}$ and sum over $k=1,\ldots,n$. Then

$$
L(f,P)+L(g,P)
\leq L(f+g,P)\leq U(f+g,P)
\leq U(f,P)+U(g,P).
$$

Take a limiting sequence $\{P_n\}$ of partitions. For each $n$,

$$
L(f,P_n)+L(g,P_n)
\leq L(f+g,P_n)\leq U(f+g,P_n)
\leq U(f,P_n)+U(g,P_n).
$$

Since $f,g\in\mathcal R([a,b])$, Theorem 3.7 gives, on letting $n\to\infty$,

$$
\begin{aligned}
\int_a^bf(x)\,dx+\int_a^bg(x)\,dx
&\leq\underline{\int_a^b}\big[f(x)+g(x)\big]\,dx\\
&\leq\overline{\int_a^b}\big[f(x)+g(x)\big]\,dx\\
&\leq\int_a^bf(x)\,dx+\int_a^bg(x)\,dx.
\end{aligned}
$$

The expressions on the far left and far right coincide, so all inequalities are equalities. Therefore

$$
\underline{\int_a^b}\big[f(x)+g(x)\big]\,dx
=\overline{\int_a^b}\big[f(x)+g(x)\big]\,dx,
$$

which shows $f+g\in\mathcal R([a,b])$, and

$$
\int_a^b\big[f(x)+g(x)\big]\,dx
=\int_a^bf(x)\,dx+\int_a^bg(x)\,dx.
$$

This proves the first linear property. $\square$

### Proof of the second linear property

Let $f\in\mathcal R([a,b])$ and $\alpha\in\mathbb R$. For an arbitrary partition $P=\{x_0,x_1,\ldots,x_n\}$, consider the infima and suprema of $\alpha f$.

If $\alpha\geq0$, then

$$
\begin{aligned}
m_k(\alpha f)
&:=\inf_{x\in[x_{k-1},x_k]}\alpha f(x)
=\alpha\inf_{x\in[x_{k-1},x_k]}f(x)
=\alpha m_k(f),\\
M_k(\alpha f)
&:=\sup_{x\in[x_{k-1},x_k]}\alpha f(x)
=\alpha\sup_{x\in[x_{k-1},x_k]}f(x)
=\alpha M_k(f).
\end{aligned}
$$

If $\alpha<0$, multiplication reverses the order, giving

$$
\begin{aligned}
m_k(\alpha f)
&:=\inf_{x\in[x_{k-1},x_k]}\alpha f(x)
=\alpha\sup_{x\in[x_{k-1},x_k]}f(x)
=\alpha M_k(f),\\
M_k(\alpha f)
&:=\sup_{x\in[x_{k-1},x_k]}\alpha f(x)
=\alpha\inf_{x\in[x_{k-1},x_k]}f(x)
=\alpha m_k(f).
\end{aligned}
$$

Here we use the notation of (3.42) and (3.43), taking $g=\alpha f$. In particular, for $\alpha\geq0$,

$$
\alpha m_k(f)=m_k(\alpha f)
\leq M_k(\alpha f)=\alpha M_k(f),
\tag{3.46}
$$

and for $\alpha<0$,

$$
\alpha M_k(f)=m_k(\alpha f)
\leq M_k(\alpha f)=\alpha m_k(f).
\tag{3.47}
$$

Multiply each inequality by $x_k-x_{k-1}$ and sum over $k=1,\ldots,n$. For $\alpha\geq0$,

$$
\alpha L(f,P)=L(\alpha f,P)
\leq U(\alpha f,P)=\alpha U(f,P),
\tag{3.48}
$$

whereas for $\alpha<0$,

$$
\alpha U(f,P)=L(\alpha f,P)
\leq U(\alpha f,P)=\alpha L(f,P).
\tag{3.49}
$$

Now substitute a limiting sequence $\{P_n\}$ into (3.48) and (3.49) and let $n\to\infty$. Because $f$ is Riemann integrable,

$$
\lim_{n\to\infty}\alpha L(f,P_n)
=\lim_{n\to\infty}\alpha U(f,P_n)
=\alpha\int_a^bf(x)\,dx.
$$

Hence the lower and upper sums of $\alpha f$ have equal limits:

$$
\lim_{n\to\infty}L(\alpha f,P_n)
=\lim_{n\to\infty}U(\alpha f,P_n).
$$

Thus $\alpha f\in\mathcal R([a,b])$. Taking these limits in (3.48) or (3.49) also gives

$$
\boxed{\int_a^b\alpha f(x)\,dx
=\alpha\int_a^bf(x)\,dx.}
$$

$\square$

### Proof of the domain splitting property

We first show the equivalence

$$
f\in\mathcal R([a,b])
\quad\Longleftrightarrow\quad
f|_{[a,c]}\in\mathcal R([a,c])
\text{ and }f|_{[c,b]}\in\mathcal R([c,b]).
$$

Let $\{P_n\}$ be a limiting sequence of partitions for $[a,b]$ such that **every** $P_n$ contains $c$. Then the restricted partitions $P_n\cap[a,c]$ and $P_n\cap[c,b]$ form limiting sequences for $[a,c]$ and $[c,b]$, respectively.

**$\Rightarrow$:** Suppose $f\in\mathcal R([a,b])$. By Theorem 3.7, for every $\varepsilon>0$ there exists $N=N(\varepsilon)$ such that for all $n\geq N$,

$$
\begin{aligned}
\varepsilon
&>U(f,P_n)-L(f,P_n)\\
&=\sum_{k=1}^{n}\left[
\sup_{x\in[x_{k-1},x_k]}f(x)
-\inf_{x\in[x_{k-1},x_k]}f(x)\right](x_k-x_{k-1})
\geq0.
\end{aligned}
$$

Every term of this sum is nonnegative. Since $c\in P_n$, the sums split exactly at $c$:

$$
U(f,P_n)
=U(f,P_n\cap[a,c])+U(f,P_n\cap[c,b]),
\tag{3.50}
$$

$$
L(f,P_n)
=L(f,P_n\cap[a,c])+L(f,P_n\cap[c,b]).
\tag{3.51}
$$

It follows that, for all $n\geq N$,

$$
\varepsilon>
U(f,P_n\cap[a,c])-L(f,P_n\cap[a,c])\geq0,
$$

$$
\varepsilon>
U(f,P_n\cap[c,b])-L(f,P_n\cap[c,b])\geq0.
$$

Because $\varepsilon>0$ was arbitrary,

$$
\lim_{n\to\infty}L(f,P_n\cap[a,c])
=\lim_{n\to\infty}U(f,P_n\cap[a,c]),
$$

$$
\lim_{n\to\infty}L(f,P_n\cap[c,b])
=\lim_{n\to\infty}U(f,P_n\cap[c,b]).
$$

Hence $f|_{[a,c]}\in\mathcal R([a,c])$ and $f|_{[c,b]}\in\mathcal R([c,b])$.

**$\Leftarrow$:** Now assume that $f|_{[a,c]}\in\mathcal R([a,c])$ and $f|_{[c,b]}\in\mathcal R([c,b])$. By Theorem 3.7, for every $\varepsilon>0$ there exists $N_1=N_1(\varepsilon)$ such that, for every $n\geq N_1$,

$$
0\leq U(f,P_n\cap[a,c])-L(f,P_n\cap[a,c])
<\frac\varepsilon2,
\tag{3.52}
$$

and there exists $N_2=N_2(\varepsilon)$ such that, for every $n\geq N_2$,

$$
0\leq U(f,P_n\cap[c,b])-L(f,P_n\cap[c,b])
<\frac\varepsilon2.
\tag{3.53}
$$

The chosen partitions split at $c$, so

$$
\begin{aligned}
U(f,P_n)&=U(f,P_n\cap[a,c])+U(f,P_n\cap[c,b]),\\
L(f,P_n)&=L(f,P_n\cap[a,c])+L(f,P_n\cap[c,b]).
\end{aligned}
$$

Adding (3.52) and (3.53) gives, for all $n\geq N:=\max\{N_1,N_2\}$,

$$
0\leq U(f,P_n)-L(f,P_n)<\varepsilon.
$$

By Theorem 3.7, $f\in\mathcal R([a,b])$.

Finally, if $f\in\mathcal R([a,b])$, both (3.50) and (3.51) hold. Taking $n\to\infty$ in either equality and using integrability on both subintervals yields

$$
\int_a^bf(x)\,dx=\int_a^cf(x)\,dx+\int_c^bf(x)\,dx,
$$

which is (3.37). $\square$

### Proof of the first two order properties

Suppose $f(x)\geq0$ for all $x\in[a,b]$. For any partition $P=\{x_0,x_1,\ldots,x_n\}$,

$$
m_k(f):=\inf_{x\in[x_{k-1},x_k]}f(x)\geq0,
\qquad M_k(f):=\sup_{x\in[x_{k-1},x_k]}f(x)\geq0.
$$

Therefore

$$
L(f,P)\geq0,\qquad U(f,P)\geq0
$$

for every partition. Since the lower and upper sums are nonnegative, the Riemann integral of $f\in\mathcal R([a,b])$ is also nonnegative:

$$
\int_a^bf(x)\,dx\geq0.
$$

This proves the first order property.

The second order property follows from the first. If $f(x)\geq g(x)$ for all $x\in[a,b]$, then

$$
f(x)-g(x)\geq0\qquad\text{for all }x\in[a,b].
$$

Apply the first property to $f-g$ and use linearity (Lemma 3.29(i)). We obtain

$$
\boxed{0\leq\int_a^b\big[f(x)-g(x)\big]\,dx
=\int_a^bf(x)\,dx-\int_a^bg(x)\,dx.}
\tag{3.54}
$$

---




## Supporting material

- [Exercises]({{ '/pages/mathematics/real_analysis/05-integral-calculus/02-riemann-integrability-and-properties/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/real_analysis/05-integral-calculus/02-riemann-integrability-and-properties/solutions/' | relative_url }})
- [References]({{ '/pages/mathematics/real_analysis/05-integral-calculus/02-riemann-integrability-and-properties/references/' | relative_url }})

## Subchapter navigation

[Previous: 5.1 - Riemann Integral and Darboux Sums]({{ '/pages/mathematics/real_analysis/05-integral-calculus/01-riemann-integral-and-darboux-sums/' | relative_url }})

[Back to Chapter 5: Integral Calculus]({{ '/pages/mathematics/real_analysis/05-integral-calculus/' | relative_url }})

[Next: 5.3 - Fundamental Theorem of Calculus]({{ '/pages/mathematics/real_analysis/05-integral-calculus/03-fundamental-theorem-of-calculus/' | relative_url }})

</article>

