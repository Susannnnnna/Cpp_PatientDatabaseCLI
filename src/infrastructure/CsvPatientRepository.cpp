#include "CsvPatientRepository.h"
#include <iostream>

void serializePatient(std::ofstream& file, const Patient& p) {
    file << p.first_name << ","
         << p.last_name << ","
         << p.pesel << ","
         << p.address << ","
         << p.phone_number << "\n";
}

Patient deserializePatient(std::istringstream& iss) {
    Patient p;

    std::string fields[5];

    for (int i = 0; i < 4; ++i) {
        if (!std::getline(iss, fields[i], ',')) return {};
    }

    std::getline(iss, fields[4]);

    p.first_name = fields[0];
    p.last_name = fields[1];
    p.pesel = fields[2];
    p.address = fields[3];
    p.phone_number = fields[4];

    return p;
}

std::vector<Patient> CsvPatientRepository::load() {
    try {
        return CsvReader::read<Patient>(file, deserializePatient);
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] CsvPatientRepositd failed: " << e.what() << "\n";
        throw;
    }
}

void CsvPatientRepository::save(const std::vector<Patient>& items) {
    CsvWriter::write<Patient>(items, file, serializePatient);
}


