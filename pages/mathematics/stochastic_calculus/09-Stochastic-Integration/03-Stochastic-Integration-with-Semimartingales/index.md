---
layout: default
title: "9.3: Stochastic Integration with Semimartingales"
permalink: /pages/mathematics/stochastic_calculus/09-stochastic-integration/03-stochastic-integration-with-semimartingales/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/03-stochastic-integration-with-semimartingales/' | relative_url }}">← Stochastic Integration with Semimartingales</a>
  <div class="eyebrow">Mathematics / Stochastic Calculus / 9.3</div>
  <h1>Stochastic Integration with Semimartingales</h1>
  <p class="lead">Placeholder topic for Stochastic Integration with Semimartingales. (TBD)</p>
</div>

<article class="article" markdown="1">

# 9.3. Stochastic Integration with Semimartingales

> **The correct class of stochastic integrators.** A continuous semimartingale is the sum of a continuous local martingale and a continuous finite-variation process. We already know how to integrate against both parts. Combining them produces the central object of Itô calculus, together with a chain rule in which quadratic variation contributes an additional second-order term.

This section develops integration with respect to **continuous semimartingales**, introduces **Itô processes**, proves Itô's formula in its main one- and multidimensional forms, and derives the **stochastic product rule** and **integration-by-parts formula**. The focus is on continuous trajectories, as in the handwritten notes; jump semimartingales require additional jump correction terms and are not treated here.

Let $(\Omega,\mathcal F,(\mathcal F_t),\mathbb P)$ be a filtered probability space satisfying the usual conditions. Unless stated otherwise, $M,N$ are continuous local martingales and $A,C$ are continuous adapted processes of locally finite variation.

---

## 9.3.1. Continuous semimartingales and their decomposition

**Definition 9.3.1 (Continuous semimartingale).** A continuous adapted process $X$ is a (continuous) semimartingale if it has a decomposition

$$
\boxed{X_t=X_0+M_t+A_t,\qquad t\ge0,}
$$

where $M_0=A_0=0$, $M$ is a continuous local martingale and $A$ is a continuous adapted finite-variation process.

The process $M$ represents the **local martingale fluctuations** and $A$ the **finite-variation component** (or drift in common diffusion models).

**Proposition 9.3.2 (Uniqueness of the decomposition).** If

$$
X=X_0+M+A=X_0+\widetilde M+\widetilde A,
$$

with both martingale parts starting at zero, then $M=\widetilde M$ and $A=\widetilde A$ up to indistinguishability.

**Proof.** Rearranging gives

$$
M-\widetilde M=\widetilde A-A.
$$

The left side is a continuous local martingale, and the right side is of finite variation. A continuous local martingale of finite variation starting at zero must be identically zero. $\square$

**Examples 9.3.3.**

1. Every continuous finite-variation adapted process is a semimartingale, with $M=0$.
2. Every continuous local martingale is a semimartingale, with $A=0$.
3. Brownian motion with drift, $X_t=x_0+\mu t+\sigma W_t$, has $M_t=\sigma W_t$ and $A_t=\mu t$.
4. An Itô process of the form $X_t=X_0+\int_0^ta_sds+\int_0^tb_sdW_s$ is a continuous semimartingale whenever its integrals are well defined.

---

## 9.3.2. The stochastic integral against a semimartingale

**Definition 9.3.4 (Admissible integrands).** Let $X=X_0+M+A$ be a continuous semimartingale. A predictable process $H$ is locally integrable against $X$ if, almost surely for every finite $t$,

$$
\int_0^tH_s^2\,d\langle M\rangle_s<\infty,
\qquad
\int_0^t|H_s|\,|dA_s|<\infty.
$$

In particular, locally bounded predictable processes satisfy both requirements on finite horizons.

**Definition 9.3.5 (Stochastic integral with respect to $X$).** For such $H$ set

$$
\boxed{(H\cdot X)_t
:=\int_0^tH_s\,dX_s
=\int_0^tH_s\,dM_s+\int_0^tH_s\,dA_s.}
$$

The first term is an Itô integral with respect to a continuous local martingale; the second is a pathwise Lebesgue–Stieltjes integral. Their sum is again a continuous semimartingale.

