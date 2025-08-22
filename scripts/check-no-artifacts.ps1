<#
Fail if common build artifacts are present in the repository index (tracked by git).
This script prefers using `git ls-files` to detect committed/tracked artifacts. If git
is not available (rare in CI), it falls back to scanning the working tree for common
artifact patterns. Scanning the working tree is noisy after a build, so prefer git in CI.
#>
Set-StrictMode -Version Latest
Push-Location -Path (Join-Path $PSScriptRoot '..')

$patterns = @('*.exe','*.o','*.obj','*.dll','*.pdb')

try {
    # Prefer checking tracked files via git
    $git = Get-Command git -ErrorAction SilentlyContinue
    if ($git) {
        $bad = @()
        foreach ($p in $patterns) {
            $files = git ls-files -- $p 2>$null | Where-Object { $_ -ne '' }
            if ($files) { $bad += $files }
        }
        if ($bad.Count -gt 0) {
            Write-Host "Found committed build artifacts:" -ForegroundColor Red
            $bad | ForEach-Object { Write-Host $_ }
            exit 1
        }
        Write-Host "No committed build artifacts found."
        return 0
    } else {
        # git not available: fall back to scanning the working tree (less strict)
        $found = @()
        foreach ($p in $patterns) { $found += Get-ChildItem -Path . -Include $p -Recurse -File -ErrorAction SilentlyContinue }
        if ($found.Count -gt 0) {
            Write-Host "Found build artifact files in working tree (no git available):" -ForegroundColor Yellow
            $found | ForEach-Object { Write-Host $_.FullName }
            exit 1
        }
        Write-Host "No common build artifacts found."
        return 0
    }
} finally {
    Pop-Location
}
