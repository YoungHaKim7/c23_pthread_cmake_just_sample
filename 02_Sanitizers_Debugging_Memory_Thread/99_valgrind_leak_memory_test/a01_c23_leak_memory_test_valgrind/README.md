# (Valgrind구체적 오류)4.5. Details of Memcheck's checking machinery
- https://valgrind.org/docs/manual/mc-manual.html#mc-manual.machine

<hr />

# Result
- https://valgrind.org/docs/manual/quick-start.html

```bash
$ just valgrind
rm -rf target
mkdir -p target
/usr/bin/clang-20 -O0 -g -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall
 -Wextra -ggdb -Werror ./src/main.c -o ./target/main
valgrind --leak-check=full ./target/main
==2089== Memcheck, a memory error detector
==2089== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==2089== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==2089== Command: ./target/main
==2089==
==2089== error calling PR_SET_PTRACER, vgdb might block
==2089== Invalid write of size 4
==2089==    at 0x10915A: f (main.c:6)
==2089==    by 0x109183: main (main.c:11)
==2089==  Address 0x4b61068 is 0 bytes after a block of size 40 alloc'd
==2089==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-a
md64-linux.so)
==2089==    by 0x109151: f (main.c:5)
==2089==    by 0x109183: main (main.c:11)
==2089==
==2089==
==2089== HEAP SUMMARY:
==2089==     in use at exit: 40 bytes in 1 blocks
==2089==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==2089==
==2089== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==2089==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-a
md64-linux.so)
==2089==    by 0x109151: f (main.c:5)
==2089==    by 0x109183: main (main.c:11)
==2089==
==2089== LEAK SUMMARY:
==2089==    definitely lost: 40 bytes in 1 blocks
==2089==    indirectly lost: 0 bytes in 0 blocks
==2089==      possibly lost: 0 bytes in 0 blocks
==2089==    still reachable: 0 bytes in 0 blocks
==2089==         suppressed: 0 bytes in 0 blocks
==2089==
==2089== For lists of detected and suppressed errors, rerun with: -s
==2089== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```
