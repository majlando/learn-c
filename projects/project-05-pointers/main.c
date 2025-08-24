#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/*
 * project-05-pointers: basic pointer usage and safety notes.
 *
 * Key ideas:
 *  - pointers store addresses; use the `&` operator to take an address.
 *  - dereference with `*` to read or write the pointed-to object.
 *  - arrays decay to pointers to their first element in many expressions.
 *  - pointer-to-pointer shows how multilevel indirection works.
=======

/*
 * Project 05: Pointers
 * Demonstrates pointer declaration, assignment, dereferencing, arithmetic, and pointers to arrays.
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
 */

int main(void) {
    int x = 42;
<<<<<<< HEAD
    int *p = &x; /* p points to x */

    /* It's good practice to check pointers for NULL before dereferencing in
     * real code. Here `p` is valid, so dereference is fine. */
    if (p == NULL) return 1;

    printf("x = %d\n", x);
    printf("p points to value = %d\n", *p); /* dereference p */

    /* Arrays and pointer arithmetic */
    int nums[] = {1, 2, 3};
    int *q = nums; /* equivalent to &nums[0] */

    /* Example of const pointer to data to show intent: */
    const int *r = nums; (void)r;
    for (size_t i = 0; i < sizeof nums / sizeof nums[0]; ++i) {
        /* q + i advances by i elements (not bytes) */
        printf("nums[%zu] = %d\n", i, *(q + i));
    }

    /* Pointer-to-pointer: a variable that holds the address of another pointer. */
    int **pp = &p;
    printf("pointer-to-pointer points to value = %d\n", **pp);

=======
    int *p = &x; // pointer to int
    // Pointer safety: always check for NULL before dereferencing in real code
    if (p != NULL) {
        printf("x = %d\n", x);
        printf("*p = %d\n", *p);
    }
    // Pointer arithmetic
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr; // points to arr[0]
    printf("arr[0] = %d\n", *ptr);
    printf("arr[1] = %d\n", *(ptr + 1)); // pointer arithmetic
    // Pointer to array
    int *a_ptr = arr;
    for (int i = 0; i < 4; ++i) {
        printf("arr[%d] = %d\n", i, a_ptr[i]);
    }
    // Input example: let user set a value in the array
    int idx, val;
    printf("Enter index (0-3) and value: ");
    if (scanf("%d %d", &idx, &val) != 2 || idx < 0 || idx > 3) {
        fprintf(stderr, "Invalid input or index out of bounds.\n");
        return 1;
    }
    arr[idx] = val;
    printf("arr[%d] is now %d\n", idx, arr[idx]);
    // Best practice: Always validate user input and check pointer bounds.
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
    return 0;
}
