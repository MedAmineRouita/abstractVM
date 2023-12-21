/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** Factory
*/

#include "Factory.hpp"

Factory::Factory()
{
}

Factory::~Factory()
{
}

IOperand* Factory::createOperand(eOperandType type, const std::string& value)
{
    switch (type)
    {
        case eOperandType::Int8:
            return createInt8(value);
        case eOperandType::Int16:
            return createInt16(value);
        case eOperandType::Int32:
            return createInt32(value);
        case eOperandType::Float:
            return createFloat(value);
        case eOperandType::Double:
            return createDouble(value);
        default:
            return nullptr;
    }
}

IOperand* Factory::createInt8(const std::string& value){
    return new Int_8(value); // Crée un nouvel objet Int8 avec la valeur
}

IOperand* Factory::createInt16(const std::string & value){
    return new Int_16(value); // Crée un nouvel objet Int16 avec la valeur
}

IOperand * Factory::createInt32(const std::string & value){
    return new Int_32(value); // Crée un nouvel objet Int32 avec la valeur
}

IOperand* Factory::createFloat(const std::string& value){
    return new Float_(value); // Crée un nouvel objet Float avec la valeur
}

IOperand *Factory::createDouble(const std::string & value){
    return new Double_(value);
}
