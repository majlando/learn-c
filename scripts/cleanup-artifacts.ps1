# Cleanup generated artifacts across projects - safe to run from repo root
# Deletes: *.exe, actual.txt, *.log, sample.txt, per-lesson README.md, lesson-* and test-* files

$projects = Get-ChildItem -Directory -Path "$PSScriptRoot\..\projects"
foreach ($p in $projects) {
    Write-Host "Cleaning $($p.Name)"
    Push-Location $p.FullName
    try {
        Get-ChildItem -File -Include lesson-*, test-* -ErrorAction SilentlyContinue | Remove-Item -Force -ErrorAction SilentlyContinue
        Get-ChildItem -File -Filter '*.exe' -ErrorAction SilentlyContinue | Remove-Item -Force -ErrorAction SilentlyContinue
        Get-ChildItem -File -Filter '*.log' -ErrorAction SilentlyContinue | Remove-Item -Force -ErrorAction SilentlyContinue
        if (Test-Path 'actual.txt') { Remove-Item -Force 'actual.txt' -ErrorAction SilentlyContinue }
        if (Test-Path 'sample.txt') { Remove-Item -Force 'sample.txt' -ErrorAction SilentlyContinue }
        if (Test-Path 'README.md') { Remove-Item -Force 'README.md' -ErrorAction SilentlyContinue }
    } finally {
        Pop-Location
    }
}
Write-Host "Cleanup complete."
