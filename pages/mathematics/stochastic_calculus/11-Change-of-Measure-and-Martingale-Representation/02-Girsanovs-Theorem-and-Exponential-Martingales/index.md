---
layout: default
title: "11.2: Girsanov's Theorem and Exponential Martingales"
permalink: /pages/mathematics/stochastic_calculus/11-change-of-measure-and-martingale-representation/02-girsanovs-theorem-and-exponential-martingales/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/stochastic_calculus/11-change-of-measure-and-martingale-representation/02-girsanovs-theorem-and-exponential-martingales/' | relative_url }}">← Girsanov's Theorem and Exponential Martingales</a>
  <div class="eyebrow">Mathematics / Stochastic Calculus / 11.2</div>
  <h1>Girsanov's Theorem and Exponential Martingales</h1>
</div>

<article class="article" markdown="1">


# 2. Girsanov's Theorem and Exponential Martingales

This chapter develops the change of measure behind [Girsanov's theorem](https://en.wikipedia.org/wiki/Girsanov_theorem) and explains how stochastic exponentials transform Brownian motion and continuous local martingales.

## 2.1. Girsanov's Theorem: One-Dimensional Brownian Motion

Girsanov's theorem identifies how the drift of Brownian motion changes under an equivalent probability measure. Its essential message is that an appropriate density can **remove or introduce drift without changing quadratic variation**.

**Theorem 2.1 (One-dimensional Girsanov theorem).** Let $W$ be a $\mathbb{P}$-Brownian motion and $\theta$ an adapted process such that the stochastic exponential

$$
Z_t
=\exp\left(
-\int_0^t\theta_s\,dW_s
-\frac12\int_0^t\theta_s^2\,ds
\right)
$$

is a true martingale on $[0,T]$. Define

$$
\frac{d\mathbb{Q}}{d\mathbb{P}}
\bigg\vert_{\mathcal{F}_T}
=Z_T.
$$

Then

$$
\boxed{
W_t^{\mathbb{Q}}
:=W_t+\int_0^t\theta_s\,ds,
\qquad 0\leq t\leq T,
}
$$

is a standard Brownian motion under $\mathbb{Q}$.

**Proof.** Since

$$
dW_t^{\mathbb{Q}}=dW_t+\theta_t\,dt,
\qquad
dZ_t=-\theta_tZ_t\,dW_t,
$$

Itô's product rule gives

$$
\begin{aligned}
d(Z_tW_t^{\mathbb{Q}})
&=Z_t\,dW_t^{\mathbb{Q}}
+W_t^{\mathbb{Q}}\,dZ_t
+d\langle Z,W^{\mathbb{Q}}\rangle_t\\
&=Z_t(dW_t+\theta_t\,dt)
-\theta_tZ_tW_t^{\mathbb{Q}}\,dW_t
-\theta_tZ_t\,dt\\
&=Z_t\bigl(1-\theta_tW_t^{\mathbb{Q}}\bigr)\,dW_t.
\end{aligned}
$$

Thus $ZW^{\mathbb{Q}}$ is a $\mathbb{P}$-local martingale. By the local-martingale transfer principle, $W^{\mathbb{Q}}$ is a $\mathbb{Q}$-local martingale.

The added finite-variation process $\int_0^t\theta_s\,ds$ does not affect quadratic variation; hence

$$
\langle W^{\mathbb{Q}}\rangle_t
=\langle W\rangle_t=t.
$$

The process $W^{\mathbb{Q}}$ is continuous and starts at zero. Lévy's characterisation therefore shows that it is a Brownian motion under $\mathbb{Q}$. $\square$

### 2.1.1. The sign convention

For the density

$$
Z_t=\mathcal{E}\left(-\int_0^{\cdot}\theta_s\,dW_s\right)_t,
$$

the corresponding Brownian motion under the new measure is

$$
\boxed{dW_t^{\mathbb{Q}}=dW_t+\theta_t\,dt.}
$$

Equivalently,

$$
\boxed{dW_t=dW_t^{\mathbb{Q}}-\theta_t\,dt.}
$$

The minus sign in the density and the plus sign in the transformed Brownian motion are important to keep consistent.

### 2.1.2. Effect on a stochastic differential equation

Suppose that under $\mathbb{P}$ a process $X$ satisfies

$$
dX_t=b_t\,dt+\sigma_t\,dW_t.
$$

Substituting $dW_t=dW_t^{\mathbb{Q}}-\theta_t\,dt$ gives

$$
\boxed{
dX_t
=\bigl(b_t-\sigma_t\theta_t\bigr)\,dt
+\sigma_t\,dW_t^{\mathbb{Q}}.
}
$$

Thus the drift changes from $b_t$ to $b_t-\sigma_t\theta_t$, while the diffusion coefficient and instantaneous quadratic variation remain unchanged:

$$
d\langle X\rangle_t=\sigma_t^2\,dt.
$$

This drift adjustment is the mathematical mechanism behind the passage from physical probabilities to risk-neutral probabilities in diffusion-based financial models.

---

### 2.1.3. Continuous local-martingale form

The preceding Brownian-motion statement is a special case of the general continuous local-martingale version of Girsanov's theorem. Let $(\Omega,\mathcal{F},\mathbb{P})$ be a probability space with a complete and right-continuous filtration $(\mathcal{F}_t)_{t\geq 0}$, and let $X$ be a continuous local martingale. Define its stochastic exponential by

$$
Z_t=\mathcal{E}(X)_t
=\exp\left(X_t-\frac12[X]_t\right),
$$

where $[X]$ denotes quadratic variation. If $Z$ is a martingale, then for any $T>0$ the measure

$$
\mathbb{Q}(A)=\int_A Z_T\,d\mathbb{P},
\qquad A\in\mathcal{F}_T,
$$

is a probability measure on $(\Omega,\mathcal{F}_T)$ with

$$
\left.\frac{d\mathbb{Q}}{d\mathbb{P}}\right|_{\mathcal{F}_T}=Z_T=\mathcal{E}(X)_T.
$$

**Theorem 2.2 (Continuous local-martingale Girsanov theorem).** If $M$ is a continuous local martingale under $\mathbb{P}$, then

$$
\widetilde{M}_t=M_t-[M,X]_t,
\qquad t\in[0,T],
$$

is a continuous local martingale under $\mathbb{Q}$. The statement also holds for càdlàg local martingales, and for $T=\infty$ when $Z$ is uniformly integrable.

#### Corollaries

**Semimartingales.** If $Y=M+A$ is a semimartingale, where $M$ is a local martingale and $A$ has finite variation, then under the changed measure

$$
Y=\widetilde{M}+A+[M,X],
\qquad \widetilde{M}=M-[M,X].
$$

Since $A+[M,X]$ has finite variation, $Y$ remains a semimartingale under $\mathbb{Q}$.

**Brownian motion.** If $W$ is a $\mathbb{P}$-Brownian motion and $X$ is a continuous local martingale, then

$$
\widetilde{W}_t=W_t-[W,X]_t
$$

is a $\mathbb{Q}$-Brownian motion. This follows from Lévy's characterization: $\widetilde{W}$ is a continuous $\mathbb{Q}$-local martingale and

$$
[\widetilde{W}]_t=[W]_t=t.
$$

### 2.1.4. Novikov's condition

In common applications,

$$
X_t=\int_0^tY_s\,dW_s,
\qquad t\in[0,T],
$$

for a progressively measurable process $Y$ satisfying

$$
\int_0^T Y_s^2\,ds<\infty
\quad\text{almost surely}.
$$

A sufficient condition for $\mathcal{E}(X)$ to be a martingale is **Novikov's condition**:

$$
\mathbb{E}^{\mathbb{P}}\left[
\exp\left(\frac12\int_0^T Y_s^2\,ds\right)
\right]<\infty.
$$

The stochastic exponential $Z=\mathcal{E}(X)$ is the solution of

$$
Z_t=1+\int_0^t Z_s\,dX_s.
$$

The resulting measure is equivalent to $\mathbb{P}$ on $\mathcal{F}_T$ whenever Novikov's condition holds. In particular,

$$
\widetilde{W}_t=W_t-\int_0^tY_s\,ds,
\qquad t\in[0,T],
$$

is a $\mathbb{Q}$-Brownian motion. This is the classical form of Girsanov's theorem.


## 2.2. Multidimensional Girsanov Theorem

Let

$$
W_t=(W_t^1,\ldots,W_t^d)^{\mathsf T}
$$

be a $d$-dimensional Brownian motion under $\mathbb{P}$. Let $\theta_t=(\theta_t^1,\ldots,\theta_t^d)^{\mathsf T}$ be progressively measurable and satisfy

$$
\int_0^T\lVert\theta_s\rVert^2\,ds<\infty
\quad\mathbb{P}\text{-a.s.}
$$

**Theorem 2.3 (Multidimensional Girsanov theorem).** Suppose that

$$
Z_t
=\exp\left(
-\int_0^t\theta_s^{\mathsf T}\,dW_s
-\frac12\int_0^t\lVert\theta_s\rVert^2\,ds
\right)
$$

is a true $\mathbb{P}$-martingale. Define $\mathbb{Q}$ on $\mathcal{F}_T$ by

$$
\frac{d\mathbb{Q}}{d\mathbb{P}}
\bigg\vert_{\mathcal{F}_T}=Z_T.
$$

Then

$$
\boxed{
W_t^{\mathbb{Q}}
:=W_t+\int_0^t\theta_s\,ds
}
$$

is a $d$-dimensional standard Brownian motion under $\mathbb{Q}$.

A sufficient condition for the required martingale property is the multidimensional Novikov criterion

$$
\mathbb{E}^{\mathbb{P}}\left[
\exp\left(\frac12\int_0^T\lVert\theta_s\rVert^2\,ds\right)
\right]<\infty.
$$

In coordinates,

$$
Z_t
=\exp\left(
-\sum_{i=1}^{d}\int_0^t\theta_s^i\,dW_s^i
-\frac12\sum_{i=1}^{d}\int_0^t(\theta_s^i)^2\,ds
\right),
$$

and

$$
W_t^{i,\mathbb{Q}}
=W_t^i+\int_0^t\theta_s^i\,ds,
\qquad i=1,\ldots,d.
$$

**Interpretation.** In a multidimensional model, the vector $\theta$ determines how the drift of each Brownian risk factor is adjusted. Although the drift changes, the quadratic covariations remain

$$
\langle W^{i,\mathbb{Q}},W^{j,\mathbb{Q}}\rangle_t
=\delta_{ij}t.
$$

Thus the transformed process retains the covariance structure of standard multidimensional Brownian motion.

---

## 2.3. Risk-Neutral Measure in the Black–Scholes–Merton Model

We now apply the change-of-measure machinery to a financial market in which a stock is driven by one source of Brownian randomness.

Let $T<\infty$ and suppose that under the **physical measure** $\mathbb{P}$, the stock price $S$ satisfies

$$
\boxed{
dS_t=\mu S_t\,dt+\sigma S_t\,dW_t,
\qquad S_0>0,
}
$$

where $\mu\in\mathbb{R}$, $\sigma>0$, and the risk-free interest rate $r$ are constants. Let the money-market account be

$$
B_t=e^{rt}.
$$

Assume that the filtration is the augmented filtration generated by the Brownian motion $W$.

### 2.3.1. The market price of risk

Define the constant

$$
\boxed{\theta=\frac{\mu-r}{\sigma}.}
$$

This quantity is called the **market price of risk**, or *Sharpe ratio* in this constant-coefficient setting: it measures the excess expected return per unit of instantaneous volatility.

Consider the stochastic exponential

$$
Z_t
=\exp\left(-\theta W_t-\frac12\theta^2t\right),
\qquad 0\leq t\leq T.
$$

For fixed finite $T$, Novikov's condition holds:

$$
\mathbb{E}^{\mathbb{P}}\left[e^{\theta^2T/2}\right]
=e^{\theta^2T/2}<\infty.
$$

Therefore $Z$ is a true martingale on $[0,T]$, and we can define

$$
\boxed{
\frac{d\mathbb{Q}}{d\mathbb{P}}
\bigg\vert_{\mathcal{F}_T}=Z_T.
}
$$

Since $Z_T>0$ almost surely, $\mathbb{Q}\sim\mathbb{P}$ on $\mathcal{F}_T$.

By Girsanov's theorem,

$$
\boxed{
W_t^{\mathbb{Q}}=W_t+\theta t
}
$$

is a Brownian motion under $\mathbb{Q}$.

### 2.3.2. Stock-price dynamics under the new measure

Substitute

$$
dW_t=dW_t^{\mathbb{Q}}-\theta\,dt
$$

into the original stock dynamics:

$$
\begin{aligned}
dS_t
&=\mu S_t\,dt+\sigma S_t(dW_t^{\mathbb{Q}}-\theta\,dt)\\
&=(\mu-\sigma\theta)S_t\,dt+\sigma S_t\,dW_t^{\mathbb{Q}}\\
&=rS_t\,dt+\sigma S_t\,dW_t^{\mathbb{Q}}.
\end{aligned}
$$

Hence

$$
\boxed{
dS_t=rS_t\,dt+\sigma S_t\,dW_t^{\mathbb{Q}}.}
$$

The physical drift $\mu$ has been replaced by the risk-free rate $r$.

### 2.3.3. Discounted stock prices are martingales

Define the discounted stock price

$$
\widetilde{S}_t:=B_t^{-1}S_t=e^{-rt}S_t.
$$

Applying Itô's product rule,

$$
\begin{aligned}
d\widetilde{S}_t
&=-re^{-rt}S_t\,dt+e^{-rt}\,dS_t\\
&=-r\widetilde{S}_t\,dt+r\widetilde{S}_t\,dt
+\sigma\widetilde{S}_t\,dW_t^{\mathbb{Q}}\\
&=\sigma\widetilde{S}_t\,dW_t^{\mathbb{Q}}.
\end{aligned}
$$

Thus

$$
\boxed{d\widetilde{S}_t
=\sigma\widetilde{S}_t\,dW_t^{\mathbb{Q}}.}
$$

For the Black–Scholes–Merton model with constant coefficients on a finite horizon, $\widetilde{S}$ is a true $\mathbb{Q}$-martingale. The measure $\mathbb{Q}$ is therefore an **equivalent martingale measure** (EMM), also called a **risk-neutral measure**.

### 2.3.4. Self-financing portfolios

Let $H_t$ denote the number of shares held at time $t$, and let $X_t$ be the total portfolio wealth. If the remainder is invested in the money-market account, the self-financing condition is

$$
\boxed{
dX_t
=H_t\,dS_t+r(X_t-H_tS_t)\,dt.
}
$$

Under $\mathbb{Q}$,

$$
\begin{aligned}
dX_t
&=H_t(rS_t\,dt+\sigma S_t\,dW_t^{\mathbb{Q}})
+r(X_t-H_tS_t)\,dt\\
&=rX_t\,dt+\sigma H_tS_t\,dW_t^{\mathbb{Q}}.
\end{aligned}
$$

Discounting wealth, $\widetilde{X}_t=e^{-rt}X_t$, gives

$$
\boxed{
d\widetilde{X}_t
=\sigma H_t\widetilde{S}_t\,dW_t^{\mathbb{Q}}.
}
$$

Accordingly, admissible discounted self-financing wealth processes are local martingales under $\mathbb{Q}$ (and true martingales under suitable integrability conditions).

### 2.3.5. European claims, replication, and pricing

Let $C$ be an $\mathcal{F}_T$-measurable European payoff, and suppose its discounted value $\widetilde{C}=e^{-rT}C$ is square-integrable under $\mathbb{Q}$.

The Brownian martingale representation theorem yields a predictable process $\xi$ satisfying

$$
\mathbb{E}^{\mathbb{Q}}\left[\int_0^T\xi_s^2\,ds\right]<\infty,
$$

such that

$$
\boxed{
\widetilde{C}
=\mathbb{E}^{\mathbb{Q}}[\widetilde{C}]
+\int_0^T\xi_s\,dW_s^{\mathbb{Q}}.
}
$$

Comparing this representation with the discounted self-financing wealth equation, we choose the stock holding

$$
\boxed{
H_t=\frac{\xi_t}{\sigma\widetilde{S}_t}.
}
$$

Together with the initial capital

$$
\boxed{
X_0=\mathbb{E}^{\mathbb{Q}}[e^{-rT}C],
}
$$

this strategy replicates the payoff $C$ at maturity. The corresponding arbitrage-free value process is

$$
\boxed{
V_t
=\mathbb{E}^{\mathbb{Q}}
\left[e^{-r(T-t)}C\mid\mathcal{F}_t\right],
\qquad 0\leq t\leq T.
}
$$

The martingale representation theorem also explains why the market is **complete**: there is one traded risky asset, one Brownian risk factor, and the stock's non-zero volatility allows the Brownian exposure to be hedged.

Within the Brownian filtration, the requirement that the discounted stock price be a local martingale uniquely determines the Girsanov drift adjustment $\theta=(\mu-r)/\sigma$. Consequently, the model has a **unique equivalent local martingale measure**.

---

## 2.4. Finite Horizons, Infinite Horizons, and Uniform Integrability

The preceding Black–Scholes–Merton change of measure was constructed on a fixed finite horizon $[0,T]$. That restriction is mathematically meaningful.

Assume $\theta\neq0$ is constant and consider the same exponential for all $t\geq0$:

$$
Z_t=\exp\left(-\theta W_t-\frac12\theta^2t\right).
$$

For every finite $t$,

$$
\mathbb{E}^{\mathbb{P}}[Z_t]=1.
$$

However, the Brownian strong law gives

$$
\frac{W_t}{t}\longrightarrow0
\quad\mathbb{P}\text{-a.s.}
$$

Therefore,

$$
\frac{1}{t}\log Z_t
=-\theta\frac{W_t}{t}-\frac12\theta^2
\longrightarrow-\frac12\theta^2<0,
$$

and hence

$$
\boxed{
Z_t\longrightarrow0
\quad\mathbb{P}\text{-a.s. as }t\to\infty.
}
$$

Since $\mathbb{E}^{\mathbb{P}}[Z_t]=1$ for every finite $t$ but

$$
\mathbb{E}^{\mathbb{P}}\left[\lim_{t\to\infty}Z_t\right]=0,
$$

the martingale $(Z_t)_{t\geq0}$ is **not uniformly integrable on the infinite horizon**.

This does not contradict its martingale property on any finite interval: on each fixed $[0,T]$ it is uniformly integrable, with terminal density $Z_T$.

In the canonical Brownian path-space construction, the finite-horizon measures remain mutually consistent and extend to an infinite-horizon law. However, for non-zero $\theta$, that infinite-horizon law is singular with respect to the original Brownian law on the $\sigma$-algebra of the entire path. The long-run drift distinguishes the two path laws almost surely.

**Connection with statistics.** This is the continuous-time counterpart of the Bernoulli likelihood-ratio example discussed earlier: every finite observation window permits equivalent probability measures, while an infinite amount of information can distinguish the laws perfectly.

---

## 2.5. Stochastic Volatility and Incomplete Markets

The Black–Scholes–Merton model has one traded risky asset driven by one Brownian source. We now consider a stochastic-volatility model with a second source of randomness, which cannot generally be hedged by trading the stock alone.

### 2.5.1. The model under the physical measure

Let $W$ and $W^{\perp}$ be independent $\mathbb{P}$-Brownian motions. Consider

$$
\boxed{
\begin{aligned}
dS_t&=\mu S_t\,dt+Y_tS_t\,dW_t,\\
dY_t&=a_t\,dt
+b_t\left(\rho\,dW_t+\sqrt{1-\rho^2}\,dW_t^{\perp}\right),
\end{aligned}
}
$$

where $|\rho|<1$ and $a_t,b_t$ are adapted coefficients satisfying the relevant existence and integrability conditions. Assume $Y_t>0$ where needed, so that division by $Y_t$ is meaningful.

The stock $S$ is traded, whereas the volatility factor $Y$ is not itself a traded asset. It is often convenient to introduce

$$
dW_t^Y
=\rho\,dW_t+\sqrt{1-\rho^2}\,dW_t^{\perp},
$$

for which

$$
\langle W,W^Y\rangle_t=\rho t.
$$

The model has two Brownian risk factors but only one traded risky asset. In the non-degenerate case, the component driven by $W^{\perp}$ represents risk that cannot be eliminated by stock-and-cash trading alone.

### 2.5.2. A family of equivalent local martingale measures

To remove the excess drift from the stock price, set

$$
\boxed{
\theta_t=\frac{\mu-r}{Y_t}.
}
$$

Introduce an additional progressively measurable process $\psi_t$, and define the two-dimensional stochastic exponential

$$
\boxed{
Z_t
=\exp\left(
-\int_0^t\theta_s\,dW_s
-\int_0^t\psi_s\,dW_s^{\perp}
-\frac12\int_0^t(\theta_s^2+\psi_s^2)\,ds
\right).
}
$$

Suppose $Z$ is a true martingale on $[0,T]$; for example, this follows from

$$
\mathbb{E}^{\mathbb{P}}\left[
\exp\left(\frac12\int_0^T(\theta_s^2+\psi_s^2)\,ds\right)
\right]<\infty.
$$

Define

$$
\frac{d\mathbb{Q}^{\psi}}{d\mathbb{P}}
\bigg\vert_{\mathcal{F}_T}=Z_T.
$$

Multidimensional Girsanov gives independent $\mathbb{Q}^{\psi}$-Brownian motions

$$
\boxed{
\begin{aligned}
W_t^{\mathbb{Q}^{\psi}}
&=W_t+\int_0^t\theta_s\,ds,\\
W_t^{\perp,\mathbb{Q}^{\psi}}
&=W_t^{\perp}+\int_0^t\psi_s\,ds.
\end{aligned}
}
$$

The stock price satisfies

$$
\begin{aligned}
dS_t
&=\mu S_t\,dt
+Y_tS_t(dW_t^{\mathbb{Q}^{\psi}}-\theta_t\,dt)\\
&=rS_t\,dt+Y_tS_t\,dW_t^{\mathbb{Q}^{\psi}}.
\end{aligned}
$$

Therefore,

$$
\boxed{
dS_t
=rS_t\,dt+Y_tS_t\,dW_t^{\mathbb{Q}^{\psi}}.
}
$$

For the discounted stock price,

$$
\boxed{
d\widetilde{S}_t
=Y_t\widetilde{S}_t\,dW_t^{\mathbb{Q}^{\psi}}.
}
$$

Thus every admissible choice of $\psi$ for which the density is a true martingale produces an equivalent **local** martingale measure.

### 2.5.3. Volatility dynamics under the new measure

The process $Y$ transforms as

$$
\begin{aligned}
dY_t
&=a_t\,dt
+b_t\left[\rho(dW_t^{\mathbb{Q}^{\psi}}-\theta_t\,dt)
+\sqrt{1-\rho^2}
(dW_t^{\perp,\mathbb{Q}^{\psi}}-\psi_t\,dt)\right]\\
&=\left[a_t-b_t\left(\rho\theta_t
+\sqrt{1-\rho^2}\,\psi_t\right)\right]dt\\
&\quad+b_t\left(\rho\,dW_t^{\mathbb{Q}^{\psi}}
+\sqrt{1-\rho^2}\,dW_t^{\perp,\mathbb{Q}^{\psi}}\right).
\end{aligned}
$$

Hence

$$
\boxed{
\begin{aligned}
dY_t
&=\left[a_t-b_t\left(\rho\theta_t
+\sqrt{1-\rho^2}\,\psi_t\right)\right]dt\\
&\quad+b_t\left(\rho\,dW_t^{\mathbb{Q}^{\psi}}
+\sqrt{1-\rho^2}\,dW_t^{\perp,\mathbb{Q}^{\psi}}\right).
\end{aligned}
}
$$

The process $\psi$ parametrises the change of drift in the **unhedgeable volatility direction**. It is associated with the volatility-risk premium. No-arbitrage considerations alone do not generally determine its value.

### 2.5.4. Why the market is incomplete

Let $C$ be a square-integrable claim at maturity $T$ and write

$$
\widetilde{C}=e^{-rT}C.
$$

For any fixed equivalent martingale measure $\mathbb{Q}^{\psi}$, the two-dimensional martingale representation theorem gives

$$
\boxed{
\widetilde{C}
=\mathbb{E}^{\mathbb{Q}^{\psi}}[\widetilde{C}]
+\int_0^T\xi_t\,dW_t^{\mathbb{Q}^{\psi}}
+\int_0^T\varphi_t\,dW_t^{\perp,\mathbb{Q}^{\psi}}.
}
$$

Here $\xi$ and $\varphi$ are predictable square-integrable integrands.

On the other hand, the discounted wealth of a self-financing strategy trading only in the stock and cash satisfies

$$
\boxed{
\widetilde{X}_T
=X_0+\int_0^T H_tY_t\widetilde{S}_t\,dW_t^{\mathbb{Q}^{\psi}}.
}
$$

Comparing the two representations, replication requires

$$
H_tY_t\widetilde{S}_t=\xi_t
\qquad\text{and}\qquad
\boxed{\varphi_t=0}
$$

for almost every $t$ and almost surely. If the claim has non-zero exposure $\varphi$ to the orthogonal Brownian direction, it cannot be replicated by stock-and-cash trading alone.

This explains why the market is generally **incomplete**: there are two independent sources of randomness but only one risky asset available to hedge them. The freedom to choose $\psi$, when it leads to distinct admissible martingale measures, is another manifestation of this incompleteness.

**Financial interpretation.** In a complete market, every sufficiently integrable contingent claim can be hedged, and replication uniquely determines its arbitrage-free price. In an incomplete market, some risks remain unspanned, and no-arbitrage alone does not necessarily select a unique price for claims exposed to those risks. Additional modelling assumptions, traded volatility-sensitive instruments, or a pricing criterion may be needed.

---

## 2.6. Summary and Connections

The mathematical structure developed in this chapter can be summarised through a sequence of transformations:

$$
\boxed{
\begin{gathered}
\mathbb{Q}\ll\mathbb{P}
\quad\Longrightarrow\quad
Z=\frac{d\mathbb{Q}}{d\mathbb{P}},\\[4pt]
Z_t=\mathbb{E}^{\mathbb{P}}[Z_T\mid\mathcal{F}_t],\\[4pt]
\mathbb{E}^{\mathbb{Q}}[X\mid\mathcal{F}_s]
=\frac{1}{Z_s}\mathbb{E}^{\mathbb{P}}[XZ_t\mid\mathcal{F}_s],\\[4pt]
M\text{ is a }\mathbb{Q}\text{-martingale}
\quad\Longleftrightarrow\quad
MZ\text{ is a }\mathbb{P}\text{-martingale}.
\end{gathered}
}
$$

For Brownian models, the key construction is

$$
\boxed{
\begin{aligned}
Z_t
&=\exp\left(-\int_0^t\theta_s\,dW_s
-\frac12\int_0^t\theta_s^2\,ds\right),\\
W_t^{\mathbb{Q}}
&=W_t+\int_0^t\theta_s\,ds.
\end{aligned}
}
$$

This construction provides the bridge from general measure theory to stochastic calculus and mathematical finance. In particular:

- **Radon–Nikodym derivatives** express one measure as a weighted version of another.
- **Density processes** describe these weights as information is revealed and are uniformly integrable when derived from a fixed integrable terminal density.
- **Bayes' formula** transfers conditional expectations between equivalent probability measures.
- **Likelihood-ratio martingales** describe the sequential accumulation of statistical evidence; their failure of uniform integrability can reflect asymptotic singularity of models.
- **Girsanov's theorem** changes Brownian drift while preserving quadratic variation.
- **Equivalent martingale measures** make discounted traded-asset prices local martingales and form the basis of risk-neutral valuation.
- **Market completeness** concerns the ability to represent all relevant claim risks by trading available assets; one untraded Brownian risk factor generally produces incompleteness.

The deeper unifying idea is that **changing probabilities and changing drifts are two aspects of the same operation**. Density processes encode the change at the measure-theoretic level; stochastic exponentials and Girsanov's theorem reveal its effect on continuous-time stochastic dynamics.


- [Exercises]({{ '/pages/mathematics/stochastic_calculus/11-change-of-measure-and-martingale-representation/02-girsanovs-theorem-and-exponential-martingales/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/stochastic_calculus/11-change-of-measure-and-martingale-representation/02-girsanovs-theorem-and-exponential-martingales/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/stochastic_calculus/11-change-of-measure-and-martingale-representation/02-girsanovs-theorem-and-exponential-martingales/references/' | relative_url }})

[Back to Change of Measure and Martingale Representation]({{ '/pages/mathematics/stochastic_calculus/11-change-of-measure-and-martingale-representation/' | relative_url }})

</article>
