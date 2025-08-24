#include <stdio.h>
<<<<<<< HEAD
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

=======
#include <string.h>

/*
 * Project 06: Strings
 * Demonstrates string declaration, length, copying, and concatenation in C.
 * Strings are arrays of char ending with '\0'.
 */

int main(void) {
    char s1[20] = "hello";
    printf("string: %s\nlength: %zu\n", s1, strlen(s1));
    // String copying
    char s2[20];
    strcpy(s2, s1); // copy s1 to s2
    printf("copied string: %s\n", s2);
    // String concatenation
    strcat(s1, " world");
    printf("concatenated string: %s\n", s1);
    // Note: Always ensure enough space for copying/concatenation to avoid overflow.
    // Input example: read a string from the user
    char user_str[20];
    printf("Enter a word (max 19 chars): ");
    if (fgets(user_str, sizeof(user_str), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    size_t len = strlen(user_str);
    if (len > 0 && user_str[len-1] == '\n') user_str[len-1] = '\0';
    printf("You entered: %s\n", user_str);
    // Best practice: Always check buffer sizes and input validity to avoid overflow and bugs.
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
    return 0;
}
