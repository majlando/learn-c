#include <stdio.h>

/* project-07-arrays: fixed-size arrays and iteration. Keep arrays small and output deterministic. */
int main(void) {
    /*
     * Contract:
     *  - Inputs: none (uses a fixed array)
     *  - Outputs: lines showing each index and value
     *  - Success: prints lines and returns 0
     *  - Error modes: none expected
     *
     * Edge cases:
     *  - Off-by-one errors when computing array length
     *  - Using wrong format specifiers for indices and values
     */
    int nums[] = {10, 20, 30, 40, 50};
    size_t len = sizeof(nums) / sizeof(nums[0]);

    for (size_t i = 0; i < len; ++i) {
        /* print index and value; use %zu for size_t index */
        printf("nums[%zu] = %d\n", i, nums[i]);
    }

    /* 2D array example */
    int mat[2][3] = {{1,2,3},{4,5,6}};
    for (size_t r = 0; r < 2; ++r) {
        for (size_t c = 0; c < 3; ++c) {
            printf("mat[%zu][%zu] = %d\n", r, c, mat[r][c]);
        }
    }

    return 0;
}
