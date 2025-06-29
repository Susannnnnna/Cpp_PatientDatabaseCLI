include(GoogleTest)

# Find all test files
file(GLOB_RECURSE UNIT_TESTS "unit/*.cpp")
file(GLOB_RECURSE INTEGRATION_TESTS "integration/*.cpp")
file(GLOB_RECURSE SYSTEM_TESTS "system/*.cpp")
file(GLOB_RECURSE REGRESSION_TESTS "regression/*.cpp")

# Create AllTests executable
add_executable(AllTests
    AllTests.cpp
    ${UNIT_TESTS}
    ${INTEGRATION_TESTS}
    ${SYSTEM_TESTS}
    ${REGRESSION_TESTS}
)

# Link GoogleTest libraries
include_directories(
    ${gtest_SOURCE_DIR}/include
    ${gmock_SOURCE_DIR}/include
)

# Paths and links
target_include_directories(AllTests PRIVATE ../src)
target_link_libraries(AllTests
    PRIVATE
    PatientDatabaseCLI
    GTest::gtest
    GTest::gtest_main
)

# Show tests for CTest
gtest_discover_tests(AllTests)