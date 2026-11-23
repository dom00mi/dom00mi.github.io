---
layout: default
title: "4.4 — Swaptions and Option Pricing"
permalink: /pages/quantitative-finance/notes/fixed-income/04-Interest-Rate-Derivatives/04-Swaptions-and-Option-Pricing/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/04-Interest-Rate-Derivatives/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Swaptions and Option Pricing</h1>
  <p class="lead">Foundations and quantitative methods for swaptions and option pricing.</p>
</div>

<article class="article" markdown="1">


# 4.4 — Swaptions and Option Pricing

## 4.4.1 Swaption contracts

A **payer swaption** gives its holder the right at expiry \(T_0\) to enter a swap paying a predetermined fixed strike \(K\) and receiving floating. A **receiver swaption** gives the right to receive fixed. The underlying swap pays on dates \(T_1,\ldots,T_n\).

In the single-curve framework the unit-notional pay-fixed swap value at time \(t\) is

$$
V_{\mathrm{swap}}(t)=P(t,T_0)-P(t,T_n)
-K\sum_{k=1}^{n}\delta_kP(t,T_k).
$$

At \(T_0\) the payer swaption therefore pays

$$
\left[1-K\sum_{k=1}^{n}\delta_kP(T_0,T_k)-P(T_0,T_n)\right]^+.
$$

It may be interpreted as a put on the corresponding coupon-bearing bond.

## 4.4.2 Swaption as an option on the swap rate

Let

$$
A(t)=\sum_{k=1}^{n}\delta_kP(t,T_k),
\qquad S(t)=\frac{P(t,T_0)-P(t,T_n)}{A(t)}.
$$

The payer swaption payoff at expiry becomes

$$
X_{T_0}=A(T_0)\bigl(S(T_0)-K\bigr)^+.
$$

The annuity is a strictly positive portfolio of traded zero-coupon bonds. It can be used as numéraire, giving a measure \(\mathbb{Q}^{A}\) under which the forward swap rate is a martingale:

$$
V_{\mathrm{payer}}(t)
=A(t)\mathbb{E}^{\mathbb{Q}^{A}}
\left[(S(T_0)-K)^+\mid\mathcal{F}_t\right].
$$

## 4.4.3 Black's swaption formula

Suppose the forward swap rate is lognormal under \(\mathbb{Q}^A\):

$$
\mathrm{d}S(t)=S(t)\boldsymbol{\sigma}_S(t)
\cdot\mathrm{d}\boldsymbol{W}^{A}(t).
$$

With total variance

$$
\nu^2=\int_t^{T_0}\lVert\boldsymbol{\sigma}_S(u)\rVert^2\,\mathrm{d}u,
$$

its payer swaption price is

$$
V_{\mathrm{payer}}(t)=A(t)
\left[S(t)\Phi(d_1)-K\Phi(d_2)\right],
$$

$$
d_1=\frac{\log(S(t)/K)+\nu^2/2}{\nu},
\qquad d_2=d_1-\nu.
$$

For notional \(N\), multiply the entire result by \(N\). The model treats the **annuity** as the numéraire, not the money-market account. This choice is what makes the swap rate a martingale.

## 4.4.4 Model consistency

A model in which every forward LIBOR is exactly lognormal need not make forward swap rates lognormal as well. A swap rate is a nonlinear ratio of bond-price combinations, and the two assumptions are generally not simultaneously exact; see the swap market model discussion in Section 7.3.

---


**Suggested references:** [2], [6], [7]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 04 — Interest Rate Derivatives]({{ '/pages/quantitative-finance/notes/fixed-income/04-Interest-Rate-Derivatives/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
