#ifndef ITEM_H
#define ITEM_H

#include "Packing.h"

class Item
{
    public:
        Item();
        ~Item();

        virtual string name()=0;
        virtual Packing* packing()=0;
        virtual float price() = 0;
};

#endif // ITEM_H
