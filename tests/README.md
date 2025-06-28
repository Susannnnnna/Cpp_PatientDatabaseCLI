# 🧪 Project Tests

This folder contains all tests for the **Patient Database CLI** application.

Tests are structured by type (unit, integration, system, regression) and organized into separate subfolders.

---

## 📂 Test Structure

| **Test Type**       | **Test Name**                   | **Description**                                                                 |
|---------------------|----------------------------------|---------------------------------------------------------------------------------|
| **Unit Tests**       | `PatientTest`                   | Tests the `Patient` class and its correct initialization                        |
|                     | `ValidatorTest`                 | Tests the correctness of PESEL validation logic                                |
|                     | `PatientInputCollectorTest`     | Tests user input collection (e.g., mocking `std::cin`, input validation)       |
|                     | `PatientPrinterTest`            | Tests output functionality (e.g., mocking/redirecting `std::cout`)             |
| **Integration Tests**| `SavePatientDataToCsvFile`      | Tests saving patient data to a CSV file and content comparison                 |
|                     | `ReadPatientDataFromCsvFile`    | Tests reading patient data from CSV and comparing with expected output         |
|                     | `DeletePatientDataFromCsvFile`  | Tests deletion of a patient and CSV file correctness afterward                 |
|                     | `EditPatientDataInCsvFile`      | Tests patient editing flow and file update integrity                           |
| **System Tests**     | `RunMenu`                       | Simulates a full CLI session with interactive commands                         |
| **Regression Tests** | `CheckIfCsvFileCanBeRead`       | Ensures previously working file reading logic still behaves as expected        |
|                     | `CheckIfCsvFileExist`           | Ensures required `.csv` file exists and is accessible                          |
| **Main Aggregator**  | `AllTests`                     | Runs all available tests, with `--gtest_filter` support for test selection      |

---

## ▶️ How to Run the Tests

### ✅ Prerequisites

- GoogleTest must be installed and configured in your project.

To add GoogleTest as a submodule:

```bash
git submodule add https://github.com/google/googletest.git external/googletest
git submodule update --init
```

Ensure you configure your CMake project accordingly (see project-level CMakeLists.txt).

### Tests results
Test results are printed to the terminal and saved as an XML report:
```bash
build/tests/report.xml
```

This can be used in CI pipelines or imported into tools like Jenkins or GitHub Actions.

