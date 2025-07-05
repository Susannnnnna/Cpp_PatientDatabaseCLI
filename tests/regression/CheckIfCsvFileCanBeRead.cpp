#include <gtest/gtest.h>

#include "../src/infrastructure/CsvPatientRepository.h"
#include "../TestData.h"
#include "../TestHelpers.h"

// Given: a CSV file with patient data
// When: CsvPatientRepository is used to load data
// Then: it should be able to read the file without errors
TEST(RegressionTestBDD, checkIfCsvFileCanBeRead) {
    Patient alice = TestData::PatientFactory::createPatient( "Alice", "Smith", "12345678901", "123 Main St", "555-1111");
    Patient bob = TestData::PatientFactory::createPatient( "Bob", "Brown", "23456789012", "456 Elm St", "555-2222");

    // Write test CSV file
    std::ostringstream csvContent;
    csvContent 
        << alice.first_name << "," << alice.last_name << "," << alice.pesel << "," << alice.address << "," << alice.phone_number << "\n"
        << bob.first_name << "," << bob.last_name << "," << bob.pesel << "," << bob.address << "," << bob.phone_number << "\n";

    auto testFile = TestHelpers::loadTestFile(csvContent.str());

    // Load patients
    CsvPatientRepository repo(testFile.string());
    std::vector<Patient> patients = repo.load();

    // Validate data
    ASSERT_EQ(patients.size(), 2);

    EXPECT_EQ(patients[0].first_name, alice.first_name);
    EXPECT_EQ(patients[0].last_name, alice.last_name);
    EXPECT_EQ(patients[0].pesel, alice.pesel);
    EXPECT_EQ(patients[0].address, alice.address);
    EXPECT_EQ(patients[0].phone_number, alice.phone_number);

    EXPECT_EQ(patients[1].first_name, bob.first_name);
    EXPECT_EQ(patients[1].last_name, bob.last_name);
    EXPECT_EQ(patients[1].pesel, bob.pesel);
    EXPECT_EQ(patients[1].address, bob.address);
    EXPECT_EQ(patients[1].phone_number, bob.phone_number);

    // Clean up
    TestHelpers::deleteFile(testFile.string());
}
