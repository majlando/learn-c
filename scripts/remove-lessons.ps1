param(
    [string[]]$Lessons = @(
        'project-17-concurrency',
        'project-16-capstone',
        'project-15-data-structures',
        'project-14-sanitizers',
        'project-13-preprocessor',
        'project-12-types',
        'project-11-compilation'
    ),
    [switch]$Run
)

Set-StrictMode -Version Latest
$root = Join-Path $PSScriptRoot '..' | Resolve-Path -Relative
foreach ($l in $Lessons) {
    $path = Join-Path $root "projects\$l"
    if (Test-Path $path) {
        Write-Host "Found: $path"
        if ($Run) {
            Write-Host "Removing: $path" -ForegroundColor Red
            Remove-Item -LiteralPath $path -Recurse -Force
        } else {
            Write-Host "Dry-run: would remove $path" -ForegroundColor Yellow
        }
    } else {
        Write-Host "Not found: $path" -ForegroundColor Gray
    }
}

Write-Host "Done." -ForegroundColor Green
