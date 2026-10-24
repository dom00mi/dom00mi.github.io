---
layout: default
title: "The Real Number System: Foundations and Properties"
permalink: /pages/mathematics/analysis/real-number-system/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/analysis/' | relative_url }}">← Mathematical Analysis</a>
  <div class="eyebrow">Mathematics / Analysis / 01</div>
  <h1>The Real Number System</h1>
  <p class="lead">Foundations and Properties — number systems, order, completeness, bounds, and the Archimedean property.</p>
</div>

<article class="article" markdown="1">

> **Intent.** These notes are written primarily for educational purposes and personal revision, with the hope that they may also be useful to others interested in mathematics.

We begin with the very foundations of the real number system. In any journey through mathematics, I believe Mathematical Analysis is one of the most fundamental subjects, providing the rigorous framework upon which much of modern mathematics is built.

As Neil Falkner once wrote:

"Analysis is the art of taming infinity." — Neil Falkner, American Mathematical Monthly (2009)

With this thought in mind, we revisit the fundamental concepts of Analysis, beginning with the structure of the real numbers and the properties that underpin the subject.

I hope you enjoy the journey.

## Contents

1. [From natural to real numbers](#1-from-natural-to-real-numbers)
2. [The ordered field of real numbers](#2-the-ordered-field-of-real-numbers)
3. [Absolute value and distance](#3-absolute-value-and-distance)
4. [Intervals and bounded sets](#4-intervals-and-bounded-sets)
5. [Maximum, minimum, supremum, and infimum](#5-maximum-minimum-supremum-and-infimum)
6. [The completeness property](#6-the-completeness-property)
7. [The Archimedean property](#7-the-archimedean-property)
8. [Density of rational and irrational numbers](#8-density-of-rational-and-irrational-numbers)
9. [Key results and review](#9-key-results-and-review)

---

## 1. From natural to real numbers

Let's introduce 

The familiar number systems form the nested chain

$$
\mathbb{N}\subset\mathbb{Z}\subset\mathbb{Q}\subset\mathbb{R}.
$$

We take $\mathbb N=\{1,2,3,\ldots\}$, $\mathbb Z$ to be the integers, and

$$
\mathbb{Q}=\left\{\frac{p}{q}:p\in\mathbb{Z},\ q\in\mathbb{N}\right\}.
$$

Rational numbers do not exhaust the number line. For instance, $\sqrt 2$ is irrational.

**Proposition.** $\sqrt 2\notin\mathbb Q$.

**Proof.** Suppose $\sqrt 2=p/q$ for integers $p,q$ with $q\ne0$ and no common factor. Then $p^2=2q^2$, so $p$ is even. Write $p=2k$. It follows that $q^2=2k^2$, so $q$ is even as well, contradicting that $p/q$ was in lowest terms. $\square$

The real numbers include both rational and irrational numbers. One rigorous construction of $\mathbb R$ uses equivalence classes of Cauchy sequences of rational numbers; another uses Dedekind cuts. For the present chapter, we work with the defining properties of $\mathbb R$ rather than constructing it from scratch.

## 2. The ordered field of real numbers

The real numbers form a **field**: addition and multiplication obey the usual associative, commutative, and distributive laws, with additive and multiplicative identities $0$ and $1$. Every $x\ne0$ has a multiplicative inverse.

They also have an order compatible with arithmetic. In particular, for $x,y,z\in\mathbb R$:

- If $x<y$, then $x+z<y+z$.
- If $x<y$ and $z>0$, then $xz<yz$.
- If $x<y$ and $z<0$, then $xz>yz$.

These rules make $\mathbb R$ an **ordered field**. The extra property that distinguishes $\mathbb R$ from $\mathbb Q$ is completeness, introduced below.

## 3. Absolute value and distance

For $x\in\mathbb R$, define

$$
|x|=\begin{cases}x,&x\ge0,\\-x,&x<0.\end{cases}
$$

The distance between two real numbers is $d(x,y)=|x-y|$.

**Triangle inequality.** For all $x,y\in\mathbb R$,

$$
|x+y|\le |x|+|y|.
$$

**Proof.** From $-|x|\le x\le |x|$ and $-|y|\le y\le |y|$, addition gives

$$
-(|x|+|y|)\le x+y\le |x|+|y|.
$$

By the definition of absolute value, this implies the desired inequality. $\square$

A useful consequence is the **reverse triangle inequality**:

$$
\big||x|-|y|\big|\le |x-y|.
$$

## 4. Intervals and bounded sets

For $a<b$, the open and closed intervals are

$$
(a,b)=\{x\in\mathbb R:a<x<b\},\qquad
[a,b]=\{x\in\mathbb R:a\le x\le b\}.
$$

Half-open and unbounded intervals are defined similarly.

A set $A\subseteq\mathbb R$ is **bounded above** if there is an $M\in\mathbb R$ such that $a\le M$ for every $a\in A$. Such an $M$ is an *upper bound*. Lower bounds are defined analogously. A set is **bounded** if it is bounded both above and below.

For example, $A=(0,1)$ is bounded above by $1$, $2$, and every larger number, but has no largest element.

## 5. Maximum, minimum, supremum, and infimum

A **maximum** of a nonempty set $A$ is an element $m\in A$ such that $a\le m$ for every $a\in A$. A **minimum** is defined with the inequality reversed.

The **supremum** $\sup A$ is the *least upper bound* of $A$; the **infimum** $\inf A$ is the *greatest lower bound*. For a nonempty set bounded above or below, respectively, these are real numbers by completeness.

| Set $A$ | $\min A$ | $\max A$ | $\inf A$ | $\sup A$ |
|---|---:|---:|---:|---:|
| $(0,1)$ | Does not exist | Does not exist | $0$ | $1$ |
| $[0,1)$ | $0$ | Does not exist | $0$ | $1$ |
| $[0,1]$ | $0$ | $1$ | $0$ | $1$ |

**Characterization of the supremum.** For a nonempty set $A$ bounded above, $s=\sup A$ if and only if:

1. $a\le s$ for every $a\in A$; and
2. for every $\varepsilon>0$, there is some $a\in A$ with $s-\varepsilon<a$.

The second condition says that no number strictly below $s$ can remain an upper bound.

## 6. The completeness property

**Least-upper-bound axiom.** Every nonempty subset of $\mathbb R$ that is bounded above has a supremum in $\mathbb R$.

This is the defining completeness property of the real numbers as an ordered field. It is not true in $\mathbb Q$: the rational set

$$
A=\{q\in\mathbb Q:q>0,\ q^2<2\}
$$

is bounded above in $\mathbb Q$ but has no supremum **in $\mathbb Q$**. Its least upper bound in $\mathbb R$ is $\sqrt 2$.

Completeness underpins many later results, including the monotone convergence theorem for sequences and the existence of limits of Cauchy sequences.

## 7. The Archimedean property

**Theorem (Archimedean property).** For every $x\in\mathbb R$, there exists $n\in\mathbb N$ such that $n>x$.

**Proof.** Suppose instead that $\mathbb N$ were bounded above in $\mathbb R$. By completeness, $s=\sup\mathbb N$ would exist. Since $s-1$ is not an upper bound, some $n\in\mathbb N$ would satisfy $n>s-1$. But then $n+1\in\mathbb N$ and $n+1>s$, contradicting the definition of $s$. $\square$

**Consequences.** For every $\varepsilon>0$, some $n\in\mathbb N$ satisfies $1/n<\varepsilon$. More generally, if $a>0$ and $b\in\mathbb R$, there exists $n\in\mathbb N$ such that $na>b$.

The Archimedean property is fundamental when choosing sufficiently large indices in proofs of convergence.

## 8. Density of rational and irrational numbers

A subset $D\subseteq\mathbb R$ is **dense in $\mathbb R$** if every open interval $(a,b)$ with $a<b$ contains a point of $D$.

**Theorem.** Both $\mathbb Q$ and $\mathbb R\setminus\mathbb Q$ are dense in $\mathbb R$.

**Proof (rational case).** Let $a<b$. By the Archimedean property, choose $n\in\mathbb N$ with $n(b-a)>1$. There exists an integer $m$ with $na<m\le na+1$. Hence

$$
a<\frac mn\le a+\frac1n<b,
$$

so $m/n$ is a rational number in $(a,b)$.

**Proof (irrational case).** Apply rational density to the interval $(a-\sqrt2,b-\sqrt2)$, obtaining $r\in\mathbb Q$ inside it. Then $r+\sqrt2\in(a,b)$ and is irrational. $\square$

Density does **not** mean every real number is rational; it means rational numbers can approximate any real number arbitrarily closely.

## 9. Key results and review

Before moving on to sequences and limits, you should be comfortable with:

- The inclusions $\mathbb N\subset\mathbb Z\subset\mathbb Q\subset\mathbb R$.
- The distinction between an ordered field and a complete ordered field.
- Absolute value, distance, and the triangle inequality.
- The difference between a maximum and a supremum.
- The least-upper-bound axiom and the Archimedean property.
- Why rational and irrational numbers are both dense in $\mathbb R$.

**Self-check.** Can you explain why $(0,1)$ has a supremum but no maximum? Can you prove that $1/n\to0$ using the Archimedean property?

---

### Continue studying

TBD

- [Exercises]({{ '/pages/mathematics/analysis/real-number-system/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/analysis/real-number-system/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/analysis/real-number-system/references/' | relative_url }})
- [Back to Mathematical Analysis]({{ '/pages/mathematics/analysis/' | relative_url }})

</article>
