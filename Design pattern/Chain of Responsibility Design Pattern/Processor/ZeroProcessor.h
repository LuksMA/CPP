#ifndef ZEROPROCESSOR_H
#define ZEROPROCESSOR_H

#include "Chain.h"

class ZeroProcessor : public Chain
{
    public:
        void setNext(Chain* c);
        void process(Number* request);

    private:
        Chain* nextInChain;
};

#endif // ZEROPROCESSOR_H
