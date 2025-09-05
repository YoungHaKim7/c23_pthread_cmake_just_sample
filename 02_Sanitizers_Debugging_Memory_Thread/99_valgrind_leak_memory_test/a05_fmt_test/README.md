# (Valgrind구체적 오류)4.5. Details of Memcheck's checking machinery
- https://valgrind.org/docs/manual/mc-manual.html#mc-manual.machine

<hr />

#  gbd

- This starts Valgrind with gdbserver enabled.
  - Then in another terminal:

```bash
gdb ./memcheck_demo
(gdb) target remote | vgdb
```

- Now you can issue Memcheck monitor commands via GDB:
  - Inspect uninitialized memory (xb / get_vbits):

```gdb
(gdb) mc xb &arr 16
(gdb) mc get_vbits &arr 16
```

- Force memory state changes:

```gdb
(gdb) mc make_memory noaccess &arr 4
(gdb) mc check_memory addressable &arr 4
```

- Leak check and block list:

```gdb
(gdb) mc leak_check full reachable any
(gdb) mc block_list 1
```

- Show who points at a block:

```gdb
(gdb) mc who_points_at &root 32
```

- This program gives you all the ingredients for testing:
  - V-bits (uninit usage).
  - A-bits (overflow, use-after-free).
  - Leaks (tree root + buf).
  - Dangling pointers for who_points_at.

<hr />

# Result
- https://valgrind.org/docs/manual/quick-start.html


```bash
$ just valgrind_memcheck_detail

rm -rf target
mkdir -p target
/usr/bin/clang-20 -O0 -g -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror ./src/main.c -o a03_nmap_munmap_memcheck_a_bits_
valid_address_bits
mv a03_nmap_munmap_memcheck_a_bits_valid_address_bits ./target


valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./target/a03_nmap_munmap_memcheck_a_bits_valid_address_bits
==11083== Memcheck, a memory error detector
==11083== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==11083== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==11083== Command: ./target/a03_nmap_munmap_memcheck_a_bits_valid_address_bits
==11083==
==11083== error calling PR_SET_PTRACER, vgdb might block
Allocated 4096 bytes at 0x485a000
p contains: Hello from mmap!
==11083== Invalid read of size 1
==11083==    at 0x109254: main (main.c:32)
==11083==  Address 0x485a000 is not stack'd, malloc'd or (recently) free'd
==11083==
==11083==
==11083== Process terminating with default action of signal 11 (SIGSEGV)
==11083==  Access not within mapped region at address 0x485A000
==11083==    at 0x109254: main (main.c:32)
==11083==  If you believe this happened as a result of a stack
==11083==  overflow in your program's main thread (unlikely but
==11083==  possible), you can try to increase the size of the
==11083==  main thread stack using the --main-stacksize= flag.
==11083==  The main thread stack size used in this run was 8388608.
==11083==
==11083== HEAP SUMMARY:
==11083==     in use at exit: 4,096 bytes in 1 blocks
==11083==   total heap usage: 1 allocs, 0 frees, 4,096 bytes allocated
==11083==
==11083== 4,096 bytes in 1 blocks are still reachable in loss record 1 of 1
==11083==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==11083==    by 0x49D21B4: _IO_file_doallocate (filedoalloc.c:101)
==11083==    by 0x49E2523: _IO_doallocbuf (genops.c:347)
==11083==    by 0x49DFF8F: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:745)
==11083==    by 0x49E0AAE: _IO_new_file_xsputn (fileops.c:1244)
==11083==    by 0x49E0AAE: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1197)
==11083==    by 0x49ADCC8: __printf_buffer_flush_to_file (printf_buffer_to_file.c:59)
==11083==    by 0x49ADCC8: __printf_buffer_to_file_done (printf_buffer_to_file.c:120)
==11083==    by 0x49B8742: __vfprintf_internal (vfprintf-internal.c:1545)
==11083==    by 0x49AD1B2: printf (printf.c:33)
==11083==    by 0x109206: main (main.c:19)
==11083==
==11083== LEAK SUMMARY:
==11083==    definitely lost: 0 bytes in 0 blocks
==11083==    indirectly lost: 0 bytes in 0 blocks
==11083==      possibly lost: 0 bytes in 0 blocks
==11083==    still reachable: 4,096 bytes in 1 blocks
==11083==         suppressed: 0 bytes in 0 blocks
==11083==
==11083== For lists of detected and suppressed errors, rerun with: -s
==11083== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
error: Recipe `valgrind_memcheck_detail` failed on line 246 with exit code 139
```
