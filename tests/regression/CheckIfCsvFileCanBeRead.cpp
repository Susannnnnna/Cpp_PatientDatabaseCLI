#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>

#include "../src/infrastructure/CsvPatientRepository.h"
#include "../src/domain/Patient.h"

namespace fs = std::filesystem;

// Given: a CSV file with pateint data
// When: CsvPatientRepository is used to load data
// Then: it should be able to read the file without errors
TEST(RegressionTestBDD, checkIfCsvFileCanBeRead) {
    std::string testDir = "test-output/regression";
    std::string testFile = testDir + "/test_read.csv";

    // Ensure if folder exists
    if (!fs::exists(testDir)) {
        fs::create_directories(testDir);
    }

    // Write test CSV file
    std::ofstream outFile(testFile);
    outFile << "Alice,Smith,12345678901,123 Main St,555-1111\n";
    outFile << "Bob,Brown,23456789012,456 Elm St,555-2222\n";
    outFile.close();

    // Load patients
    CsvPatientRepository repo(testFile);
    std::vector<Patient> patients = repo.load();

    // Validate data
    ASSERT_EQ(patients.size(), 2);

    EXPECT_EQ(patients[0].first_name, "Alice");
    EXPECT_EQ(patients[0].last_name, "Smith");
    EXPECT_EQ(patients[0].pesel, "12345678901");
    EXPECT_EQ(patients[0].address, "123 Main St");
    EXPECT_EQ(patients[0].phone_number, "555-1111");

    EXPECT_EQ(patients[1].first_name, "Bob");
    EXPECT_EQ(patients[1].last_name, "Brown");
    EXPECT_EQ(patients[1].pesel, "23456789012");
    EXPECT_EQ(patients[1].address, "456 Elm St");
    EXPECT_EQ(patients[1].phone_number, "555-2222");

    // Clean up
    fs::remove(testFile);
}