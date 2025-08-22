#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

/*
 * project-07-arrays: demonstrates 1D and 2D arrays and how to compute lengths.
 *
 * Note: sizeof-based `len` is only valid in the same scope where the array is
 * defined. When arrays decay to pointers (e.g. function parameters), sizeof
 * will not give the element count. Use an explicit length parameter when
 * passing arrays to functions.
 */

int main(void) {
    int nums[] = {10, 20, 30, 40, 50};
    size_t len = sizeof nums / sizeof nums[0];
    for (size_t i = 0; i < len; ++i) {
        printf("nums[%zu] = %d\n", i, nums[i]);
    }

    int mat[2][3] = {{1,2,3},{4,5,6}};
    for (size_t r = 0; r < 2; ++r) {
        for (size_t c = 0; c < 3; ++c) {
            printf("mat[%zu][%zu] = %d\n", r, c, mat[r][c]);
        }
    }

    /* small hint: when passing `nums` to a function you would also pass `len`. */

    return 0;
}
