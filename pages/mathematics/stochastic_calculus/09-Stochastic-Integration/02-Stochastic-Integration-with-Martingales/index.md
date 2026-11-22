---
layout: default
title: "9.2: Stochastic Integration with Martingales"
permalink: /pages/mathematics/stochastic_calculus/09-stochastic-integration/02-stochastic-integration-with-martingales/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/02-stochastic-integration-with-martingales/' | relative_url }}">← Stochastic Integration with Martingales</a>
  <div class="eyebrow">Mathematics / Stochastic Calculus / 9.2</div>
  <h1>Stochastic Integration with Martingales</h1>
  <p class="lead">Placeholder topic for Stochastic Integration with Martingales. (TBD)</p>
</div>

<article class="article" markdown="1">


# 9.2. Stochastic Integration with Martingales

> **The bracket replaces ordinary time.** The Itô isometry for Brownian motion involves $ds$ because $[W]_t=t$. For a general continuous martingale $M$, the corresponding measure of stochastic variation is $d\langle M\rangle_s$.

Having built the stochastic integral against Brownian motion, we now extend it to arbitrary **continuous square-integrable martingales** and then, by localisation, to **continuous local martingales**. Two viewpoints will emerge: constructing integrals by completion of elementary processes and characterising them intrinsically through quadratic covariation.

Work on a filtered probability space satisfying the usual conditions. Continuous local martingales are assumed to start at zero when we consider their stochastic integrals; a general initial value can simply be subtracted.

---

## 9.2.1. Continuous martingales and their brackets

**Definition 9.2.1 (Square-integrable martingale space).** Let $\mathcal H_0^2$ be the space of continuous martingales $M$ such that $M_0=0$ and

$$
\sup_{t\ge0}\mathbb E[M_t^2]<\infty.
$$

Each such martingale converges in $L^2$ to $M_\infty$, and we define

$$
\|M\|_{\mathcal H_0^2}^2
:=\mathbb E[M_\infty^2]
=\mathbb E[\langle M\rangle_\infty].
$$

On a fixed horizon $[0,T]$, the corresponding theory uses square-integrable martingales on $[0,T]$ and terminal value $M_T$ instead of $M_\infty$.

**Theorem 9.2.2 (Martingale-square characterisation).** If $M$ is a continuous local martingale, there is a unique continuous adapted increasing process $\langle M\rangle$ with $\langle M\rangle_0=0$ and

$$
\boxed{M_t^2-\langle M\rangle_t\text{ is a continuous local martingale}.}
$$

For $M\in\mathcal H_0^2$, localisation and uniform integrability imply

$$
\mathbb E[M_t^2]=\mathbb E[\langle M\rangle_t],
\quad
\mathbb E[M_\infty^2]=\mathbb E[\langle M\rangle_\infty].
$$

**Definition 9.2.3 (Cross-bracket).** For continuous local martingales $M,N$ define

$$
\langle M,N\rangle_t
:=\frac12\left(\langle M+N\rangle_t
-\langle M\rangle_t-\langle N\rangle_t\right).
$$

Then $MN-\langle M,N\rangle$ is a continuous local martingale, and

$$
\langle M,N\rangle_t
=\lim_{\|\pi\|\to0}^{\mathbb P}
\sum_k(M_{t_{k+1}}-M_{t_k})(N_{t_{k+1}}-N_{t_k}).
$$

These facts were developed in [§8.2](../../08-quadratic-variation-and-semimartingales/02-quadratic-variation-and-covariation/).

---

## 9.2.2. The integral of an elementary process against a martingale

**Definition 9.2.4 (Elementary predictable integrand).** Fix deterministic times $0=t_0<t_1<\cdots<t_n$ and bounded random variables $\xi_k\in\mathcal F_{t_k}$. An elementary predictable process is

$$
H_s=\sum_{k=0}^{n-1}\xi_k\mathbf1_{(t_k,t_{k+1}]}(s).
$$

**Definition 9.2.5 (Elementary martingale integral).** For $M\in\mathcal H_0^2$ define

$$
\boxed{(H\cdot M)_t
=\int_0^tH_s\,dM_s
:=\sum_{k=0}^{n-1}\xi_k
\bigl(M_{t\wedge t_{k+1}}-M_{t\wedge t_k}\bigr).}
$$

Each term is a continuous square-integrable martingale, hence so is their finite sum.

**Proposition 9.2.6 (The bracket of an elementary integral).** For the elementary process above,

$$
\boxed{\langle H\cdot M\rangle_t
=\int_0^tH_s^2\,d\langle M\rangle_s.}
$$

More generally, for elementary predictable $H,K$ and continuous local martingales $M,N$,

