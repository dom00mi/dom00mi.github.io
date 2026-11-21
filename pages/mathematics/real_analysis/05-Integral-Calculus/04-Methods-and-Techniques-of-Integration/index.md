---
layout: default
title: "5.4: Methods and Techniques of Integration"
permalink: /pages/mathematics/real_analysis/05-integral-calculus/04-methods-and-techniques-of-integration/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/real_analysis/05-integral-calculus/' | relative_url }}">Chapter 5: Integral Calculus</a>
  <div class="eyebrow">Mathematics / Real Analysis / 5.4</div>
  <h1>5.4: Methods and Techniques of Integration</h1>
  <p class="lead">Placeholder notes for Methods and Techniques of Integration.</p>
</div>

<article class="article" markdown="1">

# 4. Methods of Integration

Integration is the inverse problem of differentiation: given a function, we seek a *primitive* (or *antiderivative*) whose derivative recovers the original function. Although the fundamental theorem of calculus connects primitives with definite integrals, it does not provide a universal procedure for finding them in closed form.

The purpose of this chapter is to develop a collection of complementary methods. We begin with **inspection**, proceed to **integration by parts** and **substitution**, and then study **partial fractions** for rational functions. We then consider integrals that are not expressible in elementary functions, using **power series** and the **Dirichlet integral**, and introduce **complex exponentials** as an alternative way to handle trigonometric integrands. We conclude with **differentiation under the integral sign**, a parameter-based technique often called *Feynman’s trick*.

Throughout, an indefinite integral denotes the family of all primitives on a fixed interval, and its arbitrary constant is written as follows:

$$
\int f(x)\,dx=F(x)+C,\qquad F'(x)=f(x),\qquad C\in\mathbb R.
$$

For a continuous integrand, the fundamental theorem of calculus gives

$$
\int_a^b f(x)\,dx=F(b)-F(a)=\left[F(x)\right]_a^b.
$$

---

## 4.1. Integration by Inspection

The simplest integration technique is to **recognise a derivative**. One guesses a candidate primitive and verifies it by differentiating. This is often the fastest approach when the integrand resembles a familiar differentiation rule.

More precisely, if a differentiable function satisfies

$$
F'(x)=f(x),
$$

then

$$
\int f(x)\,dx=F(x)+C.
$$

This observation includes the standard identities

$$
\begin{aligned}
\int x^n\,dx&=\frac{x^{n+1}}{n+1}+C, && n\neq-1,\\[4pt]
\int \frac{1}{x}\,dx&=\ln|x|+C, && x\neq0,\\[4pt]
\int e^x\,dx&=e^x+C,\\[4pt]
\int \sin x\,dx&=-\cos x+C,\\[4pt]
\int \cos x\,dx&=\sin x+C.
\end{aligned}
$$

### Example 4.1. Elementary primitives

Evaluate the following integrals:

$$
\int\sin x\,dx,\qquad \int x^2\,dx,\qquad \int e^x\,dx.
$$

By direct inspection,

$$
\boxed{\begin{aligned}
\int\sin x\,dx&=-\cos x+C,\\[3pt]
\int x^2\,dx&=\frac{x^3}{3}+C,\\[3pt]
\int e^x\,dx&=e^x+C.
\end{aligned}}
$$

Differentiating each answer immediately reproduces its integrand.

### Example 4.2. Definite integrals by inspection

For the first integral,

$$
\int_0^\pi\cos x\,dx
=\left[\sin x\right]_0^\pi
=\sin\pi-\sin0
=\boxed{0}.
$$

For the second,

$$
\int_1^2 x^2\,dx
=\left[\frac{x^3}{3}\right]_1^2
=\frac{8-1}{3}
=\boxed{\frac73}.
$$

For the third, we work on the interval from zero to one, where the integrand is continuous:

$$
\begin{aligned}
\int_0^1\frac{1}{x-2}\,dx
&=\left[\ln|x-2|\right]_0^1\\[3pt]
&=\ln1-\ln2\\[3pt]
&=\boxed{-\ln2}.
\end{aligned}
$$

Inspection should generally be attempted first; when no familiar primitive is apparent, the integrand may need to be transformed.

---

## 4.2. Integration by Parts

Integration by parts reverses the **product rule**. It is particularly useful for products of functions where differentiating one factor simplifies it while integrating the other is manageable. It also allows us to integrate functions such as the logarithm by viewing them as a product with the constant function one.

### Theorem 4.1. Integration by parts

Let the functions be continuously differentiable on an open interval containing the closed interval from a to b. Then

