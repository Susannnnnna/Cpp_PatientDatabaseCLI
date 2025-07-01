#ifndef TEST_DATA_H
#define TEST_DATA_H

#include "../src/domain/Patient.h"

namespace TestData {
    inline Patient makeSamplePatient() {
        return Patient {
            "John", 
            "Doe", 
            "12345678901", 
            "456 Elm St 555-5678", 
            "555-5678"
        };
    }
}

#endif // TEST_DATA_H