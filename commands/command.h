#ifndef COMMAND_H
#define COMMAND_H

template<typename T>
class Command
{
public:
    virtual ~Command() = default;

    virtual void execute(T& t) = 0;
};

#endif // COMMAND_H
