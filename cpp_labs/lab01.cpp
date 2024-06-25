//
// Created by merin on 6/25/2024.
//

#include <iostream>
#include <stdexcept>
#include <fstream>
#include "json.hpp"
#include "lab01.h"

void CheckArgumentsAmount (int arguments_amount) {
    try {
        if (arguments_amount != 2) {
            std::ostringstream oss;
            oss << "Invalid command line arguments amount: current – " << arguments_amount << ", required – 2!";
            throw std::invalid_argument (oss.str());
        }
    } catch (const std::exception& e) {
        std::cerr << e.what();
        system("pause");
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
    } catch (const std::exception& e) {
        std::cerr << e.what();
        system("pause");
        exit(0);
    }
}

bool IsJsonCorrect(const nlohmann::json& json) {
    if (!json.is_object()) {
        return false;
    }

    if (!json.contains("string_0") || !json["string_0"].is_string()) {
        return false;
    }
    if (!json.contains("number") || !json["number"].is_number_integer()) {
        return false;
    }
    if (!json.contains("object") || !json["object"].is_object()) {
        return false;
    }

    const auto& object = json["object"];
    if (!object.contains("boolean") || !object["boolean"].is_boolean()) {
        return false;
    }
    if (!object.contains("array") || !object["array"].is_array()) {
        return false;
    }

    if (!json.contains("string_1") || !json["string_1"].is_null()) {
        return false;
    }
    if (!json.contains("array") || !json["array"].is_null()) {
        return false;
    }
    return true;
}

nlohmann::json parseFile(const std::filesystem::path& path_to_filesystem_object) {
    try {
        std::ifstream in(path_to_filesystem_object);
        nlohmann::json json_from_file = nlohmann::json::parse( in );
        return json_from_file;
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "Parse error: " << e.what() << std::endl;
        system("pause");
        return 1;
    }
}