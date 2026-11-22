---
layout: default
title: "07 — Volatility and Model Calibration"
permalink: /pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/
---
<div class="page-header">
  <a class="back" href="{{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }}">← Back</a>
  <div class="eyebrow">Quantitative Finance / Fixed Income</div>
  <h1>Volatility and Model Calibration</h1>
  <p class="lead">A structured chapter on volatility and model calibration.</p>
</div>

<article class="article" markdown="1">


# 07 — Volatility and Model Calibration

Connect market Black volatilities with caplet and swaption pricing, then add clearly marked supplementary normal volatility, SABR and numerical-calibration notes.

For an option whose relevant forward is lognormal under the corresponding numéraire measure, the lecture uses Black-type pricing with the integrated variance

$$
\nu^2=\int_t^{T_0}\lVert\boldsymbol\sigma(u)\rVert^2\,\mathrm{d}u.
$$

## Subchapters

- **7.1** [Black, Bachelier and Interest-Rate Option Volatility]({{ '/pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/01-Black-Bachelier-and-Interest-Rate-Option-Volatility/' | relative_url }})
- **7.2** [SABR Model and Volatility Smiles]({{ '/pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/02-SABR-Model-and-Volatility-Smiles/' | relative_url }})
- **7.3** [Calibration, Monte Carlo and PDE Pricing]({{ '/pages/quantitative-finance/notes/fixed-income/07-Volatility-and-Model-Calibration/03-Calibration-Monte-Carlo-and-PDE-Pricing/' | relative_url }})

**Primary source mapping:** Lecture §§3.4, 5, 7 (PDF pp. 18–21, 25–30, 38–45); Bachelier, SABR and numerical methods supplemented.

[← All Fixed Income notes]({{ '/pages/quantitative-finance/notes/fixed-income/' | relative_url }})

</article>
