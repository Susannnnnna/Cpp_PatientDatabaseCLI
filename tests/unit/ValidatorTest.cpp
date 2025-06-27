#include <gtest/gtest.h>
#include "../src/Validator.h"

// Given: empty pesel
// When: validate pesel
// Then: shoudl return false
TEST(ValidatorBDD, RejestsEmptyPesel) {
    std::string pesel = "";
    bool result = Validator::isValidPesel(pesel);
    EXPECT_FALSE(result);
}

// Given: pesel with less tha 11 characters
// When: validate pesel
// Then: should return false
TEST(ValidatorBdd, RejestsTooShortPesel) {
    std::string pesel = "1234";
    bool result = Validator::isValidPesel(pesel);
    EXPECT_FALSE(result);
}

// Given: pesel contains letters
// When: validate pesel
// Then: should return false
TEST(ValidatorBdd, RejestsPeselWithLetters) {
    std::string pesel = "12we45rr";
    bool result = Validator::isValidPesel(pesel);
    EXPECT_FALSE(result);
}

// Given: correct pesel (11 digits)
// When: validate pesel
// Then: should return true
TEST(ValidatorBdd, AcceptsValidPesel) {
    std::string pesel = "99019811455";
    bool result = Validator::isValidPesel(pesel);
    EXPECT_TRUE(result);
}