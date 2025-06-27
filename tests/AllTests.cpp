#include <gtest/gtest.h>

#include "unit/PatientTest.cpp"
#include "unit/ValidatorTest.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}