---
layout: default
title: "1.1: Probabilistic Preliminaries and Brownian Motion"
permalink: /pages/mathematics/control_theory/stochastic-controls/01-mathematical-foundations-of-stochastic-control/01-probabilistic-preliminaries-and-brownian-motion/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/control_theory/stochastic-controls/01-mathematical-foundations-of-stochastic-control/' | relative_url }}">Chapter 1: Mathematical Foundations of Stochastic Control</a>
  <div class="eyebrow">Mathematics / Control Theory / Stochastic Control / 1.1</div>
  <h1>1.1: Probabilistic Preliminaries and Brownian Motion</h1>
  <p class="lead">Placeholder notes for Probabilistic Preliminaries and Brownian Motion.</p>
</div>

<article class="article" markdown="1">

# 01 — Mathematical Foundations of Stochastic Control

> **Scope.** This chapter introduces control theory and stochastic optimal control, then develops the controlled-diffusion framework, optimal stopping variants, and the classical Merton investment and consumption problems. The mathematical exposition follows the material preceding the next section where we exploit reminiscences of Dynamic Programming, Stochastic Calculus to obtain the HJB Equation which helps us building our **Stochastic Control** framework throughout this journey.
>

---

## 1.1 — From Control Theory to Stochastic Control

### 1.1.1 — What Is Control Theory?

**Control theory** is a field of applied mathematics and control engineering concerned with the behaviour and regulation of dynamical systems. Its central task is to determine how an input should be applied to a system in order to guide it towards a desired state or trajectory.

The control law should achieve the desired behaviour while keeping properties such as **delay**, **overshoot**, and **steady-state error** within acceptable bounds. A fundamental requirement is **stability**: small perturbations of the system should not produce unacceptable departures from its intended behaviour. Beyond stability, the controller may be designed to optimise a performance criterion, such as energy consumption, tracking accuracy, time, risk, or cost.

In broad terms, a control problem involves a **state** describing the system, a **control** chosen by an agent or regulator, a rule governing how the state evolves, and a **performance objective** used to evaluate the control decisions. Control may be applied in an open-loop manner, according to a predetermined schedule, or through feedback, where new decisions incorporate the state observed along the way.

### 1.1.2 — A Brief History of Control Theory

Although practical control mechanisms have existed since antiquity, the mathematical analysis of feedback and stability acquired a more systematic form during the nineteenth century. A classical example is the **centrifugal governor**, a mechanical device that adjusts the operation of an engine when its rotational speed changes. Such governors were also used to regulate windmills.

![Centrifugal governor of a Boulton & Watt engine](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c7/Boulton_and_Watt_centrifugal_governor-MJ.jpg/250px-Boulton_and_Watt_centrifugal_governor-MJ.jpg)

*Centrifugal governor in a Boulton & Watt engine (1788). Image and attribution: Wikimedia Commons.*

In 1868, James Clerk Maxwell published *On Governors*, analysing the dynamics of centrifugal governors. He examined **self-oscillation**, a phenomenon in which delayed corrections lead to overcompensation and potentially unstable behaviour. His work stimulated further mathematical study of stability.

Edward John Routh, a contemporary of Maxwell, generalised these results to classes of linear systems. Independently, Adolf Hurwitz studied stability through differential equations in 1877. Their contributions are associated with what is now called the Routh–Hurwitz stability criterion.

Reliable control became crucial in aviation. The Wright brothers, whose first successful powered flights took place on 17 December 1903, distinguished themselves not merely by producing lift but by maintaining controlled flight. Sustained flight demanded a means of continuously regulating the aircraft's motion.

By the Second World War, control theory had become an important field of research. Irmgard Flügge-Lotz developed discontinuous automatic control theory, including applications of **bang–bang control** to automatic aircraft-control equipment. Related methods found applications in fire-control, guidance, and electronic systems.

Mechanical and electromechanical methods remain relevant to stability. For instance, ship stabilisers may use actively controlled fins whose angle changes to counteract rolling induced by waves and wind. Likewise, the Space Race relied on precise control of the orientation and trajectory of spacecraft.

Over time, the mathematical ideas of control spread well beyond mechanical motion, including economics, finance, and artificial intelligence. These applications involve models in which a regulator interacts with a dynamic environment and adapts its actions as information becomes available. The idea of an **internal model**, associated with the good regulator theorem, emphasises that good regulation depends on an adequate representation of the system to be controlled. In economics this may involve models of market behaviour; in AI it may involve models of a user's changing conversational or decision state. These analogies are useful conceptually, even though they do not imply that financial markets or human decisions can be controlled like machines.

### 1.1.3 — Main Control Strategies

The design of a control system depends on the underlying model, the available information, and the specifications one wishes to satisfy. A central requirement is **closed-loop stability**. For linear systems this can often be analysed or achieved using pole placement; for nonlinear systems, stability arguments commonly draw on Lyapunov theory.

Some of the principal approaches are:

1. **Optimal control.** A control signal is selected to minimise a cost or maximise a reward. One example is determining the thrust needed to bring a satellite onto a desired trajectory while consuming as little fuel as possible. Widely used approaches include model predictive control (MPC) and linear–quadratic–Gaussian (LQG) control. MPC repeatedly solves a finite-horizon optimisation problem, can explicitly accommodate input and state constraints, and is widely used in industrial process control alongside PID techniques. Its finite-horizon optimisation criterion need not coincide with the true infinite-horizon closed-loop performance criterion.

