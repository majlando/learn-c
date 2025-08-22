# Delete committed .exe files under projects to clean repository
Set-StrictMode -Version Latest
$root = Join-Path $PSScriptRoot '..' | Resolve-Path -Relative
$projects = Join-Path $root 'projects'
$deleted = @()
Get-ChildItem -Path $projects -Filter '*.exe' -Recurse -File -ErrorAction SilentlyContinue | ForEach-Object {
    try {
        Remove-Item -LiteralPath $_.FullName -Force -ErrorAction Stop
        Write-Host "Deleted: $($_.FullName)"
        $deleted += $_.FullName
    } catch {
        Write-Host "Failed to delete: $($_.FullName) - $_" -ForegroundColor Yellow
    }
}
if ($deleted.Count -eq 0) { Write-Host "No .exe files found to delete." } else { Write-Host "Deleted $($deleted.Count) .exe files." }
