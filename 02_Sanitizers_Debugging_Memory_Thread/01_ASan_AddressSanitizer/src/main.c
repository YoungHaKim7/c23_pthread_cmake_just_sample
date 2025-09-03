#include <stdlib.h>

int main() {
    char *buf = malloc(8);
    buf[8] = 'X';   // ❌ out-of-bounds write
    free(buf);
    return 0;
}
