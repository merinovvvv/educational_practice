//
// Created by merin on 6/25/2024.
//

#include <stdexcept>
#include <ctime>
#include "json.hpp"

#ifndef CPP_LABS_LABS_H
#define CPP_LABS_LABS_H


void CheckArgumentsAmount (int arguments_amount);
void CheckInputPath (const std::filesystem::path& path_to_filesystem_object);
bool IsJsonCorrect(const nlohmann::json& json);
nlohmann::json parseFile(const std::filesystem::path& path_to_filesystem_object);

void ModifyJsonObject(nlohmann::json& json_object);
void MakeFile(nlohmann::json& json_object);

std::tm GetRequiredDateTime();
nlohmann::json TmToJson(tm date_time);
void writeToFile(const std::filesystem::path& path_to_filesystem_object, nlohmann::json& json_object);

std::size_t Size (const std::filesystem::path& path_to_filesystem_object);
nlohmann::json GetRegularFileInfo (const std::filesystem::path& path_to_file);
nlohmann::json GetDirectoryInfo (const std::filesystem::path& path_to_directory);
nlohmann::json GetFsObjectInfo (const std::filesystem::path& path_to_filesystem_object);
void writeJsonToFile (const std::filesystem::path& path_to_filesystem_object, nlohmann::json& json_object);

namespace filesystem_object {
    std::size_t Size(const std::filesystem::path& path_to_filesystem_object);
    struct Info {
        std::string name;
        std::string type;
        std::size_t size;

        explicit Info(const std::filesystem::path& path_to_filesystem_object);
    };

    std::ostream& operator<< (std::ostream& os, const Info& info);

    Info GetInfo (const std::filesystem::path& path_to_filesystem_object);
}

namespace directory_content {
    struct Info {
        std::filesystem::path path_to_directory;
        std::size_t size;
        uint32_t files_amount;
        uint32_t directories_amount;

        explicit Info(const std::filesystem::path& path_to_filesystem_object);

    };

    std::ostream& operator<< (std::ostream& os, const Info& info);

    Info GetInfo(const std::filesystem::path& path_to_directory);
}

#endif //CPP_LABS_LABS_H