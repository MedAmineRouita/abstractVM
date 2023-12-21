/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** Perfoms
*/

#include <fstream>
#include <regex>
#include <stdexcept>
#include <string>
#include <sstream>
#include "iostream"
#include  "Factory.hpp"
#include "Performs.hpp"

std::stack<IOperand*> Performs::valueStack;


void Performs::performDiv() {
    if (valueStack.size() < 2) {
        std::cerr << "Error: Insufficient operands for 'div' operation." << std::endl;
        exit(84);
    }

    IOperand *operand2 = valueStack.top();
    valueStack.pop();
    IOperand *operand1 = valueStack.top();
    valueStack.pop();

    if (operand2->toString() == "0") {
        std::cerr << "Error: Division by zero." << std::endl;
        exit(84);
    }

    IOperand *result = *operand1 / *operand2;
    valueStack.push(result);
}

void Performs::performAdd() {
    if (valueStack.size() < 2) {
        std::cerr << "Error: Insufficient operands for 'add' operation." << std::endl;
        exit(84);
    }

    IOperand *operand2 = valueStack.top();
    valueStack.pop();
    IOperand *operand1 = valueStack.top();
    valueStack.pop();

    IOperand *result = *operand1 + *operand2;
    valueStack.push(result);
}

void Performs::performSub() {
    if (valueStack.size() < 2) {
        std::cerr << "Error: Insufficient operands for 'sub' operation." << std::endl;
        exit(84);
    }

    IOperand *operand1 = valueStack.top();
    valueStack.pop();
    IOperand *operand2 = valueStack.top();
    valueStack.pop();

    IOperand *result = *operand2 - *operand1;
    valueStack.push(result);

    // std::cout << "Performing subtraction: " << operand1->toString() << " - " << operand2->toString() << " = " << result->toString() << std::endl;
}

void Performs::performMul() {
    if (valueStack.size() < 2) {
        std::cerr << "Error: Insufficient operands for 'mul' operation." << std::endl;
        exit(84);
    }

    IOperand *operand2 = valueStack.top();
    valueStack.pop();
    IOperand *operand1 = valueStack.top();
    valueStack.pop();

    IOperand *result = *operand1 * *operand2;
    valueStack.push(result);
}

void Performs::performDump() {
    std::stack<IOperand *> tempStack = valueStack;

    if (tempStack.empty()) {
        std::cerr << "The stack is empty." << std::endl;
        exit(84);
    }

    while (!tempStack.empty()) {
        std::cout << tempStack.top()->toString() << std::endl;
        tempStack.pop();
    }
}

void Performs::performClear() {
    if (valueStack.empty()) {
        std::cerr << "Error: Already empty stack." << std::endl;
    }
    while (!valueStack.empty()) {
        IOperand *operand = valueStack.top();
        delete operand;
        valueStack.pop();
    }
}

void Performs::performSwap() {
    if (valueStack.size() < 2) {
        std::cerr << "Error: Insufficient operands for 'swap' operation." << std::endl;
        exit(84);
    }

    IOperand *topOperand = valueStack.top();
    valueStack.pop();
    IOperand *secondOperand = valueStack.top();
    valueStack.pop();

    valueStack.push(topOperand);
    valueStack.push(secondOperand);
}

void Performs::performPop() {
    if (valueStack.size() == 0) {
        std::cerr << "Error: Cannot pop from an empty stack." << std::endl;
        exit(84);
    }

    IOperand *operand = valueStack.top();
    delete operand;
    valueStack.pop();
}

void Performs::performDup() {
    if (valueStack.empty()) {
        std::cerr << "Error: Cannot duplicate top value of an empty stack." << std::endl;
        exit(84);
    }

    IOperand* topOperand = valueStack.top();
    IOperand* operandCopy = Factory::createOperand(topOperand->getType(), topOperand->toString());
    valueStack.push(operandCopy);
}

void Performs::performMod() {
    if (valueStack.size() < 2) {
        std::cerr << "Error: Insufficient operands for 'mod' operation." << std::endl;
        exit(84);
    }

    IOperand *operand2 = valueStack.top();
    valueStack.pop();
    IOperand *operand1 = valueStack.top();
    valueStack.pop();

    if (operand2->toString() == "0") {
        std::cerr << "Error: Division by zero." << std::endl;
        exit(84);
    }

    IOperand *result = *operand1 % *operand2;
    valueStack.push(result);
} // std::cout << "Performing modulo: " << operand2->toString() << " % " << operand1->toString() << " = " << result->toString() << std::endl;



