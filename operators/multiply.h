#include "operator.h"

class Multiply : public Operator {
public:
    double execute(double left, double right) override;
    int priority() override;
    Operator* clone() override;
};
