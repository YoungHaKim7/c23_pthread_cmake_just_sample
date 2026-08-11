# link

- P99 is a suite of macro and function definitions that ease the programming in C99, aka C 1999. By using new tools from C99 we implement default arguments for functions, scope bound resource management, transparent allocation and initialization, ...
  - https://gitlab.inria.fr/gustedt/p99

- https://inria.hal.science/hal-02383654/document

- C23 snippets
  - code examples of some of the new features added in C23
    - https://github.com/skig/c23_snippets

<hr />

# C23돌리기 위한 컴파일러 버젼

```
# 15버젼이상
gcc

# 20버젼이상(추천은 22버젼 추천드림)
clang


$ /opt/gcc-15/bin/gcc --version
gcc (GCC) 15.1.0
Copyright (C) 2025 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.



$ clang --version
Ubuntu clang version 21.1.8 (++20251221032922+2078da43e25a-1~exp1~20251221153059.70)
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/lib/llvm-21/bin
```

## 기본 컴파일 패턴 `-std=c23` 이건 꼭 넣어줘야함. 뒤에 옵션은 안 넣어도 돌아가긴함.

- 최대한 꼼꼼히 체크하고 싶다면 뒤에 옵션 다 넣어주세요.

```bash
$ /opt/gcc-15/bin/gcc -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror ./src/main.c

```


~


# (유료 책) Jens Gustedt
Modern C, Third Edition: Covers the C23 standard
- https://www.amazon.com/Modern-Third-Covers-C23-standard-ebook/dp/B0FP5LXVCK/
- 레딧을 통해 알게 됨
  - https://www.reddit.com/r/cprogramming/comments/1ncgn8d/modern_c_third_edition_practical_guide_to_writing/?solution=079085122da35749079085122da35749&js_challenge=1&token=7afd7253fec22262ff1c52b1703fe9ec3eb0157bb91e74d8f12d235da611afdf&jsc_orig_r=

- manning에서 직접 구매가 더 싸다
https://www.manning.com/books/modern-c-third-edition?utm_campaign=21635480-book_gustedt2&utm_source=reddit&utm_medium=social


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
