#include <gtest/gtest.h>

#include "unit/PatientTest.cpp"
#include "unit/ValidatorTest.cpp"
#include "integration/PatientFileRepositoryTest.cpp"
#include "integration/HealthInfoFileRepositoryTest.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}