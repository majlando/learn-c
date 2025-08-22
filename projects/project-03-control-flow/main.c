#include <stdio.h>

/*
 * project-03-control-flow: shows loops and branching.
 *
 * Key concepts:
 *  - for-loops and loop control
 *  - if/else branching
 *  - the modulus operator (%) to check divisibility
 */
int main(void) {
    /* for-loop */
    for (int i = 1; i <= 5; ++i) {
        if (i % 2 == 0)
            printf("for: %d is even\n", i);
        else
            printf("for: %d is odd\n", i);
    }

    /* while-loop */
    int j = 1;
    while (j <= 3) {
        printf("while: %d\n", j);
        ++j;
    }

    /* do-while: runs at least once */
    int k = 0;
    do {
        printf("do-while: %d\n", k);
        ++k;
    } while (k < 1);

    /* switch example */
    int v = 2;
    switch (v) {
    case 1:
        printf("switch: one\n");
        break;
    case 2:
        printf("switch: two\n");
        break;
    default:
        printf("switch: other\n");
    }

    return 0;
}
