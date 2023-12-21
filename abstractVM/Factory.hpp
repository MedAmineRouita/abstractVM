/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
** File description:
** Factory
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "IOperand.hpp"

#pragma once

class Factory {
public:
    Factory();
    ~Factory();
    static IOperand* createOperand(eOperandType type, const std::string& value);
    static IOperand* createInt8(const std::string &value);
    static IOperand* createInt16(const std::string &value);
    static IOperand* createInt32(const std::string &value);
    static IOperand* createFloat(const std::string &value);
    static IOperand* createDouble(const std::string &value);

private:
};

class Int_8 : public IOperand {
public:
    Int_8(const std::string& value);

    std::string toString() const override;
    eOperandType getType() const override;
    IOperand* operator+(const IOperand& rhs) const override;
    IOperand* operator-(const IOperand& rhs) const override;
    IOperand* operator*(const IOperand& rhs) const override;
    IOperand* operator/(const IOperand& rhs) const override;
    IOperand* operator%(const IOperand& rhs) const override;

private:
    int8_t value_;
};

class Int_16 : public IOperand {
public:
    Int_16(const std::string& value);

    virtual std::string toString() const override;
    virtual eOperandType getType() const override;
    virtual IOperand* operator+(const IOperand& rhs) const override;
    virtual IOperand* operator-(const IOperand& rhs) const override;
    virtual IOperand* operator*(const IOperand& rhs) const override;
    virtual IOperand* operator/(const IOperand& rhs) const override;
    virtual IOperand* operator%(const IOperand& rhs) const override;
private:
    int16_t value_;
};

class Int_32 : public IOperand {
public:
    Int_32(const std::string& value);

    virtual std::string toString() const override;
    virtual eOperandType getType() const override;
    virtual IOperand* operator+(const IOperand& rhs) const override;
    virtual IOperand* operator-(const IOperand& rhs) const override;
    virtual IOperand* operator*(const IOperand& rhs) const override;
    virtual IOperand* operator/(const IOperand& rhs) const override;
    virtual IOperand* operator%(const IOperand& rhs) const override;
private:
    int32_t value_;
};

class Float_ : public IOperand {
public:
    Float_(const std::string& value);
    ~Float_();
    virtual std::string toString() const override;
    virtual eOperandType getType() const override;
    virtual IOperand* operator+(const IOperand& rhs) const override;
    virtual IOperand* operator-(const IOperand& rhs) const override;
    virtual IOperand* operator*(const IOperand& rhs) const override;
    virtual IOperand* operator/(const IOperand& rhs) const override;
    virtual IOperand* operator%(const IOperand& rhs) const override;
private:
    float value_;
};

class Double_ : public IOperand {
public:
    Double_(const std::string& value);

    virtual std::string toString() const override;
    virtual eOperandType getType() const override;
    virtual IOperand* operator+(const IOperand& rhs) const override;
    virtual IOperand* operator-(const IOperand& rhs) const override;
    virtual IOperand* operator*(const IOperand& rhs) const override;
    virtual IOperand* operator/(const IOperand& rhs) const override;
    virtual IOperand* operator%(const IOperand& rhs) const override;
private:
    double value_;
};
