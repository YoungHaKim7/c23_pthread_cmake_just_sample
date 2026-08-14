Fixed and verified — builds clean and runs.

**What was wrong:** `constexpr` functions and `consteval` don't exist in C23. C23's `constexpr` is much narrower than C++'s — it can only qualify **variable declarations** with an integer constant expression initializer. It cannot qualify functions, and `consteval` is a C++20 keyword that C never adopted.

**The fix** (`src/main.c`):
- `square` / `compile_time_id` → macros (`#define SQUARE(x) ((x) * (x))`), so `static_assert(SQUARE(5) == 25)` works — macros expand to integer constant expressions
- `factorial` → a plain runtime function (a function call is never a constant expression in C), plus kept a `constexpr int kAnswer = 42` to demonstrate the real C23 `constexpr` variable feature
- Added comments explaining the C-vs-C++ distinction, which seems to be the point of this training sample

Note: the IDE diagnostics shown for `main.c` ("Unknown type name 'constexpr'") come from clangd parsing with a pre-C23 standard — the actual build with `-std=c23` compiles fine. Also, your `justfile`/CMakeLists passes `-lm` during compilation (`C_FLAGS` instead of link libraries), which triggers the harmless `-Wunused-command-line-argument` warning; moving it to `target_link_libraries` would silence it.
