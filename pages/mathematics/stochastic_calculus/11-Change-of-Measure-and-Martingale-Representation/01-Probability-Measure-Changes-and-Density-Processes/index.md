---
layout: default
title: "11.1: Probability Measure Changes and Density Processes"
permalink: /pages/mathematics/stochastic_calculus/11-change-of-measure-and-martingale-representation/01-probability-measure-changes-and-density-processes/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/stochastic_calculus/11-change-of-measure-and-martingale-representation/01-probability-measure-changes-and-density-processes/' | relative_url }}">← Probability Measure Changes and Density Processes</a>
  <div class="eyebrow">Mathematics / Stochastic Calculus / 11.1</div>
  <h1>Probability Measure Changes and Density Processes</h1>
  <p class="lead">Placeholder topic for Probability Measure Changes and Density Processes. (TBD)</p>
</div>

<article class="article" markdown="1">

# 1. Probability Measure Changes and Density Processes

> A change of probability measure does not alter the possible outcomes of a random experiment; it changes the weights assigned to those outcomes. The Radon–Nikodym derivative makes this reweighting precise, while the density processes describe how it evolves as information is revealed.

Changing probability measures is a central idea in modern probability theory. It provides a common language for **likelihood ratios in statistics**, **Monte Carlo importance sampling** **conditional expectations**, **martingale transformations**, **Girsanov's theorem**, and **arbitrage-free pricing in mathematical finance**.

The principal question is the following: given two probability measures $\mathbb{P}$ and $\mathbb{Q}$ on the same measurable space, when can expectations under one measure be calculated using the other? The answer is expressed in terms of a *density*, or *Radon–Nikodym derivative*. On a filtered probability space, these densities become a martingale; for Brownian models, they can be constructed using stochastic exponentials.

Throughout this chapter, equalities between random variables are understood **almost surely** under the relevant measure unless otherwise stated. Expectations under the two measures are denoted by $\mathbb{E}^{\mathbb{P}}$ and $\mathbb{E}^{\mathbb{Q}}$.

---

## 1.1. Absolute Continuity and Equivalent Probability Measures

Let

$$
(\Omega,\mathcal{F})
$$

be a measurable space, and let $\mathbb{P}$ and $\mathbb{Q}$ be probability measures on $\mathcal{F}$.

**Definition 1.1 (Absolute continuity of measures).** We say that $\mathbb{Q}$ is *absolutely continuous* with respect to $\mathbb{P}$, written

$$
\mathbb{Q}\ll\mathbb{P},
$$

if

$$
\mathbb{P}(A)=0\quad\Longrightarrow\quad\mathbb{Q}(A)=0,
\qquad A\in\mathcal{F}.
$$

Thus, every event that is impossible under $\mathbb{P}$ must also be impossible under $\mathbb{Q}$. The implication need not hold in the opposite direction.

**Definition 1.2 (Equivalent measures).** The probability measures $\mathbb{P}$ and $\mathbb{Q}$ are *equivalent*, written

$$
\mathbb{Q}\sim\mathbb{P},
$$

if both

$$
\mathbb{Q}\ll\mathbb{P}
\qquad\text{and}\qquad
\mathbb{P}\ll\mathbb{Q}.
$$

Equivalence is therefore characterised by the identity of null sets:

$$
\boxed{
\mathbb{P}(A)=0\quad\Longleftrightarrow\quad\mathbb{Q}(A)=0,
\qquad A\in\mathcal{F}.
}
$$

**Definition 1.3 (Mutually singular measures).** We write

$$
\mathbb{P}\perp\mathbb{Q}
$$

if there exists $A\in\mathcal{F}$ such that

$$
\mathbb{P}(A)=1,
\qquad
\mathbb{Q}(A)=0.
$$

In this case, the two measures are concentrated on disjoint measurable sets, up to null sets. This notion will become important when discussing repeated statistical observations and changes of measure over an infinite time horizon.

### 1.1.1. Why equivalence matters

Under equivalent measures, the sets of possible outcomes agree up to null sets, but their probabilities may differ. Consequently, any statement that holds almost surely under $\mathbb{P}$ also holds almost surely under $\mathbb{Q}$, and conversely.

In mathematical finance, this is particularly useful: an *equivalent martingale measure* changes the probabilistic dynamics of asset prices without changing which events have zero probability.

---

## 1.2. The Radon–Nikodym Theorem

The Radon–Nikodym theorem gives a precise representation of one measure in terms of another.

**Theorem 1.4 (Radon–Nikodym theorem: probability version).** Suppose that

$$
\mathbb{Q}\ll\mathbb{P}.
$$

Then there exists an $\mathcal{F}$-measurable random variable $Z$ such that

$$
Z\geq 0\quad\mathbb{P}\text{-a.s.},
\qquad
\mathbb{E}^{\mathbb{P}}[Z]=1,
$$

and

$$
\boxed{
\mathbb{Q}(A)
=\int_A Z\,d\mathbb{P}
=\mathbb{E}^{\mathbb{P}}[Z\mathbf{1}_A],
\qquad A\in\mathcal{F}.
}
$$

The random variable $Z$ is unique up to $\mathbb{P}$-almost-sure equality. It is called the **Radon–Nikodym derivative** or **density** of $\mathbb{Q}$ with respect to $\mathbb{P}$, and is denoted by

