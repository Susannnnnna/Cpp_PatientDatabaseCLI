cmake_minimum_required(VERSION 3.10) # importat because older versions of CMake do not support FetchContent
project(PatientDatabaseCLI) # declare the project name

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add global definitions
add_compile_definitions(PROJECT_SOURCE_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

# Add mechanism for downloading and managing external dependencies (for example: GoogleTests)
include(FetchContent)

# Solve problem with dynamic and static libraries (MTd and MDd)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Get GoogleTest library for the GitHub repository
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    # wersja z gitem
    # GIT_REPOSITORY https://github.com/google/googletest.git
    # GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Add the directories with the source code and tests
add_subdirectory(tests)
add_subdirectory(src)
