<#
PowerShell helper: compile each lesson with gcc (if available) or cl and compare output vs expected.txt
Run from the repository root:
  pwsh -NoProfile -ExecutionPolicy Bypass ./scripts/validate-lessons.ps1
#>

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

$Root = Split-Path -Parent $PSScriptRoot
$ProjectsDir = Join-Path $Root 'projects'

$gcc = Get-Command gcc -ErrorAction SilentlyContinue
$cl = Get-Command cl -ErrorAction SilentlyContinue

$failures = @()

foreach ($p in Get-ChildItem -Directory -Path $ProjectsDir) {
    Write-Host "\n=== $($p.Name) ==="
    $files = Get-ChildItem -Path $p.FullName -Filter '*.c' -File | ForEach-Object { $_.FullName }
    if ($files.Count -eq 0) {
        Write-Host "No .c files found, skipping"
        continue
    }

    Push-Location $p.FullName
    try {
    # Name the output after the directory (e.g. project-01-hello) to avoid double-prefixing
    $out = "$($p.Name)"
    # Normalize file lists and detect test.c/main.c
    $allFiles = $files
    $hasTest = Test-Path (Join-Path $p.FullName 'test.c')
    $hasMain = Test-Path (Join-Path $p.FullName 'main.c')

        if ($gcc) {
            # Prefer compiling main.c when present, but include other companion sources that do not define their own main.
            if ($hasMain) {
                $mainFiles = @()
                $mainFiles += Join-Path $p.FullName 'main.c'
                # Include other .c files unless they contain their own main() definition or are test.c
                foreach ($f in $allFiles) {
                    if ($f -ieq (Join-Path $p.FullName 'main.c')) { continue }
                    if ($f -like "*\test.c") { continue }
                    $content = Get-Content -Raw -Path $f -ErrorAction SilentlyContinue
                    if ($content -match '\bint\s+main\s*\(' -or $content -match '\bmain\s*\(') {
                        # file defines its own main, skip it (e.g., race.c)
                        continue
                    }
                    $mainFiles += $f
                }
            } else {
                $mainFiles = if ($hasTest) { $allFiles | Where-Object { -not ($_ -like "*\test.c") } } else { $allFiles }
            }
            if ($mainFiles.Count -eq 0) {
                Write-Host "No main source files found for $($p.Name); skipping main build"
            } else {
                $gccArgs = @('-Wall','-Wextra','-pedantic') + $mainFiles + @('-o',$out)
                # If any source includes pthread.h, link with pthreads
                $contentsList = @()
                foreach ($mf in $mainFiles) {
                    $c = Get-Content -Raw -Path $mf -ErrorAction SilentlyContinue
                    if ($c) { $contentsList += $c }
                }
                $allContents = $contentsList -join "`n"
                if ($allContents -match '#include\s*<pthread.h>') {
                    $gccArgs = $gccArgs + '-pthread'
                }
                Write-Host "gcc $($gccArgs -join ' ')"
                & $gcc @gccArgs
                if ($LASTEXITCODE -ne 0) { throw "gcc failed for main with exit code $LASTEXITCODE" }
                $exe = Join-Path $p.FullName $out
                $actual = & $exe 2>&1

                $actualText = ($actual -join "`n") -replace "`r", ''
                # Remove platform-dependent pointer address lines (e.g. "address of x = 0x...")
                $actualText = ($actualText -split "`n") | Where-Object { $_ -notmatch '^(address|Address) of' } | ForEach-Object { $_ } | Out-String
                $actualText = $actualText -replace "`r", ''
                $actualText = $actualText.TrimEnd("`n","`r")
                $actualFile = Join-Path $p.FullName 'output.txt'
                $actualText | Out-File -FilePath $actualFile -Encoding utf8

                $expectedFile = Join-Path $p.FullName 'expected.txt'
                if (Test-Path $expectedFile) {
                    $expectedText = (Get-Content -Raw -Path $expectedFile) -replace "`r", ''
                    $expectedText = $expectedText.TrimEnd("`n","`r")
                    if ($expectedText -ne $actualText) {
                        Write-Host "Output mismatch for $($p.Name):"
                        Write-Host "--- expected ---"
                        $expectedText -split "`n" | ForEach-Object { Write-Host $_ }
                        Write-Host "--- actual ---"
                        $actualText -split "`n" | ForEach-Object { Write-Host $_ }
                        $failures += $p.Name
                    } else {
                        Write-Host "Match: output == expected"
                    }
                } else {
                    Write-Host "No expected.txt; wrote output.txt"
                }

                    # If per-project tests exist under ../tests/<project>/ or projects/<project>/tests/, run them now
                    $testsDirRepo = Join-Path $Root "tests\$($p.Name)"
                    $testsDirLocal = Join-Path $p.FullName 'tests'
                    $testRunner = Join-Path $PSScriptRoot 'run-project-tests.ps1'
                    if (Test-Path $testsDirRepo) {
                        Write-Host "Found repo-level tests for $($p.Name); running test harness"
                        pwsh -NoProfile -ExecutionPolicy Bypass -File $testRunner -ProjectPath $p.FullName
                        if ($LASTEXITCODE -ne 0) {
                            Write-Host "Lesson tests failed for $($p.Name)"
                            $failures += $p.Name
                        }
                    }
                    if (Test-Path $testsDirLocal) {
                        Write-Host "Found project-local tests for $($p.Name); running test harness"
                        pwsh -NoProfile -ExecutionPolicy Bypass -File $testRunner -ProjectPath $p.FullName
                        if ($LASTEXITCODE -ne 0) {
                            Write-Host "Project-local lesson tests failed for $($p.Name)"
                            $failures += $p.Name
                        }
                    }
            }

            # If there's a test.c, build and run it separately (exclude main.c)
            if ($hasTest) {
                $testOut = "test-$($p.Name)"
                $testFiles = $allFiles | Where-Object { -not ($_ -like "*\main.c") }
                if ($testFiles.Count -gt 0) {
                    $testArgs = @('-Wall','-Wextra','-pedantic') + $testFiles + @('-o',$testOut)
                    Write-Host "gcc $($testArgs -join ' ')"
                    & $gcc @testArgs
                    if ($LASTEXITCODE -ne 0) { Write-Host "test build failed for $($p.Name), skipping test run" } else {
                        $testExe = Join-Path $p.FullName $testOut
                                    $testOutText = & $testExe 2>&1
                        Write-Host "Test output for $($p.Name):"
                        $testOutText | ForEach-Object { Write-Host $_ }
                    }
                }
            }
        } elseif ($cl) {
            # MSVC path: compile main excluding test.c, and compile test separately if present
            $srcs = $files -join ' '
            $mainSrcs = if ($hasTest) { ($files | Where-Object { -not ($_ -like "*\test.c") }) -join ' ' } else { $srcs }
            $cmd = "cl /nologo /W3 $mainSrcs /Fe:$out"
            Write-Host $cmd
            cmd /c $cmd
            if ($LASTEXITCODE -ne 0) { throw "cl failed with exit code $LASTEXITCODE" }
            $exe = Join-Path $p.FullName "$out.exe"
            $actual = & $exe 2>&1

            $actualText = ($actual -join "`n") -replace "`r", ''
            $actualFile = Join-Path $p.FullName 'output.txt'
            $actualText | Out-File -FilePath $actualFile -Encoding utf8

            $expectedFile = Join-Path $p.FullName 'expected.txt'
            if (Test-Path $expectedFile) {
                $expectedText = (Get-Content -Raw -Path $expectedFile) -replace "`r", ''
                if ($expectedText -ne $actualText) {
                    Write-Host "Output mismatch for $($p.Name):"
                    Write-Host "--- expected ---"
                    $expectedText -split "`n" | ForEach-Object { Write-Host $_ }
                    Write-Host "--- actual ---"
                    $actualText -split "`n" | ForEach-Object { Write-Host $_ }
                    $failures += $p.Name
                } else {
                    Write-Host "Match: output == expected"
                }
            } else {
                Write-Host "No expected.txt; wrote output.txt"
            }

            if ($hasTest) {
                $testOut = "test-$($p.Name)"
                $testFiles = $files | Where-Object { -not ($_ -like "*\main.c") }
                $testSrcs = $testFiles -join ' '
                $testCmd = "cl /nologo /W3 $testSrcs /Fe:$testOut"
                Write-Host $testCmd
                cmd /c $testCmd
                if ($LASTEXITCODE -ne 0) { Write-Host "test build failed for $($p.Name), skipping test run" } else {
                    $testExe = Join-Path $p.FullName "$testOut.exe"
                    $testOutText = & $testExe 2>&1
                    Write-Host "Test output for $($p.Name):"
                    $testOutText | ForEach-Object { Write-Host $_ }
                }
            }
        } else {
            Write-Host "No compiler (gcc or cl) found in PATH; skipping $($p.Name)"
            continue
        }
    } catch {
        Write-Host "Error building/running $($p.Name): $_"
        $failures += $p.Name
    } finally {
        Pop-Location
    }
}

if ($failures.Count -gt 0) {
    Write-Host "\nFailures: $($failures -join ', ')"
    exit 1
} else {
    Write-Host "\nAll lessons built (where possible) and validated."
    exit 0
}
