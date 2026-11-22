---
layout: default
title: "8.2: Quadratic Variation and Covariation"
permalink: /pages/mathematics/stochastic_calculus/08-quadratic-variation-and-semimartingales/02-quadratic-variation-and-covariation/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/stochastic_calculus/08-quadratic-variation-and-semimartingales/02-quadratic-variation-and-covariation/' | relative_url }}">← Quadratic Variation and Covariation</a>
  <div class="eyebrow">Mathematics / Stochastic Calculus / 8.2</div>
  <h1>Quadratic Variation and Covariation</h1>
  <p class="lead">Placeholder topic for Quadratic Variation and Covariation. (TBD)</p>
</div>

<article class="article" markdown="1">

# 8.2. Quadratic Variation and Covariation

> **A second-order measure of roughness.** For a differentiable path, squared increments disappear when the observation intervals become small. For Brownian motion, their sum converges instead to elapsed time. This nonzero quadratic variation is the mathematical reason why Itô calculus differs from ordinary calculus.

This section starts with finite **sample quadratic variation** and **sample covariation** computed on partitions, proves that Brownian motion has quadratic variation $t$, and extends the construction to continuous local martingales and semimartingales. We distinguish first-order total variation from second-order variation, and connect sample calculations to continuous-time limits.

Throughout, $W$ is a standard Brownian motion on a filtered probability space $(\Omega,\mathcal F,(\mathcal F_t),\mathbb P)$. Unless indicated otherwise, all partitions below are deterministic and their mesh tends to zero.

---

## 8.2.1. Sample quadratic variation along a partition

**Definition 8.2.1 (Sample quadratic variation).** Let $x:[0,t]\to\mathbb R$ be a given continuous path, and let $\pi=\{0=t_0<\cdots<t_n=t\}$ be a partition. Set

$$
\boxed{Q_t^{\pi}(x):=\sum_{k=0}^{n-1}
\bigl(x(t_{k+1})-x(t_k)\bigr)^2
=\sum_{k=0}^{n-1}(\Delta_k x)^2.}
$$

This is a **realised**, or **sample**, sum: it can be calculated from finitely many observations without requiring a probability model.

If a sequence $\pi_m$ with $\|\pi_m\|\to0$ produces a limit, we call it a quadratic variation along that sequence. For stochastic processes the mode of convergence must be specified: in probability, in $L^2$, or almost surely.

**Definition 8.2.2 (Quadratic variation of a continuous process).** A continuous process $X$ admits quadratic variation $[X]$ when there is a continuous increasing process $[X]_t$, with $[X]_0=0$, such that its sampled quadratic-variation processes converge to $[X]$ in probability uniformly on compact time intervals, along the admissible refining partitions under consideration. In particular, at each fixed $t$,

$$
Q_t^{\pi_m}(X)\xrightarrow[m\to\infty]{\mathbb P}[X]_t.
$$

For continuous semimartingales this limit is canonical and independent of the deterministic partition sequence with vanishing mesh. Some authors write $\langle X\rangle$ instead of $[X]$ in the continuous setting. We use $[X]$ for quadratic variation and reserve $\langle M\rangle$ for the increasing predictable bracket of a continuous local martingale; then $[M]=\langle M\rangle$.

**Lemma 8.2.3 (Continuous finite-variation paths have zero quadratic variation).** If $x$ is continuous and $V_t(x)<\infty$, then

$$
\boxed{Q_t^\pi(x)\le
\left(\max_k|\Delta_k x|\right)V_t(x)
\xrightarrow[\|\pi\|\to0]{}0.}
$$

**Proof.** Factor one increment from each square and bound its absolute value by the largest increment:

$$
\sum_k(\Delta_k x)^2
\le\left(\max_k|\Delta_k x|\right)
\sum_k|\Delta_k x|
\le\omega_x(\|\pi\|)V_t(x),
$$

where $\omega_x(\delta)=\sup_{|u-v|\le\delta}|x(u)-x(v)|\to0$ by uniform continuity. $\square$

Thus **zero quadratic variation is necessary for continuous finite variation**, but the converse is false for general continuous paths.

