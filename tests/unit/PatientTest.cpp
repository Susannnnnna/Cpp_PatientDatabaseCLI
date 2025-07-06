#include <gtest/gtest.h>
#include "../src/domain/Patient.h"
#include "../TestData.h"

// Covers: REQ-001

// Given: correct patient data
// When: check if patient initializes correctly
// Then: should initialize with correct values
TEST(PatientTestBDD, GivenValidData_WhenPatientCreated_ThenFieldsAreInitializedCorrectly) {
    Patient p = TestData::PatientFactory::makeSamplePatient();    
    EXPECT_EQ(p.first_name, "John");
    EXPECT_EQ(p.last_name, "Doe");
    EXPECT_EQ(p.pesel, "12345678901");
    EXPECT_EQ(p.address, "456 Elm St 555-5678");
    EXPECT_EQ(p.phone_number, "555-5678");
}
