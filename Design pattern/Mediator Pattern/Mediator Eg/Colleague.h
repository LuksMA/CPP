#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include "Mediator.h"
#include <string>
#include <iostream>
using namespace std;

class Colleague
{
public:
    Colleague();
    virtual ~Colleague();

    virtual void receivemsg(string str) = 0;
    virtual void sendmsg(int toWho,string str) = 0;
    void setMediator(Mediator * aMediator);

protected:
    Mediator * m_pMediator;
};

#endif // COLLEAGUE_H
