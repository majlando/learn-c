#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

/*
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
    if (!f) {
        perror("fopen write");
        return 1;
    }
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

    return 0;
}
