---
layout: default
title: "7.1 — Black, Bachelier and Interest-Rate Option Volatility"
permalink: /pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/01-Black-Bachelier-and-Interest-Rate-Option-Volatility/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Black, Bachelier and Interest Rate Option Volatility</h1>
  <p class="lead">Foundations and quantitative methods for black, bachelier and interest rate option volatility.</p>
</div>

<article class="article" markdown="1">


# 7.1 — Black, Bachelier and Interest-Rate Option Volatility

## 7.1.1 Market-model volatility in the lecture notes

The lecture's market-model approach assumes a selected forward **simple interest rate**, or a forward swap rate, is lognormal under the numéraire measure appropriate to its payoff. For a caplet written on forward rate \(L_k\), the \(T_k\)-forward measure gives

$$
\mathrm{d}L_k(t)=L_k(t)\boldsymbol\sigma_k(t)
\cdot\mathrm{d}\boldsymbol W^{T_k}(t).
$$

The integrated variance over the remaining fixing horizon is

$$
\nu_k^2(t)=\int_t^{T_{k-1}}
\lVert\boldsymbol\sigma_k(u)\rVert^2\,\mathrm{d}u.
$$

With a positive forward and strike, Black's caplet price is

$$
V_{\mathrm{caplet}}(t)
=N\delta_kP(t,T_k)\bigl[L_k(t)\Phi(d_1)-K\Phi(d_2)\bigr],
$$

$$
d_1=\frac{\log(L_k(t)/K)+\nu_k^2/2}{\nu_k},
\qquad d_2=d_1-\nu_k.
$$

Here \(N\) is notional and \(\Phi\) denotes the standard normal distribution function. The fixed strike, forward rate and volatility must all use mutually consistent quotation conventions.

## 7.1.2 Black's swaption price

For a payer swaption, the **annuity measure** \(\mathbb Q^A\) makes the forward swap rate \(S(t)\) a martingale, and under a lognormal assumption the price is

$$
V_{\mathrm{payer}}(t)
=NA(t)\left[S(t)\Phi(d_1)-K\Phi(d_2)\right],
$$

$$
d_1=\frac{\log(S(t)/K)+\nu_S^2/2}{\nu_S},
\quad d_2=d_1-\nu_S,
\quad \nu_S^2=\int_t^{T_0}\lVert\boldsymbol\sigma_S(u)\rVert^2\,\mathrm{d}u.
$$

## 7.1.3 Implied Black volatilities

The source observes that caplet Black volatilities can be inferred from market cap/caplet prices. A deterministic function \(\boldsymbol\sigma_k(u)\) is compatible with a Black volatility \(\overline\sigma_k\) if

$$
\int_t^{T_{k-1}}\lVert\boldsymbol\sigma_k(u)\rVert^2
\,\mathrm{d}u=\overline\sigma_k^2(T_{k-1}-t).
$$

Matching the integrated variance does not uniquely determine the time profile or cross-rate correlations.

## 7.1.4 Bachelier (normal) pricing

> **Supplementary theory:** The PDF develops Black pricing, not a separate Bachelier model. The normal formula below is included for the requested comparison.

Under a normal forward model with \(\mathrm{d}F=\sigma_N\,\mathrm{d}W\) and time to fixing \(\tau\), define

$$
d=\frac{F-K}{\sigma_N\sqrt{\tau}}.
$$

A call-style interest-rate option with positive present-value multiplier \(D\) has the Bachelier price

$$
C_N=D\left[(F-K)\Phi(d)
+\sigma_N\sqrt{\tau}\,\varphi(d)\right],
$$

where \(\varphi\) is the standard normal density. For a caplet \(D=N\delta P(t,T_k)\); for a payer swaption \(D=NA(t)\). Normal pricing accommodates negative forwards without a log transform. Black volatility and normal volatility have different units and should never be compared as if they were the same parameter.

---

**Source mapping:** Lecture §§2.3, 3.4, 7.1–7.3 (PDF pp. 14, 18–21, 38–45); Bachelier subsection supplementary.

**Suggested references:** [2], [6], [7]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 07 — Volatility and Model Calibration]({{ '/pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
