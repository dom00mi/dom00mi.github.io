---
layout: default
title: "8.1: Functions and Processes of Finite Variation"
description: "Total variation, graph arc length, Jordan decomposition, Lebesgue–Stieltjes integration, and continuous finite-variation processes."
math: true
permalink: /pages/mathematics/stochastic_calculus/08-quadratic-variation-and-semimartingales/01-functions-and-processes-of-finite-variation/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/stochastic_calculus/08-quadratic-variation-and-semimartingales/' | relative_url }}">← Quadratic Variation and Semimartingales</a>
  <div class="eyebrow">Mathematics / Stochastic Calculus / 8.1</div>
  <h1>Functions and Processes of Finite Variation</h1>
</div>

<article class="article" markdown="1">

# 8.1. Functions and Processes of Finite Variation

> **The first geometric distinction in stochastic calculus.** A continuous trajectory may be perfectly well defined without admitting a derivative or having finite length. Distinguishing finite-variation paths from genuinely irregular paths explains why integration against Brownian motion requires new ideas.

In classical analysis, the length of a curve and the integral against a regular function are controlled by the function's **total variation**. Here we develop the deterministic theory, extend it to adapted stochastic processes, and identify the precise obstruction presented by Brownian motion. The geometric argument using the Pythagorean theorem will connect this section directly with [quadratic variation](../02-quadratic-variation-and-covariation/).

Throughout, $T>0$ is finite and $f:[0,T]\to\mathbb R$ is real valued. When considering stochastic processes we work on a filtered probability space $(\Omega,\mathcal F,(\mathcal F_t)_{t\ge0},\mathbb P)$ satisfying the usual conditions.

---

## 8.1.1. Partitions and total variation

**Definition 8.1.1 (Partition and mesh).** A partition $\pi$ of $[0,t]$ is a finite collection

$$
\pi=\{0=t_0<t_1<\cdots<t_n=t\}.
$$

Its **mesh** is

$$
\|\pi\|:=\max_{0\le k<n}(t_{k+1}-t_k).
$$

We write $\Delta_k f=f(t_{k+1})-f(t_k)$ and $\Delta_k t=t_{k+1}-t_k$.

**Definition 8.1.2 (Total variation).** For a function $f:[0,T]\to\mathbb R$, define

$$
V_t(f):=\sup_{\pi\text{ partition of }[0,t]}
\sum_{k=0}^{n-1}|\Delta_k f|,\qquad 0\le t\le T.
$$

We say that $f$ has **finite variation** on $[0,T]$ if $V_T(f)<\infty$. A function on $[0,\infty)$ is *locally of finite variation* if $V_T(f)<\infty$ for every finite $T$; it has *globally bounded variation* if $\sup_{T\ge0}V_T(f)<\infty$.

**Proposition 8.1.3 (Elementary properties).** For real-valued $f,g$ and scalars $a,b$,

$$
\begin{aligned}
V_t(f)&\ge |f(t)-f(0)|,\\
V_t(af+bg)&\le |a|V_t(f)+|b|V_t(g),\\
V_t(f)&\le V_s(f)+V_{[s,t]}(f),\qquad 0\le s\le t,
\end{aligned}
$$

where the last expression is in fact an equality for the appropriate interval-variation convention. Moreover $t\mapsto V_t(f)$ is nondecreasing.

**Proof.** The first inequality follows from the partition $\{0,t\}$. The second uses the triangle inequality term by term in each partition, followed by the supremum. For the interval decomposition, insert $s$ into a partition and then concatenate nearly optimal partitions on $[0,s]$ and $[s,t]$. $\square$

**Examples 8.1.4.**

- If $f$ is continuously differentiable, then $V_t(f)=\int_0^t|f'(s)|\,ds$.
- If $f$ is increasing, then $V_t(f)=f(t)-f(0)$.
- For $f(t)=\sin t$ on $[0,2\pi]$, $V_{2\pi}(f)=4$.
- A continuous function can be uniformly continuous and nevertheless have infinite variation; Brownian sample paths provide the central probabilistic example.

