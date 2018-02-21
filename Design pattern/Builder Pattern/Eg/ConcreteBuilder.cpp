#include "ConcreteBuilder.h"

ConcreteBuilder::ConcreteBuilder()
{
    //ctor
}

ConcreteBuilder::~ConcreteBuilder()
{
    //dtor
}

void ConcreteBuilder::buildPartA(){
	m_prod->setA("A Style ");
}


void ConcreteBuilder::buildPartB(){
	m_prod->setB("B Style ");
}


void ConcreteBuilder::buildPartC(){
	m_prod->setC("C style ");
}
