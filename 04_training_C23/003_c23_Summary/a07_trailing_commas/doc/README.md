Done — `src/main.c` now has a working `main` example, builds clean under `-std=c23 -pedantic -pedantic-errors -Wall -Wextra`, and runs.

**What was wrong with the old file:** `struct Point { int x, int y, };` is a syntax error — struct members are separated by `;`, and there's no trailing-comma allowance there. It also had no `main`, which breaks with `-pedantic-errors` (empty translation unit, same issue noted in a06's doc).

**The example now covers** (verified against GCC, not just the README):

Legal trailing commas:
1. **Enum enumerator lists** — `enum Color { RED, GREEN, BLUE, }` (legal since C99), plus a C23 `enum Flags : unsigned` with fixed underlying type
2. **Initializer lists** — designated `.x = 1, .y = 2,` and nested array initializers
3. **Attribute lists** — `[[deprecated("..."),]]` (confirmed GCC accepts this)

Illegal (documented as comments, since they'd break the build):
- struct/union member lists (the original bug)
- function parameter lists in declarations/calls — the course README's claim that C23 allows these is **wrong**; [cppreference's C23 feature table](https://en.cppreference.com/w/c/23) has no such change (that's a [C++26/C2Y discussion](https://www.open-std.org/jtc21/sc22/wg21/docs/papers/2025/p3776r0.html), not C23)
- fixed-arity macro calls — `SUM3(1, 2, 3,)` passes an empty 4th argument; I hit this error myself in the first draft before correcting it

Sources: [cppreference C23](https://en.cppreference.com/w/c/23), [P3776 "More trailing commas"](https://www.open-std.org/jtc21/sc22/wg21/docs/papers/2025/p3776r0.html)

You may want to update `doc/README.md` — it still describes the broken original.
