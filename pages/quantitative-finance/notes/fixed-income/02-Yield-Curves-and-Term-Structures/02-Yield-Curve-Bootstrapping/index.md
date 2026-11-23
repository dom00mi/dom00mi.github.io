---
layout: default
title: "2.2 — Yield Curve Bootstrapping"
permalink: /pages/quantitative-finance/notes/fixed-income/02-Yield-Curves-and-Term-Structures/02-Yield-Curve-Bootstrapping/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/02-Yield-Curves-and-Term-Structures/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Yield Curve Bootstrapping</h1>
  <p class="lead">Foundations and quantitative methods for yield curve bootstrapping.</p>
</div>

<article class="article" markdown="1">


# 2.2 — Yield Curve Bootstrapping

> **Scope:** Market bonds and derivatives imply a yield curve. The sequential equations below construct discount factors instrument by instrument from the pricing identities in §§1 and 3.

## 2.2.1 Bootstrap objective

At the valuation date, seek discount factors at pillar maturities

$$
P(0,T_1),P(0,T_2),\ldots,P(0,T_n)
$$

that reproduce observed market prices. Each new instrument ideally introduces one new unknown discount factor, with earlier pillar values already determined.

## 2.2.2 Zero-coupon bonds

A unit-face zero-coupon bond quoted at market price \(p_i\) directly gives

$$
P(0,T_i)=p_i.
$$

For face amount \(N\), the discount factor is market price divided by \(N\).

## 2.2.3 Fixed-coupon bond recursion

For a default-free bond whose payment schedule is fully specified,

$$
B_{\mathrm{mkt}}=\sum_{k=1}^{n-1}c_kP(0,T_k)
+(c_n+N)P(0,T_n).
$$

If the earlier factors have been determined, the final pillar is recovered as

$$
P(0,T_n)=\frac{B_{\mathrm{mkt}}-\sum_{k=1}^{n-1}c_kP(0,T_k)}{c_n+N}.
$$

When cashflows occur between existing pillars, an interpolation rule is also needed, and then construction and interpolation become coupled.

## 2.2.4 Par swap recursion

In the **single-curve** setting, a par fixed-for-floating swap satisfies

$$
K\sum_{k=1}^{n}\delta_kP(0,T_k)
=P(0,T_0)-P(0,T_n).
$$

For a spot-starting swap with \(T_0=0\), solve for the last factor:

$$
P(0,T_n)=
\frac{1-K\sum_{k=1}^{n-1}\delta_kP(0,T_k)}{1+K\delta_n}.
$$

This identity does **not** survive unchanged when floating index projection and discounting use different curves.

## 2.2.5 Consistency checks

A valid implementation should reproduce each input instrument's price, use the specified accrual factors, maintain positive discount factors, and record how interpolation changes the outputs. A maturity-by-maturity curve cannot be uniquely determined from finitely many prices without further assumptions.

---


**Suggested references:** [2], [4]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 02 — Yield Curves and Term Structures]({{ '/pages/quantitative-finance/notes/fixed-income/02-Yield-Curves-and-Term-Structures/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
