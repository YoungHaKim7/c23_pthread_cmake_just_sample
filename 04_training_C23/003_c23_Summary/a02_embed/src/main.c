#include <stdio.h>

int main(void) {
    // Embed the whole file as bytes
    unsigned char logo[] = {
#embed "logo.png"
    };

    // Embed text and append a NUL terminator with suffix(,)
    const char msg[] = {
#embed "hello.txt" suffix(, )
        0};

    printf("Embedded %zu bytes\n", sizeof logo);
    printf("msg: %zu bytes: %s\n", sizeof msg - 1, msg);
}
