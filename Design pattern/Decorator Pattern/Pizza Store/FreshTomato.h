#ifndef FRESHTOMATO_H
#define FRESHTOMATO_H

#include "ToppingsDecorator.h"
class FreshTomato: public ToppingsDecorator
{
    public:
        FreshTomato(Pizza* pizza):ToppingsDecorator(pizza){};
        virtual ~FreshTomato();
        string getDescription();
        int getCost();
};

#endif // FRESHTOMATO_H
