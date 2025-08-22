Learn C — small, focused C lessons under `lessons/`.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

This repository contains compact, beginner-friendly C lessons. Each lesson is self-contained with source files and a small build script so it's easy to build, run, and validate locally or in CI.

Quick start
-----------

Use PowerShell on Windows (examples below use pwsh). From the repository root:

- Build and validate all lessons:

```pwsh
pwsh -NoProfile -ExecutionPolicy Bypass ./build-all.ps1
```

- Build a single lesson (example):

```pwsh
pwsh -NoProfile -ExecutionPolicy Bypass ./lessons/lesson-04-functions/build.ps1
```

What the repo contains
----------------------

Keep in mind the repository focuses on lesson source, per-lesson build scripts, and deterministic expected outputs. Key files and helpers:

- `lessons/<lesson-XX-name>/` — lesson folders containing `main.c`, optional companion `.c` and `.h` files, `build.ps1`, and `expected.txt` or `tests/`.
- `build-all.ps1` — builds lessons, captures program output to `actual.txt`, and compares to `expected.txt` when present.
- `scripts/` — safe helpers for validating and cleaning working-tree artifacts (for example `check-no-artifacts.ps1`, `cleanup-artifacts.ps1`, `validate-lessons.ps1`, `run-lesson-tests.ps1`).

Note: previously-available destructive history-rewrite helpers have been removed or replaced with harmless stubs. If you need to rewrite history to remove large artifacts, coordinate with maintainers and follow documented manual procedures.

Lessons (current)
-----------------
- lesson-01-hello — minimal program and program structure
- lesson-02-variables — variables, initialization, printing
- lesson-03-control-flow — branching and loops
- lesson-04-functions — function decomposition and headers
- lesson-05-pointers — pointers and memory layout
- lesson-06-strings — C string handling and safe APIs
- lesson-07-arrays — arrays and indexing
- lesson-08-structs — composite types and initializers
- lesson-09-file-io — file I/O and error handling
- lesson-10-dynamic-memory — malloc/realloc and safe memory use

Testing and sanitizers
----------------------

`build-all.ps1` will try to run each lesson's `build.ps1` (if present), execute the produced program or compile `main.c` with `gcc`, and write program output to `actual.txt` for comparison with `expected.txt`.

Some lessons include a sanitizer-enabled build script (`build.sanitizer.ps1`) for local testing with AddressSanitizer/UBSan. Sanitizer builds are opt-in and platform dependent.

Contributing
------------

When contributing lessons:

- Keep lessons small and focused (one or two learning points).
- Include `expected.txt` or a `tests/` directory with deterministic expected output.
- Prefer safe APIs (e.g., `snprintf`) and check return values.

If your change requires removing committed build artifacts from history, coordinate with maintainers before attempting any destructive rewrite.

Support & questions
-------------------

Open an issue or a pull request and maintainers will review it.

License
-------

MIT
