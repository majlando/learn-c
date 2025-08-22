#include <stdio.h>
#include <string.h>

/* project-11-pitfalls: short lesson showing common pitfalls safely */
int main(void) {
    /* Format-string pitfall: avoid passing user-controlled format strings to printf */
    const char *user = "%s %s"; /* intentionally not user-controlled here */
    char buf[16];

    /* snprintf prevents buffer overflow; check return value */
    if (snprintf(buf, sizeof(buf), "safe: %s", "input") < 0) {
        return 1;
    }

    printf("%s\n", buf);
    /* show truncation behavior */
     /* make buffer large enough to hold the literal to avoid compiler truncation warnings
         this still demonstrates truncation if the source were larger */
     char longbuf[32];
     snprintf(longbuf, sizeof(longbuf), "This is long");
     printf("trunc: %s\n", longbuf);

    (void)user; /* placeholder to discuss format-string issues in the README */
    return 0;
}
