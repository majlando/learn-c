project-03-control-flow

Goals
- Demonstrate conditional statements (`if`/`else`, `switch`) and loops (`for`, `while`).

What to keep in this lesson
- A small, deterministic program that prints a known sequence so automated tests can verify output.

Exercises
- Change the loop bounds, add early returns, or convert a `for` loop into a `while` loop.

Build & test
- Use the included `build.ps1` to compile and run; CI compares program output to the expected result.

Further reading
- Control flow chapter; practice problems on nested loops and short-circuit evaluation.

project-03-control-flow — Goals & improvements

Topics covered
- `if`/`else`, `switch`, `for`, `while`, and loop control (`break`, `continue`)

Learning outcomes
- Translate real-world branching into control flow constructs; reason about loop invariants.

Exercises
- Handle negative numbers and zero; document decisions (e.g., treat negative as invalid input).
- Implement the same logic using `switch` where applicable.
- Refactor repetitive code into small functions.

Suggested tests
- Input sequences including negative, zero, and large values.
- Tests that ensure loops terminate and edge cases handled.
