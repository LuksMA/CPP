#ifndef PEPSI_H
#define PEPSI_H

#include "ColdDrink.h"
class Pepsi : public ColdDrink
{
    public:
        Pepsi();
        ~Pepsi();

        float price();
        string name();
};

#endif // PEPSI_H
