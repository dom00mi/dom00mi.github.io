---
layout: default
title: "8.1 — Yield-Curve PCA and Factor Models"
permalink: /pages/quantitative-finance/notes/fixed-income/08-Yield-Curve-Modelling-and-Applications/01-Yield-Curve-PCA-and-Factor-Models/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/08-Yield-Curve-Modelling-and-Applications/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Yield Curve PCA and Factor Models</h1>
  <p class="lead">Foundations and quantitative methods for yield curve pca and factor models.</p>
</div>

<article class="article" markdown="1">


# 8.1 — Yield-Curve PCA and Factor Models

> **Scope:** Principal-component analysis (PCA) provides a statistical application of the yield-curve representations developed in this chapter.

## 8.1.1 A finite-dimensional observation of the yield curve

Although a continuous curve is a function of maturity, empirical studies start from a finite set of consistently constructed maturity pillars:

$$
\boldsymbol{y}_t
=\bigl(y_t(T_1),\ldots,y_t(T_m)\bigr)^{\mathsf T}.
$$

Here \(y_t(T_i)\) could denote zero rates, par swap rates, or another fixed convention, but the series should not mix incompatible rate definitions.

Choose a sampling interval and form rate changes

$$
\Delta\boldsymbol y_t=\boldsymbol y_t-\boldsymbol y_{t-1}.
$$

## 8.1.2 Covariance matrix

Given \(n\) observed change vectors, let

$$
\overline{\Delta\boldsymbol y}
=\frac1n\sum_{t=1}^n\Delta\boldsymbol y_t.
$$

The sample covariance matrix is

$$
\widehat\Sigma=\frac{1}{n-1}\sum_{t=1}^{n}
\bigl(\Delta\boldsymbol y_t-\overline{\Delta\boldsymbol y}\bigr)
\bigl(\Delta\boldsymbol y_t-\overline{\Delta\boldsymbol y}\bigr)^{\mathsf T}.
$$

Its eigenvalue decomposition is

$$
\widehat\Sigma=U\Lambda U^{\mathsf T},
\qquad
\widehat\Sigma\boldsymbol u_j=\lambda_j\boldsymbol u_j.
$$

The orthonormal eigenvectors \(\boldsymbol u_j\) represent directions of yield-curve movements; larger eigenvalues describe larger sample variance along their directions.

## 8.1.3 Factor scores and reconstruction

For a change vector, the score on principal component \(j\) is

$$
z_{t,j}=\boldsymbol u_j^{\mathsf T}
\bigl(\Delta\boldsymbol y_t-\overline{\Delta\boldsymbol y}\bigr).
$$

Using the first \(k\) components,

$$
\Delta\boldsymbol y_t
\approx\overline{\Delta\boldsymbol y}
+\sum_{j=1}^{k}z_{t,j}\boldsymbol u_j.
$$

The explained-variance fraction is

$$
\mathrm{EV}(k)=\frac{\sum_{j=1}^{k}\lambda_j}{\sum_{j=1}^{m}\lambda_j}.
$$

The labels *level*, *slope* and *curvature* are common interpretations of leading components, not universal mathematical identities.

## 8.1.4 Relation to interest-rate models

PCA describes historical covariance of curve changes. An HJM volatility field instead appears in stochastic differential equations and must obey no-arbitrage drift restrictions. A historical factor model alone is not an arbitrage-free derivative-pricing model.

---


**Suggested references:** [4], [5] (term-structure modelling background; not direct PCA citations). See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 08 — Yield-Curve Modelling and Applications]({{ '/pages/quantitative-finance/notes/fixed-income/08-Yield-Curve-Modelling-and-Applications/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
