/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** handleINT
*/

#include "handleINT.hpp"
#include <iostream>
#include "Factory.hpp"
#include "Performs.hpp"

void Core::handleInt8Value(const std::string& value) {
    double intValue = std::stod(value);

    if (intValue < -128 || intValue > 127) {
        std::cerr << "Error: Integer value out of range for int8." << std::endl;
        exit(84);
    }

    IOperand* operand = Factory::createOperand(eOperandType::Int8, std::to_string(intValue));
    Performs::valueStack.push(operand);
    // std::cout << "Pushing int8 value: " << intValue << std::endl;
}

void Core::handleInt16Value(const std::string& value) {
    double intValue = std::stod(value);

    if (intValue < -32768 || intValue > 32767) {
        std::cerr << "Error: Integer value out of range for int16." << std::endl;
        exit(84);
    }

    IOperand* operand = Factory::createOperand(eOperandType::Int16, std::to_string(intValue));
    Performs::valueStack.push(operand);
    // std::cout << "Pushing int16 value: " << intValue << std::endl;
}

void Core::handleInt32Value(const std::string& value) {
    double intValue = std::stod(value);

    if (intValue < -2147483648 || intValue > 2147483647) {
        std::cerr << "Error: Integer value out of range for int32." << std::endl;
        exit(84);
    }

    IOperand* operand = Factory::createOperand(eOperandType::Int32, std::to_string(intValue));
    Performs::valueStack.push(operand);
    // std::cout << "Pushing int32 value: " << intValue << std::endl;
}

void Core::handleFloatValue(const std::string& value) {
    float floatValue = std::stof(value);
    IOperand* operand = Factory::createOperand(eOperandType::Float, std::to_string(floatValue));
    Performs::valueStack.push(operand);
    // std::cout << "Pushing float value: " << floatValue << std::endl;
}

void Core::handleDoubleValue(const std::string& value) {
    double doubleValue = std::stod(value);
    IOperand* operand = Factory::createOperand(eOperandType::Double, std::to_string(doubleValue));
    Performs::valueStack.push(operand);
    // std::cout << "Pushing double value: " << doubleValue << std::endl;
}

