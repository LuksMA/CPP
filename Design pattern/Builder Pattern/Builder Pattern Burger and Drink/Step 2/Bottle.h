#ifndef BOTTLE_H
#define BOTTLE_H

#include "Packing.h"

class Bottle: public Packing
{
    public:
        Bottle();
        ~Bottle();

        string pack(){ return "Bottle";}
};

#endif // BOTTLE_H
