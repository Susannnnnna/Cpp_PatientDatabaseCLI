#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

#include "../src/cli/PatientInputCollector.h"
#include "../src/cli/PatientPrinter.h"
#include "../TestData.h"
#include "../TestHelpers.h"

// Covers: REQ-004


void assertPatientPrinted(const std::string& output, const Patient& patient) {
    EXPECT_NE(output.find("First Name: " + patient.first_name), std::string::npos);
    EXPECT_NE(output.find("Last Name: " + patient.last_name), std::string::npos);
    EXPECT_NE(output.find("PESEL: " + patient.pesel), std::string::npos);
    EXPECT_NE(output.find("Address: " + patient.address), std::string::npos);
    EXPECT_NE(output.find("Phone Number: "+ patient.phone_number), std::string::npos);
}

// Given: patient vector with one patient
// When: listPatients is called
// Then: output should contain patient's full data
TEST(PatientPrinterTestBDD, GivenPatientList_WhenListPatientCalled_ThenShoudlPrintFullData) {
    std::vector<Patient> patients = { 
        TestData::PatientFactory::makeSamplePatient() 
    };
    PatientPrinter printer;

    TestHelpers::CoutRedirect redirect;
    printer.listPatients(patients);
    
    std::string output = redirect.getOutput();
    assertPatientPrinted(output, patients[0]);
}


// Given: empty patient list
// when: listPatients is called
// Then: output should say "No patients found."
TEST(PatientPrinterTestBDD, GivenEmptyPatientList_WhenListPatientsCalled_ThenShouldPrintNoPatientsMessage) {
    std::vector<Patient> patients;
    PatientPrinter printer;

    TestHelpers::CoutRedirect redirect;
    printer.listPatients(patients);
    std::string output = redirect.getOutput();

    EXPECT_NE(output.find("No patients found."), std::string::npos);
}


// Given: a message string
// When: printMessage is called
// Then: message should be printed to output
TEST(PatientPrinterTestBDD, GivenMessageString_WhenPrintMessageCalled_ThenShouldOutputGivenText) {
    PatientPrinter printer;

    TestHelpers::CoutRedirect redirect;
    printer.printMessage("Test message");

    std::string output = redirect.getOutput();
    EXPECT_NE(output.find("Test message"), std::string::npos);
}