#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* project-05-pointers: pointers, arrays, and pointer-to-pointer basics. */

int main(void) {
    int x = 42;
    int *p = &x; /* p points to x */
    if (p == NULL) return 1; /* defensive, though not needed here */

    printf("x = %d\n", x);
    printf("p points to value = %d\n", *p); /* dereference p */

    /* Arrays and pointer arithmetic */
    int nums[] = {1, 2, 3};
    int *q = nums; /* equivalent to &nums[0] */
    const int *r = nums; (void)r;
    for (size_t i = 0; i < sizeof nums / sizeof nums[0]; ++i) {
        printf("nums[%zu] = %d\n", i, *(q + i));
    }

    /* Pointer-to-pointer: a variable that holds the address of another pointer. */
    int **pp = &p;
    printf("pointer-to-pointer points to value = %d\n", **pp);

    /* interactive example: update an array element safely */
    int arr[] = {10, 20, 30, 40};
    int idx, val;
    printf("Enter index (0-3) and value: ");
    if (scanf("%d %d", &idx, &val) == 2 && idx >= 0 && idx < 4) {
        arr[idx] = val;
        printf("arr[%d] is now %d\n", idx, arr[idx]);
    }

    return 0;
}

