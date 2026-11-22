---
layout: default
title: "9.1: Construction of the Ito Integral"
permalink: /pages/mathematics/stochastic_calculus/09-stochastic-integration/01-construction-of-the-ito-integral/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/01-construction-of-the-ito-integral/' | relative_url }}">← Construction of the Ito Integral</a>
  <div class="eyebrow">Mathematics / Stochastic Calculus / 9.1</div>
  <h1>Construction of the Ito Integral</h1>
  <p class="lead">Placeholder topic for Construction of the Ito Integral. (TBD)</p>
</div>

<article class="article" markdown="1">

# 9.1. Construction of the Itô Integral

> **From left-endpoint sums to a new integral.** Since Brownian trajectories have infinite total variation, integration with respect to Brownian motion is not obtained by treating the Brownian path as an ordinary finite-variation integrator. Instead, we construct an integral for simple *adapted* integrands and extend it by the geometry of $L^2$.

The preceding chapter showed that Brownian motion $W$ has

$$
[W]_t=t,
\qquad
V_t(W)=\infty\quad\text{almost surely for }t>0.
$$

Here we construct $\int_0^t H_s\,dW_s$, prove its martingale properties and the **Itô isometry**, establish its quadratic variation, and then extend the integral from elementary processes to general square-integrable adapted integrands.

Fix $T>0$ and a filtered probability space $(\Omega,\mathcal F,(\mathcal F_t)_{0\le t\le T},\mathbb P)$ carrying Brownian motion $W$. We assume the usual conditions, and $W_t-W_s$ is independent of $\mathcal F_s$ for $s<t$.

---

## 9.1.1. Why the classical integral is insufficient

For a smooth deterministic function $f$, the integral against $f$ can be written as

$$
\int_0^t H_s\,df(s)=\int_0^tH_sf'(s)\,ds.
$$

The right-hand side requires a derivative; alternatively, a continuous finite-variation integrator admits a Lebesgue–Stieltjes measure $df$. Brownian motion almost surely satisfies neither regularity requirement.

A natural replacement is a limit of sums

$$
S_\pi(t):=\sum_{k=0}^{n-1}
H_{t_k}\bigl(W_{t_{k+1}\wedge t}-W_{t_k\wedge t}\bigr),
$$

where the coefficient $H_{t_k}$ is known at the **left endpoint** of the increment. This requirement is fundamental: it expresses the principle that the integrand cannot anticipate future Brownian noise.

The construction first gives meaning to these sums for a finite number of intervals. The limiting procedure is then performed in a probabilistic function space, rather than sample path by sample path.

---

## 9.1.2. The Hilbert space of admissible integrands

**Definition 9.1.1 (Square-integrable Brownian integrands).** The space $\mathcal H_T^2(W)$ consists of equivalence classes of progressively measurable real-valued processes $H$ satisfying

$$
\boxed{\|H\|_{\mathcal H_T^2(W)}^2
:=\mathbb E\left[\int_0^T H_s^2\,ds\right]<\infty.}
$$

Two processes are identified if they agree for $ds\otimes d\mathbb P$-almost every $(s,\omega)$. The inner product is

$$
\langle H,K\rangle_{\mathcal H_T^2(W)}
=\mathbb E\left[\int_0^TH_sK_s\,ds\right].
$$

The space is a Hilbert space. On a finite horizon we may also work with the locally square-integrable class when only $\int_0^tH_s^2ds<\infty$ almost surely is available; this will be treated in the next subchapter.

**Remark 9.1.2 (Adapted versus progressively measurable).** Adaptedness means $H_t$ is $\mathcal F_t$-measurable for each fixed $t$. Progressive measurability additionally requires the restriction $(s,\omega)\mapsto H_s(\omega)$ on $[0,t]\times\Omega$ to be $\mathcal B([0,t])\otimes\mathcal F_t$-measurable. The latter supplies the joint measurability needed for integration. All adapted continuous processes are progressive.

---

## 9.1.3. Elementary adapted processes

**Definition 9.1.3 (Elementary integrand).** Fix $0=t_0<t_1<\cdots<t_n=T$ and let $\xi_k$ be a square-integrable $\mathcal F_{t_k}$-measurable random variable. An elementary process is

$$
\boxed{H_s=\sum_{k=0}^{n-1}\xi_k\mathbf1_{(t_k,t_{k+1}]}(s),
\qquad 0\le s\le T.}
$$

For certain approximation arguments it is convenient to begin with bounded $\xi_k$ and later remove the bound by truncation. Notice that each coefficient is chosen **before** observing the corresponding Brownian increment.