---

## 8.1.2. Graph length and the Pythagorean argument

Consider the graph of $f$, parametrised by

$$
\gamma(s)=(s,f(s)),\qquad 0\le s\le t.
$$

The chord joining two successive points $\gamma(t_k)$ and $\gamma(t_{k+1})$ has horizontal displacement $\Delta_k t$ and vertical displacement $\Delta_k f$. By the **Pythagorean theorem**, its length is

$$
\ell_k=\sqrt{(\Delta_k t)^2+(\Delta_k f)^2}.
$$

This is precisely the right-triangle construction suggested by the arc-length sketch: the horizontal and vertical legs bound the sloping chord.

**Definition 8.1.5 (Length of the graph).** The polygonal approximation associated with $\pi$ has length

$$
L_\pi(f;[0,t])
:=\sum_{k=0}^{n-1}\sqrt{(\Delta_k t)^2+(\Delta_k f)^2}.
$$

The rectifiable length of the graph is

$$
L_t(f):=\sup_\pi L_\pi(f;[0,t]),
$$

which may be infinite.

**Theorem 8.1.6 (Finite arc length if and only if finite variation).** For every real-valued function $f$,

$$
\boxed{V_t(f)\le L_t(f)\le t+V_t(f).}
$$

Consequently, $L_t(f)<\infty$ exactly when $V_t(f)<\infty$.

**Proof.** On each interval of a partition, the triangle with legs $|\Delta_k t|$ and $|\Delta_k f|$ satisfies

$$
|\Delta_k f|
\le\sqrt{(\Delta_k t)^2+(\Delta_k f)^2}
\le\Delta_k t+|\Delta_k f|.
$$

Summing yields

$$
\sum_k|\Delta_k f|
\le L_\pi(f;[0,t])
\le\sum_k\Delta_k t+\sum_k|\Delta_k f|
=t+\sum_k|\Delta_k f|.
$$

Taking suprema over all partitions proves both inequalities. $\square$

**Interpretation.** The continuous graph of a Brownian path has *infinite length* because the path has infinite total variation. Its vertical oscillations cannot be controlled by any finite total variation, although its quadratic variation will turn out to be finite.

---

## 8.1.3. Jordan decomposition of finite-variation functions

**Theorem 8.1.7 (Jordan decomposition).** Suppose $f$ is of finite variation on compact intervals and $f(0)=0$. Then there exist two nondecreasing functions $f^+$ and $f^-$ such that

$$
f(t)=f^+(t)-f^-(t).
$$

A canonical choice is

$$
\boxed{f^+(t)=\frac{V_t(f)+f(t)}{2},\qquad
f^-(t)=\frac{V_t(f)-f(t)}{2}.}
$$

Conversely, the difference of two nondecreasing functions has finite variation on every compact interval.

**Proof.** For $0\le s<t$, the variation over $[s,t]$ dominates $|f(t)-f(s)|$, so

$$
V_t(f)-V_s(f)\ge|f(t)-f(s)|.
$$

Thus

$$
\begin{aligned}
f^+(t)-f^+(s)
&=\tfrac12\bigl(V_t(f)-V_s(f)+f(t)-f(s)\bigr)\ge0,\\
f^-(t)-f^-(s)
&=\tfrac12\bigl(V_t(f)-V_s(f)-f(t)+f(s)\bigr)\ge0.
\end{aligned}
$$

Both are nondecreasing, and their difference is $f$. Conversely, if $f=u-v$ with $u,v$ nondecreasing, then

$$
V_t(f)\le u(t)-u(0)+v(t)-v(0)<\infty.
$$

$\square$

When $f(0)\ne0$, apply the theorem to $f(t)-f(0)$ and retain the initial constant.

