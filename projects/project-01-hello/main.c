#include <stdio.h>

/*
 * project-01-hello: minimal C program.
 * Purpose: verify compiler and runtime are working and introduce program structure.
 *
 * Key concepts:
 *  - `#include <stdio.h>` brings in the declaration for `printf`.
 *  - `main` is the program entry point; `int` return type reports status to the OS.
 *  - `printf` writes formatted text to standard output (the console).
 *  - `\n` is a newline character (important to flush lines on some systems).
 */

int main(void) {
    /* Simple hello program. Deterministic output for tests. */
    printf("Hello, world!\n");
    return 0;
}
