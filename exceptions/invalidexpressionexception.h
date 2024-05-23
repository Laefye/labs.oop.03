#pragma once
#include "exception"

class InvalidExpressionException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid expression";
    }
};
