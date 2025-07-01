#ifndef PATIENT_PRINTER_H
#define PATIENT_PRINTER_H
#include "../domain/Patient.h"
#include <vector>

class PatientPrinter {
    public:
        void listPatients(const std::vector<Patient>& patients);
        void printMessage(const std::string& message);
};

#endif // PATIENT_PRINTER_H