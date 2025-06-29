#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>

#include "../src/domain/Patient.h"
#include "../src/infrastructure/CsvPatientRepository.h"

namespace fs = std::filesystem;

// Given: patient list
// When: call CsvPatientRepository::load()
// Then: the file should contain correct patient data
TEST(ReadPatientDataFromCsvFileBDD, GivenPatientDataFromCsvFile_WhenLoaded_ThenReturnCorrectPatients) {
    std::string tempFilePath = "test-output/load_test.csv";
    fs::create_directories("test-output");

    std::ofstream outFile(tempFilePath);
    outFile << "Alice,Smith,98765432101,789 Oak St 555-6789,555-6789\n";
    outFile.close();

    CsvPatientRepository repo(tempFilePath);

    std::vector<Patient> patients = repo.load();

    ASSERT_EQ(patients.size(), 1);
    Patient p = patients[0];
    EXPECT_EQ(p.first_name, "Alice");
    EXPECT_EQ(p.last_name, "Smith");
    EXPECT_EQ(p.pesel, "98765432101");
    EXPECT_EQ(p.address, "789 Oak St 555-6789");
    EXPECT_EQ(p.phone_number, "555-6789");

    fs::remove(tempFilePath);
}