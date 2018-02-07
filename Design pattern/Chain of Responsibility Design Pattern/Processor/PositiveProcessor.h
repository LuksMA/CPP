#ifndef POSITIVEPROCESSOR_H
#define POSITIVEPROCESSOR_H

#include "Chain.h"

class PositiveProcessor : public Chain
{
    public:
        void setNext(Chain* c);
        void process(Number* request);

    private:
        Chain* nextInChain;
};

#endif // POSITIVEPROCESSOR_H
