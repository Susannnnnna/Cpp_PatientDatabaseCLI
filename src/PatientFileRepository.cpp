#include "PatientFileRepository.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

void PatientFileRepository::savePatients(const std::vector<Patient>& patients, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file to add patient.");
    }

    for(const auto& patient : patients) {
        file << patient.first_name << "," 
             << patient.last_name << ","
             << patient.pesel << ","
             << patient.address << ","
             << patient.phone_number << "\n";
    }
    file.close();
}

std::vector<Patient> PatientFileRepository::loadPatients(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file to load patients.");
    }

    std::vector<Patient> patients;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Patient patient;
        std::string pesel_str;

        std::getline(iss, patient.first_name, ',');
        std::getline(iss, patient.last_name, ',');
        std::getline(iss, pesel_str, ',');
        patient.pesel = std::stoull(pesel_str);
        std::getline(iss, patient.address, ',');
        std::getline(iss, patient.phone_number);
        
        patients.push_back(patient);
    }
    file.close();
    return patients;
}