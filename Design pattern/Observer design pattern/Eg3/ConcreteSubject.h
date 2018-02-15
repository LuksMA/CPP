#ifndef CONCRETESUBJECT_H
#define CONCRETESUBJECT_H


#include "Subject.h"

class ConcreteSubject : public Subject
{

public:
	ConcreteSubject();
	virtual ~ConcreteSubject();

	int getState();
	void setState(int i);

private:
	int m_nState;

};

#endif // CONCRETESUBJECT_H
