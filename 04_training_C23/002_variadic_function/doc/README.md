Fixed. All math blocks now use proper `$$ ... $$` block-math delimiters (10 lines = 5 matched pairs), with no stray single `$`, `----` rules, or dangling `]`/`[` left over.

What was wrong:
- Block math used single `$` on its own line — GitHub only renders block math with `$$` delimiters.
- Some blocks were malformed mid-formula (a stray `$` after `{n}`, a `--------------------` line, a `]`, and a `[...]` pair that should have been `$$`).

The 5 formulas fixed:
1. **§13** — population SD via `E[X²]−E[X]²` form
2. **§16** — mean `(25.0+27.3+26.9+25.7)/4 = 26.225`
3. **§20** — `E[X^2] − E[X]^2`
4. **§21** — population SD `σ = √(Σ(xᵢ−μ)²/N)`
5. **§21** — sample SD `s = √(Σ(xᵢ−x̄)²/(N−1))`

Each `$$` block is on its own line with blank lines around it, which is what GitHub's MathJax renderer requires to pick it up.
