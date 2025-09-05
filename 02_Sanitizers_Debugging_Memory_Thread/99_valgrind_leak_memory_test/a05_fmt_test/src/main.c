#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
    char data[8];
} Node;

// Leak a simple tree structure
Node* make_tree(int depth, char base)
{
    if (depth == 0)
        return NULL;
    Node* n = malloc(sizeof(Node)); // deliberately not freed
    snprintf(n->data, sizeof(n->data), "%c", base);
    n->left = make_tree(depth - 1, base + 1);
    n->right = make_tree(depth - 1, base + 2);
    return n;
}

int main(void)
{
    printf("=== Memcheck Demo Program ===\n");

    // --- V-bits demo (uninitialized values) ---
    int uninit; // not initialized
    int arr[4] = { 0 };
    arr[0] = uninit; // use of uninitialized value

    // --- A-bits demo (invalid address access) ---
    char* buf = malloc(4);
    strcpy(buf, "ABCDE"); // overflow (invalid write)

    // --- Leak demo (tree structure) ---
    Node* root = make_tree(2, 'A');
    printf("Tree root at %p with data='%s'\n", (void*)root, root->data);

    // --- Dangling pointer demo ---
    char* dangling = malloc(16);
    strcpy(dangling, "Hello");
    printf("Dangling before free: %s\n", dangling);
    free(dangling); // dangling now

    // Access after free (will trigger A-bit invalid read)
    printf("Dangling after free: %c\n", dangling[0]);

    // Never freeing root → memory leak for leak_check
    // buf is also leaked here

    return 0;
}
