---
layout: default
title: "Finite Probability Spaces: Foundations and Properties"
permalink: /pages/mathematics/probability_theory/finite-probability-spaces/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/probability_theory/' | relative_url }}">← Mathematical Analysis</a>
  <div class="eyebrow">Mathematics / Probability Theory / 01</div>
  <h1>Finite Probability Spaces: Foundations and Properties</h1>
  <p class="lead">Foundations and Properties — .</p>
</div>

<article class="article" markdown="1">



# Finite Probability Spaces

> **Theoretical Journey from Basics to Advanced Mathematics**  
> Probability Theory · Foundations

## Introduction

In his famous work *An Investigation of the Laws of Thought* (1854, pp. 243–244), **George Boole** wrote:

> *"Probability is expectation founded upon partial knowledge. A perfect acquaintance with all the circumstances affecting the occurrence of an event would change expectation into certainty, and leave neither room nor demand for a theory of probabilities."*
>
> — **George Boole**, *An Investigation of the Laws of Thought* (1854).

I find this a beautiful way of thinking about probability. After all, uncertainty is something we deal with every day. We constantly make predictions, judge how likely something is to happen, and make decisions without knowing everything. Most of the time, we do this almost instinctively, without thinking about the mathematics behind it.

This reminds me of another famous observation, attributed to **Pierre-Simon Laplace**:

> *"Probability theory is nothing but common sense reduced to calculation."*
>
> — **Pierre-Simon Laplace**, *Théorie analytique des probabilités*.

And I think there is a lot of truth in that. Many ideas in probability are surprisingly intuitive once we understand what they are trying to describe. Yet, as with much of mathematics, turning intuition into something precise requires a bit more work.

This is where the formalism becomes important. Definitions, axioms, $\sigma$-algebras, probability measures, and all the mathematical machinery that might initially seem unnecessary are actually what allow us to take simple ideas and build something much deeper from them.

**That is really the motivation behind these notes.**

I wanted to put together something that starts from the very basics, explains not only the definitions but also the intuition behind them, and gradually builds towards more advanced concepts. In the hope that someone approaching probability for the first time might find it useful.

I certainly do not intend these notes to replace the excellent textbooks already available on the subject. Rather, I hope they can offer another perspective, perhaps making some of the more abstract ideas feel a little more natural.

After all, if probability really is common sense reduced to calculation, then understanding the common sense behind the calculations seems like a good place to start. Hence let's start!

---

## Overview

We begin with **finite probability spaces**, using simple experiments such as tossing a coin to introduce the basic mathematical framework.

From there, we explore how events are represented, how probabilities are assigned, and how information can be described mathematically through $\sigma$-algebras and filtrations. Finally, we introduce random variables and their probability distributions.

The goal is to move gradually from familiar examples to more formal definitions, building the foundations needed for the study of stochastic processes and more advanced probability theory.

---

## References

For textbooks and further reading, see [References](./references.md).


## Overview

Probability theory provides a rigorous language for describing uncertainty. We begin with experiments that have finitely many possible outcomes, then introduce the mathematical structures needed to describe events, assign probabilities, and model information revealed over time.

**Contents**