**Proposition 9.3.6 (Linearity, stopping and associativity).** Subject to the relevant local integrability conditions,

$$
\begin{aligned}
(aH+bK)\cdot X&=a(H\cdot X)+b(K\cdot X),\\
H\cdot(aX+bY)&=a(H\cdot X)+b(H\cdot Y),\\
(H\cdot X)^\tau&=H\cdot X^\tau
=(H\mathbf1_{(0,\tau]})\cdot X,\\
K\cdot(H\cdot X)&=(KH)\cdot X.
\end{aligned}
$$

**Proof.** Apply the corresponding stochastic-integral identities to the martingale part and the classical Stieltjes-integral identities to the finite-variation part. Add the results. $\square$

**Proposition 9.3.7 (Quadratic variation and covariation).** If

$$
X=X_0+M+A,
\qquad
Y=Y_0+N+C,
$$

then

$$
\boxed{[X,Y]_t=\langle M,N\rangle_t.}
$$

For any admissible $H,K$,

$$
\boxed{[H\cdot X,K\cdot Y]_t
=\int_0^tH_sK_s\,d[X,Y]_s.}
$$

In particular, $[H\cdot X]_t=\int_0^tH_s^2d[X]_s$. The finite-variation components contribute no continuous quadratic variation or cross-variation.

**Remark 9.3.8 (Consistency under equivalent measures).** If $\mathbb Q$ and $\mathbb P$ are equivalent probability measures, continuous semimartingale integrals of the same predictable integrand against the same integrator agree up to indistinguishability whenever they are defined. The *martingale–finite-variation decomposition* can change under the new measure, but the resulting semimartingale integral does not.

---

## 9.3.3. Stochastic dominated convergence

**Theorem 9.3.9 (Dominated convergence on compact intervals).** Let $X$ be a continuous semimartingale and let $H^{(m)}$ be predictable processes such that, outside one null set, $H_s^{(m)}\to0$ for every $s\ge0$, with

$$
|H_s^{(m)}|\le K_s
$$

for all $m$ outside one null set and for a locally bounded predictable $K$. Then for each $T<\infty$,

$$
\boxed{\sup_{0\le t\le T}
\left|\int_0^tH_s^{(m)}\,dX_s\right|
\xrightarrow[m\to\infty]{\mathbb P}0.}
$$

**Proof.** Write $X=X_0+M+A$. For the finite-variation part,

$$
\sup_{t\le T}\left|\int_0^tH_s^{(m)}\,dA_s\right|
\le\int_0^T|H_s^{(m)}|\,|dA_s|\longrightarrow0
$$

almost surely by pathwise dominated convergence. For the local martingale part, choose stopping times $\tau_r\uparrow\infty$ such that $M^{\tau_r}$ and the stopped envelope $K$ satisfy the square-integrability requirements. The isometry then gives

$$
\mathbb E\left[\left|\int_0^{T\wedge\tau_r}H_s^{(m)}\,dM_s\right|^2\right]
=\mathbb E\int_0^{T\wedge\tau_r}(H_s^{(m)})^2\,d\langle M\rangle_s\to0.
$$

Doob's inequality upgrades this to convergence of the stopped supremum. Finally $\mathbb P(\tau_r<T)\to0$ as $r\to\infty$, proving convergence in probability of the unstopped supremum. $\square$

This theorem is one reason continuous semimartingales form a natural, stable class of stochastic integrators.

---

## 9.3.4. Itô processes and stochastic differentials

**Definition 9.3.10 (One-dimensional Itô process).** Let $W$ be a Brownian motion, $a$ an adapted process locally integrable in time, and $b$ a progressively measurable process satisfying $\int_0^tb_s^2ds<\infty$ almost surely for every finite $t$. The process

$$
\boxed{X_t=X_0+\int_0^ta_s\,ds+\int_0^tb_s\,dW_s}
$$

is called an **Itô process**. Its differential notation is

$$
\boxed{dX_t=a_t\,dt+b_t\,dW_t.}
$$

Here $\int_0^t a_sds$ is of finite variation, while $\int_0^tb_sdW_s$ is a continuous local martingale. Thus $X$ is a continuous semimartingale.

