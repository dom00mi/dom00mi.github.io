---
layout: default
title: Mathematics
permalink: /pages/mathematics/
---
<div class="page-header"><a class="back" href="{{ '/' | relative_url }}">← Back to home</a><div class="eyebrow">Domenico Nava / Research</div><h1>Mathematics</h1><p class="lead">An evolving collection of mathematical notes, derivations and presentations.</p></div><div class="page-image"><img src="https://images.openai.com/static-rsc-4/FccF36olN0Yq7LCsdaiNHbAACfTnXS2DZUQqrFnJZFM-O2WeP6JBw5K5oCxyrNqtM0ApdN9Mdq3vpzV7tY13lUN4hDup7ZsVgp1l14KdtjAxa_H6HKj6WUaSXQ1loEmWl0rceUWVuYA9bimjWG1UyXwd6Md-gWjEDcgGX9_th5A?purpose=inline" alt="Mathematics banner" onerror="this.style.display='none'"></div><article class="article" markdown="1">
## A growing mathematical notebook

This section will collect **LaTeX-style explanations, detailed READMEs, PDF lecture notes, presentations and computational notebooks**. Many topics are still being written or revised.

<div class="note"><strong>Work in progress.</strong> Content and repository links will appear as notes and supporting code are ready for publication.</div>

## Topics in preparation

| Area | Planned material | Status |
|---|---|---|
| Stochastic Calculus | Itô calculus, stochastic differential equations | TBD |
| Probability & Stochastic Processes | Models, proofs and simulations | TBD |
| Numerical Analysis | Numerical schemes, error and convergence | TBD |
| Partial Differential Equations | Analytical and numerical methods | TBD |
| Optimisation | Theory and computational examples | TBD |

## Mathematical typesetting

This website supports LaTeX-style equations through MathJax. For example, the Itô process

$$
dX_t = \mu(t,X_t)\,dt + \sigma(t,X_t)\,dW_t
$$

can be rendered directly in Markdown.

## Notes and presentations

- **Research notes (PDF)** — Coming soon
- **Mathematical presentations (PDF)** — Coming soon
- **Worked derivations and notebooks** — Coming soon

### Adding a new topic

Add a Markdown link to a repository:

```markdown
- [Numerical Methods](https://github.com/dom00mi/YOUR-REPO) — implementations and notes.
```

Add a PDF file under `assets/pdfs/`, then link it:

```markdown
[Read the PDF]({{ '/assets/pdfs/numerical-methods.pdf' | relative_url }})
```

</article>
