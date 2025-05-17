cmake_minimum_required(VERSION 3.10)
project(PateintDatabaseCLI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(PROJECT_SOURCE_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(FetchContent)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # rozwiązanie problemu między bibliotekami dynamicznymi i statycznymi (MTd i MDd)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    # wersja z gitem
    # GIT_REPOSITORY https://github.com/google/googletest.git
    # GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(tests)
add_subdirectory(src)
