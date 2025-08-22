#include <stdio.h>
#include "math.h"  /* declares add3; math.c must be compiled and linked with this file */

/*
 * project-04-functions: demonstrate separate compilation units.
 *
 * Key concepts:
 *  - Declarations vs definitions: headers declare interfaces, .c files define implementations.
 *  - Header guards (in math.h) prevent multiple inclusion.
 *  - The linker resolves function references across translation units.
 */

/* local static helper for learners */
static int times_two(int x) { return x * 2; }

/* small swap using pointers to demonstrate pass-by-address */
static void swap_int(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int s = add3(1, 2, 3);
    printf("add3(1,2,3) = %d\n", s);

    printf("times_two(4) = %d\n", times_two(4));

    int x = 5, y = 7;
    printf("before swap: x=%d y=%d\n", x, y);
    swap_int(&x, &y);
    printf("after swap: x=%d y=%d\n", x, y);

    return 0;
}
