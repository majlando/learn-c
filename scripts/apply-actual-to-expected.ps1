param(
    [string]$ProjectsRoot = (Join-Path $PSScriptRoot '..\projects'),
    [switch]$DryRun
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

$dirs = Get-ChildItem -Path $ProjectsRoot -Directory -Filter 'project-*' | Sort-Object Name
foreach ($d in $dirs) {
    $proj = $d.FullName
    $actual = Join-Path $proj 'run.actual.txt'
    $expected = Join-Path $proj 'expected.txt'
    if (-not (Test-Path $actual)) { Write-Host "No run.actual.txt for $($d.Name), skipping"; continue }
    Write-Host "Processing $($d.Name)"
    $txt = (Get-Content -Raw -Encoding UTF8 $actual) -replace "`r`n","`n" -replace "`r","`n"
    if (-not $txt.EndsWith("`n")) { $txt += "`n" }
    if (Test-Path $expected) {
        Write-Host "  Backing up $expected -> $($expected + '.bak')"
        if (-not $DryRun) { Copy-Item -Path $expected -Destination ($expected + '.bak') -Force }
    }
    Write-Host "  Writing expected from actual"
    if (-not $DryRun) { Set-Content -Path $expected -Value $txt -Encoding UTF8 -Force }
}

Write-Host "apply-actual-to-expected complete." -ForegroundColor Green

