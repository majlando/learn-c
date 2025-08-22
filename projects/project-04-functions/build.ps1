$src = 'main.c math.c'
$folder = Split-Path -Leaf $PSScriptRoot
$out = "$folder.exe"
Push-Location $PSScriptRoot
try {
    # $src already set above to include companion sources
    # Allow overrides via environment variables
    $cc = ${env:CC}
    $cflags = ${env:CFLAGS}
    if (-not $cc) { $cc = 'gcc' }
    if (-not $cflags) { $cflags = '-Wall -Wextra -pedantic' }

    if (Get-Command $cc -ErrorAction SilentlyContinue) {
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
        cl /nologo /W3 $src /Fe:$out
        $rc = $LASTEXITCODE
        if ($rc -ne 0) { exit $rc }
        & (Join-Path $PSScriptRoot $out)
        exit $LASTEXITCODE
    } else {
        Write-Error "No C compiler found in PATH (gcc or cl)."
        exit 1
    }
} finally {
    Pop-Location
}
