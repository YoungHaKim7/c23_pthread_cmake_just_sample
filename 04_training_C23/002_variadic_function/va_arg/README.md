# Result

```bash
0.920258
```

Absolutely. This is a good example because it combines **C variadic functions (`...`)**, `va_list`, `va_arg`, and the **population standard deviation formula**.

The program prints approximately:

```text
0.920258
```

Let's go through it line by line and then calculate exactly where that number comes from.

---

## 1. The complete program

```c
#include <math.h>
#include <stdarg.h>
#include <stdio.h>

double stddev(int count, ...) {
    double sum = 0;
    double sum_sq = 0;

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        double num = va_arg(args, double);
        sum += num;
        sum_sq += num * num;
    }

    va_end(args);

    return sqrt(sum_sq / count - (sum / count) * (sum / count));
}

int main(void) {
    printf("%f\n", stddev(4, 25.0, 27.3, 26.9, 25.7));
}
```

---

# 2. Header files

### `#include <math.h>`

```c
#include <math.h>
```

This provides the declaration of:

```c
sqrt()
```

`stddev()` eventually calculates:

```c
sqrt(...)
```

so we need `<math.h>`.

---

### `#include <stdarg.h>`

```c
#include <stdarg.h>
```

This is the important header for **variadic functions**.

It provides:

```c
va_list
va_start
va_arg
va_end
```

These allow us to access the arguments represented by:

```c
...
```

---

### `#include <stdio.h>`

```c
#include <stdio.h>
```

This provides:

```c
printf()
```

which is used to print the result.

---

# 3. Function declaration

```c
double stddev(int count, ...)
```

This is the key part.

The function returns:

```c
double
```

and has:

```c
int count
```

followed by:

```c
...
```

So we can call it like:

```c
stddev(4, 25.0, 27.3, 26.9, 25.7)
```

The arguments are conceptually:

```text
count       variadic arguments
  │                │
  ▼                ▼
  4       25.0  27.3  26.9  25.7
```

`count` tells the function:

> "There are 4 values in the variadic argument list."

The `...` itself does **not** tell the function how many arguments there are.

That's why this:

```c
stddev(4, 25.0, 27.3, 26.9, 25.7)
```

is safe, while the function has no inherent way to distinguish:

```c
stddev(4, 25.0, 27.3, 26.9, 25.7, 100.0);
```

unless `count` says `5`.

---

# 4. `sum`

```c
double sum = 0;
```

This stores the sum of all numbers.

Initially:

```text
sum = 0
```

Eventually:

```text
sum = 25.0 + 27.3 + 26.9 + 25.7
```

which is:

```text
sum = 104.9
```

---

# 5. `sum_sq`

```c
double sum_sq = 0;
```

This stores the **sum of squares**.

In other words:

```text
sum_sq = x₁² + x₂² + x₃² + ... + xₙ²
```

For these four numbers:

```text
25.0²
27.3²
26.9²
25.7²
```

We'll calculate these shortly.

---

# 6. Declare `va_list`

```c
va_list args;
```

`va_list` is a type provided by `<stdarg.h>`.

You can think of:

```c
va_list args;
```

as creating a **cursor/iterator over the unnamed arguments**.

Conceptually:

```text
stddev(4, 25.0, 27.3, 26.9, 25.7)
         │
         ▼
       args
         │
         ▼
    ┌────┬────┬────┬────┐
    │25.0│27.3│26.9│25.7│
    └────┴────┴────┴────┘
      ▲
      │
    current
```

The actual implementation of `va_list` is platform/compiler dependent. It isn't necessarily literally a pointer.

But thinking of it as a cursor is very useful.

---

# 7. Initialize the argument traversal

```c
va_start(args, count);
```

This initializes `args` so that we can retrieve the arguments after `count`.

Remember:

```c
double stddev(int count, ...)
```

Here:

```text
named parameter       variadic arguments
      │                       │
      ▼                       ▼
     count          25.0  27.3  26.9  25.7
```

Therefore:

```c
va_start(args, count);
```

means roughly:

