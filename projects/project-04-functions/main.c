#include <stdio.h>
#include "math.h"  /* declares add3; math.c must be compiled and linked with this file */

/* project-04-functions: demonstrate decomposition into functions and use of
 * headers for declarations. */
static int times_two(int x) { return x * 2; }
static void swap_int(int *a, int *b) { int tmp = *a; *a = *b; *b = tmp; }

int main(void) {
    printf("add3(1,2,3) = %d\n", add3(1, 2, 3));
    printf("times_two(4) = %d\n", times_two(4));

    int x = 5, y = 7;
    printf("before swap: x=%d y=%d\n", x, y);
    swap_int(&x, &y);
    printf("after swap: x=%d y=%d\n", x, y);

    return 0;
}
