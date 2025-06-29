# 🧪 Project Tests

This folder contains all tests for the **Patient Database CLI** application.

Tests are structured by type (unit, integration, system, regression) and organized into separate subfolders.

---

## 📂 Test Structure

| **Test Type**       | **Test Name**                   | **Description**                                                                 | **State** |
|---------------------|----------------------------------|---------------------------------------------------------------------------------|----------------------------------|
| **Unit Tests**       | `PatientTest`                   | Tests the `Patient` class and its correct initialization                        |Finished|
|                     | `ValidatorTest`                 | Tests the correctness of PESEL validation logic                                |Finished|
|                     | `PatientInputCollectorTest`     | Tests user input collection (e.g., mocking `std::cin`, input validation)       |Finished|
|                     | `PatientPrinterTest`            | Tests output functionality (e.g., mocking/redirecting `std::cout`)             |In progress|
| **Integration Tests**| `SavePatientDataToCsvFile`      | Tests saving patient data to a CSV file and content comparison                 |In progress|
|                     | `ReadPatientDataFromCsvFile`    | Tests reading patient data from CSV and comparing with expected output         |In progress|
|                     | `DeletePatientDataFromCsvFile`  | Tests deletion of a patient and CSV file correctness afterward                 |Not started|
|                     | `EditPatientDataInCsvFile`      | Tests patient editing flow and file update integrity                           |Not started|
| **System Tests**     | `RunMenu`                       | Simulates a full CLI session with interactive commands                         |Not started|
| **Regression Tests** | `CheckIfCsvFileCanBeRead`       | Ensures previously working file reading logic still behaves as expected        |Not started|
|                     | `CheckIfCsvFileExist`           | Ensures the required `.csv` file exists and is accessible                          |Not started|
| **Main Aggregator**  | `AllTests`                     | Runs all available tests, with `--gtest_filter` support for test selection      |Finishe

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

### Test results
Test results are printed to the terminal and saved as an XML report:
```bash
test-report/report.xml
```

This can be used in CI pipelines or imported into tools like Jenkins or GitHub Actions.

