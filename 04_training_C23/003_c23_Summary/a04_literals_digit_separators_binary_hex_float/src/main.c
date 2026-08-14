#include <stdio.h>

int main(void) {
    int a = 1'000'000;
    int b = 0b1010'1100; // 172
    unsigned long long c = 0xFF'EC'12'34'56;
    double d = 0x1.ffffp+4; // hex floating

    printf("%d %d %llx %g\n", a, b, c, d);
}
