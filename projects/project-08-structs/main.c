#include <stdio.h>
#include <string.h>

/* Structs: define, init, access fields, and nested struct example. */
#include <stdio.h>
#include <string.h>

struct Person { char name[50]; int age; };
struct Point { int x, y; };
struct Node { struct Point pos; int id; };

static void print_node(const struct Node *n) {
    printf("Node id=%d pos=(%d,%d)\n", n->id, n->pos.x, n->pos.y);
}

int main(void) {
    struct Person p;
    snprintf(p.name, sizeof p.name, "%s", "Alice");
    p.age = 30;
    printf("Name: %s, Age: %d\n", p.name, p.age);

    struct Node n = {.pos = {10, 20}, .id = 7};
    print_node(&n);
    return 0;
}
