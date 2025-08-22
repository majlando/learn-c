param(
    [string]$LessonPath,
    [string]$ProjectsRoot = (Join-Path $PSScriptRoot '..\projects')
)

Set-StrictMode -Version Latest

if ($LessonPath) {
    if (-not (Test-Path $LessonPath)) { Write-Error "Lesson path not found: $LessonPath"; exit 2 }
    # delegate lesson-level build+tests to the project test harness for the specific path
    pwsh -NoProfile -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot 'run-project-tests.ps1') -ProjectPath $LessonPath
    exit $LASTEXITCODE
} else {
    # run the unified project tests for all projects
    pwsh -NoProfile -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot 'run-project-tests.ps1') -ProjectsRoot $ProjectsRoot
    exit $LASTEXITCODE
}
