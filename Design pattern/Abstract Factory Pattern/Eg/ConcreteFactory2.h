#ifndef CONCRETEFACTORY2_H
#define CONCRETEFACTORY2_H

#include "AbstractFactory.h"
#include "AbstractProductA.h"
#include "AbstractProductB.h"
#include "ProductA2.h"
#include "ProductB2.h"

class ConcreteFactory2 : public AbstractFactory
{
    public:
        ConcreteFactory2();
        virtual ~ConcreteFactory2();
        AbstractProductA * createProductA();
        AbstractProductB * createProductB();
};

#endif // CONCRETEFACTORY2_H
