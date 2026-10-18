---
layout: default
title: Research & Collaboration
permalink: /pages/collaboration/
---
<div class="page-header"><a class="back" href="{{ '/' | relative_url }}">← Back to home</a><div class="eyebrow">Domenico Nava / Research</div><h1>Research & Collaboration</h1><p class="lead">Discuss research, request access and explore selected private work.</p></div><div class="page-image"><img src="https://images.openai.com/static-rsc-4/9DbEyNDlz9M6x19wiz8DZaQjAzRO2N5cXz_70NUBFtDCIvlaCJtMNwejn1UTG0tIamnRWYORDisPzDs5S7hRSVWsAr4qDmp77Mr45ht1bhhh3dGBi3OQXp3ybWsv9_VjCdDk80_iELSCBJBIaaakd4Pfy63m-TN7ZKow9wNUzjo?purpose=inline" alt="Research & Collaboration banner" onerror="this.style.display='none'"></div><article class="article" markdown="1">
## Let's collaborate

Some repositories contain work that I am still refining or have chosen not to publish openly. If you are interested in discussing a project, reviewing selected code, or collaborating, **[send me an email](mailto:domenico.nava.dn@gmail.com)** or contact me through [GitHub](https://github.com/dom00mi).

Please mention the topic or repository you're interested in and whether you want to **browse the code** or **collaborate**.

## Option 1 — View a private repository in your browser

**No SSH key is required.**

1. Send me your **GitHub username** and the project you're interested in.
2. If access is appropriate, I'll send you a GitHub repository invitation.
3. Accept the invitation while signed in to GitHub.
4. Browse the files, README, notebooks and documents directly on github.com.

**Permissions note:** For private repositories owned by a personal GitHub account, collaborators generally receive read/write permissions rather than a strictly read-only viewer role. For a strict **Read** role, an organization-owned repository is more appropriate.

## Option 2 — Clone after access is granted

You can clone over **HTTPS** without setting up SSH:

```bash
git clone https://github.com/dom00mi/REPOSITORY-NAME.git
```

If Git prompts for authentication, use a supported GitHub authentication method (for example, Git Credential Manager or GitHub CLI). Your GitHub account must have access to the repository.

## Option 3 — Use SSH for development

SSH is optional, but convenient for command-line Git workflows.

1. Generate an SSH key locally:

   ```bash
   ssh-keygen -t ed25519 -C "your-github-email@example.com"
   ```

2. Copy the **public** key (`~/.ssh/id_ed25519.pub`):

   - macOS: `pbcopy < ~/.ssh/id_ed25519.pub`
   - Linux: `cat ~/.ssh/id_ed25519.pub`
   - Windows PowerShell: `Get-Content ~/.ssh/id_ed25519.pub | Set-Clipboard`

3. On GitHub, open **Settings → SSH and GPG keys → New SSH key**, paste the public key and save it.
4. After accepting my invitation, clone the repository:

   ```bash
   git clone git@github.com:dom00mi/REPOSITORY-NAME.git
   ```

**Never share your private SSH key.** Only the `.pub` file is intended to be shared or uploaded.

## Automated access

For CI/CD or servers, repository-specific **deploy keys** may be appropriate. They are distinct from human collaborator invitations and should be configured separately under the repository's **Settings → Deploy keys**.

## Contact

**Email:** [domenico.nava.dn@gmail.com](mailto:domenico.nava.dn@gmail.com)  
**GitHub:** [@dom00mi](https://github.com/dom00mi)

</article>
