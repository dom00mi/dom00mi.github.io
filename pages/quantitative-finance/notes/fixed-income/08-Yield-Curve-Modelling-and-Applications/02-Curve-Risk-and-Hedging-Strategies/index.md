---
layout: default
title: "8.2 — Curve Risk and Hedging Strategies"
permalink: /pages/quantitative-finance/notes/fixed-income/08-Yield-Curve-Modelling-and-Applications/02-Curve-Risk-and-Hedging-Strategies/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/08-Yield-Curve-Modelling-and-Applications/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Curve Risk and Hedging Strategies</h1>
  <p class="lead">Foundations and quantitative methods for curve risk and hedging strategies.</p>
</div>

<article class="article" markdown="1">


# 8.2 — Curve Risk and Hedging Strategies

> **Scope:** This chapter applies the lecture's bond-price and duration equations to factor hedging. Key-rate hedging and hedge optimisation are supplementary, not separately derived in the PDF.

## 8.2.1 Curve-risk vector

For discounting pillars or zero rates \(\boldsymbol z=(z_1,\ldots,z_m)\), a portfolio value \(V(\boldsymbol z)\) has first-order sensitivity vector

$$
\boldsymbol g=\nabla_{\boldsymbol z}V.
$$

A small change in rates produces the first-order approximation

$$
\Delta V\approx\boldsymbol g^{\mathsf T}\Delta\boldsymbol z.
$$

For a single continuously compounded yield, the lecture's duration formula is

$$
\frac{\partial V}{\partial y}=-V D(y).
$$

The corresponding positive currency loss for a +1 bp yield move is approximately \(VD\times10^{-4}\). A *vector* of key-rate sensitivities is needed to capture nonparallel changes.

## 8.2.2 Factor exposures

Suppose empirical or modelled factors describe moves as

$$
\Delta\boldsymbol z\approx F\Delta\boldsymbol x,
$$

where each column of \(F\) is a curve-shape direction. Then

$$
\Delta V\approx\bigl(F^{\mathsf T}\boldsymbol g\bigr)^{\mathsf T}
\Delta\boldsymbol x.
$$

The vector \(F^{\mathsf T}\boldsymbol g\) gives first-order exposure to the selected factors, such as level, slope or curvature shocks.

## 8.2.3 Hedging with liquid instruments

Let the columns of \(H\) be the maturity-bucket sensitivities of available hedge instruments. Hedge quantities \(\boldsymbol h\) that perfectly offset first-order risks solve

$$
H\boldsymbol h=-\boldsymbol g.
$$

If the equations cannot be solved exactly, a weighted least-squares hedge minimises

$$
\min_{\boldsymbol h}
\bigl(H\boldsymbol h+\boldsymbol g\bigr)^{\mathsf T}
W\bigl(H\boldsymbol h+\boldsymbol g\bigr),
$$

where \(W\) weights the importance of residual risk directions. Instrument costs and hedge limits can be included as additional constraints.

## 8.2.4 Residual risks

Matching duration or a finite set of factor exposures does not eliminate convexity, basis risk, credit risk or model risk. The source's multiple-curve framework is an important warning: a swap referencing a tenor-specific index may not respond to curve moves in the same way as an idealised single-curve discount-factor portfolio.

---

**Source mapping:** Supplementary applications of lecture §§3.1, 3.3, 8 (PDF pp. 15–18, 46–49).

**Suggested references:** [2], [4]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 08 — Yield-Curve Modelling and Applications]({{ '/pages/quantitative-finance/notes/fixed-income/08-Yield-Curve-Modelling-and-Applications/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
