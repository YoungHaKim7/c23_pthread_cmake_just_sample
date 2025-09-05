#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    size_t pagesize = getpagesize();

    // ✅ Allocate one page with mmap
    char *p = mmap(NULL, pagesize, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (p == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    printf("Allocated %zu bytes at %p\n", pagesize, (void*)p);

    // ✅ Valid access (A-bits are set)
    strcpy(p, "Hello from mmap!");
    printf("p contains: %s\n", p);

    // Release memory
    if (munmap(p, pagesize) != 0) {
        perror("munmap");
        return 1;
    }

    // ❌ Invalid access: after munmap A-bits are cleared
    printf("Access after munmap (will trigger Valgrind error): %c\n", p[0]);

    return 0;
}
