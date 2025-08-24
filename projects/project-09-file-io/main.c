#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

/*
<<<<<<< HEAD
 * project-09-file-io: basic file writing and reading with error checks.
 *
 * Teaches:
 *  - always check FILE* returned by fopen
 *  - check return values of I/O functions (fprintf, fgets)
 *  - flush/close files when finished
 */

int main(void) {
    const char *fname = "sample.txt";

    /* Open for writing. "w" truncates or creates the file. Use "wb" for binary.
     * In production consider file permissions and atomic replace patterns. */
    FILE *f = fopen(fname, "w");
=======
 * Project 09: File I/O
 * Demonstrates file writing and reading with error checking.
 * Uses "w" for write (truncates/creates) and "r" for read.
 * Note: File paths and permissions may vary by platform.
 */

int main(void) {
    FILE *f = fopen("sample.txt", "w");
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
    if (!f) {
        perror("fopen write");
        return 1;
    }
<<<<<<< HEAD
    if (fprintf(f, "Hello file world\n") < 0) {
        perror("fprintf");
        fclose(f);
        return 1;
    }
    fclose(f);

    /* Open for reading and print each line. */
    f = fopen(fname, "r");
    if (!f) {
        /* perror prints a human-readable error message based on errno */
        perror("fopen read");
        /* Example: show errno value and strerror for learners (only on error) */
        int err = errno;
        fprintf(stderr, "errno=%d (%s)\n", err, strerror(err));
        return 1;
    }
    char buf[128];
    /* fgets reads at most sizeof(buf)-1 characters and null-terminates. */
    while (fgets(buf, sizeof(buf), f)) {
        printf("read: %s", buf);
    }
    if (ferror(f)) {
        perror("fgets");
        fclose(f);
        return 1;
    }
    fclose(f);

=======
    fprintf(f, "hello file\n");
    fclose(f);
    f = fopen("sample.txt", "r");
    if (!f) {
        perror("fopen read");
        return 1;
    }
    char buf[64];
    if (fgets(buf, sizeof(buf), f)) {
        printf("read: %s", buf);
    }
    fclose(f);
    // Input example: write user input to file
    char user_line[64];
    printf("Enter a line to write to file: ");
    if (fgets(user_line, sizeof(user_line), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    // Remove newline if present
    size_t len = strlen(user_line);
    if (len > 0 && user_line[len-1] == '\n') user_line[len-1] = '\0';
    f = fopen("user.txt", "w");
    if (!f) {
        perror("fopen user.txt");
        return 1;
    }
    fprintf(f, "%s\n", user_line);
    fclose(f);
    printf("Wrote to user.txt: %s\n", user_line);
    // Best practice: Always check file operations for errors and validate input.
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
    return 0;
}
