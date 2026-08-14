#include <stdio.h>

// C23: constexpr applies to variables only — there are no constexpr
// functions and no consteval in C (those are C++ features).
// Compile-time evaluation is emulated with macros.

#define SQUARE(x) ((x) * (x))
#define COMPILE_TIME_ID(x) ((x) + 42)

// constexpr variable: must be initialized with an integer constant
// expression; gets internal linkage and can be folded at compile time.
constexpr int kAnswer = 42;

// Plain runtime function (a call is never a constant expression in C)
int factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }

int main(void) {
    // compile time evaluation via macros
    static_assert(SQUARE(5) == 25);
    static_assert(COMPILE_TIME_ID(8) == 50);
    static_assert(kAnswer == 42);

    // also usable at runtime
    int a = 7;
    printf("square = %d\n", SQUARE(a));

    int ct = COMPILE_TIME_ID(10);
    printf("ct = %d\n", ct);

    printf("factorial(5) = %d\n", factorial(5));
    printf("kAnswer = %d\n", kAnswer);
}
