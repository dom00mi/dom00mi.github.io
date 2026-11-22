---
layout: default
title: "5.4 — Bond Options and Short-Rate Model Calibration"
permalink: /pages/quantitative-finance/notes/fixed-income/05-Short-Rate-Models/04-Bond-Options-and-Short-Rate-Model-Calibration/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/05-Short-Rate-Models/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Bond Options and Short Rate Model Calibration</h1>
  <p class="lead">Foundations and quantitative methods for bond options and short rate model calibration.</p>
</div>

<article class="article" markdown="1">


# 5.4 — Bond Options and Short-Rate Model Calibration

## 5.4.1 Pricing a derivative on a future bond

In a Markov short-rate model, a European call exercised at \(S\) on a zero-coupon bond maturing at \(T>S\) pays

$$
H_S=\bigl(P(S,T)-K\bigr)^+.
$$

Its time-\(t\) value for \(t\le S\) is

$$
V(t,r(t))=\mathbb{E}^{\mathbb Q}\!\left[
 e^{-\int_t^S r(u)\,\mathrm{d}u}
\bigl(P(S,T)-K\bigr)^+
\middle|\mathcal F_t\right].
$$

When \(P(S,T)=F^{(T)}(S,r(S))\), the payoff becomes a function of the short rate at exercise.

## 5.4.2 Derivative pricing PDE

If under \(\mathbb Q\) the short rate has dynamics

$$
\mathrm{d}r=\mu^{\mathbb Q}(t,r)\,\mathrm{d}t
+\sigma(t,r)\,\mathrm{d}W^{\mathbb Q},
$$

then the call's value function satisfies

$$
V_t+\mu^{\mathbb Q}(t,x)V_x
+\frac12\sigma^2(t,x)V_{xx}-xV=0,
$$

with terminal condition

$$
V(S,x)=\bigl(F^{(T)}(S,x)-K\bigr)^+.
$$

In the same manner, a caplet can be represented as a scaled put on a bond, leading to the same PDE with a different terminal payoff. The source develops this explicitly in §5.1.

## 5.4.3 Calibrating the underlying short-rate model

For model parameter vector \(\boldsymbol\phi\), bond values become \(P(t,T;\boldsymbol\phi)\). Initial-curve calibration seeks

$$
P(0,T;\boldsymbol\phi^*)=P^*(0,T)
$$

for the observed maturities. Once the fitted model is specified, derivative prices depend on the model's **future dynamics**, not just on the fitted curve. Two models can agree on today's zero-coupon prices and disagree on bond-option prices.

## 5.4.4 Interest-rate option volatility calibration

The PDF describes caplet Black volatilities inferred from observed cap prices and volatility functions selected to reproduce those implied variances:

$$
\int_t^{T_{k-1}}\lVert\boldsymbol\sigma_k(u)\rVert^2
\,\mathrm{d}u=\overline\sigma_k^2(T_{k-1}-t).
$$

Curve-fitting parameters and option-volatility parameters play different roles: fitting bond prices fixes the current term structure, while fitting option prices constrains volatility and joint dynamics. A robust calibration checks both pricing consistency and parameter stability.

---

**Source mapping:** Lecture §§5.1, 5.4, 7.2.2 (PDF pp. 25–27, 29–30, 40–41).

**Suggested references:** [1], [2], [9]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 05 — Short-Rate Models]({{ '/pages/quantitative-finance/notes/fixed-income/05-Short-Rate-Models/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