$$
\boxed{Z=\frac{d\mathbb{Q}}{d\mathbb{P}}.}
$$

The general theorem applies to $\sigma$-finite measures; for probability measures, the total mass condition immediately implies $\mathbb{E}^{\mathbb{P}}[Z]=1$.

**Corollary 1.5 (Equivalence and positive densities).** If $\mathbb{Q}\ll\mathbb{P}$ and $Z=d\mathbb{Q}/d\mathbb{P}$, then

$$
\mathbb{Q}\sim\mathbb{P}
\quad\Longleftrightarrow\quad
Z>0\quad\mathbb{P}\text{-a.s.}
$$

In this case,

$$
\boxed{
\frac{d\mathbb{P}}{d\mathbb{Q}}=\frac{1}{Z}
\quad\mathbb{Q}\text{-a.s.}
}
$$

**Proof.** If $Z>0$ almost surely and $\mathbb{Q}(A)=0$, then

$$
0=\mathbb{E}^{\mathbb{P}}[Z\mathbf{1}_A]
$$

implies $\mathbb{P}(A)=0$. Hence $\mathbb{P}\ll\mathbb{Q}$. Conversely, if $\mathbb{P}\ll\mathbb{Q}$, then

$$
\mathbb{Q}(Z=0)
=\mathbb{E}^{\mathbb{P}}[Z\mathbf{1}_{\{Z=0\}}]=0,
$$

so $\mathbb{P}(Z=0)=0$. The reciprocal-density identity follows from the change-of-measure formula below. $\square$

### 1.2.1. Constructing a probability measure from a density

The converse construction is just as important as the theorem itself.

**Proposition 1.6 (Density construction).** Let $Z$ be an $\mathcal{F}$-measurable random variable satisfying

$$
Z\geq 0,
\qquad
\mathbb{E}^{\mathbb{P}}[Z]=1.
$$

Then

$$
\mathbb{Q}(A)
:=\mathbb{E}^{\mathbb{P}}[Z\mathbf{1}_A],
\qquad A\in\mathcal{F},
$$

defines a probability measure satisfying $\mathbb{Q}\ll\mathbb{P}$.

**Proof.** Positivity of $Z$ implies $\mathbb{Q}(A)\geq 0$, while

$$
\mathbb{Q}(\Omega)=\mathbb{E}^{\mathbb{P}}[Z]=1.
$$

For pairwise disjoint sets $A_1,A_2,\ldots\in\mathcal{F}$, put $B_n=\bigcup_{k=1}^{n}A_k$. Then $\mathbf{1}_{B_n}\uparrow\mathbf{1}_{\cup_{k\geq1}A_k}$, and the monotone convergence theorem gives

$$
\begin{aligned}
\mathbb{Q}\left(\bigcup_{k=1}^{\infty}A_k\right)
&=\lim_{n\to\infty}\mathbb{E}^{\mathbb{P}}[Z\mathbf{1}_{B_n}]\\
&=\lim_{n\to\infty}\sum_{k=1}^{n}\mathbb{E}^{\mathbb{P}}[Z\mathbf{1}_{A_k}]\\
&=\sum_{k=1}^{\infty}\mathbb{Q}(A_k).
\end{aligned}
$$

Finally, $\mathbb{P}(A)=0$ implies $\mathbb{Q}(A)=\int_AZ\,d\mathbb{P}=0$. $\square$

---

## 1.3. Changing Expectations: Likelihood Ratios

A density is not only a representation of a measure; it is also a tool for transforming integrals.

**Theorem 1.7 (Change-of-measure identity).** Suppose that $\mathbb{Q}\ll\mathbb{P}$ and

$$
Z=\frac{d\mathbb{Q}}{d\mathbb{P}}.
$$

For any non-negative measurable random variable $X$,

$$
\boxed{
\mathbb{E}^{\mathbb{Q}}[X]
=\mathbb{E}^{\mathbb{P}}[XZ].
}
$$

The identity also holds for any $X$ integrable under $\mathbb{Q}$. If $\mathbb{Q}\sim\mathbb{P}$, then, whenever the expressions are well-defined,

$$
\boxed{
\mathbb{E}^{\mathbb{P}}[Y]
=\mathbb{E}^{\mathbb{Q}}\left[\frac{Y}{Z}\right].
}
$$

**Proof.** For an indicator $X=\mathbf{1}_A$, the assertion follows from the definition of the density:

$$
\mathbb{E}^{\mathbb{Q}}[\mathbf{1}_A]
=\mathbb{Q}(A)
=\mathbb{E}^{\mathbb{P}}[Z\mathbf{1}_A].
$$

By linearity, it holds for non-negative simple random variables. If $X\geq0$ is measurable, choose non-negative simple random variables $X_n\uparrow X$. Applying the monotone convergence theorem under both measures yields

$$
\begin{aligned}
\mathbb{E}^{\mathbb{Q}}[X]
&=\lim_{n\to\infty}\mathbb{E}^{\mathbb{Q}}[X_n]\\
&=\lim_{n\to\infty}\mathbb{E}^{\mathbb{P}}[X_nZ]\\
&=\mathbb{E}^{\mathbb{P}}[XZ].
\end{aligned}
$$

