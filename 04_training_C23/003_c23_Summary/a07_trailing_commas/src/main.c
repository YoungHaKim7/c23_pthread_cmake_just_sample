// Trailing commas in C.
//
// Where a trailing comma is LEGAL (all of these predate C23; they are
// classic C99/C11 grammar, still worth knowing because they keep diffs
// clean — one line per item, no comma churn when appending):
//   1. enum enumerator lists
//   2. initializer lists (plain, designated, and nested)
//   3. attribute lists
//
// Where a trailing comma is ILLEGAL (a common misconception — note the
// original version of this file had bug #1):
//   1. struct/union member lists (members are separated by ';', never ',')
//   2. function parameter lists in declarations or calls
//   3. fixed-arity function-like macro invocations (the comma adds an
//      empty extra argument)

#include <stdio.h>

// 1. Enumerators: trailing comma allowed (legal since C99).
// C23 adds the fixed underlying type (N3030); comma still fine after it.
enum Color {
    RED,
    GREEN,
    BLUE, // <-- trailing comma
};

// C23: enum with fixed underlying type + trailing comma
enum Flags : unsigned {
    F_A = 1u << 0,
    F_B = 1u << 1, // <-- trailing comma
};

// NOT legal: struct members are separated by ';', a trailing ',' here is
// a syntax error:
//   struct Bad { int x, int y, };   // error: expected identifier or '('

struct Point {
    int x;
    int y;
};

// 2. Initializer lists: trailing comma allowed (legal since C99),
// including nested and designated initializers.
struct Point p = {
    .x = 1,
    .y = 2, // <-- trailing comma
};

static int grid[2][3] = {
    {
        1,
        2,
        3,
    },
    {
        4,
        5,
        6,
    }, // <-- trailing comma (nested)
};

// 3. Attribute lists: trailing comma allowed (C11/C23 attribute grammar).
[[deprecated("kept for old callers"), ]] void legacy(void);

// NOT legal: a fixed-arity macro call — the trailing comma becomes an
// (empty) extra argument:
//   #define SUM3(a, b, c) ((a) + (b) + (c))
//   SUM3(1, 2, 3,)   // error: passed 4 arguments, but takes just 3

int main(void) {
    printf("Point: x=%d y=%d\n", p.x, p.y);
    printf("Flags: F_A=%d F_B=%d\n", (int)F_A, (int)F_B);
    printf("grid[1][2]=%d\n", grid[1][2]);

    return 0;
}

void legacy(void) {}
