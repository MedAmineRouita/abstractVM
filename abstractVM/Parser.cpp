/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** Parser
*/

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <ostream>
#include <cctype>
#include "instructionHandler.hpp"
#include "Parser.hpp"
#include "stack"
#include "Factory.hpp"
#include "handleINT.hpp"
#include "Performs.hpp"
#include <string>
#include <regex>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include <filesystem>

std::unordered_map<std::string, std::function<void(const std::string&)>> Parser::valueHandlerFuncs;

void Parser::initializeValueHandlerFuncs() {
    valueHandlerFuncs = {
        {"int8", [](const std::string& value) { Core::handleInt8Value(value); }},
        {"int16", [](const std::string& value) { Core::handleInt16Value(value); }},
        {"int32", [](const std::string& value) { Core::handleInt32Value(value); }},
        {"float", [](const std::string& value) { Core::handleFloatValue(value); }},
        {"double", [](const std::string& value) { Core::handleDoubleValue(value); }}
    };
}


void Parser::parseLine(const std::string& line) {
    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    if (tokens.empty()) {
        return;
    }

    std::string instruction = tokens[0];

    if (instruction == "push") {
        parsePushInstruction(tokens);
    } else {
        InstructionHandler instructionHandler;
        instructionHandler.executeInstruction(instruction);
    }
}

void Parser::parsePushInstruction(const std::vector<std::string>& tokens) {
    if (tokens.size() != 2) {
        std::cerr << "Error: Insufficient arguments for 'push' instruction." << std::endl;
        exit(84);
    }

    std::string valueType = tokens[1];
    std::string value = extractValueFromType(valueType);

    handleValue(valueType, value);
}

std::string Parser::extractValueFromType(const std::string& valueType) {
    std::regex valueRegex(R"(\((.*?)\))");
    std::smatch match;
    if (std::regex_search(valueType, match, valueRegex)) {
        std::string extractedValue = match[1];

        try {
            std::stod(extractedValue);
        } catch (std::invalid_argument& ia) {
            std::cerr << "Error: Invalid argument. Value must be a number." << std::endl;
            std::exit(84);
        } catch (std::out_of_range& oor) {
            std::cerr << "Error: Out of range. Value is too large for conversion." << std::endl;
            std::exit(84);
        }

        return extractedValue;
    }
    return "";
}


void Parser::handleValue(const std::string& valueType, const std::string& value) {
    std::string valueTypeName = valueType.substr(0, valueType.find('('));
    auto it = valueHandlerFuncs.find(valueTypeName);

    // std::cout << "valueTypeName: " << valueTypeName << std::endl;

    if (it == valueHandlerFuncs.end()) {
        std::cerr << "Error: Invalid value type." << std::endl;
        exit(84);
    }

    it->second(value);
}

std::string Parser::GetFileExtension(const std::string& fileName) {
    if (fileName.find_last_of(".") != std::string::npos) {
        return fileName.substr(fileName.find_last_of(".") + 1);
    }
    return "";
}

void Parser::openFile(const std::string& filename) {
    initializeValueHandlerFuncs();
    std::string extension = GetFileExtension(filename);
    std::string line;
    if (extension != "avm") {
        std::cerr << "Error: Invalid file extension. Expected '.avm'." << std::endl;
        exit(84);
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Can not open file: " << filename << std::endl;
        exit(84);
    }

    while (std::getline(file, line)) {
        size_t commentPos = line.find(';');
        if (commentPos != std::string::npos) {
            line = line.substr(0, commentPos);
        }
        if (!line.empty()) {
            parseLine(line);
        }
    }
    file.close();
}
