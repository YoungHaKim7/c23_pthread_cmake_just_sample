In C23 (as in C99/C11/C17), the portable way to print fixed-width integer types such as `int8_t` is to use the format macros from `<inttypes.h>`, such as `PRId8`, `PRIu32`, `PRIx64`, etc. These macros automatically expand to the correct format specifier for the implementation. ([Cppreference][1])

## Example: `int8_t` and `uint8_t`

```c
// C23
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    int8_t  a = -42;
    uint8_t b = 200;

    printf("a = %" PRId8 "\n", a);
    printf("b = %" PRIu8 "\n", b);
    printf("b = 0x%" PRIx8 "\n", b);

    return 0;
}
```

Example output:

```text
a = -42
b = 200
b = 0xc8
```

---

## Common fixed-width integer specifiers

| Type      | Decimal  | Unsigned | Octal    | Hex (lower) | Hex (upper) |
| --------- | -------- | -------- | -------- | ----------- | ----------- |
| `int8_t`  | `PRId8`  | `PRIu8`  | `PRIo8`  | `PRIx8`     | `PRIX8`     |
| `int16_t` | `PRId16` | `PRIu16` | `PRIo16` | `PRIx16`    | `PRIX16`    |
| `int32_t` | `PRId32` | `PRIu32` | `PRIo32` | `PRIx32`    | `PRIX32`    |
| `int64_t` | `PRId64` | `PRIu64` | `PRIo64` | `PRIx64`    | `PRIX64`    |

These macros are defined in `<inttypes.h>`. ([Cppreference][1])

---

## Reading values with `scanf`

Use the corresponding `SCN` macros.

```c
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    int8_t value;

    printf("Enter a number: ");

    if (scanf("%" SCNd8, &value) == 1)
        printf("You entered %" PRId8 "\n", value);

    return 0;
}
```

---

## Printing several fixed-width integers

```c
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    int8_t   i8  = -100;
    int16_t  i16 = -32000;
    int32_t  i32 = -2000000000;
    int64_t  i64 = -9000000000000LL;

    printf("int8_t  = %" PRId8  "\n", i8);
    printf("int16_t = %" PRId16 "\n", i16);
    printf("int32_t = %" PRId32 "\n", i32);
    printf("int64_t = %" PRId64 "\n", i64);

    return 0;
}
```

---

## Why use `PRId8` instead of `%d`?

Although this often works:

```c
int8_t x = 10;
printf("%d\n", x);
```

because `int8_t` is promoted to `int` in a variadic function like `printf`, the C standard recommends using the `PRI...` macros because they remain correct even on implementations where the underlying type differs. They also make your code portable across different architectures and C implementations. ([Cppreference][1])

---

## Summary

```c
#include <stdint.h>
#include <inttypes.h>

int8_t   x = -5;
uint32_t y = 123456789;

printf("%" PRId8  "\n", x);
printf("%" PRIu32 "\n", y);

scanf("%" SCNd8,  &x);
scanf("%" SCNu32, &y);
```

This is the recommended, portable C23 style for formatting fixed-width integer types. ([Cppreference][1])

[1]: https://en.cppreference.com/c/types/integer?utm_source=chatgpt.com "Fixed width integer types (since C99) - cppreference.com"
