//
// Created by merin on 6/25/2024.
//

#include <stdexcept>
#include "json.hpp"

#ifndef CPP_LABS_LABS_H
#define CPP_LABS_LABS_H


void CheckArgumentsAmount (int arguments_amount);
void CheckInputPath (const std::filesystem::path& path_to_filesystem_object);
bool IsJsonCorrect(const nlohmann::json& json);
nlohmann::json parseFile(const std::filesystem::path& path_to_filesystem_object);
void ModifyJsonObject(nlohmann::json& json_object);
void MakeFile(nlohmann::json& json_object);

#endif //CPP_LABS_LABS_H