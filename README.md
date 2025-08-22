Learn C - small incremental projects

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
<!-- CI badge removed or replace OWNER/REPO to enable -->

This repository contains a curated set of small, beginner-friendly C lessons in `projects/`.

Repository status
-----------------
- The repository was streamlined to focus on a core set of lessons and learning notes. Several advanced lessons were removed to keep the syllabus concise.
- Remaining lessons are intended as a progressive learning path from basic I/O to memory management and error handling.

Quick start (PowerShell)
------------------------

Build a single project (example):

```pwsh
# from the repository root
pwsh -NoProfile -ExecutionPolicy Bypass ./projects/project-01-hello/build.ps1
```

Build and validate all lessons:

```pwsh
pwsh -NoProfile -ExecutionPolicy Bypass ./build-all.ps1
```

Run the per-lesson validator (runs a lesson's `build.ps1` then compares output against `tests/` if present):

```pwsh
pwsh -NoProfile -ExecutionPolicy Bypass ./scripts/run-lesson-tests.ps1 -LessonPath ./projects/project-02-variables
```

Lesson template and exercises
-----------------------------

- Copy `scripts/lesson-template/` to create a new lesson folder under `projects/`.
- Each lesson should include `main.c`, `build.ps1` and `expected.txt` (or `tests/`) for automated checks.

CI and artifact policy
-----------------------

- A GitHub Actions workflow `.github/workflows/no-artifacts.yml` blocks commits containing common build artifacts such as `*.exe`.
- The repo includes `scripts/remove-exes-from-history.ps1` and `scripts/run-everything.ps1` to assist with removing committed binaries from history; these are destructive and require `git-filter-repo` (see scripts for usage).

Remaining lessons
-----------------
- project-01-hello — minimal program and program structure
- project-02-variables — variables, initialization, printing
- project-03-control-flow — branching and loops
- project-04-functions — function decomposition and headers
- project-05-pointers — pointers and memory layout
- project-06-strings — C string handling and pitfalls
- project-07-arrays — arrays and indexing
- project-08-structs — composite types and initializers
- project-09-file-io — file input/output and error handling
- project-10-dynamic-memory — malloc/realloc and safe memory use
- project-18-error-handling — error codes, errno, and robust programs

Contributing
------------

To add a lesson, create `projects/project-XX-name/` with `main.c`, `build.ps1`, and `expected.txt` or add `tests/` for automated cases. Keep lessons small and focused.

If you plan to rewrite history to remove committed binaries, follow `scripts/run-everything.ps1` (requires `git-filter-repo`) and coordinate with collaborators.

Questions or suggestions are welcome via issues or PRs on the repository.
