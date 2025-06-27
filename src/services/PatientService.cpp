#include "PatientService.h"
#include <algorithm>

std::vector<Patient> PatientService::addPatient(const std::vector<Patient>& patients, const Patient& newPatient) {    
    auto updated = patients;
    updated.push_back(newPatient);
    return updated;
}

std::vector<Patient> PatientService::editPatient(std::vector<Patient> patients, const std::string& pesel, const Patient& updatedData) {
    auto it = std::find_if(patients.begin(), patients.end(), [pesel](const Patient& p) { 
        return p.pesel == pesel; 
    });

    if (it != patients.end()) {
        *it = updatedData;
    }
    return patients;
}

std::vector<Patient> PatientService::deletePatient(std::vector<Patient> patients, const std::string& pesel) {
    auto it = std::remove_if(patients.begin(), patients.end(), [pesel](const Patient& p) { 
        return p.pesel == pesel; 
    });
    if (it != patients.end()) {
        patients.erase(it, patients.end());
    }
    return patients;
}