/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** instructionHandler
*/

#ifndef INSTRUCTIONHANDLER_HPP
#define INSTRUCTIONHANDLER_HPP

#include <unordered_map>
#include <functional>
#include "Performs.hpp"

class InstructionHandler {
public:
    InstructionHandler();
    void executeInstruction(const std::string& instruction);
private:
    std::unordered_map<std::string, std::function<void()>> instructionMap;
};

#endif  // INSTRUCTIONHANDLER_HPP