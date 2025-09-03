# link


<hr />

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
