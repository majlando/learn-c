Lesson: Pitfalls (format strings & buffer overflow)

Objectives
- Demonstrate why uncontrolled format strings are dangerous.
- Show safe use of snprintf and how truncation behaves.

Build & Run
- Build: `gcc -Wall -Wextra -g -o project-11-pitfalls.exe main.c`
- Run: `./project-11-pitfalls.exe`

Notes
- This lesson intentionally demonstrates truncation and safe printing; do not use user input directly as printf format strings.
