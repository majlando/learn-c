param(
    [string[]]$Projects = @('projects\\project-01-hello','projects\\project-02-variables')
)

Set-StrictMode -Version Latest
foreach ($p in $Projects) {
    $expPath = Join-Path $p 'expected.txt'
    $actPath = Join-Path $p 'run.actual.txt'
    Write-Host "==== $p ===="
    if (Test-Path $expPath) {
        $exp = Get-Content -Raw -Encoding UTF8 $expPath
        Write-Host 'EXPECTED (escaped):'; Write-Host ($exp -replace "\r","\\r" -replace "\n","\\n")
        Write-Host ('expected length: {0}' -f $exp.Length)
    } else { Write-Host "No expected.txt at $expPath" }
    if (Test-Path $actPath) {
        $act = Get-Content -Raw -Encoding UTF8 $actPath
        Write-Host 'ACTUAL (escaped):'; Write-Host ($act -replace "\r","\\r" -replace "\n","\\n")
        Write-Host ('actual length: {0}' -f $act.Length)
    } else { Write-Host "No run.actual.txt at $actPath" }
    Write-Host ""
}
