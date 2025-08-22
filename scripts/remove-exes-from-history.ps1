<#
PowerShell helper: instructions and commands to remove .exe files from Git history.

WARNING: Rewriting history is destructive. Read and follow instructions carefully.
Recommended workflow:
  1. Make a local backup clone: git clone --mirror <repo> repo-mirror.git
  2. Run the filter operation on the mirror (see commands below).
  3. Verify the mirror contains no .exe files: git ls-tree -r --name-only HEAD | grep '\.exe$'
  4. Force-push the cleaned mirror back to origin: git push --mirror --force
  5. In collaborators' clones, run: git fetch origin && git reset --hard origin/main (or recommended re-clone).

This script prints recommended commands and will optionally run them if run with -Run.
#>
param(
    [switch]$Run
)

Set-StrictMode -Version Latest
if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
    Write-Host "git not found in PATH. Install Git and re-run this script." -ForegroundColor Yellow
    exit 1
}

Write-Host "This script will show recommended commands to remove .exe files from git history." -ForegroundColor Cyan
Write-Host "READ THE INSTRUCTIONS. Back up your repository before rewriting history." -ForegroundColor Red

# Recommended git-filter-repo command
$filterRepoCmd = "git filter-repo --invert-paths --path-glob '*.exe' --path-glob 'projects/**/lesson-*.exe' --path-glob 'projects/**/project-*.exe'"

Write-Host "Recommended (safe) workflow (run from a cloned mirror):" -ForegroundColor Green
Write-Host "1. Create a mirror backup:"
Write-Host "   git clone --mirror <git-url> repo-mirror.git"
Write-Host "2. cd repo-mirror.git"
Write-Host "3. Run filter-repo to remove .exe files:"
Write-Host "   $filterRepoCmd"
Write-Host "4. Inspect the mirror to ensure .exe files are gone:"
Write-Host "   git ls-tree -r --name-only HEAD | Select-String -Pattern '\\.exe$' -Quiet; if ($?) { Write-Host 'Found .exe files' } else { Write-Host 'No .exe files found' }"
Write-Host "5. Force-push cleaned mirror back to origin:"
Write-Host "   git push --mirror --force"
Write-Host "6. In local clones, users must re-clone or reset to the new history."

Write-Host "If git-filter-repo is not available, consider BFG (https://rtyley.github.io/bfg-repo-cleaner/) as an alternative." -ForegroundColor Yellow

if ($Run) {
    Write-Host "Running filter-repo is potentially destructive. Ensure you're in a mirror clone and have backups." -ForegroundColor Red
    if (-not (Get-Command git-filter-repo -ErrorAction SilentlyContinue)) {
        Write-Host "git-filter-repo not found. Install it (https://github.com/newren/git-filter-repo) or run the commands manually." -ForegroundColor Yellow
        exit 1
    }
    Write-Host "Running: $filterRepoCmd" -ForegroundColor Cyan
    iex $filterRepoCmd
}