For integrable signed $X$, apply the result separately to $X^+$ and $X^-$. The reverse identity follows by applying the same argument to $d\mathbb{P}/d\mathbb{Q}=1/Z$. $\square$

**Remark (Interpretation as reweighting).** The random variable $Z$ represents the relative likelihood of observing a particular outcome under $\mathbb{Q}$ rather than $\mathbb{P}$. Outcomes with $Z>1$ receive more weight under $\mathbb{Q}$; outcomes with $0\leq Z<1$ receive less weight.

### 1.3.1. Restricting a probability measure

**Lemma 1.8 (Restriction to a sub-$\sigma$-algebra).** Let $\mathcal{G}\subseteq\mathcal{F}$ be a sub-$\sigma$-algebra, and define

$$
\widetilde{\mathbb{P}}:=\mathbb{P}\big\vert_{\mathcal{G}}.
$$

Then $\widetilde{\mathbb{P}}$ is a probability measure on $(\Omega,\mathcal{G})$. For every $\mathcal{G}$-measurable random variable $Y$ integrable under $\mathbb{P}$,

$$
\mathbb{E}^{\mathbb{P}}[Y]
=\mathbb{E}^{\widetilde{\mathbb{P}}}[Y].
$$

**Proof.** Since $Y$ is $\mathcal{G}$-measurable, the events $Y^{-1}(B)$ belong to $\mathcal{G}$ for every Borel set $B$. Hence the pushforward distributions of $Y$ under $\mathbb{P}$ and $\widetilde{\mathbb{P}}$ agree, which gives equality of their integrals. $\square$

The measurability assumption matters: the restricted probability space cannot, in general, integrate a random variable that is not $\mathcal{G}$-measurable.

---

## 1.4. Conditional Expectation Through the Radon–Nikodym Theorem

The Radon–Nikodym theorem provides a direct proof of the existence of conditional expectations, without requiring the geometric interpretation as an orthogonal projection in $L^2$.

**Theorem 1.9 (Existence of conditional expectation).** Let $(\Omega,\mathcal{F},\mathbb{P})$ be a probability space, $\mathcal{G}\subseteq\mathcal{F}$ a sub-$\sigma$-algebra, and $X\in L^1(\mathbb{P})$. Then there exists a $\mathcal{G}$-measurable, integrable random variable $Y$ such that

$$
\boxed{
\int_A Y\,d\mathbb{P}
=\int_A X\,d\mathbb{P},
\qquad A\in\mathcal{G}.
}
$$

It is unique up to $\mathbb{P}$-almost-sure equality and is denoted by

$$
Y=\mathbb{E}^{\mathbb{P}}[X\mid\mathcal{G}].
$$

**Proof.** Assume first that $X\geq0$. Define a finite measure $\nu$ on $(\Omega,\mathcal{G})$ by

$$
\nu(A):=\int_A X\,d\mathbb{P},
\qquad A\in\mathcal{G}.
$$

If $\widetilde{\mathbb{P}}=\mathbb{P}\vert_{\mathcal{G}}$, then $\nu\ll\widetilde{\mathbb{P}}$. The Radon–Nikodym theorem therefore yields a non-negative $\mathcal{G}$-measurable random variable $Y$ satisfying

$$
\nu(A)
=\int_A Y\,d\widetilde{\mathbb{P}}
=\int_A Y\,d\mathbb{P},
\qquad A\in\mathcal{G}.
$$

Taking $A=\Omega$ gives

$$
\mathbb{E}^{\mathbb{P}}[Y]
=\mathbb{E}^{\mathbb{P}}[X]<\infty.
$$

For a general integrable $X$, write

$$
X=X^+-X^-,
\qquad
X^+=\max(X,0),
\qquad
X^-=\max(-X,0),
$$

and apply the non-negative argument to each part. Their difference satisfies the defining integral identity.

Uniqueness follows because if two $\mathcal{G}$-measurable random variables satisfy the same identity, their difference integrates to zero over every event in $\mathcal{G}$. Applying this to the events where the difference is positive or negative shows that the difference vanishes almost surely. $\square$

**Connection.** This construction reveals conditional expectation as a Radon–Nikodym derivative on a smaller information set:

$$
\mathbb{E}^{\mathbb{P}}[X\mid\mathcal{G}]
=\frac{d\nu}{d(\mathbb{P}\vert_{\mathcal{G}})},
\qquad
\nu(A)=\mathbb{E}^{\mathbb{P}}[X\mathbf{1}_A].
$$

---

## 1.5. Density Processes on a Filtered Probability Space

Let

$$
(\Omega,\mathcal{F},(\mathcal{F}_t)_{0\leq t\leq T},\mathbb{P})
$$

be a filtered probability space, where $T<\infty$. Suppose that $\mathbb{Q}\ll\mathbb{P}$ on $\mathcal{F}_T$ and set

$$
Z_T=\frac{d\mathbb{Q}}{d\mathbb{P}}
\bigg\vert_{\mathcal{F}_T}.
$$

**Definition 1.10 (Density process).** The density process of $\mathbb{Q}$ with respect to $\mathbb{P}$ is

$$
\boxed{
Z_t:=\mathbb{E}^{\mathbb{P}}[Z_T\mid\mathcal{F}_t],
\qquad 0\leq t\leq T.
}
$$

It can equivalently be written as