1. [Sample spaces and events](#1-sample-spaces-and-events)
2. [Sigma-algebras and measurable spaces](#2-sigma-algebras-and-measurable-spaces)
3. [Probability measures](#3-probability-measures)
4. [Information and filtrations](#4-information-and-filtrations)
5. [A filtration for three coin tosses](#5-a-filtration-for-three-coin-tosses)
6. [Random variables](#6-random-variables)
7. [Generated sigma-algebras and distributions](#7-generated-sigma-algebras-and-distributions)
8. [Key ideas](#8-key-ideas)
9. [References](#9-references)

---

## 1. Sample spaces and events

A **random experiment** is a procedure whose result cannot be predicted with certainty. The **sample space**, denoted by $\Omega$, is the set of all possible outcomes.

### Example: three coin tosses

Toss a coin three times and record the result of each toss as either heads ($H$) or tails ($T$). The sample space is

$$
\Omega = \Omega_3 = \{HHH,HHT,HTH,HTT,THH,THT,TTH,TTT\}.
$$

Each outcome $\omega\in\Omega$ is a sequence of length three. Write $\omega_k$ for its $k$-th entry. For example, if $\omega=HTH$, then

$$
\omega_1=H,\qquad \omega_2=T,\qquad \omega_3=H.
$$

An **event** is a collection of outcomes. For example, the event that the first toss is heads is

$$
A_H=\{HHH,HHT,HTH,HTT\}
   =\{\omega\in\Omega:\omega_1=H\}.
$$

To specify which collections of outcomes count as measurable events, we introduce a $\sigma$-algebra.

---

## 2. Sigma-algebras and measurable spaces

### Definition: $\sigma$-algebra

Let $\Omega$ be a nonempty set. A collection $\mathcal F$ of subsets of $\Omega$ is a **$\sigma$-algebra** (or **$\sigma$-field**) if:

1. $\varnothing\in\mathcal F$;
2. whenever $A\in\mathcal F$, its complement $A^c=\Omega\setminus A$ also belongs to $\mathcal F$;
3. whenever $A_1,A_2,\ldots\in\mathcal F$, their countable union belongs to $\mathcal F$:

   $$
   \bigcup_{k=1}^{\infty}A_k\in\mathcal F.
   $$

The pair $(\Omega,\mathcal F)$ is called a **measurable space**. Its elements $A\in\mathcal F$ are the **measurable events**.

For a finite sample space, a natural choice is the **power set**:

$$
\mathcal F=2^\Omega=\{A:A\subseteq\Omega\}.
$$

This contains every possible event. Smaller $\sigma$-algebras are also possible and will be important when modelling partial information.

**Useful consequences.** The axioms imply that $\Omega\in\mathcal F$, and that $\mathcal F$ is closed under countable intersections (by De Morgan's laws).

---

## 3. Probability measures

### Definition: probability measure

Given a measurable space $(\Omega,\mathcal F)$, a **probability measure** is a map

$$
\mathbb P:\mathcal F\longrightarrow[0,1]
$$

such that:

1. **Normalization:** $\mathbb P(\Omega)=1$;
2. **Countable additivity:** for any sequence of pairwise disjoint events $A_1,A_2,\ldots\in\mathcal F$,

   $$
   \mathbb P\!\left(\bigcup_{k=1}^{\infty}A_k\right)
   =\sum_{k=1}^{\infty}\mathbb P(A_k).
   $$

It follows that $\mathbb P(\varnothing)=0$. The triple

$$
(\Omega,\mathcal F,\mathbb P)
$$

is called a **probability space**. The quantity $\mathbb P(A)$ describes the probability that the experiment produces an outcome in $A$.

### Example: three independent, possibly biased coin tosses

Suppose each toss produces heads with probability $p\in(0,1)$ and tails with probability $q=1-p$, independently of the other tosses.

For $\omega\in\Omega$, let $N_H(\omega)$ and $N_T(\omega)$ count its heads and tails. Assign each individual outcome the probability

$$
\mathbb P(\{\omega\})=p^{N_H(\omega)}q^{N_T(\omega)},
\qquad N_H(\omega)+N_T(\omega)=3.
$$

Since $\Omega$ is finite, the probability of any event is the sum of the probabilities of its outcomes:

$$
\boxed{\mathbb P(A)=\sum_{\omega\in A}\mathbb P(\{\omega\})},
\qquad A\in\mathcal F.
$$

For the event $A_H$ that the first toss is heads,

$$
\begin{aligned}
\mathbb P(A_H)
&=\mathbb P(\{HHH\})+\mathbb P(\{HHT\})
  +\mathbb P(\{HTH\})+\mathbb P(\{HTT\})\\
&=p^3+2p^2q+pq^2\\
&=p(p+q)^2\\
&=p.
\end{aligned}
$$

Thus the probability of heads on the first toss is $p$, as expected.

---

## 4. Information and filtrations

A $\sigma$-algebra can be understood as a mathematical description of **available information**. An event belongs to the information available at a given time if, using what has been observed by then, we can determine whether that event occurred.

In the three-toss experiment, let $\mathcal F_k$ represent everything observable after the first $k$ tosses, for $k=0,1,2,3$.

### Definition: filtration

For a time index set $\mathcal T=\{0,1,\ldots,n\}$, a **filtration** is a family of $\sigma$-algebras

$$
\mathbb F=(\mathcal F_k)_{k\in\mathcal T}
$$

satisfying

$$
\mathcal F_k\subseteq\mathcal F_\ell\subseteq\mathcal F
\qquad\text{whenever }k\leq\ell.
$$

A probability space equipped with a filtration,

$$
(\Omega,\mathcal F,\mathbb P,\mathbb F),
$$

is called a **filtered probability space**. The inclusion property expresses the idea that information accumulates: observing more cannot erase previously available information.

The same notion extends to infinite discrete time $\mathcal T=\mathbb Z_{\geq0}$ or continuous time $\mathcal T=[0,\infty)$.

---

## 5. A filtration for three coin tosses

Return to

$$
\Omega=\{HHH,HHT,HTH,HTT,THH,THT,TTH,TTT\}.
$$

### Time 0: no tosses observed

Before any toss, no outcome-specific information is available. The only events we can determine are the impossible event and the certain event:

$$
\boxed{\mathcal F_0=\{\varnothing,\Omega\}}.
$$

This is the **trivial $\sigma$-algebra**.

### Time 1: the first toss observed

Define the two possible first-toss events:

$$
\begin{aligned}
A_H&=\{HHH,HHT,HTH,HTT\},\\
A_T&=\{THH,THT,TTH,TTT\}.
\end{aligned}
$$

Once the first toss is known, we can distinguish $A_H$ from $A_T$, but cannot determine the second or third toss. Hence

$$
\boxed{\mathcal F_1=\{\varnothing,\Omega,A_H,A_T\}}.
$$

For example, the event that the **second** toss is heads is

$$
B_H=\{HHH,HHT,THH,THT\}.
$$

It is not in $\mathcal F_1$, because knowing only the first toss does not tell us whether $B_H$ occurred.

### Time 2: the first two tosses observed

The first two tosses yield four mutually exclusive events:

$$
\begin{aligned}
A_{HH}&=\{HHH,HHT\},& A_{HT}&=\{HTH,HTT\},\\
A_{TH}&=\{THH,THT\},& A_{TT}&=\{TTH,TTT\}.
\end{aligned}
$$

Each event describes a possible two-toss history, without specifying the third toss. The corresponding $\sigma$-algebra consists of **all unions** of these four events:

$$
\mathcal F_2=\sigma(A_{HH},A_{HT},A_{TH},A_{TT}).
$$

More explicitly,

$$
\begin{aligned}
\mathcal F_2=\{&\varnothing,\Omega,\\
&A_{HH},A_{HT},A_{TH},A_{TT},\\
&A_{HH}\cup A_{HT},\ A_{HH}\cup A_{TH},\
 A_{HH}\cup A_{TT},\\
&A_{HT}\cup A_{TH},\ A_{HT}\cup A_{TT},\
 A_{TH}\cup A_{TT},\\
&A_{HH}^{c},A_{HT}^{c},A_{TH}^{c},A_{TT}^{c}\}.
\end{aligned}
$$

There are $2^4=16$ events in $\mathcal F_2$. In particular, $A_H=A_{HH}\cup A_{HT}$ and $A_T=A_{TH}\cup A_{TT}$, so $\mathcal F_1\subseteq\mathcal F_2$.

### Time 3: all tosses observed

After all three tosses, the complete outcome $\omega$ is known. Every subset of $\Omega$ can therefore be identified:

$$
\boxed{\mathcal F_3=\mathcal F=2^\Omega}.
$$

The complete filtration is

$$
\boxed{\mathcal F_0\subseteq\mathcal F_1\subseteq\mathcal F_2\subseteq\mathcal F_3}.
$$

| Time | Observed information | Number of events |
|:---:|---|---:|
| $0$ | No tosses | $2$ |
| $1$ | First toss | $4$ |
| $2$ | First two tosses | $16$ |
| $3$ | All three tosses | $256$ |

**General principle.** $\mathcal F_k$ contains precisely those events whose occurrence can be decided using the first $k$ observed tosses.

---

## 6. Random variables

### Definition: real-valued random variable

A **random variable** on $(\Omega,\mathcal F)$ is a measurable function

$$
X:\Omega\longrightarrow\mathbb R.
$$

Measurability means that, for every Borel set $B\in\mathcal B(\mathbb R)$, the preimage

$$
X^{-1}(B)=\{\omega\in\Omega:X(\omega)\in B\}
=\{X\in B\}
$$

belongs to $\mathcal F$.

Here $\mathcal B(\mathbb R)$ denotes the **Borel $\sigma$-algebra** on $\mathbb R$.

### Example: indicator random variable

For an event $A\in\mathcal F$, its indicator is

$$
\mathbf 1_A(\omega)=
\begin{cases}
1,&\omega\in A,\\
0,&\omega\notin A.
\end{cases}
$$

The indicator records whether the event occurred and is a measurable random variable.

---

## 7. Generated sigma-algebras and distributions

### The $\sigma$-algebra generated by a random variable

The **$\sigma$-algebra generated by $X$** is

$$
\boxed{\sigma(X)=\big\{X^{-1}(B):B\in\mathcal B(\mathbb R)\big\}}.
$$

It represents exactly the information revealed by observing $X$.

If $\mathcal G\subseteq\mathcal F$ is itself a $\sigma$-algebra, then $X$ is **$\mathcal G$-measurable** precisely when

$$
\sigma(X)\subseteq\mathcal G.
$$

For example, if $X=\mathbf 1_{A_H}$ indicates whether the first toss is heads, then

$$
\sigma(X)=\{\varnothing,\Omega,A_H,A_T\}=\mathcal F_1.
$$

### The law of a random variable

Let $(\Omega,\mathcal F,\mathbb P)$ be a probability space and $X$ a real-valued random variable. Its **distribution** (also called its **law** or **induced measure**) is the measure $\mu_X$ on $(\mathbb R,\mathcal B(\mathbb R))$ defined by

$$
\boxed{\mu_X(B)=\mathbb P\big(X^{-1}(B)\big)
=\mathbb P(X\in B)},\qquad B\in\mathcal B(\mathbb R).
$$

The distribution describes probabilities of values taken by $X$, rather than probabilities of the original outcomes $\omega$.

**Example.** Let $X=\mathbf 1_{A_H}$. Then $X$ takes values $0$ and $1$, with

$$
\mathbb P(X=1)=p,\qquad \mathbb P(X=0)=1-p=q.
$$

Thus $X$ has a Bernoulli distribution with parameter $p$.

---

## 8. Key ideas

- **Sample space $\Omega$:** all possible outcomes of an experiment.
- **$\sigma$-algebra $\mathcal F$:** the events to which probabilities can be assigned.
- **Probability measure $\mathbb P$:** a normalized, countably additive assignment of probabilities to events.
- **Filtration $(\mathcal F_k)$:** the information available as time progresses.
- **Random variable $X$:** a measurable numerical function of an outcome.
- **Generated $\sigma$-algebra $\sigma(X)$:** information contained in the observation of $X$.
- **Distribution $\mu_X$:** probabilities induced on the values of $X$.

Together, these concepts form the foundation for more advanced probability theory and stochastic processes.

## 9. References

See [reference.md](reference.md) for introductory and advanced textbooks on probability, measure theory, and stochastic processes.
