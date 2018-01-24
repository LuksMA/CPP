#ifndef COLDDRINK_H
#define COLDDRINK_H

#include "Item.h"
#include "Bottle.h"

class ColdDrink: public Item
{
    public:
        ColdDrink();
        ~ColdDrink();

        Packing* packing();
        virtual float price()=0;

};

#endif // COLDDRINK_H
