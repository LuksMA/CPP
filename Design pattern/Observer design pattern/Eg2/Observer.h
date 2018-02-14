#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

#include "Subject.h"

class Observer
{
public:
    Observer(Subject *mod, int div);
    virtual void update() = 0;

protected:
    Subject *getSubject();
    int getDivisor();

private:
    Subject *model;
    int denom;
//    friend class Subject;
};

#endif // OBSERVER_H
