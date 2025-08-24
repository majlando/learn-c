#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <string.h>
/* project-02-variables: basic scalar types, printing, and input. */

int main(void) {
    int i = -42;                // signed integer
    unsigned int ui = 42u;      // unsigned integer
    short sh = -123;            // short integer
    unsigned short ush = 123u;  // unsigned short integer
    long l = 100000L;           // long integer
    long long ll = 9000000000LL;// long long integer
    float f = 1.23f;            // single-precision float
    double d = 2.71828;         // double-precision float
    char ch = 'A';              // character
    char s[] = "hello";       // string (array of char)
    bool ok = true;             // boolean (C99)
    int8_t i8 = -8;             // 8-bit signed integer
    uint8_t u8 = 8u;            // 8-bit unsigned integer

    printf("int: %d\nunsigned int: %u\nshort: %hd\nunsigned short: %hu\n", i, ui, sh, ush);
    printf("long: %ld\nlong long: %lld\n", l, ll);
    printf("float: %.2f\ndouble: %.5f\n", f, d);
    printf("char: %c\nstring: %s\n", ch, s);
    printf("bool: %s\n", ok ? "true" : "false");
    printf("int8_t: %d\nuint8_t: %u\n", i8, u8);

    // Input example: read an integer from the user
    int user_val;
    printf("Enter an integer: ");
    if (scanf("%d", &user_val) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }
    printf("You entered: %d\n", user_val);

    return 0;
}
