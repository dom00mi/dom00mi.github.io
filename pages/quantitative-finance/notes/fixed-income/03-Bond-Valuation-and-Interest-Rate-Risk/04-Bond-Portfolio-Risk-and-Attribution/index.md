---
layout: default
title: "3.4 — Bond Portfolio Risk and Attribution"
permalink: /pages/quantitative-finance/notes/fixed-income/03-Bond-Valuation-and-Interest-Rate-Risk/04-Bond-Portfolio-Risk-and-Attribution/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/03-Bond-Valuation-and-Interest-Rate-Risk/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Bond Portfolio Risk and Attribution</h1>
  <p class="lead">Foundations and quantitative methods for bond portfolio risk and attribution.</p>
</div>

<article class="article" markdown="1">


# 3.4 — Bond Portfolio Risk and Attribution

> **Scope:** Portfolio attribution and factor-risk reporting are not developed in the lecture PDF. This section assembles a concise supplementary framework from its present-value and sensitivity equations.

## 3.4.1 Portfolio valuation

If a portfolio holds \(h_i\) units of bond \(i\), its value is additive:

$$
V(t)=\sum_{i=1}^{M}h_iB_i(t).
$$

For a given scalar yield shift, the portfolio's currency duration exposure is the sum of currency price derivatives:

$$
\frac{\partial V}{\partial y}
=\sum_{i=1}^{M}h_i\frac{\partial B_i}{\partial y}.
$$

A normalised duration is meaningful only after dividing by a well-defined, nonzero portfolio value; offsetting long and short positions can make such normalisation unstable.

## 3.4.2 Curve-factor exposure

Let \(\boldsymbol{z}\) be the rate-pillar vector. For a small move \(\Delta\boldsymbol{z}\),

$$
\Delta V\approx
\nabla_{\boldsymbol{z}}V^{\mathsf T}\Delta\boldsymbol{z}
+\frac12\Delta\boldsymbol{z}^{\mathsf T}
\nabla^2_{\boldsymbol{z}}V\,\Delta\boldsymbol{z}.
$$

The gradient captures first-order curve risk and the Hessian captures second-order effects, including cross-maturity convexity.

## 3.4.3 A conceptual attribution decomposition

Over a holding period, a useful *accounting* partition is

$$
\Delta V
=\underbrace{\text{coupon and accrual}}_{\text{income}}
+\underbrace{\text{curve-driven repricing}}_{\text{rates}}
+\underbrace{\text{other repricing and residual}}_{\text{basis, spread, model}}.
$$

The precise attribution is convention-dependent; one must decide whether carry, roll-down, credit-spread moves and financing are separate components before calculating contributions. The lecture source does not establish a unique attribution methodology.

## 3.4.4 Risk aggregation principles

Parallel duration, key-rate sensitivities and dynamic factor exposures answer different questions. When a portfolio contains instruments with different cashflow conventions or embedded options, sensitivities should be recomputed under the same valuation framework before aggregation.

---

**Source mapping:** Supplementary applications of lecture §§3.1, 4 (PDF pp. 15–16, 22–24).

**Suggested references:** [2], [4]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 03 — Bond Valuation and Interest Rate Risk]({{ '/pages/quantitative-finance/notes/fixed-income/03-Bond-Valuation-and-Interest-Rate-Risk/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
