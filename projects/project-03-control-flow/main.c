/*
 * project-03-control-flow: loops, conditionals, and switch statements.
 *
 * This lesson demonstrates common control-flow constructs. Each example is
 * deterministic to make outputs easy to understand and test.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    /* for-loop with inline conditional expression (ternary operator). */
    for (int i = 1; i <= 5; ++i) {
        /* (i % 2) ? "odd" : "even" evaluates to one of the two strings. */
        printf("for: %d %s\n", i, (i % 2) ? "odd" : "even");
    }

    /* Example of break and continue (no output change here): */
    for (int x = 0; x < 3; ++x) {
        if (x == 1) continue; /* skip the rest of this iteration */
        if (x == 2) break;    /* exit the loop early */
    }

    /* while-loop: repeat while condition is true. Post-increment in printf. */
    int j = 1;
    while (j <= 3) {
        printf("while: %d\n", j++);
    }

    /* do-while: body runs at least once because condition is checked after. */
    int k = 0;
    do {
        printf("do-while: %d\n", k++);
    } while (k < 1);

    /* switch: pick a branch based on an integral value. break prevents fall-through. */
    int v = 2;
    /* switch fall-through is allowed in C; use comments or `break` to avoid surprises. */
    switch (v) {
    case 1:
        puts("switch: one");
        break;
    case 2:
        puts("switch: two");
        break;
    default:
        puts("switch: other");
        break;
    }

    return 0;
}
