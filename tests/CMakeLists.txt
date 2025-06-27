include(GoogleTest)

file(GLOB_RECURSE UNIT_TESTS "unit/*.cpp")
file(GLOB_RECURSE INTEGRATION_TESTS "integration/*.cpp")
file(GLOB_RECURSE SYSTEM_TESTS "system/*.cpp")
file(GLOB_RECURSE REGRESSION_TESTS "regression/*.cpp")

add_executable(AllTests
    AllTests.cpp
    ${UNIT_TESTS}
    ${INTEGRATION_TESTS}
    ${SYSTEM_TESTS}
    ${REGRESSION_TESTS}
)

target_include_directories(AllTests PRIVATE ../src)
target_link_libraries(AllTests PatientDatabaseCLI GTest::gtest_main)
gtest_discover_tests(AllTests)