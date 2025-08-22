Lesson: File I/O

Objectives
- Read and write text and binary files, check for errors using `fopen`/`ferror`/`perror`.

Key points
- Always check `fopen` result before using file pointers.
- Use `fgets` for line-based input and `fread`/`fwrite` for binary data.

Hints
- Experiment with `fseek` and `ftell` to determine file size.

Build & Run
- Build: `gcc -Wall -Wextra -g -o project-09-file-io.exe main.c`
- Run: `./project-09-file-io.exe`

Exercises
- Write and then read a binary file using `fwrite`/`fread`.
- Use `fseek`/`ftell` to read a file from its middle.
