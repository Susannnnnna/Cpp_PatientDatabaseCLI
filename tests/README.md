# Project Tests
This folder contains CLI application tests for managing patient data.
Test are spearated according to tests levels and arrange in a separated catalogues.

## Test structure
- `unit/` - single and separated classes or functions tests ('Patient', 'PatientService')
- `integration/` - cooperation between modules tests (example: add or read data from file)
- `system/` - end-to-end tests, testing the whole system (runMenu())
- `regression/` - tests that ensure that new changes do not break existing functions, checking edge cases and error handling (example: PESEL == 0)

## Behavior-Driven Development (BDD)
This project uses BDD to define the behavior of the application. 
The tests are written in a way that describes the expected behavior of the application in a human-readable format. 
This helps to ensure that the application meets the requirements and behaves as expected.

### Features
Feature 1: Saving and reading patient data
  Scenario: Save patient data to file
    Given a patient with valid data
    When the patient data is saved to file
    Then the patient data should be saved successfully

  Scenario: Read patient data from file
    Given a file with patient data
    When the patient data is read from file
    Then the patient data should be read successfully

Feature 2: Validating patient data
  Scenario: Validate patient data with valid PESEL
    Given a patient with valid PESEL
    When the patient data is validated
    Then the validation should be successful

  Scenario: Validate patient data with invalid PESEL
    Given a patient with invalid PESEL
    When the patient data is validated
    Then the validation should fail

## How to run the tests?
To run the tests, you need to have GoogleTest installed and configured in your project.
Add Google Tests to project:
```
git submodule add https://github.com/google/googletest.git external/googletest
git submodule update --init
```

All tests are located in the AllTests.cpp file.

The output of the test is report.xaml file, which can be viewed in the browser.