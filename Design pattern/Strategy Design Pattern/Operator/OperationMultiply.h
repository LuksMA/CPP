#ifndef OPERATIONMULTIPLY_H
#define OPERATIONMULTIPLY_H

#include "Strategy.h"
class OperationMultiply : public Strategy
{
    public:
        int doOperation(int num1, int num2);
};

#endif // OPERATIONMULTIPLY_H
