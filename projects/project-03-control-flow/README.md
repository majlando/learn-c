Lesson: Control Flow

Objectives
- Master `if/else`, `for`, `while`, and `do-while` constructs and use them idiomatically.
- Learn loop invariants, termination conditions, and common pitfalls (off-by-one).

Key points
- Prefer clear loop boundaries and avoid modifying loop variables inside the body unless intentional.
- Use `break` and `continue` sparingly; prefer explicit conditions when possible.

Edge cases
- Ensure loops terminate on all code paths; watch for infinite loops with user input.

Hints
- Rewrite the provided `for` loop as an equivalent `while` and `do-while`. Try nested loops and early `break`.

Build & Run
- Build: `gcc -Wall -Wextra -g -o project-03-control-flow.exe main.c`
- Run: `./project-03-control-flow.exe`

Exercises
- Convert the `for` loop to a `while` and a `do-while`.
- Add a nested loop that prints a simple multiplication table.
