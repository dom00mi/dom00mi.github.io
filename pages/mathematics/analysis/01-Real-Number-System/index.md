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


> **Intent.** These notes are intended primarily for educational purposes, with the aim of helping readers develop a deeper understanding of mathematics and inspiring those who have not yet had the opportunity to explore the subject in depth.

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

The real numbers include both rational and irrational numbers. One rigorous construction of $\mathbb R$ uses equivalence classes of Cauchy sequences of rational numbers. 

The set of real numbers $\mathbb{R}$ can be constructed from the set of rational numbers $\mathbb{Q}$ using a mathematical procedure known as **completion**. To understand this construction, we first need to study sequences, especially Cauchy sequences.

A real number can be formally represented by an equivalence class of Cauchy sequences of rational numbers. Intuitively, a Cauchy sequence is a sequence whose terms become increasingly close to one another, so that the distance between any two sufficiently late terms can be made arbitrarily small.

We commonly represent real numbers using infinite decimal expansions, such as

$$
12.3456789014573\ldots
$$

This decimal expansion can be approximated by a sequence of rational numbers obtained by retaining progressively more digits after the decimal point. For example,

$$
\begin{aligned}
a_0 &= 12,\\
a_1 &= 12.3,\\
a_2 &= 12.34,\\
a_3 &= 12.345,\\
a_4 &= 12.3456,\\
&\vdots
\end{aligned}
$$

Every term $a_i$ is rational. Moreover, the difference between $a_i$ and any later term is at most $10^{-i}$. As $i$ increases, this bound approaches zero, illustrating why the sequence is Cauchy.

The concept of an **equivalence class** ensures that Cauchy sequences representing the same real number are treated as equivalent. For instance,

$$
1.00000\ldots = 0.99999\ldots = 1.
$$

Although these decimal expansions differ in their representation, they determine the same real number.

A fully rigorous construction of $\mathbb{R}$ as the completion of $\mathbb{Q}$ requires a precise definition of Cauchy sequences of rational numbers, which will be developed later. An alternative, mathematically equivalent construction can be found in Chapter 1 of W. Rudin's *Principles of Mathematical Analysis*, Third Edition, McGraw-Hill, 1976.

Both $\mathbb{Q}$ and $\mathbb{R}$ also satisfy a fundamental property known as the **Archimedean axiom**, which we will examine next.

Another construction uses Dedekind cuts. For the present chapter, we work with the defining properties of $\mathbb R$ rather than constructing it from scratch.

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

## Definition: Intervals in $\mathbb{R}$

Let $a,b \in \mathbb{R}$ with $a < b$. We define the **open interval** $(a,b)$ and the **closed interval** $[a,b]$ by

$$
(a,b) := \{x \in \mathbb{R} : a < x < b\},
$$

and

$$
[a,b] := \{x \in \mathbb{R} : a \leq x \leq b\},
$$

respectively.

More generally, we use the following notation for **half-open and half-closed intervals**:

$$
[a,b) := \{x \in \mathbb{R} : a \leq x < b\},
$$

$$
(a,b] := \{x \in \mathbb{R} : a < x \leq b\}.
$$

We also define the following **unbounded intervals**:

$$
(a,\infty) := \{x \in \mathbb{R} : x > a\},
$$

$$
[a,\infty) := \{x \in \mathbb{R} : x \geq a\},
$$

$$
(-\infty,b) := \{x \in \mathbb{R} : x < b\},
$$

and

$$
(-\infty,b] := \{x \in \mathbb{R} : x \leq b\}.
$$

For example, $A=(0,1)$ is bounded above by $1$, $2$, and every larger number, but has no largest element.

## 5. Maximum, minimum, supremum, and infimum

We begin by introducing the concepts of **maximum** and **minimum** of a set $A \subseteq \mathbb{R}$. The maximum is the largest element of the set, while the minimum is its smallest element. However, these elements do not necessarily exist, even when the set is bounded.

To understand when maximum and minimum exist, we first define what it means for a set to be bounded above or below.

### Definition 5.1 (Bounded Sets)

Let $A \subseteq \mathbb{R}$. We say that:

1. **$A$ is bounded above** if there exists $L \in \mathbb{R}$ such that

   $$
   x \leq L \qquad \text{for every } x \in A.
   $$

   In this case, $L$ is called an **upper bound** of $A$.

2. **$A$ is bounded below** if there exists $l \in \mathbb{R}$ such that

   $$
   l \leq x \qquad \text{for every } x \in A.
   $$

   In this case, $l$ is called a **lower bound** of $A$.

3. **$A$ is bounded** if it is both bounded above and bounded below.

### Definition 5.2 (Maximum and Minimum)

Let $A \subseteq \mathbb{R}$ be nonempty.

A number $M \in \mathbb{R}$ is called the **maximum** of $A$ if:

- $M \in A$.
- $x \leq M$ for every $x \in A$.

When such a number exists, we write

$$
\max A := M.
$$

Similarly, a number $m \in \mathbb{R}$ is called the **minimum** of $A$ if:

- $m \in A$.
- $m \leq x$ for every $x \in A$.

When such a number exists, we write

$$
\min A := m.
$$

A number $c \in A$ is called an **extremum** of $A$ if it is either the maximum or the minimum of the set.

### Remark 5.3 (Uniqueness)

If the maximum or minimum of a nonempty set $A \subseteq \mathbb{R}$ exists, then it is unique.

**Exercise:** Prove this statement.

### Remark 5.4 (Existence)

A set does not necessarily have a maximum or a minimum, even if it is bounded. The following examples illustrate this fact.

### Example 5.5

**1. Consider the set**

$$
A = [0,2) = \{x \in \mathbb{R} : 0 \leq x < 2\}.
$$

