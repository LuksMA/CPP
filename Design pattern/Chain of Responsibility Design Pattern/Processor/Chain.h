#ifndef CHAIN_H
#define CHAIN_H

#include "Number.h"
#include <iostream>

using namespace std;

class Chain
{
    public:
        virtual void setNext(Chain* nextInChain) = 0;
        virtual void process(Number* request) = 0;
};

#endif // CHAIN_H
