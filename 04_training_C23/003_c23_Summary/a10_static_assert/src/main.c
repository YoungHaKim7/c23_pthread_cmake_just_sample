// #include <assert.h> // Required for lowercase "static_assert" macro

int main(void) {

    _Static_assert(sizeof(int) == 4,
                   "Integers must be 4 bytes"); // Message required
    // No #include <assert.h> required!

    // Two-argument syntax still works
    static_assert(sizeof(void *) == 8, "64-bit architecture required");

    // New single-argument syntax (cleaner)
    static_assert(sizeof(int) == 4);
}
