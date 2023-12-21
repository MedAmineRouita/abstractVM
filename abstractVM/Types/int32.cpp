/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** int32
*/

#include "../Factory.hpp"
#include <stdexcept>

Int_32::Int_32(const std::string& value) {
    int32_t intValue = std::stoi(value);
    value_ = intValue;
}

std::string Int_32::toString() const {
    return std::to_string(value_);
}

eOperandType Int_32::getType() const {
    return eOperandType::Int32;
}

IOperand* Int_32::operator+(const IOperand& rhs) const {
    const Int_32* rhsInt32 = dynamic_cast<const Int_32*>(&rhs);
    int32_t rhsValue = rhsInt32 ? std::stoi(rhsInt32->toString()) : std::stoi(rhs.toString());

    int32_t result = value_ + rhsValue;

    return new Int_32(std::to_string(result));
}

IOperand* Int_32::operator-(const IOperand& rhs) const {
    const Int_32* rhsInt32 = dynamic_cast<const Int_32*>(&rhs);
    int32_t rhsValue = rhsInt32 ? std::stoi(rhsInt32->toString()) : std::stoi(rhs.toString());

    int32_t result = value_ - rhsValue;

    return new Int_32(std::to_string(result));
}


IOperand* Int_32::operator*(const IOperand& rhs) const {
    const Int_32* rhsInt32 = dynamic_cast<const Int_32*>(&rhs);
    int32_t rhsValue = rhsInt32 ? std::stoi(rhsInt32->toString()) : std::stoi(rhs.toString());

    int32_t result = value_ * rhsValue;

    return new Int_32(std::to_string(result));
}

IOperand* Int_32::operator/(const IOperand& rhs) const {
    const Int_32* rhsInt32 = dynamic_cast<const Int_32*>(&rhs);
    int32_t rhsValue = rhsInt32 ? std::stoi(rhsInt32->toString()) : std::stoi(rhs.toString());

    if (rhsValue == 0)
        throw std::runtime_error("Division by zero");

    int32_t result = value_ / rhsValue;

    return new Int_32(std::to_string(result));
}

IOperand* Int_32::operator%(const IOperand& rhs) const {
    const Int_32* rhsInt32 = dynamic_cast<const Int_32*>(&rhs);
    int32_t rhsValue = rhsInt32 ? std::stoi(rhsInt32->toString()) : std::stoi(rhs.toString());

    if (rhsValue == 0)
        throw std::runtime_error("Modulo division by zero");

    int32_t result = value_ % rhsValue;

    return new Int_32(std::to_string(result));
}