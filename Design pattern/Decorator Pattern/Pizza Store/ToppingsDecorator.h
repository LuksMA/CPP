#ifndef TOPPINGSDECORATOR_H
#define TOPPINGSDECORATOR_H

#include "Pizza.h"

class ToppingsDecorator : public Pizza
{
    public:
        ToppingsDecorator(Pizza *pizza);
        virtual ~ToppingsDecorator();
        string getDescription(){return "";};

    protected:
        Pizza* pizza;
};

#endif // TOPPINGSDECORATOR_H
