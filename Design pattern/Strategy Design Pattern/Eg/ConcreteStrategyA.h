#ifndef CONCRETESTRATEGYA_H
#define CONCRETESTRATEGYA_H


#include "Strategy.h"

class ConcreteStrategyA : public Strategy
{

public:
	ConcreteStrategyA();
	virtual ~ConcreteStrategyA();

	void algorithm();

};

#endif // CONCRETESTRATEGYA_H
