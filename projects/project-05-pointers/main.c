#include <stdio.h>
#include <stddef.h>

/* project-05-pointers: addresses, dereference, pointer arithmetic and safety notes. */
int main(void) {
    int x = 42;
    int *p = &x;

    printf("x = %d\n", x);
    printf("p points to value = %d\n", *p);

    int nums[] = {1, 2, 3};
    int *q = nums;
    for (size_t i = 0; i < sizeof nums / sizeof nums[0]; ++i) {
        printf("nums[%zu] = %d\n", i, *(q + i));
    }

    int **pp = &p;
    printf("pointer-to-pointer points to value = %d\n", **pp);

    return 0;
}
