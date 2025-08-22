#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void) {
    FILE *f = fopen("/no/such/file.txt", "r");
    if (!f) {
        fprintf(stderr, "open failed: %s\n", strerror(errno));
        return 1;
    }
    fclose(f);
    return 0;
}