$$
\boxed{
Z_t=\frac{d(\mathbb{Q}\vert_{\mathcal{F}_t})}
{d(\mathbb{P}\vert_{\mathcal{F}_t})}.
}
$$

Indeed, for each $A\in\mathcal{F}_t$,

$$
\mathbb{Q}(A)
=\mathbb{E}^{\mathbb{P}}[Z_T\mathbf{1}_A]
=\mathbb{E}^{\mathbb{P}}[Z_t\mathbf{1}_A].
$$

**Proposition 1.11 (The density is a martingale).** The process $(Z_t)_{0\leq t\leq T}$ is a non-negative, uniformly integrable $\mathbb{P}$-martingale satisfying

$$
\mathbb{E}^{\mathbb{P}}[Z_t]=1,
\qquad 0\leq t\leq T.
$$

**Proof.** Non-negativity follows from the positivity of conditional expectation. For $0\leq s\leq t\leq T$, the tower property gives

$$
\begin{aligned}
\mathbb{E}^{\mathbb{P}}[Z_t\mid\mathcal{F}_s]
&=\mathbb{E}^{\mathbb{P}}
\left[\mathbb{E}^{\mathbb{P}}[Z_T\mid\mathcal{F}_t]\mid\mathcal{F}_s\right]\\
&=\mathbb{E}^{\mathbb{P}}[Z_T\mid\mathcal{F}_s]\\
&=Z_s.
\end{aligned}
$$

Since $Z_t$ is the family of conditional expectations of a fixed integrable random variable $Z_T$, the martingale is uniformly integrable. Taking expectations gives $\mathbb{E}^{\mathbb{P}}[Z_t]=\mathbb{E}^{\mathbb{P}}[Z_T]=1$. $\square$

If $\mathbb{Q}\sim\mathbb{P}$ on $\mathcal{F}_T$, then $Z_t>0$ almost surely at each fixed time $t\leq T$.

### 1.5.1. Consistent families of measures

In discrete time, let

$$
\mathcal{F}_\infty:=\sigma\left(\bigcup_{n\geq0}\mathcal{F}_n\right).
$$

Suppose $\mathbb{Q}\ll\mathbb{P}$ on $\mathcal{F}_\infty$, with

$$
Z=\frac{d\mathbb{Q}}{d\mathbb{P}}.
$$

Then

$$
Z_n=\mathbb{E}^{\mathbb{P}}[Z\mid\mathcal{F}_n]
$$

is a uniformly integrable martingale, and the martingale convergence theorem yields

$$
Z_n\longrightarrow Z
\quad\text{almost surely and in }L^1(\mathbb{P}).
$$

Conversely, let $(Z_n)_{n\geq0}$ be a non-negative $\mathbb{P}$-martingale with $\mathbb{E}^{\mathbb{P}}[Z_n]=1$, and define a probability measure $\mathbb{Q}_n$ on $\mathcal{F}_n$ by

$$
\mathbb{Q}_n(A)=\mathbb{E}^{\mathbb{P}}[Z_n\mathbf{1}_A],
\qquad A\in\mathcal{F}_n.
$$

For $A\in\mathcal{F}_n$,

$$
\begin{aligned}
\mathbb{Q}_{n+1}(A)
&=\mathbb{E}^{\mathbb{P}}[Z_{n+1}\mathbf{1}_A]\\
&=\mathbb{E}^{\mathbb{P}}[Z_n\mathbf{1}_A]\\
&=\mathbb{Q}_n(A).
\end{aligned}
$$

Thus the measures are **consistent**:

$$
\boxed{
\mathbb{Q}_{n+1}\vert_{\mathcal{F}_n}=\mathbb{Q}_n.
}
$$

The non-negative martingale convergence theorem ensures that

$$
Z_n\longrightarrow Z_\infty
\quad\mathbb{P}\text{-a.s.},
\qquad
\mathbb{E}^{\mathbb{P}}[Z_\infty]\leq1.
$$

However, almost-sure convergence alone does **not** guarantee that $Z_\infty$ has expectation one.

**Theorem 1.12 (Uniform integrability and the limiting density).** For a non-negative martingale $(Z_n)$ with $\mathbb{E}^{\mathbb{P}}[Z_n]=1$, the following are equivalent:

1. $(Z_n)$ is uniformly integrable.
2. $Z_n\to Z_\infty$ in $L^1(\mathbb{P})$.
3. $\mathbb{E}^{\mathbb{P}}[Z_\infty]=1$.
4. $Z_n=\mathbb{E}^{\mathbb{P}}[Z_\infty\mid\mathcal{F}_n]$ for all $n$.

Under these equivalent conditions, the probability measure

$$
\mathbb{Q}(A):=\mathbb{E}^{\mathbb{P}}[Z_\infty\mathbf{1}_A],
\qquad A\in\mathcal{F}_\infty,
$$

is absolutely continuous with respect to $\mathbb{P}$ and satisfies

$$
\mathbb{Q}\vert_{\mathcal{F}_n}=\mathbb{Q}_n
\qquad\text{for every }n.
$$

