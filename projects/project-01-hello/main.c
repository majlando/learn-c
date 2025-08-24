<<<<<<< HEAD
/*
 * project-01-hello: Minimal C program.
 *
 * This lesson shows the smallest useful program in C: a `main` function that
 * returns an integer status and prints a deterministic greeting. Learners
 * should notice the following:
 *  - `main` returns 0 to indicate success to the operating system.
 *  - `puts` prints a string and appends a newline automatically.
 *  - Standard headers are not strictly necessary for this tiny program on
 *    some platforms, but including them is good practice.
 */

#include <stdio.h>   /* puts, printf, FILE, etc. */
#include <stdlib.h>  /* general utilities; good habit for real programs */
#include <stdint.h>  /* fixed-width integer types, used in later lessons */

/* Alternate `main` signatures: `int main(int argc, char **argv)` is common when
 * programs inspect command-line arguments. This tiny example uses `main(void)`
 * to keep the lesson focused on basics. */

int main(void) {
    /* Print a simple, deterministic message to stdout. */
    puts("Hello, world!");

    /* Returning 0 indicates success. Non-zero values are error codes. */
=======
#include <stdio.h>

/*
 * Project 01: Hello World
 * Demonstrates a minimal C program that prints a message to the console.
 * Compile: gcc main.c -o hello
 * Run:     ./hello
 */

int main(void) {
    // Best practice: Always check the return value of input/output functions for errors.
    char name[50];
    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        // Error handling: input failed
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    // Remove newline if present
    size_t len = strlen(name);
    if (len > 0 && name[len-1] == '\n') name[len-1] = '\0';
    printf("Hello, %s!\n", name);
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
    return 0;
}
