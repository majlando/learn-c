Lesson: Dynamic Memory

Objectives
- Learn `malloc`, `calloc`, `realloc`, `free`, and patterns for dynamic arrays and strings.
- Understand ownership, lifetime, and typical allocation errors (OOB, double-free, leaks).

Key points
- Always check allocation results and free memory when done. Use `realloc` carefully (temp pointer).
- Initialize memory when needed (`calloc` or manual); freed memory must not be used.

Edge cases
- Realloc moving memory invalidates other pointers into the old block; update references carefully.

Hints
- Use sanitizers (ASan/LSan) to detect leaks and OOB accesses during development.

Build & Run
- Build: `gcc -Wall -Wextra -g -o project-10-dynamic-memory.exe main.c`
- Run: `./project-10-dynamic-memory.exe`

Exercises
- Replace the static allocation pattern with `realloc` to grow the array.
- Intentionally create a small leak and detect it with AddressSanitizer.

Sanitizer builds
- A sanitizer build is provided: `build.sanitizer.ps1` which compiles with AddressSanitizer and UBSan flags.
- Run it on Linux with gcc: `pwsh -NoProfile -ExecutionPolicy Bypass ./build.sanitizer.ps1` then run the produced executable to see sanitizer reports.
