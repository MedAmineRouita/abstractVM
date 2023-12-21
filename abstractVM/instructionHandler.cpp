/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** instructionHandler
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

#include "Parser.hpp"
#include "handleINT.hpp"
#include "Performs.hpp"
#include "instructionHandler.hpp"

InstructionHandler::InstructionHandler() {
    instructionMap["add"] = &Performs::performAdd;
    instructionMap["sub"] = &Performs::performSub;
    instructionMap["dump"] = &Performs::performDump;
    instructionMap["swap"] = &Performs::performSwap;
    instructionMap["div"] = &Performs::performDiv;
    instructionMap["clear"] = &Performs::performClear;
    instructionMap["exit"] = []() { exit(0); };
    instructionMap["mul"] = &Performs::performMul;
    instructionMap["pop"] = &Performs::performPop;
    instructionMap["dup"] = &Performs::performDup;
    instructionMap["mod"] = &Performs::performMod;
}

void InstructionHandler::executeInstruction(const std::string& instruction) {
    if (instructionMap.find(instruction) == instructionMap.end()) {
        std::cerr << "Error: Invalid instructions." << std::endl;
        exit(84);
    }
    instructionMap[instruction]();
}
