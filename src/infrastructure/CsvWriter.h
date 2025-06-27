#pragma once
#include <vector>
#include <string>
#include <fstream>

class CsvWriter {
    public:
        template<typename T>
        static void write(const std::vector<T>& items, const std::string& filename, void(*serializer)(std::ofstream&, const T&)) {
            std::ofstream file(filename);
            if(!file.is_open()) throw std::runtime_error("Unable to open file for writing.");
            for (const auto& item : items) {
                serializer(file, item);
            }
        }
};