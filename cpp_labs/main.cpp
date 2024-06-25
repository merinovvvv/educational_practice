#include <iostream>
#include <stdexcept>
#include "json.hpp"
#include "lab01.h"

int main(int argc, char *argv[]) {
    CheckArgumentsAmount(argc);
    CheckInputPath(argv[1]);
    nlohmann::json object = parseFile(argv[1]);
    bool isJson = IsJsonCorrect(object);

    if (isJson) {
        std::cout << "Structure of JSON-file by path " << argv[1] << " is correct.";
    } else {
        std::cout << "Structure of JSON-file by path " << argv[1] <<  " is incorrect.";
    }

    system("pause");
    
    return 0;
}
