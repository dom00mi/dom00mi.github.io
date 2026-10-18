# Deploy this Jekyll site on GitHub Pages

1. Sign in to GitHub and create a **public** repository named exactly `dom00mi.github.io` under the `dom00mi` account.
2. Upload **all contents** of this folder to the repository root, preserving `_layouts/`, `assets/` and `pages/`. Do not upload only the ZIP.
3. Open **Settings → Pages → Build and deployment**. Choose **Deploy from a branch**, branch **main**, folder **/(root)**, and save.
4. Wait for GitHub Pages to build, then open **https://dom00mi.github.io**. If GitHub Pages shows a different workflow, follow the settings presented there.
5. Edit any Markdown file in `pages/` and commit changes to update your site.

## Images

The page images use the **five exact remote image URLs provided in the conversation**. They are not embedded in this ZIP because the image host could not be downloaded from the creation environment. If those temporary links stop working or you do not have reuse rights, replace them with image files you own or are licensed to use:

1. Save images to `assets/images/`, e.g. `mathematics.jpg`.
2. In `pages/mathematics.md`, replace the remote `src="https://..."` with `src="{{ '/assets/images/mathematics.jpg' | relative_url }}"`.
3. Repeat for the homepage (`index.html`) and other pages. The CSS already provides a gradient fallback if a picture fails.

## Adding a repository

In a category page, replace a `Coming soon` or `TBD` cell with `[View repository](https://github.com/dom00mi/REPOSITORY-NAME)`.

## Adding a PDF

Upload your PDF to `assets/pdfs/`, then add `[Read notes]({{ '/assets/pdfs/filename.pdf' | relative_url }})` to a Markdown page.

## LaTeX equations

MathJax is loaded in `_layouts/default.html`. Use `$$ ... $$` for display equations in Markdown.

## Notes

- Private repository invitations are handled in GitHub, not by this website.
- The website itself is public. Never commit private research, secrets, or confidential documents to this repository.
- Site design uses no paid theme or build service.
