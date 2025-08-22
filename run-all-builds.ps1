Set-StrictMode -Version Latest

# Move to the projects folder next to this script
Push-Location -Path (Join-Path $PSScriptRoot 'projects')
$errors = 0
$dirs = Get-ChildItem -Directory -Filter 'project-*' | Sort-Object Name

foreach ($d in $dirs) {
    Write-Host "==> Building $($d.Name)"
    Push-Location $d.FullName
    try {
        if (Test-Path './build.ps1') {
            try {
                & ./build.ps1
                if ($LASTEXITCODE -ne 0) {
                    Write-Host "build.ps1 exited with code $LASTEXITCODE for $($d.Name)"
                    $errors += 1
                }
            } catch {
                Write-Host "build failed for $($d.Name): $_"
                $errors += 1
            }
        } else {
            Write-Host "no build.ps1 in $($d.Name)"
        }
    } finally {
        Pop-Location
    }
}

Pop-Location

if ($errors -ne 0) { exit 1 } else { exit 0 }
