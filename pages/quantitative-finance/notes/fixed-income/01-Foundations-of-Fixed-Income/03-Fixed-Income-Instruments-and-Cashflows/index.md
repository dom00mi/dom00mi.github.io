---
layout: default
title: "1.3 — Fixed Income Instruments and Cashflows"
permalink: /pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/03-Fixed-Income-Instruments-and-Cashflows/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Fixed Income Instruments and Cashflows</h1>
  <p class="lead">Foundations and quantitative methods for fixed income instruments and cashflows.</p>
</div>

<article class="article" markdown="1">


# 1.3 — Fixed Income Instruments and Cashflows

## 1.3.1 Bonds as dated payment contracts

A bond is a contract through which an issuer receives funds and promises dated payments to the holder. A conventional fixed-coupon bond pays coupons on predetermined dates and repays notional at maturity. In the source, zero-coupon bonds are the fundamental instruments because any **deterministic** cashflow stream can be decomposed into their payoffs.

Let

$$
t\leq T_0<T_1<\cdots<T_n=T,
$$

and let the bond pay coupons \(c_k\) at \(T_k\) and principal \(N\) at \(T\). Its cashflow stream and default-free value are

$$
\mathrm{CF}(T_k)=c_k+N\mathbf{1}_{\{k=n\}},
$$

$$
P^{(c)}(t,T)=\sum_{k=1}^{n}c_kP(t,T_k)+NP(t,T).
$$

## 1.3.2 Coupon conventions

If a coupon accrues at quoted annual rate \(q_k\) over year fraction \(δ_k\), then

$$
c_k=Nq_k\delta_k.
$$

For a constant coupon rate \(q\) and equal accrual intervals \(δ\),

$$
P^{(c)}(t,T)=N\left[q\delta\sum_{k=1}^{n}P(t,T_k)+P(t,T)\right].
$$

For coupons paid periodically, the payment frequency and accrual schedule matter even when the annual coupon rate is unchanged.

## 1.3.3 Floating-rate notes

A floating-rate note resets each coupon with an observed reference rate. In the **single-curve, default-free framework** of the lecture notes, the coupon due at \(T_k\) is

$$
c_k=N\delta_kL(T_{k-1},T_k).
$$

The fair value of the floating coupon, for \(t ≤ T_{k-1}\), follows from a bond replication argument:

$$
\operatorname{PV}_t\!\left[\delta_k L(T_{k-1},T_k)
\text{ paid at }T_k\right]
=P(t,T_{k-1})-P(t,T_k).
$$

Adding all coupons plus final redemption telescopes:

$$
V_{\mathrm{FRN}}(t)=N\left[\sum_{k=1}^{n}
\bigl(P(t,T_{k-1})-P(t,T_k)\bigr)+P(t,T_n)\right]
=NP(t,T_0).
$$

Therefore **at a reset/payment date \(t=T_0\), a par floater is worth \(N\)** under these assumptions. A credit spread, a margin, or multi-curve discounting changes this simple conclusion.

## 1.3.4 Instrument classification

The source develops zero-coupon bonds, fixed-coupon bonds, floating-rate notes, swaps, caps, floors and swaptions. The latter instruments exchange or option interest-rate cashflows rather than simply promise a fixed redemption; their payoffs are treated systematically in Chapter 4.

---

**Source mapping:** Lecture §§1.1, 3.1–3.3 (PDF pp. 4, 15–18).

**Suggested references:** [1], [2], [6]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 01 — Foundations of Fixed Income]({{ '/pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