2. **Robust control.** A controller is designed to tolerate uncertainty and differences between the true system and its nominal mathematical model. Earlier frequency-domain methods, associated with figures such as Hendrik Wade Bode, often had useful robustness properties, while some later state-space designs revealed robustness limitations. Modern examples include $H_\infty$ loop shaping, sliding-mode control, and methods for controlling heterogeneous electrical loads. The aim is stability and satisfactory performance despite modest modelling errors or disturbances.

3. **Stochastic control.** The system's evolution and sometimes the observations available to the controller involve random noise. The chosen control must account explicitly for these disturbances and optimise a criterion typically expressed in terms of an expectation. This is the main subject of the chapter.

4. **Adaptive control.** Process parameters are estimated online, or the controller's gains are adjusted as new information arrives. Early successful applications appeared in aerospace during the 1950s.

5. **Hierarchical control.** A set of devices and decision-making components is organised in a hierarchy. When components communicate through a computer network, the result is also a networked control system.

6. **Intelligent control.** Artificial neural networks, Bayesian methods, fuzzy logic, machine learning, evolutionary methods, genetic algorithms, and combinations such as neuro-fuzzy systems are used in control design.

7. **Self-organised criticality control.** This seeks to influence the processes through which self-organised systems release or dissipate energy.

### 1.1.4 — Stochastic Control: Uncertainty Enters the Dynamics

**Stochastic control**, also called **stochastic optimal control**, studies how to choose actions when the behaviour of the state or the information available about that state is uncertain. Typically, the dynamics are perturbed by random noise described by a probabilistic model. Decisions are chosen to maximise a reward or minimise an expected cost even though the system cannot be predicted perfectly.

The problem can be formulated in **discrete time** or **continuous time**. The controller may observe the state directly or receive noisy observations. Probabilistic assumptions about those observations and disturbances allow the decision-maker to evaluate the consequences of a proposed control policy.

A particularly important family of problems is **linear–quadratic–Gaussian (LQG) control**, in which the state evolves according to a linear model, disturbances are Gaussian and enter additively, and the performance criterion is a quadratic expectation. In standard centralised discrete-time problems of this form, the **certainty-equivalence principle** states that the control law can be obtained as if the additive noise were absent, with the state (or its estimate in the partially observed case) replacing the unknown deterministic state. This property relies on the particular linear, quadratic, and additive-noise structure; it does not hold for arbitrary nonlinear stochastic control problems.

#### Why Stochastic Control Matters in Finance

In continuous-time finance, a natural **state variable** is an investor's **wealth or net worth**, often modelled by a stochastic differential equation. The **controls** are the amounts, holdings, or proportions allocated to risky assets, and possibly the investor's consumption rate. Given an allocation, the future changes in wealth depend on the random returns of risky assets, the interest earned on the risk-free asset, and any withdrawals or additional income.

The field grew substantially from the 1970s onwards, particularly through applications to continuous-time portfolio selection. Robert C. Merton used stochastic control techniques to study how an investor should distribute wealth between safe and risky assets and how consumption should evolve over time. His contributions, alongside the work of Black and Scholes, fundamentally changed mathematical finance. Important mathematical treatments include works by **Fleming and Rishel**, and later **Fleming and Soner**; stochastic-control methods were also used by **Jerome Stein** in analysing aspects of the 2008 financial crisis.

The key financial question is therefore not merely how uncertain prices evolve, but **how to act optimally while those prices evolve**. The remainder of this chapter makes this question precise.

---

## 1.2 — Stochastic Control Problems: Basic Structure

### 1.2.1 — Useful Background Reading

The source notes recommend the following background readings:

- **Björk**, Chapters 25–26; Chapters 27–28 provide additional background on topics not covered in detail.
- **Pham**, Chapters 2–3; Chapters 4–6 cover related material, including optimal stopping, beyond the classical dynamic-programming treatment of controlled diffusions emphasised here.
- **Rogers**, Chapter 1; Chapter 2 develops many variants of the basic Merton problem.

### 1.2.2 — Controlled Diffusion Problems

The basic structure of stochastic control in a diffusion setting begins with a **state process**, sometimes referred to simply as the *state*,

$$
X=(X_t)_{t\in\mathcal T},
$$

where the time set is either a **finite horizon**, $\mathcal T=[0,T]$ with $T<\infty$, or an **infinite horizon**, $\mathcal T=\mathbb R_+$. The trajectory of the state can be influenced by an agent, or *controller*, through a control process $\alpha$. The controller seeks to optimise a performance criterion.

Work on a filtered probability space

$$
(\Omega,\mathcal F,\mathbb F:=(\mathcal F_t)_{t\in\mathcal T},\mathbb P).
$$

The $\mathbb R^n$-valued controlled diffusion $X$ has dynamics

$$
\boxed{dX_t=b(X_t,\alpha_t)\,dt+\sigma(X_t,\alpha_t)\,dW_t,
\qquad X_0=x\in\mathbb R^n.}\tag{1.11}
$$

Here $W$ is an $\mathbb F$-adapted, $d$-dimensional Brownian motion. The control process

$$
\alpha=(\alpha_t)_{t\in\mathcal T}
$$

is an $\mathbb R^m$-valued, $\mathbb F$-adapted process, taking its values in a control set $A\subseteq\mathbb R^m$:

