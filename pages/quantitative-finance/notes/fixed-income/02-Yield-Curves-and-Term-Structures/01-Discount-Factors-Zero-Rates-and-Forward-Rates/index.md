---
layout: default
title: "2.1 — Discount Factors, Zero Rates and Forward Rates"
permalink: /pages/quantitative-finance/notes/fixed-income/02-Yield-Curves-and-Term-Structures/01-Discount-Factors-Zero-Rates-and-Forward-Rates/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/02-Yield-Curves-and-Term-Structures/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Discount Factors, Zero Rates and Forward Rates</h1>
  <p class="lead">Foundations and quantitative methods for discount factors, zero rates and forward rates.</p>
</div>

<article class="article" markdown="1">


# 2.1 — Discount Factors, Zero Rates and Forward Rates

## 2.1.1 Three equivalent representations of the curve

Fix a valuation time \(t\). The term structure may be represented by maturity-indexed discount factors, zero rates or instantaneous forward rates:

$$
T\longmapsto P(t,T),\qquad
T\longmapsto R(t,T),\qquad
T\longmapsto f(t,T).
$$

The zero-rate relation is

$$
P(t,T)=e^{-R(t,T)(T-t)}.
$$

Assuming differentiability in maturity, the **instantaneous forward rate** is

$$
f(t,T)=-\frac{\partial}{\partial T}\log P(t,T),
$$

and, since \(P(t,t)=1\), integration gives

$$
P(t,T)=\exp\!\left[-\int_t^T f(t,u)\,\mathrm{d}u\right].
$$

Consequently,

$$
R(t,T)=\frac{1}{T-t}\int_t^T f(t,u)\,\mathrm{d}u,
\qquad r(t)=f(t,t).
$$

## 2.1.2 Finite-period forward rates

For \(t ≤ S < T\), buying and selling zero-coupon bonds locks in a future exchange over \([S,T]\). The **simply compounded forward rate** satisfies

$$
L(t;S,T)=\frac{1}{T-S}\left(\frac{P(t,S)}{P(t,T)}-1\right).
$$

The equivalent continuously compounded forward rate is

$$
f(t;S,T)=-\frac{\log P(t,T)-\log P(t,S)}{T-S}.
$$

These conventions describe the same forward bond price:

$$
\frac{P(t,T)}{P(t,S)}
=e^{-f(t;S,T)(T-S)}
=\frac{1}{1+(T-S)L(t;S,T)}.
$$

## 2.1.3 Zero rates and forwards are linked

The continuous forward rate and the zero curve satisfy

$$
f(t;S,T)(T-S)=R(t,T)(T-t)-R(t,S)(S-t).
$$

The relation expresses no-arbitrage consistency between an investment spanning \([t,T]\) and an investment spanning \([t,S]\) followed by a locked-in rate spanning \([S,T]\).

## 2.1.4 Stochastic curves

The curve is observed at a particular date but can move with calendar time: for fixed \(T\), \(P(t,T)\) is a stochastic process. Short-rate models, HJM models, and discrete-tenor market models offer different ways to specify this evolution while respecting the common identities above.

---


**Suggested references:** [1], [4], [5]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 02 — Yield Curves and Term Structures]({{ '/pages/quantitative-finance/notes/fixed-income/02-Yield-Curves-and-Term-Structures/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
