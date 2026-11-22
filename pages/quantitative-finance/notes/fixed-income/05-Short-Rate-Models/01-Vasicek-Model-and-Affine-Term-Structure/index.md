---
layout: default
title: "5.1 — Vasicek Model and Affine Term Structure"
permalink: /pages/quantitative-finance/notes/fixed-income/05-Short-Rate-Models/01-Vasicek-Model-and-Affine-Term-Structure/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/05-Short-Rate-Models/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Vasicek Model and Affine Term Structure</h1>
  <p class="lead">Foundations and quantitative methods for vasicek model and affine term structure.</p>
</div>

<article class="article" markdown="1">


# 5.1 — Vasicek Model and Affine Term Structure

## 5.1.1 Short-rate modelling and the pricing equation

A short-rate model specifies the instantaneous interest rate and obtains bond prices through risk-neutral discounting. Under a risk-neutral measure \(\mathbb{Q}\), consider

$$
\mathrm{d}r(t)=a\bigl(b-r(t)\bigr)\,\mathrm{d}t
+\sigma\,\mathrm{d}W^{\mathbb{Q}}(t),
\qquad a>0,\quad\sigma>0.
$$

This is the **Vasicek model**: the drift pulls rates towards the long-run level \(b\) at speed \(a\), while Brownian volatility is constant.

For any Markov short-rate model \(\mathrm{d}r=\mu^{\mathbb Q}(t,r)\mathrm{d}t+\sigma(t,r)\mathrm{d}W^{\mathbb Q}\), define

$$
P(t,T)=F^{(T)}(t,r(t))
=\mathbb{E}^{\mathbb{Q}}
\left[e^{-\int_t^T r(u)\,\mathrm{d}u}\middle|\mathcal{F}_t\right].
$$

The Feynman–Kac/term-structure PDE is

$$
F_t+\mu^{\mathbb Q}(t,x)F_x
+\frac12\sigma^2(t,x)F_{xx}-xF=0,
\qquad F(T,x)=1.
$$

## 5.1.2 Exact short-rate dynamics

The Vasicek short rate has the explicit solution

$$
r(t)=b+\bigl(r(0)-b\bigr)e^{-at}
+\sigma\int_0^t e^{-a(t-s)}\,\mathrm{d}W^{\mathbb{Q}}(s).
$$

It follows that the conditional expectation and variance are

$$
\mathbb{E}^{\mathbb Q}[r(T)\mid\mathcal F_t]
=b+\bigl(r(t)-b\bigr)e^{-a(T-t)},
$$

$$
\operatorname{Var}^{\mathbb Q}[r(T)\mid\mathcal F_t]
=\frac{\sigma^2}{2a}\left(1-e^{-2a(T-t)}\right).
$$

The Gaussian distribution allows rates to become negative. This feature is mathematically tractable but may be undesirable for some applications.

## 5.1.3 Exponential-affine bond prices

Postulate

$$
P(t,T)=\exp\bigl[-A(t,T)-B(t,T)r(t)\bigr].
$$

Substitution into the term-structure PDE yields the Riccati system

$$
\partial_t B-aB+1=0,
\qquad
\partial_t A+abB-\frac12\sigma^2B^2=0,
$$

$$
A(T,T)=B(T,T)=0.
$$

Writing \(\tau=T-t\), the solution is

$$
B(t,T)=\frac{1-e^{-a\tau}}{a},
$$

$$
A(t,T)=\left(b-\frac{\sigma^2}{2a^2}\right)
\bigl(\tau-B(t,T)\bigr)
+\frac{\sigma^2}{4a}B(t,T)^2.
$$

## 5.1.4 From Vasicek to forward-rate dynamics

By definition,

$$
f(t,T)=-\partial_T\log P(t,T)
=\partial_T A(t,T)+r(t)\partial_TB(t,T).
$$

The implied HJM forward-rate volatility is

$$
\sigma_f(t,T)=\sigma\,e^{-a(T-t)}.
$$

The source uses this identity to exhibit Vasicek as a particular arbitrage-free HJM model. A constant-parameter model cannot generally fit an arbitrary observed initial term structure exactly.

---


**Suggested references:** [1], [2], [4]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 05 — Short-Rate Models]({{ '/pages/quantitative-finance/notes/fixed-income/05-Short-Rate-Models/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