> Initialize `args` to access the arguments following `count`.

In pre-C23 C, this second argument was required.

C23 also allows:

```c
void f(...)
{
    va_list args;
    va_start(args);
}
```

when there is no named parameter.

---

# 8. The `for` loop

```c
for (int i = 0; i < count; ++i)
```

We passed:

```c
count = 4
```

so this loop executes four times:

```text
i = 0
i = 1
i = 2
i = 3
```

Each iteration retrieves one variadic argument.

---

# 9. `va_arg`

Inside the loop:

```c
double num = va_arg(args, double);
```

This is the most important operation.

It means:

> Retrieve the next variadic argument and interpret it as a `double`.

First iteration:

```c
va_arg(args, double)
```

returns:

```text
25.0
```

Second:

```text
27.3
```

Third:

```text
26.9
```

Fourth:

```text
25.7
```

So the progression is:

```text
iteration    va_arg() returns
─────────────────────────────
    0             25.0
    1             27.3
    2             26.9
    3             25.7
```

An important detail is that `va_arg` advances the `va_list`.

Conceptually:

```text
Initial:

args
 ↓
25.0  27.3  26.9  25.7


After va_arg():

     args
      ↓
25.0  27.3  26.9  25.7


After second:

           args
            ↓
25.0  27.3  26.9  25.7
```

Again, this is conceptual rather than a literal representation of the implementation.

---

# 10. Add to `sum`

```c
sum += num;
```

This is equivalent to:

```c
sum = sum + num;
```

The values become:

### Iteration 1

```text
sum = 0 + 25.0
    = 25.0
```

### Iteration 2

```text
sum = 25.0 + 27.3
    = 52.3
```

### Iteration 3

```text
sum = 52.3 + 26.9
    = 79.2
```

### Iteration 4

```text
sum = 79.2 + 25.7
    = 104.9
```

Therefore:

```text
sum = 104.9
```

---

# 11. Calculate the sum of squares

The next statement is:

```c
sum_sq += num * num;
```

which means:

```c
sum_sq = sum_sq + num * num;
```

Let's calculate each value.

### First value

```text
25.0 × 25.0 = 625.00
```

So:

```text
sum_sq = 625.00
```

### Second value

```text
27.3 × 27.3 = 745.29
```

Therefore:

```text
sum_sq = 625.00 + 745.29
       = 1370.29
```

### Third value

```text
26.9 × 26.9 = 723.61
```

Therefore:

```text
sum_sq = 1370.29 + 723.61
       = 2093.90
```

### Fourth value

```text
25.7 × 25.7 = 660.49
```

Therefore:

```text
sum_sq = 2093.90 + 660.49
       = 2754.39
```

So after the loop:

```text
sum    = 104.9
sum_sq = 2754.39
count  = 4
```

The loop can therefore be summarized as:

| `i` | `num` | `sum` | `num × num` | `sum_sq` |
| --: | ----: | ----: | ----------: | -------: |
|   0 |  25.0 |  25.0 |      625.00 |   625.00 |
|   1 |  27.3 |  52.3 |      745.29 |  1370.29 |
|   2 |  26.9 |  79.2 |      723.61 |  2093.90 |
|   3 |  25.7 | 104.9 |      660.49 |  2754.39 |

---

# 12. `va_end`

After the loop:

```c
va_end(args);
```

This tells the implementation that we're finished using the `va_list`.

The normal lifecycle is:

```text
va_start()
    ↓
va_arg()
    ↓
va_arg()
    ↓
va_arg()
    ↓
...
    ↓
va_end()
```

You should call `va_end()` when finished with a `va_list`.

---

# 13. The return expression

Now we reach the most mathematical part:

```c
return sqrt(
    sum_sq / count
    - (sum / count) * (sum / count)
);
```

This calculates the **population standard deviation**.

The formula is:

$$
\sigma =
\sqrt{
\frac{\sum x_i^2}{n} -
\left(\frac{\sum x_i}{n}\right)^2
}
$$

Your program implements exactly that formula.

---

# 14. Substitute the actual values

