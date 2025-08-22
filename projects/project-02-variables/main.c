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
    /* integers */
    int i = -42;
    unsigned int ui = 42u;
    long l = 100000L;
    long long ll = 9000000000LL;

    /* floating point */
    float f = 1.2345f;
    double d = 2.718281828;

    /* characters and strings */
    char ch = 'A';
    char s[] = "sample";

    /* boolean-like (C99 _Bool) */
    _Bool ok = 1; /* true */

    /* size and pointer-sized types */
    size_t n = 3;
    intptr_t ip = (intptr_t) &i; /* storing pointer as integer for demonstration only */

    /* print values with appropriate format specifiers */
    printf("int i = %d\n", i);
    printf("unsigned ui = %u\n", ui);
    printf("long l = %ld\n", l);
    printf("long long ll = %lld\n", ll);

    printf("float f = %.4f\n", f);
    printf("double d = %.6f\n", d);

    printf("char ch = %c, string s = %s\n", ch, s);
    printf("_Bool ok = %d\n", ok);

    printf("size_t n = %zu\n", n);
    printf("intptr_t (pointer as integer) = %td\n", (ptrdiff_t) ip);

    /* demonstrate format mismatch pitfall: don't do this in production */
    /* printf("bad: %d\n", d); */

    return 0;
}
