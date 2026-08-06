// C23
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int8_t a = -42;
    uint8_t b = 200;

    printf("a = %" PRId8 "\n", a);
    printf("b = %" PRIu8 "\n", b);
    printf("b = 0x%" PRIx8 "\n", b);

    return 0;
}
