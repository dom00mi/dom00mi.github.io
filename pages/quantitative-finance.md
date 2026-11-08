---
layout: default
title: Quantitative Finance
permalink: /pages/quantitative-finance/
---
<div class="page-header"><a class="back" href="{{ '/' | relative_url }}">← Back to home</a><div class="eyebrow">Domenico Nava / Research</div><h1>Quantitative Finance</h1><p class="lead">Derivatives, volatility, stochastic modelling and trading research.</p></div><div class="page-image"><img src="https://images.openai.com/static-rsc-4/sqHdLD1W6J0F4tFtKKR1SbYvt0MyK7VkVnBg970AEvcbLxrkl9Qa8PsGyDmAjFT61a3Aqsb6zYXWd3zE1cOWuakvYPtIU9sV_lrzFJEQTEghzp2cccJiovVqAHgbV-iue97pnjJPUrvuLCxxUjaj90PXYj8mchT82QfHm3-O8uM?purpose=inline" alt="Quantitative Finance banner" onerror="this.style.display='none'"></div><article class="article" markdown="1">
## Research areas

- **Volatility modelling:** implied volatility surfaces, calibration and stochastic volatility models.
- **Derivatives & hedging:** pricing, Greeks and dynamic delta hedging.
- **Market microstructure:** market making, order flow and trading models.
- **Fixed income:** yield curve factor models and principal component analysis.

## Project library

> **Work in progress.** The project library is being built gradually; the first project is available below.

| Project | Focus | Link |
|---|---|---|
| Quant Finance Library in C++ | A model-driven pricing, calibration and risk library | [Read the library page]({{ '/pages/quantitative-finance/quant_finance_library_cpp/' | relative_url }}) |
| Numerical Linear Algebra in C++ | Numerical algorithms and their applications in quantitative finance | [Read the project page]({{ '/pages/quantitative-finance/numerical-linear-algebra/' | relative_url }}) |
| Dynamic Delta Hedging | Hedging simulations and visual analytics | Coming soon |
| Market-Making Model | Poisson processes and inventory decisions | Coming soon |
| UK Yield Curve PCA | Yield curve factors | Coming soon |
| Volatility Modelling | Calibration and numerical methods | In preparation |

## Quant Finance Library in C++

The [Quant Finance Library in C++]({{ '/pages/quantitative-finance/quant_finance_library_cpp/' | relative_url }}) is the main implementation-focused project in this collection. It brings together market data, mathematical models, pricing engines, calibration routines, numerical methods and portfolio risk in a single C++ codebase.

### Library breakdown

| Section | What it covers | Implementation focus |
|---|---|---|
| **Core analytics** | Black–Scholes, Bachelier, Greeks and implied volatility | Closed-form pricing with explicit domain and no-arbitrage checks |
| **Stochastic models** | Geometric Brownian motion, arithmetic Brownian motion and short-rate models | Risk-neutral evolution, discount-factor carrying and Hull–White curve consistency |
| **Curves and rates** | Discount-curve bootstrapping, interpolation, forwards, swaps, caplets and swaptions | Market conventions, accrual schedules and curve-implied pricing |
| **Calibration** | Hull–White caplet calibration | Positive parameterisation and weighted market-price fitting |
| **PDE pricing** | European and American option pricing | Theta finite differences, tridiagonal solves and projected SOR |
| **Numerics** | Root-finding, regression and numerical safeguards | Bisection, stable small-system fitting and fallbacks for degenerate samples |
| **Risk** | Numerical Greeks, portfolio aggregation, VaR and expected shortfall | Bumped pricing, position-level sensitivities and historical tail loss |

The full walkthrough, including the model equations and embedded C++ source, is available on the [library showcase page]({{ '/pages/quantitative-finance/quant_finance_library_cpp/' | relative_url }}).

</article>
