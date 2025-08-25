#include <stdio.h>
#include "merge_sort.h"

void print_array(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    print_array(arr, arr_size);

    merge_sort(arr, arr_size);

    printf("\nSorted array is \n");
    print_array(arr, arr_size);
    return 0;
}
