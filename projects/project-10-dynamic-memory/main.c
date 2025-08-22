#include <stdio.h>
#include <stdlib.h>

/* project-10-dynamic-memory: malloc and free */
int main(void) {
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
    return 0;
}
