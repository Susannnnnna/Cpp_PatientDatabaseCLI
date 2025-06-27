#include "Validator.h"
#include <cctype>

bool Validator::isValidPesel(const std::string& pesel) {
    if(pesel.length() != 11) return false;
    for(char c : pesel) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}