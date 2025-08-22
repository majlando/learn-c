<# Fail if common build artifacts are present in the repo root or projects. Useful for CI. #>
Set-StrictMode -Version Latest
Push-Location -Path $PSScriptRoot\..\

$patterns = @('*.exe','*.o','*.obj','*.dll','*.pdb')
$found = @()
foreach ($p in $patterns) { $found += Get-ChildItem -Path . -Include $p -Recurse -File -ErrorAction SilentlyContinue }
if ($found.Count -gt 0) {
    Write-Host "Found committed build artifacts:" -ForegroundColor Red
    $found | ForEach-Object { Write-Host $_.FullName }
    exit 1
}
Write-Host "No common build artifacts found."
Pop-Location
