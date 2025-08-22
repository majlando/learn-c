Set-StrictMode -Version Latest

Push-Location -Path (Join-Path $PSScriptRoot '..\projects')
$failures = @()
$dirs = Get-ChildItem -Directory -Filter 'project-*' | Sort-Object Name

foreach ($d in $dirs) {
    $proj = $d.FullName
    Write-Host "==> Testing $($d.Name)"
    Push-Location $proj
    try {
        if (Test-Path './build.ps1') {
            # build and run, capture stdout
            & ./build.ps1 *> run.actual.txt
            if (-not (Test-Path './expected.txt')) {
                Write-Host "  - missing expected.txt, skipping comparison"
            } else {
                $actual = Get-Content ./run.actual.txt -Raw
                $expected = Get-Content ./expected.txt -Raw
                if ($actual -ne $expected) {
                    Write-Host "  - MISMATCH"
                    $diff = Compare-Object -ReferenceObject ($expected -split "\r?\n") -DifferenceObject ($actual -split "\r?\n") -SyncWindow 0
                    $diff | ForEach-Object { Write-Host "    $_" }
                    $failures += $d.Name
                } else {
                    Write-Host "  - OK"
                }
            }
        } else {
            Write-Host "  - no build.ps1, skipped"
        }
    } finally { Pop-Location }
}

Pop-Location

if ($failures.Count -ne 0) {
    Write-Host "\nTest failures: $($failures -join ', ')" -ForegroundColor Red
    exit 1
} else {
    Write-Host "\nAll project outputs match expected.txt" -ForegroundColor Green
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
