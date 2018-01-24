#ifndef COLDDRINK_H
#define COLDDRINK_H

#include "Item.h"
#include "Bottle.h"

class ColdDrink
{
    public:
        ColdDrink();
        ~ColdDrink();

        Packing* packing();
        float price();

};

#endif // COLDDRINK_H
