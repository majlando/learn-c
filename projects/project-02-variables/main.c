#include <stdio.h>

/*
 * project-02-variables: demonstrates basic variable types and formatting.
 *
 * Key concepts:
 *  - integer types (int), floating point (float/double), and char
 *  - printf format specifiers: %d, %f, %c, %zu, etc.
 *  - precision control for floating point output (e.g., %.2f)
 */
int main(void) {
    /*
     * Contract:
     *  - Inputs: none (program uses constants)
     *  - Outputs: three lines to stdout showing an int, a double, and a char
     *  - Success: prints values and returns 0
     *  - Error modes: none expected in this simple example
     *
     * Edge cases to consider (for learners):
     *  - Very large integers that overflow `int` (use long/long long)
     *  - Floating-point formatting and rounding surprises
     *  - Locale influence on decimal separators (not handled here)
     */
    /* integer */
    int a = 10;

    /* floating point */
    double b = 3.14159;

    /* character */
    char c = 'Z';

    /* Print variables using format specifiers:
     * %d - int
     * %.2f - double with 2 decimals
     * %c - char
     */
    /* print values in a compact, readable form */
    printf("int a = %d\n", a);
    printf("double b = %.2f\n", b);
    printf("char c = %c\n", c);

    /* Learners: try printing unsigned values with %u, long with %ld, and size_t with %zu. */
    return 0;
}
