#include <stdio.h>

/* File I/O: write then read a deterministic text file with errors reported. */
int main(void) {
    const char *fname = "sample.txt";

    FILE *f = fopen(fname, "w");
    if (!f) { perror("fopen write"); return 1; }
    fprintf(f, "Hello file world\n");
    fclose(f);

    f = fopen(fname, "r");
    if (!f) { perror("fopen read"); return 1; }
    char buf[128];
    while (fgets(buf, sizeof(buf), f)) printf("read: %s", buf);
    if (ferror(f)) { perror("fgets"); fclose(f); return 1; }
    fclose(f);

    return 0;
}
