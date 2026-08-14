Fixed and verified — `1000000 172 ffec123456 31.9998` prints correctly.

The bug: C23 adopted the digit separator from C++14 but as the **apostrophe** `'`, not underscore. `1_000_000` is C++-only syntax; in C23 an identifier can't start with a digit, so `_000_000` parsed as an invalid suffix.

One caveat: the IDE diagnostics still flag the `'` separators because clangd is parsing the file without `-std=c23` (it doesn't see your CMake flags since no `compile_commands.json` is exported). If that bothers you, add a `.clangd` file:

```yaml
CompileFlags:
  Add: [-std=c23]
```

or enable `CMAKE_EXPORT_COMPILE_COMMANDS=ON` in your CMakeLists.txt so clangd picks up the real flags. Want me to add either?
