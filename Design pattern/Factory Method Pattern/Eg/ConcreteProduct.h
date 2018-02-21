#ifndef CONCRETEPRODUCT_H
#define CONCRETEPRODUCT_H

#include "Product.h"
class ConcreteProduct : public Product
{
    public:
        ConcreteProduct();
        virtual ~ConcreteProduct();
        void use();
};

#endif // CONCRETEPRODUCT_H
