#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "Menu.h"
#include "Patient.h"
#include "PatientService.h"
#include "PatientFileRepository.h"
#include "HealthInfoFileRepository.h"

void runMenu() {
    std::string path = std::string(PROJECT_SOURCE_DIR) + std::string("/data");
    std::filesystem::create_directories(path);
    std::string patientsFilePath = path + "/patients.csv";

    if(!std::filesystem::exists(patientsFilePath)) {
        std::ofstream createFile(patientsFilePath);
        createFile.close();
    }

    std::vector<Patient> patients = PatientFileRepository::loadPatients(patientsFilePath);
    int choice;
    do {
        std::cout << "1. Add patient\n2. Edit\n3. Delete\n4. Show\n5. Show health data\n0. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                patients = PatientService::addPatient(patients);
                break;
            }
            case 2: {
                patients = PatientService::editPatient(patients);
                break;
            }
            case 3: {
                patients = PatientService::deletePatient(patients);
                break;
            }
            case 4: {
                PatientService::listPatients(patients);
                break;
            }
            case 5: {
                std::string pesel;
                std::cout << "Enter PESEL: ";
                std::cin >> pesel;
                HealthInfoFileRepository::displayHealthInfo(pesel);
                break;
            }
            case 0:
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);
    PatientFileRepository::savePatients(patients, patientsFilePath);
}