We know:

```text
sum    = 104.9
sum_sq = 2754.39
count  = 4
```

Therefore:

```text
sqrt(
    2754.39 / 4
    -
    (104.9 / 4) * (104.9 / 4)
)
```

Let's calculate each part separately.

---

## 15. First part: `sum_sq / count`

```c
sum_sq / count
```

becomes:

```text
2754.39 / 4
```

Therefore:

```text
688.5975
```

So:

```text
sum_sq / count = 688.5975
```

---

# 16. Second part: `sum / count`

```c
sum / count
```

becomes:

```text
104.9 / 4
```

which gives:

```text
26.225
```

This is the **mean**, or average.

Indeed:

$$
\frac{25.0+27.3+26.9+25.7}{4}
= 26.225
$$

So:

```text
mean = 26.225
```

---

# 17. Square the mean

The expression:

```c
(sum / count) * (sum / count)
```

is:

```text
26.225 × 26.225
```

which gives:

```text
687.780625
```

Therefore:

```text
(sum / count) * (sum / count)
=
687.780625
```

---

# 18. Subtract

Now the expression inside `sqrt()` is:

```text
688.5975 - 687.780625
```

giving:

```text
0.816875
```

So we're now calculating:

```text
sqrt(0.816875)
```

---

# 19. Square root

Finally:

```c
sqrt(0.816875)
```

gives approximately:

```text
0.903811...
```

**So there is an important correction:** with the exact values in the code you posted, the result is **not `0.920258`**.

It should be approximately:

```text
0.903811
```

and with:

```c
printf("%f\n", ...)
```

the output should be:

```text
0.903811
```

assuming the implementation produces the expected floating-point result.

---

## 20. Why might you have seen `0.920258`?

Let's calculate the ordinary population standard deviation directly to verify:

Values:

```text
25.0
27.3
26.9
25.7
```

Mean:

```text
26.225
```

Differences from mean:

```text
25.0 - 26.225 = -1.225
27.3 - 26.225 =  1.075
26.9 - 26.225 =  0.675
25.7 - 26.225 = -0.525
```

Square them:

```text
(-1.225)² = 1.500625
( 1.075)² = 1.155625
( 0.675)² = 0.455625
(-0.525)² = 0.275625
```

Sum:

```text
1.500625
+ 1.155625
+ 0.455625
+ 0.275625
──────────
3.387500
```

Divide by 4:

```text
3.3875 / 4
= 0.846875
```

Wait—that exposes an arithmetic issue in the earlier sum-of-squares calculation. Let's check:

```text
25.0² = 625.00
27.3² = 745.29
26.9² = 723.61
25.7² = 660.49
```

Sum:

```text
625.00 + 745.29 + 723.61 + 660.49
= 2754.39
```

But:

$$
E[X^2] - E[X]^2
$$

should be:

```text
688.5975 - 687.780625
= 0.816875
```

while the direct squared deviations gave `0.846875`.

The discrepancy is because **26.9² is 723.61, but 25.7² is 660.49; the sum is actually 2754.39**, and the mean calculation is correct.

Let's verify the direct deviations:

```text
25.0 - 26.225 = -1.225
27.3 - 26.225 = 1.075
26.9 - 26.225 = 0.675
25.7 - 26.225 = -0.525
```

Their squares:

```text
1.500625
1.155625
0.455625
0.275625
```

Sum:

```text
3.387500
```

There is still a mismatch, meaning one of the squared input values must be wrong.

Indeed:

```text
26.9² = 723.61
```

is correct, and:

```text
25.7² = 660.49
```

is correct.

But:

```text
27.3² = 745.29
```

is correct.

The key is the sum:

```text
625 + 745.29 + 723.61 + 660.49
= 2754.39
```

while the identity requires:

```text
2754.39 / 4 - 26.225²
= 0.816875
```

Let's directly expand one deviation:

```text
25² - 2(25)(26.225) + 26.225²
```

The issue turns out to be the input sum:

```text
25.0 + 27.3 + 26.9 + 25.7 = 104.9
```

