#include <stdio.h>
#include <string.h>

/* project-08-structs: struct initialization, nesting, and arrays-in-struct. */

struct Point { int x, y; };
struct Person {
    char name[50];
    int age;
    struct Point location;
    int scores[3];
};

struct Node { struct Point pos; int id; };
typedef struct Node Node;

static void print_node(const Node *n) {
    printf("Node id=%d pos=(%d,%d)\n", n->id, n->pos.x, n->pos.y);
}

int main(void) {
    struct Person p = {"Alice", 30, {10, 20}, {90, 85, 88}};
    printf("Name: %s, Age: %d\n", p.name, p.age);
    printf("Location: (%d, %d)\n", p.location.x, p.location.y);
    printf("Scores: %d, %d, %d\n", p.scores[0], p.scores[1], p.scores[2]);

    struct Node n = {.pos = {10, 20}, .id = 7};
    print_node(&n);

    enum Color { RED = 0, GREEN = 1, BLUE = 2 };
    enum Color c = GREEN;
    printf("Color enum value = %d\n", c);

    /* Input example: update person's age */
    int new_age;
    printf("Enter new age for %s: ", p.name);
    if (scanf("%d", &new_age) == 1 && new_age >= 0) {
        p.age = new_age;
        printf("Updated Age: %d\n", p.age);
    }

    return 0;
}
