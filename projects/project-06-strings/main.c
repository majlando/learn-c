#include <stdio.h>
#include <string.h>

/* project-06-strings: basic C strings and common functions */
int main(void) {
    char greeting[50]; /* writable buffer */
    char name[] = "World";       /* compiler-sized array */

    /* build greeting safely with snprintf to avoid buffer overruns */
    snprintf(greeting, sizeof(greeting), "Hello, %s", name);

    printf("%s\n", greeting);              /* prints: Hello, World */
    printf("length = %zu\n", strlen(greeting));

    /* copy into another buffer safely using snprintf */
    char buf[20];
    snprintf(buf, sizeof(buf), "%s", greeting);
    printf("copy: %s\n", buf);

    return 0;
}
