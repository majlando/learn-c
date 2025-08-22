#include <stdio.h>

/* project-03-control-flow: examples of loops, conditionals, and switch. */
int main(void) {
    for (int i = 1; i <= 5; ++i) {
        printf("for: %d %s\n", i, (i % 2) ? "odd" : "even");
    }

    int j = 1;
    while (j <= 3) {
        printf("while: %d\n", j++);
    }

    int k = 0;
    do {
        printf("do-while: %d\n", k++);
    } while (k < 1);

    int v = 2;
    switch (v) {
    case 1: puts("switch: one"); break;
    case 2: puts("switch: two"); break;
    default: puts("switch: other"); break;
    }

    return 0;
}
