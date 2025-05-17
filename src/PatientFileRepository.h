#include "Patient.h"
#include <vector>
#include <string>

class PatientFileRepository {
    public:
        static void savePatients(const std::vector<Patient>& patients, const std::string& filename);
        static std::vector<Patient> loadPatients(const std::string& filename);
};