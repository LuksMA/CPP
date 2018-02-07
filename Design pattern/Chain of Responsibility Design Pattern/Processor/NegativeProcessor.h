#ifndef NEGATIVEPROCESSOR_H
#define NEGATIVEPROCESSOR_H

#include "Chain.h"

class NegativeProcessor : public Chain
{
    public:
        void setNext(Chain* c);
        void process(Number* request);

    private:
        Chain* nextInChain;
};

#endif // NEGATIVEPROCESSOR_H
