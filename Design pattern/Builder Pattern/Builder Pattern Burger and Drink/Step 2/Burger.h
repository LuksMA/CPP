#ifndef BURGER_H
#define BURGER_H

#include "Item.h"
#include "Wrapper.h"

class Burger : public Item
{
    public:
        Burger();
        ~Burger();

        Packing* packing();
        virtual float price()=0;
};

#endif // BURGER_H
