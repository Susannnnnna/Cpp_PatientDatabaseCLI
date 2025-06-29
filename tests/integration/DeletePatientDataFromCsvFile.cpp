#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>

#include "../src/domain/Patient.h"
#include "../src/services/PatientService.h"
#include "../src/infrastructure/CsvPatientRepository.h"

namespace fs = std::filesystem;

// Given: a CSV file with patient data
// When: a patient is deleted by their PESEL (using PatientService)
// Then: the CSV file should be updated correctly
TEST(DeletePateintDataFromCsvFileBDD, GivenCsvWithPatients_WhenDeleteOneByPesel_ThenCSVIsUpdated) {
    std:: string filePath = "test-output/delete_test.csv";
    fs::create_directories("test-output");

    std::ofstream outFile(filePath);
    outFile << "Alice,Smith,12345678901,1980-01-01\n";
    outFile << "Bob,Brown,23456789012,1990-02-02\n";
    outFile.close();

    CsvPatientRepository repo(filePath);
    PatientService service;

    std::vector<Patient> loadedPatients = repo.load();
    ASSERT_EQ(loadedPatients.size(), 2);

    std::vector<Patient> updated = service.deletePatient(loadedPatients, "12345678901");
    repo.save(updated);

    std::ifstream inFile(filePath);
    std::string line;
    std::getline(inFile, line);
    EXPECT_EQ(line, "Bob,Brown,23456789012,1990-02-02");

    std::getline(inFile, line);
    EXPECT_TRUE(line.empty()); // Ensure no extra lines

    inFile.close();
    fs::remove(filePath);
}