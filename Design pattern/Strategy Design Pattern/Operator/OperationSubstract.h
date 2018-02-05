#ifndef OPERATIONSUBSTRACT_H
#define OPERATIONSUBSTRACT_H

#include "Strategy.h"
class OperationSubstract : public Strategy
{
    public:
        int doOperation(int num1, int num2);
};

#endif // OPERATIONSUBSTRACT_H