$$
\boxed{\langle H\cdot M,K\cdot N\rangle_t
=\int_0^tH_sK_s\,d\langle M,N\rangle_s.}
$$

**Proof.** Begin with $H_s=\xi\mathbf1_{(u,v]}(s)$ for bounded $\xi\in\mathcal F_u$. The bracket of the stopped martingale increment $M_{t\wedge v}-M_{t\wedge u}$ is $\langle M\rangle_{t\wedge v}-\langle M\rangle_{t\wedge u}$. Multiplying by the fixed $\mathcal F_u$-measurable coefficient $\xi$ multiplies the bracket by $\xi^2$. Contributions from disjoint time intervals have zero mutual bracket, so add the pieces to obtain

$$
\langle H\cdot M\rangle_t
=\sum_k\xi_k^2
\bigl(\langle M\rangle_{t\wedge t_{k+1}}-
\langle M\rangle_{t\wedge t_k}\bigr).
$$

This is exactly the stated Stieltjes integral. The cross-bracket identity follows by the same argument and polarisation. $\square$

---

## 9.2.3. Itô isometry with a martingale integrator

**Theorem 9.2.7 (General Itô isometry for elementary processes).** Let $M\in\mathcal H_0^2$ and let $H$ be bounded elementary predictable. Then

$$
\boxed{\mathbb E\left[\left(\int_0^tH_s\,dM_s\right)^2\right]
=\mathbb E\left[\int_0^tH_s^2\,d\langle M\rangle_s\right].}
$$

**Proof.** The integral $I=H\cdot M$ is a square-integrable martingale, starting at zero. The bracket-square identity implies $I^2-\langle I\rangle$ is a martingale after the relevant integrability justification. Consequently

$$
\mathbb E[I_t^2]=\mathbb E[\langle I\rangle_t]
=\mathbb E\left[\int_0^tH_s^2\,d\langle M\rangle_s\right].
$$

$\square$

For $M=W$, we have $d\langle W\rangle_s=ds$, recovering the Brownian isometry from [§9.1](../01-construction-of-the-ito-integral/).

**Corollary 9.2.8 (Cross-isometry).** If $M,N\in\mathcal H_0^2$ and $H,K$ are bounded elementary predictable processes, then

$$
\mathbb E\left[(H\cdot M)_t(K\cdot N)_t\right]
=\mathbb E\left[\int_0^tH_sK_s\,d\langle M,N\rangle_s\right].
$$

---

## 9.2.4. The integrand space $L^2(M)$

**Definition 9.2.9 (Square-integrability relative to a martingale).** For $M\in\mathcal H_0^2$ define

$$
\boxed{L^2(M):=\left\{H\text{ predictable}:
\mathbb E\int_0^\infty H_s^2\,d\langle M\rangle_s<\infty\right\},}
$$

with the standard identification of processes that agree $d\langle M\rangle_s\,d\mathbb P$-almost everywhere. Its norm and inner product are

$$
\begin{aligned}
\|H\|_{L^2(M)}^2
&=\mathbb E\int_0^\infty H_s^2\,d\langle M\rangle_s,\\
(H,K)_{L^2(M)}
&=\mathbb E\int_0^\infty H_sK_s\,d\langle M\rangle_s.
\end{aligned}
$$

Strictly, $d\langle M\rangle_s\,d\mathbb P$ denotes the measure on predictable sets defined by $\mu_M(B)=\mathbb E\int_0^\infty\mathbf1_B(s,\omega)\,d\langle M\rangle_s(\omega)$.

**Theorem 9.2.10 (Density of elementary integrands).** Bounded elementary predictable processes are dense in $L^2(M)$.

**Proof (Hilbert-space argument).** Let $\mathcal E$ denote their span. Suppose $H\in L^2(M)$ is orthogonal to every element of $\mathcal E$. Consider the continuous finite-variation process

$$
A_t:=\int_0^tH_s\,d\langle M\rangle_s.
$$

For $0\le u<v$ and bounded $\mathcal F_u$-measurable $\xi$, orthogonality to $\xi\mathbf1_{(u,v]}$ gives

$$
\mathbb E[\xi(A_v-A_u)]
=\mathbb E\int_u^v\xi H_s\,d\langle M\rangle_s=0.
$$

Thus $A$ is a continuous martingale; it is also of finite variation and starts at zero. Hence $A\equiv0$. The signed Stieltjes measure of $A$ is therefore zero, forcing $H=0$ $d\langle M\rangle\,d\mathbb P$-almost everywhere. Since the orthogonal complement $\mathcal E^\perp$ is trivial, $\mathcal E$ is dense. $\square$

---

## 9.2.5. Construction by completion

