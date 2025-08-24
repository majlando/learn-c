#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

/* project-09-file-io: basic file read/write with error checks. */

int main(void) {
    const char *fname = "sample.txt";

    FILE *f = fopen(fname, "w");
    if (!f) { perror("fopen write"); return 1; }
    if (fprintf(f, "Hello file world\n") < 0) { perror("fprintf"); fclose(f); return 1; }
    fclose(f);

    /* Open for reading and print each line. */
    f = fopen(fname, "r");
    if (!f) {
        perror("fopen read");
        int err = errno;
        fprintf(stderr, "errno=%d (%s)\n", err, strerror(err));
        return 1;
    }
    char buf[128];
    while (fgets(buf, sizeof buf, f)) printf("read: %s", buf);
    if (ferror(f)) { perror("fgets"); fclose(f); return 1; }
    fclose(f);

    /* Input example: write user input to a file */
    char user_line[64];
    printf("Enter a line to write to file: ");
    if (fgets(user_line, sizeof user_line, stdin) == NULL) return 1;
    size_t len = strlen(user_line);
    if (len > 0 && user_line[len - 1] == '\n') user_line[len - 1] = '\0';
    f = fopen("user.txt", "w");
    if (!f) { perror("fopen user.txt"); return 1; }
    fprintf(f, "%s\n", user_line);
    fclose(f);
    printf("Wrote to user.txt: %s\n", user_line);

    return 0;
}
