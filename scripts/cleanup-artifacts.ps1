# Cleanup generated artifacts across projects - safe to run from repo root
# Deletes: *.exe, output.txt, *.log, sample.txt, per-project README.md, project-* and test-* files

$projects = Get-ChildItem -Directory -Path "$PSScriptRoot\..\projects"
foreach ($p in $projects) {
    Write-Host "Cleaning $($p.Name)"
    Push-Location $p.FullName
    try {
    Get-ChildItem -File -Include project-*, test-* -ErrorAction SilentlyContinue | Remove-Item -Force -ErrorAction SilentlyContinue
        Get-ChildItem -File -Filter '*.exe' -ErrorAction SilentlyContinue | Remove-Item -Force -ErrorAction SilentlyContinue
        Get-ChildItem -File -Filter '*.log' -ErrorAction SilentlyContinue | Remove-Item -Force -ErrorAction SilentlyContinue
    if (Test-Path 'output.txt') { Remove-Item -Force 'output.txt' -ErrorAction SilentlyContinue }
        if (Test-Path 'sample.txt') { Remove-Item -Force 'sample.txt' -ErrorAction SilentlyContinue }
        if (Test-Path 'README.md') { Remove-Item -Force 'README.md' -ErrorAction SilentlyContinue }
        # remove expected outputs if present (expected.txt or tests/expected-*.txt)
    if (Test-Path 'expected.txt') { Remove-Item -Force 'expected.txt' -ErrorAction SilentlyContinue }
        $localTests = Join-Path $PSScriptRoot '..\projects\' | Split-Path -Parent # dummy to compute path
        if (Test-Path 'tests') {
            Get-ChildItem -Path 'tests' -Filter 'expected*.txt' -File -ErrorAction SilentlyContinue | Remove-Item -Force -ErrorAction SilentlyContinue
        }
    } finally {
        Pop-Location
    }
}
Write-Host "Cleanup complete."
