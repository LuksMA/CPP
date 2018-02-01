#ifndef MARGHERITA_H
#define MARGHERITA_H
#include "Pizza.h"

class Margherita : public Pizza
{
    public:
        Margherita(){};
        virtual ~Margherita();
        int getCost() { return 100; }
        string getDescription(){ return "Margherita"; };
};

#endif // MARGHERITA_H
