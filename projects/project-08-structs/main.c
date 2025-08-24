#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*
 * project-08-structs: shows composite types (structs) and initialization.
 *
 * A struct groups related data into one object. Use fixed-size char arrays for
 * simple text fields in beginner examples. For production code prefer safer
 * patterns and validate lengths when copying strings.
 */

struct Person { char name[50]; int age; };
struct Point { int x, y; };
struct Node { struct Point pos; int id; };

/* typedef is common to simplify type names: */
typedef struct Node Node;

static void print_node(const Node *n) {
    /* Use -> to access fields through a pointer. */
    printf("Node id=%d pos=(%d,%d)\n", n->id, n->pos.x, n->pos.y);
}

int main(void) {
    struct Person p;
    /* snprintf truncates and always null-terminates when space permits. */
    snprintf(p.name, sizeof p.name, "%s", "Alice");
    p.age = 30;
    printf("Name: %s, Age: %d\n", p.name, p.age);

    struct Node n = {.pos = {10, 20}, .id = 7};
    print_node(&n);
    /* enum example: named integral constants */
    enum Color { RED = 0, GREEN = 1, BLUE = 2 };
    enum Color c = GREEN;
    printf("Color enum value = %d\n", c);
=======
#include <string.h>

/*
 * Project 08: Structs
 * Demonstrates struct initialization, nested structs, and arrays within structs.
 * Structs group related data and can be nested or contain arrays.
 */

struct Point { int x, y; };
struct Person {
    char name[50];
    int age;
    struct Point location; // nested struct
    int scores[3];         // array in struct
};
int main(void) {
    struct Person p = {"Alice", 30, {10, 20}, {90, 85, 88}}; // initialization
    printf("Name: %s, Age: %d\n", p.name, p.age);
    printf("Location: (%d, %d)\n", p.location.x, p.location.y);
    printf("Scores: %d, %d, %d\n", p.scores[0], p.scores[1], p.scores[2]);
    // Input example: update person's age
    int new_age;
    printf("Enter new age for %s: ", p.name);
    if (scanf("%d", &new_age) != 1 || new_age < 0) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }
    p.age = new_age;
    printf("Updated Age: %d\n", p.age);
    // Best practice: Always validate user input and check for valid struct field values.
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)
    return 0;
}
