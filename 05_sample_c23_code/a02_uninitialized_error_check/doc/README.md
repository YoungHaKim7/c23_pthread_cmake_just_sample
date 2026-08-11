Done. The example now deliberately fails to compile with the exact diagnostic you wanted.

## What I changed

**`src/main.c`** — a clean `switch` where `tmp` is declared uninitialized and only set in `case 0` / `case 1`, with **no `default`**. The selector (`argc`) isn't known at compile time, so when no case matches the variable is read indeterminate:

```c
unsigned tmp;                       // not initialized
switch ((unsigned)argc) {
    case 0: tmp = 0; break;
    case 1: tmp = 1; break;
    // no default → tmp unset for argc >= 2
}
printf("the temp is %u\n", tmp);   // error: 'tmp' may be used uninitialized
```

**`CMakeLists.txt`** — added two flags to make the build actually fail:
- `-Werror=maybe-uninitialized` — promotes the warning to an error.
- `-O1` — **the gotcha.** GCC's *"may be"* analysis only runs at `-O1`+; at `-O0` (the default Debug build) it's silently skipped, which is why the first attempt built clean.

## Verified output

```
src/main.c:23:5: error: 'tmp' may be used uninitialized [-Werror=maybe-uninitialized]
   23 |     printf("the temp is %u\n", tmp);
src/main.c:7:14: note: 'tmp' was declared here
    7 |     unsigned tmp;
```

I also rewrote the `README.md` (it held leftover Heron's-formula placeholder text from a07) with the real output and a bilingual EN/KO explanation of the three CMake knobs.

One note worth keeping in mind: `-Wmaybe-uninitialized` is GCC-specific (it's in `-Wall` for GCC but Clang has no equivalent flag — Clang uses `-Wsometimes-uninitialized` and reports it differently). Since this project targets GCC 15, that's fine here.

# build

- This project uses **`just`** as its task runner, backed by CMake + Ninja and direct clang invocations. Here are the main ways to build.

## 1. `just` recipes (primary)

| Command                  | What it does                                                                |
| ------------------------ | --------------------------------------------------------------------------- |
| `just r`                 | clang **debug** build (`-Wall -Wextra -Werror`), formats first, **runs** it |
| `just ro`                | clang **optimized** build (`-O2`), **runs** it                              |
| `just cr`                | **CMake + Ninja** Debug build, **runs** it                                  |
| `just cro` / `just cro3` | CMake RelWithDebInfo (`-O2`) / Release (`-O3`), **runs**                    |
| `just b`                 | clang debug build, compile only (no run)                                    |
| `just clean`             | remove `target/`, build files, artifacts                                    |

So the usual loop is simply:

```bash
just r
```

## 2. CMake directly

```bash
cmake -S . -B build && cmake --build build
```

## 3. Direct clang

```bash
clang -std=c23 -Wall -Wextra -pedantic -pedantic-errors -ggdb -o target/b33_multiple_selection_switch src/main.c
```

---

## ⚠️ Heads up: this example is *deliberately broken*

Per `README.md`, `src/main.c` is a teaching example that **won't compile** under the default flags. It's a `switch` with no `default` that leaves `tmp` uninitialized on some paths, then reads it. The build config promotes this to a hard error:

```
src/main.c:23:5: error: 'tmp' may be used uninitialized [-Werror=maybe-uninitialized]
```

That failing build **is** the intended result. If you want it to compile anyway (e.g. to inspect other behavior), drop `-Werror` and `maybe-uninitialized` promotion — `just b` uses `ldflags_debug` which has **no `-Werror`**, so that one will succeed:

```bash
just b && ./target/b33_multiple_selection_switch
```

Want me to run a build now so you can see the result?
