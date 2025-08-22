<#
Run-everything helper: commit changes, remove tracked .exe files, and rewrite Git history to remove .exe artifacts.

USAGE (dry-run default):
  pwsh -NoProfile -ExecutionPolicy Bypass ./scripts/run-everything.ps1

To actually perform destructive history rewrite, pass -Run:
  pwsh -NoProfile -ExecutionPolicy Bypass ./scripts/run-everything.ps1 -Run

By default the script will:
  - Ensure you're in a git repo and working tree is clean
  - Stage and commit the prepared files (if they exist)
  - Detect tracked .exe files and stage their removal and commit
  - Create a bare mirror clone, run git-filter-repo to strip .exe files, and push the cleaned mirror

REQUIREMENTS:
  - Git installed and configured
  - git-filter-repo installed (preferred). If not available, the script will abort and show instructions for BFG alternative.
  - You must have push rights to the remote to force-push the cleaned mirror.

WARNING: Rewriting history is destructive. Back up/push a mirror before running. Communicate with collaborators.
#>

param(
    [switch]$Run,
    [string]$Remote = 'origin',
    [string]$Branch = 'main'
)

Set-StrictMode -Version Latest
Write-Host "Run-everything script started. Dry-run mode unless -Run is provided." -ForegroundColor Cyan

# Ensure git available
if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
    Write-Host "git not found in PATH. Install Git and re-run." -ForegroundColor Red
    exit 1
}

# Ensure inside a git repository
$top = & git rev-parse --show-toplevel 2>$null
if ($LASTEXITCODE -ne 0) {
    Write-Host "This folder is not a git repository. Run this script from your repository root." -ForegroundColor Red
    exit 1
}
Set-Location $top
Write-Host "Repository root: $top" -ForegroundColor Green

# Check working tree clean
$status = & git status --porcelain
if ($status) {
    Write-Host "Working tree has uncommitted changes. Please commit or stash them before running this script." -ForegroundColor Yellow
    Write-Host $status
    exit 1
}

# Files we intend to add/commit (only if present)
$toAdd = @(
    '.github/workflows/no-artifacts.yml',
    'scripts/cleanup-committed-exes.ps1',
    'scripts/remove-exes-from-history.ps1',
    'scripts/run-everything.ps1',
    'projects/project-17-concurrency/main.c'
)
$existing = $toAdd | Where-Object { Test-Path $_ }
if ($existing.Count -gt 0) {
    Write-Host "Will stage these files for commit:" -ForegroundColor Green
    $existing | ForEach-Object { Write-Host "  $_" }
    if ($Run) {
        & git add -- $existing
        & git commit -m "chore: fix concurrency unused param; add CI and cleanup scripts" || Write-Host "No commit created (nothing to commit)."
        Write-Host "Committed staged files." -ForegroundColor Green
    } else {
        Write-Host "Dry-run: to commit these files run with -Run" -ForegroundColor Yellow
    }
} else {
    Write-Host "No prepared files found to stage/commit." -ForegroundColor Yellow
}

# Detect tracked .exe files
$trackedExes = & git ls-files -- "*.exe" 2>$null | Where-Object { $_ -ne '' }
if ($trackedExes) {
    Write-Host "Tracked .exe files found:" -ForegroundColor Red
    $trackedExes | ForEach-Object { Write-Host "  $_" }

    if ($Run) {
        Write-Host "Staging removal of tracked .exe files..." -ForegroundColor Cyan
        & git rm --cached -r --ignore-unmatch -- $trackedExes
        & git commit -m "chore: remove tracked .exe build artifacts" || Write-Host "No commit created for removal."
        Write-Host "Committed removal of tracked .exe files." -ForegroundColor Green
    } else {
        Write-Host "Dry-run: to remove these tracked files, run with -Run" -ForegroundColor Yellow
    }
} else {
    Write-Host "No tracked .exe files found." -ForegroundColor Green
}

# Prepare to rewrite history via a mirror clone
$remoteUrl = (& git remote get-url $Remote) 2>$null
if ($LASTEXITCODE -ne 0 -or -not $remoteUrl) {
    Write-Host "Unable to determine remote URL for remote '$Remote'. Set remote or pass a different remote name." -ForegroundColor Red
    exit 1
}
Write-Host "Remote URL: $remoteUrl" -ForegroundColor Green

$mirrorDir = Join-Path -Path $env:TEMP -ChildPath ("repo-mirror-{0}" -f ([guid]::NewGuid().ToString('N')))
Write-Host "Mirror directory: $mirrorDir" -ForegroundColor Cyan

Write-Host "Next: create a mirror clone, run git-filter-repo to drop .exe paths, and force-push the cleaned mirror back to remote." -ForegroundColor Yellow

$filterCmd = "git filter-repo --invert-paths --path-glob '*.exe' --path-glob 'projects/**/lesson-*.exe' --path-glob 'projects/**/project-*.exe'"
Write-Host "Filter command: $filterCmd" -ForegroundColor Cyan

if (-not $Run) {
    Write-Host "Dry-run complete. Re-run with -Run to execute the destructive history rewrite steps." -ForegroundColor Yellow
    exit 0
}

# Confirm Run
Write-Host "You passed -Run. This will create a mirror clone and rewrite history. Proceeding..." -ForegroundColor Red

# Create mirror
& git clone --mirror $remoteUrl $mirrorDir
if ($LASTEXITCODE -ne 0) {
    Write-Host "Failed to clone mirror from $remoteUrl" -ForegroundColor Red
    exit 1
}

Push-Location $mirrorDir
try {
    # Ensure git-filter-repo present
    if (-not (Get-Command git-filter-repo -ErrorAction SilentlyContinue)) {
        Write-Host "git-filter-repo not found in PATH. Please install it (https://github.com/newren/git-filter-repo) and re-run this script." -ForegroundColor Red
        throw "git-filter-repo-missing"
    }

    Write-Host "Running git-filter-repo to strip .exe files from history..." -ForegroundColor Cyan
    iex $filterCmd
    if ($LASTEXITCODE -ne 0) { throw "filter-repo failed with exit code $LASTEXITCODE" }

    Write-Host "Pushing cleaned mirror back to remote (force)..." -ForegroundColor Cyan
    & git push --mirror --force $remoteUrl
    if ($LASTEXITCODE -ne 0) { throw "git push --mirror failed with exit code $LASTEXITCODE" }

    Write-Host "Mirror pushed. History rewritten on remote." -ForegroundColor Green
} finally {
    Pop-Location
    # Cleanup mirror dir
    try { Remove-Item -LiteralPath $mirrorDir -Recurse -Force -ErrorAction SilentlyContinue } catch { }
}

Write-Host "All done. Important: collaborators must re-clone or reset to the rewritten history." -ForegroundColor Yellow
Write-Host "Suggested post-steps for collaborators:" -ForegroundColor Cyan
Write-Host "  git fetch $Remote && git reset --hard $Remote/$Branch" -ForegroundColor Gray

Exit 0