---

## 8.2.2. The quadratic variation of Brownian motion

**Theorem 8.2.4 (Brownian quadratic variation).** For any fixed $t>0$ and any deterministic partitions $\pi_m$ of $[0,t]$ satisfying $\|\pi_m\|\to0$,

$$
\boxed{Q_t^{\pi_m}(W)
=\sum_{k}(W_{t_{k+1}}-W_{t_k})^2
\xrightarrow[m\to\infty]{L^2}t.}
$$

Consequently, $[W]_t=t$ and, formally, $d[W]_t=dt$.

**Proof (from independent Brownian increments).** Write

$$
D_k=W_{t_{k+1}}-W_{t_k},
\qquad
h_k=t_{k+1}-t_k.
$$

The increments $D_k$ are independent, $D_k\sim N(0,h_k)$. Therefore

$$
\mathbb E[D_k^2]=h_k,
\qquad
\mathbb E[D_k^4]=3h_k^2,
\qquad
\operatorname{Var}(D_k^2)=2h_k^2.
$$

First calculate the mean:

$$
\mathbb E[Q_t^\pi(W)]
=\sum_k\mathbb E[D_k^2]
=\sum_kh_k=t.
$$

Next, by independence, the cross terms in the variance vanish:

$$
\begin{aligned}
\mathbb E\left[\bigl(Q_t^\pi(W)-t\bigr)^2\right]
&=\operatorname{Var}\left(\sum_kD_k^2\right)\\
&=\sum_k\operatorname{Var}(D_k^2)\\
&=2\sum_k h_k^2\\
&\le 2\|\pi\|\sum_kh_k
=2t\|\pi\|\longrightarrow0.
\end{aligned}
$$

This is exactly $L^2$ convergence. $\square$

**Corollary 8.2.5 (Almost-sure dyadic quadratic variation).** For the dyadic partition $t_k^{(m)}=kt/2^m$,

$$
\sum_{k=0}^{2^m-1}
\bigl(W_{(k+1)t/2^m}-W_{kt/2^m}\bigr)^2
\longrightarrow t\quad\text{almost surely}.
$$

**Proof.** The preceding second-moment estimate becomes $2t^2/2^m$. For $\varepsilon>0$, Chebyshev's inequality gives

$$
\mathbb P\left(\left|Q_t^{\pi_m}(W)-t\right|>\varepsilon\right)
\le\frac{2t^2}{\varepsilon^2 2^m}.
$$

The sum over $m$ is finite. Borel–Cantelli implies that deviations exceeding any fixed rational $\varepsilon>0$ happen only finitely often; hence the limit holds almost surely. $\square$

**Remark 8.2.6 (Modes of convergence).** The $L^2$ result holds for arbitrary deterministic partitions with vanishing mesh. The almost-sure result just proved uses a special sequence (dyadic partitions). One must not infer almost-sure convergence for every arbitrary sequence merely from $L^2$ convergence.

**Corollary 8.2.7 (Nonrectifiable Brownian paths).** Almost surely, for every $t>0$,

$$
V_t(W)=\infty,
\qquad L_t(W)=\infty.
$$

**Proof.** Were a Brownian trajectory continuous and of finite variation, Lemma 8.2.3 would force the sampled quadratic variation to converge to zero along dyadic partitions. But Corollary 8.2.5 says it converges to $t>0$ almost surely. Hence the variation is infinite, and the Pythagorean arc-length inequalities of [§8.1](../01-functions-and-processes-of-finite-variation/) imply that the graph length is infinite. A countable argument over positive rational $t$ makes the conclusion simultaneous in $t$. $\square$

This establishes the apparent paradox: Brownian motion has **infinite first-order variation** but **finite and nonzero second-order variation**.

---

## 8.2.3. Sample covariation and the polarisation identity

**Definition 8.2.8 (Sample covariation).** For two observed paths $x,y$ and a common partition $\pi$, set

$$
\boxed{C_t^\pi(x,y):=\sum_{k=0}^{n-1}
\bigl(x(t_{k+1})-x(t_k)\bigr)
\bigl(y(t_{k+1})-y(t_k)\bigr).}
$$

