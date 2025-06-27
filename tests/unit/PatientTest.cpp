#include <gtest/gtest.h>
#include "../src/domain/Patient.h"

// Given: correct patient data
// When: check if patient initializes correctly
// Then: should initialize with correct values
namespace TestData {
    Patient makeSamplePatient() {
        return Patient{
            "John", 
            "Doe", 
            "12345678901", 
            "456 Elm St 555-5678", 
            "555-5678"
        };
    }
}

TEST(PatientTest, GivenValidData_ShouldInitializeCorrectly) {
    Patient p = TestData::makeSamplePatient();    
    EXPECT_EQ(p.first_name, "John");
    EXPECT_EQ(p.last_name, "Doe");
    EXPECT_EQ(p.pesel, "12345678901");
    EXPECT_EQ(p.address, "456 Elm St 555-5678");
    EXPECT_EQ(p.phone_number, "555-5678");
}
