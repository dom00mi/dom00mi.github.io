---
layout: default
title: "1.1 Optimal Control: Definitions and Examples"
permalink: /pages/mathematics/control_theory/deterministic-controls/01-introduction-to-pde-optimal-control/01-optimal-control-definitions-and-examples/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/control_theory/deterministic-controls/01-introduction-to-pde-optimal-control/' | relative_url }}">Chapter 1</a>
  <div class="eyebrow">Mathematics / Control Theory / Deterministic Control / Chapter 1</div>
  <h1>Optimal Control: Definitions and Examples</h1>
  <p class="lead">From physical models to finite-dimensional optimality systems.</p>
</div>

<article class="article" markdown="1">

> We begin with few definitions for our standard control problems, and give some context for real applications such as heat conduction. We then progress to state several conditions of optimality, which would then lead to KKT. The next step is to then observe controls in a PDE context.

## 1. What is optimal control?

Optimal control asks how to choose an input so that a dynamical system performs as well as possible according to a specified criterion. “Optimal” therefore has meaning only after the objective is stated: one may want the shortest travel time, a small tracking error, little energy consumption, or a compromise between several goals.

The system can be described by ordinary differential equations (ODEs), as in aviation, robotics, and chemical processes, or by partial differential equations (PDEs), as in heat conduction, waves, and fluid flow. The **control** is the quantity we can choose; the **state** is the configuration produced by that choice.

### 1.1 The rocket-car example

Suppose a vehicle moves along a line. At \(t=0\) it is at \(y_0\), with zero velocity. We can prescribe a forward or backward thrust \(u(t)\), but the engine is limited:

$$
-1\leq u(t)\leq1.
$$

