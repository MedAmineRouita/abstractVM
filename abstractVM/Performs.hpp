/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** Performs
*/

#pragma once

#include <stack>
#include "Factory.hpp"

class Performs {
    public:
        static void performAdd();
        static void performSub();
        static void performMul();
        static void performDump();
        static void performDiv();
        static void performClear();
        static void performSwap();
        static void performPop();
        static void performMod();
        static void performDup();


        static std::stack<IOperand *> valueStack;
    protected:
    private:
};

