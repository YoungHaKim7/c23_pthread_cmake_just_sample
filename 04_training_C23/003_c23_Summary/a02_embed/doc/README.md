Builds and runs. What was wrong and what changed:

1. **`as` isn't a C23 parameter** — it was in early `#embed` drafts but the standard only defines `limit`, `prefix`, `suffix`, and `if_empty`. Removed both `as uint8_t` and `as char` (embed expands to integer constants, which fit any array type — no cast needed).
2. **`const char *msg = {...}`** — a brace list can't initialize a pointer; changed it to an array `const char msg[]` with `suffix(,)` so a trailing `0` (NUL terminator) can be appended after the embedded bytes.
3. **Missing files** — `#embed` resolves paths relative to the including source file, so I created `src/logo.png` (a 1×1 PNG, 70 bytes) and `src/hello.txt` (15 bytes).

Output:
```
Embedded 70 bytes
msg: 15 bytes: Hello, #embed!
```

One unrelated note: `-lm` is in your compile flags (`add_compile_options` in CMakeLists.txt) rather than `target_link_libraries`, hence the "linker input unused" warning — move it to the link step if you want it gone.
