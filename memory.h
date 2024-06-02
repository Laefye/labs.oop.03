#ifndef MEMORY_H
#define MEMORY_H
#include <string>


class Memory
{
private:
    double value = 0;
    double cachedMemory = 0;
public:
    void save(double value);
    void save();
    double get();
    void reset();
};

#endif // MEMORY_H
