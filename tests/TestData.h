#ifndef TEST_DATA_H
#define TEST_DATA_H

#include "../src/domain/Patient.h"

namespace TestData {
    struct PatientFactory {
        static Patient makeSamplePatient() {
            return Patient {
                "John", 
                "Doe", 
                "12345678901", 
                "456 Elm St 555-5678", 
                "555-5678"
            };
        }

        static Patient makeSamplePatient2() {
            return Patient {
                "Alice", 
                "Smith", 
                "23456789012", 
                "123 Main St 555-1234", 
                "555-1234"
            };
        }

        static Patient makeSamplePatientWithInvalidPesel() {
            return Patient {
                "Jane", 
                "Smith", 
                "1234567890", // Invalid PESEL (should be 11 digits)
                "789 Oak St 555-6789", 
                "555-6789"
            };
        }

        static Patient makeSamplePatientWithEmptyFields() {
            return Patient {
                "", 
                "", 
                "", 
                "", 
                ""
            };
        }

        static Patient createPatient(
            const std::string& first_name,
            const std::string& last_name,
            const std::string& pesel,
            const std::string& address,
            const std::string& phone_number) 
        {
            return Patient {
                first_name,
                last_name,
                pesel,
                address,
                phone_number
            };
        }
    };
}

#endif // TEST_DATA_H