project-05-pointers

Goals
- Introduce pointers, the address-of (`&`) and dereference (`*`) operators, pointer arithmetic, and passing pointers to functions.

Topics covered
- Pointers to single variables and arrays
- Pointer arithmetic and iteration
- Const correctness and avoiding UB

Examples
- Show dereferencing, pointer arithmetic over a small array, and passing a pointer to a helper.

Exercises
- Implement a function that swaps two integers via pointers.
project-05-pointers

Goals
- Introduce pointers, address-of operator (`&`), dereference (`*`), and pointer arithmetic.

What to keep in this lesson
- Clear examples showing pointer usage; avoid UB and keep output deterministic.

Exercises
- Convert array indexing to pointer arithmetic; write functions that accept pointers.

Build & test
- Use `build.ps1` to compile and run; outputs are compared in CI.

Further reading
- Pointer pitfalls, ownership, and lifetime.

project-05-pointers — Goals & improvements

Topics covered
- Pointer basics, dereferencing, pointer arithmetic, `const` pointers, pointer to pointer

Learning outcomes
- Understand how pointers reference memory, how to use them for in-place modification.

Exercises
- Implement `swap(int *a, int *b)` and test with different values.
- Demonstrate pointer arithmetic on arrays, and show pointer aliasing pitfalls.
- Visualize stack vs heap addresses.

Suggested tests
- Tests for swap correctness and pointer arithmetic bounds.

Further reading
- Undefined behavior and how to avoid common pointer errors.
