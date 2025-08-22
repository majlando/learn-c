project-10-dynamic-memory

Goals
- Introduce dynamic allocation with `malloc` and `free`, and emphasize correct allocation sizes.

What to keep in this lesson
- Small dynamic examples with deterministic contents that can be validated in CI.

Exercises
- Demonstrate realloc, detect allocation failures, and avoid leaks.

Build & test
- `build.ps1` supports a sanitizer build via `build.sanitizer.ps1` for checking memory errors locally.
Improvements for project-10-dynamic-memory

- Add exercises that intentionally leak memory and use sanitizers to find them (optional).
- Add tests for allocation failure handling and resizing arrays with `realloc`.
- Include a short checklist for safe `malloc`/`free` usage and common bugs.

Error handling (moved from project-18)

- Check return values from `malloc`/`realloc` and print informative errors using `strerror(errno)` when allocations fail. Example pattern:

```c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void *xmalloc(size_t n) {
	void *p = malloc(n);
	if (!p) {
		fprintf(stderr, "malloc failed (%zu bytes): %s\n", n, strerror(errno));
		return NULL;
	}
	return p;
}
```

- Add tests that simulate allocation failure (e.g., request extremely large allocations) and verify graceful handling.

Additional improvements

- Add exercises for building simple dynamic arrays, implementing `push_back` semantics, and shrinking arrays.
- Add an example linked-list implementation to show allocation patterns and freeing nodes.
