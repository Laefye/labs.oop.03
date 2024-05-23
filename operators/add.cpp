#include "add.h"

double Add::execute(double left, double right) {
    return left + right;
}

int Add::priority() {
    return 1;
}
