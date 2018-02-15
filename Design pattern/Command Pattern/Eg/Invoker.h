#ifndef INVOKER_H
#define INVOKER_H

#include "Command.h"
#include <iostream>
using namespace std;

class Invoker
{

public:
	Invoker(Command * pCommand);
	virtual ~Invoker();
	void call();

private:
	Command *m_pCommand;
};

#endif // INVOKER_H
