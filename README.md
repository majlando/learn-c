Learn C — progressive, small C lessons

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

This repository contains a set of small, beginner-friendly C lessons under `projects/`. Each lesson is intentionally compact and designed to be easy to build, run, and test.

Quick start
-----------

Use PowerShell on Windows or a POSIX shell on other platforms. From the repository root:

- Build and validate all lessons (PowerShell):

```pwsh
pwsh -NoProfile -ExecutionPolicy Bypass ./build-all.ps1
```

- Build a single lesson (example):

```pwsh
pwsh -NoProfile -ExecutionPolicy Bypass ./projects/project-01-hello/build.ps1
```

How lessons are organized
-------------------------

Each lesson folder typically contains:
- `main.c` — the lesson source
- `build.ps1` — short build script used by `build-all.ps1`
- `expected.txt` or `tests/` — expected output (used by the validator)

To add a new lesson, copy `scripts/lesson-template/` and include `main.c`, `build.ps1`, and an `expected.txt` or a `tests/` directory.

CI and artifact policy
-----------------------

- A GitHub Actions workflow `.github/workflows/no-artifacts.yml` already blocks common committed build artifacts (for example `*.exe`).
- There are helper scripts in `scripts/` to assist with cleaning up committed binaries; see the scripts for usage and warnings — some operations are destructive and require `git-filter-repo`.

Lessons (current)
-----------------
- project-01-hello — minimal program and program structure
- project-02-variables — variables, initialization, printing
- project-03-control-flow — branching and loops
- project-04-functions — function decomposition and headers
- project-05-pointers — pointers and memory layout
- project-06-strings — C string handling and safe APIs
- project-07-arrays — arrays and indexing
- project-08-structs — composite types and initializers
- project-09-file-io — file I/O and error handling
- project-10-dynamic-memory — malloc/realloc and safe memory use
- project-11-pitfalls — short, safe demos of common C pitfalls

Testing and sanitizers
----------------------

- `build-all.ps1` runs each lesson's `build.ps1`, executes the produced program (or compiles `main.c` with `gcc`), writes program output to `actual.txt`, and compares it to `expected.txt` (or `tests/` when present).
- Lessons that provide `build.sanitizer.ps1` can be built with AddressSanitizer/UBSan locally or in CI to detect memory issues. Example:

```pwsh
pwsh -NoProfile -ExecutionPolicy Bypass ./projects/project-11-pitfalls/build.sanitizer.ps1
./projects/project-11-pitfalls/project-11-pitfalls.sanitized.exe
```

Contributing
------------

Please follow these guidelines when contributing lessons:

- Keep lessons small and focused (one or two small learning points).
- Include `expected.txt` or a `tests/` directory with deterministic expected output so CI can validate changes.
- Prefer safe APIs (e.g., `snprintf`) and check return values in examples.
- If your lesson demonstrates a pitfall, include a safe version and guidance for using sanitizers.

If you plan a destructive operation such as rewriting history to remove committed build artifacts, coordinate with collaborators and follow `scripts/run-everything.ps1` instructions carefully.

Support & questions
-------------------

Open an issue or a pull request — maintainers will review and provide feedback.

License
-------

MIT
