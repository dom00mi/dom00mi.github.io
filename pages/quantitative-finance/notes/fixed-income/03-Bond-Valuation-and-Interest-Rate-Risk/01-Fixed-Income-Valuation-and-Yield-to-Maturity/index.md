---
layout: default
title: "3.1 — Fixed Income Valuation and Yield to Maturity"
permalink: /pages/quantitative-finance/notes/fixed-income/03-Bond-Valuation-and-Interest-Rate-Risk/01-Fixed-Income-Valuation-and-Yield-to-Maturity/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/03-Bond-Valuation-and-Interest-Rate-Risk/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income / Notes</div>
  <h1>Fixed Income Valuation and Yield to Maturity</h1>
  <p class="lead">Foundations and quantitative methods for fixed income valuation and yield to maturity.</p>
</div>

<article class="article" markdown="1">


# 3.1 — Fixed Income Valuation and Yield to Maturity

## 3.1.1 Discounting all promised cashflows

In the default-free framework, the bond's time-\(t\) price is the sum of discounted coupons and principal:

$$
B(t)=\sum_{k=1}^{n}c_kP(t,T_k)+NP(t,T_n).
$$

This formula makes the payment schedule explicit. The price depends on the **whole zero curve** through the discount factors at payment dates.

## 3.1.2 Continuously compounded yield to maturity

For comparison and quotation, the source defines a single yield \(y\) implicitly by

$$
B(t)=\sum_{k=1}^{n}c_ke^{-y(T_k-t)}+Ne^{-y(T_n-t)}.
$$

The same cashflows are repriced using one constant yield instead of the individual zero rates. For strictly positive future cashflows and positive times to payment, the right-hand side is strictly decreasing in \(y\), ensuring at most one real yield for a valid positive bond price.

For a zero-coupon bond, the yield coincides with the zero rate:

$$
y(t,T)=R(t,T)=-\frac{\log P(t,T)}{T-t}.
$$

## 3.1.3 Relationship between the curve and a yield quote

For fixed payment dates, a rise in all continuously compounded zero rates by the same amount \(Δy\) transforms the discount factors as

$$
P_{\mathrm{new}}(t,T_k)=P(t,T_k)e^{-\Delta y(T_k-t)}.
$$

If the original curve is flat at \(y\), this coincides with applying the same shift to the yield in the cashflow formula. For non-flat curves, a yield shift is not equivalent to arbitrary shape changes.

## 3.1.4 Price sensitivity to yield

The first derivative is

$$
\frac{\partial B}{\partial y}
=-\sum_{k=1}^{n}(T_k-t)c_ke^{-y(T_k-t)}
-(T_n-t)Ne^{-y(T_n-t)}.
$$

With positive coupons and principal, a higher yield corresponds to a lower price. Later chapters express the derivative in units of duration, convexity and DV01.

---

**Source mapping:** Lecture §3.1 (PDF pp. 15–16).

**Suggested references:** [1], [2]. See the [numbered bibliography]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}#references).

[← 03 — Bond Valuation and Interest Rate Risk]({{ '/pages/quantitative-finance/notes/fixed-income/03-Bond-Valuation-and-Interest-Rate-Risk/' | relative_url }}) · [All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
