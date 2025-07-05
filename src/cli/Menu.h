#ifndef MENU_H
#define MENU_H

#include <string>

void runMenu(
    const std::string& filePath = std::string(PROJECT_DIR) + "/data/patients.csv"
);

#endif // MENU_H