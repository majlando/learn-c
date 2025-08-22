Lesson: Functions, macros, and function pointers

Objectives
- Break code into reusable functions.
- Use simple preprocessor macros safely.
- Basic function pointer usage and typedefs.

Key points
- Prefer `static inline` functions over complex macros when possible.
- When using macros, wrap arguments in parentheses: `#define SQR(x) ((x) * (x))`.

Try it
- Experiment by converting the `SQR` macro into a `static inline` function and compare output.

Exercise
- Add a new function pointer type and call a math function through it.
