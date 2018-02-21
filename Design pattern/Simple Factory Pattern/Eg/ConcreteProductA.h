#ifndef CONCRETEPRODUCTA_H
#define CONCRETEPRODUCTA_H

#include "Product.h"
class ConcreteProductA : public Product
{
    public:
        ConcreteProductA();
        virtual ~ConcreteProductA();
        void Use();
};

#endif // CONCRETEPRODUCTA_H
