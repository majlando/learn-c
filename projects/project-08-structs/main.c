#include <stdio.h>
#include <string.h>

/* project-08-structs: simple struct usage */
struct Person {
    char name[50];
    int age;
};

int main(void) {
    struct Person p;
    /* use snprintf to safely write into fixed-size arrays */
    snprintf(p.name, sizeof(p.name), "%s", "Alice");
    p.age = 30;

    printf("Name: %s, Age: %d\n", p.name, p.age);
    return 0;
}
