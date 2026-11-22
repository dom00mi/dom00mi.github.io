---
layout: default
title: "2.3 — OIS Curves and Multi-Curve Frameworks"
permalink: /pages/quantitative-finance/notes/fixed-income/02-Yield-Curves-and-Term-Structures/03-OIS-Curves-and-Multi-Curve-Frameworks/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/02-Yield-Curves-and-Term-Structures/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>OIS Curves and Multi Curve Frameworks</h1>
  <p class="lead">Foundations and quantitative methods for ois curves and multi curve frameworks.</p>
</div>

<article class="article" markdown="1">


# 2.3 — OIS Curves and Multi-Curve Frameworks

## 2.3.1 Motivation for multiple curves

Before the 2007–08 crisis, single-curve approaches often treated discounting and term-rate projections as if they were governed by the same zero-coupon curve. The lecture notes describe how bank credit and funding concerns produced a material divergence between overnight-indexed swap (OIS) rates and term unsecured rates. This motivated **distinct discount and tenor-specific forward curves**.

The lecture's post-LIBOR discussion refers to overnight reference rates such as SONIA, SOFR and €STR. These are backward-looking overnight benchmarks, unlike traditional forward-looking LIBOR term fixings.

## 2.3.2 Discount curve and tenor-indexed forwards

Let \(P^d(t,T)\) denote a discount factor inferred from the overnight/collateral discounting framework. The simple forward rate implied by discount factors over \([S,T]\) is

$$
F^d(t;S,T)=\frac{1}{T-S}
\left(\frac{P^d(t,S)}{P^d(t,T)}-1\right).
$$

Let \(L^x_k(t)\) denote a forward rate for an index of tenor \(x\), fixed for \([T^x_{k-1},T^x_k]\). In a multi-curve framework, generally

$$
L^x_k(t)\neq F^d(t;T^x_{k-1},T^x_k).
$$

This separates discounting from the projection of rate-dependent payoffs.

## 2.3.3 Additive and multiplicative spreads

The lecture defines the **additive spread** as

$$
S^x_k(t)=L^x_k(t)-F^d_k(t),
$$

and a **multiplicative spread** using

$$
1+\delta_x\widetilde{S}^x_k(t)
=\frac{1+\delta_x L^x_k(t)}{1+\delta_x F^d_k(t)}.
$$

The two choices define different state variables; neither is determined solely by the OIS discount curve.

## 2.3.4 Pricing with separate projection and discounting

For a receive-floating swap leg with notional \(N\) and accrual fractions \(δ_k\), the schematic time-\(t\) value is

$$
V_{\mathrm{float}}(t)=N\sum_{k=1}^{n}
\delta_kP^d(t,T_k)L^x_k(t),
$$

where \(L^x_k(t)\) is the appropriate forward-measure expectation of the future fixing. A fixed leg at rate \(K\) has value

$$
V_{\mathrm{fixed}}(t)=NK\sum_{k=1}^{n}\delta_kP^d(t,T_k).
$$

The multi-curve par swap rate is their ratio:

$$
K^x_{\mathrm{par}}(t)
=\frac{\sum_{k=1}^{n}\delta_kP^d(t,T_k)L^x_k(t)}
{\sum_{k=1}^{n}\delta_kP^d(t,T_k)}.
$$

The telescoping single-curve floating-leg identity can no longer be imposed without a model linking the projection rates to the discount curve.

---


**Suggested references:** [2], [3]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 02 — Yield Curves and Term Structures]({{ '/pages/quantitative-finance/notes/fixed-income/02-Yield-Curves-and-Term-Structures/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
