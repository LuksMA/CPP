#include "Abstraction.h"

Abstraction::Abstraction()
{
    //ctor
}

Abstraction::~Abstraction()
{
    delete m_pImp;
}

Abstraction::Abstraction(Implementor* imp){
	m_pImp = imp;
}

void Abstraction::operation(){

}