**Theorem 9.2.11 (Integral against a square-integrable martingale).** For every $M\in\mathcal H_0^2$ and $H\in L^2(M)$ there is a unique continuous square-integrable martingale $H\cdot M$ starting at zero such that, whenever $H^{(m)}$ is elementary and $H^{(m)}\to H$ in $L^2(M)$,

$$
\boxed{H\cdot M
=\lim_{m\to\infty}H^{(m)}\cdot M
\quad\text{in the }\mathcal H_0^2\text{ norm}.}
$$

It satisfies the isometry

$$
\boxed{\|H\cdot M\|_{\mathcal H_0^2}^2
=\mathbb E\int_0^\infty H_s^2\,d\langle M\rangle_s.}
$$

**Proof.** The elementary isometry gives

$$
\|H^{(m)}\cdot M-H^{(r)}\cdot M\|_{\mathcal H_0^2}^2
=\|H^{(m)}-H^{(r)}\|_{L^2(M)}^2\to0.
$$

Completeness of $\mathcal H_0^2$ produces a unique limit. If two approximating sequences represent the same $H$, their difference has vanishing $L^2(M)$ norm, so the corresponding integrals converge to the same martingale. Taking limits yields the stated isometry. $\square$

**Theorem 9.2.12 (Intrinsic covariation characterisation).** For every continuous square-integrable martingale $N$,

$$
\boxed{\langle H\cdot M,N\rangle_t
=\int_0^tH_s\,d\langle M,N\rangle_s.}
$$

This identity uniquely characterises $H\cdot M$ among continuous square-integrable martingales starting at zero.

**Proof.** The identity holds for elementary $H$ by Proposition 9.2.6. Approximate in $L^2(M)$ and pass to the limit using the bracket Cauchy–Schwarz / Kunita–Watanabe inequality. For uniqueness, if two candidates $I,J$ have the same bracket against every $N$, their difference $D=I-J$ satisfies $\langle D,N\rangle=0$ for all $N$, hence also for $N=D$. Thus $\langle D\rangle=0$, and the martingale-square identity gives $D=0$. $\square$

This intrinsic formulation is especially useful when the integrator is only locally square-integrable.

---

## 9.2.6. Covariation, orthogonality and martingale geometry

**Proposition 9.2.13 (Covariation of martingale integrals).** For $M,N\in\mathcal H_0^2$ and admissible $H,K$,

$$
\boxed{\langle H\cdot M,K\cdot N\rangle_t
=\int_0^tH_sK_s\,d\langle M,N\rangle_s.}
$$

The integrand is well defined locally by Kunita–Watanabe. If $\langle M,N\rangle\equiv0$, then any two such integrals are **strongly orthogonal**:

$$
\langle H\cdot M,K\cdot N\rangle_t=0.
$$

**Corollary 9.2.14 (Vector martingale isometry).** Suppose $M=(M^1,\ldots,M^d)$ is a vector of continuous square-integrable martingales and $H=(H^1,\ldots,H^d)$ is an admissible integrand. With

$$
I_t=\sum_{k=1}^d\int_0^tH_s^k\,dM_s^k,
$$

its bracket is

$$
\boxed{\langle I\rangle_t
=\sum_{k=1}^d\sum_{\ell=1}^d
\int_0^tH_s^kH_s^\ell\,d\langle M^k,M^\ell\rangle_s.}
$$

When the components are independent Brownian motions, the off-diagonal terms vanish and

$$
\langle I\rangle_t=\int_0^t\sum_{k=1}^d(H_s^k)^2\,ds.
$$

---

## 9.2.7. Localisation: integrals against local martingales

**Definition 9.2.15 (Locally square-integrable integrands).** For a continuous local martingale $M$, define

$$
\boxed{L^2_{\mathrm{loc}}(M)
:=\left\{H\text{ predictable}:
\int_0^tH_s^2\,d\langle M\rangle_s<\infty
\text{ a.s. for every }t<\infty\right\}.}
$$

The process need not satisfy $\mathbb E\int_0^tH_s^2\,d\langle M\rangle_s<\infty$. A suitable stopping sequence can enforce integrability on each stopped interval.

**Theorem 9.2.16 (Local martingale stochastic integral).** Let $M$ be a continuous local martingale and $H\in L^2_{\mathrm{loc}}(M)$. There exists a unique continuous local martingale $I=H\cdot M$, with $I_0=0$, such that for every continuous local martingale $N$,

$$
\boxed{\langle I,N\rangle_t
=\int_0^tH_s\,d\langle M,N\rangle_s.}
$$

In particular,

$$
\boxed{\langle H\cdot M\rangle_t
=\int_0^tH_s^2\,d\langle M\rangle_s.}
$$

**Proof (localisation and pasting).** Define, for $n\ge1$,

