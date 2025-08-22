project-09-file-io

Goals
- Demonstrate basic file read/write using `fopen`, `fprintf`, `fgets`, and `fclose`.

Topics covered
- Text file I/O, error handling with `perror` and `errno`
- Binary I/O considerations and portable newline handling

Exercises
- Modify the program to append rather than overwrite; handle missing files gracefully.
- Add a small binary read/write exercise using a simple struct array.

Build & test
- `build.ps1` compiles and runs; the program creates `sample.txt` during execution and prints its contents.

Error handling
- Use `errno` and `strerror(errno)` to provide helpful messages on failure. Add tests for permission errors.

```markdown
project-09-file-io

Goal
- Demonstrate basic text file I/O with error checks.

What to learn
- `fopen` modes, `fprintf`/`fgets`, checking `ferror`
- Use `errno`/`perror` for helpful diagnostics

Exercises
- Modify the program to append instead of overwrite.
- Add a small binary read/write example using a struct array.

Note
- Keep file contents deterministic for automated tests.

```
Notes

- Keep file contents deterministic for tests.
