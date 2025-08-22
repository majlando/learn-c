<#
Build and validate all projects under `projects/`.

This script runs each project's `build.ps1` (if present), attempts to run the produced
executable or compiles `main.c` with gcc as a fallback, writes output to `actual.txt`,
and compares it to `expected.txt` when available.
#>
Set-StrictMode -Version Latest
Push-Location -Path $PSScriptRoot

# Notes: this script is intentionally conservative. It runs each project's build
# script if present and falls back to compiling `main.c` with gcc for quick checks.

$projects = Get-ChildItem -Path .\projects -Directory | Sort-Object Name
foreach ($p in $projects) {
    Write-Host "\n=== $($p.Name) ==="
    $projDir = Join-Path $p.FullName ''
    $buildScript = Join-Path $projDir 'build.ps1'
    if (Test-Path $buildScript) {
        Write-Host "Running build script: $buildScript"
    & pwsh -NoProfile -ExecutionPolicy Bypass -File $buildScript
    } else {
        Write-Host "No build.ps1 found, skipping build for $($p.Name)"
    }

    # Try to find an executable with the project name or a produced default
    $exe = Get-ChildItem -Path $projDir -Filter '*.exe' -File -ErrorAction SilentlyContinue | Select-Object -First 1
    $cmd = $null
    if ($exe) { $cmd = $exe.FullName }

    # If no exe, try running a default lesson executable name matching pattern
    if (-not $cmd) {
        $fallback = Join-Path $projDir "$($p.Name).exe"
        if (Test-Path $fallback) { $cmd = $fallback }
    }

    $actualFile = Join-Path $projDir 'actual.txt'
    if ($cmd) {
        Write-Host "Running: $cmd"
        # Redirect both stdout and stderr to the actual file for deterministic comparison
        & $cmd *>$actualFile
    } else {
        # If there's no exe, try running 'main.c' with gcc if available
        $mainC = Join-Path $projDir 'main.c'
        if (Test-Path $mainC) {
            $tempExe = Join-Path $projDir 'lesson-temp.exe'
            # try gcc
            $gcc = Get-Command gcc -ErrorAction SilentlyContinue
            if ($gcc) {
                gcc -o $tempExe $mainC
                if (Test-Path $tempExe) { & $tempExe *>$actualFile; Remove-Item $tempExe -Force }
            } else {
                Write-Host "gcc not found; skipping run for $($p.Name)"
            }
        }
    }

    # Compare with expected.txt when present
    $expected = Join-Path $projDir 'expected.txt'
    if ((Test-Path $expected) -and (Test-Path $actualFile)) {
        # read contents and normalize line endings
        $expLines = Get-Content $expected | ForEach-Object { $_ -replace "\r","" }
        $actLines = Get-Content $actualFile | ForEach-Object { $_ -replace "\r","" }

        # apply per-project ignore regex patterns if present (.ignore contains regex per line)
        $ignoreFile = Join-Path $projDir '.ignore'
        if (Test-Path $ignoreFile) {
            $patterns = Get-Content $ignoreFile | Where-Object { $_ -and -not ($_ -match '^\s*#') }
            if ($patterns) {
                $expLines = $expLines | Where-Object { $line = $_; -not ($patterns | Where-Object { $line -match $_ }) }
                $actLines = $actLines | Where-Object { $line = $_; -not ($patterns | Where-Object { $line -match $_ }) }
            }
        }

        $diff = Compare-Object -ReferenceObject $expLines -DifferenceObject $actLines
        if ($diff) {
            Write-Host "Output mismatch for $($p.Name)" -ForegroundColor Yellow
            $diff
            $global:anyMismatch = $true
        } else {
            Write-Host "OK: output matches expected" -ForegroundColor Green
        }
    }
}

Pop-Location
