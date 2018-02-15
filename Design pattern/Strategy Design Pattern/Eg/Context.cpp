#include "Context.h"

Context::Context()
{
    //ctor
}

Context::~Context()
{
    //dtor
}

void Context::algorithm(){
	m_pStrategy->algorithm();
}

void Context::setStrategy(Strategy* st){
	m_pStrategy = st;
}
