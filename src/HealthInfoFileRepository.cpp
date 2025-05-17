#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "HealthInfoFileRepository.h"

void HealthInfoFileRepository::displayHealthInfo(const std::string& pesel) {
    std::string path = std::string(PROJECT_SOURCE_DIR) + std::string("/data");
    std::filesystem::create_directories(path);
    std::string filePath = path + "/health_info_" + pesel + ".txt";

    if(!std::filesystem::exists(filePath)) {
        std::ofstream createFile(filePath);
        createFile.close();
    }
    std::ifstream file(filePath);
    if(!file.is_open()) {
        std::cerr << "Error: Unable to open file for patient with PESEL: " << pesel << std::endl;
        return;
    }

    std::cout << "Health information for patient with PESEL: " << pesel << std::endl;
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}