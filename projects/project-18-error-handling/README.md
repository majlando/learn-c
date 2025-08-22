Lesson: Error Handling & `errno`

Objectives
- Learn common error-handling patterns using return codes and `errno`.

Key points
- Use `perror` or `strerror(errno)` to provide user-friendly error messages.

Hints
- Prefer returning non-zero exit codes for errors so scripts can detect failures.
