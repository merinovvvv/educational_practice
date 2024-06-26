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
//    std::cout << "Current Time in JSON: " << date_time_json.dump(4) << std::endl;
//    writeToFile(argv[1], date_time_json);

    //lab04:
    CheckArgumentsAmount(argc);
    CheckInputPath(argv[1]);
    nlohmann::json jsonObject = GetFsObjectInfo(argv[1]);
    std::cout << jsonObject.dump(4) << std::endl;
    writeJsonToFile(argv[1], jsonObject);

    return 0;
}
