Set-StrictMode -Version Latest
$src = Join-Path $PSScriptRoot 'main.c'
$out = Join-Path $PSScriptRoot 'lesson-project-10-dynamic-memory'
if (Get-Command gcc -ErrorAction SilentlyContinue) {
    $args = @('-fsanitize=address,undefined','-g','-Wall','-Wextra','-pedantic','-o',$out,$src)
    & gcc @args
} else {
    Write-Error "gcc not found"
    exit 2
}
