---
layout: default
title: "1.4 — Bond Prices, Yields and Coupon Structures"
permalink: /pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/04-Bond-Prices-Yields-and-Coupon-Structures/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Bond Prices, Yields and Coupon Structures</h1>
  <p class="lead">Foundations and quantitative methods for bond prices, yields and coupon structures.</p>
</div>

<article class="article" markdown="1">


# 1.4 — Bond Prices, Yields and Coupon Structures

## 1.4.1 Bond prices as functions of a term structure

The cleanest valuation uses **one discount factor for each payment date**, rather than a single yield:

$$
B(t)=\sum_{k=1}^{n}c_kP(t,T_k)+NP(t,T_n).
$$

As rates or maturities change, the curve contributes differently to each coupon. A single yield is useful for quoting and summarising a bond, but it generally loses the curve's maturity structure.

## 1.4.2 Yield to maturity

The lecture notes define a *continuously compounded yield to maturity* \(y\) as the constant rate reproducing the bond price:

$$
B(t)=\sum_{k=1}^{n} c_ke^{-y(T_k-t)}+Ne^{-y(T_n-t)}.
$$

For a zero-coupon bond the implied yield is simply its continuously compounded zero rate:

$$
y(t,T)=-\frac{\log P(t,T)}{T-t}=R(t,T).
$$

For a coupon-bearing bond, the yield implicitly aggregates discount factors from several maturities. Thus it is not generally equal to the zero rate at the final maturity.

## 1.4.3 Par coupon rate

Consider a fixed-rate coupon bond issued at par at \(t=T_0\). If \(c_k=Nq\delta_k\), the par condition gives

$$
N=Nq\sum_{k=1}^{n}\delta_kP(t,T_k)+NP(t,T_n).
$$

Hence its **par coupon rate** satisfies

$$
q_{\mathrm{par}}=
\frac{1-P(t,T_n)}{\sum_{k=1}^{n}\delta_kP(t,T_k)}.
$$

This is the same algebraic structure as the par swap rate in a single-curve setting, but a bond's actual coupon contract, credit risk and conventions need not match a swap.

## 1.4.4 Price–yield monotonicity

Differentiating the continuously compounded-yield price function yields

$$
\frac{\partial B}{\partial y}
=-\sum_{k=1}^{n}(T_k-t)c_ke^{-y(T_k-t)}
-(T_n-t)Ne^{-y(T_n-t)}.
$$

For positive future cashflows this is negative: an increase in yield decreases bond price. The second derivative is positive, giving the usual bond-price convexity, developed in Chapter 3.

---


**Suggested references:** [1], [2]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 01 — Foundations of Fixed Income]({{ '/pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