$$
\alpha_t\in A\subseteq\mathbb R^m,\qquad t\in\mathcal T.
$$

The coefficient functions satisfy

$$
b:\mathbb R^n\times A\longrightarrow\mathbb R^n,
\qquad
\sigma:\mathbb R^n\times A\longrightarrow\mathbb R^{n\times d},
$$

with conditions ensuring that equation (1.11) has a unique solution. In a finite-horizon problem the drift and diffusion coefficients may also depend explicitly on time; this dependence is omitted here to keep the notation compact. For the time-homogeneous infinite-horizon setting considered in the source notes, the coefficients have no explicit time dependence.

The **control problem** is to choose $\alpha$ to maximise a specified **objective functional** or **performance criterion**.

#### Finite-Horizon Objective

For $\mathcal T=[0,T]$ and $X_0=x$, a typical performance criterion is

$$
\boxed{J(x;\alpha):=\mathbb E\!\left[\int_0^T f(t,X_t,\alpha_t)\,dt+F(X_T)\right].}\tag{1.12}
$$

The function

$$
f:[0,T]\times\mathbb R^n\times\mathbb R^m\longrightarrow\mathbb R
$$

is a **running reward**, while $F:\mathbb R^n\to\mathbb R$ is the **terminal reward**. One may also allow explicit dependence on the terminal time, writing $F(T,X_T)$, but this is suppressed in (1.12).

If $\mathcal A(x)$ denotes the admissible controls from initial state $X_0=x$, the maximum achievable reward is the **value function**

$$
\boxed{u(x):=\sup_{\alpha\in\mathcal A(x)}J(x;\alpha).}\tag{1.13}
$$

#### Infinite-Horizon Objective

For $\mathcal T=\mathbb R_+$ and $X_0=x$, the typical criterion is

$$
J(x;\alpha):=\mathbb E\!\left[\int_0^\infty e^{-\beta t}f(X_t,\alpha_t)\,dt\right],
$$

where $\beta>0$ is a discount rate, usually needed to ensure that the objective is well defined, and $f:\mathbb R^n\times\mathbb R^m\to\mathbb R$ is the running reward. The value function is again given by equation (1.13).

### 1.2.3 — Variants with Optimal Stopping

Sometimes the controller may **also choose when the problem ends**. This creates a combined stochastic-control and optimal-stopping problem. In other circumstances, the state process does not depend on a control, and the agent's only decision is when to claim a reward, giving a **pure optimal-stopping problem**.

Strictly speaking, a pure optimal-stopping problem is not usually classified as a stochastic-control problem in the narrower controlled-diffusion sense. Nevertheless, dynamic-programming ideas can be applied to optimal stopping and to problems that combine stopping with control. We briefly describe these variants, although they are not the main focus here.

#### Pure Optimal Stopping

The uncontrolled $\mathbb R^n$-valued diffusion has dynamics

$$
dX_t=b(X_t)\,dt+\sigma(X_t)\,dW_t,
\qquad X_0=x\in\mathbb R^n,
$$

where

$$
b:\mathbb R^n\to\mathbb R^n,
\qquad
\sigma:\mathbb R^n\to\mathbb R^{n\times d}.
$$

We are again on the filtered probability space $\left(\Omega,\mathcal F,\mathbb F,\mathbb P\right)$. Let $\mathfrak T$ denote the collection of $\mathbb F$-stopping times taking values in $\mathcal T$. For a stopping time $\tau\in\mathfrak T$, a typical criterion is

$$
J(x;\tau):=\mathbb E\!\left[\int_0^\tau f(t,X_t)\,dt+F(\tau,X_\tau)\right],
$$

with running reward $f:\mathcal T\times\mathbb R^n\to\mathbb R$ and terminal reward $F:\mathcal T\times\mathbb R^n\to\mathbb R$. The value function is

$$
u(x):=\sup_{\tau\in\mathfrak T}J(x;\tau).
$$

The familiar example is the exercise of an **American put option** on an underlying asset with non-negative price process $X$. In that case,

$$
f\equiv0,\qquad F(t,x):=e^{-rt}(K-x)^+,
\qquad t\in\mathcal T,\quad x\in\mathbb R_+,
$$

where $r\geq0$ is the interest rate and $K\geq0$ is the strike.

#### Combined Optimal Stopping and Control

If the state is a controlled diffusion of the form (1.11) and the controller can also select the termination time, the objective becomes

$$
J(x;\alpha,\tau):=\mathbb E\!\left[\int_0^\tau f(t,X_t,\alpha_t)\,dt+F(\tau,X_\tau)\right],
$$

where $\alpha$ is a control process, $\tau\in\mathfrak T$ is a stopping time,

$$
f:\mathcal T\times\mathbb R^n\times\mathbb R^m\to\mathbb R,
\qquad F:\mathcal T\times\mathbb R^n\to\mathbb R.
$$

With $\mathcal A(x)$ denoting the admissible controls given $X_0=x$, the value function is

$$
u(x):=\sup_{\substack{\alpha\in\mathcal A(x)\\\tau\in\mathfrak T}}J(x;\alpha,\tau).
$$

