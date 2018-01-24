#ifndef VEGBURGER_H
#define VEGBURGER_H

#include "Burger.h"

class VegBurger: public Burger
{
    public:
        VegBurger();
        ~VegBurger();

        float price();
        string name();
};

#endif // VEGBURGER_H
