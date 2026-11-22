---
layout: default
title: "4.3 — Caps, Floors and Caplets"
permalink: /pages/quantitative-finance/notes/fixed-income/04-Interest-Rate-Derivatives/03-Caps-Floors-and-Caplets/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/04-Interest-Rate-Derivatives/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Caps, Floors and Caplets</h1>
  <p class="lead">Foundations and quantitative methods for caps, floors and caplets.</p>
</div>

<article class="article" markdown="1">


# 4.3 — Caps, Floors and Caplets

## 4.3.1 Cap and floor payoffs

Let the floating rate \(L_k=L(T_{k-1},T_k)\) reset at \(T_{k-1}\) for payment at \(T_k\), and let \(\delta_k=T_k-T_{k-1}\). A **caplet** with strike \(K\) and unit notional pays

$$
X^{\mathrm{caplet}}_k
=\delta_k(L_k-K)^+
\qquad\text{at }T_k,
$$

where \(x^+=\max(x,0)\). A floorlet pays

$$
X^{\mathrm{floorlet}}_k=\delta_k(K-L_k)^+.
$$

A cap or floor is the sum of its respective optionlets. For notional \(N\), multiply every cashflow and value by \(N\).

## 4.3.2 Caplets as bond options

In the **single-curve** setting,

$$
1+\delta_k L_k=\frac{1}{P(T_{k-1},T_k)}.
$$

Write

$$
E_k=\frac{1}{1+\delta_kK}.
$$

At the reset date, the value of the caplet's eventual payment is

$$
P(T_{k-1},T_k)\,\delta_k(L_k-K)^+
=\frac{1}{E_k}\bigl(E_k-P(T_{k-1},T_k)\bigr)^+.
$$

Thus a caplet may be viewed as \(1/E_k\) European **puts on the \(T_k\)-bond**, expiring at \(T_{k-1}\). For \(t\le T_{k-1}\), its price is

$$
V_k(t)=\frac{1}{E_k}\mathbb{E}^{\mathbb{Q}}\!\left[
 e^{-\int_t^{T_{k-1}}r(u)\,\mathrm{d}u}
\bigl(E_k-P(T_{k-1},T_k)\bigr)^+
\middle|\mathcal{F}_t\right].
$$

This identity connects caps with short-rate models and bond-option pricing.

## 4.3.3 The appropriate forward measure

For the \(T_k\)-forward measure,

$$
V_k(t)=\delta_k P(t,T_k)
\mathbb{E}^{\mathbb{Q}^{T_k}}
\left[(L_k-K)^+\mid\mathcal{F}_t\right].
$$

Under this measure the forward simple rate \(L(t;T_{k-1},T_k)\) is a martingale. If it is lognormal with integrated variance

$$
\nu_k^2=\int_t^{T_{k-1}}\lVert\boldsymbol{\sigma}_k(u)\rVert^2\,\mathrm{d}u,
$$

then the Black caplet formula is

$$
V_k(t)=\delta_kP(t,T_k)
\left[L_k(t)\Phi(d_1)-K\Phi(d_2)\right],
$$

$$
d_1=\frac{\log(L_k(t)/K)+\nu_k^2/2}{\nu_k},
\qquad d_2=d_1-\nu_k.
$$

Here \(\Phi\) is the standard normal CDF; positivity of forward and strike is needed for unshifted lognormal Black pricing.

## 4.3.4 Backward-looking compounded overnight rates

The notes contrast traditional forward-looking LIBOR payments with compounded overnight rates such as SONIA. Since the completed period's compounded rate is known only in arrears, the option payoff retains exposure to the rate evolution throughout the accrual period; the notes compare this to an Asian-style payoff. A standard forward-LIBOR caplet formula cannot automatically be reused unchanged.

---

**Source mapping:** Lecture §§3.4.1, 7.2 (PDF pp. 18–19, 38–41).

**Suggested references:** [2], [6], [7]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 04 — Interest Rate Derivatives]({{ '/pages/quantitative-finance/notes/fixed-income/04-Interest-Rate-Derivatives/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