The sum is symmetric and bilinear in its two arguments. It is not, in general, nonnegative.

**Proposition 8.2.9 (Sample polarisation).** For any sample paths $x,y$ and any partition,

$$
\boxed{C_t^\pi(x,y)=\frac12
\left(Q_t^\pi(x+y)-Q_t^\pi(x)-Q_t^\pi(y)\right).}
$$

Equivalently,

$$
C_t^\pi(x,y)=\frac14\left(Q_t^\pi(x+y)-Q_t^\pi(x-y)\right).
$$

**Proof.** Expand $(\Delta_kx+\Delta_ky)^2$ and sum over $k$. $\square$

**Definition 8.2.10 (Quadratic covariation).** For continuous semimartingales $X,Y$, the **quadratic covariation** (or *cross-variation*) is the limit

$$
\boxed{[X,Y]_t
=\lim_{\|\pi\|\to0}^{\mathbb P}
\sum_k\Delta_kX\,\Delta_kY
=\frac12\bigl([X+Y]_t-[X]_t-[Y]_t\bigr).}
$$

For continuous local martingales $M,N$ we also write $\langle M,N\rangle=[M,N]$. Unlike $[M]=[M,M]$, the cross-variation $[M,N]$ need not be increasing: it is a continuous finite-variation process.

**Proposition 8.2.11 (Sample Cauchy–Schwarz inequality).** On every partition,

$$
|C_t^\pi(x,y)|
\le\sqrt{Q_t^\pi(x)}\sqrt{Q_t^\pi(y)}.
$$

For continuous semimartingales, taking the limit gives

$$
\boxed{|[X,Y]_t|\le\sqrt{[X]_t[Y]_t}\quad\text{a.s.}}
$$

---

## 8.2.4. Worked sample quadratic variation and covariation

Suppose two trajectories are observed at the same four times $t_0,t_1,t_2,t_3$:

| $k$ | $X_{t_k}$ | $Y_{t_k}$ | $\Delta_{k-1}X$ | $\Delta_{k-1}Y$ |
|---:|---:|---:|---:|---:|
| $0$ | $0.0$ | $0.0$ | — | — |
| $1$ | $0.3$ | $0.2$ | $0.3$ | $0.2$ |
| $2$ | $0.1$ | $0.4$ | $-0.2$ | $0.2$ |
| $3$ | $0.5$ | $0.3$ | $0.4$ | $-0.1$ |

The finite-sample quadratic variations are

$$
\begin{aligned}
Q_{t_3}^{\pi}(X)&=0.3^2+(-0.2)^2+0.4^2=0.29,\\
Q_{t_3}^{\pi}(Y)&=0.2^2+0.2^2+(-0.1)^2=0.09.
\end{aligned}
$$

The sample covariation is

$$
\boxed{C_{t_3}^{\pi}(X,Y)
=(0.3)(0.2)+(-0.2)(0.2)+(0.4)(-0.1)=-0.02.}
$$

We may form the **realised correlation of increments**

$$
\rho_\pi^{\mathrm{real}}
=\frac{C_{t_3}^{\pi}(X,Y)}{
\sqrt{Q_{t_3}^{\pi}(X)Q_{t_3}^{\pi}(Y)}}
=\frac{-0.02}{\sqrt{0.29\cdot0.09}}\approx-0.124.
$$

This example is a **finite collection of observations**, not a proof of a continuous-time limit. In particular, $C_t^\pi$ is an *uncentred sum of increment products* and should not be confused with the sample covariance statistic using demeaned observations and division by $n-1$.

---

## 8.2.5. Covariation of Brownian motions

**Theorem 8.2.12 (Independent Brownian motions).** If $W$ and $B$ are independent standard Brownian motions, then for each $t\ge0$,

$$
\boxed{[W,B]_t=0.}
$$

**Proof.** Consider

$$
C_t^\pi(W,B)=\sum_kD_kE_k,
\quad D_k=\Delta_kW,\quad E_k=\Delta_kB.
$$

Each product has mean zero. Independence of Brownian increments and independence of $W$ and $B$ make cross terms vanish, hence

