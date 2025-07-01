#ifndef PATIENT_SERVICE_H
#define PATIENT_SERVICE_H

#include "domain/Patient.h"
#include <vector>
#include <string>

class PatientService {
    public:
        static std::vector<Patient> addPatient(const std::vector<Patient>&, const Patient& newPatients);
        static std::vector<Patient> editPatient(std::vector<Patient> patients, const std::string& pesel, const Patient& updatedData);
        static std::vector<Patient> deletePatient(std::vector<Patient> patients, const std::string& pesel);
};

#endif // PATIENT_SERVICE_H