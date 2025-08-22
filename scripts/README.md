Scripts quick reference

- `validate-expected.ps1` — validate `projects/*/expected.txt` for markdown fences and trailing blank lines. Supports `-Fix` to auto-normalize trivial issues.
- `run-project-tests.ps1` — run each `projects/project-*` `build.ps1`, capture output, and compare to `expected.txt`.
- `validate-lessons.ps1` — compile-and-compare harness (gcc/cl preferred) and will run per-project tests when present.
- `cleanup-artifacts.ps1` — list/remove generated artifacts (dry-run by default; use -Force to delete).
- `check-no-artifacts.ps1` — CI-level check for committed artifacts (uses `git ls-files` when available).

Developer helpers live in `scripts/dev/`.

Examples (CI-friendly):

```powershell
pwsh -NoProfile -ExecutionPolicy Bypass -File .\scripts\validate-expected.ps1 -Fix
pwsh -NoProfile -ExecutionPolicy Bypass -File .\scripts\run-project-tests.ps1
```
