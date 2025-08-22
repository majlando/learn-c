Lesson: Arrays

Objectives
- Fixed-size arrays, iteration, and relationship to pointers.

Key points
- `sizeof(array)/sizeof(array[0])` yields element count for statically sized arrays.
- Passing arrays to functions decays to pointer; size must be tracked separately.

Hints
- Try iterating with pointer arithmetic instead of indexing.

Build & Run
- Build: `gcc -Wall -Wextra -g -o project-07-arrays.exe main.c`
- Run: `./project-07-arrays.exe`

Exercises
- Rewrite the loop using pointer arithmetic instead of indexing.
- Create a 2D static array and print its elements.
