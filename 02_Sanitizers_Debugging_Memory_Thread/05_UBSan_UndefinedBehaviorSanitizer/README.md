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
-- Build files have been written to: /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/05_UBSan_UndefinedBehaviorSanitizer
ninja
[1/2] Building C object CMakeFiles/05_UBSan_UndefinedBehaviorSanitizer.dir/src/main.c.o
/home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/05_UBSan_UndefinedBehaviorSanitizer/src/main.c: In function ‘main’:
/home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/05_UBSan_UndefinedBehaviorSanitizer/src/main.c:7:15: warning: left shift count >= width of type [-Wshift-count-overflow]
    7 |     int z = 1 << 40;    // ❌ shift out of range (UB on 32-bit int)
      |               ^~
[2/2] Linking C executable target/05_UBSan_UndefinedBehaviorSanitizer
mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
./build/target/05_UBSan_UndefinedBehaviorSanitizer
/home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/05_UBSan_UndefinedBehaviorSanitizer/src/main.c:6:9: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int'
/home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/05_UBSan_UndefinedBehaviorSanitizer/src/main.c:7:15: runtime error: shift exponent 40 is too large for 32-bit type 'int'
-2147483648 0

```
