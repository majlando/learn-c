# learn-c

A small collection of beginner C lessons. Each lesson is a single, self-contained `main.c` under `projects/` and demonstrates a basic C concept.

Projects

- `project-01-hello` — Minimal program: prints a greeting.
- `project-02-variables` — Scalar types, printing, and basic input.
- `project-03-control-flow` — Loops, conditionals, bitwise ops, and switch.
- `project-04-functions` — Functions, prototypes, macros, and function pointers.
- `project-05-pointers` — Pointers, arrays, and pointer-to-pointer basics.
- `project-06-strings` — Strings, length, safe copy, and tokenization.
- `project-07-arrays` — 1D/2D arrays, computing lengths, and bounds-checking.
- `project-08-structs` — Struct initialization, nesting, and arrays inside structs.
- `project-09-file-io` — File read/write with error checking.
- `project-10-dynamic-memory` — malloc, realloc, free, and safe allocation patterns.

Build and run

To compile and run a single lesson (example: project-01-hello):

```bash
gcc -std=c11 -Wall -Wextra -o project-01-hello/project-01-hello project-01-hello/main.c
./project-01-hello/project-01-hello
```

To compile all lessons quickly (creates one executable per lesson):

```bash
for d in project-*; do
  if [ -f "$d/main.c" ]; then
    name=$(basename "$d")
    gcc -std=c11 -Wall -Wextra -o "$d/$name" "$d/main.c" || echo "compile failed: $d"
  fi
done
```

Quick syntax check (no binaries):

```bash
for f in project-*/main.c; do
  echo "Checking: $f"
  gcc -std=c11 -Wall -Wextra -fsyntax-only "$f"
done
```

Notes

- Many lessons include small interactive prompts (stdin). When running in automated environments, either provide input or remove/disable those prompts.
- Examples favor safe APIs (snprintf, fgets) and basic validation to be suitable for teaching.

Next steps

- Add per-lesson README or tests if you want runnable checks for CI.
- Open a PR with these changes or let me create a branch and push if you want.
