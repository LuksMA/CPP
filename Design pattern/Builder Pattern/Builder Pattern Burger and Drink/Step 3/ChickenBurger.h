#ifndef CHICKENBURGER_H
#define CHICKENBURGER_H

#include "Burger.h"

class ChickenBurger: public Burger
{
    public:
        ChickenBurger();
        ~ChickenBurger();

        float price();
        string name();
};

#endif // CHICKENBURGER_H
