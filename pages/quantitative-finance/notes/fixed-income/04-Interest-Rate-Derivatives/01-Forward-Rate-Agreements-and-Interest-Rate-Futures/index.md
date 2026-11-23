---
layout: default
title: "4.1 — Forward Rate Agreements and Interest Rate Futures"
permalink: /pages/quantitative-finance/notes/fixed-income/04-Interest-Rate-Derivatives/01-Forward-Rate-Agreements-and-Interest-Rate-Futures/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/04-Interest-Rate-Derivatives/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Forward Rate Agreements and Interest Rate Futures</h1>
  <p class="lead">Foundations and quantitative methods for forward rate agreements and interest rate futures.</p>
</div>

<article class="article" markdown="1">


# 4.1 — Forward Rate Agreements and Interest Rate Futures

## 4.1.1 Forward rate agreements

A forward rate agreement (FRA) locks in a rate for a future accrual interval \([S,T]\), with year fraction \(\delta=T-S\). In the **single-curve** setting the reference simple rate realised at \(S\) is

$$
L(S,T)=\frac{1}{\delta}\left(\frac{1}{P(S,T)}-1\right).
$$

Consider an FRA with notional \(N\) and a net payment at \(T\) of \(N\delta(L(S,T)-K)\) to the receive-floating party. For \(t\le S\), the replication lemma implies

$$
\operatorname{PV}_t\!\left[\delta L(S,T)
\text{ paid at }T\right]
=P(t,S)-P(t,T).
$$

Hence the FRA value is

$$
V_{\mathrm{FRA}}(t)=N\left[P(t,S)-(1+\delta K)P(t,T)\right].
$$

The unique fair strike in this idealised single-curve setting is

$$
K_{\mathrm{FRA}}(t;S,T)
=\frac{P(t,S)/P(t,T)-1}{\delta}
=L(t;S,T).
$$

## 4.1.2 Forward-measure interpretation

Using the \(T\)-maturity zero-coupon bond as numéraire yields the \(T\)-forward measure \(\mathbb{Q}^T\). The forward simple rate is a martingale under this measure:

$$
L(t;S,T)=\mathbb{E}^{\mathbb{Q}^{T}}
\left[L(S,T)\mid\mathcal{F}_t\right].
$$

Consequently,

$$
V_{\mathrm{FRA}}(t)=N\delta P(t,T)
\left[L(t;S,T)-K\right].
$$

These expressions coincide by the bond-ratio identity.

## 4.1.3 Reset dates and conventions

Some FRA markets settle at the beginning rather than the end of the accrual period; a payment at \(S\) requires an appropriate settlement-adjustment convention. The simple end-payment formula above is the exact convention used to develop the LIBOR replication identity.

## 4.1.4 Interest-rate futures

> **Supplementary note:** Exchange-traded interest-rate futures and futures convexity adjustments are developed here alongside the underlying forward-rate framework.

A futures contract differs from a forward because margin cashflows are settled through time. Under stochastic interest rates, the futures-implied rate and the corresponding FRA forward rate need not agree. Their difference depends on the dynamics and covariation of the underlying rate and discount factors; no universal adjustment can be inferred from the source alone.

---


**Suggested references:** [2], [6], [10]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 04 — Interest Rate Derivatives]({{ '/pages/quantitative-finance/notes/fixed-income/04-Interest-Rate-Derivatives/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
