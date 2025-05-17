
#include <iostream>
#include "Patient.h"
#include "PatientService.h"
#include "PatientFileRepository.h"
#include "Menu.h"

int main() {
    try {
        runMenu();
    } catch (const std::exception& e) {
        std::cerr << "An error occured: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}