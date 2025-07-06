#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>

#include "../src/infrastructure/CsvPatientRepository.h"
#include "../src/services/PatientService.h"
#include "../TestData.h"
#include "../TestHelpers.h"

// Covers: REQ-008

namespace fs = std::filesystem;

// Given: a CSV file with patient data
// When: a patient is edited by their PESEL (using PatientService)
// Then: the CSV file should be updated correctly
TEST(EditPatientDataInCsvFileBDD, GivenPatientInCsv_WhenEditByPesel_ThenUpdatedDataIsSaved) {
    auto filePath = TestHelpers::editTestFile();

    // Use PatientFactory for test data
    Patient original = TestData::PatientFactory::makeSamplePatient();
    Patient updated = TestData::PatientFactory::makeSamplePatient2();

    // Write original patient to CSV
    std::ofstream outFile(filePath);
    outFile << original.first_name << "," << original.last_name << "," 
            << original.pesel << "," << original.address << "," << original.phone_number << "\n";
    outFile.close();

    CsvPatientRepository repo(filePath.string());
    PatientService service;

    std::vector<Patient> loaded = repo.load();
    ASSERT_EQ(loaded.size(), 1);
    EXPECT_EQ(loaded[0].address, original.address);

    std::vector<Patient> edited = service.editPatient(loaded, original.pesel, updated);
    repo.save(edited);

    std::ifstream inFile(filePath);
    std::string line;
    std::getline(inFile, line);
    EXPECT_EQ(line, updated.first_name + "," + updated.last_name + "," + updated.pesel + "," + updated.address + "," + updated.phone_number);

    inFile.close();
    TestHelpers::deleteFile(filePath.string());
}

