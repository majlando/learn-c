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
