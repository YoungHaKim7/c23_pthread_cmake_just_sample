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
-- Build files have been written to: /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/02_LSan_LeakSanitizer
ninja
[2/2] Linking C executable target/02_LSan_LeakSanitizer
mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
./build/target/02_LSan_LeakSanitizer

=================================================================
==18556==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 128 byte(s) in 1 object(s) allocated from:
    #0 0x774a1a818132 in malloc ../../../../src/libsanitizer/lsan/lsan_interceptors.cpp:75
    #1 0x401137 in main /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/02_LSan_LeakSanitizer/src/main.c:6
    #2 0x774a1a42a1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #3 0x774a1a42a28a in __libc_start_main_impl ../csu/libc-start.c:360
    #4 0x401064 in _start (/home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/02_LSan_LeakSanitizer/build/target/02_LSan_LeakSanitizer+0x401064)

SUMMARY: LeakSanitizer: 128 byte(s) leaked in 1 allocation(s).
error: Recipe `cr` failed on line 81 with exit code 23

```
