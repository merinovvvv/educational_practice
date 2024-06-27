#include <iostream>
#include <stdexcept>
#include "json.hpp"
#include "labs.h"

int main(int argc, char *argv[]) {

    //    lab01:
//    CheckArgumentsAmount(argc);
//    CheckInputPath(argv[1]);
//    nlohmann::json object = parseFile(argv[1]);
//
//    bool isJson = IsJsonCorrect(object);
//
//    if (isJson) {
//        std::cout << "Structure of JSON-file by path " << argv[1] << " is correct.";
//    } else {
//        std::cout << "Structure of JSON-file by path " << argv[1] <<  " is incorrect.";
//    }

      //lab02:
//    CheckArgumentsAmount(argc);
//    CheckInputPath(argv[1]);
//    nlohmann::json object = parseFile(argv[1]);
//
//    ModifyJsonObject(object);
//    MakeFile(object);

    //lab03:
//    CheckArgumentsAmount(argc);
//    CheckInputPath(argv[1]);
//    std::tm date_time = GetRequiredDateTime();
//    nlohmann::json date_time_json = TmToJson(date_time);
//    std::cout << "Time in JSON: " << date_time_json.dump(4) << std::endl;
//    writeToFile(argv[1], date_time_json);

//    //lab04:
//    CheckArgumentsAmount(argc);
//    CheckInputPath(argv[1]);
//    nlohmann::json jsonObject = GetFsObjectInfo(argv[1]);
//    std::cout << jsonObject.dump(4) << std::endl;
//    writeJsonToFile(argv[1], jsonObject);

    //lab05:
//    CheckArgumentsAmount(argc);
//    CheckInputPath(argv[1]);
//    directory_content::Info dirInfo = directory_content::GetInfo(argv[1]);
//    std::cout << "\n" << dirInfo << "\n\n";
//    filesystem_object::Info filesInfo = filesystem_object::GetInfo(argv[1]);
//    std::cout << filesInfo;

    //lab06:
//    CheckArgumentsAmount(argc);
//    CheckDirectoryPath(argv[1]);
//    CheckDirectoryPath(argv[2]);
//    std::set<std::string> filesSet = GetFilesContentFromDirectory(argv[2]);
//    setInsert (filesSet, argv[1], argv[2]);

    //lab07:
    CheckArgumentsAmount(argc);
    CheckDirectoryPath(argv[1]);
    CheckDirectoryPath(argv[2]);
    FilesStorage filesStorage(argv[2]);
    filesStorage.InitStorage();
    filesStorage.CopyFilesFromDirectory(argv[1], argv[2]);

    return 0;
}
