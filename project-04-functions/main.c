/* project-04-functions: define and call functions, macros, and function pointers. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Simple macro example. Prefer inline functions in real APIs for type safety. */
#define SQR(x) ((x) * (x))

/* Small helpers with internal linkage. */
static int times_two(int x) { return x * 2; }
static void swap_int(int *a, int *b) { int tmp = *a; *a = *b; *b = tmp; }

typedef int myint_t;
typedef int (*int_unary_fn)(int);

/* Small library-style functions included here so the file compiles standalone. */
int add(int a, int b) { return a + b; }
int multiply(int a, int b, int c) { return a * b * c; }
void print_sum(int a, int b) { printf("sum of %d and %d is %d\n", a, b, a + b); }
int add3(int a, int b, int c) { return a + b + c; }

int main(void) {
    printf("add3(1,2,3) = %d\n", add3(1, 2, 3));
    printf("times_two(4) = %d\n", times_two(4));
    int_unary_fn fn = times_two;
    printf("fn(times_two)(4) = %d\n", fn(4));
    printf("SQR(3) = %d\n", SQR(3));

    int x = 5, y = 7;
    printf("before swap: x=%d y=%d\n", x, y);
    swap_int(&x, &y);
    printf("after swap: x=%d y=%d\n", x, y);

    /* small interactive example: read three integers and show function usage */
    int a, b, c;
    printf("Enter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) == 3) {
        printf("add(%d,%d) = %d\n", a, b, add(a, b));
        printf("multiply(%d,%d,%d) = %d\n", a, b, c, multiply(a, b, c));
        print_sum(a, b);
    }

    return 0;
}
