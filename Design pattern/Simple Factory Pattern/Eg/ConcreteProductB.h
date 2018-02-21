#ifndef CONCRETEPRODUCTB_H
#define CONCRETEPRODUCTB_H

#include "Product.h"
class ConcreteProductB : public Product
{
    public:
        ConcreteProductB();
        virtual ~ConcreteProductB();
        void Use();
};

#endif // CONCRETEPRODUCTB_H
