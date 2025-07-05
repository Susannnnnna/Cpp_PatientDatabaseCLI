#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <fstream>
#include "../src/cli/Menu.h"
#include "../src/infrastructure/CsvPatientRepository.h"
#include "../src/domain/Patient.h"

// Helper to redirect std::cin
class CinRedirect {
    std::streambuf* originalBuffer;
    std::istringstream inputBuffer;

public:
    CinRedirect(const std::string& simulateInput) : inputBuffer(simulateInput) {
        originalBuffer = std::cin.rdbuf();
        std::cin.rdbuf(inputBuffer.rdbuf());
    }

    ~CinRedirect() {
        std::cin.rdbuf(originalBuffer);
    }
};

// Helper to redirect std::cout
class CoutRedirect {
    std::streambuf* originalBuffer;
    std::ostringstream captureBuffer;

public:
    CoutRedirect() {
        originalBuffer = std::cout.rdbuf();
        std::cout.rdbuf(captureBuffer.rdbuf());
    }

    ~CoutRedirect() {
        std::cout.rdbuf(originalBuffer);
    }

    std::string getOutput() const {
        return captureBuffer.str();
    }
};

// === TEST ===
// Given: Empty patient database
// When: Simulate CLI session: add patient -> list patients -> exit
// Then: Patient data is saved to CSV and appears in output
TEST(SystemTestBDD, RunMenu_SimulateFullCLISession) {
    std::string dataDir = PROJECT_DIR + std::string("/data/tests");
    std::string testCsv = dataDir + "/test_runmenu.csv";

    // Ensure folder exists
    if (!std::filesystem::exists(dataDir)) {
        std::filesystem::create_directories(dataDir);
    }

    // Ensure file is clean
    if (std::filesystem::exists(testCsv)) {
        std::filesystem::remove(testCsv);
    }

    // Simulated user input
    std::string simulatedInput =
        "1\n"           // Add patient
        "Joe\n"         // First name
        "Doe\n"         // Last name
        "12345678901\n" // PESEL
        "123 Main St\n" // Address
        "555-1234\n"    // Phone number
        "4\n"           // Show patients
        "0\n";          // Exit

    CinRedirect cinRedirect(simulatedInput);
    CoutRedirect coutRedirect;

    // Run menu
    runMenu(testCsv);

    // Capture output
    std::string output = coutRedirect.getOutput();

    // Check if patient data appeared in output
    EXPECT_TRUE(output.find("Joe") != std::string::npos);
    EXPECT_TRUE(output.find("Doe") != std::string::npos);
    EXPECT_TRUE(output.find("12345678901") != std::string::npos);
    EXPECT_TRUE(output.find("123 Main St") != std::string::npos);
    EXPECT_TRUE(output.find("555-1234") != std::string::npos);

    // Check if patient data was saved to file
    ASSERT_TRUE(std::filesystem::exists(testCsv));
    std::ifstream file(testCsv);
    std::string line;
    bool found = false;
    while (std::getline(file, line)) {
        if (line.find("Joe,Doe,12345678901,123 Main St,555-1234") != std::string::npos) {
            found = true;
            break;
        }
    }
    file.close();
    EXPECT_TRUE(found);

    // Clean up test file
    std::filesystem::remove(testCsv);
}
