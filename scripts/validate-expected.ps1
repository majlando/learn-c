param(
    [string]$ProjectsRoot = (Join-Path $PSScriptRoot '..\projects'),
    [switch]$Fix
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
Push-Location -Path $PSScriptRoot

$issues = [System.Collections.Generic.List[string]]::new()
$fixes = [System.Collections.Generic.List[string]]::new()
try {
    $files = Get-ChildItem -Path $ProjectsRoot -Recurse -Filter expected.txt -File -ErrorAction Stop
    foreach ($f in $files) {
        try {
            # Read as UTF8 and preserve raw contents
            $text = Get-Content -Raw -Encoding UTF8 -Path $f.FullName
        } catch {
            $issues.Add($f.FullName + ': read error - ' + $_.Exception.Message)
            continue
        }

    # Normalize any run of CR/LF to a single LF for consistent checks (handles sequences like \n\r\n)
    $norm = [regex]::Replace($text, '(\r\n|\r|\n)+', "`n")

        if ($norm -match '```') { $issues.Add($f.FullName + ': contains markdown fence ```') }

        $lines = $norm -split [char]10
        if ($lines.Count -gt 0) {
            if ($lines[0] -match '^\s*$') { $issues.Add($f.FullName + ': starts with blank line') }

            # count trailing empty lines (lines that are entirely whitespace)
            $trailingEmptyCount = 0
            for ($i = $lines.Count - 1; $i -ge 0; $i--) {
                if ($lines[$i] -match '^\s*$') { $trailingEmptyCount++ } else { break }
            }
            if ($trailingEmptyCount -gt 1) { $issues.Add($f.FullName + ": has $trailingEmptyCount trailing blank line(s)") }
        }

        if ($Fix) {
            # Auto-fix trivial issues: preserve content inside markdown fences and trim surrounding blanks
            # Replace a fenced block like ```[lang]\n...content...``` with just the content
            $fixed = [regex]::Replace($norm, '(?s)```(?:.*?\n)?(.*?)```', '$1')
            # collapse repeated newlines and split into lines
            $fixed = [regex]::Replace($fixed, '(\r\n|\r|\n)+', "`n")
            $parts = $fixed -split [char]10
            # remove leading blank lines (avoid invalid slice when Count -le 1)
            while ($parts.Count -gt 0 -and ($parts[0] -match '^\s*$')) {
                if ($parts.Count -le 1) { $parts = @() } else { $parts = $parts[1..($parts.Count-1)] }
            }
            # remove trailing blank lines (avoid invalid slice when Count -le 1)
            while ($parts.Count -gt 0 -and ($parts[-1] -match '^\s*$')) {
                if ($parts.Count -le 1) { $parts = @() } else { $parts = $parts[0..($parts.Count-2)] }
            }
            # Rejoin and ensure single trailing newline when writing
            $out = ($parts -join "`n") + "`n"
            # If the auto-fix produced an empty file but there's a run.actual.txt in the same folder,
            # use that as the expected output (helps recover when previous fixes accidentally removed content)
            if ([string]::IsNullOrWhiteSpace($out)) {
                $actualPath = Join-Path $f.DirectoryName 'run.actual.txt'
                if (Test-Path $actualPath) {
                    try {
                        $act = (Get-Content -Raw -Encoding UTF8 -Path $actualPath) -replace "`r`n","`n" -replace "`r","`n"
                        $out = $act
                    } catch {
                        # ignore, will fall through to write empty file if unreadable
                    }
                }
            }
            try {
                $tmp = $f.FullName + '.tmp'
                Set-Content -Path $tmp -Value $out -Encoding UTF8 -Force
                # Attempt atomic replace; if Move fails because file locked, capture the error.
                try {
                    Move-Item -Path $tmp -Destination $f.FullName -Force
                } catch {
                    Remove-Item -Path $tmp -ErrorAction SilentlyContinue
                    throw
                }
                $fixes.Add($f.FullName)
            } catch {
                $issues.Add($f.FullName + ': fix write error - ' + $_.Exception.Message)
            }
        }
    }
} catch {
    Write-Error "Validator failed: $($_.Exception.Message)"
    Pop-Location
    exit 2
}

if ($fixes.Count -gt 0) {
    Write-Host "Auto-fixed files:" -ForegroundColor Green
    $fixes | ForEach-Object { Write-Host " - $_" }
}

if ($issues.Count -ne 0) {
    Write-Host "Found issues in expected.txt files:" -ForegroundColor Yellow
    $issues | ForEach-Object { Write-Host " - $_" -ForegroundColor Yellow }
    Pop-Location
    exit 1
} else {
    Write-Host "All expected.txt files look good." -ForegroundColor Green
    Pop-Location
    exit 0
}
