---
layout: default
title: "6.1 — Risk-Neutral and Forward Measures"
permalink: /pages/quantitative-finance/notes/fixed-income/06-Arbitrage-Free-Term-Structure-Models/01-Risk-Neutral-and-Forward-Measures/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/06-Arbitrage-Free-Term-Structure-Models/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Risk Neutral and Forward Measures</h1>
  <p class="lead">Foundations and quantitative methods for risk neutral and forward measures.</p>
</div>

<article class="article" markdown="1">


# 6.1 — Risk-Neutral and Forward Measures

## 6.1.1 Risk-neutral valuation

Let \(B(t)\) be the money-market account,

$$
B(t)=\exp\!\left(\int_0^t r(s)\,\mathrm{d}s\right).
$$

In the complete, arbitrage-free semimartingale setting of the lecture, there is an equivalent martingale measure \(\mathbb{Q}\) such that sufficiently integrable self-financing asset prices divided by \(B\) are martingales. A replicable payoff \(H\) at maturity \(T\) then has value

$$
V(t)=B(t)\mathbb{E}^{\mathbb Q}
\left[\frac{H}{B(T)}\middle|\mathcal F_t\right].
$$

In particular,

$$
P(t,T)=\mathbb{E}^{\mathbb Q}\!\left[
 e^{-\int_t^T r(u)\,\mathrm{d}u}\middle|\mathcal F_t\right].
$$

The dependence between the future payoff and the stochastic discount factor generally prevents one from separating the expectation into a price times a payoff expectation under \(\mathbb Q\).

## 6.1.2 Numéraire pairs

A **numéraire** is a strictly positive traded asset or self-financing portfolio used to express other traded prices in relative units. A numéraire pair \((N,\mathbb{Q}^N)\) is chosen so that appropriately integrable relative prices \(S/N\) are martingales under \(\mathbb{Q}^N\).

If \(U\) is another eligible numéraire, the change-of-numéraire density process is

$$
\left.\frac{\mathrm{d}\mathbb Q^U}{\mathrm{d}\mathbb Q^N}
\right|_{\mathcal F_t}
=\frac{U(t)/U(0)}{N(t)/N(0)}.
$$

The valuation formula is independent of the eligible numéraire:

$$
V(t)=U(t)\mathbb{E}^{\mathbb Q^U}
\left[\frac{H}{U(T)}\middle|\mathcal F_t\right].
$$

## 6.1.3 The \(T\)-forward measure

Choose as numéraire the strictly positive zero-coupon bond maturing at \(T\), whose price is \(P(t,T)\). The associated measure is written \(\mathbb{Q}^T\), and relative to the money-market measure,

$$
\left.\frac{\mathrm{d}\mathbb Q^T}{\mathrm{d}\mathbb Q}
\right|_{\mathcal F_t}
=\frac{P(t,T)}{P(0,T)B(t)}
\qquad\text{when }B(0)=1.
$$

Because \(P(T,T)=1\), a claim paid at \(T\) has the convenient price

$$
V(t)=P(t,T)\mathbb{E}^{\mathbb Q^T}
\left[H\mid\mathcal F_t\right].
$$

## 6.1.4 Forward prices are martingales

For a non-dividend-paying traded underlying \(S\), the time-\(t\) delivery price of a zero-value forward contract is

$$
F(t,T)=\frac{S(t)}{P(t,T)}.
$$

Because the ratio of traded prices to the bond numéraire is a \(\mathbb Q^T\)-martingale,

$$
F(t,T)=\mathbb{E}^{\mathbb Q^T}[S(T)\mid\mathcal F_t].
$$

Applying the same reasoning to bond-price ratios produces the martingale property of forward simple rates and eventually the Black caplet formula.

---


**Suggested references:** [1], [7], [9], [10]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 06 — Arbitrage-Free Term-Structure Models]({{ '/pages/quantitative-finance/notes/fixed-income/06-Arbitrage-Free-Term-Structure-Models/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
