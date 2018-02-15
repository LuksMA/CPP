#ifndef STRATEGY_H
#define STRATEGY_H


#include <iostream>
using namespace std;

class Strategy
{

public:
	Strategy();
	virtual ~Strategy();

	virtual void algorithm();

};

#endif // STRATEGY_H
