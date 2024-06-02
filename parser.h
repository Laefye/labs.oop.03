#pragma once
#include <vector>
#include <string>
#include "operators/operatorcreator.h"
#include "contstants.h"
#include "calculator.h"
#include "commands/command.h"

class Parser {
private:
    std::string expression;

    const std::string operators = OPERATORS;
    void split(std::vector<std::string>& parts);
public:
    Parser(const std::string& expression);

    static double toDouble(std::string str);
    static std::string toString(double value);

    void parse(std::vector<Command<Calculator>*>& commands);
};
