#ifndef ITEM_H
#define ITEM_H

#include "Packing.h"

class Item
{
    public:
        Item();
        ~Item();

        string name();
        Packing* packing();
        float price();
};

#endif // ITEM_H
