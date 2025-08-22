param(
    [switch]$Force
)

# Cleanup generated artifacts across projects. By default runs as a dry-run and lists
# candidate files. Pass -Force to actually delete.

$projects = Get-ChildItem -Directory -Path (Join-Path $PSScriptRoot '..\projects')
foreach ($p in $projects) {
    Write-Host "Inspecting $($p.Name)"
    Push-Location $p.FullName
    try {
        $toRemove = @()
        $toRemove += Get-ChildItem -File -Filter '*.exe' -ErrorAction SilentlyContinue
        $toRemove += Get-ChildItem -File -Filter '*.log' -ErrorAction SilentlyContinue
        if (Test-Path 'output.txt') { $toRemove += Get-Item -Path 'output.txt' }
        if (Test-Path 'sample.txt') { $toRemove += Get-Item -Path 'sample.txt' }
        # Do NOT delete README.md or expected.txt by default. Those are considered source.

        if ($toRemove.Count -eq 0) {
            Write-Host "  No common artifacts found for $($p.Name)"
        } else {
            Write-Host "  Candidate deletions:"
            $toRemove | ForEach-Object { Write-Host "    $_.FullName" }
            if ($Force) {
                $toRemove | Remove-Item -Force -ErrorAction SilentlyContinue
                Write-Host "  Deleted above items."
            } else {
                Write-Host "  Run with -Force to delete these files."
            }
        }
        # Also offer to clean tests/expected*.txt only with Force
        if ((Test-Path 'tests') -and $Force) {
            Get-ChildItem -Path 'tests' -Filter 'expected*.txt' -File -ErrorAction SilentlyContinue | Remove-Item -Force -ErrorAction SilentlyContinue
        }
    } finally {
        Pop-Location
    }
}
Write-Host "Cleanup complete (dry-run unless -Force specified)."
