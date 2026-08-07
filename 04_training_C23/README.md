# link

- P99 is a suite of macro and function definitions that ease the programming in C99, aka C 1999. By using new tools from C99 we implement default arguments for functions, scope bound resource management, transparent allocation and initialization, ...
  - https://gitlab.inria.fr/gustedt/p99

<hr />

# C23
- https://cppreference.com/c/23

- `constexpr`
  - https://en.cppreference.com/c/language/constexpr

# 잘 정리된 Github
- A cheatsheet of modern C language and library features.
  - https://github.com/AnthonyCalandra/modern-c-features

# 잘 정리된 외국 Blog
- https://simplifycpp.org/articles/a0583/what-s-new-in-the-c23-standard-for-the-c-programming-language/

# 장 정리된 유튜브 영상
- [231206) What's new and what's changed in C23 - Jarosław Stańczyk - code::dive 2023 | code::dive conference](https://youtu.be/ivl84xCeVFs?si=uNrDHCvt-tX20FSA)

# Google Gemini가 정리 AI
- C23 is a major revision to the C23 (C standard revision) programming language standard, introducing modern additions like `nullptr`, binary literals, digit separators, `constexpr`, `typeof`, C++-style attributes (`[[deprecated]]`, etc.), and the `#embed` preprocessor directive for resource inclusion.


## New Language and Syntax Features

- `nullptr`: A dedicated null pointer constant and type (`nullptr_t`) replacing widespread NULL macro ambiguities.

- Binary Literals and Digit Separators: Support for `0b/0B` prefixes (e.g., `0b1010`) and single quotes as digit separators (e.g., `1'000'000`).

- `constexpr`: Allows defining compile-time constant objects.

- `typeof` and `typeof_unqual`: Standardized compile-time type inference operators.

- Bit-precise integers: Added `_BitInt(N)` and unsigned variants for exact bit-width control.

- Attributes: Standardized attributes like`[[deprecated]]`, `[[fallthrough]]`, `[[nodiscard]]`, and `[[maybe_unused]]`.

- Keywords promoted from macros: `true`, `false`, `static_assert`, and `thread_local` are now real keywords.

- Empty initializers: Permits `= {}` to zero-initialize structures and arrays.

## Preprocessor and Library Updates
- `#embed`: A new directive to embed binary files or raw data directly into arrays at compile time.

- New Preprocessor Directives: Added `#elifdef`, `#elifndef`, and `#warning`.

- Safe Overflow Arithmetic: Introduced standard macros like `ckd_add()`, `ckd_sub()`, and `ckd_mul()` in a new or extended context to check for integer overflows safely.

- Enumerations: Allowed specifying underlying types for `enum` declarations.
