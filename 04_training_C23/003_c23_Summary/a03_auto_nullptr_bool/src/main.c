#include <stdio.h>

int main(void) {
    auto x = 42; // int
    auto p = &x; // int* — no '*' allowed: C23 auto infers from the initializer
    auto s = "hello"; // const char*

    int *ptr = nullptr; // nullptr, typed nullptr_t, not NULL
    bool flag = true;   // bool is now a keyword

    printf("%d %d %s %d %d\n", x, *p, s, ptr == nullptr, flag);
}
