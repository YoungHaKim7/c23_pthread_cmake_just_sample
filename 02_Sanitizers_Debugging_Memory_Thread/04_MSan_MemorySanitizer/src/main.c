#include <stdio.h>

int main()
{
    int x; // ❌ uninitialized
    if (x == 42) {
        printf("x is 42!\n");
    }
    return 0;
}
