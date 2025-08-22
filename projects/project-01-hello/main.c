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
    /* Print a friendly greeting. Keep output simple and deterministic for automated checks. */
    printf("Hello, C learner!\n");

    /* 0 indicates success to the operating system. */
    return 0;
}
