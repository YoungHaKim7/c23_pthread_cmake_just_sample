Fixed and building clean. Output confirms both alignments work:

```
alignof Vec4 = 32
&buffer % 16 = 0, buffer[0] = 0
```

Two issues fixed in `src/main.c`:

1. **`struct alignas(32) Vec4` → alignment moved to the member** (`src/main.c:5`). In C23, `alignas` is an alignment-specifier that goes in declaration-specifiers — it can't sit between `struct` and the tag (that slot only accepts attribute specifiers like `[[...]]`), so Clang parsed it as an anonymous struct. The standard way to align a struct type is to align its member; the struct's alignment is then the max of its members'.
2. **`alignof(buffer)` → `(uintptr_t)&buffer % 16`**. `alignof` on an expression is a GNU extension and rejected under `-pedantic-errors`; ISO C only allows it on types. Taking the address modulo 16 demonstrates the `_Alignas(16)` effect portably.

Also note your `justfile` passes `-lm` at compile time, hence the harmless `linker input unused` warning — that flag belongs in link options.
