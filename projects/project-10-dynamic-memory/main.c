#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* project-10-dynamic-memory: safe use of malloc/realloc/free and simple checks. */
int main(void) {
    size_t n = 5;
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

/* Realloc example: grow and preserve contents (exercise). */
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
