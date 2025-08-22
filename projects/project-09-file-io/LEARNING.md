## project-09-file-io

Goal
- Demonstrate basic text file I/O with simple, deterministic output and clear error checks.

What to learn
- fopen modes: "w" to create/overwrite, "a" to append, "r" to read.
- fprintf for formatted writes; fgets for bounded, line-oriented reads.
- Check fopen return values and use perror/errno for diagnostics.
- Use ferror after reads to detect I/O errors.

Exercises
- Change the example to append instead of overwrite.
- Persist a small struct using fwrite/fread and validate it after reading.

Build & test
- `build.ps1` compiles and runs; the program writes `sample.txt` then prints its contents.
- Keep output deterministic so tests can compare stdout to expected output.

Notes
- Prefer text I/O for simple lessons; show binary I/O as an exercise.
- `build.ps1` compiles and runs; the program writes `sample.txt` then prints its contents.
