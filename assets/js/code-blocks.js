
document.addEventListener("DOMContentLoaded", () => {
    const blocks = document.querySelectorAll(".cpp-code");

    blocks.forEach((block) => {
        const pre = block.querySelector("pre");

        if (!pre) return;

        // Create the filename toolbar
        const toolbar = document.createElement("div");
        toolbar.className = "cpp-code-toolbar";

        const filename = document.createElement("span");
        filename.className = "cpp-code-filename";
        filename.textContent =
            block.dataset.filename || "C++ Implementation";

        // Create Copy button
        const copyButton = document.createElement("button");
        copyButton.type = "button";
        copyButton.className = "cpp-code-copy";
        copyButton.textContent = "Copy";
        copyButton.setAttribute(
            "aria-label",
            "Copy " + filename.textContent
        );

        // Copy the actual source code
        copyButton.addEventListener("click", async () => {
            const code = pre.querySelector("code") || pre;
            const source = code.textContent;

            try {
                await navigator.clipboard.writeText(source);
                copyButton.textContent = "Copied!";
            } catch (error) {
                console.error("Copy failed:", error);
                copyButton.textContent = "Copy failed";
            }

            window.setTimeout(() => {
                copyButton.textContent = "Copy";
            }, 1800);
        });

        toolbar.appendChild(filename);
        toolbar.appendChild(copyButton);

        block.prepend(toolbar);
    });
});
