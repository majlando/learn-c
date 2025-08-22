Lesson: Strings & Character Arrays

Objectives
- Understand C-strings as null-terminated byte arrays.
- Learn safe string handling using `snprintf` and `strlen`.

Key points
- Avoid buffer overflows; prefer `snprintf` and check sizes.
- Remember strings are arrays of `char` (not a separate string type).

Hints
- Try copying with `snprintf` into a smaller buffer and observe truncation.

Build & Run
- Build: `gcc -Wall -Wextra -g -o project-06-strings.exe main.c`
- Run: `./project-06-strings.exe`

Exercises
- Demonstrate truncation by copying into a smaller buffer.
- Show correct NUL-termination when using `strncpy` and pitfalls.
