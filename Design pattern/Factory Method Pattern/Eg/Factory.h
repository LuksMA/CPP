#ifndef FACTORY_H
#define FACTORY_H

#include "Product.h"

class Factory
{
    public:
        Factory();
        virtual ~Factory();
        virtual Product* factoryMethod();
};

#endif // FACTORY_H
