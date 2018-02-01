#ifndef PIZZA_H
#define PIZZA_H

#include <string>

using namespace std;

class Pizza
{
    public:
        virtual string getDescription() = 0;
        virtual int getCost() = 0;
};

#endif // PIZZA_H