**Remark 8.1.8 (Signed measures).** A right-continuous function $f$ of locally finite variation with $f(0)=0$ determines a locally finite signed Stieltjes measure $df$ on $(0,\infty)$ through

$$
df((s,t])=f(t)-f(s).
$$

Its Jordan decomposition is $df=df^+-df^-$, and its total-variation measure satisfies

$$
|df|((0,t])=V_t(f).
$$

For a *continuous* finite-variation function, the measure $df$ has no atoms; for a function with jumps, $df(\{s\})=\Delta f_s$.

---

## 8.1.4. Integration with respect to a finite-variation path

**Definition 8.1.9 (Lebesgue–Stieltjes integral).** Let $f$ be right-continuous and of finite variation and let $h$ be measurable with

$$
\int_0^t|h(s)|\,|df|(ds)<\infty.
$$

The integral against $f$ is defined by

$$
\boxed{\int_0^t h(s)\,df(s)
=\int_{(0,t]}h(s)\,df^+(s)
-\int_{(0,t]}h(s)\,df^-(s).}
$$

This is an ordinary integral against a signed measure, constructed **pathwise**; no probabilistic limiting procedure is needed.

**Proposition 8.1.10 (Variation bound and stability).** If $G_t=\int_0^t h(s)\,df(s)$, then

$$
\left|\int_0^t h(s)\,df(s)\right|
\le\int_0^t|h(s)|\,|df|(ds),
\qquad
V_t(G)\le\int_0^t|h(s)|\,|df|(ds).
$$

In particular, $G$ is a finite-variation function.

**Proposition 8.1.11 (Associativity).** Whenever the integrals are well defined,

$$
\int_0^t g(s)\,d\left(\int_0^s h(u)\,df(u)\right)
=\int_0^t g(s)h(s)\,df(s).
$$

**Proposition 8.1.12 (Classical chain and product rules).** If $f,g$ are continuous finite-variation functions and $\Phi\in C^1(\mathbb R)$, then

$$
\Phi(f(t))-\Phi(f(0))
=\int_0^t\Phi'(f(s))\,df(s),
$$

and

$$
\boxed{f(t)g(t)-f(0)g(0)
=\int_0^t f(s)\,dg(s)+\int_0^t g(s)\,df(s).}
$$

**Proof of the product identity.** For any partition, expand

$$
\Delta_k(fg)
=f(t_k)\Delta_k g+g(t_k)\Delta_k f
+(\Delta_k f)(\Delta_k g).
$$

The final term disappears when the mesh tends to zero because, by continuity,

$$
\left|\sum_k(\Delta_k f)(\Delta_k g)\right|
\le\left(\max_k|\Delta_k f|\right)V_t(g)
\longrightarrow0.
$$

The remaining sums converge to the Lebesgue–Stieltjes integrals and telescope to the product difference. $\square$

The vanishing of this **cross-increment sum** will fail for two general continuous martingales. This is precisely why stochastic integration by parts requires a covariation term.

---

## 8.1.5. Finite-variation stochastic processes

**Definition 8.1.13 (Process of finite variation).** An adapted process $A=(A_t)_{t\ge0}$ with right-continuous paths is a finite-variation process if, outside a single null set, each trajectory $t\mapsto A_t(\omega)$ has finite variation on compact time intervals. We frequently take $A_0=0$.

If $A$ is continuous and adapted, then its variation process

$$
V_t(A)(\omega):=\sup_\pi\sum_k|A_{t_{k+1}}(\omega)-A_{t_k}(\omega)|
$$

is continuous, nondecreasing and adapted. In particular, continuous finite-variation processes are predictable.

**Definition 8.1.14 (Integral against a finite-variation process).** For a progressively measurable $H$ satisfying

$$
\int_0^t|H_s|\,|dA_s|<\infty\quad\text{almost surely for every }t,
$$

we define $H\cdot A$ by the pathwise Stieltjes integral

$$
(H\cdot A)_t:=\int_0^tH_s\,dA_s.
$$

