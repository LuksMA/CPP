#include "ConcreteFactory2.h"

ConcreteFactory2::ConcreteFactory2()
{
    //ctor
}

ConcreteFactory2::~ConcreteFactory2()
{
    //dtor
}

AbstractProductA * ConcreteFactory2::createProductA(){
	return new ProductA2();
}


AbstractProductB * ConcreteFactory2::createProductB(){
	return new ProductB2();
}