**Proof.** Uniform integrability together with almost-sure convergence implies $L^1$ convergence and preservation of expectations. Conversely, for non-negative $Z_n\to Z_\infty$ almost surely with $\mathbb{E}[Z_n]=1$, equality $\mathbb{E}[Z_\infty]=1$ implies $L^1$ convergence by Scheffé's lemma. An $L^1$-convergent martingale is uniformly integrable, and passing to the limit in the martingale property gives $Z_n=\mathbb{E}[Z_\infty\mid\mathcal{F}_n]$. The final consistency statement follows by integrating against indicators from $\mathcal{F}_n$. $\square$

> **Important distinction.** Consistent finite-time changes of measure need not arise from a single density on the terminal or infinite-horizon $\sigma$-algebra. Uniform integrability is the condition that prevents probability mass from disappearing in the limit. Without it, a consistent extension may still exist in a suitable path-space setting, but it need not be absolutely continuous with respect to $\mathbb{P}$.

---

## 1.6. Bayes' Formula Under a Change of Measure

Assume that $\mathbb{Q}\sim\mathbb{P}$ on $\mathcal{F}_T$, and let $Z_t$ be the strictly positive density process. The next identity transforms **conditional** expectations under $\mathbb{Q}$ into conditional expectations under $\mathbb{P}$.

