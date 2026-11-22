---
layout: default
title: "2.4 — Interpolation and Yield Curve Construction"
permalink: /pages/quantitative-finance/notes/fixed-income/02-Yield-Curves-and-Term-Structures/04-Interpolation-and-Yield-Curve-Construction/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/02-Yield-Curves-and-Term-Structures/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Interpolation and Yield Curve Construction</h1>
  <p class="lead">Foundations and quantitative methods for interpolation and yield curve construction.</p>
</div>

<article class="article" markdown="1">


# 2.4 — Interpolation and Yield Curve Construction

> **Scope:** The PDF states that building the term structure from observed prices is important but does not specify numerical interpolation schemes. The methods below are supplementary ways to respect the discount-factor identities.

## 2.4.1 Why interpolation is necessary

Market instruments typically identify discount factors at only a finite set of maturities \(T_1,\ldots,T_n\). Yet derivatives may pay on intermediate dates. To calculate present values, we must define \(P(t,T)\) between calibration pillars.

A representation-independent quantity is the integrated instantaneous forward rate

$$
G(t,T):=-\log P(t,T)=\int_t^T f(t,u)\,\mathrm{d}u.
$$

If \(G\) is interpolated, the corresponding discount factor is \(P=e^{-G}\). An interpolation of zero rates and an interpolation of log discount factors generally do **not** coincide.

## 2.4.2 Linear interpolation of log discount factors

At pillars \(T_i<T<T_{i+1}\) let

$$
w=\frac{T-T_i}{T_{i+1}-T_i}.
$$

Define

$$
\log P(t,T)=(1-w)\log P(t,T_i)+w\log P(t,T_{i+1}).
$$

Then

$$
P(t,T)=P(t,T_i)^{1-w}P(t,T_{i+1})^w.
$$

By differentiation, the instantaneous forward rate is piecewise constant between pillars:

$$
f(t,T)=\frac{\log P(t,T_i)-\log P(t,T_{i+1})}{T_{i+1}-T_i}.
$$

## 2.4.3 Interpolating zero rates instead

An alternative is to interpolate \(R(t,T)\) and reconstruct discount factors:

$$
P(t,T)=e^{-(T-t)R(t,T)}.
$$

The resulting forward curve depends on both the level and maturity slope of the interpolated zero rate:

$$
f(t,T)=R(t,T)+(T-t)\frac{\partial R(t,T)}{\partial T}.
$$

Thus a visually smooth zero curve need not imply a smooth forward curve.

## 2.4.4 Design principles

The chosen method should reproduce calibration pillars exactly, be consistent with the compounding convention and day-count schedule, and control oscillations or economically implausible forwards. The curve must be rebuilt consistently when market pillars are shocked for risk calculations.

---


**Suggested references:** [2], [4]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 02 — Yield Curves and Term Structures]({{ '/pages/quantitative-finance/notes/fixed-income/02-Yield-Curves-and-Term-Structures/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
