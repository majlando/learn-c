param(
    [string]$Project = 'projects\\project-01-hello'
)

function Show-FileBytes($path) {
    if (-not (Test-Path $path)) { Write-Host "Missing: $path"; return }
    $bytes = [System.IO.File]::ReadAllBytes($path)
    $hex = ($bytes | ForEach-Object { $_.ToString('x2') }) -join ' '
    Write-Host "$path -> $($bytes.Length) bytes"
    Write-Host $hex
}

$exp = Join-Path $Project 'expected.txt'
$act = Join-Path $Project 'run.actual.txt'
Show-FileBytes $exp
Show-FileBytes $act
