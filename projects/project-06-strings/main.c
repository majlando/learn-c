#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* project-06-strings: safe string formatting, length, and tokenization examples. */
int main(void) {
    char greeting[50];
    char name[] = "World";
    char csv[] = "red,green,blue";

    if (snprintf(greeting, sizeof greeting, "Hello, %s", name) < 0) {
        return 1;
    }

    printf("%s\n", greeting);
    printf("length = %zu\n", strlen(greeting));

    char buf[20];
    if (snprintf(buf, sizeof buf, "%s", greeting) < 0) return 1;
    printf("copy: %s\n", buf);

#if defined(_MSC_VER)
    char *saveptr = NULL;
    char *tok = strtok_s(csv, ",", &saveptr);
    while (tok) { printf("tok: %s\n", tok); tok = strtok_s(NULL, ",", &saveptr); }
#else
    char *tok = strtok(csv, ",");
    while (tok) {
        printf("tok: %s\n", tok);
        tok = strtok(NULL, ",");
    }
#endif

    return 0;
}
