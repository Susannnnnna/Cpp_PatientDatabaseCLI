
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

# Run tests if any test executables exist
$testExe = Get-ChildItem -Recurse -Filter "*.exe" | Where-Object { $_.Name -like "*test*" }

if ($testExe) {
    Write-Info "Running tests..."
    foreach ($exe in $testExe) {
        if (-not (& $exe.FullName)) {
            Write-ErrorMsg "Tests failed."
            exit 1
        }
    }
    Write-Success "All tests passed."
} else {
    Write-Info "No test executables found. Skipping tests."
}

# Run main application if exists
$appExe = Get-ChildItem -Recurse -Filter "PatientDatabaseCLIApp.exe"

if ($appExe) {
    Write-Info "Running main application..."
    & $appExe.FullName
    Write-Success "Application executed successfully."
} else {
    Write-ErrorMsg "Application executable not found."
}

Set-Location ".."
