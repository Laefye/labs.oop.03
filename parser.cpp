#include "parser.h"
#include "exceptions/unknownoperatorexception.h"
#include <locale>
#include "commands/operatorcommand.h"
#include "commands/pushstackcommand.h"

Parser::Parser(const std::string& expression) {
    this->expression = expression;
}

double Parser::toDouble(std::string str) {
    char point = std::use_facet<std::numpunct<char>>(std::locale("")).decimal_point();
    if (str.find('.') != std::string::npos) {
        str[str.find('.')] = point;
    }
    return std::stod(str);
}

std::string Parser::toString(double value) {
    std::string result = std::to_string(value);
    char point = std::use_facet<std::numpunct<char>>(std::locale("")).decimal_point();
    if (result.find(point) != std::string::npos) {
        result[result.find(point)] = '.';
    }
    return result;
}

void Parser::split(std::vector<std::string>& parts) {
    std::string expression = this->expression;
    size_t pos = 0;
    while ((pos = expression.find(' ')) != std::string::npos) {
        parts.push_back(expression.substr(0, pos));
        expression.erase(0, pos + 1);
    }
    parts.push_back(expression);
}

void Parser::parse(std::vector<Command<Calculator>*>& commands) {
    if (this->expression.length() == 0) {
        commands.push_back(new PushStackCommand(0));
        return;
    }
    OperatorCreator operatorCreator;
    std::vector<std::string> parts;
    split(parts);
    for (std::string& part : parts) {
        if (operators.find(part) != std::string::npos) {
            Operator* op = operatorCreator.create(part[0]);
            commands.push_back(new OperatorCommand(op));
        } else {
            commands.push_back(new PushStackCommand(toDouble(part)));
        }
    }
}
