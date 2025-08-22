Get-ChildItem -Path 'c:\code\learn-c\projects' -Recurse -Filter expected.txt | ForEach-Object {
    Write-Host "FILE: $($_.FullName)"
    $s = Get-Content -Raw -Path $_.FullName
    $esc = $s -replace '\r','\\r' -replace '\n','\\n'
    Write-Host $esc
    Write-Host '---'
}

