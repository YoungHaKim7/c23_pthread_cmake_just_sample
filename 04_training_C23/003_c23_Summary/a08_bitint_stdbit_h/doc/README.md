Fixed. The issue was the function names — C23's `<stdbit.h>` doesn't have `stdbit_*` or `stdc_popcount`/`stdc_ffs`:

- `stdbit_popcount(v)` → **`stdc_count_ones(v)`**
- `stdbit_ffs(v)` → **`stdc_first_trailing_one(v)`** (returns the 1-based index of the lowest set bit, 0 if none — same semantics as POSIX `ffs`)

The build and run now succeed:

```
big = 1          ← (2^64-1)² truncated by the (unsigned long long) cast
popcount = 3     ← 0b101100 has three set bits
ffs = 3          ← lowest set bit is bit 3
```

For reference, the C23 `<stdbit.h>` family is: `stdc_count_ones/zeros`, `stdc_leading/trailing_zeros/ones`, `stdc_first_leading/trailing_zero/one`, `stdc_bit_width/width`, `stdc_bit_floor/ceil`, `stdc_has_single_bit` — each also with typed suffixes (`_uc`, `_ul`, …).
