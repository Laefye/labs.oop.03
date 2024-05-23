#include "minus.h"

double Minus::execute(double left, double right) {
    return left - right;
}

int Minus::priority() {
    return 1;
}
