#include <gtest/gtest.h>
#include "../src/validation/Validator.h"

// Covers: REQ-002

// Given: empty pesel
// When: validate pesel
// Then: should return FALSE
TEST(ValidatorTestBDD, GivenEmptyPesel_WhenValidated_ThenReturnFalse) {
    std::string pesel = "";
    bool result = Validator::isValidPesel(pesel);
    EXPECT_FALSE(result);
}

// Given: pesel with less tha 11 characters
// When: validate pesel
// Then: should return FALSE
TEST(ValidatorTestBDD, GivenTooShortPesel_WhenValidated_ThenReturnFalse) {
    std::string pesel = "1234";
    bool result = Validator::isValidPesel(pesel);
    EXPECT_FALSE(result);
}

// Given: pesel with more tha 11 characters
// When: validate pesel
// Then: should return FALSE
TEST(ValidatorTestBDD, GivenTooLongPesel_WhenValidated_ThenReturnFalse) {
    std::string pesel = "12345678901234";
    bool result = Validator::isValidPesel(pesel);
    EXPECT_FALSE(result);
}

// Given: pesel contains letters
// When: validate pesel
// Then: should return FALSE
TEST(ValidatorTestBDD, GivenPeselWithLetters_WhenValidated_ThenReturnFalse) {
    std::string pesel = "12we45rr";
    bool result = Validator::isValidPesel(pesel);
    EXPECT_FALSE(result);
}

// Given: correct pesel (11 digits)
// When: validate pesel
// Then: should return TRUE
TEST(ValidatorTestBDD, GivenCorrectPesel_WhenValidated_ThenReturnTrue) {
    std::string pesel = "99019811455";
    bool result = Validator::isValidPesel(pesel);
    EXPECT_TRUE(result);
}