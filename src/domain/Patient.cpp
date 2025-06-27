#include "Patient.h"
#include <vector>

std::vector<Patient> addPatients(const std::vector<Patient>& patients, const Patient& newPatient) {
    auto updatedPatients = patients;
    updatedPatients.push_back(newPatient);
    return updatedPatients;
}