#include <gtest/gtest.h>

#include "unit/PatientTest.cpp"
#include "unit/ValidatorTest.cpp"
#include "unit/PatientPrinterTest.cpp"
#include "unit/PatientInputCollectorTest.cpp"
#include "integration/SavePatientDataToCsvFile.cpp"
#include "integration/EditPatientDataInCsvFile.cpp"
#include "integration/ReadPatientDataFromCsvFile.cpp"
#include "integration/DeletePatientDataFromCsvFile.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}