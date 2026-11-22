---
layout: default
title: "3.2 — Duration, Convexity and Price Sensitivity"
permalink: /pages/quantitative-finance/notes/fixed-income/03-Bond-Valuation-and-Interest-Rate-Risk/02-Duration-Convexity-and-Price-Sensitivity/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/03-Bond-Valuation-and-Interest-Rate-Risk/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Duration, Convexity and Price Sensitivity</h1>
  <p class="lead">Foundations and quantitative methods for duration, convexity and price sensitivity.</p>
</div>

<article class="article" markdown="1">


# 3.2 — Duration, Convexity and Price Sensitivity

## 3.2.1 Duration as a derivative

Let the price at continuously compounded yield \(y\) be

$$
B(y)=\sum_{k=1}^{n}c_ke^{-y\tau_k}+Ne^{-y\tau_n},
\qquad \tau_k=T_k-t.
$$

The lecture defines **duration** by the negative price derivative normalised by current price:

$$
D(y)=-\frac{1}{B(y)}\frac{\partial B(y)}{\partial y}.
$$

Substitution gives the cashflow-weighted time-to-payment representation

$$
D(y)=\frac{\sum_{k=1}^{n}\tau_kc_ke^{-y\tau_k}
+\tau_nNe^{-y\tau_n}}{B(y)}.
$$

Thus, under continuous compounding, duration is the weighted average time of the cashflows, using present-value weights.

## 3.2.2 Convexity

The **convexity** of the same price–yield relationship is

$$
C(y)=\frac{1}{B(y)}\frac{\partial^2B(y)}{\partial y^2}.
$$

Explicitly,

$$
C(y)=\frac{\sum_{k=1}^{n}\tau_k^2c_ke^{-y\tau_k}
+\tau_n^2Ne^{-y\tau_n}}{B(y)}.
$$

For a zero-coupon bond:

$$
D_{\mathrm{ZCB}}=T-t,
\qquad C_{\mathrm{ZCB}}=(T-t)^2.
$$

## 3.2.3 Second-order price approximation

A Taylor expansion around the current yield gives

$$
B(y+\Delta y)\approx
B(y)+B'(y)\Delta y+\frac12 B''(y)(\Delta y)^2.
$$

Dividing by \(B(y)\) and using the definitions yields

$$
\frac{\Delta B}{B}
\approx-D(y)\Delta y+\frac12 C(y)(\Delta y)^2.
$$

The linear term captures directional sensitivity; the convexity term captures curvature. These sensitivities are defined with respect to the bond's **single continuously compounded yield**. The risk of a non-parallel movement in the zero curve requires separate factor or key-rate sensitivities.

---


**Suggested references:** [1], [2]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 03 — Bond Valuation and Interest Rate Risk]({{ '/pages/quantitative-finance/notes/fixed-income/03-Bond-Valuation-and-Interest-Rate-Risk/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
