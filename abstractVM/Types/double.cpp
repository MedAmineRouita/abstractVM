/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** double
*/

#include "../Factory.hpp"
#include <stdexcept>
#include <iomanip>

Double_::Double_(const std::string& value) {
    value_ = std::stod(value);
}

std::string Double_::toString() const {
    std::stringstream ss;
    ss << std::defaultfloat << std::setprecision(15) << value_;
    return ss.str();
}

eOperandType Double_::getType() const {
    return eOperandType::Double;
}

IOperand* Double_::operator+(const IOperand& rhs) const {
    const Double_* rhsDouble = dynamic_cast<const Double_*>(&rhs);
    double rhsValue = rhsDouble ? std::stod(rhsDouble->toString()) : std::stod(rhs.toString());

    double result = value_ + rhsValue;

    return new Double_(std::to_string(result));
}

IOperand* Double_::operator-(const IOperand& rhs) const {
    const Double_* rhsDouble = dynamic_cast<const Double_*>(&rhs);
    double rhsValue = rhsDouble ? std::stod(rhsDouble->toString()) : std::stod(rhs.toString());

    double result = value_ - rhsValue;

    return new Double_(std::to_string(result));
}

IOperand* Double_::operator*(const IOperand& rhs) const {
    const Double_* rhsDouble = dynamic_cast<const Double_*>(&rhs);
    double rhsValue = rhsDouble ? std::stod(rhsDouble->toString()) : std::stod(rhs.toString());

    double result = value_ * rhsValue;

    return new Double_(std::to_string(result));
}

IOperand* Double_::operator/(const IOperand& rhs) const {
    const Double_* rhsDouble = dynamic_cast<const Double_*>(&rhs);
    double rhsValue = rhsDouble ? std::stod(rhsDouble->toString()) : std::stod(rhs.toString());

    if (rhsValue == 0.0)
        throw std::runtime_error("Division by zero");

    double result = value_ / rhsValue;

    return new Double_(std::to_string(result));
}

IOperand* Double_::operator%(const IOperand& /*rhs*/) const {
    throw std::runtime_error("Modulo operation not supported for double");
}


