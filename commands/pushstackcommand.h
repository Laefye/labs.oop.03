#ifndef PUSHSTACKCOMMAND_H
#define PUSHSTACKCOMMAND_H
#include "command.h"

class Calculator;

class PushStackCommand : public Command<Calculator>
{
private:
    double number;
public:
    PushStackCommand(double number);

    void execute(Calculator& calculator) override;
};

#endif // PUSHSTACKCOMMAND_H