**Definition 9.1.4 (Integral of an elementary process).** For $H$ as above, define the Itô integral process

$$
\boxed{I_t=(H\cdot W)_t
:=\int_0^tH_s\,dW_s
=\sum_{k=0}^{n-1}\xi_k
\bigl(W_{t\wedge t_{k+1}}-W_{t\wedge t_k}\bigr),
\quad 0\le t\le T.}
$$

The integral is continuous and adapted, with $I_0=0$. In particular,

$$
I_T=\sum_{k=0}^{n-1}\xi_k(W_{t_{k+1}}-W_{t_k}).
$$

**Proposition 9.1.5 (Linearity).** If $H,K$ are elementary and $a,b\in\mathbb R$, then

$$
\int_0^t(aH_s+bK_s)\,dW_s
=a\int_0^tH_s\,dW_s+b\int_0^tK_s\,dW_s.
$$

**Proof.** Refine the two elementary partitions to a common partition. The assertion then follows directly from linearity of the finite sum defining the integral. $\square$

---

## 9.1.4. Why the Itô integral is a martingale

**Theorem 9.1.6 (Martingale property for elementary integrands).** For an elementary $H\in\mathcal H_T^2(W)$, $I_t=\int_0^tH_s\,dW_s$ is a continuous square-integrable martingale, and

$$
\mathbb E[I_t]=0,
\qquad
\mathbb E[I_t\mid\mathcal F_s]=I_s,
\quad 0\le s\le t\le T.
$$

**Proof.** Consider one elementary term $\xi_k(W_{t\wedge t_{k+1}}-W_{t\wedge t_k})$. If $s\le t_k$, the conditional expectation of its increment after $s$ is zero because $\xi_k$ is $\mathcal F_{t_k}$-measurable and the Brownian increment after $t_k$ has conditional mean zero. If $t_k<s<t_{k+1}$, decompose the Brownian increment into its known part up to $s$ and the independent mean-zero increment after $s$. Terms with $t_{k+1}\le s$ are already $\mathcal F_s$-measurable. Summing gives

$$
\mathbb E[I_t-I_s\mid\mathcal F_s]=0.
$$

Square integrability follows from the isometry proved below. $\square$

The crucial identity here is the **conditional centring** of future increments, not a pathwise cancellation.

---

## 9.1.5. Itô isometry for elementary processes

**Theorem 9.1.7 (Itô isometry).** For an elementary $H$,

$$
\boxed{\mathbb E\left[\left(\int_0^tH_s\,dW_s\right)^2\right]
=\mathbb E\left[\int_0^tH_s^2\,ds\right],
\quad 0\le t\le T.}
$$

**Proof.** First take $t=T$ and write

$$
D_k=W_{t_{k+1}}-W_{t_k},
\qquad
I_T=\sum_{k=0}^{n-1}\xi_kD_k.
$$

Expanding the square gives

$$
I_T^2=\sum_{k=0}^{n-1}\xi_k^2D_k^2
+2\sum_{0\le k<\ell<n}\xi_k\xi_\ell D_kD_\ell.
$$

For $k<\ell$, the product $\xi_k\xi_\ell D_k$ is $\mathcal F_{t_\ell}$-measurable, whereas $\mathbb E[D_\ell\mid\mathcal F_{t_\ell}]=0$. Thus

$$
\mathbb E[\xi_k\xi_\ell D_kD_\ell]
=\mathbb E\left[\xi_k\xi_\ell D_k
\mathbb E[D_\ell\mid\mathcal F_{t_\ell}]\right]=0.
$$

For the diagonal terms, $\xi_k$ is $\mathcal F_{t_k}$-measurable and Brownian increment variance is $t_{k+1}-t_k$, hence

$$
\mathbb E[\xi_k^2D_k^2]
=\mathbb E\left[\xi_k^2
\mathbb E[D_k^2\mid\mathcal F_{t_k}]\right]
=\mathbb E[\xi_k^2](t_{k+1}-t_k).
$$

Therefore

$$
\begin{aligned}
\mathbb E[I_T^2]
&=\sum_k\mathbb E[\xi_k^2](t_{k+1}-t_k)\\
&=\mathbb E\left[\sum_k\xi_k^2(t_{k+1}-t_k)\right]\\
&=\mathbb E\left[\int_0^TH_s^2\,ds\right].
\end{aligned}
$$

The same argument works at $t<T$ by replacing each interval with its intersection with $[0,t]$. $\square$

**Corollary 9.1.8 (Centredness and variance).** Since $\mathbb E[I_t]=0$,

$$
\operatorname{Var}(I_t)
=\mathbb E\left[\int_0^tH_s^2\,ds\right].
$$

