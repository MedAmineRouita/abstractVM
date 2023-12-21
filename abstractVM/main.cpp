/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** main
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


int main(int argc, char** argv) {
    if (argc > 2) {
        std::cerr << "Wrong Arguments\n";
        return(84);
    }

    if (argc == 2) {
        std::string file = argv[1];
        Parser::openFile(file);
    }

    std::string command;
    while (true) {
        std::getline(std::cin, command);
        Parser::parseLine(command);
    }
    return 0;
}