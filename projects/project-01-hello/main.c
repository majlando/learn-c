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

/* small helper to show basic function structure */
static void print_version(void) {
    const int major = 1, minor = 0;
    printf("lesson 01 version %d.%d\n", major, minor);
}

int main(void) {
    /*
     * Contract:
     *  - Inputs: none (uses constant string)
     *  - Outputs: one line to stdout: "Hello, C learner!\n"
     *  - Success: prints greeting and returns 0
     *  - Error modes: none expected in this simple example
     *
     * Edge cases (for learners):
     *  - Terminal encoding and newline semantics on different platforms
     *  - Buffering: ensure newline to flush output when necessary
     */
    /* Print a friendly greeting. Keep output simple and deterministic for automated checks. */
    printf("Hello, C learner!\n");

    /* 0 indicates success to the operating system. */
    return 0;
}
