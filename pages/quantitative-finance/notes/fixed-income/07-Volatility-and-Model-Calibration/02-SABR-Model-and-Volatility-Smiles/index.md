---
layout: default
title: "7.2 — SABR Model and Volatility Smiles"
permalink: /pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/02-SABR-Model-and-Volatility-Smiles/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>SABR Model and Volatility Smiles</h1>
  <p class="lead">Foundations and quantitative methods for sabr model and volatility smiles.</p>
</div>

<article class="article" markdown="1">


# 7.2 — SABR Model and Volatility Smiles

> **Scope:** SABR is introduced here as supplementary volatility-smile theory and is developed for the modelling applications in this chapter.

## 7.2.1 Why a volatility-smile model is needed

A single lognormal volatility assumes that every option strike is priced by the same volatility parameter. In practice one may observe a strike-dependent **implied volatility smile** or skew. A stochastic-volatility model introduces a second source of randomness to create richer distributions of the forward rate at option expiry.

## 7.2.2 SABR dynamics

A standard **stochastic alpha, beta, rho (SABR)** specification for a positive forward \(F_t\) is

$$
\mathrm{d}F_t=\alpha_t F_t^{\beta}\,\mathrm{d}W_t^{(1)},
$$

$$
\mathrm{d}\alpha_t=\nu\alpha_t\,\mathrm{d}W_t^{(2)},
\qquad
\mathrm{d}\langle W^{(1)},W^{(2)}\rangle_t=\rho\,\mathrm{d}t,
$$

with parameter restrictions

$$
\alpha_0>0,\qquad 0\le\beta\le1,
\qquad\nu\ge0,\qquad -1<\rho<1.
$$

In this simplified formulation, \(F_t\) is intended to be a forward martingale under the appropriate pricing measure; boundary behaviour depends on the choice of \(\beta\) and model conventions.

## 7.2.3 Parameter interpretation

The initial volatility level is controlled by \(\alpha_0\); \(\beta\) controls the dependence of the forward's instantaneous absolute volatility on its level; \(\rho\) governs instantaneous correlation between forward and volatility shocks; \(\nu\) is the volatility of \(\alpha_t\). Changing the correlation and volatility-of-volatility parameters allows the model to represent different shapes of skew and smile.

The instantaneous conditional variance of the forward increment is

$$
\operatorname{Var}(\mathrm{d}F_t\mid\mathcal F_t)
\approx\alpha_t^2F_t^{2\beta}\,\mathrm{d}t.
$$

For \(\beta=1\) the forward uses lognormal-style scaling; for \(\beta=0\) its noise has normal-style scaling.

## 7.2.4 Calibration concept

Given market prices or consistently quoted implied volatilities at one expiry and several strikes, seek parameters \(\boldsymbol\theta=(\alpha_0,\beta,\rho,\nu)\) that minimise a weighted pricing error:

$$
\min_{\boldsymbol\theta}
\sum_{i=1}^{m}w_i\left[
V^{\mathrm{SABR}}(K_i;\boldsymbol\theta)
-V^{\mathrm{mkt}}(K_i)\right]^2.
$$

The implied-volatility approximation, numerical pricing method, shift convention, and treatment of negative forward rates must be specified before the model is operational. For low or negative rates, **shifted SABR** is often considered, but that construction is developed separately here.

---


**Suggested references:** [2] (broad background on smile models). See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 07 — Volatility and Model Calibration]({{ '/pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
