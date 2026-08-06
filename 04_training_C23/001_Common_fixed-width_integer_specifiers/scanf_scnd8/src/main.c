// Use the corresponding SCN macros.
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int8_t value;

    printf("Enter a number: ");

    if (scanf("%" SCNd8, &value) == 1)
        printf("You entered %" PRId8 "\n", value);

    return 0;
}
