# Remove on-disk .exe files under the projects folder
Set-StrictMode -Version Latest
Push-Location -Path $PSScriptRoot\..\

$removed = 0
Get-ChildItem -Path .\projects -Recurse -Filter '*.exe' -File -ErrorAction SilentlyContinue | ForEach-Object {
    try {
        Remove-Item -LiteralPath $_.FullName -Force -ErrorAction Stop
        Write-Host "Removed: $($_.FullName)"
        $removed++
    } catch {
        Write-Host "Failed to remove: $($_.FullName) - $_" -ForegroundColor Yellow
    }
}
if ($removed -eq 0) { Write-Host "No .exe files found under projects/." } else { Write-Host "Removed $removed .exe files." }

Pop-Location
