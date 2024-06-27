//
// Created by merin on 6/25/2024.
//

#include <stdexcept>
#include <ctime>
#include <set>
#include <functional>
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

void CheckDirectoryPath (const std::filesystem::path& path_to_directory);
std::string ReadFileContent (const std::filesystem::path& path_to_file);
std::set<std::string> GetFilesContentFromDirectory (const std::filesystem::path& path_to_directory);
void setInsert (std::set <std::string>& filesSet, const std::filesystem::path& path_to_directory_1, const std::filesystem::path& path_to_directory_2);

class FilesStorage {

public:
    std::filesystem::path path_to_directory_;
    std::set<std::string> files_content_storage_;

    FilesStorage(const std::filesystem::path& path_to_directory): path_to_directory_(path_to_directory) {};

    void InitStorage();
    void CopyFile(const std::filesystem::path& path_to_file);

    void CopyFilesFromDirectory(const std::filesystem::path& sourceDirectory, const std::filesystem::path& destinationDirectory);
};


std::size_t GetFileContentHash (const std::filesystem::path& path_to_file);
void RemoveDuplicatesFromDirectory (const std::filesystem::path& path_to_directory);

std::filesystem::path GetPathToMove (const std::filesystem::path& path_to_file);
void Move(const std::filesystem::path& path_to_file);
void MoveForFiles(const std::filesystem::path& path_to_directory);

class FileName {
public:
    std::filesystem::path path_to_current_file;
    uint16_t year;
    uint16_t month;
    uint16_t day;
    std::string only_name;

    FileName(std::filesystem::path path_to_file): path_to_current_file(path_to_file) {};

    void Parse();
    bool IsRemoveRequired() const;
};

void MoveAndDelete(const std::filesystem::path& path_to_directory);

#endif //CPP_LABS_LABS_H