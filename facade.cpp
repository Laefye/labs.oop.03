#include "facade.h"
#include "validator.h"
#include "translator.h"
#include "calculator.h"

std::string Facade::calculate(const std::string& expression) {
    Validator validator(expression);
    validator.validate();
    Translator translator(expression);
    std::string rpn = translator.translate();
    Calculator calculator(rpn);
    return calculator.calculate();
}