$$
\begin{aligned}
\mathbb E\left[(C_t^\pi(W,B))^2\right]
&=\sum_k\mathbb E[D_k^2]\mathbb E[E_k^2]\\
&=\sum_k(\Delta_kt)^2\\
&\le t\|\pi\|\longrightarrow0.
\end{aligned}
$$

Therefore the cross-increment sum converges to zero in $L^2$, and in probability. $\square$

**Proposition 8.2.13 (Correlated Brownian motions).** Let $W,B$ be independent Brownian motions and fix $\rho\in[-1,1]$. Define

$$
\widetilde W_t:=\rho W_t+\sqrt{1-\rho^2}\,B_t.
$$

Then $\widetilde W$ is a standard Brownian motion and

$$
\boxed{[W,\widetilde W]_t=\rho t.}
$$

**Proof.** The Gaussian increments of $\widetilde W$ are centred, independent over disjoint intervals, and have variance $(\rho^2+1-\rho^2)(t-s)=t-s$. The covariation follows by bilinearity:

$$
[W,\widetilde W]_t=\rho[W]_t+
\sqrt{1-\rho^2}[W,B]_t=\rho t.
$$

$\square$

**Proposition 8.2.14 (Covariation with time and finite variation).** If $A$ is continuous and of finite variation and $X$ is any continuous semimartingale, then

$$
\boxed{[A,X]_t=0,\qquad[A]_t=0.}
$$

**Proof.** For each sample path on $[0,t]$,

$$
\left|\sum_k\Delta_kA\,\Delta_kX\right|
\le\left(\max_k|\Delta_kX|\right)V_t(A)\to0,
$$

by continuity of $X$. In particular $[t,W]_t=0$ and $[t]_t=0$. $\square$

---

## 8.2.6. Quadratic variation of continuous local martingales

**Definition 8.2.15 (Continuous local martingale).** An adapted continuous process $M$ is a local martingale if there exists a sequence of stopping times $\tau_n\uparrow\infty$ almost surely such that $M^{\tau_n}_t=M_{t\wedge\tau_n}$ is a martingale for every $n$.

**Theorem 8.2.16 (The martingale bracket).** For a continuous local martingale $M$ there exists a unique (up to indistinguishability) continuous adapted increasing process $\langle M\rangle$ starting at zero such that

$$
\boxed{M_t^2-\langle M\rangle_t
\quad\text{is a continuous local martingale}.}
$$

Furthermore the quadratic-increment sums converge in probability to $\langle M\rangle$ as the deterministic partition mesh vanishes:

$$
\sum_k(M_{t_{k+1}}-M_{t_k})^2
\xrightarrow{\mathbb P}\langle M\rangle_t.
$$

**Proof of uniqueness.** If increasing processes $A$ and $B$ both have the asserted property, their difference

$$
A-B=(M^2-B)-(M^2-A)
$$

is a continuous local martingale of finite variation starting at zero. Such a process is indistinguishable from zero (a consequence of the local-martingale finite-variation theorem). Hence $A=B$. Existence is obtained by localising $M$ to bounded martingales and taking limits of the discrete quadratic-increment sums; the $L^2$ estimates and Doob's inequality control convergence on compact intervals. $\square$

**Corollary 8.2.17 (Second moments and the bracket).** For a square-integrable martingale $M$ with $M_0=0$, when the stopped/martingale identities have the necessary integrability,

$$
\mathbb E[M_t^2]=\mathbb E[\langle M\rangle_t].
$$

If $M$ is bounded in $L^2$ on the entire horizon, then

$$
\mathbb E[M_\infty^2]=\mathbb E[\langle M\rangle_\infty].
$$

This identity is the geometric foundation of the **Itô isometry**.

**Theorem 8.2.18 (Bracket covariation).** For continuous local martingales $M,N$, there is a unique continuous finite-variation process $\langle M,N\rangle$, characterised by

$$
\boxed{M_tN_t-\langle M,N\rangle_t
\quad\text{being a local martingale},}
$$

and given by polarisation:

$$
\langle M,N\rangle_t
=\frac12\left(\langle M+N\rangle_t-\langle M\rangle_t-\langle N\rangle_t\right).
$$

