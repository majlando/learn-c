#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* project-06-strings: strings, length, safe copy, and tokenization. */

int main(void) {
    char greeting[50];
    const char name[] = "World";
    if (snprintf(greeting, sizeof greeting, "Hello, %s", name) < 0) return 1;
    printf("%s\n", greeting);
    printf("length = %zu\n", strlen(greeting));

    char buf[20];
    if (snprintf(buf, sizeof buf, "%s", greeting) < 0) return 1;
    printf("copy: %s\n", buf);

    /* Tokenize CSV string. strtok modifies the string in place; copy if original needed. */
    char csv[] = "red,green,blue";
    char *tok = strtok(csv, ",");
    while (tok) {
        printf("tok: %s\n", tok);
        tok = strtok(NULL, ",");
    }

    /* Input example: read a word safely */
    char user_str[20];
    printf("Enter a word (max 19 chars): ");
    if (fgets(user_str, sizeof user_str, stdin) == NULL) return 1;
    size_t len = strlen(user_str);
    if (len > 0 && user_str[len - 1] == '\n') user_str[len - 1] = '\0';
    printf("You entered: %s\n", user_str);

    return 0;
}
