#pragma once
#include "exception"

class UnknownOperatorException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Unknown operator";
    }
};
