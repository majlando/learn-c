/* project-03-control-flow: loops, conditionals, bitwise ops, and switch. */

#include <stdio.h>

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

    // Small interactive example (optional during automated tests)
    printf("Enter a value (1 or 2): ");
    int user_v;
    if (scanf("%d", &user_v) == 1) {
        switch (user_v) {
        case 1: printf("User switch: one\n"); break;
        case 2: printf("User switch: two\n"); break;
        default: printf("User switch: other\n"); break;
        }
    }

    return 0;
}
