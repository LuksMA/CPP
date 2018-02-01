#ifndef SIMPLEPIZZA_H
#define SIMPLEPIZZA_H

#include "Pizza.h"
class SimplePizza : public Pizza
{
    public:
        SimplePizza(){};
        virtual ~SimplePizza();
        int getCost() { return 50; }
        string getDescription(){ return "SimplePizza"; };
};

#endif // SIMPLEPIZZA_H
