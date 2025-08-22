#include <stdio.h>

/* project-02-variables: demonstrate scalar types, printing, and basic conversions. */
int main(void) {
    int i = -42;
    unsigned int ui = 42u;
    long l = 100000L;
    long long ll = 9000000000LL;

    float f = 1.2345f;
    double d = 2.718281828;

    char ch = 'A';
    char s[] = "sample";

    _Bool ok = 1;
    size_t n = 3;
    intptr_t ip = (intptr_t) &i; /* demo only; avoid in production */
    (void)ip; /* silence unused-variable warnings in tutorial code */

    printf("int i = %d\n", i);
    printf("unsigned ui = %u\n", ui);
    printf("long l = %ld\n", l);
    printf("long long ll = %lld\n", ll);

    printf("float f = %.4f\n", f);
    printf("double d = %.6f\n", d);

    printf("char ch = %c, string s = %s\n", ch, s);
    printf("_Bool ok = %d\n", ok);

    printf("size_t n = %zu\n", n);
    /* print a deterministic placeholder instead of a raw address */
    printf("pointer address (void*) = (address)\n");

    return 0;
}
