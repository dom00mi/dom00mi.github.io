---
layout: default
title: "4.2 — Interest Rate Swaps and Swap Rates"
permalink: /pages/quantitative-finance/notes/fixed-income/04-Interest-Rate-Derivatives/02-Interest-Rate-Swaps-and-Swap-Rates/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/04-Interest-Rate-Derivatives/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Interest Rate Swaps and Swap Rates</h1>
  <p class="lead">Foundations and quantitative methods for interest rate swaps and swap rates.</p>
</div>

<article class="article" markdown="1">


# 4.2 — Interest Rate Swaps and Swap Rates

## 4.2.1 Structure and payment schedule

A vanilla fixed-for-floating interest-rate swap exchanges two coupon streams in the same currency on a common notional \(N\). Set the reset/payment schedule

$$
t\leq T_0<T_1<\cdots<T_n=T,
\qquad \delta_k=T_k-T_{k-1}.
$$

At payment date \(T_k\), the party **receiving fixed** receives the net amount

$$
N\delta_k\bigl(K-L(T_{k-1},T_k)\bigr).
$$

The fixed rate \(K\) remains constant throughout the life of the contract. The quoted floating rate is reset for the relevant accrual period.

## 4.2.2 Floating and fixed legs in a single-curve market

By the floating-coupon replication lemma,

$$
V_{\mathrm{float}}(t)
=N\sum_{k=1}^{n}\bigl[P(t,T_{k-1})-P(t,T_k)\bigr]
=N\bigl[P(t,T_0)-P(t,T_n)\bigr].
$$

The fixed leg has value

$$
V_{\mathrm{fixed}}(t)
=NK\sum_{k=1}^{n}\delta_kP(t,T_k).
$$

Define the unit-notional **swap annuity** (also called accrual factor in the notes)

$$
A(t;T_0,T_n)=\sum_{k=1}^{n}\delta_kP(t,T_k).
$$

Thus the receive-fixed swap value is

$$
V_{\mathrm{rec.fixed}}(t)=N\left[KA(t;T_0,T_n)-P(t,T_0)+P(t,T_n)\right].
$$

The receive-floating/pay-fixed value is the negative of this expression.

## 4.2.3 Par swap rate

The **forward par swap rate** \(S(t;T_0,T_n)\) is the strike \(K\) that gives initial swap value zero:

$$
S(t;T_0,T_n)
=\frac{P(t,T_0)-P(t,T_n)}{A(t;T_0,T_n)}.
$$

When \(t=T_0\), \(P(t,T_0)=1\) and the spot-starting rate becomes

$$
S(t;t,T_n)=\frac{1-P(t,T_n)}{\sum_{k=1}^{n}\delta_kP(t,T_k)}.
$$

## 4.2.4 Swap rate as a tradable-assets ratio

The numerator is the value of a portfolio of zero-coupon bonds; the denominator is a strictly positive portfolio of zero-coupon bonds. Consequently, under the **annuity measure** associated with \(A\), the forward swap rate is a martingale:

$$
\mathbb{E}^{\mathbb{Q}^{A}}
\left[S(T_0;T_0,T_n)\mid\mathcal{F}_t\right]
=S(t;T_0,T_n).
$$

This observation is central to swaption valuation. In the multiple-curve setting the fixed leg still discounts with the chosen discount curve, but floating rate projections are supplied separately; see §2.3.

---

**Source mapping:** Lecture §3.3 and §3.4.2 (PDF pp. 17–21).

**Suggested references:** [2], [6]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 04 — Interest Rate Derivatives]({{ '/pages/quantitative-finance/notes/fixed-income/04-Interest-Rate-Derivatives/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
