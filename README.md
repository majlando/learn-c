Learn C - small incremental projects

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
<!-- CI badge removed or replace OWNER/REPO to enable -->

This workspace contains a set of small, beginner-friendly C projects under `projects/`.

Note: This repository has been streamlined to focus on the lesson sources. Older lessons and CI artifacts were removed to keep the learning path concise.

Quick start (PowerShell):

- Build a single project (example):
  ./projects/project-01-hello/build.ps1

- Build and run all projects (validates output vs expected):
  ./build-all.ps1

New lesson template and exercises:

- A lesson template is available in `scripts/lesson-template/` -> copy into `projects/project-XX-name/` and edit.
- Each lesson can include `exercises.txt` with short tasks for learners; many lessons already include them.


The CI workflow (`.github/workflows/ci.yml`) runs GCC on Ubuntu and the PowerShell validator on Windows. Locally you can run the validator directly:

```pwsh
# from the repository root
pwsh -NoProfile -ExecutionPolicy Bypass -File ./scripts/validate-lessons.ps1
```

Each project contains a `main.c`, `expected.txt`, and `build.ps1` that attempts to use `gcc` or `cl` if available.


Building and testing locally
---------------------------

This repository is focused on the lesson sources under `projects/` and includes a simple PowerShell build helper to run lessons locally.

Run the workspace build (PowerShell):

```pwsh
# from the repository root
pwsh -NoProfile -ExecutionPolicy Bypass -File ./build-all.ps1
```

Contributing
------------

To add a new lesson, create a new `projects/project-XX-name/` folder containing `main.c`, `build.ps1`, and `expected.txt` (optional). Keep lessons small and self-contained.

Curriculum (revamped)
---------------------

The repository now includes a full, ordered syllabus covering key C topics. Use `build-all.ps1` to run and validate each lesson.

0. `project-11-compilation` — build stages, preprocess/compile/link
1. `project-01-hello` — program structure and I/O
2. `project-12-types` — integer types, promotions, `stdint.h`
3. `project-03-control-flow` — branching and loops
4. `project-04-functions` — functions, headers, linkage
5. `project-05-pointers` — pointers, aliasing, and memory model
6. `project-06-strings` & `project-07-arrays` — strings and array handling
7. `project-08-structs` — structs, enums, bitfields
8. `project-09-file-io` — text/binary I/O and error handling
9. `project-10-dynamic-memory` & `project-15-data-structures` — malloc/realloc and linked lists
10. `project-13-preprocessor` — macros and conditional compilation
11. `project-14-sanitizers` — sanitizers and debugging
12. `project-16-capstone` — integration capstone (file-based small app)

Each lesson contains `exercises.txt` with suggested practice tasks; some lessons include sanitizer-friendly builds.
