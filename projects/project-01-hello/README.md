Lesson: Hello & Program Structure

Objectives
- Understand `main` function, `#include`, and basic I/O with `printf`.
- Learn how to compile and run a C program.

Key points
- `#include <stdio.h>` gives access to `printf`.
- `int main(void)` is the usual program entry point; return value reports status to the OS.

Hints
- Try building with `gcc -Wall -Wextra -g -o project-01-hello.exe main.c`.
- Exercise: modify the program to accept a name via `argv` and greet the user.

Build & Run
- Build: `gcc -Wall -Wextra -g -o project-01-hello.exe main.c`
- Run: `./project-01-hello.exe` (on Windows `project-01-hello.exe`)

Exercises
- Change the program to accept a name via `argv` and greet the user.
- Print the program name (`argv[0]`) and count of arguments.
