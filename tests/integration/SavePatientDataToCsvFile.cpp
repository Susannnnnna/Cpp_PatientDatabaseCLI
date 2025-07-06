#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>

#include "../src/infrastructure/CsvPatientRepository.h"
#include "../TestData.h"
#include "../TestHelpers.h"

// Covers: REQ-005

namespace fs = std::filesystem;

// Given: patient list
// When: saving patient data to a temprorary CSV file
// Then: the file should contain correct patient data in CSV format
TEST(SavePatientDataToCsvFileBDD, GivenPatient_WhenSavedToCsv_ThenFileContainsCorrectData) {
    auto tempFilePath = TestHelpers::saveTestFile();

    // Use PatientFactory for consistent test data
    Patient expected = TestData::PatientFactory::makeSamplePatient();

    std::vector<Patient> patients = { expected };
    CsvPatientRepository repo(tempFilePath.string());

    repo.save(patients);

    std::ifstream inFile(tempFilePath);
    ASSERT_TRUE(inFile.is_open());
    
    std::string line;
    std::getline(inFile, line);
    
    // Compare saved CSV line to expected serialization
    std::ostringstream expectedCsv;
    expectedCsv << expected.first_name << ","
                << expected.last_name << ","
                << expected.pesel << ","
                << expected.address << ","
                << expected.phone_number;

    EXPECT_EQ(line, expectedCsv.str());

    inFile.close();
    TestHelpers::deleteFile(tempFilePath.string());
}