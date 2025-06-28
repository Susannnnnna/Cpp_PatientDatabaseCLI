#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "../src/cli/PatientInputCollector.h"
#include "../src/cli/PatientPrinter.h"

// Helper to redirect std::cout
class CoutRedirect {
    std::streambuf* originalBuffer;
    std::ostringstream capturestream;

    public:
        CoutRedirect() {
            originalBuffer = std::cout.rdbuf();
            std::cout.rdbuf(capturestream.rdbuf());
        }

        ~CoutRedirect() {
            std::cout.rdbuf(originalBuffer);
        }

        std::string getOutput() const {
            return capturestream.str();
        }
};

// Test data generator
namespace TestData {
    Patient makeSamplePatient() {
        return Patient {
            "John", 
            "Doe", 
            "12345678901", 
            "456 Elm St 555-5678", 
            "555-5678"
        };
    }
}

// Given: patient vector with one patient
// When: listPatients is called
// Then: output should contain patient's full data
TEST(PatientPrinterTestBDD, GivenPatientList_WhenListPatientCalled_ThenShoudlPrintFullData) {
    std::vector<Patient> patients = { TestData::makeSamplePatient() };
    PatientPrinter printer;

    CoutRedirect redirect;
    printer.listPatients(patients);
    std::string output = redirect.getOutput();

    EXPECT_NE(output.find("John Doe"), std::string::npos);
    EXPECT_NE(output.find("12345678901"), std::string::npos);
    EXPECT_NE(output.find("456 Elm St 555-5678"), std::string::npos);
    EXPECT_NE(output.find("555-5678"), std::string::npos);
}


// Given: empty patient list
// when: listPatients is called
// Then: output should say "No patients found."
TEST(PatientPrinterTestBDD, GivenEmptyPatientList_WhenListPatientsCalled_ThenShouldPrintNoPatientsMessage) {
    std::vector<Patient> patients;
    PatientPrinter printer;

    CoutRedirect redirect;
    printer.listPatients(patients);
    std::string output = redirect.getOutput();

    EXPECT_NE(output.find("No patients found."), std::string::npos);
}


// Given: a message string
// When: printMessage is called
// Then: message should be printed to output
TEST(PatientPrinterTestBDD, GivenMessageString_WhenPrintMessageCalled_ThenShouldOutputGivenText) {
    PatientPrinter printer;

    CoutRedirect redirect;
    printer.printMessage("Test message");
    std::string output = redirect.getOutput();

    EXPECT_NE(output.find("Test message"), std::string::npos);
}