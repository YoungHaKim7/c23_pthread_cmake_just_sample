#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {

    int8_t x = -5;
    uint32_t y = 123456789;
    uint64_t z = 12'345'678'912'345;

    int money = 1'000'000;
    long population = 7'654'321;
    int binary_mask = 0b1010'0101;

    printf("%" PRId8 "\n", x);
    printf("%" PRIu32 "\n", y);
    printf("%" PRIu64 "\n", z);

    printf("money: %d\n", money);
    printf("population: %ld\n", population);
    printf("binary_mask: %d\n", binary_mask);

    scanf("%" SCNd8, &x);
    scanf("%" SCNu32, &y);
}
