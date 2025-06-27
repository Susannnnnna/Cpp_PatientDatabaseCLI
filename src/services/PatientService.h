#include "Patient.h"
#include <vector>

class PatientService {
    public:
        static std::vector<Patient> addPatient(const std::vector<Patient>& pateints);
        static std::vector<Patient> editPatient(const std::vector<Patient>& patients);
        static std::vector<Patient> deletePatient(const std::vector<Patient>& patients);
        static void listPatients(const std::vector<Patient>& patients);
};