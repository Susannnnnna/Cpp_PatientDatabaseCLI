#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include <iostream>
#include <sstream>
#include <filesystem>
#include <fstream>

struct TestHelpers {
    struct CinRedirect {
        std::streambuf* originalBuffer;
        std::istringstream inputBuffer;

            CinRedirect(const std::string& simulateInput) : inputBuffer(simulateInput) {
                originalBuffer = std::cin.rdbuf(); // Save the original cin buffer
                std::cin.rdbuf(inputBuffer.rdbuf()); // Redirect cin to our input stream
            }    

            ~CinRedirect() { 
                std::cin.rdbuf(originalBuffer); 
            }
    };

    struct CoutRedirect {
        std::streambuf* originalBuffer;
        std::ostringstream captureBuffer;

            CoutRedirect () {
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

    static std::filesystem::path deleteTestFile(const std::string& content = "") {
        return createTempFile("delete_test.csv", content);
    }

    static std::filesystem::path editTestFile(const std::string& content = "") {
        return createTempFile("edit_test.csv", content);
    }

    static std::filesystem::path loadTestFile(const std::string& content = "") {
        return createTempFile("load_test.csv", content);
    }

    static std::filesystem::path saveTestFile(const std::string& content = "") {
        return createTempFile("save_test.csv", content);
    }

    static std::filesystem::path runMenuTestFile(const std::string& content = "") {
        return createTempFile("runmenu_test.csv", content);
    }


    // Helper function to create a temporary file with specified content
    static std::filesystem::path createTempFile(const std::string& fileName, const std::string& content) {
        std::filesystem::path baseDir = std::filesystem::path(PROJECT_DIR) / "data/tests";
        std::filesystem::create_directories(baseDir);
        
        std::filesystem::path filePath = baseDir / fileName;
        std::ofstream outFile(filePath);
        outFile << content;
        outFile.close();

        return filePath;
    }

    static void deleteFile(const std::string& path) {
        if (std::filesystem::exists(path)) {
            std::filesystem::remove(path);
        }
    }
};

#endif // TEST_HELPERS_H