**Theorem 9.3.11 (Quadratic variation of an Itô process).** If $X$ has the representation above, then

$$
\boxed{[X]_t=\int_0^tb_s^2\,ds.}
$$

**Proof.** Write $X=X_0+A+I$ with $A_t=\int_0^ta_sds$ and $I_t=\int_0^tb_sdW_s$. Since $A$ is continuous finite variation, $[A]=[A,I]=0$. The bracket of the Brownian stochastic integral is

$$
[I]_t=\int_0^tb_s^2ds.
$$

Consequently $[X]=[I]$. $\square$

**Definition 9.3.12 (Integration against an Itô process).** If $H$ is an admissible integrand and $dX_t=a_tdt+b_tdW_t$, then

$$
\boxed{\int_0^tH_s\,dX_s
=\int_0^tH_sa_s\,ds+
\int_0^tH_sb_s\,dW_s.}
$$

This identity is the rigorous interpretation of multiplying the formal differential $dX_t$ by $H_t$ and integrating in time.

---

## 9.3.5. Itô's formula for a function of Brownian motion

**Theorem 9.3.13 (One-dimensional Itô formula, Brownian version).** If $f\in C^2(\mathbb R)$, then

$$
\boxed{f(W_t)=f(W_0)
+\int_0^tf'(W_s)\,dW_s
+\frac12\int_0^tf''(W_s)\,ds.}
$$

In stochastic differential notation,

$$
\boxed{df(W_t)=f'(W_t)\,dW_t
+\frac12f''(W_t)\,dt.}
$$

The stochastic integrals are interpreted locally if $f'$ or $f''$ is unbounded.

**Proof (Taylor expansion and quadratic variation).** Let $\pi=\{0=t_0<\cdots<t_n=t\}$ and denote $D_k=W_{t_{k+1}}-W_{t_k}$. Taylor's theorem gives, for each $k$,

$$
f(W_{t_{k+1}})-f(W_{t_k})
=f'(W_{t_k})D_k
+\frac12f''(W_{t_k})D_k^2+R_k,
$$

where $R_k=o(D_k^2)$ uniformly as $\max_k|D_k|\to0$ on each sample path when $f''$ is uniformly continuous on the compact range of that path. Sum over $k$:

$$
f(W_t)-f(W_0)
=\sum_kf'(W_{t_k})D_k
+\frac12\sum_kf''(W_{t_k})D_k^2
+\sum_kR_k.
$$

The first sum converges to $\int_0^tf'(W_s)dW_s$, after localisation on the event that $\sup_{s\le t}|W_s|$ is bounded. The second converges in probability to $\int_0^tf''(W_s)ds$, since Brownian quadratic-variation sums converge to $t$ and weighted sums have the corresponding limit. Finally,

$$
\left|\sum_kR_k\right|
\le\max_k\left|\frac{R_k}{D_k^2}\right|\sum_kD_k^2
\xrightarrow{\mathbb P}0,
$$

where the ratio is interpreted as zero when $D_k=0$. This proves the formula. $\square$

**Example 9.3.14 (Square of Brownian motion).** With $f(x)=x^2$,

$$
d(W_t^2)=2W_t\,dW_t+dt,
$$

and so

$$
\boxed{\int_0^tW_s\,dW_s=\frac12(W_t^2-t).}
$$

The appearance of $dt$ is exactly the nonzero quadratic variation $d[W]_t=dt$.

---

## 9.3.6. Time-dependent Itô formula for Brownian motion

**Theorem 9.3.15 (Time-dependent Brownian Itô formula).** For $f\in C^{1,2}([0,T]\times\mathbb R)$,

$$
\boxed{\begin{aligned}
f(t,W_t)=f(0,W_0)
&+\int_0^tf_t(s,W_s)\,ds\\
&+\int_0^tf_x(s,W_s)\,dW_s\\
&+\frac12\int_0^tf_{xx}(s,W_s)\,ds.
\end{aligned}}
$$

Equivalently,

$$
df(t,W_t)
=\left(f_t+\frac12f_{xx}\right)(t,W_t)\,dt
+f_x(t,W_t)\,dW_t.
$$

