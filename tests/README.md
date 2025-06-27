# Project Tests
This folder contains CLI application tests for managing patient data.
Test are spearated according to tests levels and arrange in a separated catalogues.

## Test structure
| Test | Content | Description |
| ----------- | ----------- | ----------- |
| Unit Tests | PatientTest | Test of object - Patient, construction  |
| Unit Tests | ValidatorTest | Checking PESEL validation |
| Unit Tests | PatientInputCollectorTest | Interaction test (mock std::cin) or input validation user |
| Unit Tests | PatientPrinterTest | Output test (mock std::cout / redirect) |
| Integration Tests | SavePatientDataToCsvFile| Save patient data to CSV file and content comparision |
| Integration Tests | ReadPatientDataFromCsvFile | Read patient data from CSV file and comparision with expected object |
| Integration Tests | DeletePatientDataFromCsvFile | Remove patient and check file correctnes |
| Integration Tests | EditPatientDataInCsvFile | Edit patient data and check recording |
| System Tests | RunMenu | Simulate full CLI session with interactions  |
| Regression Tests | CheckIfCsvFileCanBeRead | Check if reading CSV file is still correct |
| Regression Tests | CheckIfCsvFileExist | Check if CSV file exist and is accesible |
| Main | AllTests | Tests agregation, with filtering possibility ( --gtest_filter) |

## How to run the tests?
To run the tests, you need to install GoogleTest and configured it in your project.
Add Google Tests to project:
```
git submodule add https://github.com/google/googletest.git external/googletest
git submodule update --init
```

### Tests results
Tests output report is located in report.xml file.