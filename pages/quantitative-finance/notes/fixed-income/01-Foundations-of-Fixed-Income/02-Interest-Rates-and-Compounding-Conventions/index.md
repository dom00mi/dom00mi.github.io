---
layout: default
title: "1.2 — Interest Rates and Compounding Conventions"
permalink: /pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/02-Interest-Rates-and-Compounding-Conventions/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Interest Rates and Compounding Conventions</h1>
  <p class="lead">Foundations and quantitative methods for interest rates and compounding conventions.</p>
</div>

<article class="article" markdown="1">


# 1.2 — Interest Rates and Compounding Conventions

## 1.2.1 Simple interest

A simple interest rate \(L\) over a year fraction \(δ\) turns one unit invested at the beginning of a period into

$$
1+\delta L.
$$

For a zero-coupon bond spanning the same period,

$$
P(t,T)=\frac{1}{1+(T-t)L(t,T)},
\qquad
L(t,T)=\frac{P(t,T)^{-1}-1}{T-t}.
$$

The source notes refer to the historical market quote as the spot LIBOR rate. The algebraic discount-factor identity is more general than the benchmark's historical name.

## 1.2.2 Discrete compounding

Let \(0=t_0<t_1<\cdots<t_n=T\), with \(\Delta t_k=t_k-t_{k-1}\). If \(r_k\) applies over period \(k\), the accumulated value of one unit is

$$
X_n=\prod_{k=1}^{n}\left(1+r_k\Delta t_k\right).
$$

For a constant nominal annual rate \(r\) compounded \(m\) times each year over \(τ\) years, this becomes

$$
A_m(\tau)=\left(1+\frac{r}{m}\right)^{m\tau},
\qquad
D_m(\tau)=\left(1+\frac{r}{m}\right)^{-m\tau}.
$$

## 1.2.3 Continuous compounding

Taking finer and finer partitions, under regularity assumptions,

$$
\lim_{\max_k\Delta t_k\to0}
\prod_{k=1}^{n}(1+r_k\Delta t_k)
=\exp\!\left(\int_0^T r(s)\,\mathrm{d}s\right).
$$

For constant continuously compounded rate \(r_c\), the accumulation factor is \(e^{r_c\tau}\). Equating it to periodic accumulation gives the convention conversion

$$
r_c=m\log\!\left(1+\frac{r}{m}\right),
\qquad
r=m\left(e^{r_c/m}-1\right).
$$

A rate quotation has meaning only when its accrual interval, compounding convention, and applicable day-count fraction have been specified. In swap notation the accrual fractions are often written \(δ_k\).

## 1.2.4 Continuous and simple zero-rate representations

If the same maturity \(T\) has continuously compounded zero rate \(R(t,T)\) and simple rate \(L(t,T)\), then

$$
e^{R(t,T)(T-t)}=1+(T-t)L(t,T).
$$

Thus the numerical value of the quoted rate depends on the convention even when the underlying price \(P(t,T)\) is identical. Discount factors are the convention-independent object for pricing.

---


**Suggested references:** [1], [2]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 01 — Foundations of Fixed Income]({{ '/pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
