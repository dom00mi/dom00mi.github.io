---
layout: default
title: "6.3 — LIBOR Market Model"
permalink: /pages/quantitative-finance/notes/fixed-income/06-Arbitrage-Free-Term-Structure-Models/03-LIBOR-Market-Model/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/06-Arbitrage-Free-Term-Structure-Models/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>LIBOR Market Model</h1>
  <p class="lead">Foundations and quantitative methods for libor market model.</p>
</div>

<article class="article" markdown="1">


# 6.3 — LIBOR Market Model

## 6.3.1 Why market models are built on simple forward rates

The lecture notes explain that making every **instantaneous continuously compounded forward rate** lognormal is difficult in an HJM model. Interest-rate derivatives, however, commonly depend on **simple forward rates over finite accrual periods**. Market models therefore take these forwards as their underlying state variables.

For dates \(T_0<T_1<\cdots<T_n\), define

$$
\delta_k=T_k-T_{k-1},
\qquad
L_k(t)=\frac{1}{\delta_k}
\left(\frac{P(t,T_{k-1})}{P(t,T_k)}-1\right),
\quad t\le T_{k-1}.
$$

## 6.3.2 Each forward rate has its own forward measure

Because \(P(t,T_{k-1})/P(t,T_k)\) is a martingale under the \(T_k\)-forward measure, \(L_k\) is also a martingale under \(\mathbb Q^{T_k}\). The **lognormal LIBOR market model** specifies

$$
\mathrm{d}L_k(t)=L_k(t)\boldsymbol\sigma_k(t)
\cdot\mathrm{d}\boldsymbol W^{T_k}(t),
\qquad t\le T_{k-1},
$$

where the volatility vectors are deterministic in the version developed in the lectures.

The caplet written on \(L_k\) is therefore priced with a Black formula using

$$
\nu_k^2(t)=\int_t^{T_{k-1}}
\lVert\boldsymbol\sigma_k(u)\rVert^2\,\mathrm{d}u.
$$

## 6.3.3 Consistency across forward measures

Different forward rates cannot be evolved independently under unrelated probability measures. To construct a single joint model, the source uses the **terminal measure** \(\mathbb Q^{T_n}\). With the conventions of its Eq. (7.9), the common-measure SDE is

$$
\mathrm{d}L_k(t)=L_k(t)\boldsymbol\sigma_k(t)\cdot
\left[\mathrm{d}\boldsymbol W^{T_n}(t)
-\sum_{j=k+1}^{n}
\frac{\delta_j L_j(t)}{1+\delta_jL_j(t)}
\boldsymbol\sigma_j(t)\,\mathrm{d}t\right].
$$

The terminal forward rate \(L_n\) has zero drift in this representation. Earlier forwards acquire state-dependent drifts through their correlations with later forwards. The rate-dependent drift makes simulation of a collection of forwards more complex than pricing an isolated caplet.

## 6.3.4 Linking rate and bond volatilities

Let the HJM bond volatility vector be

$$
\boldsymbol\gamma(t,T)=-\int_t^T\boldsymbol\sigma_f(t,u)\,\mathrm{d}u.
$$

The lecture derives

$$
\boldsymbol\sigma_k(t)=
\frac{1+\delta_k L_k(t)}{\delta_k L_k(t)}
\left[\boldsymbol\gamma(t,T_{k-1})-\boldsymbol\gamma(t,T_k)\right],
$$

for positive \(L_k\). Thus the lognormal forward-rate volatility and the bond volatility cannot be chosen arbitrarily and independently.

## 6.3.5 Swap market models and the modern benchmark setting

The source also considers a **swap market model**, using a lognormal swap rate under an annuity measure. It observes that exact lognormality of every forward simple rate and every swap rate is generally incompatible.

Following the transition from LIBOR to overnight benchmarks, backward-looking compounded rates require adjustments to the traditional LMM construction. The PDF mentions the extension using new bond-like numéraires for rates fixed in arrears, but does not work out a complete post-LIBOR market model.

---

**Source mapping:** Lecture §§7.1–7.3 and §8 (PDF pp. 38–49).

**Suggested references:** [2], [5], [6], [7]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 06 — Arbitrage-Free Term-Structure Models]({{ '/pages/quantitative-finance/notes/fixed-income/06-Arbitrage-Free-Term-Structure-Models/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
