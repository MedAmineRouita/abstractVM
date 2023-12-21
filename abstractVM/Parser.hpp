/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** Parser
*/

#include <fstream>
#include <regex>
#include <stdexcept>
#include <string>
#include <sstream>
#include <unordered_map>
#include "IOperand.hpp"
#include "handleINT.hpp"


#pragma once

class Parser {
public:
    static void openFile(const std::string& filename);
    static std::string GetFileExtension(const std::string& fileName);
    static void parseLine(const std::string& line);
    static void initializeValueHandlerFuncs();
    static std::unordered_map<std::string, std::function<void(const std::string&)>> valueHandlerFuncs;
private:
    static void parsePushInstruction(const std::vector<std::string>& tokens);
    static std::string extractValueFromType(const std::string& valueType);
    static void handleValue(const std::string& valueType, const std::string& value);
};
