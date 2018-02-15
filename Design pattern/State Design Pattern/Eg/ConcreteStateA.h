#ifndef CONCRETESTATEA_H
#define CONCRETESTATEA_H


#include "State.h"

class ConcreteStateA : public State
{

public:
	virtual ~ConcreteStateA();

	static State * Instance();

	virtual void handle(Context * c);

private:
	ConcreteStateA();
	static State * m_pState;
};

#endif // CONCRETESTATEA_H
