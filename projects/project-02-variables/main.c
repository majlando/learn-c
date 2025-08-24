#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h> /* nicer boolean type name */
#include <limits.h>  /* integer limits, optional for learners */
#include <float.h>   /* floating-point limits */

/*
 * project-02-variables: illustrate scalar types and printing.
 *
 * Notes for learners:
 *  - Use the correct printf format for each type: %d, %u, %ld, %lld, %f, %zu, etc.
 *  - Signed vs unsigned types behave differently with negative values.
 *  - `size_t` is the correct type for object sizes and array indexes.
 *  - Avoid printing raw pointer values in beginner code; platform representations
 *    vary and the address itself is rarely useful for learning basics.
 */

int main(void) {
    /* Integer types */
    int i = -42;                 /* signed regular int */
    unsigned int ui = 42u;      /* unsigned int literal has trailing 'u' */
    long l = 100000L;           /* long integer, literal uses 'L' */
    long long ll = 9000000000LL;/* 64-bit style on many platforms */

    /* Floating point types */
    float f = 1.2345f;          /* single-precision */
    double d = 2.718281828;     /* double-precision */

    /* Characters and strings */
    char ch = 'A';
    char s[] = "sample";

    /* Boolean and size types */
    _Bool ok = 1;               /* C99 boolean as integer 0/1 */
    bool ok2 = true;            /* <stdbool.h> provides `bool` and `true/false` */
    size_t n = 3;               /* portable size type */

    /* intptr_t can hold a pointer as an integer; avoid using it casually. */
    intptr_t ip = (intptr_t) &i; /* demo only; don't do pointer arithmetic with it */
    (void)ip; /* silence unused-variable warning in educational snippets */

    /* brief note for learners: limits like INT_MAX and DBL_MAX are in limits.h / float.h */
    (void)INT_MAX; (void)DBL_MAX;

    /* Print values using correct format specifiers. */
    printf("int i = %d\n", i);
    printf("unsigned ui = %u\n", ui);
    printf("long l = %ld\n", l);
    printf("long long ll = %lld\n", ll);

    printf("float f = %.4f\n", f);
    printf("double d = %.6f\n", d);

    printf("char ch = %c, string s = %s\n", ch, s);
    printf("_Bool ok = %d\n", ok);
    /* print the stdbool value in a readable way to avoid unused-variable warnings */
    printf("bool ok2 = %s\n", ok2 ? "true" : "false");

    printf("size_t n = %zu\n", n);
    /* For portability, print a placeholder for addresses in beginner lessons. */
    printf("pointer address (void*) = (address)\n");

=======
#include <stdbool.h>
#include <stdint.h>

/*
 * Project 02: Variables and Types
 * Demonstrates declaration and printing of basic C types, including edge cases.
 * Note: Type sizes may differ by platform.
 */

int main(void) {
    int i = -42;                // signed integer
    unsigned int ui = 42u;      // unsigned integer
    short sh = -123;            // short integer
    unsigned short ush = 123u;  // unsigned short integer
    long l = 100000L;           // long integer
    long long ll = 9000000000LL;// long long integer
    float f = 1.23f;            // single-precision float
    double d = 2.71828;         // double-precision float
    double d_inf = 1.0/0.0;     // double infinity edge case
    double d_nan = 0.0/0.0;     // double NaN edge case
    char ch = 'A';              // character
    char s[] = "hello";         // string (array of char)
    bool ok = true;             // boolean (C99)
    int8_t i8 = -8;             // 8-bit signed integer
    uint8_t u8 = 8u;            // 8-bit unsigned integer
    // Print all types
    printf("int: %d\nunsigned int: %u\nshort: %hd\nunsigned short: %hu\n", i, ui, sh, ush);
    printf("long: %ld\nlong long: %lld\n", l, ll);
    printf("float: %.2f\ndouble: %.5f\n", f, d);
    printf("double inf: %f\ndouble nan: %f\n", d_inf, d_nan);
    printf("char: %c\nstring: %s\n", ch, s);
    printf("bool: %s\n", ok ? "true" : "false");
    printf("int8_t: %d\nuint8_t: %u\n", i8, u8);
    // Comments: Use the correct format specifier for each type.
    //           Signed vs unsigned types behave differently with negative values.
    //           Strings are arrays of char ending with '\0'.
    //           Type sizes: sizeof(int), sizeof(short), etc. may differ by platform.
    // Input example: read an integer from the user
    int user_val;
    printf("Enter an integer: ");
    if (scanf("%d", &user_val) != 1) {
        // Error handling: input failed
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }
    printf("You entered: %d\n", user_val);
    // Best practice: Always validate user input and handle errors gracefully.
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
    return 0;
}