In addition, Cauchy–Schwarz yields

$$
\mathbb E|I_t|
\le\left(\mathbb E\int_0^tH_s^2\,ds\right)^{1/2}<\infty.
$$

**Corollary 9.1.9 (Polarised isometry).** For elementary $H,K$,

$$
\boxed{\mathbb E\left[\left(\int_0^tH_s\,dW_s\right)
\left(\int_0^tK_s\,dW_s\right)\right]
=\mathbb E\left[\int_0^tH_sK_s\,ds\right].}
$$

**Proof.** Apply the isometry to $H+K$, expand both squares, and subtract the separate isometry identities for $H$ and $K$. $\square$

---

## 9.1.6. Quadratic variation of an elementary Itô integral

**Theorem 9.1.10 (Quadratic variation of a simple Itô integral).** If

$$
I_t=\int_0^tH_s\,dW_s,
\qquad H_s=\sum_k\xi_k\mathbf1_{(t_k,t_{k+1}]}(s),
$$

then

$$
\boxed{[I]_t=\int_0^tH_s^2\,ds,
\qquad I_t^2-\int_0^tH_s^2\,ds
\text{ is a martingale}.}
$$

**Proof.** On $(t_k,t_{k+1}]$ the process satisfies $I_s-I_{t_k}=\xi_k(W_s-W_{t_k})$. The sample quadratic-increment sum on that interval is $\xi_k^2$ times the Brownian quadratic-increment sum. By the Brownian quadratic-variation theorem, its limit is $\xi_k^2(s-t_k)$, and adding the intervals yields $[I]_t=\int_0^tH_s^2ds$.

For the martingale identity, one may instead compute conditional expectations directly: the increments of

$$
I_t^2-\int_0^tH_s^2\,ds
$$

have zero conditional expectation because $I$ is a martingale and its conditional second moments are exactly the elapsed integral of $H^2$ by conditional Itô isometry. $\square$

For two elementary integrals $I=\int H\,dW$ and $J=\int K\,dW$, polarisation gives

$$
\boxed{[I,J]_t=\int_0^tH_sK_s\,ds.}
$$

The isometry and the quadratic-variation identity are related but not identical: **isometry is an expectation identity; quadratic variation is a process-level path property**.

---

## 9.1.7. Approximation by elementary integrands

**Theorem 9.1.11 (Density of elementary processes).** For every $H\in\mathcal H_T^2(W)$ there exists a sequence of elementary adapted integrands $H^{(m)}$ such that

$$
\boxed{\lim_{m\to\infty}
\mathbb E\left[\int_0^T|H_s^{(m)}-H_s|^2\,ds\right]=0.}
$$

**Explanation of the construction.** First truncate $H$ so that it is bounded. Approximate it in the product-measure space by time-step processes whose coefficients are observable at the start of each interval, using predictable approximations (or one-sided time averages followed by suitable simple approximations). Finally remove the truncation. This is a density statement in $L^2(ds\otimes d\mathbb P)$, rather than pointwise convergence of arbitrary sample paths.

**Definition 9.1.12 (Itô integral of a general square-integrable process).** Choose elementary $H^{(m)}\to H$ in $\mathcal H_T^2(W)$ and define

$$
\boxed{\int_0^tH_s\,dW_s
:=\lim_{m\to\infty}^{L^2(\mathbb P)}
\int_0^tH_s^{(m)}\,dW_s.}
$$

**Theorem 9.1.13 (Existence, uniqueness and isometry).** This limit exists, is independent of the approximating sequence, and satisfies

$$
\boxed{\mathbb E\left[\left(\int_0^tH_s\,dW_s\right)^2\right]
=\mathbb E\left[\int_0^tH_s^2\,ds\right].}
$$

**Proof.** The elementary isometry gives

$$
\begin{aligned}
&\mathbb E\left[\left|\int_0^t(H_s^{(m)}-H_s^{(r)})\,dW_s\right|^2\right]\\
&\hspace{30mm}=\mathbb E\left[\int_0^t|H_s^{(m)}-H_s^{(r)}|^2\,ds\right]\longrightarrow0.
\end{aligned}
$$

Thus the integrals form a Cauchy sequence in the complete space $L^2(\Omega)$. If $K^{(m)}$ is another approximation, apply the same estimate to $H^{(m)}-K^{(m)}$; the difference of the candidate limits is zero. Taking limits on both sides of the elementary isometry establishes the general identity. $\square$

**Theorem 9.1.14 (Continuous martingale version).** There is a continuous modification of the process $I_t=\int_0^tH_s\,dW_s$, and this version is a square-integrable martingale. Moreover, Doob's inequality and the isometry yield

