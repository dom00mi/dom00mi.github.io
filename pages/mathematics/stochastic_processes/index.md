---
layout: default
title: Stochastic Processes
permalink: /pages/mathematics/stochastic_processes/
---

<div class="page-header">
  <a class="back" href="{{ '/pages/mathematics/' | relative_url }}">Back to Mathematics</a>
  <div class="eyebrow">Mathematics / Stochastic Processes</div>
  <h1>Stochastic Processes</h1>
  <p class="lead">A structured progression through random processes, renewal theory, Markov chains, queueing, Monte Carlo methods, filtering, and Brownian motion. (TBD)</p>
</div>

<article class="article" markdown="1">

## Scope and organisation

These notes develop stochastic processes in ten chapters. Each chapter contains linked subchapters, exercises, solutions, and references.

### Chapter 1 - Foundations of Stochastic Processes

- [1.1: Definitions and Examples of Stochastic Processes]({{ '/pages/mathematics/stochastic_processes/01-foundations-of-stochastic-processes/01-definitions-and-examples-of-stochastic-processes/' | relative_url }})
- [1.2: Filtrations Adapted Processes and Stopping Times]({{ '/pages/mathematics/stochastic_processes/01-foundations-of-stochastic-processes/02-filtrations-adapted-processes-and-stopping-times/' | relative_url }})
- [1.3: Markov Property and Process Classification]({{ '/pages/mathematics/stochastic_processes/01-foundations-of-stochastic-processes/03-markov-property-and-process-classification/' | relative_url }})

### Chapter 2 - Renewal Theory and Random Clocks

- [2.1: Renewal Processes and Interarrival Times]({{ '/pages/mathematics/stochastic_processes/02-renewal-theory-and-random-clocks/01-renewal-processes-and-interarrival-times/' | relative_url }})
- [2.2: Elementary Renewal Theorem and Renewal Equations]({{ '/pages/mathematics/stochastic_processes/02-renewal-theory-and-random-clocks/02-elementary-renewal-theorem-and-renewal-equations/' | relative_url }})
- [2.3: Inspection Paradox and Size-Biased Distributions]({{ '/pages/mathematics/stochastic_processes/02-renewal-theory-and-random-clocks/03-inspection-paradox-and-size-biased-distributions/' | relative_url }})
- [2.4: Renewal-Reward Processes and Applications]({{ '/pages/mathematics/stochastic_processes/02-renewal-theory-and-random-clocks/04-renewal-reward-processes-and-applications/' | relative_url }})

### Chapter 3 - Poisson and Counting Processes

- [3.1: Counting Processes and Poisson Process]({{ '/pages/mathematics/stochastic_processes/03-poisson-and-counting-processes/01-counting-processes-and-poisson-process/' | relative_url }})
- [3.2: Exponential Interarrival Times and Memorylessness]({{ '/pages/mathematics/stochastic_processes/03-poisson-and-counting-processes/02-exponential-interarrival-times-and-memorylessness/' | relative_url }})
- [3.3: Superposition Thinning and Coloring]({{ '/pages/mathematics/stochastic_processes/03-poisson-and-counting-processes/03-superposition-thinning-and-coloring/' | relative_url }})
- [3.4: Conditional Arrival Times and Poisson Point Processes]({{ '/pages/mathematics/stochastic_processes/03-poisson-and-counting-processes/04-conditional-arrival-times-and-poisson-point-processes/' | relative_url }})
- [3.5: Compound Poisson and Nonhomogeneous Processes]({{ '/pages/mathematics/stochastic_processes/03-poisson-and-counting-processes/05-compound-poisson-and-nonhomogeneous-processes/' | relative_url }})

### Chapter 4 - Branching and Population Processes

- [4.1: Galton-Watson Branching Processes]({{ '/pages/mathematics/stochastic_processes/04-branching-and-population-processes/01-galton-watson-branching-processes/' | relative_url }})
- [4.2: Generating Functions Extinction and Total Progeny]({{ '/pages/mathematics/stochastic_processes/04-branching-and-population-processes/02-generating-functions-extinction-and-total-progeny/' | relative_url }})
- [4.3: Yule and Pure-Birth Processes]({{ '/pages/mathematics/stochastic_processes/04-branching-and-population-processes/03-yule-and-pure-birth-processes/' | relative_url }})
- [4.4: Birth-Death Processes and Population Models]({{ '/pages/mathematics/stochastic_processes/04-branching-and-population-processes/04-birth-death-processes-and-population-models/' | relative_url }})

### Chapter 5 - Discrete-Time Markov Chains

- [5.1: Markov Chains and Transition Probability Matrices]({{ '/pages/mathematics/stochastic_processes/05-discrete-time-markov-chains/01-markov-chains-and-transition-probability-matrices/' | relative_url }})
- [5.2: Communicating Classes and State Classification]({{ '/pages/mathematics/stochastic_processes/05-discrete-time-markov-chains/02-communicating-classes-and-state-classification/' | relative_url }})
- [5.3: Recurrence Transience and Periodicity]({{ '/pages/mathematics/stochastic_processes/05-discrete-time-markov-chains/03-recurrence-transience-and-periodicity/' | relative_url }})
- [5.4: Hitting Times Return Times and Absorption]({{ '/pages/mathematics/stochastic_processes/05-discrete-time-markov-chains/04-hitting-times-return-times-and-absorption/' | relative_url }})
- [5.5: Stationary Distributions Ergodicity and Reversibility]({{ '/pages/mathematics/stochastic_processes/05-discrete-time-markov-chains/05-stationary-distributions-ergodicity-and-reversibility/' | relative_url }})