**Proof outline.** Expand $f(t_{k+1},W_{t_{k+1}})-f(t_k,W_{t_k})$ in both variables. The first-order time increments produce $\int f_tds$, first-order Brownian increments produce $\int f_xdW$, and squared Brownian increments produce $\tfrac12\int f_{xx}ds$. Mixed terms $\Delta t\Delta W$ and the terms of order $(\Delta t)^2$ vanish; localisation handles unbounded derivatives. $\square$

---

## 9.3.7. Itô formula for a general one-dimensional Itô process

**Theorem 9.3.16 (One-dimensional Itô formula).** Let

$$
dX_t=a_t\,dt+b_t\,dW_t,
$$

and let $f\in C^{1,2}([0,T]\times\mathbb R)$. Then

$$
\boxed{\begin{aligned}
f(t,X_t)=f(0,X_0)
&+\int_0^tf_t(s,X_s)\,ds\\
&+\int_0^tf_x(s,X_s)a_s\,ds\\
&+\int_0^tf_x(s,X_s)b_s\,dW_s\\
&+\frac12\int_0^tf_{xx}(s,X_s)b_s^2\,ds.
\end{aligned}}
$$

In differential form,

$$
\boxed{df(t,X_t)
=\left(f_t+a_tf_x+\frac12b_t^2f_{xx}\right)(t,X_t)\,dt
+b_tf_x(t,X_t)\,dW_t.}
$$

Equivalently, directly in terms of the quadratic variation of $X$,

$$
\boxed{df(t,X_t)
=f_t(t,X_t)\,dt+f_x(t,X_t)\,dX_t
+\frac12f_{xx}(t,X_t)\,d[X]_t.}
$$

**Proof (partition method).** Apply Taylor expansion along a partition:

$$
\begin{aligned}
f(t_{k+1},X_{t_{k+1}})-f(t_k,X_{t_k})
={}&f_t(t_k,X_{t_k})\Delta_kt\\
&+f_x(t_k,X_{t_k})\Delta_kX\\
&+\frac12f_{xx}(t_k,X_{t_k})(\Delta_kX)^2+r_k.
\end{aligned}
$$

Summing and letting the mesh vanish, the time sum converges to $\int f_tds$ and the linear increments converge to $\int f_xdX$ by the definition and continuity properties of stochastic integration. Since $[X]_t=\int_0^tb_s^2ds$, the squared-increment sum converges to $\int f_{xx}\,d[X]$. All mixed time-space terms and higher-order remainders vanish after localisation. Substituting the decomposition $dX=a\,dt+b\,dW$ completes the proof. $\square$

**Corollary 9.3.17 (Time-independent function).** If $f\in C^2(\mathbb R)$,

