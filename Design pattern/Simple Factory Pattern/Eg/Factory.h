#ifndef FACTORY_H
#define FACTORY_H

#include "Product.h"
#include "ConcreteProductA.h"
#include "ConcreteProductB.h"
#include <string>
using namespace std;

class Factory
{
    public:
        Factory();
        virtual ~Factory();
        static Product * createProduct(string proname);
};

#endif // FACTORY_H
