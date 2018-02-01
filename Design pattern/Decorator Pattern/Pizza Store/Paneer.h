#ifndef PANEER_H
#define PANEER_H

#include "ToppingsDecorator.h"
class Paneer: public ToppingsDecorator
{
    public:
        Paneer(Pizza* pizza):ToppingsDecorator(pizza){};
        virtual ~Paneer();
        string getDescription();
        int getCost();
};

#endif // PANEER_H
