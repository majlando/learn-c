param(
    [string]$LessonPath
)

Set-StrictMode -Version Latest
if (-not (Test-Path $LessonPath)) { Write-Error "Lesson path not found: $LessonPath"; exit 2 }
$lessonName = Split-Path -Leaf $LessonPath
$testsDir = Join-Path $PSScriptRoot "..\tests\$lessonName"
if (-not (Test-Path $testsDir)) { Write-Host "No tests for $lessonName"; exit 0 }

# Build the lesson executable using existing per-lesson build.ps1 when present
$buildScript = Join-Path $LessonPath 'build.ps1'
if (Test-Path $buildScript) {
    pwsh -NoProfile -ExecutionPolicy Bypass -File $buildScript
} else {
    Write-Error "No build.ps1 for $lessonName; test harness requires lesson build script"
    exit 2
}

# Find executable produced (lesson-<name> or <name>.exe)
$exeCandidates = Get-ChildItem -Path $LessonPath -Filter 'lesson-*' -File -ErrorAction SilentlyContinue | Select-Object -First 1
if (-not $exeCandidates) {
    $exeCandidates = Get-ChildItem -Path $LessonPath -Filter '*.exe' -File -ErrorAction SilentlyContinue | Select-Object -First 1
}
if (-not $exeCandidates) { Write-Error "Cannot find built executable for $lessonName"; exit 2 }
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
        Write-Host ("Test {0} case {1}: FAIL" -f $lessonName, $num)
        Write-Host "--- expected ---"; $expected -split "`n" | ForEach-Object { Write-Host $_ }
        Write-Host "--- actual ---"; $actual -split "`n" | ForEach-Object { Write-Host $_ }
        $fail = $true
    } else {
        Write-Host ("Test {0} case {1}: PASS" -f $lessonName, $num)
    }
}
if ($fail) { exit 1 } else { exit 0 }
