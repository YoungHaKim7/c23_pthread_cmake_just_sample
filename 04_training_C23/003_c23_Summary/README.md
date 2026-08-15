Tell me about the new grammar in C23.

Tell me about new grammar in C23. Provide overview.

C23 is ISO/IEC 9899:2024, the latest C standard. It was officially published in June 2024 and is a major update after C17 from 2018.

The biggest theme is modernization and safety, plus borrowing useful ideas from C++ and fixing long-standing pain points.

Here are the major new features and grammar changes:

### 1. Core Language Modernization

**`#embed` Directive**
A new preprocessing directive to embed binary data directly into the object file at compile time.
```c
    // Embed the whole file as bytes
    unsigned char logo[] = {
#embed "logo.png"
    };

```
It replaces the need for external tools to convert binary files to C arrays.

**`constexpr` and `consteval` concepts for expressions**
* `constexpr` functions: Functions that can be evaluated at compile time if called with constant expressions. Similar to C++ `constexpr`.
```c
constexpr int kAnswer = 42;
static_assert(kAnswer == 42);
```
* `consteval` functions: Functions that *must* be evaluated at compile time.

**`nullptr`**
A null pointer constant `nullptr` is now a keyword, with type `nullptr_t`. It is preferred over `NULL`/`0` for pointers.

**`bool` as a first-class type**
`bool`, `true`, and `false` are now standard keywords in `<stdbool.h>` is still provided but they are part of core language. `_Bool` remains.

**Digit separators**
Underscores can be used in numeric literals for readability, like C++.
```c
int a = 1'000'000;
int b = 0b1010'1100; // 172
unsigned long long c = 0xFF'EC'12'34'56;
double d = 0x1.ffffp+4; // hex floating
```

**Binary literals**
`0b` and `0B` prefixes for binary integers are now standard.
```c
0b1010'1100; // 172
```

**Hexadecimal floating point**
`0x1.ffffp+4` style is now fully standardized.

### 2. Type System and Declarations

**`auto` type inference**
`auto` can now be used as a storage class specifier for type deduction, like C++.
```c
auto x = 42; // int
auto p = &x; // int* — no '*' allowed: C23 auto infers from the initializer
```
It does not support reference types.

**`typeof` and `typeof_unqual`**
Standardized extensions. `typeof(expr)` gives the type of an expression. `typeof_unqual` removes qualifiers.
```c
typeof(x) y = x;
```

**Attributes**
The `[[attribute]]` syntax from C++ is now standard for C. Attributes are now a first-class part of the grammar.
```c
[[nodiscard]] int get_value(void) { return 7; }

[[deprecated("use new_api")]]
void old_api(void) {}
```
Standard attributes include `nodiscard`, `deprecated`, `fallthrough`, `maybe_unused`, `reproducible`, etc.

**Flexible array members improvements**
Designated initializers can now initialize flexible array members.

### 3. Safety and Security

**`#warning` directive**
A standard way to emit a warning from source code.
```c
// C23 preprocessor additions: #warning, #elifdef, #elifndef
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#warning "You are using C23"
#endif
```

**`static_assert` is now a keyword**
`static_assert` was previously a macro in `<assert.h>`. It is now a built-in keyword.

- Code ExamplesBefore C23 (C11 / C17)
```c
#include <assert.h> // Required for lowercase "static_assert" macro

_Static_assert(sizeof(int) == 4, "Integers must be 4 bytes"); // Message required
```

- In C23
```c
// No #include <assert.h> required!

// Two-argument syntax still works
static_assert(sizeof(void*) == 8, "64-bit architecture required");

// New single-argument syntax (cleaner)
static_assert(sizeof(int) == 4); 
```

**Trailing commas in declarations and initializers**
Trailing commas are now allowed in struct initializers, enum declarations, parameter type lists, and macro parameter lists. This makes diffs cleaner.

**`_BitInt`**
Arbitrary precision integer types. `_BitInt(N)` is an integer type with at least N bits.
```c
_BitInt(128) big = 0;
```

### 4. Library Additions

C23 adds several new headers and functions:

* `<stdckdint.h>` - Checked integer arithmetic. `ckd_add`, `ckd_mul` etc. that detect overflow.
* `<stdbit.h>` - Bit manipulation functions: `stdbit_ffs`, `stdbit_popcount`, `stdbit_leading_zero`, etc.
* `<stdalign.h>` improvements and `alignas`/`alignof` are now keywords.
* `<string.h>` additions: `memset_explicit`, `memcpy_s` family is now standardized in Annex K.
* `<time.h>` additions: `timespec_getres`, `nanosleep`.
* `nullptr_t` and `nullptr` in `<stddef.h>`.

**`alignas` and `alignof` as keywords**
No longer just macros. They are now part of the core grammar.

### 5. Preprocessor and Compatibility

**`#elifdef` and `#elifndef`**
Shortcuts for `#elif defined MACRO`.

**Hexadecimal character constants**
`\x` sequences in character constants can now be longer than one byte, and are implementation-defined.

**Removed trigraphs**
Trigraphs are finally removed from the standard. They were deprecated for decades.

**`__VA_OPT__`**
Variadic macro support is now standardized, allowing optional commas in variadic macros.

**`__has_include`**
The feature test macro `__has_include` is now standard for conditional inclusion of headers.

### 6. Other notable grammar changes

* **Compound literals can be used in more contexts**
* **Anonymous structures and unions** are now fully supported without implementation-defined behavior.
* **Improved designated initializers**: Designators can now be mixed with non-designated initializers in a more flexible way, and range designators are allowed in some implementations.
* **`_Atomic` improvements**: Atomic types are now more consistently handled.

### Summary

C23 is not a revolutionary rewrite like C99 was, but a very practical modernization. The biggest wins are:

* **Compile-time programming**: `constexpr`, `consteval`, `static_assert` as keyword
* **Safety**: `nullptr`, `[[nodiscard]]`, checked arithmetic, `memset_explicit`
* **Usability**: `auto`, digit separators, binary literals, `#embed`, trailing commas
* **Standardization**: Attributes, `alignas`/`alignof`, `typeof`

Adoption is ongoing in 2025-2026. GCC 13+, Clang 17+, and MSVC have partial support. Many features are enabled with `-std=c23`.

Do you want a focused example of a specific feature, like `constexpr` or `#embed` in practice?<|eot|>
