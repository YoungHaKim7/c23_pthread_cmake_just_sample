Fixed and building clean. Output: `42 42 hello 1 1`.

Two changes:

1. **`auto *p = &x;` → `auto p = &x;`** — In C23, `auto` type inference only applies to declarations with a plain identifier (optionally with trailing attributes). Writing `auto *p` or `auto p[10]` is a Clang extension, rejected under `-pedantic-errors`. The pointer type is fully inferred from the initializer, so no `*` is needed.

2. **Used the previously-unused variables** in the printf (`*p`, `ptr == nullptr`) to clear the `-Wunused-variable` warnings.

The new diagnostics you saw in the editor (implicit int, undeclared `nullptr`/`bool`) come from clangd analyzing the file without the `-std=c23` flag from your compile commands — the actual build with `clang -std=c23` passes fine.
