// Printing several fixed-width integers
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int8_t i8 = -100;
    int16_t i16 = -32000;
    int32_t i32 = -2000000000;
    int64_t i64 = -9000000000000LL;

    printf("int8_t  = %" PRId8 "\n", i8);
    printf("int16_t = %" PRId16 "\n", i16);
    printf("int32_t = %" PRId32 "\n", i32);
    printf("int64_t = %" PRId64 "\n", i64);

    return 0;
}
