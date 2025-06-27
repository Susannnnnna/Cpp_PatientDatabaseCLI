#pragma once
#include "../domain/Patient.h"
#include <vector>

class PatientPrinter {
    public:
        void listPatients(const std::vector<Patient>& patients);
        void printMessage(const std::string& message);
};