Lesson: Types & Variables

Objectives
- Learn basic scalar types: `int`, `double`, `char` and format specifiers.
- Understand `sizeof`, `sizeof(int)`, and how to print floats with precision.

Key points
- Use the correct `printf` format specifier for the type.
- Prefer `stdint.h` types for portability when needed.

Hints
- Try `-Wall` to see warnings for mismatches in format specifiers.

Build & Run
- Build: `gcc -Wall -Wextra -g -o project-02-variables.exe main.c`
- Run: `./project-02-variables.exe`

Exercises
- Print an unsigned value with `%u` and a `long` with `%ld`.
- Intentionally mismatch a format specifier and observe the compiler warning.
