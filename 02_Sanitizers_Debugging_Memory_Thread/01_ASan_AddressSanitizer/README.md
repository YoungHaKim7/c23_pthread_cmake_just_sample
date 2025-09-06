# That log line is the runtime error report from AddressSanitizer (ASan).
- AddressSanitizer is a compiler/runtime instrumentation that detects memory safety bugs (buffer overflows, use-after-free, invalid frees, double frees, stack/global corruption, etc.).
  - 해당 로그 라인은 AddressSanitizer(ASAN)의 런타임 오류 보고서입니다.
AddressSanitizer는 메모리 안전 버그(버퍼 오버플로, 사용 후 프리, 무효 프리, 더블 프리, 스택/글로벌 손상 등)를 감지하는 컴파일러/런타임 계측기입니다.

- ==18086== → process ID (here, 18086).

- ERROR: AddressSanitizer → tool raising the error (ASan).

- heap-buffer-overflow → type of bug detected.
That means your program wrote beyond the allocated heap buffer.

- on address 0x502000000018 → the offending memory address.

- at pc 0x0000004011b8 → program counter where the fault happened (useful for backtrace).

- bp 0x7fff9dc20410 sp 0x7fff9dc20400 → base pointer and stack pointer at the time.

- WRITE of size 1 → the invalid memory write was 1 byte.

- thread T0 → happened in the main thread.

- ==18086== → 프로세스 ID (여기, 18086).
  - 오류: AddressSanitizer → 오류를 발생시키는 도구(ASAN).
  - 힙-buffer-overflow → 유형의 버그가 감지되었습니다.
  - 즉, 프로그램이 할당된 힙 버퍼를 초과하여 작성되었음을 의미합니다.
  - 주소 0x5020000018 → 문제가 되는 메모리 주소.
  - PC 0x0000004011b8 → 프로그램 카운터에서 오류가 발생했습니다(백트레이스용 useful).
  - bp 0x7ff9dc20410 sp 0x7ff9dc20400 → 당시 기본 포인터와 스택 포인터.
  - 크기 1 → 잘못된 메모리 쓰기가 1바이트였습니다.
  - T0 → 스레드가 메인 스레드에서 발생했습니다.

# Result

```bash
 just cr
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
-- Build files have been written to: /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/01_ASan_AddressSanitizer
ninja
[2/2] Linking C executable target/01_ASan_AddressSanitizer
mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
./build/target/01_ASan_AddressSanitizer
=================================================================
==18086==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x502000000018 at pc 0x0000004011b8 bp 0x7fff9dc20410 sp 0x7fff9dc20400
WRITE of size 1 at 0x502000000018 thread T0
    #0 0x4011b7 in main /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/01_ASan_AddressSanitizer/src/main.c:5
    #1 0x70588902a1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #2 0x70588902a28a in __libc_start_main_impl ../csu/libc-start.c:360
    #3 0x4010a4 in _start (/home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/01_ASan_AddressSanitizer/build/target/01_ASan_AddressSanitizer+0x4010a4)

0x502000000018 is located 0 bytes after 8-byte region [0x502000000010,0x502000000018)
allocated by thread T0 here:
    #0 0x7058894fd9c7 in malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:69
    #1 0x401177 in main /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/01_ASan_AddressSanitizer/src/main.c:4
    #2 0x70588902a1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #3 0x70588902a28a in __libc_start_main_impl ../csu/libc-start.c:360
    #4 0x4010a4 in _start (/home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/01_ASan_AddressSanitizer/build/target/01_ASan_AddressSanitizer+0x4010a4)

SUMMARY: AddressSanitizer: heap-buffer-overflow /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/01_ASan_AddressSanitizer/src/main.c:5 in main
Shadow bytes around the buggy address:
  0x501ffffffd80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x501ffffffe00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x501ffffffe80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x501fffffff00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x501fffffff80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x502000000000: fa fa 00[fa]fa fa fa fa fa fa fa fa fa fa fa fa
  0x502000000080: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x502000000100: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x502000000180: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x502000000200: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x502000000280: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==18086==ABORTING
error: Recipe `cr` failed on line 81 with exit code 1

```
