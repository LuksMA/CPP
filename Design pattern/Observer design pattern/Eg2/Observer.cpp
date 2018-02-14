#include "Observer.h"



Observer::Observer(Subject *mod, int div)
{
    model = mod;
    denom = div;
    model->attach(this);
}

Subject* Observer::getSubject()
{
    return model;
}
int Observer::getDivisor()
{
    return denom;
}
