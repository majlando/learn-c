#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* project-09-file-io: demonstrate writing and reading files and basic error handling. */
int main(void) {
    const char *fname = "sample.txt";

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

    f = fopen(fname, "r");
    if (!f) {
        perror("fopen read");
        return 1;
    }
    char buf[128];
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
