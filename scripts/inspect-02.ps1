Set-StrictMode -Version Latest
$proj = Join-Path $PSScriptRoot '..\projects\project-02-variables'
$expFile = Join-Path $proj 'expected.txt'
$actFile = Join-Path $proj 'run.actual.txt'

$exp = Get-Content $expFile -Raw -ErrorAction Stop
$act = Get-Content $actFile -Raw -ErrorAction Stop

$expLines = $exp -split "\r?\n"
$actLines = $act -split "\r?\n"

Write-Host "EXPECTED lines: $($expLines.Count)"
for ($i=0;$i -lt $expLines.Count; $i++) { Write-Host ("{0:000}: [{1}]" -f $i, $expLines[$i]) }
Write-Host "\nACTUAL lines: $($actLines.Count)"
for ($i=0;$i -lt $actLines.Count; $i++) { Write-Host ("{0:000}: [{1}]" -f $i, $actLines[$i]) }

Write-Host "\nCOMPARE-OBJECT:" 
$diff = Compare-Object -ReferenceObject $expLines -DifferenceObject $actLines -SyncWindow 0
$diff | ForEach-Object { Write-Host ("{0} {1}" -f $_.SideIndicator, ($_.InputObject -replace '\r','\r')) }

# Show byte lengths
Write-Host "\nByte lengths:"; Write-Host ("expected: {0}, actual: {1}" -f (Get-Item $expFile).Length, (Get-Item $actFile).Length)
