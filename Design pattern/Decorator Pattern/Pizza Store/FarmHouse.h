#ifndef FARMHOUSE_H
#define FARMHOUSE_H

#include "Pizza.h"

class FarmHouse : public Pizza
{
    public:
        FarmHouse(){};
        virtual ~FarmHouse();
        int getCost() { return 200; }
        string getDescription(){ return "FarmHouse"; };
};

#endif // FARMHOUSE_H
