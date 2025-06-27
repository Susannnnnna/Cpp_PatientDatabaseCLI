#ifndef PATIENTINPUTCOLLECTOR_H
#define PATIENTINPUTCOLLECTOR_H
#include "../domain/Patient.h"

class PatientInputCollector {
    public: 
        Patient collectNewPatient();
        std::string askForPesel(const std::string& message);
};

#endif // PATIENTINPUTCOLLECTOR_H