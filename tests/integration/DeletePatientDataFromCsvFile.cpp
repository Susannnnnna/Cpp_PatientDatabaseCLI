#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>

#include "../src/services/PatientService.h"
#include "../src/infrastructure/CsvPatientRepository.h"
#include "../TestData.h"
#include "../TestHelpers.h"

namespace fs = std::filesystem;

// Given: a CSV file with patient data
// When: a patient is deleted by their PESEL (using PatientService)
// Then: the CSV file should be updated correctly
TEST(DeletePatientDataFromCsvFileBDD, GivenCsvWithPatients_WhenDeleteOneByPesel_ThenCSVIsUpdated) {
    auto filePath = TestHelpers::deleteTestFile();

    Patient john = TestData::PatientFactory::makeSamplePatient();
    Patient alice = TestData::PatientFactory::makeSamplePatient2();

    std::ofstream outFile(filePath);
    outFile << john.first_name << "," << john.last_name << "," << john.pesel << "," << john.address << "," << john.phone_number << "\n";
    outFile << alice.first_name << "," << alice.last_name << "," << alice.pesel << "," << alice.address << "," << alice.phone_number << "\n";
    outFile.close();

    CsvPatientRepository repo(filePath.string());
    PatientService service;

    std::vector<Patient> loadedPatients = repo.load();
    ASSERT_EQ(loadedPatients.size(), 2);

    // Delete John by PESEL
    std::vector<Patient> updated = service.deletePatient(loadedPatients, john.pesel);
    repo.save(updated);

    // Check if only Alice remains in the file
    std::ifstream inFile(filePath);
    std::string line;
    std::getline(inFile, line);
    
    EXPECT_EQ(line, alice.first_name + "," + alice.last_name + "," + alice.pesel + "," + alice.address + "," + alice.phone_number);

    std::getline(inFile, line);
    EXPECT_TRUE(line.empty()); // Ensure no extra lines

    inFile.close();
    TestHelpers::deleteFile(filePath.string());
}