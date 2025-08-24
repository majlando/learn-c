#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
<<<<<<< HEAD
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
=======
 * Project 10: Dynamic Memory
 * Demonstrates malloc, realloc, and freeing memory in C.
 * Always check malloc/realloc for NULL. Freeing NULL is safe.
 */

int main(void) {
    int *arr = malloc(3 * sizeof *arr);
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
    if (!arr) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }
<<<<<<< HEAD

    for (size_t i = 0; i < n; ++i) {
        arr[i] = (int)((i + 1) * 10);
    }
    for (size_t i = 0; i < n; ++i) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    free(arr);
=======
    arr[0] = 10; arr[1] = 20; arr[2] = 30;
    for (int i = 0; i < 3; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    // Realloc: grow array to 5 elements
    int *tmp = realloc(arr, 5 * sizeof *arr);
    if (!tmp) {
        free(arr); // free original if realloc fails
        fprintf(stderr, "realloc failed\n");
        return 1;
    }
    arr = tmp;
    arr[3] = 40; arr[4] = 50;
    for (int i = 0; i < 5; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);
    arr = NULL;
    free(arr); // safe to free NULL
    // Input example: allocate user-defined array size
    int n;
    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }
    int *user_arr = malloc(n * sizeof *user_arr);
    if (!user_arr) {
        fprintf(stderr, "malloc failed for user_arr\n");
        return 1;
    }
    for (int i = 0; i < n; ++i) user_arr[i] = i + 1;
    printf("User array: ");
    for (int i = 0; i < n; ++i) printf("%d ", user_arr[i]);
    printf("\n");
    free(user_arr);
    // Best practice: Always check memory allocation and free memory to avoid leaks.
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
    return 0;
}

/* Realloc example: grow and preserve contents (exercise). This helper shows a
 * safe realloc pattern: use a temporary pointer and only replace the original
 * when realloc succeeds. If realloc fails, the original block remains valid
 * and must be freed by the caller. */
<<<<<<< HEAD
=======

>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
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
