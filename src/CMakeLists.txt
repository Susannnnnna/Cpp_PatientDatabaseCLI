
add_library(PatientDatabaseCLI STATIC
    Menu.h
    Menu.cpp
    Patient.h
    HealthInfoFileRepository.h
    HealthInfoFileRepository.cpp
    PatientFileRepository.h
    PatientFileRepository.cpp
    PatientService.h
    PatientService.cpp
)

target_include_directories(PatientDatabaseCLI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(PatientDatabaseCLIApp main.cpp)
target_link_libraries(PatientDatabaseCLIApp PatientDatabaseCLI)
