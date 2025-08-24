<<<<<<< HEAD
<!-- Top-level README: brief repo purpose and how to build lessons -->
Learn C — small, focused C lessons under `projects/`.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

This repository contains compact, beginner-friendly C lessons. Each lesson is self-contained with source files and a small build script so it's easy to build, run, and validate locally or in CI.

Quick start
-----------

Use PowerShell on Windows (examples below use pwsh). From the repository root:

- Build and validate all projects (single-run helper):

```pwsh
pwsh -NoProfile -ExecutionPolicy Bypass -File ./run-all-builds.ps1
```

- Build a single project (example):

```pwsh
pwsh -NoProfile -ExecutionPolicy Bypass -File ./projects/project-04-functions/build.ps1
```

What the repo contains
----------------------

Keep in mind the repository focuses on lesson source, per-lesson build scripts, and deterministic expected outputs. Key files and helpers:

- `projects/<project-XX-name>/` — project folders containing `main.c`, optional companion `.c` and `.h` files, `build.ps1`, and `expected.txt` or `tests/`.
- `build-all.ps1` — builds projects, captures program output to `actual.txt`, and compares to `expected.txt` when present.
- `scripts/` — safe helpers for validating and cleaning working-tree artifacts (for example `check-no-artifacts.ps1`, `cleanup-artifacts.ps1`, `validate-lessons.ps1`, `run-lesson-tests.ps1`).

Note: previously-available destructive history-rewrite helpers have been removed or replaced with harmless stubs. If you need to rewrite history to remove large artifacts, coordinate with maintainers and follow documented manual procedures.

Projects (current)
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

Testing and sanitizers
----------------------

`build-all.ps1` will try to run each project's `build.ps1` (if present), execute the produced program or compile `main.c` with `gcc`, and write program output to `actual.txt` for comparison with `expected.txt`.

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
=======
# Learn C — Small, Focused C Lessons

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

This repository contains compact, beginner-friendly C lessons. Each lesson is self-contained with source files so it's easy to build and run locally.

## Quick Start

- Each project is in its own folder under `projects/` and contains C source files (`main.c`, and sometimes additional `.c` or `.h` files).
- To build and run a lesson, use your C compiler (e.g., `gcc main.c -o main && ./main`).
- No build scripts or test artifacts are included; only source code and this README remain.

## What the Repo Contains

- `projects/<project-XX-name>/` — project folders containing `main.c` and optional companion `.c` and `.h` files.
- `README.md` — this file, with an overview and project list.

## Projects (Current)

Each project demonstrates a key C concept. Most now include user input/output examples, improved comments, and best practices for error handling and memory safety.

- **project-01-hello** — minimal program, program structure, user input
- **project-02-variables** — variables, initialization, printing, user input
- **project-03-control-flow** — branching, loops, user-driven switch
- **project-04-functions** — function decomposition, headers, modularity, user input
- **project-05-pointers** — pointers, memory layout, user-driven array modification
- **project-06-strings** — C string handling, safe APIs, user input
- **project-07-arrays** — arrays, indexing, user-driven modification
- **project-08-structs** — composite types, initializers, user-driven struct update
- **project-09-file-io** — file I/O, error handling, user-driven file writing
- **project-10-dynamic-memory** — malloc/realloc, safe memory use, user-driven allocation

## Contributing

When contributing lessons:
- Keep lessons small and focused (one or two learning points).
- Prefer safe APIs (e.g., `snprintf`) and check return values.
- Add comments explaining why certain practices are important (e.g., error handling, memory safety).
- Use header files for function prototypes and modularity where appropriate.

## Support & Questions

Open an issue or a pull request and maintainers will review it.

## License
>>>>>>> ebc12b1 (Initial commit: update lessons and README with input/output examples, modularity, and best practices)

MIT
