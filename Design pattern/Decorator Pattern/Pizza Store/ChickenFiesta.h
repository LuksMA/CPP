#ifndef CHICKENFIESTA_H
#define CHICKENFIESTA_H
#include "Pizza.h"

class ChickenFiesta : public Pizza
{
    public:
        ChickenFiesta(){};
        virtual ~ChickenFiesta();
        int getCost() { return 200; }
        string getDescription(){ return "ChickenFiesta"; };
};

#endif // CHICKENFIESTA_H
