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

//  lab02:
    CheckArgumentsAmount(argc);
    CheckInputPath(argv[1]);
    nlohmann::json object = parseFile(argv[1]);

    ModifyJsonObject(object);
    MakeFile(object);

    return 0;
}
