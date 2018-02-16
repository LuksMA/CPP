#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H


#include "ConcreteColleagueB.h"
#include "Mediator.h"
#include "ConcreteColleagueA.h"

#include <map>
#include <iostream>
using namespace std;

class ConcreteMediator : public Mediator
{

public:
	ConcreteMediator();
	virtual ~ConcreteMediator();

	virtual void operation(int nWho,string str);
	virtual void registered(int nWho, Colleague * aColleague);
private:
	map<int,Colleague*> m_mpColleague;
};

#endif // CONCRETEMEDIATOR_H
