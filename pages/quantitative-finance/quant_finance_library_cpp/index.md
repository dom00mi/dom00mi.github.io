---
layout: default
title: Quant Finance Library in C++
permalink: /pages/quantitative-finance/quant_finance_library_cpp/
---

# Quant Finance Library in C++

### A small, model-driven pricing and risk engine

This project is an ongoing C++ quantitative-finance library built around
explicit market conventions, mathematically defined models, and numerical
methods that can be inspected in the source.

**Repository:** [quantengine-cpp](https://github.com/dom00mi/quantengine-cpp)

---

## 1. Library architecture

The implementation follows the path of a pricing calculation:

1. **Market data** is represented by discount curves and instrument quotes.
2. **Analytics** provide closed-form Black–Scholes and Bachelier values,
   sensitivities, and implied volatility inversion.
3. **Models** generate risk-neutral paths for equity and interest-rate factors.
4. **Rates and calibration** turn curves and market quotes into tradable
   prices and fitted parameters.
5. **Numerics and PDEs** provide interpolation, root-finding, finite-difference
   pricing, and early-exercise treatment.
6. **Risk** aggregates positions and estimates Greeks and historical tail loss.

The result is intentionally transparent: each financial assumption is visible
in a small, testable C++ component.

---

## 2. Core pricing models

### Black–Scholes and Bachelier analytics

The analytics layer uses the discounted spot and strike in the Black–Scholes
formula, while the Bachelier implementation prices options on a forward with
normal volatility. Both implementations validate their domains and expose
the conventions needed by downstream pricing code.

<div class="cpp-code" data-filename="analytics.cpp">

{% highlight cpp %}
{% include code/quant_finance_library_cpp/analytics.cpp %}
{% endhighlight %}

</div>

### Stochastic models

The model layer makes the state and discount factor explicit. Geometric
Brownian motion preserves a positive asset level, arithmetic Brownian motion
models a Gaussian forward, and the short-rate models carry discounting along
the simulated path. Hull–White adds a deterministic shift so the model is
consistent with an initial discount curve.

<div class="cpp-code" data-filename="models.cpp">

{% highlight cpp %}
{% include code/quant_finance_library_cpp/models.cpp %}
{% endhighlight %}

</div>

---

## 3. Curves, rates, and calibration

The curve builder bootstraps discount factors from deposits and par swaps.
Monotone cubic interpolation supplies smooth values without introducing
spurious turning points. Rates are then derived from the curve through forward
LIBOR, swap annuities, swap rates, caplets, and swaptions.

<div class="cpp-code" data-filename="curves.cpp">

{% highlight cpp %}
{% include code/quant_finance_library_cpp/curves.cpp %}
{% endhighlight %}

</div>

Hull–White caplet calibration works in log-parameter space, which keeps mean
reversion and volatility positive while Nelder–Mead minimises a weighted
market-price error.

<div class="cpp-code" data-filename="model_calibration.cpp">

{% highlight cpp %}
{% include code/quant_finance_library_cpp/model_calibration.cpp %}
{% endhighlight %}

</div>

The rates layer converts curve values into instrument prices using the
appropriate accrual, annuity, discounting, and volatility convention.

<div class="cpp-code" data-filename="rates.cpp">

{% highlight cpp %}
{% include code/quant_finance_library_cpp/rates.cpp %}
{% endhighlight %}

</div>

---

## 4. PDE pricing

The finite-difference engine prices European and American calls and puts on a
truncated spot grid. A theta scheme advances the Black–Scholes equation in
time; European contracts solve the tridiagonal system directly, while
American contracts use projected SOR to enforce the early-exercise constraint.

The implementation also returns a grid-interpolated value together with
finite-difference delta, gamma, and the local grid spacing.

<div class="cpp-code" data-filename="pde.cpp">

{% highlight cpp %}
{% include code/quant_finance_library_cpp/pde.cpp %}
{% endhighlight %}

</div>

---

## 5. Numerics and risk

Supporting components include bisection for robust one-dimensional inversion,
quadratic least-squares fitting for regression-based exercise decisions, and
Richardson-extrapolated finite differences for numerical Greeks. Portfolio
risk aggregates position-level values and sensitivities, while historical
tail risk reports both VaR and expected shortfall.

<div class="cpp-code" data-filename="numerics.cpp">

{% highlight cpp %}
{% include code/quant_finance_library_cpp/numerics.cpp %}
{% endhighlight %}

</div>

<div class="cpp-code" data-filename="risk.cpp">

{% highlight cpp %}
{% include code/quant_finance_library_cpp/risk.cpp %}
{% endhighlight %}

</div>

| Area | Source | What it demonstrates |
| --- | --- | --- |
| Closed-form analytics | [`analytics.cpp`](https://github.com/dom00mi/quantengine-cpp/blob/main/src/analytics.cpp) | Black–Scholes, Bachelier, Greeks, implied volatility |
| Market curves | [`curves.cpp`](https://github.com/dom00mi/quantengine-cpp/blob/main/src/curves.cpp) | Monotone interpolation and bootstrap equations |
| Rates products | [`rates.cpp`](https://github.com/dom00mi/quantengine-cpp/blob/main/src/rates.cpp) | Forward rates, swaps, caplets, swaptions |
| Numerical methods | [`numerics.cpp`](https://github.com/dom00mi/quantengine-cpp/blob/main/src/numerics.cpp) | Stable small-system regression and fallbacks |
| Optimisation | [`optimisation.cpp`](https://github.com/dom00mi/quantengine-cpp/blob/main/src/optimisation.cpp) | Parameter fitting and objective minimisation |
| Risk | [`risk.cpp`](https://github.com/dom00mi/quantengine-cpp/blob/main/src/risk.cpp) | Numerical Greeks, aggregation, VaR, expected shortfall |
| PDE pricing | [`pde.cpp`](https://github.com/dom00mi/quantengine-cpp/blob/main/src/pde.cpp) | Theta stepping, tridiagonal solves, projected SOR |

---

## 6. Design principles

- **Precise contracts:** invalid market inputs, grids, schedules, and model
  parameters fail explicitly rather than producing silent numerical output.
- **Composable models:** pricing functions accept clear market and payoff
  types, so analytics, simulation, calibration, and risk can share them.
- **Numerical safeguards:** the code checks pivots, interpolation nodes,
  no-arbitrage bounds, convergence, and degenerate regression samples.
- **Inspectable mathematics:** formulas and algorithmic choices remain close
  to the C++ that implements them.

---

## 7. Source code

The complete headers, implementations, tests, and build configuration are
available in the [quantengine-cpp repository](https://github.com/dom00mi/quantengine-cpp).
This page highlights the implementation ideas; the repository is the source of
truth for the production code.

