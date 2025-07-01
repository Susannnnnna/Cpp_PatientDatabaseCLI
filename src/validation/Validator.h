#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

class Validator {
    public:
    static bool isValidPesel(const std::string& pesel);
};

#endif // VALIDATOR_H