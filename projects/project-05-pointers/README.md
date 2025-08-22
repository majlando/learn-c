Lesson: Pointers Basics

Objectives
- Learn addresses, dereferencing, `NULL`, pointer types, and pointer arithmetic.
- Use pointers to modify caller variables, traverse arrays, and return multiple values.

Key points
- Casting pointers to `(void*)` for printing is portable; avoid printing addresses unless necessary.
- Pointer arithmetic depends on the pointed type (e.g., `p+1` advances by `sizeof(*p)`).

Edge cases
- Beware dangling pointers (pointing to freed or stack memory) and off-by-one when iterating arrays.

Hints
- Implement `void increment(int *p)` and a function that reverses an array in-place using pointers.

Build & Run
- Build: `gcc -Wall -Wextra -g -o project-05-pointers.exe main.c`
- Run: `./project-05-pointers.exe`

Exercises
- Write a function `void increment(int *p)` and call it from `main`.
- Implement an in-place array reverse function using pointer arithmetic.
