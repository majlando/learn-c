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
    /*
     * Contract:
     *  - Inputs: none (uses fixed loop bounds)
     *  - Outputs: five lines to stdout indicating odd/even for 1..5
     *  - Success: prints lines and returns 0
     *  - Error modes: none expected
     *
     * Edge cases:
     *  - Changing loop bounds could require updating tests; ensure determinism
     *  - Integer wrap/overflow for very large loops (not relevant here)
     */
    /* for-loop from 1 to 5 (inclusive). Keep output deterministic for tests. */
        for (int i = 1; i <= 5; ++i) {
            /* check remainder to determine even/odd */
            if (i % 2 == 0) {
                printf("%d is even\n", i);
            } else {
                printf("%d is odd\n", i);
            }
        }

        /* Learners: try changing the loop bounds and experiment with while/do-while loops. */
    return 0;
}
