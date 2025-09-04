#include <limits.h>
#include <stdio.h>

int main()
{
    int x = INT_MAX;
    int y = x + 1; // ❌ signed integer overflow
    int z = 1 << 40; // ❌ shift out of range (UB on 32-bit int)
    printf("%d %d\n", y, z);
    return 0;
}
