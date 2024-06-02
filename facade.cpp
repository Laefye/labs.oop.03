#include "facade.h"
#include "validator.h"
#include "translator.h"
#include "parser.h"

void Facade::calculate() {
    if (!commandCalculator) {
        expression = Parser::toString(calculateCurrentExpression());
        this->needToCache = true;
    }
}

double Facade::calculateCurrentExpression() {
    Validator validator(expression);
    validator.validate();
    Translator translator(expression);
    std::string rpn = translator.translate();
    std::vector<Command<Calculator>*> commands;
    Parser parser(rpn);
    parser.parse(commands);
    Calculator calculator;
    for (Command<Calculator>* command : commands) {
        command->execute(calculator);
        delete command;
    }
    return calculator.top();
}

std::string Facade::getExpression() {
    return this->expression;
}

void Facade::setExpression(const std::string& expression) {
    this->needToCache = true;
    this->expression = expression;
}

void Facade::freeCommands() {
    currentCommand = 0;
    for (Command<Calculator>* command : commands) {
        delete command;
    }
    commands.clear();
    if (commandCalculator) {
        delete commandCalculator;
        commandCalculator = 0;
    }
}

void Facade::run() {
    Validator validator(expression);
    validator.validate();
    Translator translator(expression);
    std::string rpn = translator.translate();
    Parser parser(rpn);

    freeCommands();
    commandCalculator = new Calculator();
    parser.parse(commands);
}

void Facade::stop() {
    freeCommands();
}

void Facade::next() {
    if (this->currentCommand < commands.size()) {
        commands[this->currentCommand]->execute(*commandCalculator);
        expression = Parser::toString(commandCalculator->top());
    }
    this->currentCommand++;
    if (this->currentCommand >= commands.size()) {
        freeCommands();
    }
}

Facade::~Facade() {
    freeCommands();
}

bool Facade::isCommands() {
    return commandCalculator;
}

void Facade::mc() {
    memory.reset();
}
void Facade::mr() {
    if (!isCommands()) {
        expression = Parser::toString(memory.get());
        needToCache = false;
    }
}
void Facade::mp() {
    if (needToCache) {
        memory.save(calculateCurrentExpression());
        needToCache = false;
    } else {
        memory.save();
    }

}
void Facade::mm() {
    if (needToCache) {
        memory.save(-calculateCurrentExpression());
        needToCache = false;
    } else {
        memory.save();
    }
}
