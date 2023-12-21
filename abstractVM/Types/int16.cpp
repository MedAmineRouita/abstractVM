/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** int16
*/

#include "../Factory.hpp"
#include <stdexcept>

IOperand* Int_16::operator+(const IOperand& rhs) const {
    const Int_16* rhsInt16 = dynamic_cast<const Int_16*>(&rhs);
    int32_t rhsValue = rhsInt16 ? std::stoi(rhsInt16->toString()) : std::stoi(rhs.toString());

    int32_t tempResult = static_cast<int32_t>(value_) + rhsValue;

    if (tempResult < -32768 || tempResult > 32767)
        throw std::runtime_error("Arithmetic operation caused overflow or underflow");

    int16_t result = static_cast<int16_t>(tempResult);

    return new Int_16(std::to_string(result));
}

IOperand* Int_16::operator-(const IOperand& rhs) const {
    const Int_16* rhsInt16 = dynamic_cast<const Int_16*>(&rhs);
    int32_t rhsValue = rhsInt16 ? std::stoi(rhsInt16->toString()) : std::stoi(rhs.toString());

    int32_t tempResult = static_cast<int32_t>(value_) - rhsValue;

    if (tempResult < -32768 || tempResult > 32767)
        throw std::runtime_error("Arithmetic operation caused overflow or underflow");

    int16_t result = static_cast<int16_t>(tempResult);

    return new Int_16(std::to_string(result));
}

IOperand* Int_16::operator*(const IOperand& rhs) const {
    const Int_16* rhsInt16 = dynamic_cast<const Int_16*>(&rhs);
    int32_t rhsValue = rhsInt16 ? std::stoi(rhsInt16->toString()) : std::stoi(rhs.toString());

    int32_t tempResult = static_cast<int32_t>(value_) * rhsValue;

    if (tempResult < -32768 || tempResult > 32767)
        throw std::runtime_error("Arithmetic operation caused overflow or underflow");

    int16_t result = static_cast<int16_t>(tempResult);

    return new Int_16(std::to_string(result));
}

IOperand* Int_16::operator/(const IOperand& rhs) const {
    const Int_16* rhsInt16 = dynamic_cast<const Int_16*>(&rhs);
    int32_t rhsValue = rhsInt16 ? std::stoi(rhsInt16->toString()) : std::stoi(rhs.toString());

    if (rhsValue == 0)
        throw std::runtime_error("Division by zero");

    int16_t result = static_cast<int16_t>(value_ / rhsValue);

    return new Int_16(std::to_string(result));
}

IOperand* Int_16::operator%(const IOperand& rhs) const {
    const Int_16* rhsInt16 = dynamic_cast<const Int_16*>(&rhs);
    int32_t rhsValue = rhsInt16 ? std::stoi(rhsInt16->toString()) : std::stoi(rhs.toString());

    if (rhsValue == 0)
        throw std::runtime_error("Modulo division by zero");

    int16_t result = static_cast<int16_t>(value_ % rhsValue);

    return new Int_16(std::to_string(result));
}



