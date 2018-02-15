#ifndef CONCRETESTRATEGYB_H
#define CONCRETESTRATEGYB_H


#include "Strategy.h"

class ConcreteStrategyB : public Strategy
{

public:
	ConcreteStrategyB();
	virtual ~ConcreteStrategyB();

	virtual void algorithm();

};

#endif // CONCRETESTRATEGYB_H
