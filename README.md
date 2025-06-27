# Patient Database CLI

## 🎯 Objective
Command Line Interface (CLI) application for managing patient data and storing results in CSV files.

## ✅ Key Features
- Store patient data in a `.csv` file
- Add, edit, delete patient records via command line
- Includes unit, integration, system, and regression tests
- Behavior-Driven Development (BDD)
- CI/CD pipeline using PowerShell

## 📁 Project Structure
- `src/` — main application source code
- `tests/` — unit and integration tests
- `data/` — stored `.csv` patient data
- `build/` — compiled artifacts
- `ci-pipeline.ps1` — CI/CD build & run script

## 🧪 Testing
Detailed structure and description: [`tests/README.md`](./tests/README.md)

## ▶️ How to Run the App

### 💻 Environment
- Tested on **Windows 11**
- Visual Studio Code + CMake toolchain

### 🛠️ Used Technologies
- C++
- CMake
- GoogleTest
- PowerShell
- JSON (planned or for configs)

### 🗂️ Data Handling
- Patient data stored in `.csv` file
- CLI-based interactions (add/edit/delete)

### 🚀 Run the App

1. **Clone the repository:**
```bash
git clone https://github.com/Susannnnnna/Cpp_PatientDatabaseCLI
cd Cpp_PatientDatabaseCLI
```
2. Open in VS Code and install recommended extensions
- GitHub Pull Requests and Issues
- CMake Tools
- CMake
- YAML (optional)
- PowerShell

3. Build and run
    
Press Ctrl + Shift + B in VS Code

Or use terminal:
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Debug
```

4. Run main application
```bash
./src/Debug/PatientDatabaseCLIApp.exe
```

### 🔗 Useful Links
- [DDD, Hexagonal, Onion, Clean, CQRS, … How I put it all together](https://herbertograca.com/2017/11/16/explicit-architecture-01-ddd-hexagonal-onion-clean-cqrs-how-i-put-it-all-together/)

## License
[MIT license](https://opensource.org/licenses/MIT)