$$
\boxed{df(X_t)
=f'(X_t)\,dX_t+\frac12f''(X_t)\,d[X]_t.}
$$

In particular,

$$
d(X_t^2)=2X_t\,dX_t+d[X]_t.
$$

---

## 9.3.8. Geometric Brownian motion and logarithms

**Example 9.3.18 (The exponential solution).** Consider the stochastic differential equation

$$
dS_t=\mu S_t\,dt+\sigma S_t\,dW_t,
\qquad S_0>0,
$$

where $\mu\in\mathbb R$ and $\sigma>0$ are constants. Define

$$
S_t=S_0\exp\left(\left(\mu-\frac12\sigma^2\right)t+\sigma W_t\right).
$$

Applying Itô's formula to $f(t,x)=S_0e^{(\mu-\sigma^2/2)t+\sigma x}$, we have

$$
\begin{aligned}
f_t&=\left(\mu-\tfrac12\sigma^2\right)f,
&f_x&=\sigma f,
&f_{xx}&=\sigma^2f,
\end{aligned}
$$

so that

$$
\begin{aligned}
dS_t
&=\left(\mu-\tfrac12\sigma^2\right)S_tdt
+\sigma S_tdW_t
+\tfrac12\sigma^2S_tdt\\
&=\mu S_tdt+\sigma S_tdW_t.
\end{aligned}
$$

Conversely, applying $f(x)=\log x$ for $S_t>0$ yields

$$
\begin{aligned}
d(\log S_t)
&=\frac{1}{S_t}dS_t
-\frac{1}{2S_t^2}d[S]_t\\
&=\left(\mu-\frac12\sigma^2\right)dt+\sigma dW_t.
\end{aligned}
$$

Therefore,

$$
\boxed{S_t=S_0\exp\left(\left(\mu-\frac12\sigma^2\right)t+\sigma W_t\right).}
$$

The drift correction $-\sigma^2/2$ is a direct consequence of Itô's second derivative term.

**Example 9.3.19 (Quadratic variation of geometric Brownian motion).** From $dS_t=\mu S_tdt+\sigma S_tdW_t$,

$$
\boxed{[S]_t=\int_0^t\sigma^2S_s^2\,ds.}
$$

Thus the quadratic variation of the **price** is random, whereas the quadratic variation of its **logarithm** is deterministic:

$$
[\log S]_t=\sigma^2t.
$$

---

## 9.3.9. Several Brownian motions and vector Itô processes

Let $W=(W^1,\ldots,W^d)$ be a standard $d$-dimensional Brownian motion with independent components. The cross-variation rules are

$$
\boxed{[W^k,W^\ell]_t=\delta_{k\ell}t,
\qquad dW_t^k\,dW_t^\ell=\delta_{k\ell}dt.}
$$

**Definition 9.3.20 ($m$-dimensional Itô process).** An $\mathbb R^m$-valued process $X$ is an Itô process driven by $W$ if

$$
\boxed{dX_t=a_t\,dt+B_t\,dW_t,}
$$

where $a_t\in\mathbb R^m$ and $B_t\in\mathbb R^{m\times d}$, or componentwise,

$$
dX_t^k=a_t^k\,dt+\sum_{\ell=1}^dB_t^{k\ell}\,dW_t^\ell,
\qquad k=1,\ldots,m.
$$

**Proposition 9.3.21 (Covariation matrix).** The continuous cross-variations satisfy

$$
\boxed{d[X^k,X^r]_t
=\sum_{\ell=1}^dB_t^{k\ell}B_t^{r\ell}\,dt
=(B_tB_t^{\mathsf T})_{kr}\,dt.}
$$

**Proof.** Terms involving finite-variation drift have zero covariation. By bilinearity and the independence of the Brownian components,

$$
\begin{aligned}
d[X^k,X^r]_t
&=\sum_{\ell=1}^d\sum_{j=1}^d
B_t^{k\ell}B_t^{rj}\,d[W^\ell,W^j]_t\\
&=\sum_{\ell=1}^dB_t^{k\ell}B_t^{r\ell}\,dt.
\end{aligned}
$$

$\square$

---

## 9.3.10. Multidimensional Itô formula

**Theorem 9.3.22 (Multidimensional Itô formula).** Let $X=(X^1,\ldots,X^m)$ be a continuous vector Itô process and let $f\in C^{1,2}([0,T]\times\mathbb R^m)$. Then

$$
\boxed{\begin{aligned}
df(t,X_t)
={}&f_t(t,X_t)\,dt
+\sum_{k=1}^mf_{x_k}(t,X_t)\,dX_t^k\\
&+\frac12\sum_{k=1}^m\sum_{r=1}^m
f_{x_kx_r}(t,X_t)\,d[X^k,X^r]_t.
\end{aligned}}
$$

Substituting $dX=a\,dt+B\,dW$ gives

$$
\boxed{\begin{aligned}
df(t,X_t)
={}&\left[f_t+\sum_{k=1}^ma_t^kf_{x_k}
+\frac12\sum_{k=1}^m\sum_{r=1}^m
(B_tB_t^{\mathsf T})_{kr}f_{x_kx_r}\right](t,X_t)\,dt\\
&+\sum_{\ell=1}^d\left(\sum_{k=1}^m
f_{x_k}(t,X_t)B_t^{k\ell}\right)dW_t^\ell.
\end{aligned}}
$$

In vector notation, with $D^2f$ the Hessian,

$$
\boxed{df(t,X_t)
=\left(f_t+\nabla f^{\mathsf T}a_t
+\tfrac12\operatorname{tr}(B_tB_t^{\mathsf T}D^2f)\right)dt
+\nabla f^{\mathsf T}B_t\,dW_t.}
$$

All derivatives of $f$ above are evaluated at $(t,X_t)$.

**Proof (multivariate Taylor expansion).** Over each partition interval, expand $f(t_{k+1},X_{t_{k+1}})-f(t_k,X_{t_k})$ to second order:

$$
\begin{aligned}
\Delta_kf
={}&f_t(t_k,X_{t_k})\Delta_kt
+\sum_r f_{x_r}(t_k,X_{t_k})\Delta_kX^r\\
&+\frac12\sum_{r,q}f_{x_rx_q}(t_k,X_{t_k})
\Delta_kX^r\Delta_kX^q+R_k.
\end{aligned}
$$

Summing and taking the mesh to zero, the first two sums converge to the time and stochastic-integral terms, while the quadratic sums converge to the covariations $[X^r,X^q]$. Uniform continuity after stopping on compact ranges ensures the total remainder vanishes in probability. This proves the formula. $\square$

**Remark 9.3.23 (Correlated Brownian drivers).** If the driving Brownian vector has instantaneous covariance matrix $R=(\rho_{\ell j})$, meaning $d[W^\ell,W^j]_t=\rho_{\ell j}dt$, replace $BB^{\mathsf T}$ by $BRB^{\mathsf T}$ in the second-order term.

---

## 9.3.11. Product rule and integration by parts

**Theorem 9.3.24 (Itô product rule).** Let $X,Y$ be continuous semimartingales. Then

$$
\boxed{d(X_tY_t)
=X_t\,dY_t+Y_t\,dX_t+d[X,Y]_t.}
$$

Equivalently,

$$
\boxed{X_tY_t
=X_0Y_0+\int_0^tX_s\,dY_s
+\int_0^tY_s\,dX_s+[X,Y]_t.}
$$

**Proof.** Apply the two-dimensional Itô formula to $f(x,y)=xy$. We have

$$
f_x=y,\qquad f_y=x,
\qquad f_{xx}=f_{yy}=0,
\qquad f_{xy}=f_{yx}=1.
$$

Hence the second-order contribution is

$$
\frac12\bigl(f_{xy}\,d[X,Y]_t+f_{yx}\,d[Y,X]_t\bigr)
=d[X,Y]_t,
$$

which gives the stated formula. $\square$

**Corollary 9.3.25 (Stochastic integration by parts).** Rearranging,

$$
\boxed{\int_0^tX_s\,dY_s
=X_tY_t-X_0Y_0
-\int_0^tY_s\,dX_s-[X,Y]_t.}
$$

The additional cross-variation term is the exact correction to the classical finite-variation product rule.

**Proposition 9.3.26 (Product of two Itô processes).** Suppose two Itô processes share one Brownian driver:

$$
dX_t=a_tdt+b_tdW_t,
\qquad dY_t=c_tdt+d_tdW_t.
$$

Then

$$
\boxed{\begin{aligned}
d(X_tY_t)
={}&\bigl(X_tc_t+Y_ta_t+b_td_t\bigr)dt\\
&+\bigl(X_td_t+Y_tb_t\bigr)dW_t.
\end{aligned}}
$$

The term $b_td_tdt$ comes from $d[X,Y]_t=b_td_tdt$.

**Corollary 9.3.27 (Classical rule as a special case).** If $Y$ is continuous and of finite variation, then $[X,Y]=0$, so

$$
X_tY_t-X_0Y_0
=\int_0^tX_s\,dY_s+\int_0^tY_s\,dX_s.
$$

In particular, for deterministic $g\in C^1$,

$$
\boxed{d(g(t)X_t)=g'(t)X_tdt+g(t)\,dX_t.}
$$

This identity is useful in integrating-factor calculations for linear stochastic differential equations.

---

## 9.3.12. Itô formula with a finite-variation argument

**Theorem 9.3.28 (Two-variable Itô formula with finite variation).** Suppose $X$ is a continuous semimartingale, $A$ is a continuous finite-variation process, and $f\in C^2(\mathbb R^2)$. Then

$$
\boxed{\begin{aligned}
f(X_t,A_t)=f(X_0,A_0)
&+\int_0^tf_x(X_s,A_s)\,dX_s\\
&+\int_0^tf_y(X_s,A_s)\,dA_s\\
&+\frac12\int_0^tf_{xx}(X_s,A_s)\,d[X]_s.
\end{aligned}}
$$

**Proof.** The two-dimensional Itô formula would normally contain terms in $d[A]$ and $d[X,A]$. Both vanish because $A$ is continuous and of finite variation. The remaining terms are exactly those displayed. $\square$

**Example 9.3.29 (Running maximum of Brownian motion).** Define

$$
R_t:=\sup_{0\le s\le t}W_s.
$$

The process $R$ is continuous, adapted and nondecreasing. Hence it has finite variation on every compact interval and satisfies

$$
[R]_t=0,
\qquad [W,R]_t=0.
$$

Although $R$ is not generally differentiable with respect to time, its integral $\int_0^tH_s\,dR_s$ is a well-defined pathwise Stieltjes integral for suitable $H$.

**Remark 9.3.30 (Beyond $C^2$).** The formulas above are formulated for sufficiently smooth functions. For nonsmooth convex functions one needs extensions involving **local time**, of which Tanaka's formula is a central example. Those results belong to a more advanced development and are not needed for the continuous $C^2$ calculus established here.

---

## 9.3.13. Stochastic exponentials

**Proposition 9.3.31 (Continuous stochastic exponential).** For a continuous local martingale $M$ with $M_0=0$, the process

$$
\boxed{\mathcal E(M)_t
:=\exp\left(M_t-\frac12\langle M\rangle_t\right)}
$$

satisfies

$$
\boxed{d\mathcal E(M)_t=\mathcal E(M)_t\,dM_t,
\qquad\mathcal E(M)_0=1.}
$$

**Proof.** Apply Itô's formula to $f(x,a)=e^{x-a/2}$ with $x=M_t$ and $a=\langle M\rangle_t$. The finite-variation differential contributes $-\tfrac12\mathcal E(M)_td\langle M\rangle_t$, and the second derivative contributes $+\tfrac12\mathcal E(M)_td\langle M\rangle_t$. They cancel, leaving $d\mathcal E(M)=\mathcal E(M)dM$. $\square$

Stochastic exponentials are central to stochastic differential equations and changes of probability measure. A positive local martingale need not be a true martingale; additional assumptions are needed when a stochastic exponential is used as a probability-density process.

---

## 9.3.14. Summary of the main formulas

For continuous semimartingales $X,Y$ and a smooth function $f$, the central results are

$$
\boxed{\begin{aligned}
\int_0^tH_s\,dX_s
&=\int_0^tH_s\,dM_s+\int_0^tH_s\,dA_s,
&&X=X_0+M+A,\\[4pt]
[X,Y]_t&=\langle M,N\rangle_t,
&&Y=Y_0+N+C,\\[4pt]
df(t,X_t)
&=f_t\,dt+f_x\,dX_t+\tfrac12f_{xx}\,d[X]_t,\\[4pt]
d(X_tY_t)
&=X_t\,dY_t+Y_t\,dX_t+d[X,Y]_t.
\end{aligned}}
$$

For a vector Itô process $dX_t=a_tdt+B_tdW_t$,

$$
\boxed{df(t,X_t)
=\left(f_t+\nabla f^{\mathsf T}a_t
+\frac12\operatorname{tr}(B_tB_t^{\mathsf T}D^2f)\right)dt
+\nabla f^{\mathsf T}B_t\,dW_t.}
$$

The essential lesson is that classical first-order calculus survives **with a second-order correction dictated by quadratic covariation**. This gives a unified framework for stochastic integrals, stochastic differential equations, and applications such as geometric Brownian motion.


- [Exercises]({{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/03-stochastic-integration-with-semimartingales/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/03-stochastic-integration-with-semimartingales/solutions/' | relative_url }})
- [References and further reading]({{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/03-stochastic-integration-with-semimartingales/references/' | relative_url }})

[Back to Stochastic Integration]({{ '/pages/mathematics/stochastic_calculus/09-stochastic-integration/' | relative_url }})

</article>
