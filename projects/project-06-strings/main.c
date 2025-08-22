#include <stdio.h>
#include <string.h>

/* project-06-strings: basic C strings and common functions. Use safe APIs and check return values. */
int main(void) {
    /*
     * Contract:
     *  - Inputs: none (uses hard-coded name)
     *  - Outputs: greeting line, length line, and copy line
     *  - Success: prints lines and returns 0
     *  - Error modes: snprintf failure (handled by fallback)
     *
     * Edge cases:
     *  - Buffer truncation if greeting exceeds buffer size (snprintf handles this)
     *  - strlen result and newline handling
     */
    char greeting[50]; /* writable buffer */
    char name[] = "World";       /* compiler-sized array */
    /* small tokenizer example input */
    char csv[] = "red,green,blue";

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

    /* simple tokenizer: use strtok_s on Windows, fallback to strtok */
#if defined(_MSC_VER)
    char *saveptr = NULL;
    char *tok = strtok_s(csv, ",", &saveptr);
    while (tok) {
        printf("tok: %s\n", tok);
        tok = strtok_s(NULL, ",", &saveptr);
    }
#else
    char *tok = strtok(csv, ",");
    while (tok) {
        printf("tok: %s\n", tok);
        tok = strtok(NULL, ",");
    }
#endif

    return 0;
}
