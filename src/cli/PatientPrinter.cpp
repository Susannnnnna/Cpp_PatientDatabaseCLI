#include "PatientPrinter.h"
#include <iostream>

void PatientPrinter::listPatients(const std::vector<Patient>& patients) {
    if (patients.empty()) {
        std::cout << "No patients found.\n";
        return;
    }
    std::cout << "List of patients:\n";
    for (const auto& p : patients) {
        std::cout << "First Name: " << p.first_name << ", "
                  << "Last Name: " << p.last_name << ", "
                  << "PESEL: " << p.pesel << ", "
                  << "Address: " << p.address << ", "
                  << "Phone Number: " << p.phone_number << "\n";
    }
}

void PatientPrinter::printMessage(const std::string& message) {
    std::cout << message << "\n";
}