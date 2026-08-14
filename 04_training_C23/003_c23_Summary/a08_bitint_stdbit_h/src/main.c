#include <stdbit.h>
#include <stdio.h>

int main(void) {
    _BitInt(128) big = 0xFFFFFFFFFFFFFFFFULL * 0xFFFFFFFFFFFFFFFFULL;
    printf("big = %llu...\n", (unsigned long long)big);

    unsigned int v = 0b101100;
    printf("popcount = %u\n", stdc_count_ones(v));
    printf("ffs = %u\n", stdc_first_trailing_one(v));
}
