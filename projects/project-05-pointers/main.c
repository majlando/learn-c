#include <stdio.h>

/*
 * project-05-pointers: basic pointer usage.
 */
int main(void) {
    int x = 42;      /* a normal integer */
    int *p = &x;     /* p stores the address of x */

    printf("x = %d\n", x);
    /* *p dereferences the pointer to obtain the value stored at that address */
    printf("p points to value = %d\n", *p);
    /* avoid printing raw addresses in lesson output (non-deterministic) */

    return 0;
}
