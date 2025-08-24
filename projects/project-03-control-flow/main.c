<<<<<<< HEAD
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

=======
#include <stdio.h>

/*
 * Project 03: Control Flow
 * Demonstrates loops (for, while, do-while), conditionals, bitwise operations, and switch statements.
 */

int main(void) {
    // For loop: repeat 3 times
    for (int i = 0; i < 3; ++i) {
        printf("for: i = %d\n", i);
    }
    // While loop: repeat while j < 3
    int j = 0;
    while (j < 3) {
        printf("while: j = %d\n", j);
        j++;
    }
    // Do-while loop: always runs at least once
    int k = 0;
    do {
        printf("do-while: k = %d\n", k);
        k++;
    } while (k < 1);
    // If/else condition: compare x and y
    int x = 5, y = 3;
    if (x > y) {
        printf("%d is greater than %d\n", x, y);
    } else {
        printf("%d is not greater than %d\n", x, y);
    }
    // Bitwise operations: set and test flags
    unsigned int flags = 0;
    flags |= 1u << 0; // set bit 0
    flags |= 1u << 2; // set bit 2
    printf("flags: %u\n", flags);
    printf("bit 0 set? %s\n", (flags & (1u << 0)) ? "yes" : "no");
    printf("bit 1 set? %s\n", (flags & (1u << 1)) ? "yes" : "no");
    printf("bit 2 set? %s\n", (flags & (1u << 2)) ? "yes" : "no");
    // Switch statement: select case based on value
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
            break;
    }
    // Comments: For/while/do-while are common loop types. Bitwise ops are used for flags. Switch selects among cases.
    // Input example: let user choose a value for switch
    printf("Enter a value (1 or 2): ");
    int user_v;
    if (scanf("%d", &user_v) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }
    switch (user_v) {
        case 1:
            printf("User switch: one\n");
            break;
        case 2:
            printf("User switch: two\n");
            break;
        default:
            printf("User switch: other\n");
            break;
    }
    // Best practice: Always validate user input and handle errors gracefully.
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
    return 0;
}
