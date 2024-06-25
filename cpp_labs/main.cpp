#include <iostream>
#include <stdexcept>
#include "json.hpp"

void CheckArgumentsAmount (int arguments_amount) {
    try {
        if (arguments_amount != 2) {
            std::ostringstream oss;
            oss << "Invalid command line arguments amount: current – " << arguments_amount << ", required – 2!";
            throw std::invalid_argument (oss.str());
        }
    } catch (std::exception& ex) {
        std::cerr << ex.what();
        exit(0);
    }
}

void CheckInputPath (const std::filesystem::path& path_to_filesystem_object) {
    try {
        std::filesystem::path filepath( "path_to_filesystem_object" );
        if (!std::filesystem::exists(filepath)) {
            std::ostringstream oss;
            oss << "Filesystem object by path " << filepath << " is not exists!";
            throw std::invalid_argument (oss.str());
        } else if (!std::filesystem::is_regular_file(filepath)) {
            std::ostringstream oss;
            oss << "Filesystem object by path " << filepath << " is not a regular file!";
            throw std::invalid_argument (oss.str());
        } else {
            if (filepath.extension() != ".json") {
                std::ostringstream oss;
                oss << "Filesystem object by path " << filepath << " has invalid extension!";
                throw std::invalid_argument (oss.str());
            }
        }
    } catch (std::exception& ex) {
        std::cerr << ex.what();
        exit(0);
    }
}

bool IsJsonCorrect(const nlohmann::json& json) {
    try {
        if (!json.is_array() || !json.is_object() || !json.is_string() || !json.is_number() || !json.is_boolean() || !json.is_null()) {
            throw std::invalid_argument ("Not a nlohmann::json object.");
        }
    } catch (std::exception& ex) {
        std::cerr << ex.what();
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;
    
    return 0;
}
