project-04-functions

Goals
- Show how to split code into multiple functions and files; demonstrate headers and separate compilation.

What to keep in this lesson
- A small example where one function is declared in a header and defined in another source file. Keep outputs deterministic.

Exercises
- Add more functions, write small tests, and experiment with `static` functions and linkage.

Build & test
- The lesson includes `math.c` and `math.h`; `build.ps1` compiles and links them together.

Further reading
- Translation units, the compilation pipeline, and header best practices.

project-04-functions — Goals & improvements

Topics covered
- Function declaration/definition, parameter passing, return values, scope, header files

Learning outcomes
- Break code into reusable functions, reason about parameter passing semantics.

Exercises
- Convert loops into functions and add unit-style tests.
- Demonstrate `const` parameters and pointer parameters for output values.
- Add a simple header `.h` for function prototypes and include it in the main file.

Suggested tests
- Tests for boundary input values and returned results.

Further reading
- Linkage, static functions, and header best practices.
