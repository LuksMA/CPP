#include "ConcreteSubject.h"

ConcreteSubject::ConcreteSubject()
{
    //ctor
}

ConcreteSubject::~ConcreteSubject()
{
    //dtor
}

int ConcreteSubject::getState(){
	return m_nState;
}


void ConcreteSubject::setState(int i){
	m_nState = i;
}
