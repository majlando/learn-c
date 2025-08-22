#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*
 * project-06-strings: safe formatting, measuring, copying and tokenization.
 *
 * Teaches:
 *  - use of snprintf to avoid buffer overruns
 *  - strlen for measuring string length (excludes terminating '\0')
 *  - strncpy vs snprintf: prefer snprintf for guaranteed termination when possible
 *  - strtok is destructive to the input string; use a copy when you need the original
 */

int main(void) {
    char greeting[50];
    char name[] = "World";
    char csv[] = "red,green,blue"; /* will be modified by strtok (copy if you need original) */

    /* snprintf returns the number of characters that would have been written;
     * negative return indicates encoding error on some platforms. */
    if (snprintf(greeting, sizeof greeting, "Hello, %s", name) < 0) {
        return 1;
    }

    printf("%s\n", greeting);
    printf("length = %zu\n", strlen(greeting));

    char buf[20];
    if (snprintf(buf, sizeof buf, "%s", greeting) < 0) return 1;
    printf("copy: %s\n", buf);

    /* Tokenize CSV string. strtok modifies the string in place. If you need the
     * original, make a copy first. On POSIX use strtok_r for reentrancy. */
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
