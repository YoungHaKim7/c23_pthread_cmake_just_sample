# Result(Clang (memory))
- https://clang.llvm.org/docs/MemorySanitizer.html

```bash
❯ just cr
rm -rf build
mkdir -p build
export CC=/usr/bin/clang-20
cmake -D CMAKE_C_COMPILER=/usr/bin/clang-20 -G Ninja .
-- Configuring done (0.0s)
You have changed variables that require your cache to be deleted.
Configure will be re-run and you may have to reset some variables.
The following variables have changed:
CMAKE_C_COMPILER= /usr/bin/clang-20

-- The C compiler identification is Clang 20.1.8
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/clang-20 - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done (0.1s)
-- Generating done (0.0s)
-- Build files have been written to: /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/04_MSan_MemorySanitizer
ninja
[1/2] Building C object CMakeFiles/04_MSan_MemorySanitizer.dir/src/main.c.o
clang-20: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
/home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/04_MSan_MemorySanitizer/src/main.c:5:9: warning: variable 'x' is uninitialized when used here [-Wuninitialized]
    5 |     if (x == 42) {
      |         ^
/home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/04_MSan_MemorySanitizer/src/main.c:4:10: note: initialize the variable 'x' to silence this warning
    4 |     int x;   // ❌ uninitialized
      |          ^
      |           = 0
1 warning generated.
[2/2] Linking C executable target/04_MSan_MemorySanitizer
mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
./build/target/04_MSan_MemorySanitizer
==24317==WARNING: MemorySanitizer: use-of-uninitialized-value
    #0 0x5fd3ac9e364a in main /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/04_MSan_MemorySanitizer/src/main.c:5:11
    #1 0x7b4c69c2a1c9 in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16
    #2 0x7b4c69c2a28a in __libc_start_main csu/../csu/libc-start.c:360:3
    #3 0x5fd3ac947304 in _start (/home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/04_MSan_MemorySanitizer/build/target/04_MSan_MemorySanitizer+0x32304) (BuildId: 8173ba8b572f4ee1958f3c5f7ea315bbb8d02fe3)

SUMMARY: MemorySanitizer: use-of-uninitialized-value /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/04_MSan_MemorySanitizer/src/main.c:5:11 in main
Exiting
error: Recipe `cr` failed on line 81 with exit code 1
```
