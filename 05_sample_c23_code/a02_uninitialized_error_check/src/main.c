#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[argc + 1]) {
    (void)argv; // argc is used below; argv is not -> silence -Wunused-parameter
    // Deliberately NOT initialized. It is assigned only inside *some*
    // switch cases below; if no case matches, it is left indeterminate.
    unsigned tmp;

    // argc's value is not known at compile time, so the compiler cannot
    // prove which case (if any) will run -> 'tmp' may stay unset.
    switch ((unsigned)argc) {
    case 0:
        tmp = 0;
        break;
    case 1:
        tmp = 1;
        break;
        // NOTE: no `default` here, and no assignment for argc >= 2,
        //       so 'tmp' is not guaranteed to be set on every path.
    }

    // Error: on a path where no case matched, 'tmp' may be used uninitialized.
    printf("the temp is %u\n", tmp);

    return EXIT_SUCCESS;
}
