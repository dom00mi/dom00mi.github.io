---
layout: default
title: "5.2 — Cox–Ingersoll–Ross Model"
permalink: /pages/quantitative-finance/notes/fixed-income/05-Short-Rate-Models/02-Cox-Ingersoll-Ross-Model/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/05-Short-Rate-Models/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Cox–Ingersoll–Ross Model</h1>
  <p class="lead">Foundations and quantitative methods for cox–ingersoll–ross model.</p>
</div>

<article class="article" markdown="1">


# 5.2 — Cox–Ingersoll–Ross Model

## 5.2.1 CIR dynamics

The **Cox–Ingersoll–Ross (CIR)** model replaces constant short-rate volatility with a square-root diffusion:

$$
\mathrm{d}r(t)=a\bigl(b-r(t)\bigr)\,\mathrm{d}t
+\sigma\sqrt{r(t)}\,\mathrm{d}W^{\mathbb{Q}}(t),
\qquad a,b,\sigma>0.
$$

The mean-reverting drift is the same as in Vasicek, but the diffusion magnitude decreases towards zero as the rate approaches zero. Starting from a nonnegative rate, the CIR process remains nonnegative; strict inaccessibility of zero is ensured by the additional **Feller condition**

$$
2ab\geq\sigma^2.
$$

The Feller boundary condition is a supplementary standard result; it is not derived in the lecture PDF.

## 5.2.2 Conditional mean

The conditional mean remains of mean-reverting form:

$$
\mathbb{E}^{\mathbb{Q}}[r(T)\mid\mathcal F_t]
=b+\bigl(r(t)-b\bigr)e^{-a(T-t)}.
$$

Unlike Vasicek, the diffusion is state-dependent and the distribution is not Gaussian.

## 5.2.3 Affine pricing equation

The time-\(t\) bond value is

$$
P(t,T)=F^{(T)}(t,r(t)),
$$

where the term-structure PDE becomes

$$
F_t+a(b-x)F_x+\frac12\sigma^2xF_{xx}-xF=0,
\qquad F(T,x)=1.
$$

Use the exponential-affine ansatz

$$
P(t,T)=e^{-A(\tau)-B(\tau)r(t)},
\qquad\tau=T-t.
$$

Matching the constant and linear coefficients of the short rate gives the Riccati equations

$$
\frac{\mathrm{d}B}{\mathrm{d}\tau}
=1-aB-\frac12\sigma^2B^2,
\qquad B(0)=0,
$$

$$
\frac{\mathrm{d}A}{\mathrm{d}\tau}
=abB,\qquad A(0)=0.
$$

Thus CIR belongs to the affine short-rate family introduced in lecture §5.3. The Riccati equations determine its zero-coupon term structure and allow calibration to observed bonds, subject to the model's parameter restrictions.

## 5.2.4 Vasicek versus CIR

Both models are one-factor and mean-reverting. Vasicek permits negative rates but has Gaussian dynamics. CIR keeps rates nonnegative and makes volatility depend on the level. Both constant-parameter models have limited freedom to reproduce an arbitrary initial yield curve; time-dependent extensions address initial-curve fitting.

---

**Source mapping:** Lecture §§5.2–5.4 (PDF pp. 27–30); Feller condition and conditional mean are supplementary standard results.

**Suggested references:** [1], [2], [4]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 05 — Short-Rate Models]({{ '/pages/quantitative-finance/notes/fixed-income/05-Short-Rate-Models/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
