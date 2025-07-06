#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>

#include "../src/infrastructure/CsvPatientRepository.h"
#include "../TestData.h"
#include "../TestHelpers.h"

// Covers: REQ-006

namespace fs = std::filesystem;

// Given: patient list
// When: call CsvPatientRepository::load()
// Then: the file should contain correct patient data
TEST(ReadPatientDataFromCsvFileBDD, GivenPatientDataFromCsvFile_WhenLoaded_ThenReturnCorrectPatients) {
    auto tempFilePath = TestHelpers::loadTestFile();

    // Use PatientFactory for test data
    Patient expected = TestData::PatientFactory::makeSamplePatient();

    std::ofstream outFile(tempFilePath.string());
    outFile << expected.first_name << "," << expected.last_name << "," 
            << expected.pesel << "," << expected.address << "," 
            << expected.phone_number << "\n";
    outFile.close();

    CsvPatientRepository repo(tempFilePath.string());

    std::vector<Patient> patients = repo.load();

    // Verify loaded patient matches expected
    ASSERT_EQ(patients.size(), 1);
    Patient actual = patients[0];

    EXPECT_EQ(actual.first_name, expected.first_name);
    EXPECT_EQ(actual.last_name, expected.last_name);
    EXPECT_EQ(actual.pesel, expected.pesel);
    EXPECT_EQ(actual.address, expected.address);
    EXPECT_EQ(actual.phone_number, expected.phone_number);

    TestHelpers::deleteFile(tempFilePath.string());
}