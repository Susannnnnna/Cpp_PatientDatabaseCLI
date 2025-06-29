#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>

#include "../src/domain/Patient.h"
#include "../src/infrastructure/CsvPatientRepository.h"
#include "../src/services/PatientService.h"

namespace fs = std::filesystem;

// Given: a CSV file with patient data
// When: a patient is edited by their PESEL (using PatientService)
// Then: the CSV file should be updated correctly
TEST(EditPatientDataInCsvFileBDD, GivenPatientInCsv_WhenEditByPesel_ThenUpdatedDataIsSaved) {
    std::string filePath = "test-output/edit_test.csv";
    fs::create_directories("test-output");

    std::ofstream outFile(filePath);
    outFile << "Alice,Smith,12345678901,789 Oak St 555-6789,555-6789\n";
    outFile.close();

    CsvPatientRepository repo(filePath);
    PatientService service;

    std::vector<Patient> loaded = repo.load();
    ASSERT_EQ(loaded.size(), 1);
    EXPECT_EQ(loaded[0].address, "789 Oak St 555-6789");

    Patient updated;
    updated.first_name = "Alice";
    updated.last_name = "Smith";
    updated.pesel = "12345678901";
    updated.address = "123 New St 555-6789";
    updated.phone_number = "555-6789";

    std::vector<Patient> edited = service.editPatient(loaded, "12345678901", updated);
    repo.save(edited);

    std::ifstream inFile(filePath);
    std::string line;
    std::getline(inFile, line);
    EXPECT_EQ(line, "Alice,Smith,12345678901,123 New St 555-6789,555-6789");

    inFile.close();
    fs::remove(filePath);
}

