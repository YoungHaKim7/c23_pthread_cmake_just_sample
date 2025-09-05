# (Valgrind구체적 오류)4.5. Details of Memcheck's checking machinery
- https://valgrind.org/docs/manual/mc-manual.html#mc-manual.machine

<hr />

# Result
- https://valgrind.org/docs/manual/quick-start.html

```bash
$ just valgrind_detail

rm -rf target
mkdir -p target
/usr/bin/clang-20 -O0 -g -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror ./src/main.c -o a02_valid_value_v_bits
mv a02_valid_value_v_bits ./target

valgrind --leak-check=full --track-origins=yes ./target/a02_valid_value_v_bits
==9561== Memcheck, a memory error detector
==9561== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==9561== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==9561== Command: ./target/a02_valid_value_v_bits
==9561==
==9561== error calling PR_SET_PTRACER, vgdb might block
==9561== Conditional jump or move depends on uninitialised value(s)
==9561==    at 0x1091A7: main (main.c:14)
==9561==  Uninitialised value was created by a stack allocation
==9561==    at 0x109140: main (main.c:4)
==9561==
==9561==
==9561== HEAP SUMMARY:
==9561==     in use at exit: 0 bytes in 0 blocks
==9561==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==9561==
==9561== All heap blocks were freed -- no leaks are possible
==9561==
==9561== For lists of detected and suppressed errors, rerun with: -s
==9561== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
