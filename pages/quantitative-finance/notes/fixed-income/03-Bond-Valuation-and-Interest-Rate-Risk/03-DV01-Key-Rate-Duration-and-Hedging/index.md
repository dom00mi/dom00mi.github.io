---
layout: default
title: "3.3 — DV01, Key-Rate Duration and Hedging"
permalink: /pages/quantitative-finance/notes/fixed-income/03-Bond-Valuation-and-Interest-Rate-Risk/03-DV01-Key-Rate-Duration-and-Hedging/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/03-Bond-Valuation-and-Interest-Rate-Risk/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>DV01, Key Rate Duration and Hedging</h1>
  <p class="lead">Foundations and quantitative methods for dv01, key rate duration and hedging.</p>
</div>

<article class="article" markdown="1">


# 3.3 — DV01, Key-Rate Duration and Hedging

> **Scope:** The lecture explicitly defines duration and convexity; DV01, key-rate duration and risk-bucket hedging are supplementary applications of those derivatives.

## 3.3.1 Dollar value of a basis point

Let \(B(y)\) be a bond price and one basis point be \(\varepsilon=10^{-4}\) in decimal yield units. The **DV01** can be defined as the positive price decline for a one-basis-point increase:

$$
\mathrm{DV01}\approx-\frac{\partial B}{\partial y}\,10^{-4}
=B(y)D(y)\,10^{-4}.
$$

For reporting, a symmetric bump estimate is often used:

$$
\mathrm{DV01}_{\mathrm{central}}
\approx\frac{B(y-\varepsilon)-B(y+\varepsilon)}{2}.
$$

These expressions have units of currency per one-basis-point yield change; the notional is already embedded in \(B\).

## 3.3.2 Key-rate sensitivities

A parallel yield sensitivity cannot distinguish a 2-year rate shock from a 10-year rate shock. Parameterise the curve by pillar rate vector

$$
\boldsymbol{z}=(z_1,\ldots,z_m),
\qquad B=B(\boldsymbol{z}).
$$

Define the local currency change for a one-basis-point increase in the \(j\)th curve pillar by

$$
\mathrm{KRDV01}_j
\approx-10^{-4}\frac{\partial B}{\partial z_j}.
$$

This definition depends on how the entire curve is reconstructed after the individual pillar shock. Different interpolation and bump conventions yield different reported values.

## 3.3.3 First-order hedging

Suppose a target portfolio has first-order risk vector \(\boldsymbol{g}\) and hedge instruments have risk vectors as columns of matrix \(H\). Choose hedge quantities \(\boldsymbol{h}\) to satisfy

$$
H\boldsymbol{h}=-\boldsymbol{g}.
$$

If the number of hedge instruments is smaller than the number of risk buckets, one may instead minimise a weighted residual:

$$
\min_{\boldsymbol{h}}
\left(H\boldsymbol{h}+\boldsymbol{g}\right)^{\mathsf T}
W\left(H\boldsymbol{h}+\boldsymbol{g}\right).
$$

First-order matching does not eliminate convexity, basis risk or subsequent changes in the model sensitivities.

---


**Suggested references:** [2], [4]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 03 — Bond Valuation and Interest Rate Risk]({{ '/pages/quantitative-finance/notes/fixed-income/03-Bond-Valuation-and-Interest-Rate-Risk/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
