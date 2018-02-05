#include "Context.h"

Context::Context(Strategy* strategy)
{
    this->strategy = strategy;
}

int Context::executeStrategy(int num1, int num2){
    return strategy->doOperation(num1, num2);
}