The process $H\cdot A$ is adapted and of finite variation. It is continuous when $A$ is continuous.

**Proposition 8.1.15 (Stopping and associativity).** If $\tau$ is a stopping time, write $A^\tau_t=A_{t\wedge\tau}$. Under the stated integrability assumptions,

$$
\begin{aligned}
\int_0^{t\wedge\tau}H_s\,dA_s
&=\int_0^tH_s\,dA_s^\tau
=\int_0^tH_s\mathbf1_{\{s\le\tau\}}\,dA_s,\\
\int_0^tK_s\,d(H\cdot A)_s
&=\int_0^tK_sH_s\,dA_s.
\end{aligned}
$$

For continuous $A$, the inclusion or exclusion of a single endpoint does not change the integral.

---

## 8.1.6. Why Brownian motion lies outside the finite-variation theory

Ordinary Riemann–Stieltjes integration is straightforward when the integrator has finite variation. Brownian motion $W$, however, satisfies the opposite behaviour.

**Theorem 8.1.16 (Brownian trajectories have infinite variation and length).** For every $t>0$,

$$
\mathbb P\bigl(V_t(W)=\infty\bigr)=1,
\qquad
\mathbb P\bigl(L_t(W)=\infty\bigr)=1.
$$

Moreover, there is a single event of probability one on which these properties hold simultaneously for every $t>0$.

**Proof.** In the next section we establish directly from Brownian increments that for any sequence of deterministic partitions with mesh tending to zero,

$$
\sum_{k}(W_{t_{k+1}}-W_{t_k})^2\longrightarrow t
\quad\text{in }L^2(\mathbb P).
$$

If a continuous sample path $w$ has finite variation, then for any such partitions,

$$
\sum_k(\Delta_kw)^2
\le\underbrace{\max_k|\Delta_kw|}_{\longrightarrow0}
\underbrace{\sum_k|\Delta_kw|}_{\le V_t(w)}
\longrightarrow0.
$$

The convergence in probability to $t>0$ is incompatible with convergence to zero on an event of positive probability: applying a subsequence that converges almost surely, or using convergence in probability on that event, shows $\mathbb P(V_t(W)<\infty)=0$. By Theorem 8.1.6 the graph also has infinite length. Applying this result to all positive rational times and using monotonicity of variation proves the simultaneous assertion. $\square$

**Consequence.** The classical pathwise Stieltjes integral against $dW_t$ cannot be used for arbitrary integrands. In [Chapter 9](../../09-stochastic-integration/01-construction-of-the-ito-integral/), we will replace the pathwise finite-variation construction with an $L^2$ limit of *left-adapted* random sums.

---

## 8.1.7. Summary and transition

The central deterministic facts are

$$
\boxed{
\begin{gathered}
V_t(f)=\sup_\pi\sum_k|\Delta_kf|,\\
V_t(f)\le L_t(f)\le t+V_t(f),\\
f=f^+-f^-,\\
\int_0^t h\,df\quad\text{is defined pathwise for finite-variation }f.
\end{gathered}}
$$

For continuous finite-variation paths, products and compositions obey classical calculus. Brownian motion, by contrast, has infinite variation yet *nonzero finite quadratic variation*. Quantifying this second-order behaviour is our next task.

**Next:** [8.2 — Quadratic Variation and Covariation](../02-quadratic-variation-and-covariation/).


- [Exercises]({{ '/pages/mathematics/stochastic_calculus/08-quadratic-variation-and-semimartingales/01-functions-and-processes-of-finite-variation/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/stochastic_calculus/08-quadratic-variation-and-semimartingales/01-functions-and-processes-of-finite-variation/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/stochastic_calculus/08-quadratic-variation-and-semimartingales/01-functions-and-processes-of-finite-variation/references/' | relative_url }})

[Back to Quadratic Variation and Semimartingales]({{ '/pages/mathematics/stochastic_calculus/08-quadratic-variation-and-semimartingales/' | relative_url }})

</article>
