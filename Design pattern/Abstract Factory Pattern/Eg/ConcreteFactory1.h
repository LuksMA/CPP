#ifndef CONCRETEFACTORY1_H
#define CONCRETEFACTORY1_H

#include "AbstractFactory.h"
#include "AbstractProductA.h"
#include "AbstractProductB.h"
#include "ProductA1.h"
#include "ProductB1.h"

class ConcreteFactory1 : public AbstractFactory
{
    public:
        ConcreteFactory1();
        virtual ~ConcreteFactory1();
        AbstractProductA * createProductA();
        AbstractProductB * createProductB();
};

#endif // CONCRETEFACTORY1_H