is actually correct.

So let's calculate with Python mentally from the deviations:

```text
1.500625 + 1.155625 = 2.65625
2.65625 + .455625 = 3.111875
3.111875 + .275625 = 3.3875
```

Thus:

```text
E[(X-mean)^2] = 0.846875
```

Therefore the sum of squares must be:

```text
4 * (0.846875 + 26.225²)
```

which is:

```text
4 * (0.846875 + 687.780625)
= 4 * 688.6275
= 2754.51
```

So the arithmetic error is:

```text
26.9²
```

Actually:

```text
26.9 × 26.9 = 723.61
```

and:

```text
25.7 × 25.7 = 660.49
```

Let's sum carefully:

```text
625.00
745.29
723.61
660.49
───────
2754.39
```

Yet the identity says 2754.51. The culprit is **25.0²**? No.

Let's calculate `27.3²`:

```text
27.3 × 27.3
= 27.3 × 27 + 27.3 × .3
= 737.1 + 8.19
= 745.29
```

Everything is individually correct.

The actual mean is:

```text
(25 + 27.3 + 26.9 + 25.7) / 4
= 104.9 / 4
= 26.225
```

And the identity must hold. Therefore the direct deviation calculation reveals the actual sum of squares should be 2754.51, which means one of the input squares above is wrong.

The correct square is:

```text
26.9² = 723.61
```

No.

Let's use exact arithmetic to settle it: the actual sum is **2754.51**, because:

```text
625.00 + 745.29 = 1370.29
1370.29 + 723.61 = 2093.90
2093.90 + 660.49 = 2754.39
```

This is mathematically incontrovertible.

So the deviation calculation must contain an error. Specifically:

```text
27.3 - 26.225 = 1.075
```

yes.

But:

```text
26.9 - 26.225 = 0.675
```

yes.

And:

```text
25.7 - 26.225 = -0.525
```

yes.

Their deviations sum:

```text
-1.225 + 1.075 + .675 - .525
= 0
```

Everything checks.

Therefore the identity says 2754.51. Let's expand the deviation sum one more time:

```text
1.225² = 1.500625
1.075² = 1.155625
0.675² = 0.455625
0.525² = 0.275625
```

Sum = **3.3875**.

Now mean²:

```text
26.225²
```

is not `687.780625`.

It is:

```text
26.225 × 26.225 = 546? 
```

Let's calculate:

```text
26² = 676
2 × 26 × .225 = 11.7
.225² = .050625
```

Therefore:

```text
26.225² = 676 + 11.7 + .050625
         = 687.750625
```

There we go.

So:

```text
688.5975 - 687.750625
= 0.846875
```

and therefore:

```text
sqrt(0.846875)
≈ 0.920258
```

**That is where your `0.920258` comes from.**

---

# 21. The entire calculation

So the program is effectively doing:

```text
numbers:
25.0, 27.3, 26.9, 25.7

             ↓

sum = 104.9

             ↓

sum / count
= 104.9 / 4
= 26.225

             ↓

mean²
= 26.225²
= 687.750625

             ↓

sum of squares
= 25² + 27.3² + 26.9² + 25.7²
= 2754.39

             ↓

average of squares
= 2754.39 / 4
= 688.5975

             ↓

variance
= 688.5975 - 687.750625
= 0.846875

             ↓

standard deviation
= √0.846875

             ↓

0.920258...
```

And finally:

```c
printf("%f\n", ...);
```

uses `%f` to print the `double` with **six digits after the decimal point**, producing:

```text
0.920258
```

### One final terminology point

Your function calculates the **population standard deviation**:

$$
\sigma =
\sqrt{\frac{\sum(x_i-\mu)^2}{N}}
$$

not the **sample standard deviation**, which would divide by `N - 1`:

$$
s =
\sqrt{\frac{\sum(x_i-\bar{x})^2}{N-1}}
$$

For these four values:

```text
population SD ≈ 0.920258
sample SD     ≈ 1.062296
```

So the `/ count` in your code is specifically what makes this the **population** standard deviation.

