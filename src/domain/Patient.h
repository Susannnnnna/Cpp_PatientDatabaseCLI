#ifndef PATIENT_H
#define PATIENT_H

#include <string>

struct Patient {
    std::string first_name;
    std::string last_name;
    std::string pesel;
    std::string address;
    std::string phone_number;    
};

#endif // PATIENT_H
