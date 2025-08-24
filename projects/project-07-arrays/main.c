<<<<<<< HEAD
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

    /* Bitwise flags example: define and test simple flags. */
    const unsigned FLAG_A = 1u << 0; /* 0b001 */
    const unsigned FLAG_B = 1u << 1; /* 0b010 */
    const unsigned FLAG_C = 1u << 2; /* 0b100 */
    unsigned flags = FLAG_A | FLAG_C; /* set A and C */
    printf("FLAG_A set? %s\n", (flags & FLAG_A) ? "yes" : "no");
    printf("FLAG_B set? %s\n", (flags & FLAG_B) ? "yes" : "no");

=======

#include <stdio.h>

/*
 * Project 07: Arrays
 * Demonstrates array declaration, bounds, and passing arrays to functions.
 * Note: Accessing out-of-bounds is undefined behavior in C.
 */

void print_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}
int main(void) {
    int nums[] = {1, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    print_array(nums, size);
    // Array bounds: size is 3, valid indices are 0, 1, 2
    // Input example: let user set a value in the array
    int idx, val;
    printf("Enter index (0-2) and value: ");
    if (scanf("%d %d", &idx, &val) != 2 || idx < 0 || idx >= size) {
        fprintf(stderr, "Invalid input or index out of bounds.\n");
        return 1;
    }
    nums[idx] = val;
    print_array(nums, size);
    // Best practice: Always validate user input and check array bounds.
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
    return 0;
}
