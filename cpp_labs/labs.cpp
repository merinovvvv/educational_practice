//
// Created by merin on 6/25/2024.
//

#include <iostream>
#include <stdexcept>
#include <fstream>
#include "json.hpp"
#include "labs.h"

//void CheckArgumentsAmount (int arguments_amount) {
//    try {
//        if (arguments_amount != 2) {
//            std::ostringstream oss;
//            oss << "Invalid command line arguments amount: current is " << arguments_amount << ", required is 2!";
//            throw std::invalid_argument (oss.str());
//        }
//    } catch (const std::exception& e) {
//        std::cerr << e.what();
//        //system("pause");
//        //exit(0);
//    }
//}

//void CheckInputPath (const std::filesystem::path& path_to_filesystem_object) { //for labs 1, 2
//    try {
//        std::filesystem::path filepath( path_to_filesystem_object.string() );
//        if (!std::filesystem::exists(filepath)) {
//            std::ostringstream oss;
//            oss << "Filesystem object by path " << filepath << " is not exists!";
//            throw std::invalid_argument (oss.str());
//        } else if (!std::filesystem::is_regular_file(filepath)) {
//            std::ostringstream oss;
//            oss << "Filesystem object by path " << filepath << " is not a regular file!";
//            throw std::invalid_argument (oss.str());
//        } else {
//            if (filepath.extension() != ".json") {
//                std::ostringstream oss;
//                oss << "Filesystem object by path " << filepath << " has invalid extension!";
//                throw std::invalid_argument (oss.str());
//            }
//        }
//    } catch (const std::exception& e) {
//        std::cerr << e.what();
//        //system("pause");
//        //exit(0);
//    }
//}

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
        //system("pause");
        return 1;
    }
}

void ModifyJsonObject(nlohmann::json& json_object) {
    for (auto it = json_object.begin(); it != json_object.end(); ++it) {
        if (it.value().is_object()) {
            nlohmann::json& valueObj = it.value();
            for (auto it_2 = valueObj.begin(); it_2 != valueObj.end();) {
                if (it_2.value().is_number_integer() && it_2.value().get<int>() % 2 == 0) {
                    std::cout << "Removing: " << it_2.key() << " = " << it_2.value() << std::endl;
                    it_2 = valueObj.erase(it_2);
                } else {
                    ++it_2;
                }
            }
        }
    }
}


void MakeFile(nlohmann::json& json_object) {
    for (nlohmann::json::iterator it = json_object.begin(); it != json_object.end(); ++it) {
        const std::string filename = "../lab02_folder/" + it.key() + ".json";
        std::ofstream file(filename, std::ios::out);

//        if (!file.is_open()) {
//            std::cerr << "Failed to open file: " << filename << std::endl;
//            continue;
//        }

        try {
            nlohmann::json valueObj = it.value();
            file << valueObj.dump(4);
            file.close();
        } catch (const std::exception& e) {
            std::cerr << "Error writing to file: " << filename << ". " << e.what() << std::endl;
        }
    }
}

std::tm GetRequiredDateTime() {
    std::time_t now = std::time(nullptr);

    std::time_t yesterday = now - 86400;

    std::tm localTime;
    localtime_s(&localTime, &yesterday);
    return localTime;
}

nlohmann::json TmToJson(tm date_time) {
    return nlohmann::json{
            {"year", date_time.tm_year + 1900},
            {"month", date_time.tm_mon},
            {"day", date_time.tm_mday},
            {"hour", date_time.tm_hour},
            {"minute", date_time.tm_min},
            {"second", date_time.tm_sec}
    };
}

void writeToFile(const std::filesystem::path& path_to_filesystem_object, nlohmann::json& json_object) { //for lab03

    std::filesystem::path directory = path_to_filesystem_object.parent_path();

    if (!std::filesystem::exists(directory)) {
        std::filesystem::create_directories(directory);
    }

    std::ofstream jsonData (path_to_filesystem_object, std::ios::out);

    try {
        jsonData << json_object.dump(4) << std::endl;
        jsonData.close();
    } catch (const std::runtime_error& e) {
        std::cerr << "Failed to open file for writing: " + path_to_filesystem_object.string();
    }
}

