#include <stdio.h>

/* project-09-file-io: write and read a small file */
int main(void) {
    /*
     * Contract:
     *  - Inputs: none (writes then reads `sample.txt`)
     *  - Outputs: lines read from the file printed to stdout
     *  - Success: creates/reads file and prints contents
     *  - Error modes: fopen failures (handled with perror)
     *
     * Edge cases:
     *  - File permission errors or missing working directory
     *  - Buffer size vs. line length (fgets handles trimming)
     */
    const char *fname = "sample.txt";

    /* write to a file */
    FILE *f = fopen(fname, "w");
    if (!f) {
        perror("fopen");
        return 1;
    }
    fprintf(f, "Hello file world\n");
    fclose(f);

    /* read from the file */
    f = fopen(fname, "r");
    if (!f) {
        perror("fopen");
        return 1;
    }
    char buf[128];
    while (fgets(buf, sizeof(buf), f)) {
        /* fgets retains the trailing newline if present; print as-is */
        printf("read: %s", buf);
    }
    fclose(f);

    /*
     * Note: To demonstrate binary I/O, you can write a small struct to a .bin file
     * using fwrite/fread and then verify contents. This example keeps behavior
     * deterministic and focuses on text I/O so tests remain stable.
     */

    return 0;
}
