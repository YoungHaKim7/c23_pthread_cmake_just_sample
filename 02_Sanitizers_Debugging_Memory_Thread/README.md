# link


<hr />

# 정의되지 않은 동작 Undefined Behavior, UB 
- · 마지막 업데이트: 2026-07-12 | Jeong Dongwoo

- https://github.com/YoungHaKim7/c23_pthread_cmake_just_sample/tree/main/02_Sanitizers_Debugging_Memory_Thread/05_UBSan_UndefinedBehaviorSanitizer

## UB 점검 방법
```bash
# clang sanitize(ASan=address / LSan=leak / TSan=thread / MSan=memory / UBSan=undefined)
clang -fsanitize=undefined -g -fno-omit-frame-pointer -c main.c
clang -g -fsanitize=undefined *.o
./a.out
```
- https://clang.llvm.org/docs/MemorySanitizer.html

```cpp
#include <limits.h>
#include <stdio.h>

int main()
{
    int x = INT_MAX;
    int y = x + 1; // :x: signed integer overflow
    int z = 1 << 40; // :x: shift out of range (UB on 32-bit int)
    printf("%d %d\n", y, z);
    return 0;
}
```

- https://www.makonea.com/ko/wiki/%EC%A0%95%EC%9D%98%EB%90%98%EC%A7%80-%EC%95%8A%EC%9D%80-%EB%8F%99%EC%9E%91

# Rust Sanitizers문서[|🔝|](#link)
- https://github.com/rust-lang/rust/blob/master/src/doc/unstable-book/src/compiler-flags/sanitizer.md#sanitizer

# Sanitizers - Tools[|🔝|](#link)
- AddressSanitizer(ASan)
  - detects addressability issues
- LeakSanitizer(LSan)
  - detects memory leaks
  - https://github.com/google/sanitizers/wiki/AddressSanitizerLeakSanitizer
  - https://clang.llvm.org/docs/LeakSanitizer.html
    - Rust
      - https://github.com/rust-lang/rust/blob/master/src/doc/unstable-book/src/compiler-flags/sanitizer.md#leaksanitizer
- ThreadSanitizer(TSan)
  - detects data races and deadlocks
- MemorySanitizer(MSan)
  - detects use of uninitialized memory
  - https://clang.llvm.org/docs/MemorySanitizer.html
    - Rust
      - https://github.com/rust-lang/rust/blob/master/src/doc/unstable-book/src/compiler-flags/sanitizer.md#memorysanitizer 
- UndefinedBehaviorSanitizer(UBSan)
  - dectects undefined behavior
