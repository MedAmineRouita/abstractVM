/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** handleInt
*/

#pragma once

#include <fstream>
#include <regex>
#include <stdexcept>
#include <string>
#include <sstream>

#pragma once

class Core {
    public:
        static void handleInt8Value(const std::string& value);
        static void handleInt16Value(const std::string& value);
        static void handleInt32Value(const std::string& value);
        static void handleFloatValue(const std::string& value);
        static void handleDoubleValue(const std::string& value);
    protected:
    private:
};