Let \(y(t)\) denote the position. Then \(y'(t)\) is velocity and \(y''(t)\) is acceleration. Newton’s law gives

$$
m y''(t)=u(t),\qquad y(0)=y_0,\qquad y'(0)=0.
$$

The vehicle must reach \(y_T\neq y_0\) and stop there:

$$
y(T)=y_T,\qquad y'(T)=0,\qquad |u(t)|\leq1.
$$

The final time \(T>0\) is free and is to be minimized. In this simple example the natural strategy is maximum acceleration up to the midpoint, followed by maximum braking. The point of the model is not the obvious strategy itself, but the structure it exposes:

1. a **cost functional** to minimize, here the travel time \(T\);
2. a **state equation**, here the initial-value problem for \(y\);
3. **constraints**, including the terminal conditions and the thrust bound.

The function \(u\) is the control. A control that gives the smallest admissible cost is an **optimal control**, and the associated trajectory is the **optimal state**.

## 2. Examples of convex control problems

The next models we briefly show have quadratic objectives and linear state equations. They are representative linear-quadratic problems and provide the PDE examples that motivate the finite-dimensional theory.

### 2.1 Stationary boundary heating

Let \(\Omega\subset\mathbb R^3\) be a body with boundary \(\Gamma=\partial\Omega\). A boundary heater has intensity \(u(x)\), independent of time but variable along \(\Gamma\). We want the stationary temperature \(y(x)\) to approximate a prescribed profile \(y_\Omega(x)\), while penalizing the energy used:

$$
\begin{aligned}
\min_{y,u}\quad J(y,u)
&:=\frac12\int_\Omega |y-y_\Omega|^2\,dx
  +\frac{\lambda}{2}\int_\Gamma |u|^2\,ds,\\
\text{subject to}\quad
-\Delta y&=0 &&\text{in }\Omega,\\
\frac{\partial y}{\partial\nu}&=\alpha(u-y) &&\text{on }\Gamma,\\
u_a(x)&\leq u(x)\leq u_b(x) &&\text{on }\Gamma.
\end{aligned}
$$

Here \(\nu\) is the outward unit normal, \(\alpha>0\) is a heat-transfer coefficient, \(\lambda\geq0\) weights the control effort, and \(u_a,u_b\) are prescribed bounds. If the material is heterogeneous, the Laplacian may be replaced by

$$
\operatorname{div}(a(x)\nabla y(x))=0,
$$

with \(a\equiv1\) recovering the Laplace equation. Since the PDE is linear elliptic, the objective is quadratic, and the control acts on \(\Gamma\), this is a **linear-quadratic elliptic boundary-control problem**.

### 2.2 Stationary distributed heating

If the heater acts inside the body, the control is distributed. With zero boundary temperature, a model is

$$
\begin{aligned}
\min_{y,u}\quad J(y,u)
&:=\frac12\int_\Omega |y-y_\Omega|^2\,dx
  +\frac{\lambda}{2}\int_\Omega |u|^2\,dx,\\
\text{subject to}\quad
-\Delta y&=\beta u &&\text{in }\Omega,\\
y&=0 &&\text{on }\Gamma,\\
u_a(x)&\leq u(x)\leq u_b(x) &&\text{in }\Omega.
\end{aligned}
$$

The second integral is over \(\Omega\), because the actuator is distributed. The coefficient \(\beta\) specifies where it acts; for a subdomain \(\Omega'\subset\Omega\), one may take

$$
\beta=\chi_{\Omega'},\qquad
\chi_{\Omega'}(x)=
\begin{cases}
1,&x\in\Omega',\\
0,&x\notin\Omega'.
\end{cases}
$$

This is a **linear-quadratic elliptic distributed-control problem**. Other boundary conditions, such as \(\partial_\nu y=\alpha(y_a-y)\), can be used as well.

### 2.3 Non-stationary boundary heating

Let \(\Omega\) be a potato being heated during \(0\leq t\leq T\). The temperature is \(y(x,t)\), initially \(y_0(x)\). A time-dependent boundary control \(u(x,t)\) should make the final temperature close to \(y_\Omega(x)\):

$$
\begin{aligned}
\min_{y,u}\quad J(y,u)
&:=\frac12\int_\Omega |y(x,T)-y_\Omega(x)|^2\,dx
 +\frac{\lambda}{2}\int_0^T\int_\Gamma |u(x,t)|^2\,ds\,dt,\\
\text{subject to}\quad
y_t-\Delta y&=0 &&\text{in }Q:=\Omega\times(0,T),\\
\frac{\partial y}{\partial\nu}&=\alpha(u-y) &&\text{on }\Sigma:=\Gamma\times(0,T),\\
y(x,0)&=y_0(x) &&\text{in }\Omega,\\
u_a(x,t)&\leq u(x,t)\leq u_b(x,t) &&\text{on }\Sigma.
\end{aligned}
$$

This is a **linear-quadratic parabolic boundary-control problem**. Optimal vibration and nonconvex examples are just mentioned here and would be treated later in the chapters. The present course focuses on linear-quadratic elliptic problems, asking about existence, necessary and sufficient conditions, and numerical methods.

## 3. The finite-dimensional problem

Let the state be \(y\in\mathbb R^n\), the control \(u\in\mathbb R^m\), and the admissible set \(U_{\mathrm{ad}}\subset\mathbb R^m\). Given \(J:\mathbb R^n\times\mathbb R^m\to\mathbb R\), consider

$$
\min J(y,u)
\quad\text{subject to}\quad
Ay=Bu,\qquad u\in U_{\mathrm{ad}},
$$

where \(A\in\mathbb R^{n\times n}\) and \(B\in\mathbb R^{n\times m}\).

### 3.1 The reduced problem

If \(A\) is invertible, each admissible \(u\) determines one and only one state:

$$
y=A^{-1}Bu.
$$

This is why \(u\) is called the control: varying it changes the state. Define the solution operator

$$
S:=A^{-1}B,\qquad y=Su.
$$

The state can then be eliminated:

$$
f(u):=J(Su,u)=J(A^{-1}Bu,u),
$$

and the original problem becomes

$$
\min_{u\in U_{\mathrm{ad}}}f(u).
$$

For example, with desired state \(y_d\in\mathbb R^n\) and \(\lambda\geq0\),

$$
J(y,u)=|y-y_d|^2+\lambda|u|^2
$$

leads to

$$
\min_{u\in U_{\mathrm{ad}}}
\left|A^{-1}Bu-y_d\right|^2+\lambda|u|^2.
$$

### 3.2 Existence

**Definition.** A vector \(\bar u\in U_{\mathrm{ad}}\) is an optimal control if

$$
f(\bar u)\leq f(u)\qquad\forall u\in U_{\mathrm{ad}}.
$$

The associated optimal state is \(\bar y=S\bar u\). Overlines will indicate optimal quantities.

**Theorem.** If \(A\) is invertible, \(J\) is continuous, and \(U_{\mathrm{ad}}\) is nonempty, closed, and bounded, then an optimal control exists.

Indeed, \(f(u)=J(A^{-1}Bu,u)\) is continuous. In \(\mathbb R^m\), closed and bounded sets are compact, so the Weierstrass theorem guarantees that \(f\) attains its minimum on \(U_{\mathrm{ad}}\). This proof does not carry over directly to infinite-dimensional spaces: there, bounded closed sets need not be compact.

## 4. First-order necessary conditions

For \(f:\mathbb R^m\to\mathbb R\), write

$$
D_i=\frac{\partial}{\partial u_i},\qquad
f'(u)=\big(D_1f(u),\ldots,D_mf(u)\big),\qquad
\nabla f(u)=f'(u)^T.
$$

For \(a,b\in\mathbb R^m\), let

$$
(a,b)_{\mathbb R^m}=a\cdot b=\sum_{i=1}^m a_i b_i,
$$

so \(f'(u)h=(\nabla f(u),h)_{\mathbb R^m}\).

### 4.1 Variational inequality

Assume \(U_{\mathrm{ad}}\) is convex and \(\bar u\) is optimal. Then

$$
f'(\bar u)(u-\bar u)\geq0
\qquad\forall u\in U_{\mathrm{ad}}.
\tag{VI}
$$

To see this, fix \(u\in U_{\mathrm{ad}}\) and set

$$
u(\tau)=\bar u+\tau(u-\bar u),\qquad 0<\tau<1.
$$

Convexity puts \(u(\tau)\) in \(U_{\mathrm{ad}}\). Optimality gives

$$
0\leq\frac{f(\bar u+\tau(u-\bar u))-f(\bar u)}{\tau}.
$$

Taking \(\tau\to0^+\) proves (VI). It says that the objective cannot decrease in a feasible direction from \(\bar u\). It does not generally imply \(f'(\bar u)=0\): for \(f(u)=-u^2\) on \([0,1]\), the minimum is at \(\bar u=1\), while \(f'(1)=-2\).

### 4.2 Derivative of the reduced functional

Since \(f(u)=J(Su,u)\), the chain rule gives, for \(h\in\mathbb R^m\),

$$
\begin{aligned}
f'(u)h
&=D_yJ(Su,u)(Sh)+D_uJ(Su,u)h\\
&=\big(S^T\nabla_yJ(Su,u)+\nabla_uJ(Su,u),h\big)_{\mathbb R^m}.
\end{aligned}
$$

Because \(S=A^{-1}B\),

$$
f'(u)h=
\Big(B^T(A^{-1})^T\nabla_yJ(Su,u)+\nabla_uJ(Su,u),h\Big)_{\mathbb R^m}.
$$

For

$$
J(y,u)=\frac12|y-y_d|^2+\frac{\lambda}{2}|u|^2,
$$

we have

$$
\nabla_yJ=y-y_d,\qquad \nabla_uJ=\lambda u,
$$

and therefore

$$
\nabla f(u)=S^T(Su-y_d)+\lambda u.
$$

The necessary condition is

$$
\big(S^T(S\bar u-y_d)+\lambda\bar u,u-\bar u\big)_{\mathbb R^m}\geq0
\qquad\forall u\in U_{\mathrm{ad}}.
$$

## 5. The adjoint state and optimality system

The inverse transpose \((A^{-1})^T\) is best avoided in numerical work. Define the adjoint state by

$$
p=(A^{-1})^T\nabla_yJ(y,u).
$$

Equivalently, compute it from the adjoint equation

$$
A^Tp=\nabla_yJ(y,u).
$$

For the quadratic tracking functional this is \(A^T\bar p=\bar y-y_d\).

The state equation, adjoint equation, and control inequality form the optimality system:

$$
\begin{aligned}
A\bar y&=B\bar u,\qquad \bar u\in U_{\mathrm{ad}},\\
A^T\bar p&=\nabla_yJ(\bar y,\bar u),\\
\big(B^T\bar p+\nabla_uJ(\bar y,\bar u),v-\bar u\big)_{\mathbb R^m}
&\geq0\qquad\forall v\in U_{\mathrm{ad}}.
\end{aligned}
\tag{OS}
$$

If \(U_{\mathrm{ad}}=\mathbb R^m\), every direction is feasible. Applying the inequality to opposite directions gives

$$
B^T\bar p+\nabla_uJ(\bar y,\bar u)=0.
$$

For

$$
J(y,u)=\frac12|Cy-y_d|^2+\frac{\lambda}{2}|u|^2,
$$

the unconstrained system is

$$
A\bar y=B\bar u,\qquad
A^T\bar p=C^T(C\bar y-y_d),\qquad
B^T\bar p+\lambda\bar u=0.
$$

When \(\lambda>0\),

$$
\bar u=-\frac1\lambda B^T\bar p.
$$

## 6. Lagrangians

Introduce

$$
L(y,u,p)=J(y,u)-(Ay-Bu,p)_{\mathbb R^n}.
$$

The adjoint variable is a Lagrange multiplier for the state equation. Its stationarity conditions are

$$
\nabla_pL=0\iff Ay=Bu,
$$

and

$$
\nabla_yL=0\iff A^Tp=\nabla_yJ(y,u).
$$

The control condition is

$$
\big(\nabla_uL(\bar y,\bar u,\bar p),v-\bar u\big)_{\mathbb R^m}\geq0
\qquad\forall v\in U_{\mathrm{ad}},
$$

which reproduces the third equation of (OS). If there are no control constraints, all three derivatives of \(L\) vanish.

## 7. Box constraints

A common admissible set is

$$
U_{\mathrm{ad}}=\{u\in\mathbb R^m:u_a\leq u\leq u_b\},
$$

where the inequalities are componentwise. Put

$$
q:=B^T\bar p+\nabla_uJ(\bar y,\bar u).
$$

The variational inequality is equivalent to saying that \(\bar u\) solves

$$
\min_{u\in U_{\mathrm{ad}}}(q,u)_{\mathbb R^m}.
$$

The components separate, giving

$$
\begin{cases}
q_i>0 &\Longrightarrow \bar u_i=u_{a,i},\\
q_i<0 &\Longrightarrow \bar u_i=u_{b,i},\\
q_i=0 &\Longrightarrow \text{the inequality gives no direct value of }\bar u_i.
\end{cases}
$$

Thus a positive derivative pushes the control to its lower bound, a negative derivative pushes it to its upper bound, and a zero derivative leaves the component undetermined by this condition alone.

## 8. Karush–Kuhn–Tucker conditions

For \(v\in\mathbb R^m\), define

$$
v_i^+=\max\{v_i,0\},\qquad
v_i^-=\max\{-v_i,0\},\qquad v=v^+-v^-.
$$

Let

$$
\mu_a=(B^Tp+\nabla_uJ(y,u))^+,\qquad
\mu_b=(B^Tp+\nabla_uJ(y,u))^-.
$$

The extended Lagrangian is

$$
\mathcal L
=J(y,u)-(Ay-Bu,p)_{\mathbb R^n}
+(u_a-u,\mu_a)_{\mathbb R^m}
+(u-u_b,\mu_b)_{\mathbb R^m}.
$$

For an optimal pair, the KKT system is

$$
\begin{aligned}
\nabla_p\mathcal L&=0,\\
\nabla_y\mathcal L&=0,\\
\nabla_u\mathcal L&=0,\\
\mu_a&\geq0,\qquad \mu_b\geq0,\\
(u_a-\bar u,\mu_a)_{\mathbb R^m}&=0,\\
(\bar u-u_b,\mu_b)_{\mathbb R^m}&=0.
\end{aligned}
\tag{KKT}
$$

The last two equations are complementary slackness. A lower-bound multiplier can be positive only when the lower bound is active; the analogous statement holds for the upper bound. Indeed,

$$
\nabla_u\mathcal L
=\nabla_uJ+B^Tp-\mu_a+\mu_b,
$$

and \(\mu_a-\mu_b=B^Tp+\nabla_uJ\), so stationarity in \(u\) is exactly the variational inequality written with multipliers.

## 9. Worked example with two controls

Take

$$
u_a=\begin{pmatrix}-2\\-1\end{pmatrix},\qquad
u_b=\begin{pmatrix}2\\1\end{pmatrix},\qquad
A=1,\qquad B=(-1,2),
$$

and

$$
J(y,u)=u_1^2+u_2^2+2y.
$$

The state equation gives \(y=-u_1+2u_2\), so

$$
\begin{aligned}
f(u)&=u_1^2+u_2^2-2u_1+4u_2\\
&=(u_1-1)^2+(u_2+2)^2-5.
\end{aligned}
$$

The admissible set is \([-2,2]\times[-1,1]\). The unconstrained minimum \((1,-2)\) violates the second bound, so

$$
\bar u=\begin{pmatrix}1\\-1\end{pmatrix},\qquad f(\bar u)=-4.
$$

The KKT calculation agrees. Since \(\nabla_yJ=2\), the adjoint equation gives \(\bar p=2\). Hence

$$
B^T\bar p+\nabla_uJ(\bar y,\bar u)
=\begin{pmatrix}2\bar u_1-2\\2\bar u_2+4\end{pmatrix}.
$$

For \(i=1\), neither bound is compatible with the required sign, so the component must vanish: \(\bar u_1=1\). For \(i=2\), \(\bar u_2=-1\) gives \(2\bar u_2+4=2>0\), which is precisely the sign associated with the lower bound. Therefore

$$
\bar u=\begin{pmatrix}1\\-1\end{pmatrix},\qquad
\bar\mu_a=\begin{pmatrix}0\\2\end{pmatrix},\qquad
\bar\mu_b=\begin{pmatrix}0\\0\end{pmatrix}.
$$

The first component is interior and has zero multiplier. The second lies at its lower bound and has a positive lower-bound multiplier.

## 10. What entails PDE control

The finite-dimensional theory supplies the starting point for the PDE case, so we:

- choose a control from an admissible set;
- determine the state from a state equation;
- reduce the objective by substituting the state;
- introduce an adjoint equation to differentiate efficiently;
- express control constraints through a variational inequality or KKT conditions.

For PDEs, vectors become functions, matrices become differential operators, and ordinary derivatives become Fréchet derivatives. We will introduce all the functional analytic framework that we require to deal with such problems (for a more in depth treatment of those topics, you can check the Functional Analysis notes)
The viewpoint about these problems is that the structure survives, but existence and regularity require weak solutions, compactness or weak compactness, so it sits in the context of Sobolev spaces, weak solutions and adjoint operators, which builds up from a functional analytic set-up.

## References

1. F. Tröltzsch, *Optimal Control of Partial Differential Equations: Theory, Methods and Applications*, Graduate Studies in Mathematics 112, American Mathematical Society, 2010.

</article>
