# Contributing

Thank you for considering contributions. This repository holds small C lessons under `projects/`.

Guidelines
- New lessons should go into `projects/project-XX-short-name/` where `XX` is a two-digit number.
- Required files: `main.c`, `build.ps1`, `expected.txt` (optional but recommended).
- Keep lessons small (20–50 lines typical) and focused on one concept.
- Add an `exercises.txt` with 2–3 short exercises.

Build script expectations
- `build.ps1` should try `gcc` first then `cl` and produce an executable named `lesson-project-XX-name.exe` or similar.

Testing
- Each lesson should have an `expected.txt` describing the expected stdout. The repository includes `build-all.ps1` to help validate lessons.
