/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** IOperand
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

#pragma once

enum class eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

class IOperand
{
public :
virtual std::string toString () const = 0; // string that represents the
virtual eOperandType getType () const = 0; // returns the type of instance
virtual IOperand * operator +( const IOperand & rhs ) const = 0; // sum
virtual IOperand * operator -( const IOperand & rhs ) const = 0; // difference
virtual IOperand * operator *( const IOperand & rhs ) const = 0; // product
virtual IOperand * operator /( const IOperand & rhs ) const = 0; // quotient
virtual IOperand * operator %( const IOperand & rhs ) const = 0; // modulo
virtual ~IOperand () {}
};