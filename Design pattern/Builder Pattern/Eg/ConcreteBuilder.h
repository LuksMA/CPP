#ifndef CONCRETEBUILDER_H
#define CONCRETEBUILDER_H

#include "Builder.h"

class ConcreteBuilder : public Builder
{
public:
    ConcreteBuilder();
    virtual ~ConcreteBuilder();

    void buildPartA();
    void buildPartB();
    void buildPartC();
};

#endif // CONCRETEBUILDER_H
