---
layout: default
title: "7.3 — Calibration, Monte Carlo and PDE Pricing"
permalink: /pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/03-Calibration-Monte-Carlo-and-PDE-Pricing/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Calibration, Monte Carlo and PDE Pricing</h1>
  <p class="lead">Foundations and quantitative methods for calibration, monte carlo and pde pricing.</p>
</div>

<article class="article" markdown="1">


# 7.3 — Calibration, Monte Carlo and PDE Pricing

## 7.3.1 What the lecture explicitly calibrates

The lecture notes distinguish two calibration targets: the initial term structure and the prices of interest-rate options. For a parametric short-rate model with vector \(\boldsymbol\phi\), the initial bond calibration seeks

$$
P^{\mathrm{model}}(0,T;\boldsymbol\phi)
=P^{\mathrm{market}}(0,T).
$$

The source explains that time-dependent coefficients can fit a continuum of initial bond prices more flexibly than a small set of constant parameters. In the LIBOR market model, caplet implied variances constrain forward-rate volatility functions:

$$
\int_0^{T_{k-1}}\lVert\boldsymbol\sigma_k(u)\rVert^2
\,\mathrm{d}u=\overline\sigma_k^2T_{k-1}.
$$

This does not fully identify the multivariate correlations between the rates.

## 7.3.2 Short-rate PDE pricing

For a \(\mathbb Q\)-Markov short rate with dynamics

$$
\mathrm{d}r(t)=\mu^{\mathbb Q}(t,r(t))\,\mathrm{d}t
+\sigma(t,r(t))\,\mathrm{d}W^{\mathbb Q}(t),
$$

an interest-rate claim with payoff \(\Psi(r(T))\) has price function satisfying

$$
V_t+\mu^{\mathbb Q}(t,x)V_x
+\frac12\sigma^2(t,x)V_{xx}-xV=0,
\qquad V(T,x)=\Psi(x).
$$

The bond-price case uses terminal payoff \(\Psi(x)=1\). A bond-option or caplet terminal payoff can also be substituted, as demonstrated in lecture §5.1.

## 7.3.3 Monte Carlo form of the same price

> **Supplementary numerical implementation:** The PDF provides the Feynman–Kac expectation but not a Monte Carlo algorithm or its convergence analysis.

For simulated risk-neutral short-rate paths \(r^{(j)}\), a natural estimator for a maturity-\(T\) payoff \(H^{(j)}\) is

$$
\widehat V_M(t)=\frac1M\sum_{j=1}^{M}
\exp\!\left(-\int_t^T r^{(j)}(u)\,\mathrm{d}u\right)H^{(j)}.
$$

The estimator approximates the source's risk-neutral expectation. Discretisation error in the SDE and time integral must be distinguished from Monte Carlo sampling error. A numerical PDE method instead discretises the state and time variables of the backward equation.

## 7.3.4 Calibration objective and constraints

A practical fitting objective may combine weighted errors across selected bonds and options:

$$
\min_{\boldsymbol\phi\in\Theta}
\left\{\sum_i w_i^B(P_i^{\mathrm{model}}-P_i^{\mathrm{mkt}})^2
+\sum_jw_j^O(V_j^{\mathrm{model}}-V_j^{\mathrm{mkt}})^2\right\}.
$$

The weights, admissible parameter region \(\Theta\), volatility quotation method and instrument conventions must be specified. A good price fit alone does not guarantee stable parameters or hedge sensitivities.

---

**Source mapping:** Lecture §§5.1, 5.4, 7.2 (PDF pp. 25–30, 39–42); Monte Carlo estimator and optimisation objective supplementary.

**Suggested references:** [1], [2], [4], [9]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 07 — Volatility and Model Calibration]({{ '/pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
