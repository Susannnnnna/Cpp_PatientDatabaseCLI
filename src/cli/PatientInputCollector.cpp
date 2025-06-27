#include "PatientInputCollector.h"
#include <iostream>

Patient PatientInputCollector::collectNewPatient() {
    Patient patient;
    std::cout << "Enter first name: ";
    std::cin >> patient.first_name;
    std::cout << "Enter last name: ";
    std::cin >> patient.last_name;
    std::cout << "Enter PESEL: ";
    std::cin >> patient.pesel;
    std::cout << "Enter address: ";
    std::cin.ignore(); // Clear the newline character from the input buffer
    std::getline(std::cin, patient.address);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, patient.phone_number);
    return patient;
}

std::string PatientInputCollector::askForPesel(const std::string& message) {
    std::string pesel;
    std::cout << message;
    std::cin >> pesel;
    return pesel;
}