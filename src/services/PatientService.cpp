#include "PatientService.h"
#include "Validator.h"
#include <iostream>
#include <algorithm>

std::vector<Patient> PatientService::addPatient(const std::vector<Patient>& patients) {
    Patient newPatient;
    std::cout << "Enter first name: ";
    std::cin >> newPatient.first_name;
    std::cout << "Enter last name: ";
    std::cin >> newPatient.last_name;
    std::cout << "Enter PESEL: ";
    std::cin >> newPatient.pesel;
    if(!Validator::isValidPesel(newPatient.pesel)) {
        std::cout << "Invalid PESEL. Please try again.\n";
        return patients;
    }
    std::cout << "Enter address: ";
    std::cin.ignore(); // Clear the newline character from the input buffer
    std::getline(std::cin, newPatient.address);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, newPatient.phone_number);
    
    auto updatedPatients = patients;
    updatedPatients.push_back(newPatient);
    return updatedPatients;
}

std::vector<Patient> PatientService::editPatient(const std::vector<Patient>& patients) {
    std::string pesel;
    std::cout << "Enter PESEL of the patient to edit: ";
    std::cin >> pesel;

    auto updatedPatients = patients;
    auto it = std::find_if(updatedPatients.begin(), updatedPatients.end(), 
                        [pesel](const Patient& p) { return p.pesel == pesel; });

    if (it != updatedPatients.end()) {
        std::cout << "Editing patient: " << it->first_name << " " << it->last_name << "\n";
        std::cout << "Enter new first name (leave blank to keep current): ";
        std::string firstName;
        std::cin.ignore();
        std::getline(std::cin, firstName);
        if (!firstName.empty()) {
            it->first_name = firstName;
        }

        std::cout << "Enter new last name (leave blank to keep current): ";
        std::string lastName;
        std::getline(std::cin, lastName);
        if (!lastName.empty()) {
            it->last_name = lastName;
        }

        std::cout << "Enter new address (leave blank to keep current): ";
        std::string address;
        std::getline(std::cin, address);
        if (!address.empty()) {
            it->address = address;
        }

        std::cout << "Enter new phone number (leave blank to keep current): ";
        std::string phoneNumber;
        std::getline(std::cin, phoneNumber);
        if (!phoneNumber.empty()) {
            it->phone_number = phoneNumber;
        }
    } else {
        std::cout << "Patient with PESEL " << pesel << " not found.\n";
    }
    
    return updatedPatients;
}

std::vector<Patient> PatientService::deletePatient(const std::vector<Patient>& patients) {
    std::string pesel;
    std::cout << "Enter PESEL of the patient to delete: ";
    std::cin >> pesel;

    auto updatedPatients = patients;
    auto it = std::remove_if(updatedPatients.begin(), updatedPatients.end(), 
                        [pesel](const Patient& p) { return p.pesel == pesel; });

    if (it != updatedPatients.end()) {
        updatedPatients.erase(it, updatedPatients.end());
        std::cout << "Patient with PESEL " << pesel << " deleted.\n";
    } else {
        std::cout << "Patient with PESEL " << pesel << " not found.\n";
    }
    
    return updatedPatients;
}

void PatientService::listPatients(const std::vector<Patient>& patients) {
    if (patients.empty()) {
        std::cout << "No patients found.\n";
        return;
    }

    std::cout << "List of patients:\n";
    for (const auto& patient : patients) {
        std::cout << "Name: " << patient.first_name << " " << patient.last_name 
                  << "\nPESEL: " << patient.pesel 
                  << "\nAddress: " << patient.address 
                  << "\nPhone Number: " << patient.phone_number << "\n";
    }
}