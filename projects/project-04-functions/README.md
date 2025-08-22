Lesson: Functions & Separate Compilation

Objectives
- Learn function declaration vs definition, parameter passing (by value vs by pointer), and return types.
- Understand compilation units, header guards, and the linker's role in combining object files.

Key points
- Keep interfaces (headers) minimal: expose only what's needed by clients.
- Use `static` for internal helper functions to limit linkage.

Edge cases
- Be careful with pointer parameters and ownership: document whether the callee frees memory.

Hints
- Add more functions to `math.c` (e.g., multiply, safe_add) and declare them in `math.h`.

Build & Run
- Build: `gcc -Wall -Wextra -g -o project-04-functions.exe main.c math.c`
- Run: `./project-04-functions.exe`

Exercises
- Add a new function to `math.c` and call it from `main.c`.
- Experiment with `static` functions and see linker behavior.
