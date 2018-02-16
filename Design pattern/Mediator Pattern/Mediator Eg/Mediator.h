#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>

using namespace std;

class Colleague;

class Mediator
{
public:
    Mediator();
    virtual ~Mediator();

    virtual void operation(int nWho,string str) = 0;
    virtual void registered(int nWho, Colleague * aColleague) = 0;
};

#endif // MEDIATOR_H
