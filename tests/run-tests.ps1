param()

Push-Location -Path "$PSScriptRoot/.."
try {
    $projects = @(
        'projects/project-04-functions',
        'projects/project-05-pointers',
        'projects/project-09-file-io'
    )

    foreach ($p in $projects) {
        Write-Host "Building $p"
        Push-Location $p
        pwsh -NoProfile -ExecutionPolicy Bypass -File .\build.ps1
        if ($LASTEXITCODE -ne 0) { throw "Build failed for $p" }
        Write-Host "Running $p"
        $exe = Get-ChildItem -Filter "*.exe" | Select-Object -First 1
        if (-not $exe) { throw "No exe found in $p" }
    # Capture output reliably by redirecting stdout to a temp file
    $scriptRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
    $tempFile = Join-Path $scriptRoot "_proj_act.txt"
    if (Test-Path $tempFile) { Remove-Item $tempFile -Force }
    Start-Process -FilePath (Join-Path (Get-Location) $exe.Name) -NoNewWindow -Wait -RedirectStandardOutput $tempFile
    $out = Get-Content -Raw -Path $tempFile
        $expected = Get-Content -Raw -Path "expected.txt"
    # Normalize CRLF vs LF to avoid false mismatches on Windows runners
    $outNorm = ($out -replace "`r`n", "`n").Trim()
    $expectedNorm = ($expected -replace "`r`n", "`n").Trim()
    if ($outNorm -ne $expectedNorm) {
            Write-Host "--- ACTUAL (raw) ---"
            Write-Host $out
            Write-Host "--- EXPECTED (raw) ---"
            Write-Host $expected
            Write-Host "--- DIAGNOSTICS ---"
            Write-Host "actual length: $($outNorm.Length)"
            Write-Host "expected length: $($expectedNorm.Length)"
            Write-Host "actual lines:" 
            $outNorm -split "\n" | ForEach-Object { Write-Host "[$_]" }
            Write-Host "expected lines:" 
            $expectedNorm -split "\n" | ForEach-Object { Write-Host "[$_]" }
            throw "Output mismatch in $p"
        } else {
            Write-Host "OK: $p"
        }
    if (Test-Path $tempFile) { Remove-Item $tempFile -Force }
        Pop-Location
    }
    Write-Host "All selected tests passed."
} finally {
    Pop-Location
}
