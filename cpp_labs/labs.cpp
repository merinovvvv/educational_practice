//
// Created by merin on 6/25/2024.
//

#include <iostream>
#include <stdexcept>
#include <fstream>
#include "json.hpp"
#include "labs.h"

void CheckArgumentsAmount (int arguments_amount, const size_t& labNumber) {

    if (labNumber >= 1 && labNumber <= 5 || labNumber >= 8 && labNumber <= 10) {
        try {
            if (arguments_amount != 2) {
                std::ostringstream oss;
                oss << "Invalid command line arguments amount: current is " << arguments_amount << ", required is 2!";
                throw std::invalid_argument (oss.str());
            }
        } catch (const std::exception& e) {
            std::cerr << e.what();
            //system("pause");
            //exit(0);
        }
    } else if (labNumber == 6 || labNumber == 7) {
        try {
            if (arguments_amount != 3) {
                std::ostringstream oss;
                oss << "Invalid command line arguments amount: current is " << arguments_amount << ", required is 3!";
                throw std::invalid_argument(oss.str());
            }
        } catch (const std::exception &e) {
            std::cerr << e.what();
        }
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

    std::tm localTime{};
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

void CheckInputPath (const std::filesystem::path& path_to_filesystem_object, const size_t& labNumber) {
    if (labNumber >= 5 && labNumber <= 10) {
        try {
            std::filesystem::path filepath( path_to_filesystem_object.string() );
            if (!std::filesystem::exists(filepath)) {
                std::ostringstream oss;
                oss << "Filesystem object by path " << filepath << " is not exists!";
                throw std::runtime_error (oss.str());
            } else if (!std::filesystem::is_directory(filepath)) {
                std::ostringstream oss;
                oss << "Filesystem object by path " << filepath << " is not a directory!";
                throw std::runtime_error (oss.str());
            }
        } catch (const std::exception& e) {
            std::cerr << e.what();
            //system("pause");
            //exit(0);
        }
    } else if (labNumber == 4) {
        try {
            std::filesystem::path filepath(path_to_filesystem_object.string());
            if (!std::filesystem::exists(filepath)) {
                std::ostringstream oss;
                oss << "Filesystem object by path " << filepath << " is not exists!";
                throw std::invalid_argument(oss.str());
            } else if (!std::filesystem::is_regular_file(filepath) && !std::filesystem::is_directory(filepath)) {
                std::ostringstream oss;
                oss << "Filesystem object by path " << filepath << " has invalid type!";
                throw std::invalid_argument(oss.str());
            }
        } catch (const std::exception &e) {
            std::cerr << e.what();
        }
    } else if (labNumber == 3) {
        try {
            std::filesystem::path filepath( path_to_filesystem_object.string() );
            if (filepath.extension() != ".json") {
                std::ostringstream oss;
                oss << "Filesystem object by path " << filepath << " has invalid extension!";
                throw std::invalid_argument (oss.str());
            }
        } catch (const std::exception& e) {
            std::cerr << e.what();
        }
    } else if (labNumber == 1 || labNumber == 2) {
        try {
            std::filesystem::path filepath( path_to_filesystem_object.string() );
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
        }
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

void CheckDirectoryPath (const std::filesystem::path& path_to_directory) {
    try {
        std::filesystem::path filepath( path_to_directory.string() );
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
            os << "Filesystem object by path " << path_to_file << " has not been opened!";
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

    return "";
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

void setInsert (std::set <std::string>& filesSet, const std::filesystem::path& path_to_directory_1, const std::filesystem::path& path_to_directory_2) { //TODO

    for (const auto &dir: std::filesystem::directory_iterator(path_to_directory_1)) {
        bool isEqual = false;
        if (std::filesystem::is_regular_file(dir)) {
            std::string fileContent = ReadFileContent(dir);

            for (auto it = filesSet.begin(); it != filesSet.end(); ++it) {
                if (*it == fileContent) {
                    isEqual = true;
                }
            }
            if (!isEqual) {
                filesSet.insert(fileContent);
                std::cout << "File by path " << dir << " has been copied to directory by path " << path_to_directory_2
                          << " !";
                std::filesystem::path targetFilePath = path_to_directory_2 / dir.path().filename();
                std::filesystem::copy_file(dir, targetFilePath, std::filesystem::copy_options::overwrite_existing);
            }
        }
    }
}

void FilesStorage::InitStorage() {
    for (const auto& dir : std::filesystem::directory_iterator(path_to_directory_)) {
        if (std::filesystem::is_regular_file(dir)) {
            files_content_storage_.insert(ReadFileContent(dir.path()));
        }
    }
}

void FilesStorage::CopyFile(const std::filesystem::path& path_to_file) {

    bool isEqual = false;

    std::string fileContent = ReadFileContent(path_to_file);

    for (auto it = files_content_storage_.begin(); it != files_content_storage_.end(); ++it) {
        if (*it == fileContent) {
            isEqual = true;
        }
    }
    if (!isEqual) {
        files_content_storage_.insert(fileContent);
        std::cout << "File by path " << path_to_file << " has been copied to directory by path " << path_to_directory_ << " !";
        std::filesystem::path targetFilePath = path_to_directory_ / path_to_file.filename();
        std::filesystem::copy_file(path_to_file, targetFilePath, std::filesystem::copy_options::overwrite_existing);
    }
}

void FilesStorage::CopyFilesFromDirectory(const std::filesystem::path& sourceDirectory, const std::filesystem::path& destinationDirectory) {
    for (const auto& dir : std::filesystem::directory_iterator(sourceDirectory)) {
        if (dir.is_regular_file()) {
            std::filesystem::path destinationFile = destinationDirectory / dir.path().filename();
            CopyFile(dir.path());
        }
    }
}

std::size_t GetFileContentHash (const std::filesystem::path& path_to_file) {
    if (std::filesystem::is_regular_file(path_to_file)) {
        std::string str = ReadFileContent(path_to_file);
        std::hash<std::string> hash_fn;

        size_t hash = hash_fn(str);
        return hash;
    }
    return 0;
}

void RemoveDuplicatesFromDirectory (const std::filesystem::path& path_to_directory) {
    std::set <std::size_t> hashes;
    for (const auto& dir : std::filesystem::directory_iterator(path_to_directory)) {
        size_t hash = GetFileContentHash(dir);
        auto [_, inserted] = hashes.insert(hash);
        if (!inserted) {
            std::filesystem::remove(dir);
            std::cout << "File by path " << dir.path() << " has been removed";
        }
    }
}

void Move(const std::filesystem::path& path_to_file, const size_t& labNumber) {

    try {
        std::filesystem::path new_path = GetPathToMove(path_to_file, labNumber);
        std::filesystem::create_directories(new_path.parent_path());
        std::filesystem::rename(path_to_file, new_path);
        std::cout << "File by path " << path_to_file << " has been moved to " << new_path << "!";
    } catch (std::exception& ex) {
        std::cerr << ex.what();
    }
}

void MoveForFiles(const std::filesystem::path& path_to_directory, const size_t& labNumber) {
    for (const auto& dir : std::filesystem::directory_iterator(path_to_directory)) {
        if (std::filesystem::is_regular_file(dir)) {
                Move(dir.path(), labNumber);
        }
    }
}

void FileName::Parse() {
    try {
        std::string filename = path_to_current_file.filename().string();
        std::string stem = path_to_current_file.stem().string();
        std::string extension = path_to_current_file.extension().string();

        std::size_t first_underscore = filename.find('_');
        std::size_t second_underscore = filename.find('_', first_underscore + 1);
        std::size_t third_underscore = filename.find('_', second_underscore + 1);

        if (first_underscore == std::string::npos || second_underscore == std::string::npos || third_underscore == std::string::npos) {
            throw std::invalid_argument("Invalid filename. File path: " + path_to_current_file.string() + "!");
        }

        year = std::stoll(stem.substr(0, first_underscore));
        month = std::stoll(stem.substr(first_underscore + 1, second_underscore - first_underscore - 1));
        day = std::stoll(stem.substr(second_underscore + 1, third_underscore - second_underscore - 1));
        only_name = stem.substr(third_underscore + 1);

    } catch (std::exception& ex) {
        std::cerr << ex.what();
        exit(0);
    }
}

bool FileName::IsRemoveRequired() const {
    if (year % 5 == 0 && day % 5 == 0) {
        return true;
    } else {
        return false;
    }
}

std::filesystem::path GetPathToMove (const std::filesystem::path& path_to_file, const size_t& labNumber) { //for labs 9, 10

    if (labNumber == 10) {
        FileName fname(path_to_file);
        fname.Parse();

        std::filesystem::path new_path = path_to_file.parent_path();
        new_path.append(std::to_string(fname.year));
        new_path.append(std::to_string(fname.month));
        new_path.append(std::to_string(fname.day));
        new_path.append(fname.only_name + path_to_file.extension().string());

        return new_path;
    } else if (labNumber == 9) {
        try {
            std::string filename = path_to_file.filename().string();
            std::string stem = path_to_file.stem().string();
            std::string extension = path_to_file.extension().string();

            std::size_t first_underscore = filename.find('_');
            std::size_t second_underscore = filename.find('_', first_underscore + 1);
            std::size_t third_underscore = filename.find('_', second_underscore + 1);

            if (first_underscore == std::string::npos || second_underscore == std::string::npos ||
                third_underscore == std::string::npos) {
                throw std::invalid_argument("Invalid filename. File path: " + path_to_file.string() + "!");
            }

            std::string year = stem.substr(0, first_underscore);
            std::string month = stem.substr(first_underscore + 1, second_underscore - first_underscore - 1);
            std::string day = stem.substr(second_underscore + 1, third_underscore - second_underscore - 1);
            std::string name = stem.substr(third_underscore + 1);

            std::filesystem::path new_path = path_to_file.parent_path();
            new_path.append(year);
            new_path.append(month);
            new_path.append(day);
            new_path.append(name + extension);

            return new_path;

        } catch (std::exception &ex) {
            std::cerr << ex.what();
            exit(0);
        }
    } else {
        std::cout << "Invalid lab number.";
        exit(0);
    }
}

void MoveAndDelete(const std::filesystem::path& path_to_directory, const size_t& labNumber) {
    for (const auto& dir : std::filesystem::directory_iterator(path_to_directory)) {
        FileName fName(dir);
        fName.Parse();
        if (fName.IsRemoveRequired()) {
            std::filesystem::remove(fName.path_to_current_file);
        }
        if (std::filesystem::is_regular_file(dir)) {
            Move(dir.path(), labNumber);
        }
    }
}

void labChoose(int argc, char *argv[]) {
    size_t labNumber;
    std::cout << "Input the lab number: (1 - 10)" << "\n";
    std::cin >> labNumber;

    switch (labNumber) {
        case 1: {
            CheckArgumentsAmount(argc, labNumber);
            CheckInputPath(argv[1], labNumber);
            nlohmann::json object = parseFile(argv[1]);

            bool isJson = IsJsonCorrect(object);

            if (isJson) {
                std::cout << "Structure of JSON-file by path " << argv[1] << " is correct.";
            } else {
                std::cout << "Structure of JSON-file by path " << argv[1] << " is incorrect.";
            }
            break;
        }
        case 2: {
            CheckArgumentsAmount(argc, labNumber);
            CheckInputPath(argv[1], labNumber);
            nlohmann::json object = parseFile(argv[1]);

            ModifyJsonObject(object);
            MakeFile(object);
            break;
        }
        case 3: {
            CheckArgumentsAmount(argc, labNumber);
            CheckInputPath(argv[1], labNumber);
            std::tm date_time = GetRequiredDateTime();
            nlohmann::json date_time_json = TmToJson(date_time);
            std::cout << "Time in JSON: " << date_time_json.dump(4) << std::endl;
            writeToFile(argv[1], date_time_json);
            break;
        }
        case 4: {
            CheckArgumentsAmount(argc, labNumber);
            CheckInputPath(argv[1], labNumber);
            nlohmann::json jsonObject = GetFsObjectInfo(argv[1]);
            std::cout << jsonObject.dump(4) << std::endl;
            writeJsonToFile(argv[1], jsonObject);
            break;
        }
        case 5: {
            CheckArgumentsAmount(argc, labNumber);
            CheckInputPath(argv[1], labNumber);
            directory_content::Info dirInfo = directory_content::GetInfo(argv[1]);
            std::cout << "\n" << dirInfo << "\n\n";
            filesystem_object::Info filesInfo = filesystem_object::GetInfo(argv[1]);
            std::cout << filesInfo;
            break;
        }
        case 6: {
            CheckArgumentsAmount(argc, labNumber);
            CheckDirectoryPath(argv[1]);
            CheckDirectoryPath(argv[2]);
            std::set<std::string> filesSet = GetFilesContentFromDirectory(argv[2]);
            setInsert(filesSet, argv[1], argv[2]);
            break;
        }
        case 7: {
            CheckArgumentsAmount(argc, labNumber);
            CheckDirectoryPath(argv[1]);
            CheckDirectoryPath(argv[2]);
            FilesStorage filesStorage(argv[2]);
            filesStorage.InitStorage();
            filesStorage.CopyFilesFromDirectory(argv[1], argv[2]);
            break;
        }
        case 8: {
            CheckArgumentsAmount(argc, labNumber);
            CheckDirectoryPath(argv[1]);
            RemoveDuplicatesFromDirectory(argv[1]);
        }
        case 9: {
            CheckArgumentsAmount(argc, labNumber);
            CheckDirectoryPath(argv[1]);
            MoveForFiles(argv[1], labNumber);
        }
        case 10: {
            CheckArgumentsAmount(argc, labNumber);
            CheckDirectoryPath(argv[1]);
            MoveAndDelete(argv[1], labNumber);
            break;
        }
        default:
            std::cout << "Invalid lab number.";
            break;
    }
}