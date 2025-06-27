#include "CsvPatientRepository.h"

void serializePatient(std::ofstream& file, const Patient& p) {
    file << p.first_name << ","
         << p.last_name << ","
         << p.pesel << ","
         << p.address << ","
         << p.phone_number << "\n";
}

Patient deserializePatient(std::istringstream& iss) {
    Patient p;
    std::getline(iss, p.first_name, ',');
    std::getline(iss, p.last_name, ',');
    std::getline(iss, p.pesel, ',');
    std::getline(iss, p.address, ',');
    std::getline(iss, p.phone_number, ',');
    return p;
}

std::vector<Patient> CsvPatientRepository::load() {
    return CsvReader::read<Patient>(file, deserializePatient);
}

void CsvPatientRepository::save(const std::vector<Patient>& items) {
    CsvWriter::write<Patient>(items, file, serializePatient);
}