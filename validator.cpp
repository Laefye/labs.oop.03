#include "validator.h"
#include  <iostream>

Validator::Validator(const std::string& expression) {
    this->expression = expression;
}

bool Validator::hasCharacterInNumber(std::size_t begin, char character) {
    for (std::size_t i = begin - 1; i >= 0 && i < expression.length() && operators.find(expression[i]) == std::string::npos && brackets.find(expression[i]) == std::string::npos; i--)
    {
        if (expression[i] == character) {
            return true;
        }
    }
    return false;
}

void Validator::validate() {
    int deep = 0;
    for (std::size_t i = 0; i < expression.length(); i++)
    {
        char character = expression[i];
        std::size_t pos;
        if ((pos = digits.find(character)) != std::string::npos) {
            continue;
        } else if ((pos = operators.find(character)) != std::string::npos) {
            if ((i == 0 || expression[i - 1] == '(') && expression[i] == '-') {
                continue;
            } if (i == 0 || operators.find(expression[i - 1]) != std::string::npos || i == expression.length() - 1 || expression[i - 1] == '(') {
                throw InvalidExpressionException();
            }
        } else if ((pos = brackets.find(character)) != std::string::npos) {
            if (i > 0 && pos == 0 && digits.find(expression[i - 1]) != std::string::npos) {
                throw InvalidExpressionException();
            } else if (i > 0 && pos == 1 && operators.find(expression[i - 1]) != std::string::npos) {
                throw InvalidExpressionException();
            }
            deep += pos == 0 ? 1 : -1;
        } else if (character == point) {
            if (i == 0 || operators.find(expression[i - 1]) != std::string::npos || brackets.find(expression[i - 1]) != std::string::npos || hasCharacterInNumber(i, point)) {
                throw InvalidExpressionException();
            }
        } else {
            throw InvalidExpressionException();
        }
    }
    if (deep) {
        throw InvalidExpressionException();
    }
}
