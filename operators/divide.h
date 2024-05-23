#include "operator.h"

class Divide : public Operator {
public:
    double execute(double left, double right) override;
    int priority() override;
};