One example is an **investment decision coupled to the exercise of a real option**. An agent trades a stock, generating a controlled self-financing wealth process $X$, and may choose a stopping time $\tau$ at which to pay an amount $K$ to invest in an industrial project, such as an oil well. The project's stochastic value $Y$ is correlated with the traded wealth or asset dynamics. At exercise, the project produces payoff $Y_\tau-K$.

The state is $\left(X,Y\right)$, with initial point $\left(X_0,Y_0\right)=(x,y)\in\mathbb R_+^2$. The control is a trading strategy $\pi$, representing the amount of wealth in the stock. For a utility function $U:\mathbb R\to\mathbb R$ describing satisfaction from wealth, one possible objective is

$$
J(x,y;\pi,\tau):=\mathbb E\!\left[U\!\left(X_\tau+Y_\tau-K\right)\right],
$$

and the corresponding value function is

$$
u(x,y):=\sup_{\substack{\pi\in\mathcal A(x,y)\\\tau\in\mathfrak T}}J(x,y;\pi,\tau),
$$

where $\mathcal A(x,y)$ denotes admissible strategies from $\left(X_0,Y_0\right)=(x,y)$ and $\mathfrak T$ is the collection of stopping times in the permitted time set.

---

## 1.3 — The Merton Problems

The classical financial stochastic-control problem is the **Merton problem**: choose investment and consumption so as to maximise the expected utility of **terminal wealth** and **intermediate consumption**.

We begin with direct methods in a Black–Scholes–Merton market. Dynamic-programming methods for more general Markovian controlled systems are left to the next chapter section, beginning with **Dynamic Programming and the HJB Equation**.

### 1.3.1 — The Market and the Wealth Process

Let $S=(S_t)_{t\geq0}$ be the price of a continuously traded stock on a filtered probability space $\left(\Omega,\mathcal F,\mathbb F,\mathbb P\right)$. Under the Black–Scholes–Merton model, the stock follows **geometric Brownian motion**:

$$
dS_t=\mu S_t\,dt+\sigma S_t\,dW_t,
\qquad \mu\in\mathbb R,\quad\sigma>0,
$$

where $W$ is an $\mathbb F$-Brownian motion, and $\mu$ and $\sigma$ are known constants. There is also a constant risk-free interest rate $r\geq0$. We may take $\mathbb F$ to be the $\mathbb P$-augmentation of the natural filtration of $W$, so that it satisfies the usual conditions of right-continuity and completeness.

An agent with initial capital $x>0$ trades the stock and cash and may consume at a non-negative, adapted rate $c=(c_t)_{t\geq0}$. Let $X=(X_t)_{t\geq0}$ be portfolio wealth, and let $H_t$ denote the number of shares held at time $t$. The amount invested in cash is $X_t-H_tS_t$. Consequently, wealth evolves as

$$
\begin{aligned}
dX_t
&=H_t\,dS_t+r(X_t-H_tS_t)\,dt-c_t\,dt\\
&=rX_t\,dt+\sigma\pi_t(\lambda\,dt+dW_t)-c_t\,dt,
\qquad X_0=x,
\end{aligned}\tag{1.14}
$$

where

$$
\pi_t:=H_tS_t,
\qquad
\lambda:=\frac{\mu-r}{\sigma}.
$$

Thus $\pi$ is the adapted strategy giving the **amount of wealth invested in the stock**, while $\lambda$ is its **market price of risk**.

The agent chooses an investment–consumption pair $\left(\pi,c\right)$ from an admissible class $\mathcal A(x)$, seeking to maximise expected utility over a given finite horizon $[0,T]$. The value function is

$$
\boxed{u(x):=\sup_{(\pi,c)\in\mathcal A(x)}\mathbb E\!\left[\int_0^T e^{-\delta t}U_1(c_t)\,dt+U_2(X_T)\right],}\tag{1.15}
$$

where $U_1$ and $U_2$ are **increasing, concave utility functions** expressing the agent's preferences, and $\delta>0$ is a subjective consumption discount rate representing impatience: the preference to consume sooner rather than later.

The problem is to find an optimal investment–consumption strategy $\left(\widehat\pi,\widehat c\right)$ that attains the supremum. The **state** is wealth $X$; the **control** is the pair $\left(\pi,c\right)$. Admissibility generally depends on the utility function. For example, when terminal-wealth utility $U_2$ is defined only for non-negative wealth, one can specify $\mathcal A(x)$ as those strategies for which $X_t\geq0$ almost surely throughout the horizon.

### 1.3.2 — Utility Functions and Risk Aversion

Utility functions are increasing, concave functions intended to represent a rational, risk-averse agent's preferences towards wealth or consumption. We do not develop their economic justification here; for a fuller discussion, see **Föllmer and Schied**, Chapter 2.

The three classical choices are:

**Logarithmic utility**

$$
U(x)=\log x,\qquad x>0.
$$

**Power utility**

$$
U(x)=\frac{x^p}{p},\qquad p<1,\quad p\neq0,\quad x>0.
$$

**Exponential utility**

$$
U(x)=-e^{-\alpha x},\qquad\alpha>0,\quad x\in\mathbb R.
$$

The **coefficient of absolute risk aversion** is

