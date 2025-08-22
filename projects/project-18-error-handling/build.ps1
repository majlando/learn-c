Set-StrictMode -Version Latest
$src = Join-Path $PSScriptRoot 'main.c'
$out = Join-Path $PSScriptRoot 'project-18-error-handling.exe'
if (Get-Command gcc -ErrorAction SilentlyContinue) {
    gcc -o $out $src
} elseif (Get-Command cl -ErrorAction SilentlyContinue) {
    cl /Fe:$out $src
}
