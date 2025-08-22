#include <stdio.h>

/* Arrays: 1D and 2D with sizeof-based lengths. */
int main(void) {
    int nums[] = {10, 20, 30, 40, 50};
    size_t len = sizeof nums / sizeof nums[0];
    for (size_t i = 0; i < len; ++i) printf("nums[%zu] = %d\n", i, nums[i]);

    int mat[2][3] = {{1,2,3},{4,5,6}};
    for (size_t r = 0; r < 2; ++r)
        for (size_t c = 0; c < 3; ++c)
            printf("mat[%zu][%zu] = %d\n", r, c, mat[r][c]);

    return 0;
}
