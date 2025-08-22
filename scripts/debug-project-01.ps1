Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
$p = Join-Path $PSScriptRoot '..\projects\project-01-hello'
$exp = (Get-Content -Raw -Encoding UTF8 (Join-Path $p 'expected.txt')) -replace "`r`n","`n" -replace "`r","`n"
$act = (Get-Content -Raw -Encoding UTF8 (Join-Path $p 'run.actual.txt')) -replace "`r`n","`n" -replace "`r","`n"
Write-Host '--- EXPECTED LINES ---'
$exp -split "`n" | ForEach-Object { Write-Host "[$_]" }
Write-Host '--- ACTUAL LINES ---'
$act -split "`n" | ForEach-Object { Write-Host "[$_]" }
