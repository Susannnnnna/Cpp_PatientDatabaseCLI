# Main app library
add_library(PatientDatabaseCLI STATIC
    cli/Menu.h
    cli/Menu.cpp
    cli/PatientInputCollector.h
    cli/PatientInputCollector.cpp
    cli/PatientPrinter.h
    cli/PatientPrinter.cpp
    
    domain/Patient.h
    domain/Patient.cpp
    domain/IRepository.h

    infrastructure/CsvPatientRepository.h
    infrastructure/CsvPatientRepository.cpp
    infrastructure/CsvReader.h
    infrastructure/CsvWriter.h
    
    services/PatientService.h
    services/PatientService.cpp

    validation/Validator.h
    validation/Validator.cpp
)

target_include_directories(PatientDatabaseCLI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_compile_definitions(PROJECT_DIR="${CMAKE_SOURCE_DIR}")


# Main library paths and links
add_executable(PatientDatabaseCLIApp main.cpp)
target_link_libraries(PatientDatabaseCLIApp PatientDatabaseCLI)
