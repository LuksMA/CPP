#ifndef CONCRETEFACTORY_H
#define CONCRETEFACTORY_H

#include "Product.h"
#include "Factory.h"
#include "ConcreteProduct.h"
class ConcreteFactory : public Factory
{
    public:
        ConcreteFactory();
        virtual ~ConcreteFactory();
        Product* factoryMethod();
};

#endif // CONCRETEFACTORY_H
