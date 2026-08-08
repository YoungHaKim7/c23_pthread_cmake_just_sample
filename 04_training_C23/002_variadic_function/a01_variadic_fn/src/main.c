#include <stdarg.h>
#include <stdio.h>

void print_ints(...) {
    va_list ap;
    va_start(ap);

    for (int i = 0; i < 3; ++i) {
        int value = va_arg(ap, int);
        printf("%d\n", value);
    }

    va_end(ap);
}

int main(void) { print_ints(10, 20, 30); }
