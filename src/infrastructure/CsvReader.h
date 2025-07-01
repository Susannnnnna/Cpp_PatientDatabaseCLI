#ifndef CSV_READER_H
#define CSV_READER_H
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class CsvReader {
    public:
        template<typename T>
        static std::vector<T> read(const std::string& filename, T(*deserializer)(std::istringstream&)) {
            std::ifstream file(filename);
            if (!file.is_open()) throw std::runtime_error("Unable to open file for reading");

            std::vector<T> items;
            std::string line;
            while(std::getline(file, line)) {
                if (line.empty()) continue;
                std::istringstream iss(line);
                items.push_back(deserializer(iss));
            }
            return items;
        }
};

#endif // CSV_READER_H