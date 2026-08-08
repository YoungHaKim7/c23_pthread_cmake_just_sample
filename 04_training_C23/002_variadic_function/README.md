Yes. The important point is that **C23 changes both the function parameter-list syntax and `va_start`**.

### Before C23

A variadic function needed at least one named parameter before `...`:

```c
#include <stdarg.h>

void print_values(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);

    // ...

    va_end(ap);
}
```

You could **not** write:

```c
void print_values(...)
{
    // invalid before C23
}
```

The reason was that `va_start` traditionally needed the last named parameter:

```c
va_start(ap, format);
```

---

### C23

C23 permits an ellipsis to appear by itself:

```c
#include <stdarg.h>

void print_values(...)
{
    va_list ap;
    va_start(ap);

    // ...

    va_end(ap);
}
```

The corresponding change is that `va_start` no longer takes the last named parameter:

```c
va_start(ap);
```

So conceptually:

|                             | C17 and earlier   | C23             |
| --------------------------- | ----------------- | --------------- |
| Variadic parameter list     | `f(int x, ...)`   | `f(int x, ...)` |
| Parameterless variadic list | `f(...)` ❌        | `f(...)` ✅      |
| `va_start`                  | `va_start(ap, x)` | `va_start(ap)`  |
| Requires named parameter    | Yes               | No              |

### A complete C23 example

```c
#include <stdio.h>
#include <stdarg.h>

void print_ints(...)
{
    va_list ap;
    va_start(ap);

    for (int i = 0; i < 3; ++i) {
        int value = va_arg(ap, int);
        printf("%d\n", value);
    }

    va_end(ap);
}

int main(void)
{
    print_ints(10, 20, 30);
}
```

The function has **no fixed parameters at all**:

```c
void print_ints(...)
```

and the arguments are retrieved entirely through `va_arg`:

```c
va_arg(ap, int)
```

One important caveat: **there is no automatic way to know how many arguments were supplied.** You still need some convention, such as a count, sentinel, or format string.

For example:

```c
void print_ints(int count, ...)
```

is often more practical:

```c
print_ints(3, 10, 20, 30);
```

The interesting C23 case is therefore specifically:

```c
void f(...);
```

which is now a legitimate **parameterless variadic function**.
