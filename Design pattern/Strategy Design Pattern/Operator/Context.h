#ifndef CONTEXT_H
#define CONTEXT_H

#include "Strategy.h"

class Context
{
    public:
        Context(Strategy* strategy);
        int executeStrategy(int num1, int num2);
    private:
        Strategy* strategy;
};

#endif // CONTEXT_H
