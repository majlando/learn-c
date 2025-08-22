param(
    [string]$ProjectsRoot = (Join-Path $PSScriptRoot '..\projects')
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

Push-Location -Path (Resolve-Path $ProjectsRoot)
$failures = [System.Collections.Generic.List[string]]::new()
$dirs = Get-ChildItem -Directory -Filter 'project-*' | Sort-Object Name

foreach ($d in $dirs) {
    $proj = $d.FullName
    Write-Host "==> Testing $($d.Name)"
    Push-Location $proj
    try {
        if (Test-Path './build.ps1') {
            # run build script and capture stdout/stderr to run.actual.txt (UTF8)
            try {
                & pwsh -NoProfile -ExecutionPolicy Bypass -File ./build.ps1 *>&1 | Out-File -FilePath run.actual.txt -Encoding UTF8
            } catch {
                Write-Host "  - build failed: $($_.Exception.Message)" -ForegroundColor Red
                $failures.Add($d.Name)
                continue
            }

            if (-not (Test-Path './expected.txt')) {
                Write-Host "  - missing expected.txt, skipping comparison"
                continue
            }

                # Read and normalize line endings: collapse any run of newlines to single LF, trim trailing newlines; use UTF8 explicitly
                $rawActual = Get-Content -Raw -Encoding UTF8 ./run.actual.txt
                $rawExpected = Get-Content -Raw -Encoding UTF8 ./expected.txt
                $normActual = [regex]::Replace($rawActual, '(\r\n|\r|\n)+', "`n").TrimEnd("`n")
                $normExpected = [regex]::Replace($rawExpected, '(\r\n|\r|\n)+', "`n").TrimEnd("`n")

            if ($normActual -ne $normExpected) {
                Write-Host "  - MISMATCH" -ForegroundColor Yellow
                # Split normalized content on any newline sequence (CRLF, LF, CR)
                $expLines = [regex]::Split($normExpected, '\r\n|\r|\n')
                $actLines = [regex]::Split($normActual, '\r\n|\r|\n')
                # Remove trailing empty lines from both arrays to avoid false mismatches due to extra blank lines
                while ($expLines.Count -gt 0 -and ($expLines[-1] -match '^[\s]*$')) { $expLines = $expLines[0..($expLines.Count-2)] }
                while ($actLines.Count -gt 0 -and ($actLines[-1] -match '^[\s]*$')) { $actLines = $actLines[0..($actLines.Count-2)] }
                $diff = Compare-Object -ReferenceObject $expLines -DifferenceObject $actLines -SyncWindow 0
                $diff | ForEach-Object { Write-Host "    $_" }
                $failures.Add($d.Name)
            } else {
                Write-Host "  - OK" -ForegroundColor Green
            }
        } else {
            Write-Host "  - no build.ps1, skipped"
        }
    } catch {
        Write-Host "  - error testing $($d.Name): $($_.Exception.Message)" -ForegroundColor Red
        $failures.Add($d.Name)
    } finally { Pop-Location }
}

Pop-Location

if ($failures.Count -ne 0) {
    Write-Host "`nTest failures: $($failures -join ', ')" -ForegroundColor Red
    exit 1
} else {
    Write-Host "`nAll project outputs match expected.txt" -ForegroundColor Green
    exit 0
}
param(
    [string]$ProjectPath
)

Set-StrictMode -Version Latest
if (-not (Test-Path $ProjectPath)) { Write-Error "Project path not found: $ProjectPath"; exit 2 }
$projectName = Split-Path -Leaf $ProjectPath
$testsDir = Join-Path $PSScriptRoot "..\tests\$projectName"
if (-not (Test-Path $testsDir)) { Write-Host "No tests for $projectName"; exit 0 }

# Build the project executable using existing per-project build.ps1 when present
$buildScript = Join-Path $ProjectPath 'build.ps1'
if (Test-Path $buildScript) {
    pwsh -NoProfile -ExecutionPolicy Bypass -File $buildScript
} else {
    Write-Error "No build.ps1 for $projectName; test harness requires project build script"
    exit 2
}

# Find executable produced (project-<name> or <name>.exe)
$exeCandidates = Get-ChildItem -Path $ProjectPath -Filter 'project-*' -File -ErrorAction SilentlyContinue | Select-Object -First 1
if (-not $exeCandidates) {
    $exeCandidates = Get-ChildItem -Path $ProjectPath -Filter '*.exe' -File -ErrorAction SilentlyContinue | Select-Object -First 1
}
if (-not $exeCandidates) { Write-Error "Cannot find built executable for $projectName"; exit 2 }
$exe = $exeCandidates.FullName

$cases = Get-ChildItem -Path $testsDir -Filter 'case-*.input' -File | Sort-Object Name
$fail = $false
foreach ($case in $cases) {
    $num = ($case.BaseName -replace 'case-','')
    $expFile = Join-Path $testsDir ("expected-$num.txt")
    $caseInput = Get-Content -Raw -Path $case.FullName

    # Run the executable and capture stdout/stderr using Start-Process
    $procInfo = New-Object System.Diagnostics.ProcessStartInfo
    $procInfo.FileName = $exe
    $procInfo.RedirectStandardInput = $true
    $procInfo.RedirectStandardOutput = $true
    $procInfo.RedirectStandardError = $true
    $procInfo.UseShellExecute = $false

    $proc = New-Object System.Diagnostics.Process
    $proc.StartInfo = $procInfo
    $proc.Start() | Out-Null
    $proc.StandardInput.Write($caseInput)
    $proc.StandardInput.Close()
    $stdout = $proc.StandardOutput.ReadToEnd()
    $stderr = $proc.StandardError.ReadToEnd()
    $proc.WaitForExit()

    $actual = ($stdout + "`n" + $stderr) -replace "`r", ''
    $expected = if (Test-Path $expFile) { (Get-Content -Raw -Path $expFile) -replace "`r", '' } else { "" }
    if ($actual.Trim() -ne $expected.Trim()) {
        Write-Host (("Test {0} case {1}: FAIL") -f $projectName, $num)
        Write-Host "--- expected ---"; $expected -split "`n" | ForEach-Object { Write-Host $_ }
        Write-Host "--- actual ---"; $actual -split "`n" | ForEach-Object { Write-Host $_ }
        $fail = $true
    } else {
        Write-Host (("Test {0} case {1}: PASS") -f $projectName, $num)
    }
}
if ($fail) { exit 1 } else { exit 0 }
