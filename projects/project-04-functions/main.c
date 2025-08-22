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

int main(void) {
    /*
     * Contract:
     *  - Inputs: none (calls add3 with constant arguments)
     *  - Outputs: one line to stdout showing the sum
     *  - Success: prints result and returns 0
     *  - Error modes: linker errors if math.c is not compiled/linked
     *
     * Edge cases:
     *  - Ensure math.c is compiled and linked; watch for mismatched prototypes
     *  - Integer overflow if add3 arguments are large
     */
    /* call the function declared in math.h and defined in math.c */
    /* build system should compile math.c and link the object */
    int s = add3(1, 2, 3);
    printf("1 + 2 + 3 = %d\n", s);

    /* demonstrate a local static helper for learners */
    static int times_two(int x) { return x * 2; }
    printf("2 * 4 = %d\n", times_two(4));

    return 0;
}
