#include <stdio.h>

/* project-09-file-io: write and read a small file */
int main(void) {
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
        printf("read: %s", buf);
    }
    fclose(f);

    return 0;
}