$$
R_A(x):=-\frac{U''(x)}{U'(x)},
$$

while the **coefficient of relative risk aversion** is

$$
R_R(x):=-\frac{xU''(x)}{U'(x)}.
$$

For power and logarithmic utility, absolute risk aversion is proportional to $1/x$. These utilities are commonly discussed within the **hyperbolic absolute risk aversion (HARA)** family. Their relative risk aversion is constant, so both are **constant relative risk aversion (CRRA)** utilities:

$$
\begin{array}{c|cc}
\text{Utility}&R_A(x)&R_R(x)\\\hline
\log x&1/x&1\\
x^p/p&(1-p)/x&1-p
\end{array}
$$

For CRRA preferences, optimal trading strategies are often expressed most naturally in terms of the **fraction of wealth** invested in the stock.

For exponential utility,

$$
R_A(x)=\alpha,
$$

which is constant. This explains the label **constant absolute risk aversion (CARA)**. Optimal strategies under CARA preferences are typically represented in terms of the **amount of wealth** invested in the stock.

The logarithmic and power utilities satisfy the **Inada conditions** at zero and infinity:

$$
U'(0):=\lim_{x\downarrow0}U'(x)=+\infty,
\qquad
U'(\infty):=\lim_{x\to\infty}U'(x)=0.
$$

The first condition expresses a severe utility penalty near zero wealth: the marginal utility $U'(x)$ of an additional unit of wealth becomes arbitrarily large as wealth approaches zero. The second expresses the decay of marginal utility as wealth grows very large.

Exponential utility has analogous limiting behaviour, but its first limit occurs as wealth tends to $-\infty$ rather than zero.

### 1.3.3 — Variations of the Merton Problem

Equation (1.15) is the **finite-horizon Merton problem for utility from consumption and terminal wealth**. Several natural variations follow by changing the objective.

#### Finite-Horizon Utility from Terminal Wealth

For a utility function $U$, define

$$
\boxed{u(x):=\sup_{\pi\in\mathcal A(x)}\mathbb E[U(X_T)],
\qquad X_0=x.}\tag{1.16}
$$

There is no consumption, $c\equiv0$, and equation (1.14) reduces to

$$
dX_t=rX_t\,dt+\sigma\pi_t(\lambda\,dt+dW_t),
\qquad X_0=x.
$$

For a CRRA utility $U:\mathbb R_+\to\mathbb R$, the admissible class may require non-negative wealth. For exponential utility, where negative wealth is allowed, admissibility needs a different definition. One possible choice is the class of strategies for which **discounted wealth is a supermartingale under every equivalent martingale measure** $\mathbb Q$. The reasons for this choice are technical and are not pursued here; the source notes refer to papers [5, 1, 17, 18] for more detail.

#### Finite-Horizon Utility from Consumption

Here the value function is

$$
\boxed{u(x):=\sup_{(\pi,c)\in\mathcal A(x)}\mathbb E\!\left[\int_0^T e^{-\delta t}U(c_t)\,dt\right].}\tag{1.17}
$$

Wealth again follows equation (1.14), and $\mathcal A(x)$ contains the investment–consumption strategies whose wealth process remains non-negative.

#### Infinite-Horizon Utility from Consumption

The analogous infinite-horizon objective is

$$
\boxed{u(x):=\sup_{(\pi,c)\in\mathcal A(x)}\mathbb E\!\left[\int_0^\infty e^{-\delta t}U(c_t)\,dt\right].}\tag{1.18}
$$

The wealth dynamics remain those in equation (1.14), and admissibility is defined as in the finite-horizon consumption problem. Any or all of the preceding formulations are frequently called **the Merton problem**.

### 1.3.4 — Variations with Stochastic Volatility

The investment and consumption problems above can be studied with more complicated stock-price dynamics. Suppose volatility itself is a diffusion process $Y$ driven by a Brownian motion correlated with the Brownian motion driving the stock.

Let $\left(W,W^\perp\right)$ be a two-dimensional Brownian motion, with $W^\perp$ independent of $W$, and let $\mathbb F$ be its augmented natural filtration. Given a constant correlation $\rho\in(-1,1)$, define

$$
\widetilde W:=\rho W+\sqrt{1-\rho^2}\,W^\perp.
$$

Assume a constant risk-free interest rate $r\geq0$. Stock price $S$ and stochastic volatility $Y$ evolve according to

$$
\begin{aligned}
dS_t&=rS_t\,dt+Y_tS_t\bigl(\lambda(Y_t)\,dt+dW_t\bigr),\\
dY_t&=a(Y_t)\,dt+b(Y_t)\,d\widetilde W_t,
\end{aligned}
$$

for suitable functions $a$, $b$ and $\lambda$. The process $\lambda(Y)$ is the stock's **market price of risk**.

An agent trading in the stock and cash and consuming at non-negative rate $c$ generates wealth

$$
dX_t=rX_t\,dt+Y_t\pi_t\bigl(\lambda(Y_t)\,dt+dW_t\bigr)-c_t\,dt,
\qquad X_0=x>0,
$$

where $\pi$ is the amount of wealth invested in the stock.

If only the stock and cash are liquidly traded, this market is **incomplete**. The additional Brownian risk $W^\perp$ affects volatility and therefore stock dynamics, but cannot generally be eliminated through trading in the single stock. In particular, claims exposed to the volatility factor cannot all be perfectly hedged by stock-and-cash portfolios.

We may still study Merton problems in this richer market. With $c\equiv0$, an initial state $(X_0,Y_0)=(x,y)\in\mathbb R_+^2$, and CRRA terminal utility $U:\mathbb R_+\to\mathbb R$, the terminal-wealth value function becomes

$$
u(x,y):=\sup_{\pi\in\mathcal A(x,y)}\mathbb E[U(X_T)].
$$

The class $\mathcal A(x,y)$ is chosen so that wealth stays non-negative. This generalises equation (1.16) to a market with stochastic volatility. Similar extensions can be formulated for equations (1.15), (1.17), and (1.18).

### 1.3.5 — Problems with Random Endowment

Another family of Merton-type problems allows the agent to receive a **random endowment**, such as an income stream or the payoff of a derivative at a future time.

#### Example 1.1 — Basis-Risk Hedging

Consider a **basis-risk model** (see Monoyios [5]) in which a Black–Scholes–Merton stock $S$ is traded to hedge a European contingent claim on a **non-traded** asset $Y$. The second asset follows correlated geometric Brownian motion.

Let $W$ and $W^\perp$ be independent Brownian motions on a filtered probability space

$$
(\Omega,\mathcal F,\mathbb F=(\mathcal F_t)_{t\in[0,T]},\mathbb P),
$$

where $\mathbb F$ is the augmented filtration generated by $\left(W,W^\perp\right)$. For a correlation parameter $\rho\in[-1,1]$, the dynamics are

$$
\begin{aligned}
dS_t&=\mu S_t\,dt+\sigma S_t\,dW_t,\\
dY_t&=\nu Y_t\,dt+\eta Y_t\left(\rho\,dW_t+\sqrt{1-\rho^2}\,dW_t^\perp\right),
\end{aligned}
$$

where $\mu,\nu\in\mathbb R$ are constant drifts and $\sigma,\eta>0$ are constant volatilities.

For $|\rho|\neq1$ the market is incomplete. Because $Y$ is not traded, claims written on $Y$ cannot generally be replicated using $S$. The non-traded factor might be a weather index or a large basket of stocks whose continual rebalancing would involve prohibitive transaction costs, so it is treated as effectively non-tradable.

In an incomplete market, valuation and hedging must account for the residual risk that cannot be removed by trading. A natural approach is to embed valuation and hedging in an **optimal investment problem**, allowing the agent's attitude towards risk to influence the result.

With exponential utility and initial state $(X_0,Y_0)=(x,y)$, where $X$ denotes wealth from trading $S$ and cash, let $h(Y_T)$ be the payoff of the claim at time $T$. We consider

$$
u(x,y)=\sup_{\pi\in\mathcal A(x,y)}\mathbb E\!\left[U\bigl(X_T-h(Y_T)\bigr)\right],
\qquad U(x)=-e^{-\alpha x}.
$$

One admissible class is the set of strategies for which **discounted wealth is a martingale under all equivalent martingale measures** $\mathbb Q$. Because the market is incomplete, there are infinitely many such measures. The source notes express their density processes as

$$
\left.\frac{d\mathbb Q}{d\mathbb P}\right|_{\mathcal F_t}
=\mathcal E\!\left(-\lambda W-\psi\!\cdot\!W^\perp\right)_t,
\qquad t\in[0,T],
$$

where $\lambda$ is the stock's constant market price of risk and $\psi$ is an adapted process such that

$$
\int_0^T\psi_t^2\,dt<\infty\qquad\text{almost surely}.
$$

The stochastic exponential $\mathcal E$ is defined below when we solve the direct Merton problem. Additional conditions may be needed for a given density process to define a true martingale measure.

#### Example 1.2 — Merton Consumption with an Income Stream

Consider the infinite-horizon consumption problem in (1.18) in the Black–Scholes–Merton market. Suppose the agent receives additional income at a constant rate $a\geq0$. Wealth then evolves according to

$$
dX_t=rX_t\,dt+\sigma\pi_t(\lambda\,dt+dW_t)-c_t\,dt+a\,dt,
\qquad X_0=x.
$$

The objective remains the one in (1.18). However, the admissible set changes, requiring wealth to remain above the lower bound $-a/r$; equivalently, $X+a/r$ must remain non-negative almost surely (when $r>0$).

The intuition is that the agent may **borrow against future income**. The present value of the perpetual income stream, under a strictly positive constant interest rate, is

$$
\int_0^\infty e^{-rt}a\,dt=\frac{a}{r},\qquad r>0.
$$

The agent can borrow this amount and then follow the no-income optimal investment–consumption strategy with adjusted initial wealth $x+a/r$.

### 1.3.6 — Problems with a Random Horizon

Another variation replaces a fixed terminal time with a **random horizon**. Consider the terminal-wealth problem (1.16), but maximise expected utility $\mathbb E[U(X_\tau)]$ at an almost surely finite, non-negative random time $\tau$.

For example, let $\tau\sim\operatorname{Exp}(\eta)$ with $\eta>0$, independent of the Brownian filtration. Integrating over the probability density of the random time gives

$$
\mathbb E[U(X_\tau)]
=\mathbb E\!\left[\int_0^\infty\eta e^{-\eta t}U(X_t)\,dt\right].
$$

For initial wealth $x>0$, this leads to an infinite-horizon problem in which utility is derived from the entire **intertemporal wealth process**:

$$
u(x)=\sup_{\pi\in\mathcal A(x)}\mathbb E\!\left[\int_0^\infty e^{-\eta t}U(X_t)\,dt\right],
\qquad x>0.
$$

The value function of the original random-horizon problem is $\eta u(x)$.

---

## 1.4 — The Merton Terminal-Wealth Problem: A Direct Approach

We now consider the terminal-wealth problem (1.16) and solve it **formally for logarithmic utility** using a direct method. This is possible because the Black–Scholes–Merton model is one-dimensional and has constant coefficients. Later, the same result can be obtained through the more systematic theory of stochastic control and dynamic programming.

### 1.4.1 — Wealth Dynamics Without Consumption

Assume $c\equiv0$ on a finite horizon $[0,T]$ in a standard Black–Scholes–Merton market. Portfolio wealth satisfies

$$
\boxed{dX_t=rX_t\,dt+\sigma\pi_t(\lambda\,dt+dW_t),
\qquad X_0=x>0.}\tag{1.19}
$$

The trading strategy $\pi=(\pi_t)_{t\in[0,T]}$ specifies the amount of wealth invested in the stock. The investor chooses a process $\pi$ from an admissible set $\mathcal A(x)$ to maximise expected terminal utility:

$$
\boxed{u(x):=\sup_{\pi\in\mathcal A(x)}\mathbb E[U(X_T)],
\qquad x>0,}\tag{1.20}
$$

where $U$ is increasing and concave.

### 1.4.2 — Logarithmic Utility and Proportional Investment

Take

$$
U(x)=\log x,\qquad x>0.
$$

Define $\mathcal A(x)$ as the class of strategies under which the wealth process remains **strictly positive**. Anticipating the result, introduce the **fraction of wealth invested in the risky asset**:

$$
\theta_t:=\frac{\pi_t}{X_t},\qquad t\in[0,T].
$$

In terms of $\theta$, the wealth dynamics become

$$
\boxed{dX_t=X_t\left[(r+\sigma\lambda\theta_t)\,dt+\sigma\theta_t\,dW_t\right],
\qquad X_0=x.}\tag{1.21}
$$

Applying **Itô's formula** to $\log X_t$ yields

$$
\boxed{\log X_t=\log x+rt+\sigma\int_0^t\theta_s\left(\lambda-\frac12\sigma\theta_s\right)ds
+\sigma\int_0^t\theta_s\,dW_s,\quad t\in[0,T].}\tag{1.22}
$$

Equivalently, exponentiating gives

$$
\boxed{X_t=x\exp\!\left[rt+\sigma\int_0^t\theta_s\left(\lambda-\frac12\sigma\theta_s\right)ds
+\sigma\int_0^t\theta_s\,dW_s\right],\quad t\in[0,T].}\tag{1.23}
$$

In compact notation,

$$
X_t=x\exp\!\left(rt+\sigma\lambda\int_0^t\theta_s\,ds\right)
\mathcal E(\sigma\theta\!\cdot\!W)_t,
\qquad t\in[0,T].
$$

Here $b\!\cdot\!W$ denotes the stochastic integral

$$
(b\!\cdot\!W)_t:=\int_0^t b_s\,dW_s
$$

for an appropriate integrand $b$. For a continuous local martingale $Y$, the **stochastic exponential** is

$$
\mathcal E(Y)_t:=\exp\!\left(Y_t-\frac12[Y]_t\right),
$$

where $[Y]$ denotes the quadratic variation of $Y$. More generally, the exponential uses the increment $Y_t-Y_0$ when $Y_0\neq0$.

### 1.4.3 — Maximising Expected Logarithmic Utility

We can now solve (1.20) formally for logarithmic utility, subject to a few strong assumptions that can ultimately be justified.

Assume the stochastic integral in (1.22) is a **true martingale**. Its expectation is therefore zero, so

$$
\boxed{\mathbb E[\log X_T]=\log x+rT
+\sigma\mathbb E\!\left[\int_0^T\theta_t\left(\lambda-\frac12\sigma\theta_t\right)dt\right].}\tag{1.24}
$$

We maximise the right-hand side by maximising its integrand with respect to $\theta_t$. The optimal fraction is constant:

$$
\boxed{\widehat\theta_t=\frac{\lambda}{\sigma},
\qquad t\in[0,T].}\tag{1.25}
$$

Thus the optimal strategy for maximising expected logarithmic utility of terminal wealth is to maintain a **constant proportion** of wealth in the risky stock. Maintaining that proportion requires continuous portfolio rebalancing.

Substituting $\theta=\widehat\theta$ into (1.23) gives the optimal wealth process:

$$
\boxed{\widehat X_t=x\exp\!\left((r+\lambda^2)t\right)\mathcal E(\lambda W)_t
=e^{rt}\frac{x}{\mathcal E(-\lambda W)_t},\qquad t\in[0,T].}\tag{1.26}
$$

The maximum expected utility is

$$
\boxed{u(x)=\mathbb E[\log\widehat X_T]
=\log x+\left(r+\frac12\lambda^2\right)T.}\tag{1.27}
$$

### 1.4.4 — Remark: Martingale Measures and Deflators

Define the **Radon–Nikodym derivative** of the unique equivalent martingale measure $\mathbb Q$ by its density process

$$
\left.\frac{d\mathbb Q}{d\mathbb P}\right|_{\mathcal F_t}
:=Z_t:=\mathcal E(-\lambda W)_t
=\exp\!\left(-\lambda W_t-\frac12\lambda^2t\right),
\qquad t\in[0,T].
$$

Define also the **deflator**

$$
Y_t:=e^{-rt}Z_t,\qquad t\in[0,T].
$$

Then the value function in (1.27) can be expressed as

$$
\boxed{u(x)=\log x+rT-\mathbb E[\log Z_T]
=\log x-\mathbb E[\log Y_T].}\tag{1.28}
$$

The optimal wealth process in (1.26) is

$$
\boxed{\widehat X_t=\frac{x}{Y_t},
\qquad t\in[0,T].}\tag{1.29}
$$

This relationship is not accidental. It is connected with the **dual approach to utility maximisation**, which is not developed in the source course; see, for example, **Björk**, Chapter 27.

### 1.4.5 — Remark: Other Utility Functions

The source notes' Problem Sheet 1 invites the reader to repeat the same direct calculations for other utility functions. The resulting optimal strategies and value functions are the following.

#### Power Utility

For

$$
U(x)=\frac{x^p}{p},\qquad p<1,\quad p\neq0,\quad x>0,
$$

the optimal risky fraction is

$$
\boxed{\widehat\theta_t=\frac{\lambda}{\sigma(1-p)},
\qquad t\in[0,T].}\tag{1.30}
$$

Once again, the strategy keeps a **constant proportion** of wealth invested in stock at all times. The logarithmic-utility solution is recovered in the limit $p\to0$.

The maximum utility is

$$
\boxed{u(x)=\frac{x^p}{p}\exp\!\left[\left(rp+\frac12\frac{p}{1-p}\lambda^2\right)T\right],
\qquad x>0.}\tag{1.31}
$$

#### Exponential Utility

For

$$
U(x)=-\exp(-\alpha x),\qquad\alpha>0,\quad x\in\mathbb R,
$$

the optimal strategy is naturally expressed in terms of $\pi$, the **amount** of wealth invested in the risky stock:

$$
\boxed{\widehat\pi_t=e^{-r(T-t)}\frac{\lambda}{\alpha\sigma},
\qquad t\in[0,T].}\tag{1.32}
$$

The corresponding maximum utility is

$$
\boxed{u(x)=-\exp\!\left(-\alpha x e^{rT}-\frac12\lambda^2T\right).}\tag{1.33}
$$

---

## Where We Go Next

The direct computation succeeded because the coefficients of the Black–Scholes–Merton model are constant and the problem is one-dimensional. A more general **systematic stochastic-control method** is required when the state has several dimensions, the market coefficients are state-dependent, or controls affect more complicated dynamics.

The natural next topic is **Dynamic Programming and the Hamilton–Jacobi–Bellman (HJB) Equation**, which starts at Section 3 of the source notes and is **not included in this chapter**.

---

## Sources and Further Reading

1. T. Björk, *Arbitrage Theory in Continuous Time*, 4th ed., Oxford University Press, 2019. Recommended reading: Chapters 25–28 [source reference 2].
2. H. Pham, *Continuous-Time Stochastic Control and Optimization with Financial Applications*, Springer, 2009. Recommended reading: Chapters 2–6 [source reference 14].
3. L. C. G. Rogers, *Optimal Investment*, Springer, 2013. Recommended reading: Chapters 1–2 [source reference 16].
4. H. Föllmer and A. Schied, *Stochastic Finance*, 4th revised and extended ed., De Gruyter, 2016 [source reference 6].
5. M. Monoyios, “Performance of utility-based strategies for hedging basis risk,” *Quantitative Finance*, 4 (2004), 245–255 [source reference 9].
6. D. Becherer, “Utility-indifference hedging and valuation via reaction-diffusion systems,” *Proceedings of the Royal Society A*, 460 (2004), 27–51 [source reference 1].
7. F. Delbaen, P. Grandits, T. Rheinländer, D. Samperi, M. Schweizer and C. Stricker, “Exponential hedging and entropic penalties,” *Mathematical Finance*, 12 (2002), 99–123 [source reference 5].
8. W. Schachermayer, “Optimal investment in incomplete markets when wealth may become negative,” *Annals of Applied Probability*, 11 (2001), 694–734 [source reference 17].
9. W. Schachermayer, “A super-martingale property of the optimal portfolio process,” *Finance and Stochastics*, 7 (2003), 433–456 [source reference 18].


## Supporting material

- [Exercises]({{ '/pages/mathematics/control_theory/stochastic-controls/01-mathematical-foundations-of-stochastic-control/01-probabilistic-preliminaries-and-brownian-motion/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/control_theory/stochastic-controls/01-mathematical-foundations-of-stochastic-control/01-probabilistic-preliminaries-and-brownian-motion/solutions/' | relative_url }})
- [References]({{ '/pages/mathematics/control_theory/stochastic-controls/01-mathematical-foundations-of-stochastic-control/01-probabilistic-preliminaries-and-brownian-motion/references/' | relative_url }})

## Subchapter navigation

Previous: this is the first subchapter

[Back to Chapter 1: Mathematical Foundations of Stochastic Control]({{ '/pages/mathematics/control_theory/stochastic-controls/01-mathematical-foundations-of-stochastic-control/' | relative_url }})

[Next: 1.2 - Ito Calculus and Stochastic Integrals]({{ '/pages/mathematics/control_theory/stochastic-controls/01-mathematical-foundations-of-stochastic-control/02-ito-calculus-and-stochastic-integrals/' | relative_url }})

</article>

