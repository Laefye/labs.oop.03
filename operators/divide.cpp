#include "divide.h"

double Divide::execute(double left, double right) {
    return left / right;
}

int Divide::priority() {
    return 2;
}
