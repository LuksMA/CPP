#ifndef CONCRETECOLLEAGUEA_H
#define CONCRETECOLLEAGUEA_H


#include "Colleague.h"
class ConcreteColleagueA : public Colleague
{
public:
    ConcreteColleagueA();
    virtual ~ConcreteColleagueA();

    void sendmsg(int toWho,string str);
    void receivemsg(string str);
};

#endif // CONCRETECOLLEAGUEA_H