//void CheckInputPath (const std::filesystem::path& path_to_filesystem_object) { //for lab03
//    try {
//        std::filesystem::path filepath( path_to_filesystem_object.string() );
//        if (filepath.extension() != ".json") {
//            std::ostringstream oss;
//            oss << "Filesystem object by path " << filepath << " has invalid extension!";
//            throw std::invalid_argument (oss.str());
//        }
//    } catch (const std::exception& e) {
//        std::cerr << e.what();
//        //system("pause");
//        //exit(0);
//    }
//}

//void CheckInputPath (const std::filesystem::path& path_to_filesystem_object) { //for lab 4
//    try {
//        std::filesystem::path filepath( path_to_filesystem_object.string() );
//        if (!std::filesystem::exists(filepath)) {
//            std::ostringstream oss;
//            oss << "Filesystem object by path " << filepath << " is not exists!";
//            throw std::invalid_argument (oss.str());
//        } else if (!std::filesystem::is_regular_file(filepath) && !std::filesystem::is_directory(filepath)) {
//            std::ostringstream oss;
//            oss << "Filesystem object by path " << filepath << " has invalid type!";
//            throw std::invalid_argument (oss.str());
//        }
//    } catch (const std::exception& e) {
//        std::cerr << e.what();
//        //system("pause");
//        //exit(0);
//    }
//}

std::size_t Size (const std::filesystem::path& path_to_filesystem_object) {

    std::size_t total_size = 0;

    if (std::filesystem::is_directory(path_to_filesystem_object)) {

        for (const auto& dir : std::filesystem::recursive_directory_iterator(path_to_filesystem_object)) {

            if (std::filesystem::is_regular_file(dir)) {
                total_size += std::filesystem::file_size(dir);
            }
        }
    } else if (std::filesystem::is_regular_file(path_to_filesystem_object)) {
        total_size = std::filesystem::file_size(path_to_filesystem_object);
    }

    return total_size;
}

nlohmann::json GetRegularFileInfo (const std::filesystem::path& path_to_file) {
        nlohmann::json jsonObject;

        jsonObject["type"] = "reguar_file";
        jsonObject["full_name"] = path_to_file.filename().string();
        jsonObject["name_without_extension"] = path_to_file.stem().string();

        if (path_to_file.has_extension()) {
            jsonObject["extension"] = path_to_file.extension().string();
        } else {
            jsonObject["extension"] = nullptr;
        }

        jsonObject["size"] = Size(path_to_file);

        return jsonObject;
}

nlohmann::json GetDirectoryInfo (const std::filesystem::path& path_to_directory) {
        std::ofstream out(path_to_directory, std::ios::out);

        nlohmann::json jsonObject;

        jsonObject["type"] = "directory";

        jsonObject["name"] = path_to_directory.stem().string();
        jsonObject["size"] = Size(path_to_directory);

        size_t files_amount = 0;
        size_t directories_amount = 0;

        for (const auto& dir : std::filesystem::directory_iterator(path_to_directory)) {
            if (std::filesystem::is_regular_file(dir.path())) {
                ++files_amount;
            } else if (std::filesystem::is_directory(dir.path())) {
                ++directories_amount;
            }
        }

        jsonObject["files_amount"] = files_amount;
        jsonObject["directories_amount"] = directories_amount;

        return jsonObject;
}

nlohmann::json GetFsObjectInfo (const std::filesystem::path& path_to_filesystem_object) {

    nlohmann::json fs_object_info;

    if (std::filesystem::is_regular_file(path_to_filesystem_object)) {
        fs_object_info = GetRegularFileInfo(path_to_filesystem_object);
    } else if (std::filesystem::is_directory(path_to_filesystem_object)) {
        fs_object_info = GetDirectoryInfo(path_to_filesystem_object);
    } else {
        throw std::runtime_error("Unsupported filesystem object type or path does not exist: " + path_to_filesystem_object.string());
    }

    return fs_object_info;
}

void writeJsonToFile (const std::filesystem::path& path_to_filesystem_object, nlohmann::json& json_object) { //for lab04
    std::filesystem::path directory = path_to_filesystem_object.parent_path();

    std::string filePath = directory.string() + "/fs_object_info.json";

    std::ofstream jsonData (filePath, std::ios::out);

    try {
        jsonData << json_object.dump(4) << std::endl;
        jsonData.close();
    } catch (const std::runtime_error& e) {
        std::cerr << "Failed to open file for writing: " + path_to_filesystem_object.string();
    }
}

