#ifndef COKE_H
#define COKE_H

#include "ColdDrink.h"
class Coke : public ColdDrink
{
    public:
        Coke();
        ~Coke();

        float price();
        string name();
};

#endif // COKE_H
