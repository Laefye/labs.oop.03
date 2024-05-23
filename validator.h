#pragma once
#include <string>
#include "exceptions/invalidexpressionexception.h"
#include "contstants.h"


class Validator {
private:
    const std::string digits = DIGITS;
    const char point = POINT;
    const std::string operators = OPERATORS; 
    const std::string brackets = BRACKETS;

    std::string expression;

    bool hasCharacterInNumber(std::size_t begin, char character);
public:
    Validator(const std::string& expression);

    void validate();
};
