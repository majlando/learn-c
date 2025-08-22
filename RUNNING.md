Running and cleaning the repo

Run all project builds (single command, safe per-process policy):

pwsh -NoProfile -ExecutionPolicy Bypass -File c:\code\learn-c\run-all-builds.ps1

Notes:
- Using -ExecutionPolicy Bypass only affects that process. It's safe for CI.
- If you prefer not to bypass, set a process-scoped policy instead:
  pwsh -NoProfile -Command "Set-ExecutionPolicy -Scope Process RemoteSigned; ./run-all-builds.ps1"

Cleaning artifacts (dry-run default):
- The cleanup script is conservative by default. To preview deletions (dry-run):
  pwsh ./scripts/cleanup-artifacts.ps1
- To actually delete common artifacts (exe, log, output.txt):
  pwsh ./scripts/cleanup-artifacts.ps1 -Force

Checking for committed artifacts:
- Use the check script to detect committed binaries (requires git):
  pwsh ./scripts/check-no-artifacts.ps1


If you want me to apply any further hardening (signing, strict logging, unit tests), say what you want next.
