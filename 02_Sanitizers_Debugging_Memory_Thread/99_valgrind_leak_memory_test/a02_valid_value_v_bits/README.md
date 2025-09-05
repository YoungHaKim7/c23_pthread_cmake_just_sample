# (Valgrind구체적 오류)4.5. Details of Memcheck's checking machinery
- https://valgrind.org/docs/manual/mc-manual.html#mc-manual.machine

<hr />

# Result
- https://valgrind.org/docs/manual/quick-start.html

```bash
$ just valgrind_detail

rm -rf target
mkdir -p target

/usr/bin/clang-20 -O0 -g -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall
 -Wextra -ggdb -Werror ./src/main.c -o ./targeta02_valid_value_v_bits

valgrind --leak-check=full --track-origins=yes ./targeta02_valid_value_v_bits
==6333== Memcheck, a memory error detector
==6333== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==6333== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==6333== Command: ./targeta02_valid_value_v_bits
==6333==
==6333== error calling PR_SET_PTRACER, vgdb might block
==6333== Conditional jump or move depends on uninitialised value(s)
==6333==    at 0x1091A7: main (main.c:15)
==6333==  Uninitialised value was created by a stack allocation
==6333==    at 0x109140: main (main.c:5)
==6333==
==6333==
==6333== HEAP SUMMARY:
==6333==     in use at exit: 0 bytes in 0 blocks
==6333==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==6333==
==6333== All heap blocks were freed -- no leaks are possible
==6333==
==6333== For lists of detected and suppressed errors, rerun with: -s
==6333== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
mv ./targeta02_valid_value_v_bits ./target

```
