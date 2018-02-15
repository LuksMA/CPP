#ifndef STACKITER_H
#define STACKITER_H

#include "Stack.h"

class StackIter
{
public:
    StackIter(const Stack &s): stk(s){  index = 0;}
    void operator++();
    bool operator()();
    int operator *();

private:
    const Stack &stk;
    int index;
};



#endif // STACKITER_H