The equality above remains true for nonzero initial values because the extra terms in $M_tN_t$ are (local) martingale terms.

**Remark 8.2.19 (Kunita–Watanabe inequality).** For continuous local martingales $M,N$ and suitable measurable $H,K$,

$$
\int_0^t|H_sK_s|\,|d\langle M,N\rangle_s|
\le\left(\int_0^tH_s^2\,d\langle M\rangle_s\right)^{1/2}
\left(\int_0^tK_s^2\,d\langle N\rangle_s\right)^{1/2}.
$$

It extends the sample Cauchy–Schwarz inequality to covariation measures and will ensure that stochastic integrals against different martingales have well-defined cross-variations.

---

## 8.2.7. Quadratic variation of continuous semimartingales

**Definition 8.2.20 (Continuous semimartingale).** A continuous adapted process $X$ is a continuous semimartingale when it can be decomposed as

$$
X_t=X_0+M_t+A_t,
$$

where $M$ is a continuous local martingale with $M_0=0$ and $A$ is a continuous adapted finite-variation process with $A_0=0$.

**Theorem 8.2.21 (Only the martingale part contributes).** If $X=X_0+M+A$ and $Y=Y_0+N+C$ are continuous semimartingales, then

$$
\boxed{[X]_t=\langle M\rangle_t,
\qquad[X,Y]_t=\langle M,N\rangle_t.}
$$

**Proof.** Expand the sample sums:

$$
Q_t^\pi(X)=\sum_k(\Delta_kM)^2
+2\sum_k\Delta_kM\,\Delta_kA
+\sum_k(\Delta_kA)^2.
$$

The last two terms tend to zero by the continuous finite-variation estimates in Propositions 8.2.3 and 8.2.14; the first converges to $\langle M\rangle_t$. Apply polarisation to obtain the corresponding covariation identity. $\square$

**Example 8.2.22 (Quadratic variation of an Itô process).** Suppose

$$
dX_t=a_t\,dt+b_t\,dW_t,
$$

where $a$ is locally integrable and $b$ is locally square-integrable. Then

$$
\boxed{[X]_t=\int_0^t b_s^2\,ds.}
$$

For two processes driven by the same Brownian motion,

$$
dX_t=a_t\,dt+b_t\,dW_t,
\qquad
dY_t=c_t\,dt+d_t\,dW_t,
$$

we obtain

$$
\boxed{[X,Y]_t=\int_0^t b_sd_s\,ds.}
$$

These identities will be proved directly in [§9.1](../../09-stochastic-integration/01-construction-of-the-ito-integral/) and revisited for general martingale drivers in [§9.2](../../09-stochastic-integration/02-stochastic-integration-with-martingales/).

---

## 8.2.8. The differential multiplication table

For a one-dimensional Brownian motion the rigorous bracket identities are often written formally as

$$
\boxed{(dW_t)^2=dt,\qquad dW_t\,dt=0,\qquad(dt)^2=0.}
$$

For independent components $W^1,\ldots,W^d$ of a standard $d$-dimensional Brownian motion,

$$
dW_t^k\,dW_t^\ell=\delta_{k\ell}\,dt,
\qquad k,\ell\in\{1,\ldots,d\}.
$$

For correlated Brownian motions, replace $\delta_{k\ell}$ by the instantaneous covariance $\rho_{k\ell}$. These are **mnemonics for quadratic and cross-variation**, not ordinary algebra with infinitesimal quantities.


- [Exercises]({{ '/pages/mathematics/stochastic_calculus/08-quadratic-variation-and-semimartingales/02-quadratic-variation-and-covariation/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/stochastic_calculus/08-quadratic-variation-and-semimartingales/02-quadratic-variation-and-covariation/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/stochastic_calculus/08-quadratic-variation-and-semimartingales/02-quadratic-variation-and-covariation/references/' | relative_url }})

[Back to Quadratic Variation and Semimartingales]({{ '/pages/mathematics/stochastic_calculus/08-quadratic-variation-and-semimartingales/' | relative_url }})

</article>
