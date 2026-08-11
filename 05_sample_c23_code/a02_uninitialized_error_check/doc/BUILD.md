# build
 
Got the full picture now. Your "not check uninitialized" had **two separate causes**, and the second one is the real story:

## 1. The build was blocked (fixed)
`-Werror` turned the unused `argv` into a hard error, so the compiler quit before reaching uninitialized analysis. Added `(void)argv;` — your regular compile now passes cleanly.

## 2. The real problem: Clang's `-Wsometimes-uninitialized` doesn't fire on a `switch` without `default`
Even with the build fixed, Clang emits **zero** warnings at `-O0/-O1/-O2/-O3`. I verified this is intrinsic to the warning, not your code:
- The identical logic written with `if` → **warns** correctly.
- The identical logic written with `switch` (no `default`) → **silent**.

`gcc -Wmaybe-uninitialized` (gcc 16.1.1) also didn't catch it. Warning-based detection simply doesn't trace the "no case matched" path of a `switch`.

## The fix: use Clang's static analyzer, not the warning flag
`clang --analyze` (the Clang Static Analyzer) traced the `Default` branch and nailed it:

```
src/main.c:24:5: warning: 2nd function call argument is an uninitialized value [core.CallAndMessage]
   24 |     printf("the temp is %u\n", tmp);
src/main.c:12:5: note: 'Default' branch taken. Execution continues on line 24
```

**Build command to actually detect the bug:**

```bash
/usr/bin/clang --analyze -std=c23 -Xanalyzer -analyzer-output=text src/main.c
```

Note: don't combine this with your `-Werror` compile line — `--analyze` is a *separate* pass (it doesn't produce a binary), so you run it *alongside* your normal compile, not as a replacement:

```bash
# regular compile (produces the binary)
/usr/bin/clang -std=c23 -Wall -Wextra -pedantic -Werror -O1 -ggdb -o ./target/a02_uninitialized_error_check src/main.c
# analysis pass (catches what -Wsometimes-uninitialized can't)
/usr/bin/clang --analyze -std=c23 -Xanalyzer -analyzer-output=text src/main.c
```

## Bottom line
- To make the **`-Wsometimes-uninitialized` flag itself** trigger on this demo, you'd have to rewrite the `switch` as an `if/else` chain — that's the only construct it analyzes.
- To keep your `switch` demo and still get caught, use `clang --analyze` (or install `cppcheck`, which isn't on your system).

Want me to update the source comments to reflect that this demo needs `--analyze` rather than `-Wsometimes-uninitialized`, so the file stays accurate?