**Theorem 1.13 (Bayes' formula).** Let $0\leq s\leq t\leq T$, and let $X$ be $\mathcal{F}_t$-measurable with $\mathbb{E}^{\mathbb{Q}}[|X|]<\infty$. Then

$$
\boxed{
\mathbb{E}^{\mathbb{Q}}[X\mid\mathcal{F}_s]
=\frac{1}{Z_s}
\mathbb{E}^{\mathbb{P}}[XZ_t\mid\mathcal{F}_s].
}
$$

Equivalently,

$$
\boxed{
Z_s\mathbb{E}^{\mathbb{Q}}[X\mid\mathcal{F}_s]
=\mathbb{E}^{\mathbb{P}}[XZ_t\mid\mathcal{F}_s].
}
$$

**Proof.** The right-hand side of the first formula is $\mathcal{F}_s$-measurable, so it remains to verify the defining partial-averaging property. For any $A\in\mathcal{F}_s$, the change-of-measure identity implies

$$
\begin{aligned}
\mathbb{E}^{\mathbb{Q}}
\left[\mathbf{1}_A\frac{1}{Z_s}
\mathbb{E}^{\mathbb{P}}[XZ_t\mid\mathcal{F}_s]\right]
&=\mathbb{E}^{\mathbb{P}}
\left[\mathbf{1}_A\frac{Z_s}{Z_s}
\mathbb{E}^{\mathbb{P}}[XZ_t\mid\mathcal{F}_s]\right]\\
&=\mathbb{E}^{\mathbb{P}}[\mathbf{1}_A XZ_t]\\
&=\mathbb{E}^{\mathbb{Q}}[\mathbf{1}_A X].
\end{aligned}
$$

The uniqueness of conditional expectation completes the proof. $\square$

### 1.6.1. Conditional probabilities under the new measure

Taking $X=\mathbf{1}_B$ for $B\in\mathcal{F}_t$ gives

$$
\boxed{
\mathbb{Q}(B\mid\mathcal{F}_s)
=\frac{\mathbb{E}^{\mathbb{P}}[Z_t\mathbf{1}_B\mid\mathcal{F}_s]}{Z_s}.
}
$$

The denominator normalises the weighted conditional probabilities. Bayes' formula can therefore be understood as a dynamic version of likelihood reweighting: the density process records how much the relative weights change as information accumulates.

---

## 1.7. Martingales Under Equivalent Measures

One of the most useful consequences of Bayes' formula is a simple way of determining whether a process is a martingale under a new probability measure.

**Theorem 1.14 (Martingale transfer).** Let $\mathbb{Q}\sim\mathbb{P}$ on $\mathcal{F}_T$ and let $(Z_t)$ be its density process. If $M=(M_t)_{0\leq t\leq T}$ is adapted and $\mathbb{E}^{\mathbb{Q}}[|M_t|]<\infty$ for every $t$, then

$$
\boxed{
M\text{ is a }\mathbb{Q}\text{-martingale}
\quad\Longleftrightarrow\quad
MZ\text{ is a }\mathbb{P}\text{-martingale}.
}
$$

Here $MZ$ denotes the product process $(M_tZ_t)$.

**Proof.** Bayes' formula gives

$$
\mathbb{E}^{\mathbb{Q}}[M_t\mid\mathcal{F}_s]
=\frac{1}{Z_s}
\mathbb{E}^{\mathbb{P}}[M_tZ_t\mid\mathcal{F}_s],
\qquad s\leq t.
$$

Therefore,

$$
\mathbb{E}^{\mathbb{Q}}[M_t\mid\mathcal{F}_s]=M_s
$$

if and only if

$$
\mathbb{E}^{\mathbb{P}}[M_tZ_t\mid\mathcal{F}_s]
=M_sZ_s.
$$

Moreover,

$$
\mathbb{E}^{\mathbb{P}}[|M_tZ_t|]
=\mathbb{E}^{\mathbb{Q}}[|M_t|]<\infty,
$$

so the relevant martingale integrability requirements are satisfied. $\square$

### 1.7.1. The local-martingale version

A process $M$ is a *local martingale* under a measure if there exists an increasing sequence of stopping times $\tau_n\uparrow\infty$ (or up to the terminal horizon) such that each stopped process $M^{\tau_n}$ is a martingale under that measure.

Under the usual localisation conditions for continuous semimartingales, the martingale-transfer principle extends to local martingales:

$$
\boxed{
M\text{ is a }\mathbb{Q}\text{-local martingale}
\quad\Longleftrightarrow\quad
MZ\text{ is a }\mathbb{P}\text{-local martingale}.
}
$$

A useful way to see the forward direction is to stop $M$ at levels making $M^{\tau_n}$ bounded. Then $M^{\tau_n}$ is a true $\mathbb{Q}$-martingale, so $M^{\tau_n}Z$ is a $\mathbb{P}$-martingale by Theorem 1.14. Stopping again at $\tau_n$ gives the stopped product $(MZ)^{\tau_n}$. The reverse direction follows using the reciprocal density and appropriate common localisation.

**Caution.** Local martingales are not necessarily true martingales. In particular, an equality for conditional expectations cannot be asserted for an arbitrary local martingale without the necessary integrability or localisation arguments.

---

## 1.8. Likelihood Ratios and Statistical Experiments

The Radon–Nikodym derivative is called a *likelihood ratio* in statistics. It compares the relative plausibility of an observed sample under two models or hypotheses.

Suppose that the laws under hypotheses $H_0$ and $H_1$ are $\mathbb{P}$ and $\mathbb{Q}$, respectively, with $\mathbb{Q}\ll\mathbb{P}$. For observations represented by $\mathcal{F}_n$, define

$$
L_n:=\frac{d(\mathbb{Q}\vert_{\mathcal{F}_n})}
{d(\mathbb{P}\vert_{\mathcal{F}_n})}.
$$

By the density-process result, $(L_n)$ is a non-negative $\mathbb{P}$-martingale and

$$
\mathbb{E}^{\mathbb{P}}[L_n]=1.
$$

A likelihood-ratio test favours $H_1$ when $L_n$ is sufficiently large and favours $H_0$ when it is small. This follows directly from the interpretation of the density as relative probability weight.

### 1.8.1. Repeated Bernoulli observations

Let $X_1,X_2,\ldots$ be independent coin-toss observations, with $X_k=1$ for heads and $X_k=0$ for tails. Consider two values

$$
0<a<b<1,
$$

and let $\mathbb{P}_a$ and $\mathbb{P}_b$ denote the corresponding laws on the infinite sequence space. Write

$$
\mathcal{F}_n=\sigma(X_1,\ldots,X_n),
\qquad
S_n=\sum_{k=1}^{n}X_k.
$$

For every finite $n$, the restrictions of $\mathbb{P}_a$ and $\mathbb{P}_b$ to $\mathcal{F}_n$ are equivalent because every sequence of $n$ outcomes has strictly positive probability under both hypotheses.

The density of $\mathbb{P}_b$ with respect to $\mathbb{P}_a$ on $\mathcal{F}_n$ is

$$
\boxed{
L_n
=\left(\frac{b}{a}\right)^{S_n}
\left(\frac{1-b}{1-a}\right)^{n-S_n}.
}
$$

Indeed, $L_n$ is the ratio of the probabilities of the realised sequence of observations under the two hypotheses. Its logarithm is

$$
\log L_n
=S_n\log\frac{b}{a}
+(n-S_n)\log\frac{1-b}{1-a}.
$$

Under $\mathbb{P}_a$, the strong law of large numbers gives

$$
\frac{S_n}{n}\longrightarrow a
\quad\mathbb{P}_a\text{-a.s.}
$$

Consequently,

$$
\begin{aligned}
\frac{1}{n}\log L_n
&\longrightarrow
 a\log\frac{b}{a}
 +(1-a)\log\frac{1-b}{1-a}\\
&=-D_{\mathrm{KL}}\bigl(\operatorname{Bern}(a)
\,\Vert\,\operatorname{Bern}(b)\bigr)<0,
\end{aligned}
$$

where

$$
D_{\mathrm{KL}}\bigl(\operatorname{Bern}(a)
\,\Vert\,\operatorname{Bern}(b)\bigr)
=a\log\frac{a}{b}
+(1-a)\log\frac{1-a}{1-b}.
$$

Because $a\neq b$, this divergence is strictly positive. Therefore

$$
\boxed{
L_n\longrightarrow0
\quad\mathbb{P}_a\text{-a.s.}
}
$$

Yet for every finite $n$,

$$
\mathbb{E}^{\mathbb{P}_a}[L_n]=1.
$$

It follows that $L_n$ does **not** converge in $L^1(\mathbb{P}_a)$ and is **not uniformly integrable**.

### 1.8.2. Equivalence at finite times, singularity at the limit

Define the event

$$
A_a=
\left\{\lim_{n\to\infty}\frac{S_n}{n}=a\right\}.
$$

By the strong law,

$$
\mathbb{P}_a(A_a)=1,
\qquad
\mathbb{P}_b(A_a)=0.
$$

Therefore,

$$
\boxed{
\mathbb{P}_a\perp\mathbb{P}_b
\quad\text{on }\mathcal{F}_\infty,
}
$$

although their restrictions to every $\mathcal{F}_n$ are equivalent.

This example illustrates a subtle but fundamental principle: **local equivalence does not necessarily imply equivalence on the limiting $\sigma$-algebra**. The failure of uniform integrability is precisely what prevents the finite-time likelihood ratios from converging to a probability density for $\mathbb{P}_b$ with respect to $\mathbb{P}_a$ on $\mathcal{F}_\infty$.

---

## 1.9. Uniform Absolute Continuity and a Martingale Proof of Radon–Nikodym

The relationship between martingales and changes of measure also works in the other direction. Martingale convergence can be used to construct Radon–Nikodym derivatives, first on countably generated $\sigma$-algebras.

**Lemma 1.15 (Uniform absolute continuity).** If $\mathbb{Q}\ll\mathbb{P}$ are probability measures on $\mathcal{F}$, then

$$
\boxed{
\forall\varepsilon>0\;\exists\delta>0\;\forall A\in\mathcal{F},
\qquad
\mathbb{P}(A)<\delta
\ \Longrightarrow\ \mathbb{Q}(A)<\varepsilon.
}
$$

**Proof.** Suppose the assertion were false. Then for some $\varepsilon>0$, there would exist measurable events $A_n$ such that

$$
\mathbb{P}(A_n)<2^{-n},
\qquad
\mathbb{Q}(A_n)\geq\varepsilon.
$$

Let

$$
B=\limsup_{n\to\infty}A_n
=\bigcap_{m\geq1}\bigcup_{n\geq m}A_n.
$$

Since $\sum_{n\geq1}\mathbb{P}(A_n)<\infty$, the first Borel–Cantelli lemma gives $\mathbb{P}(B)=0$. On the other hand, applying the reverse Fatou inequality to the indicators (bounded above by one) gives

$$
\mathbb{Q}(B)
=\mathbb{E}^{\mathbb{Q}}\left[\limsup_{n\to\infty}\mathbf{1}_{A_n}\right]
\geq\limsup_{n\to\infty}\mathbb{Q}(A_n)
\geq\varepsilon.
$$

This contradicts $\mathbb{Q}\ll\mathbb{P}$. $\square$

### 1.9.1. Constructing the density with finite partitions

**Theorem 1.16 (Martingale construction on a countably generated space).** Assume that

$$
\mathcal{F}=\sigma(A_1,A_2,\ldots)
$$

for a countable collection of measurable sets, and let $\mathbb{Q}\ll\mathbb{P}$. Then there exists $Z\in L^1(\mathbb{P})$, $Z\geq0$, such that

$$
\mathbb{Q}(A)=\mathbb{E}^{\mathbb{P}}[Z\mathbf{1}_A],
\qquad A\in\mathcal{F}.
$$

**Proof.** Define the finite $\sigma$-algebras

$$
\mathcal{F}_n=\sigma(A_1,\ldots,A_n).
$$

Each $\mathcal{F}_n$ has a finite set $\mathcal{A}_n$ of non-empty atoms. Define

$$
Z_n
=\sum_{C\in\mathcal{A}_n}
\frac{\mathbb{Q}(C)}{\mathbb{P}(C)}
\mathbf{1}_C,
$$

where a term with $\mathbb{P}(C)=0$ is assigned coefficient zero. This convention is legitimate because $\mathbb{Q}\ll\mathbb{P}$.

By construction, $Z_n$ is non-negative and $\mathcal{F}_n$-measurable. Moreover, for every $A\in\mathcal{F}_n$,

$$
\mathbb{E}^{\mathbb{P}}[Z_n\mathbf{1}_A]
=\mathbb{Q}(A),
$$

because $A$ is a union of atoms of $\mathcal{F}_n$. In particular,

$$
\mathbb{E}^{\mathbb{P}}[Z_n]=1.
$$

For $A\in\mathcal{F}_n$, the same integral identity holds with $Z_{n+1}$ in place of $Z_n$, so

$$
\mathbb{E}^{\mathbb{P}}[Z_{n+1}\mid\mathcal{F}_n]=Z_n.
$$

Thus $(Z_n)$ is a non-negative $\mathbb{P}$-martingale.

To prove uniform integrability, fix $\varepsilon>0$ and take $\delta>0$ from Lemma 1.15. For $K>1/\delta$, Markov's inequality gives, uniformly in $n$,

$$
\mathbb{P}(Z_n>K)
\leq\frac{\mathbb{E}^{\mathbb{P}}[Z_n]}{K}
=\frac{1}{K}<\delta.
$$

Since $\{Z_n>K\}\in\mathcal{F}_n$,

$$
\mathbb{E}^{\mathbb{P}}[Z_n\mathbf{1}_{\{Z_n>K\}}]
=\mathbb{Q}(Z_n>K)<\varepsilon.
$$

This proves uniform integrability. Martingale convergence therefore produces $Z\geq0$ such that

$$
Z_n\longrightarrow Z
\quad\text{in }L^1(\mathbb{P}),
\qquad
Z_n=\mathbb{E}^{\mathbb{P}}[Z\mid\mathcal{F}_n].
$$

For every $A\in\mathcal{F}_n$,

$$
\mathbb{Q}(A)
=\mathbb{E}^{\mathbb{P}}[Z_n\mathbf{1}_A]
=\mathbb{E}^{\mathbb{P}}[Z\mathbf{1}_A].
$$

The union $\bigcup_{n\geq1}\mathcal{F}_n$ is a $\pi$-system generating $\mathcal{F}$. The $\pi$-$\lambda$ theorem (uniqueness of finite measures) extends the equality to every $A\in\mathcal{F}$. Hence

$$
Z=\frac{d\mathbb{Q}}{d\mathbb{P}}.
$$

This completes the construction. $\square$

**Remark.** Countable generation does not mean that $\mathcal{F}$ itself is generated by a countable *partition* into atoms. The proof uses the finite atoms of each $\mathcal{F}_n$, which works for general countably generated spaces, including non-atomic Borel spaces. The full Radon–Nikodym theorem for arbitrary $\sigma$-finite measure spaces requires an additional general measure-theoretic argument.

The preceding sections exhibit a useful conceptual chain:

$$
\boxed{
\text{Martingale convergence}
\ \Longrightarrow\
\text{Radon–Nikodym densities}
\ \Longrightarrow\
\text{Conditional expectations}.
}
$$

This perspective complements the geometric construction of conditional expectation as an $L^2$ projection.

---

## 1.10. Stochastic Exponentials and Continuous-Time Densities

The density processes used in stochastic models are often constructed through **stochastic exponentials**.

Let $W=(W_t)_{0\leq t\leq T}$ be a Brownian motion under $\mathbb{P}$, and let $\theta=(\theta_t)$ be a progressively measurable process satisfying

$$
\int_0^T\theta_s^2\,ds<\infty
\quad\mathbb{P}\text{-a.s.}
$$

Define the continuous local martingale

$$
N_t=-\int_0^t\theta_s\,dW_s.
$$

Its quadratic variation is

$$
\langle N\rangle_t=\int_0^t\theta_s^2\,ds.
$$

**Definition 1.17 (Doléans–Dade stochastic exponential).** The stochastic exponential of a continuous local martingale $N$ is

$$
\mathcal{E}(N)_t
=\exp\left(N_t-\frac12\langle N\rangle_t\right).
$$

For the choice above,

$$
\boxed{
Z_t
=\mathcal{E}\left(-\int_0^{\cdot}\theta_s\,dW_s\right)_t
=\exp\left(
-\int_0^t\theta_s\,dW_s
-\frac12\int_0^t\theta_s^2\,ds
\right).
}
$$

**Proposition 1.18 (Dynamics of the stochastic exponential).** The process $Z$ satisfies

$$
\boxed{
dZ_t=-\theta_tZ_t\,dW_t,
\qquad Z_0=1.
}
$$

**Proof.** Apply Itô's formula to $Z_t=e^{N_t-\langle N\rangle_t/2}$. The quadratic variation term cancels the compensator ${-\langle N\rangle_t/2}$, leaving

$$
dZ_t=Z_t\,dN_t=-\theta_tZ_t\,dW_t.
$$

$\square$

Since $Z_t>0$ at every finite time and $Z$ is a non-negative local martingale, it is also a supermartingale. Consequently,

$$
\mathbb{E}^{\mathbb{P}}[Z_t]\leq1.
$$

The inequality may be strict: **a positive stochastic exponential need not be a true martingale**. To define a probability measure by $d\mathbb{Q}=Z_T\,d\mathbb{P}$, one must ensure $\mathbb{E}^{\mathbb{P}}[Z_T]=1$.

### 1.10.1. Novikov's sufficient condition

**Theorem 1.19 (Novikov's condition).** If

$$
\boxed{
\mathbb{E}^{\mathbb{P}}\left[
\exp\left(\frac12\int_0^T\theta_s^2\,ds\right)
\right]<\infty,
}
$$

then $Z$ is a true, uniformly integrable martingale on $[0,T]$. In particular,

$$
\mathbb{E}^{\mathbb{P}}[Z_T]=1,
$$

and the probability measure

$$
\mathbb{Q}(A)
:=\mathbb{E}^{\mathbb{P}}[Z_T\mathbf{1}_A],
\qquad A\in\mathcal{F}_T,
$$

is well-defined and equivalent to $\mathbb{P}$.

A common sufficient special case is that $\theta$ is uniformly bounded on the finite horizon $[0,T]$.

**Remark.** Novikov's condition is sufficient, not necessary. There are stochastic exponentials that are true martingales even when this particular exponential-moment condition fails.

---


### Further reading

For broader treatments of the ideas in this chapter, see:

- D. Williams, *Probability with Martingales* — conditional expectation, changes of measure, and martingale convergence.
- I. Karatzas and S. E. Shreve, *Brownian Motion and Stochastic Calculus* — continuous martingales, stochastic exponentials, and Girsanov's theorem.
- S. E. Shreve, *Stochastic Calculus for Finance II: Continuous-Time Models* — equivalent martingale measures, pricing, and hedging.

- [Exercises]({{ '/pages/mathematics/stochastic_calculus/11-change-of-measure-and-martingale-representation/01-probability-measure-changes-and-density-processes/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/stochastic_calculus/11-change-of-measure-and-martingale-representation/01-probability-measure-changes-and-density-processes/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/stochastic_calculus/11-change-of-measure-and-martingale-representation/01-probability-measure-changes-and-density-processes/references/' | relative_url }})

[Back to Change of Measure and Martingale Representation]({{ '/pages/mathematics/stochastic_calculus/11-change-of-measure-and-martingale-representation/' | relative_url }})

</article>
