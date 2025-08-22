$src = 'main.c'
$out = 'project-09-file-io.exe'

# Allow overrides via environment variables
$cc = ${env:CC}
$cflags = ${env:CFLAGS}
if (-not $cc) { $cc = 'gcc' }
if (-not $cflags) { $cflags = '-Wall -Wextra -pedantic' }

Push-Location $PSScriptRoot
try {
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
} finally { Pop-Location }
