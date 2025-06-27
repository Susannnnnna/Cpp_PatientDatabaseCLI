
#include <iostream>
#include "cli/Menu.h"

int main() {
    try {
        runMenu();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}