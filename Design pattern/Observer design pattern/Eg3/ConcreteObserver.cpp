#include "ConcreteObserver.h"

ConcreteObserver ::ConcreteObserver (string name)
{
    m_objName = name;
}

ConcreteObserver ::~ConcreteObserver ()
{
    //dtor
}

void ConcreteObserver::update(Subject * sub){
	m_observerState = sub->getState();
	cout << "update observer[" << m_objName << "] state:" << m_observerState << endl;
}
