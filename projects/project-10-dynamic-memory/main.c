#include <stdio.h>
#include <stdlib.h>

/* project-10-dynamic-memory: malloc and free */
int main(void) {
    /*
     * Contract:
     *  - Inputs: none (allocates an array of fixed size)
     *  - Outputs: printed array contents to stdout
     *  - Success: allocates memory, prints values, frees memory, returns 0
     *  - Error modes: malloc failure (returns non-zero and prints error)
     *
     * Edge cases:
     *  - malloc returning NULL on allocation failure
     *  - Off-by-one allocation mistakes (ensure n * sizeof(int))
     */
    size_t n = 5;
    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    for (size_t i = 0; i < n; ++i) arr[i] = (int)(i + 1) * 10;

    for (size_t i = 0; i < n; ++i) printf("arr[%zu] = %d\n", i, arr[i]);

    /* always free allocated memory */
    free(arr);
    /*
     * Note: To practice resizing, use `realloc` carefully and always check for NULL
     * before overwriting the original pointer to avoid leaks on failure.
     */
    return 0;
}

/* small realloc example: grow and preserve contents */
int example_realloc(void) {
    size_t n = 2;
    int *a = malloc(n * sizeof(int));
    if (!a) return 1;
    a[0] = 1; a[1] = 2;

    size_t new_n = 4;
    int *b = realloc(a, new_n * sizeof(int));
    if (!b) { free(a); return 1; }
    b[2] = 3; b[3] = 4;
    for (size_t i = 0; i < new_n; ++i) printf("r[%zu] = %d\n", i, b[i]);
    free(b);
    return 0;
}
