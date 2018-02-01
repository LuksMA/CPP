#ifndef BARBEQUE_H
#define BARBEQUE_H

#include "ToppingsDecorator.h"
class Barbeque: public ToppingsDecorator
{
    public:
        Pizza* pizza;
//        Barbeque(Pizza* pizza);
        Barbeque(Pizza* pizza):ToppingsDecorator(pizza){}
        virtual ~Barbeque();
        string getDescription();
        int getCost();
};

#endif // BARBEQUE_H
