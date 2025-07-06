#include <gtest/gtest.h>
#include <sstream>
#include "../src/cli/PatientInputCollector.h"
#include "../TestData.h"
#include "../TestHelpers.h"

// Covers: REQ-003

// Given: valid input data entered by user
// When: collectNewPatient is called
// Then: it should return a patient object with correct fields
TEST(PatientInputCollectorTestBDD, GivenValidInput_WhenCollectsPatient_ThenReturnCorrectPatient) {
    PatientInputCollector collector;
    Patient expected = TestData::PatientFactory::makeSamplePatient();

    std::ostringstream inputStream;
    inputStream
        << expected.first_name << "\n"
        << expected.last_name << "\n"
        << expected.pesel << "\n"
        << expected.address << "\n"
        << expected.phone_number << "\n";

    TestHelpers::CinRedirect redirect(inputStream.str());

    Patient actual = collector.collectNewPatient();

    EXPECT_EQ(actual.first_name, expected.first_name);
    EXPECT_EQ(actual.last_name, expected.last_name);
    EXPECT_EQ(actual.pesel, expected.pesel);
    EXPECT_EQ(actual.address, expected.address);
    EXPECT_EQ(actual.phone_number, expected.phone_number);
}

// Given: pesel prompt
// When:: ask for pesel
// Then: it should return the entered pesel
TEST(PatientInputCollectorTestBDD, GivenPeselPrompt_WhenAskForPesel_ThenReturnCorrectInput) {
    std::string expectedPesel = TestData::PatientFactory::makeSamplePatient().pesel;
    TestHelpers::CinRedirect redirect(expectedPesel);

    PatientInputCollector collector;
    
    std::string actualPesel = collector.askForPesel("Please enter PESEL:");

    EXPECT_EQ(actualPesel, expectedPesel);
}