$$
\tau_n:=\inf\left\{t\ge0:
\int_0^t(1+H_s^2)\,d\langle M\rangle_s\ge n\right\}\wedge n.
$$

Continuity of the accumulated bracket, local finiteness and the $\wedge n$ term imply $\tau_n\uparrow\infty$ almost surely. On each stopped horizon, $\langle M^{\tau_n}\rangle_\infty\le n$ and

$$
\mathbb E\int_0^\infty H_s^2\,d\langle M^{\tau_n}\rangle_s\le n,
$$

so $H\cdot M^{\tau_n}$ exists by the square-integrable theory. If $m\ge n$, stopped-integral consistency gives

$$
(H\cdot M^{\tau_m})^{\tau_n}=H\cdot M^{\tau_n}.
$$

Thus these integrals agree before $\tau_n$ and define one continuous process $I$ by pasting. By construction $I^{\tau_n}$ is a martingale; hence $I$ is a continuous local martingale. The bracket formula follows on each stopped interval and therefore globally. Uniqueness follows from the intrinsic covariation characterisation. $\square$

**Remark 9.2.17 (Local is not necessarily true).** A local martingale need not be a true martingale. The identity

$$
\langle H\cdot M\rangle_t=\int_0^tH_s^2\,d\langle M\rangle_s
$$

does **not** by itself imply $\mathbb E[(H\cdot M)_t^2]<\infty$. A sufficient condition is integrability of the right-hand side, under which the stopped martingales can be promoted to a square-integrable martingale on that horizon.

---

## 9.2.8. Stopping and associativity

**Proposition 9.2.18 (Stopping identities).** Let $\tau$ be a stopping time. For $H\in L^2_{\mathrm{loc}}(M)$,

$$
\boxed{(H\cdot M)^\tau
=H\cdot M^\tau
=(H\mathbf1_{(0,\tau]})\cdot M.}
$$

**Proposition 9.2.19 (Associativity).** If $H\in L^2_{\mathrm{loc}}(M)$ and $K\in L^2_{\mathrm{loc}}(H\cdot M)$, then

$$
\boxed{K\cdot(H\cdot M)=(KH)\cdot M.}
$$

**Proof idea.** Both identities are immediate for elementary predictable processes. The isometry gives stability under $L^2$ approximation; localisation extends them to the local case. Alternatively, the intrinsic covariation formula gives both identities and uniqueness identifies the resulting martingales. $\square$

---

## 9.2.9. Martingale representation in the Brownian filtration

**Theorem 9.2.20 (Brownian martingale representation).** Suppose $(\mathcal F_t)$ is the completed, right-continuous filtration generated by a $d$-dimensional Brownian motion $W=(W^1,\ldots,W^d)$. Every square-integrable $\mathcal F_T$-measurable random variable $\xi$ admits a representation

$$
\boxed{\xi=\mathbb E[\xi]
+\sum_{k=1}^d\int_0^TH_s^k\,dW_s^k,}
$$

for predictable processes $H^1,\ldots,H^d$ with

$$
\mathbb E\int_0^T\sum_{k=1}^d(H_s^k)^2\,ds<\infty.
$$

The representation is unique up to $ds\otimes d\mathbb P$-almost-everywhere equality of the integrands. Equivalently,

$$
\mathbb E[\xi\mid\mathcal F_t]
=\mathbb E[\xi]+\sum_{k=1}^d\int_0^tH_s^k\,dW_s^k.
$$

**Scope of the theorem.** The Brownian filtration is essential. Not every martingale on an arbitrary filtered probability space can be represented as an integral against one chosen driver. Martingale representation in a general filtration requires additional hypotheses.

---

## 9.2.10. Summary

For a continuous local martingale $M$ and an admissible predictable integrand $H$,

$$
\boxed{\begin{gathered}
I=H\cdot M=\int_0^{\cdot}H_s\,dM_s,\\
\langle I\rangle_t=\int_0^tH_s^2\,d\langle M\rangle_s,\\
\langle H\cdot M,N\rangle_t
=\int_0^tH_s\,d\langle M,N\rangle_s.
\end{gathered}}
$$

When square integrability holds, the corresponding **isometry** is

$$
\mathbb E[(H\cdot M)_t^2]
=\mathbb E\int_0^tH_s^2\,d\langle M\rangle_s.
$$

In [§9.3](../03-stochastic-integration-with-semimartingales/) we add a finite-variation component to the martingale integrator and recover a class closed under stochastic integration and smooth transformations: the **continuous semimartingales**.


- [Exercises]({{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/02-stochastic-integration-with-martingales/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/02-stochastic-integration-with-martingales/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/02-stochastic-integration-with-martingales/references/' | relative_url }})

[Back to Stochastic Integration]({{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/' | relative_url }})

</article>
