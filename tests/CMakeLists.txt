
enable_testing()
include(GoogleTest)

add_executable(PatientTest PatientTest.cpp)
target_link_libraries(PatientTest PatientDatabaseCLI GTest::gtest_main)

gtest_discover_tests(PatientTest)
