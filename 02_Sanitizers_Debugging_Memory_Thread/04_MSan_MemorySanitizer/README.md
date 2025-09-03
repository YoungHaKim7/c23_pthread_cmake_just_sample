# Result


```bash
$ just cr
rm -rf build
mkdir -p build
export CC=/opt/gcc-15/bin/gcc
cmake -D CMAKE_C_COMPILER=/opt/gcc-15/bin/gcc -G Ninja .
-- The C compiler identification is GNU 15.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /opt/gcc-15/bin/gcc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done (0.1s)
-- Generating done (0.0s)
-- Build files have been written to: /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/04_MSan_MemorySanitizer
ninja
[1/2] Building C object CMakeFiles/04_MSan_MemorySanitizer.dir/src/main.c.o
/home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/04_MSan_MemorySanitizer/src/main.c: In function ‘main’:
/home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/04_MSan_MemorySanitizer/src/main.c:5:8: warning: ‘x’ is used uninitialized [-Wuninitialized]
    5 |     if (x == 42) {
      |        ^
/home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/04_MSan_MemorySanitizer/src/main.c:4:9: note: ‘x’ was declared here
    4 |     int x;   // ❌ uninitialized
      |         ^
[2/2] Linking C executable target/04_MSan_MemorySanitizer
mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
./build/target/04_MSan_MemorySanitizer
```
