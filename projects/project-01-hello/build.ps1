param([switch]$ClangSanitize)

if ($ClangSanitize) {
    # configure environment for Clang sanitizers
    $env:CC = 'clang'
    $env:CFLAGS = '-fsanitize=address,undefined -fno-omit-frame-pointer -g -O1 -std=c11 -Wall -Wextra'
}

$src = 'main.c'
$folder = Split-Path -Leaf $PSScriptRoot
$out = "$folder.exe"

# Allow overrides via environment variables
$cc = ${env:CC}
$cflags = ${env:CFLAGS}
if (-not $cc) { $cc = 'gcc' }
if (-not $cflags) { $cflags = '-Wall -Wextra -pedantic' }

Push-Location $PSScriptRoot
try {
    if (Get-Command $cc -ErrorAction SilentlyContinue) {
        # split flags and src into arrays to avoid passing them as one combined argument
        $flagsArray = @()
        if ($cflags) { $flagsArray = $cflags -split '\s+' }
        $srcArray = $src -split '\s+'
    $compileArgs = $flagsArray + $srcArray + @('-o', $out)
    & $cc @compileArgs
        $rc = $LASTEXITCODE
        if ($rc -ne 0) { exit $rc }
        & (Join-Path $PSScriptRoot $out)
        exit $LASTEXITCODE
    } elseif (Get-Command cl -ErrorAction SilentlyContinue) {
        # MSVC: warn level 3 and no logo
        cl /nologo /W3 $src /Fe:$out
        $rc = $LASTEXITCODE
        if ($rc -ne 0) { exit $rc }
        & (Join-Path $PSScriptRoot $out)
        exit $LASTEXITCODE
    } else {
        Write-Error "No C compiler found in PATH (gcc or cl)."
        exit 1
    }
} finally { Pop-Location }
