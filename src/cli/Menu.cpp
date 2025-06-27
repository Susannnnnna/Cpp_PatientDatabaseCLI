#include <iostream>
#include <filesystem>

#include "Menu.h"
#include "../cli/PatientInputCollector.h"
#include "../cli/PatientPrinter.h"
#include "../services/PatientService.h"
#include "../infrastructure/CsvPatientRepository.h"
#include "../validation/Validator.h"

void runMenu() {
    std::string path = std::filesystem::absolute("data").string();
    std::filesystem::create_directories(path);
    std::string filePath = path + "/patients.csv";

    if (!std::filesystem::exists(filePath)) {
        std::ofstream createFile(filePath);
        createFile.close();
    }

    CsvPatientRepository repo(filePath);
    PatientInputCollector input;
    PatientPrinter printer;
    PatientService service;

    std::vector<Patient> patients = repo.load();

    int choice;
    do {
        std::cout << "\n--- PATIENT MANAGEMENT ---\n";
        std::cout << "1. Add patient\n2. Edit\n3. Delete\n4. Show\n0. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Patient newPatient = input.collectNewPatient();
                if (!Validator::isValidPesel(newPatient.pesel)) {
                    printer.printMessage("Invalid PESEL format. Please try again.");
                    break;
                }
                patients = service.addPatient(patients, newPatient);
                printer.printMessage("Patient added successfully.");
                break;
            }
            case 2: {
                std::string pesel = input.askForPesel("Enter PESEL of the patient to edit: ");
                Patient updatedData = input.collectNewPatient();
                patients = service.editPatient(patients, pesel, updatedData);
                break;
            }
            case 3: {
                std::string pesel = input.askForPesel("Enter PESEL of the patient to delete: ");
                patients = service.deletePatient(patients, pesel);
                break;
            }
            case 4: {
                printer.listPatients(patients);
                break;
            }
            case 0:
                printer.printMessage("Saving data and existing...");
                break;
            default:
                printer.printMessage("Invalid choice. Please try again.");
        }
    } while (choice != 0);

    repo.save(patients);
}