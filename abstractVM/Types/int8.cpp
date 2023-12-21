/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** int8
*/

#include "../Factory.hpp"
#include <stdexcept>

Int_8::Int_8(const std::string& value) {
    int32_t intValue = std::stoi(value);
    if (intValue < -128 || intValue > 127) {
        throw std::runtime_error("Value out of range for Int8");
    }
    value_ = static_cast<int8_t>(intValue);
}

std::string Int_8::toString() const {
    return std::to_string(value_);
}

eOperandType Int_8::getType() const {
    return eOperandType::Int8;
}

IOperand* Int_8::operator+(const IOperand& rhs) const {
    const Int_8* rhsInt8 = dynamic_cast<const Int_8*>(&rhs);
    int32_t rhsValue = rhsInt8 ? std::stoi(rhsInt8->toString()) : std::stoi(rhs.toString());

    int32_t tempResult = static_cast<int32_t>(value_) + rhsValue;

    if (tempResult < -128 || tempResult > 127)
        throw std::runtime_error("Arithmetic operation caused overflow or underflow");

    int8_t result = static_cast<int8_t>(tempResult);

    return new Int_8(std::to_string(result));
}

IOperand* Int_8::operator-(const IOperand& rhs) const {
    const Int_8* rhsInt8 = dynamic_cast<const Int_8*>(&rhs);
    int32_t rhsValue = rhsInt8 ? std::stoi(rhsInt8->toString()) : std::stoi(rhs.toString());

    int32_t tempResult = static_cast<int32_t>(value_) - rhsValue;

    if (tempResult < -128 || tempResult > 127)
        throw std::runtime_error("Arithmetic operation caused overflow or underflow");

    int8_t result = static_cast<int8_t>(tempResult);

    return new Int_8(std::to_string(result));
}

IOperand* Int_8::operator*(const IOperand& rhs) const {
    const Int_8* rhsInt8 = dynamic_cast<const Int_8*>(&rhs);
    int32_t rhsValue = rhsInt8 ? std::stoi(rhsInt8->toString()) : std::stoi(rhs.toString());

    int32_t tempResult = static_cast<int32_t>(value_) * rhsValue;

    if (tempResult < -128 || tempResult > 127)
        throw std::runtime_error("Arithmetic operation caused overflow or underflow");

    int8_t result = static_cast<int8_t>(tempResult);

    return new Int_8(std::to_string(result));
}

IOperand* Int_8::operator/(const IOperand& rhs) const {
    const Int_8* rhsInt8 = dynamic_cast<const Int_8*>(&rhs);
    int32_t rhsValue = rhsInt8 ? std::stoi(rhsInt8->toString()) : std::stoi(rhs.toString());

    if (rhsValue == 0)
        throw std::runtime_error("Division by zero");

    int8_t result = static_cast<int8_t>(value_ / rhsValue);

    return new Int_8(std::to_string(result));
}

IOperand* Int_8::operator%(const IOperand& rhs) const {
    const Int_8* rhsInt8 = dynamic_cast<const Int_8*>(&rhs);
    int32_t rhsValue = rhsInt8 ? std::stoi(rhsInt8->toString()) : std::stoi(rhs.toString());

    if (rhsValue == 0)
        throw std::runtime_error("Modulo division by zero");

    int8_t result = static_cast<int8_t>(value_ % rhsValue);

    return new Int_8(std::to_string(result));
}
