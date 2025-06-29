#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>

#include "../src/domain/Patient.h"
#include "../src/infrastructure/CsvPatientRepository.h"

namespace fs = std::filesystem;

// Given: patient list
// When: saving patient data to a temprorary CSV file
// Then: the file should contain correct patient data in CSV format
TEST(SavePatientDataToCsvFileBDD, GivenPatient_WhenSavedToCsv_ThenFileContainsCorrectData) {
    std::string tempFilePath = "test-output/save_test.csv";
    fs::create_directories("test-output");

    Patient patient {
        "Alice",
        "Smith",
        "98765432101",
        "789 Oak St 555-6789",
        "555-6789"
    };

    std::vector<Patient> patients = { patient };
    CsvPatientRepository repo(tempFilePath);

    repo.save(patients);

    std::ifstream inFile(tempFilePath);
    ASSERT_TRUE(inFile.is_open());
    
    std::string line;
    std::getline(inFile, line);
    
    EXPECT_EQ(line, "Alice,Smith,98765432101,789 Oak St 555-6789,555-6789");

    inFile.close();
    fs::remove(tempFilePath);
}