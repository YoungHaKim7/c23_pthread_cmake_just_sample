#include <stdio.h>

[[nodiscard]] int get_value(void) { return 7; }

[[deprecated("use new_api")]]
void old_api(void) {}

int main(void) {
    // [[nodiscard]] triggers a warning if return value is ignored
    int v = get_value();

    // [[fallthrough]] is allowed in switch
    switch (v) {
    case 1:
        printf("one\n");
        [[fallthrough]];
    case 2:
        printf("two\n");
    }
}
