---
layout: default
title: "5.3 — Hull–White Model and Curve Fitting"
permalink: /pages/quantitative-finance/notes/fixed-income/05-Short-Rate-Models/03-Hull-White-Model-and-Curve-Fitting/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/05-Short-Rate-Models/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Hull–White Model and Curve Fitting</h1>
  <p class="lead">Foundations and quantitative methods for hull–white model and curve fitting.</p>
</div>

<article class="article" markdown="1">


# 5.3 — Hull–White Model and Curve Fitting

## 5.3.1 Time-dependent coefficients

The frameworks introduce a time-inhomogeneous Hull–White extension of Vasicek:

$$
\mathrm{d}r(t)=\left[\alpha(t)-a(t)r(t)\right]\mathrm{d}t
+\sigma(t)\,\mathrm{d}W^{\mathbb{Q}}(t),
$$

with deterministic coefficient functions. A commonly used special case has constant \(a>0\) and \(\sigma>0\) with a time-dependent drift \(\theta(t)\):

$$
\mathrm{d}r(t)=\left[\theta(t)-ar(t)\right]\mathrm{d}t
+\sigma\,\mathrm{d}W^{\mathbb{Q}}(t).
$$

A time-dependent drift offers enough flexibility to match the initial discount curve, subject to regularity conditions.

## 5.3.2 Affine bond-price representation

Write

$$
P(t,T)=e^{-A(t,T)-B(t,T)r(t)}.
$$

For the general drift \(a(t)(b(t)-r(t))\) and volatility \(\sigma(t)\) in the model, the coefficient equations are

$$
\partial_t B(t,T)-a(t)B(t,T)+1=0,
$$

$$
\partial_t A(t,T)+a(t)b(t)B(t,T)
-\frac12\sigma(t)^2B(t,T)^2=0,
$$

with \(A(T,T)=B(T,T)=0\). Their solutions are

$$
B(t,T)=\int_t^T\exp\!\left(-\int_t^u a(s)\,\mathrm{d}s\right)\mathrm{d}u,
$$

$$
A(t,T)=\int_t^T\left[a(u)b(u)B(u,T)
-\frac12\sigma(u)^2B(u,T)^2\right]\mathrm{d}u.
$$

For constant mean-reversion speed \(a\), this simplifies to

$$
B(t,T)=\frac{1-e^{-a(T-t)}}{a}.
$$

## 5.3.3 Curve-fitting idea

Suppose market prices at the initial date are given by \(P^*(0,T)\), or equivalently by the market instantaneous forward curve

$$
f^*(0,T)=-\partial_T\log P^*(0,T).
$$

A successful initial calibration must achieve

$$
P(0,T)=P^*(0,T),\qquad\text{for all modelled maturities }T.
$$

The framework explains why constant parameters generally cannot satisfy an infinite collection of maturity-specific constraints, whereas a deterministic drift function can.

## 5.3.4 Ho–Lee as an explicit calibration example

The source works out the **Ho–Lee** case

$$
\mathrm{d}r(t)=\alpha(t)\,\mathrm{d}t+\sigma\,\mathrm{d}W^{\mathbb Q}(t).
$$

It has an explicit initial-curve fit:

$$
\alpha(t)=\frac{\partial f^*(0,t)}{\partial t}+\sigma^2t.
$$

HJM with constant forward-rate volatility reproduces exactly the same short-rate dynamics. This is the concrete demonstration of the initial-curve calibration principle.

---


**Suggested references:** [1], [2], [4], [5]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 05 — Short-Rate Models]({{ '/pages/quantitative-finance/notes/fixed-income/05-Short-Rate-Models/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
