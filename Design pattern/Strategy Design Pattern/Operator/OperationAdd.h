#ifndef OPERATIONADD_H
#define OPERATIONADD_H

#include "Strategy.h"

class OperationAdd : public Strategy
{
    public:
        int doOperation(int num1, int num2);
};

#endif // OPERATIONADD_H
