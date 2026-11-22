---
layout: default
title: "Fixed Income — Mathematical Finance Notes"
permalink: /pages/quantitative-finance/notes/fixed-income/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Notes</div>
  <h1>Fixed Income Notes</h1>
  <p class="lead">Mathematical finance notes on discounting, yield curves, interest-rate derivatives and term-structure models.</p>
</div>

<article class="article" markdown="1">


# Fixed Income

*From discounting and yield curves to arbitrage-free interest-rate modelling.*


The source's core topics are treated in detail. Some of the requested headings—including bootstrapping, interpolation, futures, DV01, PCA, SABR and relative value—go beyond the PDF; those notes explicitly identify their **supplementary** status. Models referring to LIBOR are presented as the historical market-model constructions in the source, while the overnight-rate/multi-curve changes are discussed separately.

## Chapters

| Chapter | Focus | Notes |
|:--|:--|:--|
| **01 — Foundations of Fixed Income** | Start with the time value of money, zero-coupon bond prices, accumulation conventions and the cashflow decomposition of fixed- and floating-rate bonds. | [Read chapter]({{ '/pages/quantitative-finance/notes/fixed-income/01-Foundations-of-Fixed-Income/' | relative_url }}) |
| **02 — Yield Curves and Term Structures** | Develop discount, zero and forward curves; then distinguish the lecture’s term-structure identities from supplementary numerical curve construction and the OIS/multi-curve setting. | [Read chapter]({{ '/pages/quantitative-finance/notes/fixed-income/02-Yield-Curves-and-Term-Structures/' | relative_url }}) |
| **03 — Bond Valuation and Interest Rate Risk** | Price coupon bonds, define their continuously compounded yield, derive duration and convexity, and extend the same sensitivities to portfolio-level risk. | [Read chapter]({{ '/pages/quantitative-finance/notes/fixed-income/03-Bond-Valuation-and-Interest-Rate-Risk/' | relative_url }}) |
| **04 — Interest Rate Derivatives** | Value forward-rate agreements, fixed-for-floating swaps, caps, floors and swaptions using bond replication, forward measures and annuity numeraires. | [Read chapter]({{ '/pages/quantitative-finance/notes/fixed-income/04-Interest-Rate-Derivatives/' | relative_url }}) |
| **05 — Short-Rate Models** | Study the risk-neutral short-rate pricing PDE and affine models, including Vasicek, CIR and Hull–White extensions and initial term-structure calibration. | [Read chapter]({{ '/pages/quantitative-finance/notes/fixed-income/05-Short-Rate-Models/' | relative_url }}) |
| **06 — Arbitrage-Free Term-Structure Models** | Derive change-of-numéraire valuation, the HJM no-arbitrage drift restriction, and the construction of a consistent forward-LIBOR market model. | [Read chapter]({{ '/pages/quantitative-finance/notes/fixed-income/06-Arbitrage-Free-Term-Structure-Models/' | relative_url }}) |
| **07 — Volatility and Model Calibration** | Connect market Black volatilities with caplet and swaption pricing, then add clearly marked supplementary normal volatility, SABR and numerical-calibration notes. | [Read chapter]({{ '/pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/' | relative_url }}) |
| **08 — Yield-Curve Modelling and Applications** | Extend the curve identities towards PCA, factor risk, hedging and scenario analysis. These applications are clearly marked as supplementary where the PDF does not cover them. | [Read chapter]({{ '/pages/quantitative-finance/notes/fixed-income/08-Yield-Curve-Modelling-and-Applications/' | relative_url }}) |


## References


[1] T. Björk, *Arbitrage Theory in Continuous Time*, Oxford University Press, 3rd ed., 2009.

[2] D. Brigo and F. Mercurio, *Interest Rate Models — Theory and Practice: With Smile, Inflation and Credit*, Springer Finance, Springer, 2nd ed., 2006.

[3] D. Brigo, M. Morini and A. Pallavicini, *Counterparty Credit Risk, Collateral and Funding*, Wiley, 2013.

[4] D. Filipović, *Term-Structure Models: A Graduate Course*, Springer Finance, Springer, 2009.

[5] D. Heath, R. Jarrow and A. Morton, “Bond Pricing and the Term Structure of Interest Rates: A New Methodology for Contingent Claims Valuation,” *Econometrica*, **60** (1992), 77–105.

[6] P. Hunt and J. Kennedy, *Financial Derivatives in Theory and Practice*, Wiley, revised ed., 2004.

[7] M. Musiela and M. Rutkowski, *Martingale Methods in Financial Modelling*, Stochastic Modelling and Applied Probability, vol. 36, Springer, 2nd ed., 2005.

[8] P. Schönbucher, *Credit Derivatives Pricing Models*, Wiley, 2003.

[9] S. E. Shreve, *Stochastic Calculus for Finance II: Continuous-Time Models*, Springer Finance, Springer, 2004.

[10] J. Večeř, *Stochastic Finance: A Numeraire Approach*, Chapman & Hall/CRC Financial Mathematics Series, CRC Press, 2011.


</article>
