---
layout: default
title: "01 — Foundations of Fixed Income"
permalink: /pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income</div>
  <h1>Foundations of Fixed Income</h1>
  <p class="lead">A structured chapter on foundations of fixed income.</p>
</div>

<article class="article" markdown="1">


# 01 — Foundations of Fixed Income

Start with the time value of money, zero-coupon bond prices, accumulation conventions and the cashflow decomposition of fixed- and floating-rate bonds.

The basic discounting identity is

$$
P(t,T)=\exp\!\left(-\int_t^T f(t,u)\,\mathrm{d}u\right),
$$

and deterministic cashflow streams are priced by

$$
V(t)=\sum_k C_kP(t,T_k).
$$

## Subchapters

- **1.1** [Time Value of Money and Discounting]({{ '/pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/01-Time-Value-of-Money-and-Discounting/' | relative_url }})
- **1.2** [Interest Rates and Compounding Conventions]({{ '/pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/02-Interest-Rates-and-Compounding-Conventions/' | relative_url }})
- **1.3** [Fixed Income Instruments and Cashflows]({{ '/pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/03-Fixed-Income-Instruments-and-Cashflows/' | relative_url }})
- **1.4** [Bond Prices, Yields and Coupon Structures]({{ '/pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/04-Bond-Prices-Yields-and-Coupon-Structures/' | relative_url }})

**Primary source mapping:** Lecture §§1, 3.1–3.2 (PDF pp. 4–9, 15–17).

[← All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
