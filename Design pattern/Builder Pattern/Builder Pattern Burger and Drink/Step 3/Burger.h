#ifndef BURGER_H
#define BURGER_H

#include "Item.h"
#include "Wrapper.h"

class Burger
{
    public:
        Burger();
        ~Burger();

        Packing* packing();
        float price();
};

#endif // BURGER_H
