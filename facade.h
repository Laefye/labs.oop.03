#pragma once
#include <string>
#include <vector>
#include "commands/command.h"
#include "calculator.h"
#include "memory.h"

class Facade {
private:
    std::vector<Command<Calculator>*> commands;
    size_t currentCommand;
    Calculator* commandCalculator = 0;
    Memory memory;

    std::string expression;
    bool needToCache = false;

    void freeCommands();
    double calculateCurrentExpression();
public:
    void setExpression(const std::string& expression);
    std::string getExpression();
    void calculate();
    void run();
    bool isCommands();
    void next();
    void stop();
    void mc();
    void mr();
    void mp();
    void mm();
    ~Facade();
};
