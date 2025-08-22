Lesson: Structs & Composite Types

Objectives
- Define and use `struct` types, initialize them, and pass pointers to functions.

Key points
- Fixed-size char arrays inside structs need bounds-safe writes.
- Use designated initializers for readability.

Hints
- Try creating and returning a struct from a function (by value).

Build & Run
- Build: `gcc -Wall -Wextra -g -o project-08-structs.exe main.c`
- Run: `./project-08-structs.exe`

Exercises
- Use a designated initializer to initialize the `Person` struct.
- Write a function that accepts a `struct Person *` and updates its fields.
