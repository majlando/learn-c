#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * project-10-dynamic-memory: demonstrates malloc/realloc/free with checks.
 *
 * Learner notes:
 *  - Always check the pointer returned by malloc/realloc for NULL.
 *  - Use sizeof *ptr idiom to avoid repeating the type and to stay correct
 *    if the type of `ptr` changes.
 *  - Free allocated memory when no longer needed to avoid leaks.
 */

int main(void) {
    size_t n = 5;
    // Watch for integer overflow when computing allocation sizes in real code:
    //   if (n > SIZE_MAX / sizeof *arr) { /* handle error */ }
    // Use calloc when you want zero-initialized memory.
    int *arr = malloc(n * sizeof *arr);
    if (!arr) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    for (size_t i = 0; i < n; ++i) {
        arr[i] = (int)((i + 1) * 10);
    }
    for (size_t i = 0; i < n; ++i) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    free(arr);
    return 0;
}

/* Realloc example: grow and preserve contents (exercise). This helper shows a
 * safe realloc pattern: use a temporary pointer and only replace the original
 * when realloc succeeds. If realloc fails, the original block remains valid
 * and must be freed by the caller. */
int example_realloc(void) {
    size_t n = 2;
    int *a = malloc(n * sizeof *a);
    if (!a) return 1;
    a[0] = 1; a[1] = 2;

    size_t new_n = 4;
    int *b = realloc(a, new_n * sizeof *b);
    if (!b) { free(a); return 1; }
    b[2] = 3; b[3] = 4;
    for (size_t i = 0; i < new_n; ++i) printf("r[%zu] = %d\n", i, b[i]);
    free(b);
    return 0;
}