void CheckInputPath (const std::filesystem::path& path_to_filesystem_object) { //for lab 5
    try {
        std::filesystem::path filepath( path_to_filesystem_object.string() );
        if (!std::filesystem::exists(filepath)) {
            std::ostringstream oss;
            oss << "Filesystem object by path " << filepath << " is not exists!";
            throw std::invalid_argument (oss.str());
        } else if (!std::filesystem::is_directory(filepath)) {
            std::ostringstream oss;
            oss << "Filesystem object by path " << filepath << " is not a directory!";
            throw std::invalid_argument (oss.str());
        }
    } catch (const std::exception& e) {
        std::cerr << e.what();
        //system("pause");
        //exit(0);
    }
}

namespace filesystem_object {
    std::size_t Size(const std::filesystem::path &path_to_filesystem_object) {
        size_t totalSize = 0;
        if (std::filesystem::is_directory(path_to_filesystem_object)) {
            for (const auto &dir: std::filesystem::recursive_directory_iterator(path_to_filesystem_object)) {
                if (std::filesystem::is_regular_file(dir)) {
                    totalSize += std::filesystem::file_size(dir);
                }
            }
        } else if (std::filesystem::is_regular_file(path_to_filesystem_object)) {
            totalSize = std::filesystem::file_size(path_to_filesystem_object);
        } else {
            throw std::runtime_error("Invalid filesystem object.");
        }
        return totalSize;
    }

    Info::Info(const std::filesystem::path &path_to_filesystem_object) {
        if (std::filesystem::is_directory(path_to_filesystem_object)) {
            name = path_to_filesystem_object.stem().string();
            type = "directory";
            size = Size(path_to_filesystem_object);
        } else if (std::filesystem::is_regular_file(path_to_filesystem_object)) {
            name = path_to_filesystem_object.stem().string();
            size = std::filesystem::file_size(path_to_filesystem_object);
            auto extension = path_to_filesystem_object.extension().string();
            if (extension.empty()) {
                type = "file without extension";
            } else {
                type = extension;
            }
        } else {
            throw std::runtime_error("Invalid filesystem object.");
        }
    }

    std::ostream &operator<<(std::ostream &os, const Info &info) {
        os << std::left << std::setfill(' ')
           << std::setw(50) << info.name
           << std::setw(20) << info.type
           << std::setw(20) << info.size;
        return os;
    }

    Info GetInfo (const std::filesystem::path& path_to_filesystem_object) {
        return Info(path_to_filesystem_object);
    }
}

namespace directory_content {

    Info::Info(const std::filesystem::path &path_to_dir) {
        if (std::filesystem::is_directory(path_to_dir)) {
            path_to_directory = path_to_dir;
            size =  filesystem_object::Size(path_to_dir);

            size_t filesAmount = 0;
            size_t directoriesAmount = 0;

            for (const auto& obj :  std::filesystem::directory_iterator(path_to_dir)) {
                if (std::filesystem::is_regular_file(obj)) {
                    filesAmount++;
                } else if (std::filesystem::is_directory(obj)) {
                    directoriesAmount++;
                } else {
                    throw std::invalid_argument("Unknown type of file.");
                }
            }

            files_amount = filesAmount;
            directories_amount = directoriesAmount;

        }
    }

    std::ostream& operator<< (std::ostream& os, const Info& info) {
        os << std::left << std::setfill(' ');

        os << std::setw(50) << "Path to directory: " << std::setw(20) << info.path_to_directory << "\n";
        os << std::setw(50) << "Size (bytes): " << std::setw(20) << info.size << "\n";
        os << std::setw(50) << "Files amount (1st lvl): " << std::setw(20) << info.files_amount << "\n";
        os << std::setw(50) << "Directories amount (1st lvl): " << std::setw(20) << info.directories_amount  << "\n";
        return os;
    }

    Info GetInfo(const std::filesystem::path& path_to_directory) {
        return Info(path_to_directory);
    }
}

