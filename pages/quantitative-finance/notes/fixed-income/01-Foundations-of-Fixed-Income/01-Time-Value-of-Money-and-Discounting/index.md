---
layout: default
title: "1.1 — Time Value of Money and Discounting"
permalink: /pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/01-Time-Value-of-Money-and-Discounting/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Time Value of Money and Discounting</h1>
  <p class="lead">Foundations and quantitative methods for time value of money and discounting.</p>
</div>

<article class="article" markdown="1">


# 1.1 — Time Value of Money and Discounting

## 1.1.1 The time value of money

An amount payable at one date cannot in general be compared directly with the same nominal amount at another date. We choose a valuation date, represent future obligations as dated cashflows, and discount each cashflow to that date. In the idealised default-free market of the lectures, the building blocks are **zero-coupon bonds**.

**Definition (zero-coupon bond).** A zero-coupon bond maturing at \(T\) pays one unit of currency at \(T\) and makes no intermediate payment. Its time-\(t\) value is denoted by \(P(t,T)\), for \(t ≤ T\), and it satisfies

$$
P(T,T)=1.
$$

If an amount \(X\) is paid with certainty at \(T\), its value at \(t\) is

$$
V(t)=X\,P(t,T).
$$

For deterministic dated payments \(C_k\) at maturities \(T_k\), linearity of valuation gives

$$
V(t)=\sum_{k=1}^{n} C_k P(t,T_k).
$$

This decomposition explains why a coupon bond can be viewed as a portfolio of zero-coupon bonds.

## 1.1.2 Continuously compounded discounting

The **zero rate** \(R(t,T)\) is defined through

$$
P(t,T)=\exp\!\left[-R(t,T)(T-t)\right], \qquad t<T.
$$

Equivalently,

$$
R(t,T)=-\frac{\log P(t,T)}{T-t}.
$$

When the interest rate is constant over the interval, this is exponential discounting. A positive zero rate generally corresponds to a discount factor below one; the formal definition also admits negative zero rates.

## 1.1.3 The bank account as a numéraire

Let \(r(t)\) be the instantaneous short rate. The continuously reinvested money-market account \(B(t)\) is defined by

$$
\mathrm{d}B(t)=r(t)B(t)\,\mathrm{d}t,\qquad B(0)=1,
$$

so that

$$
B(t)=\exp\!\left(\int_0^t r(s)\,\mathrm{d}s\right).
$$

In an arbitrage-free market admitting a suitable risk-neutral measure \(Q\), a default-free claim of one unit at \(T\) is priced by

$$
P(t,T)=\mathbb{E}^{\mathbb{Q}}\!\left[
\exp\!\left(-\int_t^T r(s)\,\mathrm{d}s\right)
\middle|\mathcal{F}_t\right].
$$

The last formula is particularly important: **when short rates are stochastic, the discount factor inside the expectation is random**. In general it cannot be replaced by an exponential at the expected future short rate. The precise no-arbitrage argument is developed in Chapter 6.

## 1.1.4 Assumptions of the lecture framework

The source assumes a frictionless, liquid continuum of default-free bonds, sufficiently smooth prices as functions of maturity, and no arbitrage. These are modelling assumptions, not literal descriptions of every bond market.

---


**Suggested references:** [1], [2], [9]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 01 — Foundations of Fixed Income]({{ '/pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
