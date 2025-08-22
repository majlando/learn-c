#include <stdio.h>
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
 */

int main(void) {
    int x = 42;
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

    return 0;
}
