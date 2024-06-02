#include "pushstackcommand.h"
#include "../calculator.h"

PushStackCommand::PushStackCommand(double number)
{
    this->number = number;
}

void PushStackCommand::execute(Calculator& calculator) {
    calculator.pushStack(number);
}
