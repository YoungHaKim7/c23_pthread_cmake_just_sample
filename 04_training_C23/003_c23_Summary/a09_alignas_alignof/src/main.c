#include <stdint.h>
#include <stdio.h>

struct Vec4 {
    alignas(32) float v[4];
};

int main(void) {
    printf("alignof Vec4 = %zu\n", alignof(struct Vec4));

    _Alignas(16) int buffer[4] = {0};
    printf("&buffer %% 16 = %tu, buffer[0] = %d\n", (uintptr_t)&buffer % 16,
           buffer[0]);
}