### Chapter 6 - Continuous-Time Markov Chains

- [6.1: Continuous-Time Markov Property and Semigroups]({{ '/pages/mathematics/stochastic_processes/06-continuous-time-markov-chains/01-continuous-time-markov-property-and-semigroups/' | relative_url }})
- [6.2: Generator Q-Matrices and Kolmogorov Equations]({{ '/pages/mathematics/stochastic_processes/06-continuous-time-markov-chains/02-generator-q-matrices-and-kolmogorov-equations/' | relative_url }})
- [6.3: Holding Times Jump Chains and Construction]({{ '/pages/mathematics/stochastic_processes/06-continuous-time-markov-chains/03-holding-times-jump-chains-and-construction/' | relative_url }})
- [6.4: Explosion Minimality and Nonexplosive Processes]({{ '/pages/mathematics/stochastic_processes/06-continuous-time-markov-chains/04-explosion-minimality-and-nonexplosive-processes/' | relative_url }})
- [6.5: Long-Run Behaviour Invariant Measures and Detailed Balance]({{ '/pages/mathematics/stochastic_processes/06-continuous-time-markov-chains/05-long-run-behaviour-invariant-measures-and-detailed-balance/' | relative_url }})

### Chapter 7 - Queueing Theory

- [7.1: Queueing Models and MM1 Queues]({{ '/pages/mathematics/stochastic_processes/07-queueing-theory/01-queueing-models-and-mm1-queues/' | relative_url }})
- [7.2: Multi-Server and Finite-Capacity Queues]({{ '/pages/mathematics/stochastic_processes/07-queueing-theory/02-multi-server-and-finite-capacity-queues/' | relative_url }})
- [7.3: Burke's Theorem and Tandem Queues]({{ '/pages/mathematics/stochastic_processes/07-queueing-theory/03-burkes-theorem-and-tandem-queues/' | relative_url }})
- [7.4: Little's Law Balking and Queueing Applications]({{ '/pages/mathematics/stochastic_processes/07-queueing-theory/04-littles-law-balking-and-queueing-applications/' | relative_url }})

### Chapter 8 - Markov Chain Monte Carlo

- [8.1: Markov Chain Sampling and Invariant Distributions]({{ '/pages/mathematics/stochastic_processes/08-markov-chain-monte-carlo/01-markov-chain-sampling-and-invariant-distributions/' | relative_url }})
- [8.2: Metropolis and Metropolis-Hastings Algorithms]({{ '/pages/mathematics/stochastic_processes/08-markov-chain-monte-carlo/02-metropolis-and-metropolis-hastings-algorithms/' | relative_url }})
- [8.3: Gibbs Sampling and Conditional Distributions]({{ '/pages/mathematics/stochastic_processes/08-markov-chain-monte-carlo/03-gibbs-sampling-and-conditional-distributions/' | relative_url }})
- [8.4: Mixing Autocorrelation and MCMC Diagnostics]({{ '/pages/mathematics/stochastic_processes/08-markov-chain-monte-carlo/04-mixing-autocorrelation-and-mcmc-diagnostics/' | relative_url }})

### Chapter 9 - State-Space Models and Stochastic Filtering

- [9.1: Hidden Markov Models and Latent-State Processes]({{ '/pages/mathematics/stochastic_processes/09-state-space-models-and-stochastic-filtering/01-hidden-markov-models-and-latent-state-processes/' | relative_url }})
- [9.2: Forward-Backward Algorithms and Bayesian Filtering]({{ '/pages/mathematics/stochastic_processes/09-state-space-models-and-stochastic-filtering/02-forward-backward-algorithms-and-bayesian-filtering/' | relative_url }})
- [9.3: Linear Gaussian State-Space Models and Kalman Filter]({{ '/pages/mathematics/stochastic_processes/09-state-space-models-and-stochastic-filtering/03-linear-gaussian-state-space-models-and-kalman-filter/' | relative_url }})
- [9.4: Sequential Monte Carlo and Particle Filters]({{ '/pages/mathematics/stochastic_processes/09-state-space-models-and-stochastic-filtering/04-sequential-monte-carlo-and-particle-filters/' | relative_url }})

### Chapter 10 - Brownian Motion and Path Properties

- [10.1: Brownian Motion Construction and Path Properties]({{ '/pages/mathematics/stochastic_processes/10-brownian-motion-and-path-properties/01-brownian-motion-construction-and-path-properties/' | relative_url }})
- [10.2: Strong Markov Property Reflection and Zero-One Laws]({{ '/pages/mathematics/stochastic_processes/10-brownian-motion-and-path-properties/02-strong-markov-property-reflection-and-zero-one-laws/' | relative_url }})

## Navigation

[Stochastic Processes overview page]({{ '/pages/mathematics/stochastic_processes/overview/' | relative_url }})

[Back to Mathematics]({{ '/pages/mathematics/' | relative_url }})

TBD

</article>
