#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <fstream>

#include "../src/cli/Menu.h"
#include "../src/infrastructure/CsvPatientRepository.h"
#include "../TestData.h"
#include "../TestHelpers.h"

// === TEST ===
// Given: Empty patient database
// When: Simulate CLI session: add patient -> list patients -> exit
// Then: Patient data is saved to CSV and appears in output
TEST(SystemTestBDD_Unique, RunMenu_SimulateFullCLISession) {
     auto testCsv = TestHelpers::runMenuTestFile();

    // Sample patient from factory
    Patient samplePatient = TestData::PatientFactory::makeSamplePatient();

    // Simulated user input
    std::ostringstream simulatedInputStream;
    simulatedInputStream
        << "1\n"                    // Add patient
        << samplePatient.first_name << "\n"
        << samplePatient.last_name << "\n"
        << samplePatient.pesel << "\n"
        << samplePatient.address << "\n"
        << samplePatient.phone_number << "\n"
        << "4\n"                    // Show patients
        << "0\n";                   // Exit

    TestHelpers::CinRedirect cinRedirect(simulatedInputStream.str());
    TestHelpers::CoutRedirect coutRedirect;

    // Run menu
    runMenu(testCsv.string());

    // Capture output
    std::string output = coutRedirect.getOutput();

    // Check if patient data appeared in output
    EXPECT_TRUE(output.find(samplePatient.first_name) != std::string::npos);
    EXPECT_TRUE(output.find(samplePatient.last_name) != std::string::npos);
    EXPECT_TRUE(output.find(samplePatient.pesel) != std::string::npos);
    EXPECT_TRUE(output.find(samplePatient.address) != std::string::npos);
    EXPECT_TRUE(output.find(samplePatient.phone_number) != std::string::npos);

    // Check if patient data was saved to file
    ASSERT_TRUE(std::filesystem::exists(testCsv));

    std::ifstream file(testCsv);
    std::string line;

    bool found = false;
    while (std::getline(file, line)) {
        std::ostringstream expectedLine;
        expectedLine
            << samplePatient.first_name << ","
            << samplePatient.last_name << ","
            << samplePatient.pesel << ","
            << samplePatient.address << ","
            << samplePatient.phone_number;

        if (line.find(expectedLine.str()) != std::string::npos) {
            found = true;
            break;
        }
    }
    file.close();
    EXPECT_TRUE(found);

    TestHelpers::deleteFile(testCsv.string());
}
