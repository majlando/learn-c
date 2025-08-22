project-10-dynamic-memory

Goal
- Introduce `malloc`/`realloc`/`free` and common failure modes.

What to learn
- Correct sizing, checking return values, and freeing memory
- `realloc` strategies to avoid leaks

Exercises
- Implement a dynamic array with push/pop and test resizing and failure handling.

Build & test
- `build.ps1` and `build.sanitizer.ps1` (local sanitizers) are provided.

Note
- Check allocation results and keep examples deterministic for CI.
