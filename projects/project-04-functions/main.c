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
    /* call the function declared in math.h and defined in math.c */
    /* build system should compile math.c and link the object */
    int s = add3(1, 2, 3);
    printf("1 + 2 + 3 = %d\n", s);
    return 0;
}
