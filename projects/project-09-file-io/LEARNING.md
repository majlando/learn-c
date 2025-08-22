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

Additional notes
- Discuss text vs binary modes and newline handling on Windows vs Unix.
project-09-file-io

Goals
- Demonstrate basic file read/write using fopen, fprintf, fgets, and fclose.

What to keep in this lesson
- Use a small known filename and deterministic content; keep sample files under version control if necessary.

Exercises
- Modify to append instead of overwrite; read files line-by-line and handle errors.

Build & test
- `build.ps1` compiles and runs; the program creates `sample.txt` during execution.
Improvements for project-09-file-io

- Add exercises to read/write binary files and to handle file-not-found gracefully.
- Add tests for file permission errors and truncated files.
- Document how to use `fopen` modes safely and portable newline handling.

Error handling (moved from project-18)

- Use `errno` and `strerror(errno)` to provide helpful error messages when I/O fails. For example:

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

FILE *open_or_warn(const char *path, const char *mode) {
	FILE *f = fopen(path, mode);
	if (!f) {
		fprintf(stderr, "open failed (%s): %s\n", path, strerror(errno));
	}
	return f;
}
```

- Add tests that simulate missing files or permission errors and verify programs print useful messages and exit non-zero.

Additional improvements

- Add an exercise to read and write binary files (e.g., simple struct array) and check endianness issues.
- Demonstrate portable newline handling and text vs binary modes on Windows vs Unix.
