Set-StrictMode -Version Latest
Push-Location -Path $PSScriptRoot

$gcc = Get-Command gcc -ErrorAction SilentlyContinue
if (-not $gcc) { Write-Host "gcc not found in PATH."; exit 1 }

# Build with ASan and UBSan if supported
$args = @('-fsanitize=address,undefined','-fno-omit-frame-pointer','-g','-Wall','-Wextra','-o','project-11-pitfalls.sanitized.exe','main.c')
& gcc @args

Pop-Location
