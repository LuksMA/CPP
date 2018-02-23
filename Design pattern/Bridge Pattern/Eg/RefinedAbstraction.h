#ifndef REFINEDABSTRACTION_H
#define REFINEDABSTRACTION_H

#include "Abstraction.h"

class RefinedAbstraction : public Abstraction
{
public:
    RefinedAbstraction();
    RefinedAbstraction(Implementor* imp);
    virtual ~RefinedAbstraction();

    virtual void operation();
};

#endif // REFINEDABSTRACTION_H
