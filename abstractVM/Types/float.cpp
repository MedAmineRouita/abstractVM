/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** float
*/

#include "../Factory.hpp"
#include <iomanip>

Int_16::Int_16(const std::string& value) {
    int32_t intValue = std::stoi(value);
    if (intValue < -32768 || intValue > 32767) {
        throw std::runtime_error("Value out of range for Int16");
    }
    value_ = static_cast<int16_t>(intValue);
}

std::string Int_16::toString() const {
    return std::to_string(value_);
}

eOperandType Int_16::getType() const {
    return eOperandType::Int16;
}


Float_::Float_(const std::string& value) {
    try {
        value_ = std::stof(value);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Bad input: std::invalid_argument thrown");
    } catch (const std::out_of_range& e) {
        throw std::out_of_range("Float is out of range");
    }
}

Float_::~Float_() {
}

std::string Float_::toString() const {
    std::stringstream ss;
    ss << std::defaultfloat << std::setprecision(7) << value_;
    return ss.str();
}

eOperandType Float_::getType() const {
    return eOperandType::Float;
}

IOperand* Float_::operator+(const IOperand& rhs) const {
    const Float_* rhsFloat = dynamic_cast<const Float_*>(&rhs);
    float rhsValue = rhsFloat ? std::stof(rhsFloat->toString()) : std::stof(rhs.toString());

    float result = value_ + rhsValue;

    return new Float_(std::to_string(result));
}

IOperand* Float_::operator-(const IOperand& rhs) const {
    const Float_* rhsFloat = dynamic_cast<const Float_*>(&rhs);
    float rhsValue = rhsFloat ? std::stof(rhsFloat->toString()) : std::stof(rhs.toString());

    float result = value_ - rhsValue;

    return new Float_(std::to_string(result));
}

IOperand* Float_::operator*(const IOperand& rhs) const {
    const Float_* rhsFloat = dynamic_cast<const Float_*>(&rhs);
    float rhsValue = rhsFloat ? std::stof(rhsFloat->toString()) : std::stof(rhs.toString());

    float result = value_ * rhsValue;

    return new Float_(std::to_string(result));
}

IOperand* Float_::operator/(const IOperand& rhs) const {
    const Float_* rhsFloat = dynamic_cast<const Float_*>(&rhs);
    float rhsValue = rhsFloat ? std::stof(rhsFloat->toString()) : std::stof(rhs.toString());

    if (rhsValue == 0)
        throw std::runtime_error("Division by zero");

    float result = value_ / rhsValue;

    return new Float_(std::to_string(result));
}

IOperand* Float_::operator%(const IOperand& /*rhs*/) const {
    throw std::runtime_error("Modulo operation not supported for float");
}
