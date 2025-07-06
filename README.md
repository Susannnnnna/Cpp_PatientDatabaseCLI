# Patient Database CLI

## 🎯 Objective
This repository contains a simulated **medical data management CLI application**.  
The project includes a **traceability matrix** mapping requirements (REQ) to corresponding tests.

⚠️ *Note: This is a **learning/demo project** created to simulate professional development workflows, including requirements management, traceability and structured testing (based on IEC 62304).*

## ✅ Key Features
- Store patient data in a `.csv` file
- Add, view, edit, delete patient records via command line
- Includes unit, integration, system, and regression tests
- Behavior-Driven Development (BDD)
- CI pipeline using PowerShell and tasks in VS Code

## 📁 Project Structure
- `src/` — main application source code
- `tests/` — unit and integration tests
- `data/` — stored `.csv` patient data
- `tests-report/` — tests report result available in XML
- `ci-pipeline.ps1` — CI build & run script

## 📋 Requirements (REQ)
The system is designed to meet the following requirements:

| **ID**    | **Description**                                                                                     |
|-----------|------------------------------------------------------------------------------------------------------|
| **REQ-001** | The system must allow creation of `Patient` objects with correct field initialization.              |
| **REQ-002** | The system must validate PESEL numbers according to Polish rules (11 digits and correct checksum). |
| **REQ-003** | The system must allow capturing patient data from user input (stdin).                              |
| **REQ-004** | The system must allow displaying a list of patients to the user (stdout).                          |
| **REQ-005** | The system must save patient data to a CSV file in the correct format.                              |
| **REQ-006** | The system must load patient data from a CSV file.                                                  |
| **REQ-007** | The system must allow deleting patient data by PESEL and update the CSV file.                       |
| **REQ-008** | The system must allow editing patient data and saving updates to the CSV file.                      |
| **REQ-009** | The system must offer a CLI menu with CRUD operations and exit functionality.                       |

## 🧪 Traceability Matrix
Each test in the project covers specific requirements:

| **Test Name**                     | **Covers Requirements** |
|-------------------------------------|--------------------------|
| `PatientTest`                      | REQ-001                 |
| `ValidatorTest`                    | REQ-002                 |
| `PatientInputCollectorTest`        | REQ-003                 |
| `PatientPrinterTest`               | REQ-004                 |
| `SavePatientDataToCsvFile`         | REQ-005                 |
| `ReadPatientDataFromCsvFile`       | REQ-006                 |
| `DeletePatientDataFromCsvFile`     | REQ-007                 |
| `EditPatientDataInCsvFile`         | REQ-008                 |
| `RunMenu`                          | REQ-009, REQ-003        |
| `CheckIfCsvFileCanBeRead`          | REQ-006                 |

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
- PowerShell (CI pipeline)
- JSON (only for vscode tasks)

### 🗂️ Data Handling
- Patient data stored in `.csv` file
- CLI-based interactions (add/view/edit/delete)

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
- PowerShell

3. Build and run
    
Press `Ctrl + Shift + B` in VS Code

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