$$
\boxed{\mathbb E\left[\sup_{0\le s\le T}|I_s|^2\right]
\le4\mathbb E\left[\int_0^TH_s^2\,ds\right].}
$$

**Proof.** For elementary approximants, the processes are continuous martingales. Doob's maximal $L^2$ inequality gives

$$
\mathbb E\sup_{s\le T}|I_s^{(m)}-I_s^{(r)}|^2
\le4\mathbb E\int_0^T|H_s^{(m)}-H_s^{(r)}|^2ds\longrightarrow0.
$$

Hence the approximating processes are Cauchy in the space of continuous processes under the $L^2$ supremum norm and admit a continuous adapted limit. Passing the conditional expectation identity to the limit proves the martingale property. $\square$

**Theorem 9.1.15 (Quadratic variation of the general Itô integral).** For $H\in\mathcal H_T^2(W)$,

$$
\boxed{\left[\int_0^{\cdot}H_s\,dW_s\right]_t
=\int_0^tH_s^2\,ds.}
$$

More generally, for $H,K\in\mathcal H_T^2(W)$,

$$
\boxed{\left[\int_0^{\cdot}H_s\,dW_s,
\int_0^{\cdot}K_s\,dW_s\right]_t
=\int_0^tH_sK_s\,ds.}
$$

**Proof.** The elementary result establishes the identity for $H^{(m)}$. The isometry shows convergence in $L^2$ of the corresponding integrals, while $H^{(m)}\to H$ in $L^2(ds\otimes d\mathbb P)$ implies $\int_0^t(H_s^{(m)})^2ds\to\int_0^tH_s^2ds$ in $L^1$ (by Cauchy–Schwarz). Taking limits in the martingale-square characterisation, after localisation if needed, identifies the bracket of the limiting continuous martingale. Polarisation yields the cross-variation formula. $\square$

---

## 9.1.8. A fundamental calculation: $\int W\,dW$

**Theorem 9.1.16 (Brownian motion integrated against itself).** For every $t\ge0$,

$$
\boxed{\int_0^tW_s\,dW_s=\frac12(W_t^2-t).}
$$

**Proof from left-endpoint sums.** Let $\pi$ partition $[0,t]$. The algebraic identity

$$
W_{t_{k+1}}^2-W_{t_k}^2
=2W_{t_k}(W_{t_{k+1}}-W_{t_k})
+(W_{t_{k+1}}-W_{t_k})^2
$$

implies

$$
\sum_kW_{t_k}(W_{t_{k+1}}-W_{t_k})
=\frac12\left(W_t^2-W_0^2
-\sum_k(W_{t_{k+1}}-W_{t_k})^2\right).
$$

With $W_0=0$, the sample quadratic-variation sum converges to $t$ in $L^2$, while the left sum converges to the Itô integral. Therefore

$$
\int_0^tW_s\,dW_s=\tfrac12W_t^2-\tfrac12t.
$$

$\square$

Compare this with the classical formula $\int_0^t f(s)df(s)=\frac12(f(t)^2-f(0)^2)$ for a differentiable or continuous finite-variation $f$. The additional term $-t/2$ is the correction caused by $[W]_t=t$.

**Remark 9.1.17 (Left endpoints versus symmetric sums).** Replacing left endpoints by midpoints/symmetric evaluation leads, in the usual continuous semimartingale setting, to the Stratonovich integral, with

$$
\int_0^tW_s\circ dW_s=\frac12W_t^2.
$$

The distinction is not merely notational: the choice of approximation rule changes the integral by half the quadratic covariation.

---

## 9.1.9. Summary

For an admissible adapted integrand $H$ and Brownian motion $W$,

$$
\boxed{\begin{gathered}
I_t=\int_0^tH_s\,dW_s,\qquad \mathbb E[I_t\mid\mathcal F_s]=I_s,\\
\mathbb E[I_t^2]=\mathbb E\int_0^tH_s^2\,ds,\\
[I]_t=\int_0^tH_s^2\,ds,\\
\int_0^tW_s\,dW_s=\frac12(W_t^2-t).
\end{gathered}}
$$

The isometry permits an $L^2$ extension from simple random sums. In [§9.2](../02-stochastic-integration-with-martingales/) we replace Brownian motion with a general continuous martingale, whose bracket $\langle M\rangle$ plays the role of elapsed time.


- [Exercises]({{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/01-construction-of-the-ito-integral/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/01-construction-of-the-ito-integral/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/01-construction-of-the-ito-integral/references/' | relative_url }})

[Back to Stochastic Integration]({{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/' | relative_url }})

</article>
