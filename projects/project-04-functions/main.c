#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <stdint.h>
#include "math.h"  /* declares add3; math.c must be compiled and linked with this file */

/* Note: headers should have include guards (#ifndef/#define) to avoid double
 * inclusion. `math.h` here declares add3; the definition lives in math.c. */

/* Example macro: simple square. Prefer inline functions for type safety, but
 * macros are common in legacy C. */
#define SQR(x) ((x) * (x))

/* Example include-guard pattern (for use in header files):
 * #ifndef EXAMPLE_H
 * #define EXAMPLE_H
 * // declarations
 * #endif // EXAMPLE_H
 */

/*
 * project-04-functions: decomposition and header usage.
 *
 * This lesson shows:
 *  - splitting functionality into smaller functions for clarity and reuse.
 *  - using a header file (`math.h`) to declare functions implemented elsewhere.
 *  - `static` functions with internal linkage used only in this translation unit.
 */

/* small helper: double the input. Marked static because it's local to this file. */
static int times_two(int x) { return x * 2; }

/* swap two integers in-place via pointers. Demonstrates passing by reference. */
static void swap_int(int *a, int *b) { int tmp = *a; *a = *b; *b = tmp; }

/* Example typedef often used with structs and APIs: */
typedef int myint_t;

/* function-pointer typedef and example */
typedef int (*int_unary_fn)(int);

int main(void) {
    /* add3 is declared in math.h and defined in math.c which the build links. */
    printf("add3(1,2,3) = %d\n", add3(1, 2, 3));
    printf("times_two(4) = %d\n", times_two(4));
    /* call times_two through a function pointer to demonstrate syntax */
    int_unary_fn fn = times_two;
    printf("fn(times_two)(4) = %d\n", fn(4));

    /* use the macro example */
    printf("SQR(3) = %d\n", SQR(3));

    int x = 5, y = 7;
    printf("before swap: x=%d y=%d\n", x, y);
    swap_int(&x, &y); /* pass addresses so swap_int can modify caller's variables */
    printf("after swap: x=%d y=%d\n", x, y);

=======
#include "math.h"

/*
 * Project 04: Functions
 * Demonstrates defining and using functions with parameters, return values, and void functions.
 * Best practice: Use header files for function prototypes to improve modularity and maintainability.
 */

// Function returning a value
int add(int a, int b) {
    return a + b;
}

// Function with multiple parameters
int multiply(int a, int b, int c) {
    return a * b * c;
}

// Void function
void print_sum(int a, int b) {
    printf("sum of %d and %d is %d\n", a, b, a + b);
}

int main(void) {
    // User input example
    int x, y, z;
    printf("Enter three integers: ");
    if (scanf("%d %d %d", &x, &y, &z) != 3) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }
    printf("add(%d, %d) = %d\n", x, y, add(x, y));
    printf("multiply(%d, %d, %d) = %d\n", x, y, z, multiply(x, y, z));
    print_sum(x, y);
    printf("add3(%d, %d, %d) = %d\n", x, y, z, add3(x, y, z));
    // Best practice: Always validate user input and handle errors gracefully.
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
    return 0;
}
