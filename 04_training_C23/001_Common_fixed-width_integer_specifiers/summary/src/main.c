#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {

    int8_t x = -5;
    uint32_t y = 123456789;

    printf("%" PRId8 "\n", x);
    printf("%" PRIu32 "\n", y);

    scanf("%" SCNd8, &x);
    scanf("%" SCNu32, &y);
}
