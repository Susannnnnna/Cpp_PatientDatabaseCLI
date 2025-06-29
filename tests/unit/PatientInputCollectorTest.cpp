#include <gtest/gtest.h>
#include <sstream>
#include "../src/cli/PatientInputCollector.h"
#include "../src/domain/Patient.h"

// Given: valid input data entered by user
// When: collectNewPatient is called
// Then: it should return a patient object with correct fields
TEST(PatientInputCollectorTestBDD, GivenValidInput_WhenCollectsPatient_ThenReturnCorrectPatient) {
    std::istringstream input("John\nDoe\n12345678901\n123 Main St\n555-1234");
    std::streambuf* originalCin = std::cin.rdbuf(input.rdbuf()); //redirect

    PatientInputCollector collector;
    Patient p = collector.collectNewPatient();
    

    std::cin.rdbuf(originalCin);

    EXPECT_EQ(p.first_name, "John");
    EXPECT_EQ(p.last_name, "Doe");
    EXPECT_EQ(p.pesel, "12345678901");
    EXPECT_EQ(p.address, "123 Main St");
    EXPECT_EQ(p.phone_number, "555-1234");
}

// Given: pesel prompt
// When:: ask for pesel
// Then: it should return the entered pesel
TEST(PatientInputCollectorTestBDD, Given_PeselPrompt_WhenAskForPesel_ThenReturnCorrectInput) {
    std::istringstream input("12345678901");
    std::streambuf* originalCin = std::cin.rdbuf(input.rdbuf());

    PatientInputCollector collector;
    std::string pesel = collector.askForPesel("Please enter PESEL:");

    std::cin.rdbuf(originalCin);

    EXPECT_EQ(pesel, "12345678901");
}