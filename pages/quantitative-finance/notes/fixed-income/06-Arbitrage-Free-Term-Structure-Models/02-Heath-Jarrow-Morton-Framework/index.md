---
layout: default
title: "6.2 — Heath–Jarrow–Morton Framework"
permalink: /pages/quantitative-finance/notes/fixed-income/06-Arbitrage-Free-Term-Structure-Models/02-Heath-Jarrow-Morton-Framework/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/06-Arbitrage-Free-Term-Structure-Models/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Heath–Jarrow–Morton Framework</h1>
  <p class="lead">Foundations and quantitative methods for heath–jarrow–morton framework.</p>
</div>

<article class="article" markdown="1">


# 6.2 — Heath–Jarrow–Morton Framework

## 6.2.1 From short-rate models to forward-rate models

The **Heath–Jarrow–Morton (HJM)** framework models the entire instantaneous forward curve \(T\mapsto f(t,T)\) directly. The initial market curve is an initial condition:

$$
f(0,T)=f^*(0,T),\qquad T\ge0.
$$

Under the physical measure \(\mathbb P\), the framework postulates

$$
\mathrm{d}f(t,T)=\alpha^{\mathbb P}(t,T)\,\mathrm{d}t
+\boldsymbol\sigma(t,T)\cdot\mathrm{d}\boldsymbol W^{\mathbb P}(t).
$$

The forward-rate volatility is vector-valued when there are multiple Brownian factors.

## 6.2.2 Bond-price dynamics induced by forwards

Since

$$
P(t,T)=\exp\!\left(-\int_t^T f(t,u)\,\mathrm{d}u\right),
$$

define

$$
\boldsymbol\gamma(t,T)=-\int_t^T\boldsymbol\sigma(t,u)\,\mathrm{d}u,
\qquad
\beta(t,T)=-\int_t^T\alpha(t,u)\,\mathrm{d}u.
$$

The Itô formula yields

$$
\frac{\mathrm{d}P(t,T)}{P(t,T)}
=\left[r(t)+\beta(t,T)+\frac12\lVert\boldsymbol\gamma(t,T)\rVert^2\right]\mathrm{d}t
+\boldsymbol\gamma(t,T)\cdot\mathrm{d}\boldsymbol W(t).
$$

This identity holds before choosing the pricing measure; the no-arbitrage condition constrains its drift.

## 6.2.3 HJM drift restriction under the risk-neutral measure

For discounted bond prices to be local martingales under \(\mathbb Q\), their drift must equal the short rate \(r(t)\). Hence

$$
-\int_t^T\alpha^{\mathbb Q}(t,u)\,\mathrm{d}u
+\frac12\left\lVert\int_t^T\boldsymbol\sigma(t,u)\,\mathrm{d}u\right\rVert^2=0.
$$

Differentiating with respect to maturity gives the **HJM drift condition**

$$
\boxed{\displaystyle
\alpha^{\mathbb Q}(t,T)
=\boldsymbol\sigma(t,T)\cdot
\int_t^T\boldsymbol\sigma(t,u)\,\mathrm{d}u.}
$$

Therefore the arbitrage-free \(\mathbb Q\) dynamics are

$$
\mathrm{d}f(t,T)=
\left[\boldsymbol\sigma(t,T)\cdot\int_t^T\boldsymbol\sigma(t,u)\,\mathrm{d}u\right]\mathrm{d}t
+\boldsymbol\sigma(t,T)\cdot\mathrm{d}\boldsymbol W^{\mathbb Q}(t).
$$

**Once the volatility field has been specified, the risk-neutral drift is not free.**

## 6.2.4 Physical-measure drift and market price of risk

If \(\boldsymbol\lambda(t)\) is the market price of risk and

$$
\mathrm{d}\boldsymbol W^{\mathbb Q}(t)
=\mathrm{d}\boldsymbol W^{\mathbb P}(t)
+\boldsymbol\lambda(t)\,\mathrm{d}t,
$$

then the physical-measure drift condition is

$$
\alpha^{\mathbb P}(t,T)
=\boldsymbol\sigma(t,T)\cdot\left[
\int_t^T\boldsymbol\sigma(t,u)\,\mathrm{d}u
+\boldsymbol\lambda(t)\right].
$$

## 6.2.5 Ho–Lee example

Take constant one-factor forward volatility \(\sigma(t,T)=\sigma\). Under \(\mathbb Q\),

$$
\alpha^{\mathbb Q}(t,T)=\sigma^2(T-t),
$$

and the solution is

$$
f(t,T)=f^*(0,T)+\sigma^2t\left(T-\frac{t}{2}\right)
+\sigma W^{\mathbb Q}(t).
$$

Setting \(T=t\) recovers a Ho–Lee short rate fitting the initial forward curve, as shown in the source.

---


**Suggested references:** [1], [4], [5], [9]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 06 — Arbitrage-Free Term-Structure Models]({{ '/pages/quantitative-finance/notes/fixed-income/06-Arbitrage-Free-Term-Structure-Models/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
