#include <stdio.h>

/*
 * project-05-pointers: basic pointer usage. Keep output deterministic for tests.
 */
int main(void) {
    /*
     * Contract:
     *  - Inputs: none (uses local variable `x`)
     *  - Outputs: two lines to stdout showing x and *p
     *  - Success: prints values and returns 0
     *  - Error modes: none expected; pointer is valid for local variable
     *
     * Edge cases:
     *  - Dangling pointers if pointer refers to freed memory (not here)
     *  - Printing raw addresses is non-deterministic and avoided
     */
    int x = 42;      /* a normal integer */
    int *p = &x;     /* p stores the address of x */

    printf("x = %d\n", x);
    /* *p dereferences the pointer to obtain the value stored at that address */
    printf("p points to value = %d\n", *p);
    /* avoid printing raw addresses in lesson output (non-deterministic) */

    /* pointer arithmetic example: iterate an array via pointer */
    int nums[] = {1, 2, 3};
    int *q = nums; /* points to first element */
    for (size_t i = 0; i < sizeof(nums)/sizeof(nums[0]); ++i) {
        printf("nums[%zu] = %d\n", i, *(q + i));
    }

    return 0;
}
