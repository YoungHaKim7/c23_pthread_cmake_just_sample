- Fixed and building clean. What was wrong:

**The error** — with `-pedantic-errors`, ISO C requires a translation unit to contain at least one declaration. The old file was *only* preprocessor directives (`#if`, `#define`, `#endif`), so `-Wempty-translation-unit` fired as an error. Adding `main` fixes it.

**The examples added** (`src/main.c`):
1. **`#elifdef` / `#elifndef`** (C23 shortcuts) — two chained blocks showing which branch wins:
   - `FOO` defined → first `#if` branch taken
   - after `#undef FOO` with `BAR`/`BAZ` undefined → the `#elifndef BAZ` branch taken
2. **`#warning`** — a compile-time diagnostic that doesn't stop compilation (the classic "VERSION not defined, defaulting to X" fallback pattern), visible in the build output above.

Remaining warnings are intentional — they're the demo itself (`#warning` printing at compile time) plus the harmless `-lm` linker-input note from your CMake flags.
