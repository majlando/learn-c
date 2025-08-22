#include <stdio.h>
#include <string.h>

/* project-08-structs: simple struct usage */
struct Person {
    char name[50];
    int age;
};

int main(void) {
    /*
     * Contract:
     *  - Inputs: none (uses hard-coded values)
     *  - Outputs: one line to stdout with a person's name and age
     *  - Success: prints the formatted Person and returns 0
     *  - Error modes: none expected in this small example
     *
     * Edge cases to consider (for learners):
     *  - Name truncation if input exceeds buffer (use dynamic allocation or larger buffers)
     *  - Signedness and range of `int` for `age`
     *  - Mixing text encodings; C strings are raw bytes terminated by '\0'
     */
    struct Person p;
    /* use snprintf to safely write into fixed-size arrays */
    snprintf(p.name, sizeof(p.name), "%s", "Alice");
    p.age = 30;

    printf("Name: %s, Age: %d\n", p.name, p.age);
    return 0;
}
