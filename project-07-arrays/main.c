#include <stdio.h>
#include <stddef.h>

/* project-07-arrays: 1D/2D arrays, lengths, and bounds. */

void print_array(const int arr[], int size) {
    for (int i = 0; i < size; ++i) printf("arr[%d] = %d\n", i, arr[i]);
}

int main(void) {
    int nums[] = {10, 20, 30, 40, 50};
    size_t len = sizeof nums / sizeof nums[0];
    for (size_t i = 0; i < len; ++i) printf("nums[%zu] = %d\n", i, nums[i]);

    int mat[2][3] = {{1,2,3},{4,5,6}};
    for (size_t r = 0; r < 2; ++r)
        for (size_t c = 0; c < 3; ++c)
            printf("mat[%zu][%zu] = %d\n", r, c, mat[r][c]);

    /* Bitwise flags example */
    const unsigned FLAG_A = 1u << 0;
    const unsigned FLAG_B = 1u << 1;
    const unsigned FLAG_C = 1u << 2;
    unsigned flags = FLAG_A | FLAG_C;
    printf("FLAG_A set? %s\n", (flags & FLAG_A) ? "yes" : "no");
    printf("FLAG_B set? %s\n", (flags & FLAG_B) ? "yes" : "no");

    /* Interactive example: set an element safely */
    int idx, val;
    printf("Enter index (0-%zu) and value: ", len - 1);
    if (scanf("%d %d", &idx, &val) == 2 && idx >= 0 && (size_t)idx < len) {
        nums[idx] = val;
        print_array(nums, (int)len);
    }

    return 0;
}
