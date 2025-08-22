#include <stdio.h>
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
    return 0;
}
