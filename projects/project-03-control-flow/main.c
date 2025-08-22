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
    /* for-loop from 1 to 5 (inclusive)
     * i starts at 1, loop continues while i <= 5, and i increments after each iteration
     */
    for (int i = 1; i <= 5; ++i) {
        /* check remainder to determine even/odd */
        if (i % 2 == 0)
            printf("%d is even\n", i);
        else
            printf("%d is odd\n", i);
    }

    /* Learners: try changing the loop bounds and experiment with while/do-while loops. */
    return 0;
}