$$
\boxed{\int_a^b F'(x)G(x)\,dx
=\left[F(x)G(x)\right]_a^b
-\int_a^b F(x)G'(x)\,dx.}
$$

Equivalently, setting the differential expressions as below,

$$
u=G(x),\qquad dv=F'(x)\,dx,
$$

we obtain the familiar form

$$
\boxed{\int u\,dv=uv-\int v\,du.}
$$

For indefinite integrals the same identity holds, with an arbitrary constant added at the end.

**Proof.** From the product rule,

$$
\frac{d}{dx}\bigl(F(x)G(x)\bigr)
=F'(x)G(x)+F(x)G'(x).
$$

Integrating over the interval and using linearity,

$$
\int_a^b(FG)'(x)\,dx
=\int_a^b F'(x)G(x)\,dx
+\int_a^b F(x)G'(x)\,dx.
$$

By the fundamental theorem of calculus,

$$
\int_a^b(FG)'(x)\,dx=F(b)G(b)-F(a)G(a).
$$

Rearranging proves the formula.

**Choosing the factors.** A good choice makes the remaining integral simpler than the original. Logarithms and polynomial factors are often convenient to differentiate, while exponentials and trigonometric functions are often convenient to integrate. These are guidelines rather than rules: some integrals require applying the method twice and solving an equation for the original integral.

### Example 4.3. An exponential–polynomial product

Evaluate

$$
I=\int_0^1 xe^{-x}\,dx.
$$

Choose

$$
u=x,\qquad dv=e^{-x}\,dx,
\qquad du=dx,\qquad v=-e^{-x}.
$$

Integration by parts gives

$$
\begin{aligned}
I&=\left[-xe^{-x}\right]_0^1+\int_0^1e^{-x}\,dx\\[3pt]
&=\left[-xe^{-x}-e^{-x}\right]_0^1\\[3pt]
&=\boxed{1-\frac2e}.
\end{aligned}
$$

### Example 4.4. An integral of the logarithm

Consider

$$
I=\int_1^2\ln x\,dx.
$$

Set

$$
u=\ln x,\qquad dv=dx,
\qquad du=\frac{1}{x}\,dx,\qquad v=x.
$$

It follows that

$$
\begin{aligned}
I&=\left[x\ln x\right]_1^2-\int_1^2 1\,dx\\[3pt]
&=2\ln2-\left[x\right]_1^2\\[3pt]
&=\boxed{2\ln2-1}.
\end{aligned}
$$

The same calculation, without bounds, establishes the general primitive

$$
\boxed{\int\ln x\,dx=x\ln x-x+C,\qquad x>0.}
$$

More formally, choosing any fixed positive base point and integrating from that point to a variable endpoint shows that the apparent base-point terms can be absorbed into the arbitrary constant.

### Example 4.5. A polynomial–trigonometric product

Evaluate

$$
I=\int_0^\pi x\sin x\,dx.
$$

Taking

$$
u=x,\qquad dv=\sin x\,dx,
\qquad du=dx,\qquad v=-\cos x,
$$

we find

$$
\begin{aligned}
I&=\left[-x\cos x\right]_0^\pi+\int_0^\pi\cos x\,dx\\[3pt]
&=-\pi\cos\pi+\left[\sin x\right]_0^\pi\\[3pt]
&=\boxed{\pi}.
\end{aligned}
$$

### Example 4.6. Repeated integration by parts

Consider the pair of integrals

$$
I=\int_0^\pi e^x\cos x\,dx,
\qquad
J=\int_0^\pi e^x\sin x\,dx.
$$

Applying integration by parts to the first integral, with the exponential as the differentiated factor and cosine as the integrated factor, gives

$$
\begin{aligned}
I
&=\left[e^x\sin x\right]_0^\pi
-\int_0^\pi e^x\sin x\,dx\\[3pt]
&=-J.
\end{aligned}
$$

Applying integration by parts to the second integral gives

$$
\begin{aligned}
J
&=\left[-e^x\cos x\right]_0^\pi
+\int_0^\pi e^x\cos x\,dx\\[3pt]
&=(e^\pi+1)+I.
\end{aligned}
$$

Combining the two equations,

$$
I=-(e^\pi+1)-I,
\qquad 2I=-(e^\pi+1).
$$

Therefore,

$$
\boxed{\int_0^\pi e^x\cos x\,dx=-\frac{e^\pi+1}{2},}
$$

and consequently

$$
\boxed{\int_0^\pi e^x\sin x\,dx=\frac{e^\pi+1}{2}.}
$$

The key idea is that the original integral reappears after two applications. One can then solve the resulting algebraic equation. In Section 4.6 we will recover the same results directly using complex exponentials.

### Example 4.7. A primitive involving the square of a sine

Find all primitives of

$$
h(x)=\sin^2x+2x+3,\qquad x\in\mathbb R.
$$

We first calculate the trigonometric part by integration by parts:

$$
\begin{aligned}
\int_0^x\sin^2t\,dt
&=\left[-\sin t\cos t\right]_0^x
+\int_0^x\cos^2t\,dt\\[3pt]
&=-\sin x\cos x
+\int_0^x(1-\sin^2t)\,dt.
\end{aligned}
$$

The same integral appears on both sides, so

$$
2\int_0^x\sin^2t\,dt=x-\sin x\cos x.
$$

Hence

$$
\int_0^x\sin^2t\,dt=\frac{x-\sin x\cos x}{2}.
$$

Adding the remaining terms,

$$
\begin{aligned}
H(x)
&=\frac{x-\sin x\cos x}{2}+x^2+3x+C\\[3pt]
&=\boxed{x^2+\frac72x-\frac12\sin x\cos x+C}.
\end{aligned}
$$

As a check, differentiation gives exactly the original function. In particular, the factor one-half in front of the trigonometric product is necessary.

### Example 4.8. A primitive of the squared secant

Find all primitives of

$$
h(x)=\frac{1}{\cos^2x},
\qquad -\frac\pi2<x<\frac\pi2.
$$

Using the identity

$$
1=\cos^2t+\sin^2t,
$$

we write

$$
\int_0^x\frac{1}{\cos^2t}\,dt
=x+\int_0^x\frac{\sin^2t}{\cos^2t}\,dt.
$$

For the remaining integral, take the factors

$$
F(t)=\frac1{\cos t},\qquad G(t)=\sin t,
$$

so that

$$
F'(t)=\frac{\sin t}{\cos^2t},
\qquad G'(t)=\cos t.
$$

Integration by parts yields

$$
\begin{aligned}
\int_0^x\frac{\sin^2t}{\cos^2t}\,dt
&=\left[\frac{\sin t}{\cos t}\right]_0^x
-\int_0^x\frac{1}{\cos t}\cos t\,dt\\[3pt]
&=\tan x-x.
\end{aligned}
$$

Therefore

$$
\int_0^x\frac{1}{\cos^2t}\,dt=x+(\tan x-x)=\tan x,
$$

and all primitives on this interval are

$$
\boxed{H(x)=\tan x+C.}
$$

---

## 4.3. Integration by Substitution

Substitution, also called **change of variable**, is the inverse counterpart of the **chain rule**. Its purpose is to express a complicated integral in terms of a simpler variable, keeping track of both the differential and, for definite integrals, the integration limits.

### Theorem 4.2. Change of variable

Let the function below be continuously differentiable on an open interval containing the points a and b, and let the second function be continuous on an interval containing its image:

$$
\varphi:(c,d)\longrightarrow\mathbb R,
\qquad f:\, (c',d')\longrightarrow\mathbb R,
\qquad \varphi((c,d))\subseteq(c',d').
$$

Then

$$
\boxed{\int_a^b f(\varphi(t))\varphi'(t)\,dt
=\int_{\varphi(a)}^{\varphi(b)}f(u)\,du.}
$$

This formula remains valid if the substitution reverses the order of the limits, because definite integrals are oriented:

$$
\int_\beta^\alpha f(u)\,du=-\int_\alpha^\beta f(u)\,du.
$$

**Proof.** Let a primitive of the continuous function be defined by

$$
F(s)=\int_\gamma^s f(u)\,du,
$$

where the base point belongs to the interval on which the function is continuous. By the fundamental theorem of calculus,

$$
F'(s)=f(s).
$$

The chain rule therefore gives

$$
\frac{d}{dt}F(\varphi(t))
=F'(\varphi(t))\varphi'(t)
=f(\varphi(t))\varphi'(t).
$$

Integrating and applying the fundamental theorem again,

$$
\begin{aligned}
\int_a^b f(\varphi(t))\varphi'(t)\,dt
&=F(\varphi(b))-F(\varphi(a))\\[3pt]
&=\int_{\varphi(a)}^{\varphi(b)}f(u)\,du.
\end{aligned}
$$

This proves the identity.

For an indefinite integral, the same principle takes the form

$$
\int f(\varphi(x))\varphi'(x)\,dx
=F(\varphi(x))+C,
\qquad F'=f.
$$

**Practical procedure.** Choose a substitution, calculate its differential, rewrite the entire integrand in the new variable, change the bounds when present, and integrate. Avoid mixing old and new variables within the same integral.

### Example 4.9. A polynomial substitution

Evaluate

$$
I=\int_0^2 x(1+x^2)^4\,dx.
$$

Set

$$
u=1+x^2,\qquad du=2x\,dx.
$$

The bounds become

$$
x=0\implies u=1,
\qquad x=2\implies u=5.
$$

Consequently,

$$
\begin{aligned}
I&=\frac12\int_1^5u^4\,du\\[3pt]
&=\frac1{10}\left[u^5\right]_1^5\\[3pt]
&=\frac{5^5-1}{10}\\[3pt]
&=\boxed{\frac{1562}{5}}.
\end{aligned}
$$

### Example 4.10. Trigonometric substitution and a quarter-circle

Evaluate

$$
I=\int_0^1 2\sqrt{1-x^2}\,dx.
$$

Use the substitution

$$
x=\cos u,\qquad dx=-\sin u\,du.
$$

As the original variable increases from zero to one, the new variable decreases from pi over two to zero:

$$
x=0\implies u=\frac\pi2,
\qquad x=1\implies u=0.
$$

For the relevant interval, the sine is nonnegative, so

$$
\sqrt{1-\cos^2u}=\sin u.
$$

Therefore

$$
\begin{aligned}
I&=\int_{\pi/2}^{0}2\sin u(-\sin u)\,du\\[3pt]
&=2\int_0^{\pi/2}\sin^2u\,du\\[3pt]
&=\int_0^{\pi/2}(1-\cos2u)\,du\\[3pt]
&=\left[u-\frac{\sin2u}{2}\right]_0^{\pi/2}\\[3pt]
&=\boxed{\frac\pi2}.
\end{aligned}
$$

Geometrically, the graph of the square root is the upper quarter of the unit circle. The factor of two makes the integral equal to the area of a semicircle of radius one.

### Example 4.11. A trigonometric power

Consider

$$
I=\int_0^{\pi/2}\sin^5t\cos t\,dt.
$$

Let

$$
u=\sin t,\qquad du=\cos t\,dt.
$$

The bounds become zero and one, giving

$$
I=\int_0^1u^5\,du
=\left[\frac{u^6}{6}\right]_0^1
=\boxed{\frac16}.
$$

### Example 4.12. A primitive involving a trigonometric composition

Find all primitives of

$$
f(x)=\sin^2x\cos x.
$$

Set

$$
u=\sin x,\qquad du=\cos x\,dx.
$$

Then

$$
\int\sin^2x\cos x\,dx
=\int u^2\,du
=\boxed{\frac{\sin^3x}{3}+C}.
$$

The answer is valid for all real x; no globally invertible sine function is needed because the chain-rule form of substitution is sufficient.

### Example 4.13. Primitives of an exponential with arbitrary base

Let the base be positive. Since

$$
a^x=e^{x\ln a},\qquad a>0,
$$

we distinguish two cases. For a base different from one, the substitution

$$
u=x\ln a,\qquad du=(\ln a)\,dx
$$

gives

$$
\int a^x\,dx
=\frac{1}{\ln a}\int e^u\,du
=\boxed{\frac{a^x}{\ln a}+C},
\qquad a>0,\ a\neq1.
$$

For the special case of a base equal to one,

$$
\boxed{\int1^x\,dx=\int1\,dx=x+C.}
$$

### Example 4.14. The inverse sine primitive

Find all primitives of

$$
f(x)=\frac1{\sqrt{1-x^2}},\qquad -1<x<1.
$$

Set

$$
x=\sin u,\qquad dx=\cos u\,du,
\qquad -\frac\pi2<u<\frac\pi2.
$$

On this interval the cosine is positive, so

$$
\sqrt{1-\sin^2u}=\sqrt{\cos^2u}=\cos u.
$$

Hence

$$
\begin{aligned}
\int\frac{1}{\sqrt{1-x^2}}\,dx
&=\int\frac{\cos u}{\cos u}\,du\\[3pt]
&=u+C\\[3pt]
&=\boxed{\arcsin x+C}.
\end{aligned}
$$

### Combining substitution with integration by parts

The methods in Sections 4.2 and 4.3 are not mutually exclusive. A substitution may uncover a product that is best handled by integration by parts.

### Example 4.15. Substitution followed by parts

Evaluate

$$
I=\int_0^{\sqrt[3]{2\pi}}x^5\sin(x^3)\,dx.
$$

Let

$$
y=x^3,\qquad dy=3x^2\,dx,
\qquad x^5\,dx=x^3x^2\,dx=\frac{y}{3}\,dy.
$$

The limits change from zero and the cube root of two pi to zero and two pi. Thus

$$
I=\frac13\int_0^{2\pi}y\sin y\,dy.
$$

Integrating by parts,

$$
\begin{aligned}
I&=\frac13\left(\left[-y\cos y\right]_0^{2\pi}
+\int_0^{2\pi}\cos y\,dy\right)\\[3pt]
&=\frac13\left(-2\pi+\left[\sin y\right]_0^{2\pi}\right)\\[3pt]
&=\boxed{-\frac{2\pi}{3}}.
\end{aligned}
$$

### Example 4.16. An exponential substitution followed by parts

Evaluate

$$
I=\int_0^1 e^{2x}\cos(e^x-1)\,dx.
$$

Use

$$
y=e^x-1,\qquad dy=e^x\,dx,
\qquad e^x=y+1.
$$

The bounds become zero and e minus one, so

$$
I=\int_0^{e-1}(y+1)\cos y\,dy.
$$

Choosing the polynomial factor for differentiation,

$$
\begin{aligned}
I&=\left[(y+1)\sin y\right]_0^{e-1}
-\int_0^{e-1}\sin y\,dy\\[3pt]
&=\left[(y+1)\sin y+\cos y\right]_0^{e-1}\\[3pt]
&=\boxed{e\sin(e-1)+\cos(e-1)-1}.
\end{aligned}
$$

---

## 4.4. Integration Using Partial Fractions

A **rational function** is a quotient of two polynomials:

$$
R(x)=\frac{P(x)}{Q(x)},\qquad Q(x)\neq0.
$$

Partial fractions exploit the algebraic factorisation of the denominator to express the rational function as a sum of simpler terms, whose primitives can be found by inspection or substitution.

### 4.4.1. Proper rational functions with distinct linear factors

Suppose the numerator has smaller degree than the denominator and the latter splits into distinct real linear factors:

$$
\deg P<\deg Q,
\qquad Q(x)=\prod_{k=1}^{n}(x-a_k),
\qquad a_j\neq a_k\quad(j\neq k).
$$

Then the partial-fraction decomposition has the form

$$
\boxed{\frac{P(x)}{Q(x)}
=\sum_{k=1}^{n}\frac{A_k}{x-a_k}.}
$$

The coefficients are determined by multiplying through by the denominator and comparing polynomial coefficients, or by evaluating the resulting polynomial identity at carefully chosen points.

### Example 4.17. Two distinct linear factors

Decompose

$$
\frac{x+4}{x^2-5x+6}.
$$

The denominator factors as

$$
x^2-5x+6=(x-2)(x-3).
$$

Seek constants A and B satisfying

$$
\frac{x+4}{(x-2)(x-3)}
=\frac{A}{x-2}+\frac{B}{x-3}.
$$

Multiplying by the common denominator yields

$$
x+4=A(x-3)+B(x-2).
$$

Equating the coefficients of x and the constants gives

$$
A+B=1,\qquad -3A-2B=4.
$$

Solving,

$$
A=-6,\qquad B=7.
$$

Thus

$$
\boxed{\frac{x+4}{x^2-5x+6}
=-\frac6{x-2}+\frac7{x-3}.}
$$

In particular, on any interval avoiding both poles,

$$
\boxed{\int\frac{x+4}{x^2-5x+6}\,dx
=-6\ln|x-2|+7\ln|x-3|+C.}
$$

### 4.4.2. Repeated linear factors

If the denominator contains a factor raised to a positive integer power, **every power up to that multiplicity must appear** in the decomposition. For example,

$$
\frac{P(x)}{(x-a)^2(x-b)}
=\frac{A}{x-a}+\frac{B}{(x-a)^2}+\frac{D}{x-b},
$$

provided the rational function is proper and the displayed factors are distinct apart from the repetition.

### Example 4.18. A repeated factor

Evaluate

$$
I=\int\frac{1}{x(x-1)^2}\,dx.
$$

Write

$$
\frac1{x(x-1)^2}
=\frac A{x}+\frac B{(x-1)^2}+\frac D{x-1}.
$$

Multiplication by the denominator gives

$$
1=A(x-1)^2+Bx+Dx(x-1).
$$

Expanding and comparing coefficients,

$$
\begin{aligned}
A+D&=0,\\
-2A+B-D&=0,\\
A&=1.
\end{aligned}
$$

The solution is

$$
A=1,\qquad B=1,\qquad D=-1.
$$

Consequently,

$$
\begin{aligned}
I
&=\int\left(\frac1x+\frac1{(x-1)^2}-\frac1{x-1}\right)dx\\[3pt]
&=\boxed{\ln|x|-\frac1{x-1}-\ln|x-1|+C}.
\end{aligned}
$$

The constant may differ between connected intervals of the domain, because the integrand is undefined at zero and one.

### 4.4.3. Irreducible quadratic factors

When the denominator contains a real quadratic factor that cannot be split into real linear factors, its numerator in the decomposition must be **linear**, not merely constant. For example,

$$
\frac{P(x)}{(x-a)(x^2+bx+c)}
=\frac A{x-a}+\frac{Bx+D}{x^2+bx+c},
$$

where the quadratic is irreducible over the reals. Repeated irreducible quadratics require one such linear numerator over each successive power of that quadratic.

The resulting terms can be integrated using logarithms, completing the square, and inverse trigonometric functions. For example,

$$
\int\frac{2x+b}{x^2+bx+c}\,dx
=\ln|x^2+bx+c|+C,
$$

on intervals where the denominator does not vanish. When the quadratic is positive and its discriminant is negative,

$$
\int\frac{dx}{x^2+bx+c}
=\frac{2}{\sqrt{4c-b^2}}
\arctan\!\left(\frac{2x+b}{\sqrt{4c-b^2}}\right)+C,
\quad 4c-b^2>0.
$$

### 4.4.4. Improper rational functions and polynomial division

If the numerator has degree at least as large as the denominator, polynomial division must come first. The division algorithm gives

$$
P(x)=Q(x)S(x)+R(x),
\qquad \deg R<\deg Q,
$$

where the remainder may be zero. Therefore

$$
\boxed{\frac{P(x)}{Q(x)}=S(x)+\frac{R(x)}{Q(x)}.}
$$

The polynomial term is integrated directly, while the proper rational remainder is treated by partial fractions.

### Example 4.19. Polynomial division and integration

Consider

$$
I=\int\frac{2x^2+x+9}{x-2}\,dx.
$$

Dividing the numerator by the denominator,

$$
\begin{aligned}
2x^2+x+9
&=(x-2)(2x+5)+19,\\[3pt]
\frac{2x^2+x+9}{x-2}
&=2x+5+\frac{19}{x-2}.
\end{aligned}
$$

Indeed,

$$
(x-2)(2x+5)+19
=2x^2+x+9.
$$

We can now integrate term by term:

$$
\begin{aligned}
I
&=\int\left(2x+5+\frac{19}{x-2}\right)dx\\[3pt]
&=\boxed{x^2+5x+19\ln|x-2|+C},
\qquad x\neq2.
\end{aligned}
$$

**Summary of the algebraic method.** Divide first when necessary; factor the denominator over the reals; include the full family of terms for repeated linear or quadratic factors; determine the unknown coefficients; and integrate the simpler pieces. Each formula applies on intervals that avoid the denominator's zeros.

---

## 4.5. Integration by Power Series and Non-Elementary Integrals

The preceding methods do not always produce primitives in terms of a finite combination of elementary functions. In such cases, a **power-series expansion** may give an exact representation, even when no elementary closed form exists. Truncating that expansion also provides a useful approximation near its centre.

If a power series converges within a nonzero radius,

$$
f(x)=\sum_{n=0}^{\infty}a_n(x-x_0)^n,
$$

then it may be integrated term by term on any closed interval lying strictly inside its radius of convergence:

$$
\boxed{\int f(x)\,dx
=C+\sum_{n=0}^{\infty}\frac{a_n}{n+1}(x-x_0)^{n+1}.}
$$

This follows from uniform convergence of the series on compact subintervals of its convergence interval. The resulting series has the same radius of convergence as the original one.

### 4.5.1. The sine integral

A classical example is the function

$$
\operatorname{Si}(x)=\int_0^x\frac{\sin t}{t}\,dt,
$$

where the integrand at zero is understood by its continuous extension:

$$
\lim_{t\to0}\frac{\sin t}{t}=1.
$$

The sine integral is a **special function**; its primitive is not expressible in elementary functions. We can nevertheless obtain an exact, globally convergent power series.

Starting with the Taylor series for sine,

$$
\sin x
=x-\frac{x^3}{3!}+\frac{x^5}{5!}-\frac{x^7}{7!}+\cdots
=\sum_{n=0}^{\infty}\frac{(-1)^n x^{2n+1}}{(2n+1)!},
$$

we divide by x and extend continuously at zero:

$$
\frac{\sin x}{x}
=1-\frac{x^2}{3!}+\frac{x^4}{5!}-\frac{x^6}{7!}+\cdots
=\sum_{n=0}^{\infty}\frac{(-1)^n x^{2n}}{(2n+1)!}.
$$

Term-by-term integration from zero to x gives

$$
\begin{aligned}
\operatorname{Si}(x)
&=x-\frac{x^3}{3\cdot3!}+\frac{x^5}{5\cdot5!}
-\frac{x^7}{7\cdot7!}+\cdots\\[3pt]
&=\boxed{\sum_{n=0}^{\infty}
\frac{(-1)^n x^{2n+1}}{(2n+1)(2n+1)!}}.
\end{aligned}
$$

Thus, on any real interval,

$$
\boxed{\int\frac{\sin x}{x}\,dx=\operatorname{Si}(x)+C,}
$$

where the integrand is continuously extended at zero. The series converges for every real value of x, although numerical evaluation far from zero can benefit from alternative representations.

### 4.5.2. The Dirichlet integral

One of the most remarkable identities associated with the sine integral is the **Dirichlet integral**:

$$
\boxed{\int_0^{\infty}\frac{\sin x}{x}\,dx=\frac\pi2.}
$$

This is an *improper, conditionally convergent* integral: the oscillations of the sine cause cancellation, whereas the integral of the absolute value diverges.

First, convergence follows from integration by parts on a finite interval. For positive R and T with T greater than R,

$$
\begin{aligned}
\int_R^T\frac{\sin x}{x}\,dx
&=\left[-\frac{\cos x}{x}\right]_R^T
-\int_R^T\frac{\cos x}{x^2}\,dx.
\end{aligned}
$$

The boundary term has a limit as T tends to infinity, and the last integral is absolutely convergent. Thus the original improper integral converges.

To calculate its value, introduce an exponential damping parameter:

$$
I(s)=\int_0^{\infty}e^{-sx}\frac{\sin x}{x}\,dx,
\qquad s>0.
$$

Differentiating under the integral sign (justified for every strictly positive s) yields

$$
\begin{aligned}
I'(s)
&=-\int_0^{\infty}e^{-sx}\sin x\,dx\\[3pt]
&=-\frac1{1+s^2}.
\end{aligned}
$$

Since the damping makes the integral tend to zero as s tends to infinity,

$$
I(s)=\int_s^{\infty}\frac{du}{1+u^2}
=\frac\pi2-\arctan s.
$$

Equivalently,

$$
\boxed{I(s)=\arctan\!\left(\frac1s\right),\qquad s>0.}
$$

Finally, because the undamped improper integral converges, its value is the limit of these exponentially damped integrals as the parameter decreases to zero. This limiting step can be justified by integration by parts, which bounds the tails uniformly in the damping parameter. Therefore

$$
\begin{aligned}
\int_0^{\infty}\frac{\sin x}{x}\,dx
&=\lim_{s\downarrow0}I(s)\\[3pt]
&=\lim_{s\downarrow0}\left(\frac\pi2-\arctan s\right)\\[3pt]
&=\boxed{\frac\pi2}.
\end{aligned}
$$

In terms of the sine integral,

$$
\boxed{\lim_{x\to+\infty}\operatorname{Si}(x)=\frac\pi2.}
$$

The power series and the damping argument answer different questions: the series represents the primitive and is effective locally, while the improper-integral argument establishes its limiting value at infinity.

---

## 4.6. Complex Exponential Substitutions

Euler's formula connects trigonometric functions with complex exponentials:

$$
e^{ix}=\cos x+i\sin x,
\qquad e^{-ix}=\cos x-i\sin x.
$$

Adding and subtracting these identities,

$$
\boxed{\cos x=\frac{e^{ix}+e^{-ix}}2,
\qquad
\sin x=\frac{e^{ix}-e^{-ix}}{2i}.}
$$

This suggests another approach to integration. Instead of repeatedly integrating trigonometric products by parts, we can combine real exponentials and oscillations into a **single complex exponential**, integrate it, and take the real or imaginary part.

### 4.6.1. Exponentially damped or amplified trigonometric integrals

For real parameters a and b, provided the complex denominator is nonzero,

$$
\int e^{(a+ib)x}\,dx
=\frac{e^{(a+ib)x}}{a+ib}+C.
$$

Since

$$
e^{(a+ib)x}=e^{ax}\bigl(\cos(bx)+i\sin(bx)\bigr),
$$

we can compute the two real integrals directly. Multiplying the fraction by the conjugate of its denominator,

$$
\frac1{a+ib}=\frac{a-ib}{a^2+b^2},
$$

and equating real and imaginary parts gives

$$
\boxed{\int e^{ax}\cos(bx)\,dx
=\frac{e^{ax}}{a^2+b^2}\bigl(a\cos(bx)+b\sin(bx)\bigr)+C,}
$$

$$
\boxed{\int e^{ax}\sin(bx)\,dx
=\frac{e^{ax}}{a^2+b^2}\bigl(a\sin(bx)-b\cos(bx)\bigr)+C,}
$$

for real a and b not both zero.

### Example 4.20. Integrating an exponential–trigonometric product without parts

Revisit the integral

$$
I=\int_0^\pi e^x\cos x\,dx.
$$

Because cosine is the real part of a complex exponential,

$$
\begin{aligned}
I
&=\operatorname{Re}\int_0^\pi e^{(1+i)x}\,dx\\[3pt]
&=\operatorname{Re}\left[\frac{e^{(1+i)x}}{1+i}\right]_0^\pi.
\end{aligned}
$$

Using

$$
\frac1{1+i}=\frac{1-i}{2},
$$

we obtain an antiderivative by taking real parts:

$$
\begin{aligned}
\operatorname{Re}\left(\frac{e^{(1+i)x}}{1+i}\right)
&=\frac{e^x}{2}\operatorname{Re}\left((1-i)(\cos x+i\sin x)\right)\\[3pt]
&=\frac{e^x}{2}(\cos x+\sin x).
\end{aligned}
$$

Consequently,

$$
\begin{aligned}
I
&=\left[\frac{e^x}{2}(\cos x+\sin x)\right]_0^\pi\\[3pt]
&=\boxed{-\frac{e^\pi+1}{2}}.
\end{aligned}
$$

This agrees with Example 4.6, but avoids the two integrations by parts entirely. Similarly, taking imaginary parts gives

$$
\int e^x\sin x\,dx
=\frac{e^x}{2}(\sin x-\cos x)+C.
$$

### 4.6.2. Rationalising trigonometric expressions

Complex exponentials can also transform trigonometric rational functions into rational expressions. Introduce the complex variable

$$
z=e^{ix},\qquad dz=iz\,dx,
\qquad dx=\frac{dz}{iz}.
$$

From Euler's identity,

$$
\cos x=\frac{z+z^{-1}}2
=\frac{z^2+1}{2z}.
$$

Thus the integral of the secant becomes a rational integral in z.

### Example 4.21. The secant integral using complex exponentials

On any interval where the cosine is nonzero, start from

$$
\int\sec x\,dx
=\int\frac{dx}{\cos x}.
$$

With the substitution just introduced,

$$
\begin{aligned}
\int\frac{dx}{\cos x}
&=\frac2i\int\frac{dz}{z^2+1}\\[3pt]
&=\frac2i\int\frac{dz}{(z-i)(z+i)}.
\end{aligned}
$$

The algebraic partial-fraction identity is

$$
\frac1{z^2+1}
=\frac1{2i}\left(\frac1{z-i}-\frac1{z+i}\right).
$$

Integrating and choosing continuous logarithm branches along the relevant arc gives

$$
\int\sec x\,dx
=\log\!\left(\frac{z+i}{z-i}\right)+C,
\qquad z=e^{ix}.
$$

The complex expression has a real derivative along real x, so its imaginary part is locally constant. Taking its real part therefore gives a real primitive:

$$
\begin{aligned}
\int\sec x\,dx
&=\ln\left|\frac{e^{ix}+i}{e^{ix}-i}\right|+C\\[3pt]
&=\frac12\ln\left(\frac{1+\sin x}{1-\sin x}\right)+C\\[3pt]
&=\boxed{\ln|\sec x+\tan x|+C}.
\end{aligned}
$$

This example connects **complex exponentials**, **partial fractions**, and the usual trigonometric primitive. Complex logarithms require consistent branch choices, but the final real-valued identity is valid on each interval where the cosine does not vanish.

For a complementary discussion of complex-number techniques in elementary integration, see [Complex tricks for integration (University of Maryland)](https://math.umd.edu/~jmr/141/complextricks.pdf).

---

## 4.7. Choosing an Integration Method

No single technique is best for every integral. A sensible strategy is to identify the mathematical structure of the integrand before manipulating it.

1. **Inspection:** Look for a known derivative or a straightforward linear combination of familiar primitives.
2. **Integration by parts:** Look for a product in which one factor becomes simpler upon differentiation, or for an integral that may reappear after repeated applications.
3. **Substitution:** Look for a composite function accompanied by the derivative of its inner expression; update definite-integral bounds immediately.
4. **Partial fractions:** For rational functions, divide first if necessary, factor the denominator, and decompose into elementary terms.
5. **Power series:** When an elementary primitive is unavailable or an approximation is useful, expand a suitable integrand and integrate term by term within the appropriate convergence region.
6. **Complex exponentials:** For products of exponentials and trigonometric functions, combine oscillations into a complex exponential and recover the desired real or imaginary part.
7. **Differentiation under the integral sign:** Introduce a parameter when direct integration is difficult, differentiate the parameterised integral, and use an initial or limiting condition to reconstruct it.

These methods often reinforce each other rather than compete. Substitution can lead to integration by parts, partial fractions can follow a complex change of variable, and power series can describe primitives that cannot be written in elementary form.

---

## 4.8. Differentiation Under the Integral Sign — Feynman's Trick

A less conventional but remarkably effective method of integration consists of **introducing an auxiliary parameter into an integral and differentiating with respect to that parameter**. The technique is generally known as *differentiation under the integral sign*, or the **Leibniz integral rule**. It is also associated with Richard Feynman, who described its usefulness in his autobiography *Surely You're Joking, Mr. Feynman!*

The essential idea is to replace a difficult integral by a family of integrals whose variation with a parameter is easier to understand. Differentiation can simplify the integrand, cancel a troublesome factor, or lead to a differential equation for the parameterised integral. Once this equation has been solved, an initial value or a limiting condition determines the desired result.

The discussion and examples in this section are developed from the exposition of [Leo Goldmakher, *Differentiation Under the Integral Sign*](https://web.williams.edu/Mathematics/lg5/Feynman.pdf), with additional explanations of the analytic assumptions and convergence issues.

### 4.8.1. The Leibniz integral rule

Let

$$
F(t)=\int_a^b f(x,t)\,dx,
$$

where the integrand depends on both the integration variable $x$ and a parameter $t$. Under suitable regularity assumptions, one may interchange differentiation and integration:

$$
\boxed{
\frac{d}{dt}\int_a^b f(x,t)\,dx
=\int_a^b\frac{\partial f}{\partial t}(x,t)\,dx.
}
$$

**Theorem 4.3 (Differentiation under the integral sign).** Suppose that $t$ varies in an open interval $J$ and that $f(x,t)$ and $\partial f/\partial t$ are continuous on $[a,b]\times J$, where $a<b$ are finite. Then $F$ is differentiable on $J$ and

$$
F'(t)=\int_a^b \frac{\partial f}{\partial t}(x,t)\,dx.
$$

**Proof.** Fix $t\in J$. By the definition of the derivative,

$$
\begin{aligned}
F'(t)
&=\lim_{h\to0}\frac{F(t+h)-F(t)}{h}\\[3pt]
&=\lim_{h\to0}\int_a^b
\frac{f(x,t+h)-f(x,t)}{h}\,dx.
\end{aligned}
$$

Because the parameter derivative is continuous on each compact rectangle around $t$, the difference quotients converge uniformly in $x\in[a,b]$ to $\partial f/\partial t(x,t)$. We may therefore exchange the limit and the integral:

$$
F'(t)=\int_a^b \lim_{h\to0}
\frac{f(x,t+h)-f(x,t)}{h}\,dx
=\int_a^b\frac{\partial f}{\partial t}(x,t)\,dx.
$$

This proves the result.

For **improper integrals**, such as integrals over $[0,\infty)$, convergence alone is not sufficient to justify this interchange. A useful sufficient condition is that, on every compact parameter interval $K\subset J$, the derivative satisfies

$$
\left|\frac{\partial f}{\partial t}(x,t)\right|
\leq g_K(x),\qquad t\in K,
$$

where $g_K$ is integrable with respect to $x$. Assuming the integrand is integrable at one parameter value and is continuously differentiable in the parameter for almost every $x$, the dominated convergence theorem then justifies differentiation under the integral sign. In the examples below, the exponential damping factors provide the required bounds whenever the parameter is strictly positive.

**Remark (Variable integration limits).** When the endpoints also depend differentiably on $t$, the full Leibniz formula is

$$
\boxed{
\frac{d}{dt}\int_{a(t)}^{b(t)} f(x,t)\,dx
=f(b(t),t)b'(t)-f(a(t),t)a'(t)
+\int_{a(t)}^{b(t)}\frac{\partial f}{\partial t}(x,t)\,dx.
}
$$

The endpoint terms follow from the fundamental theorem of calculus and the chain rule. Feynman's trick typically uses fixed endpoints, so only the integral of the parameter derivative remains.

### 4.8.2. Recovering the Gamma function

### Example 4.22. Factorials from a parameterised exponential integral

Consider the elementary improper integral

$$
F(t)=\int_0^\infty e^{-tx}\,dx,\qquad t>0.
$$

By direct integration,

$$
F(t)=\left[-\frac{e^{-tx}}{t}\right]_0^\infty=\frac1t.
$$

Differentiating with respect to $t$ rather than $x$ gives

$$
\begin{aligned}
F'(t)
&=\int_0^\infty\frac{\partial}{\partial t}
\left(e^{-tx}\right)\,dx\\[3pt]
&=-\int_0^\infty xe^{-tx}\,dx
=-\frac1{t^2}.
\end{aligned}
$$

Repeated differentiation yields, for every integer $n\geq0$,

$$
\begin{aligned}
F^{(n)}(t)
&=(-1)^n\int_0^\infty x^ne^{-tx}\,dx\\[3pt]
&=\frac{(-1)^n n!}{t^{n+1}}.
\end{aligned}
$$

Hence

$$
\boxed{\int_0^\infty x^ne^{-tx}\,dx=\frac{n!}{t^{n+1}},
\qquad t>0,\quad n=0,1,2,\ldots.}
$$

In particular, at $t=1$,

$$
\boxed{n!=\int_0^\infty x^ne^{-x}\,dx.}
$$

This motivates Euler's **Gamma function**, defined for real $s>0$ by

$$
\boxed{\Gamma(s)=\int_0^\infty x^{s-1}e^{-x}\,dx.}
$$

Integration by parts shows that

$$
\Gamma(s+1)=s\Gamma(s),\qquad \Gamma(1)=1,
$$

and therefore

$$
\boxed{\Gamma(n+1)=n!,\qquad n\in\{0,1,2,\ldots\}.}
$$

The integral defining $\Gamma(s)$ remains meaningful for positive non-integer arguments. Thus, differentiating a simple exponential integral reveals a formula that extends the factorial beyond the integers.

### 4.8.3. Introducing an artificial parameter

When an integral contains no parameter, we can sometimes create one deliberately. The goal is to choose a family that contains the original integral and has a much simpler derivative.

### Example 4.23. A logarithmic integral

Evaluate

$$
I=\int_0^1\frac{x^2-1}{\ln x}\,dx.
$$

The apparent singularity at $x=1$ is removable, since

$$
\lim_{x\to1}\frac{x^2-1}{\ln x}=2.
$$

Introduce, for $t>-1$,

$$
G(t)=\int_0^1\frac{x^t-1}{\ln x}\,dx.
$$

The desired integral is $G(2)$, and $G(0)=0$. Differentiating with respect to $t$ cancels the logarithm:

$$
\begin{aligned}
G'(t)
&=\int_0^1\frac{\partial}{\partial t}
\left(\frac{x^t-1}{\ln x}\right)\,dx\\[3pt]
&=\int_0^1 x^t\,dx
=\frac1{t+1}.
\end{aligned}
$$

The parameter differentiation is justified locally for $t>-1$ because $x^t$ has an integrable dominating power near zero. Applying the fundamental theorem of calculus in the parameter,

$$
\begin{aligned}
G(2)
&=G(0)+\int_0^2G'(t)\,dt\\[3pt]
&=\int_0^2\frac{dt}{t+1}
=\left[\ln(t+1)\right]_0^2.
\end{aligned}
$$

Thus

$$
\boxed{\int_0^1\frac{x^2-1}{\ln x}\,dx=\ln3.}
$$

The important step is the *choice of parameter*: differentiating $x^t$ generates the factor $\ln x$ needed to cancel the denominator.

### 4.8.4. The Dirichlet integral revisited

In Section 4.5, we used exponential damping to determine the value of the Dirichlet integral. We now recognise that argument as an application of the same differentiation-under-the-integral-sign principle, and connect it with the complex-exponential method of Section 4.6.

### Example 4.24. An alternative to contour integration

Consider

$$
I=\int_{-\infty}^{\infty}\frac{\sin x}{x}\,dx.
$$

Since $\sin x/x$ is even (with its continuous extension at zero),

$$
I=2\int_0^\infty\frac{\sin x}{x}\,dx.
$$

Introduce a damping parameter $t>0$ and set

$$
H(t)=\int_0^\infty e^{-tx}\frac{\sin x}{x}\,dx.
$$

Differentiating under the integral sign eliminates the factor $1/x$:

$$
H'(t)=-\int_0^\infty e^{-tx}\sin x\,dx.
$$

Using Euler's formula and taking imaginary parts,

$$
\begin{aligned}
\int_0^\infty e^{-tx}\sin x\,dx
&=\operatorname{Im}\int_0^\infty e^{-(t-i)x}\,dx\\[3pt]
&=\operatorname{Im}\left(\frac1{t-i}\right)\\[3pt]
&=\operatorname{Im}\left(\frac{t+i}{t^2+1}\right)
=\frac1{t^2+1}.
\end{aligned}
$$

Therefore

$$
H'(t)=-\frac1{1+t^2},
\qquad
H(t)=C-\arctan t.
$$

Because $H(t)\to0$ as $t\to\infty$, we obtain $C=\pi/2$. Hence

$$
H(t)=\frac\pi2-\arctan t.
$$

The undamped integral converges by Dirichlet's test, and integration by parts gives a bound on its tails that is uniform in $t\geq0$. This justifies passage to the limit $t\downarrow0$, giving

$$
\begin{aligned}
\int_0^\infty\frac{\sin x}{x}\,dx
&=\lim_{t\downarrow0}H(t)\\[3pt]
&=\frac\pi2.
\end{aligned}
$$

Consequently,

$$
\boxed{\int_{-\infty}^{\infty}\frac{\sin x}{x}\,dx=\pi.}
$$

This is an example of how a real-variable parameter can replace a more elaborate contour-integration calculation.

### 4.8.5. Higher-order differentiation and oscillatory moments

The same parameter method gives an entire family of integral identities. Starting with

$$
\int_0^\infty e^{-tx}\sin x\,dx=\frac1{1+t^2},
\qquad t>0,
$$

we differentiate repeatedly to obtain integrals containing powers of $x$. Instead of expanding a high-order rational derivative, write

$$
\frac1{1+t^2}=\operatorname{Im}\frac1{t-i}.
$$

For every integer $n\geq1$,

$$
\begin{aligned}
\int_0^\infty x^{n-1}e^{-tx}\sin x\,dx
&=(-1)^{n-1}\frac{d^{n-1}}{dt^{n-1}}\left(\frac1{1+t^2}\right)\\[3pt]
&=(n-1)!\operatorname{Im}(t-i)^{-n}.
\end{aligned}
$$

For $t>0$, express the complex number in polar form:

$$
t-i=\sqrt{1+t^2}\,e^{-i\theta},
\qquad
\theta=\arctan\!\left(\frac1t\right)
=\arcsin\!\left(\frac1{\sqrt{1+t^2}}\right).
$$

It follows that

$$
(t-i)^{-n}=(1+t^2)^{-n/2}e^{in\theta}.
$$

Taking imaginary parts gives the identity

$$
\boxed{
\int_0^\infty x^{n-1}e^{-tx}\sin x\,dx
=\frac{(n-1)!}{(1+t^2)^{n/2}}\sin(n\theta),
\qquad n\geq1,\quad t>0.
}
$$

For instance, when $n=2$,

$$
\int_0^\infty xe^{-tx}\sin x\,dx
=\frac{2t}{(1+t^2)^2}.
$$

The identity extends to real orders $s>0$ with the Gamma function:

$$
\boxed{
\int_0^\infty x^{s-1}e^{-tx}\sin x\,dx
=\frac{\Gamma(s)}{(1+t^2)^{s/2}}
\sin\!\left(s\arctan\frac1t\right),
\quad t>0.
}
$$

This follows by taking imaginary parts of the complex Laplace–Gamma integral $\Gamma(s)(t-i)^{-s}$ (with the principal branch).

**Convergence caution.** The positive-damping condition $t>0$ is essential for the general moment formula. At $t=0$, the ordinary improper integral $\int_0^\infty x^{n-1}\sin x\,dx$ does **not** converge for **any integer $n\geq1$** (including $n=1$, when the integrand is $\sin x$). Although the damped expression has an Abel limit as $t\downarrow0$, that limit is not the value of an ordinary improper integral. The convergent Dirichlet integral instead has the factor $1/x$ and is treated separately above.

### 4.8.6. The Gaussian integral through Feynman's trick

The Gaussian integral is fundamental in probability and mathematical physics:

$$
\boxed{\int_{-\infty}^{\infty}e^{-x^2}\,dx=\sqrt\pi.}
$$

It is commonly computed by squaring the integral and changing to polar coordinates. We instead use a parameterised integral, following the approach discussed by Goldmakher.

### Example 4.25. Evaluating the Gaussian integral without polar coordinates

In [Multivariable calculus]({{ '/pages/mathematics/multivariable_calculus/' | relative_url }}), we will see how to exploite Fubini's theorem, a standard technique to compute the Gaussian integral, but here the goal is to show an alternative version which may be a little unconventional to some.

By symmetry, it is enough to calculate

$$
A=\int_0^\infty e^{-x^2}\,dx.
$$

Introduce the auxiliary family

$$
I(t)=\int_0^\infty\frac{e^{-x^2}}{1+(x/t)^2}\,dx,
\qquad t>0.
$$

As $t\to\infty$, dominated convergence gives $I(t)\to A$. Substitute $x=tu$ to obtain

$$
I(t)=t\int_0^\infty\frac{e^{-t^2u^2}}{1+u^2}\,du.
$$

This expression gives a second useful limit. Since the integrand is bounded by $1/(1+u^2)$,

$$
\begin{aligned}
\lim_{t\downarrow0}\frac{I(t)}t
&=\int_0^\infty\frac{du}{1+u^2}\\[3pt]
&=\left[\arctan u\right]_0^\infty
=\frac\pi2.
\end{aligned}
$$

Rather than differentiate $I(t)$ directly, define a **renormalised integral**

$$
\begin{aligned}
K(t)
&=\frac{e^{-t^2}}{t}I(t)\\[3pt]
&=\int_0^\infty\frac{e^{-t^2(1+u^2)}}{1+u^2}\,du.
\end{aligned}
$$

The advantage is that differentiating removes the denominator:

$$
\begin{aligned}
K'(t)
&=\int_0^\infty
\frac{\partial}{\partial t}
\left(\frac{e^{-t^2(1+u^2)}}{1+u^2}\right)\,du\\[3pt]
&=-2t\int_0^\infty e^{-t^2(1+u^2)}\,du\\[3pt]
&=-2te^{-t^2}\int_0^\infty e^{-t^2u^2}\,du.
\end{aligned}
$$

Making the substitution $v=tu$ in the last integral gives

$$
\int_0^\infty e^{-t^2u^2}\,du
=\frac1t\int_0^\infty e^{-v^2}\,dv
=\frac At.
$$

Thus the parameter derivative simplifies to

$$
\boxed{K'(t)=-2Ae^{-t^2}.}
$$

The boundary values of $K$ are already known:

$$
\lim_{t\downarrow0}K(t)=\frac\pi2,
\qquad
\lim_{t\to\infty}K(t)=0.
$$

The first follows from the limit of $I(t)/t$, and the second from $0\leq K(t)\leq(\pi/2)e^{-t^2}$. Integrate the differential equation over $t\in(0,\infty)$:

$$
\begin{aligned}
K(\infty)-K(0^+)
&=\int_0^\infty K'(t)\,dt\\[3pt]
-\frac\pi2
&=-2A\int_0^\infty e^{-t^2}\,dt\\[3pt]
&=-2A^2.
\end{aligned}
$$

It follows that

$$
A^2=\frac\pi4.
$$

As $A>0$, we conclude that

$$
\boxed{\int_0^\infty e^{-x^2}\,dx=\frac{\sqrt\pi}{2},
\qquad
\int_{-\infty}^{\infty}e^{-x^2}\,dx=\sqrt\pi.}
$$

The method obtains a nonlinear equation for $A$ without using polar coordinates: the unknown Gaussian integral appears on both sides only after a carefully chosen parameter transformation.

---

### Closing perspective

Differentiation under the integral sign offers another way to recognise the structure of a difficult integral. Where integration by parts reverses the product rule and substitution reverses the chain rule, Feynman's trick exploits a **family of integrals** and the derivative with respect to its parameter. It is particularly effective for logarithmic factors, Laplace transforms, oscillatory integrals, and identities involving special functions.

**Chapter summary.** We have developed a collection of methods for integration: inspection, integration by parts, change of variable, partial fractions, power series, complex exponentials, and differentiation under the integral sign. These techniques share a guiding idea: transform the integrand or the integral itself into a form whose structure we understand. Equally important is knowing when a transformation is legitimate, especially when interchanging limits, derivatives, and improper integrals.



## Supporting material

- [Exercises]({{ '/pages/mathematics/real_analysis/05-integral-calculus/04-methods-and-techniques-of-integration/exercises/' | relative_url }})
- [Worked solutions]({{ '/pages/mathematics/real_analysis/05-integral-calculus/04-methods-and-techniques-of-integration/solutions/' | relative_url }})
- [References]({{ '/pages/mathematics/real_analysis/05-integral-calculus/04-methods-and-techniques-of-integration/references/' | relative_url }})

## Subchapter navigation

[Previous: 5.3 - Fundamental Theorem of Calculus]({{ '/pages/mathematics/real_analysis/05-integral-calculus/03-fundamental-theorem-of-calculus/' | relative_url }})

[Back to Chapter 5: Integral Calculus]({{ '/pages/mathematics/real_analysis/05-integral-calculus/' | relative_url }})

[Next: 5.5 - Improper Integrals and Integrability]({{ '/pages/mathematics/real_analysis/05-integral-calculus/05-improper-integrals-and-integrability/' | relative_url }})

</article>

