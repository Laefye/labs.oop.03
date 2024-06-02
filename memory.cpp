#include "memory.h"

double Memory::get() {
    return value;
}

void Memory::reset() {
    value = 0;
    cachedMemory = 0;
}

void Memory::save(double value) {
    this->value += value;
    this->cachedMemory = value;
}

void Memory::save() {
    this->value += cachedMemory;
}
