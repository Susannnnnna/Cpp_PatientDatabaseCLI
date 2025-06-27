#pragma once
#include "../domain/IRepository.h"
#include "../domain/Patient.h"
#include "CsvReader.h"
#include "CsvWriter.h"

class CsvPatientRepository : public IRepository<Patient> {
    std::string file;

    public:
        CsvPatientRepository(const std::string& filePath) : file(filePath) {}

        std::vector<Patient> load() override;
        void save(const std::vector<Patient>& items) override;
};
