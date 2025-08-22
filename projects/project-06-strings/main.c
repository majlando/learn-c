#include <stdio.h>
#include <string.h>

/* project-06-strings: basic C strings and common functions. Use safe APIs and check return values. */
int main(void) {
    char greeting[50]; /* writable buffer */
    char name[] = "World";       /* compiler-sized array */

    /* build greeting safely with snprintf to avoid buffer overruns */
    /* build greeting safely with snprintf to avoid buffer overruns */
    if (snprintf(greeting, sizeof(greeting), "Hello, %s", name) < 0) {
        /* snprintf failed unexpectedly; print minimal fallback */
        printf("Hello\n");
        return 1;
    }

    printf("%s\n", greeting);              /* prints: Hello, World */
    printf("length = %zu\n", strlen(greeting));

    /* copy into another buffer safely using snprintf; check return value */
    char buf[20];
    if (snprintf(buf, sizeof(buf), "%s", greeting) < 0) {
        printf("copy failed\n");
        return 1;
    }
    printf("copy: %s\n", buf);

    return 0;
}
