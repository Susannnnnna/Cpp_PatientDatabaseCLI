# Stop script on error
$ErrorActionPreference = "Stop"

# Colors for output
function Write-Info($message) { Write-Host "INFO: $message" -ForegroundColor Cyan }
function Write-Success($message) { Write-Host "SUCCESS: $message" -ForegroundColor Green }
function Write-ErrorMsg($message) { Write-Host "ERROR: $message" -ForegroundColor Red }

Write-Info "Cleaning previous build (if exists)..."
if (Test-Path "build") {
    Remove-Item -Recurse -Force "build"
}

Write-Info "Creating build directory..."
New-Item -ItemType Directory -Force -Path "build" | Out-Null
Set-Location "build"

Write-Info "Configuring CMake..."
if (-not (cmake ..)) {
    Write-ErrorMsg "CMake configuration failed."
    exit 1
}

Write-Info "Building project..."
if (-not (cmake --build .)) {
    Write-ErrorMsg "Build failed."
    exit 1
}

# === RUN TESTS from AllTests.exe and save unified XML report ===

$testExe = Get-ChildItem -Recurse -Filter "AllTests.exe"

if ($testExe) {
    Write-Info "Running tests from AllTests.exe..."

    $reportDir = Join-Path $PSScriptRoot "test-report"
    New-Item -ItemType Directory -Force -Path $reportDir | Out-Null
    $reportPath = Join-Path $reportDir "tests/report.xml"

    if (-not (& $testExe.FullName "--gtest_output=xml:$reportPath")) {
        Write-ErrorMsg "Tests failed."
        exit 1
    }

    Write-Success "All tests passed."
    Write-Info "Test report saved to: $reportPath"
    
    Write-Info "Opening test report in default browser..."
    Start-Process $reportPath
} else {
    Write-Info "AllTests.exe not found. Skipping tests."
}

# === RUN MAIN APP if exists ===
$appExe = Get-ChildItem -Recurse -Filter "PatientDatabaseCLIApp.exe"

if ($appExe) {
    Write-Info "Running main application..."
    & $appExe.FullName
    Write-Success "Application executed successfully."
} else {
    Write-ErrorMsg "Application executable not found."
}

Set-Location ".."