The minimum exists and is given by

$$
\min A = 0,
$$

because $0 \in A$ and $0 \leq x$ for every $x \in A$.

However, $A$ has no maximum. Indeed, for any $a \in A$, define

$$
b := \frac{a+2}{2}.
$$

Since $a < 2$, we have $a < b < 2$, so $b \in A$ and $b > a$. Thus, every element of $A$ has a larger element in the set.

**2. Consider the closed interval**

$$
A = [3,8].
$$

Both endpoints belong to the set, so

$$
\max A = 8, \qquad \min A = 3.
$$

**3. Consider the set**

$$
A = (-\infty,7] = \{x \in \mathbb{R} : x \leq 7\}.
$$

The maximum exists and equals

$$
\max A = 7.
$$

However, $A$ has no minimum. For any $a \in A$, the number

$$
b := a-1
$$

also belongs to $A$ and satisfies $b < a$. Therefore, no element of $A$ can be its minimum.

The previous examples show that a nonempty bounded set need not have a maximum or a minimum. To describe the least upper bound and greatest lower bound of a set, we introduce the concepts of **supremum** and **infimum**.

### Theorem 5.7 (Existence of the Supremum)

Let $A \subseteq \mathbb{R}$ be nonempty and bounded above. Then the set of all upper bounds of $A$,

$$
U_A := \{L \in \mathbb{R} : L \text{ is an upper bound of } A\},
$$

has a minimum element.

### Definition 5.8 (Supremum)

Let $A \subseteq \mathbb{R}$ be nonempty. The **supremum** of $A$, also called its **least upper bound**, is defined by

$$
\sup A :=
\begin{cases}
\min U_A, & \text{if } A \text{ is bounded above},\\
+\infty, & \text{otherwise},
\end{cases}
$$

where

$$
U_A := \{L \in \mathbb{R} : L \text{ is an upper bound of } A\}.
$$

Thus, if $A$ is bounded above, its supremum is the smallest of all its upper bounds.

### Theorem 5.9 (Existence of the Infimum)

Let $A \subseteq \mathbb{R}$ be nonempty and bounded below. Then the set of all lower bounds of $A$,

$$
L_A := \{l \in \mathbb{R} : l \text{ is a lower bound of } A\},
$$

has a maximum element.

### Definition 5.10 (Infimum)

Let $A \subseteq \mathbb{R}$ be nonempty. The **infimum** of $A$, also called its **greatest lower bound**, is defined by

$$
\inf A :=
\begin{cases}
\max L_A, & \text{if } A \text{ is bounded below},\\
-\infty, & \text{otherwise},
\end{cases}
$$

where

$$
L_A := \{l \in \mathbb{R} : l \text{ is a lower bound of } A\}.
$$

Thus, if $A$ is bounded below, its infimum is the largest of all its lower bounds.

### Remark 5.11 (The Meaning of Infinity)

The symbols $+\infty$ and $-\infty$ do not represent real numbers. They are used to indicate that a set is unbounded.

- $\sup A = +\infty$ means that $A$ is not bounded above.
- $\inf A = -\infty$ means that $A$ is not bounded below.

### Remark 5.12 (Supremum, Infimum, Maximum and Minimum)

The maximum and minimum of a set must belong to the set itself. The supremum and infimum, however, may or may not belong to the set.

### Remark 5.13 (Relationship Between Maximum and Supremum)

Whenever $\max A$ exists, we have

$$
\sup A = \max A.
$$

Similarly, whenever $\min A$ exists,

$$
\inf A = \min A.
$$

**Exercise:** Prove both statements.

### Example 5.14

We revisit the sets considered in Example 5.5.

**1. Let**

$$
A = [0,2).
$$

The set has no maximum, but its supremum is

$$
\sup A = 2.
$$

Since $2 \notin A$, the supremum does not belong to the set. Meanwhile,

$$
\min A = \inf A = 0.
$$

**2. Let**

$$
A = [3,8].
$$

Then

$$
\max A = \sup A = 8,
$$

and

$$
\min A = \inf A = 3.
$$

Both the supremum and infimum belong to $A$.

**3. Let**

$$
A = (-\infty,7].
$$

The maximum and supremum coincide:

$$
\max A = \sup A = 7 \in A.
$$

The set has no minimum and is unbounded below, so

$$
\inf A = -\infty.
$$

### Remark 5.15 (Characterization of the Supremum)

Let $A \subseteq \mathbb{R}$ be nonempty and bounded above. A number $S \in \mathbb{R}$ is the supremum of $A$ if and only if:

1. $S$ is an upper bound of $A$:

   $$
   x \leq S \qquad \text{for every } x \in A.
   $$

2. For every $r < S$, there exists $x_r \in A$ such that

   $$
   r < x_r.
   $$

The second condition ensures that no number smaller than $S$ can be an upper bound of $A$.

### Remark 5.16 (Characterization of the Infimum)

Let $A \subseteq \mathbb{R}$ be nonempty and bounded below. A number $I \in \mathbb{R}$ is the infimum of $A$ if and only if:

1. $I$ is a lower bound of $A$:

   $$
   x \geq I \qquad \text{for every } x \in A.
   $$

2. For every $t > I$, there exists $x_t \in A$ such that

   $$
   x_t < t.
   $$

The second condition ensures that no number larger than $I$ can be a lower bound of $A$.




| Set $A$ | $\min A$ | $\max A$ | $\inf A$ | $\sup A$ |
|---|---:|---:|---:|---:|
| $(0,1)$ | Does not exist | Does not exist | $0$ | $1$ |
| $[0,1)$ | $0$ | Does not exist | $0$ | $1$ |
| $[0,1]$ | $0$ | $1$ | $0$ | $1$ |



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
