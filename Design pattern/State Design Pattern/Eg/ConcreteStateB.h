#ifndef CONCRETESTATEB_H
#define CONCRETESTATEB_H


#include "State.h"

class ConcreteStateB : public State
{

public:
	static State * Instance();

	virtual ~ConcreteStateB();

	virtual void handle(Context * c);
private:
	ConcreteStateB();
	static State * m_pState;
};
#endif // CONCRETESTATEB_H
