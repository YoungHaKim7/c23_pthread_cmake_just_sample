#include <stdlib.h>
#include <string.h>

int main()
{
    char* leak = malloc(128);
    strcpy(leak, "this memory is leaked!"); // ❌ never freed
    return 0;
}
