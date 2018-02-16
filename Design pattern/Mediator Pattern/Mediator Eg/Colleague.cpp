#include "Colleague.h"

Colleague::Colleague()
{
    //ctor
}

Colleague::~Colleague()
{
    //dtor
}

void Colleague::setMediator(Mediator * aMediator){
	m_pMediator = aMediator;
}
