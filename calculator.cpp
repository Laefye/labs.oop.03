#include "calculator.h"
#include "exceptions/unknownoperatorexception.h"
#include <locale>

Calculator::Calculator(const std::string& expression) {
    this->expression = expression;
}

double Calculator::toDouble(std::string str) {
    char point = std::use_facet<std::numpunct<char>>(std::locale("")).decimal_point();
    if (str.find('.') != std::string::npos) {
        str[str.find('.')] = point;
    }
    return std::stod(str);
}

std::string Calculator::toString(double value) {
    std::string result = std::to_string(value);
    char point = std::use_facet<std::numpunct<char>>(std::locale("")).decimal_point();
    if (result.find(point) != std::string::npos) {
        result[result.find(point)] = '.';
    }
    return result;
}

void Calculator::split(std::vector<std::string>& parts) {
    std::string expression = this->expression;
    size_t pos = 0;
    while ((pos = expression.find(' ')) != std::string::npos) {
        parts.push_back(expression.substr(0, pos));
        expression.erase(0, pos + 1);
    }
    parts.push_back(expression);
}

std::string Calculator::calculate() {
    OperatorCreator operatorCreator;
    std::vector<std::string> parts;
    split(parts);
    std::vector<double> stack;
    for (std::string& part : parts) {
        if (operators.find(part) != std::string::npos) {
            Operator* op = operatorCreator.create(part[0]);
            double value = op->execute(*(++stack.rbegin()), *stack.rbegin());
            delete op;
            stack.erase(stack.begin() + (stack.size() - 1));
            stack.erase(stack.begin() + (stack.size() - 1));
            stack.push_back(value);
        } else {
            stack.push_back(toDouble(part));
        }
    }
    return toString(stack.empty() ? 0 : stack[0]);
}
