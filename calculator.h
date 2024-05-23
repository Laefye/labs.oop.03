#pragma once
#include <vector>
#include <string>
#include "operators/operatorcreator.h"
#include "contstants.h"

class Calculator {
private:
    std::string expression;

    const std::string operators = OPERATORS;
    void split(std::vector<std::string>& parts);
    double toDouble(std::string str);
    std::string toString(double value);
public:
    Calculator(const std::string& expression);

    std::string calculate();
};
