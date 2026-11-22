---
layout: default
title: "8.3 — Yield-Curve Relative Value and Scenario Analysis"
permalink: /pages/quantitative-finance/notes/fixed-income/08-Yield-Curve-Modelling-and-Applications/03-Yield-Curve-Relative-Value-and-Scenario-Analysis/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/08-Yield-Curve-Modelling-and-Applications/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Yield Curve Relative Value and Scenario Analysis</h1>
  <p class="lead">Foundations and quantitative methods for yield curve relative value and scenario analysis.</p>
</div>

<article class="article" markdown="1">


# 8.3 — Yield-Curve Relative Value and Scenario Analysis

> **Scope:** Relative-value trading frameworks and scenario analysis are not standalone topics in the PDF. The formulas below are supplementary applications of its arbitrage-free bond-pricing and curve identities.

## 8.3.1 Relative value as model-versus-market comparison

Let \(B_i^{\mathrm{mkt}}\) be the observed market price of bond \(i\), and let \(B_i^{\mathrm{model}}\) be the price obtained by discounting its specified cashflows using a common fitted curve:

$$
B_i^{\mathrm{model}}(t)
=\sum_{k}c_{ik}P^{\mathrm{model}}(t,T_{ik})
+N_iP^{\mathrm{model}}(t,T_i).
$$

The raw pricing residual is

$$
\varepsilon_i=B_i^{\mathrm{mkt}}-B_i^{\mathrm{model}}.
$$

This is a **model residual**, not automatically an arbitrage profit. A tradable relative-value conclusion would also require controls for credit, liquidity, financing, bid–ask costs, collateral and model uncertainty.

## 8.3.2 Parallel and nonparallel scenarios

Under a uniform shift \(\Delta y\) of every continuously compounded zero rate, a zero-coupon factor transforms as

$$
P_{\mathrm{new}}(t,T)
=P(t,T)\exp\bigl[-(T-t)\Delta y\bigr].
$$

For more general maturity-dependent shifts \(\Delta R(T)\), set

$$
P_{\mathrm{new}}(t,T)
=P(t,T)\exp\bigl[-(T-t)\Delta R(T)\bigr].
$$

The portfolio is repriced under the entire shocked curve rather than by changing a single bond yield.

## 8.3.3 Factor-based P&L approximation

Let the current portfolio value depend on a curve vector \(\boldsymbol z\). A second-order local scenario approximation is

$$
\Delta V\approx\boldsymbol g^{\mathsf T}\Delta\boldsymbol z
+\frac12\Delta\boldsymbol z^{\mathsf T}
H_V\Delta\boldsymbol z,
$$

where

$$
\boldsymbol g=\nabla V,
\qquad H_V=\nabla^2V.
$$

The same formula can be expressed in a factor basis \(\Delta\boldsymbol z=F\Delta\boldsymbol x\), with first-order factor exposure \(F^{\mathsf T}\boldsymbol g\) and factor Hessian \(F^{\mathsf T}H_VF\).

## 8.3.4 Carry, roll-down and changes in curve shape

For a held instrument, P&L over time can be conceptually separated into coupon/accrual, passage-of-time effects on discounted cashflows, yield-curve changes and residual spread/basis moves. A rigorous attribution must specify whether the curve is held constant in maturity coordinates, date coordinates, or another convention while calculating **roll-down**.

The lecture's main contribution to this discussion is the consistency requirement: whether one values bonds, swaps or options, all prices must be coherent with the chosen discounting and no-arbitrage framework. In the multi-curve setting one must maintain separate projection and discount curves in every scenario.

---


**Suggested references:** [2], [4]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 08 — Yield-Curve Modelling and Applications]({{ '/pages/quantitative-finance/notes/fixed-income/08-Yield-Curve-Modelling-and-Applications/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