void CheckArgumentsAmount (int arguments_amount) { //for lab06
    try {
        if (arguments_amount != 3) {
            std::ostringstream oss;
            oss << "Invalid command line arguments amount: current is " << arguments_amount << ", required is 3!";
            throw std::invalid_argument (oss.str());
        }
    } catch (const std::exception& e) {
        std::cerr << e.what();
        //system("pause");
        //exit(0);
    }
}

void CheckDirectoryPath (const std::filesystem::path& path_to_directory_1, const std::filesystem::path& path_to_directory_2) {
    try {
        std::filesystem::path filepath1( path_to_directory_1.string() );
        std::filesystem::path filepath2( path_to_directory_2.string() );
        if (!std::filesystem::exists(filepath1)) {
            std::ostringstream oss;
            oss << "Filesystem object by path " << filepath1 << " is not exists!";
            throw std::invalid_argument (oss.str());
        } else if (!std::filesystem::exists(filepath2)) {
            std::ostringstream oss;
            oss << "Filesystem object by path " << filepath2 << " is not exists!";
            throw std::invalid_argument (oss.str());
        } else if (!std::filesystem::is_directory(filepath1)) {
            std::ostringstream oss;
            oss << "Filesystem object by path " << filepath1 << " is not a directory!";
            throw std::invalid_argument (oss.str());
        } else if (!std::filesystem::is_directory(filepath2)) {
            std::ostringstream oss;
            oss << "Filesystem object by path " << filepath2 << " is not a directory!";
            throw std::invalid_argument (oss.str());
        }
    } catch (const std::exception& e) {
        std::cerr << e.what();
        //system("pause");
        //exit(0);
    }
}

std::string ReadFileContent (const std::filesystem::path& path_to_file) {
    try {
        std::filesystem::path filepath( path_to_file.string() );
        if (!std::filesystem::exists(filepath)) {
            std::ostringstream oss;
            oss << "Filesystem object by path " << filepath << " is not exists!";
            throw std::invalid_argument (oss.str());
        }
        std::ifstream in (filepath, std::ios::in);

        if (!in.is_open()) {
            std::ostringstream os;
            os << "Filesystem object by path " << path_to_file << " hasn’t been opened!";
            throw std::invalid_argument(os.str());
        }

        in.seekg(0, std::ios::end);
        std::streamsize size = in.tellg();
        in.seekg(0, std::ios::beg);

        std::string content;
        content.resize(static_cast<size_t>(size));

        if (!in.read(&content[0], size)) {
            std::ostringstream oss;
            oss << "Failed to read file content from " << path_to_file;
            throw std::runtime_error(oss.str());
        }

        in.close();

        return content;

    } catch (const std::exception& e) {
        std::cerr << e.what();
        //system("pause");
        //exit(0);
    }
}

std::set<std::string> GetFilesContentFromDirectory (const std::filesystem::path& path_to_directory) {

    std::set<std::string> contents;

    for (const auto& entry : std::filesystem::directory_iterator(path_to_directory)) {
        if (entry.is_regular_file()) {
            std::string file_content = ReadFileContent(entry.path());
            if (!file_content.empty()) {
                contents.insert(file_content);
            }
        }
    }
    return contents;
}

void setInsert (std::set <std::string>& filesSet, const std::filesystem::path& path_to_directory_1, const std::filesystem::path& path_to_directory_2) {

    for (const auto& dir : std::filesystem::recursive_directory_iterator(path_to_directory_1)) {

        bool isEqual = false;

        for (const auto& dir : std::filesystem::recursive_directory_iterator(path_to_directory_1)) {
            std::string fileContent = ReadFileContent(dir);

            for (auto it = filesSet.begin(); it != filesSet.end(); ++it) {
                if (*it == fileContent) {
                    isEqual = true;
                }
            }
            if (!isEqual) {
                filesSet.insert(fileContent);
                std::cout << "File by path " << dir << " has been copied to directory by path " << path_to_directory_2 << " !";
                std::filesystem::path targetFilePath = path_to_directory_2 / dir.path().filename();
                std::filesystem::copy_file(dir, targetFilePath, std::filesystem::copy_options::overwrite_existing);
            }
        }
    }
}