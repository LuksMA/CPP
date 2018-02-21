#include "ConcreteFactory1.h"

ConcreteFactory1::ConcreteFactory1()
{
    //ctor
}

ConcreteFactory1::~ConcreteFactory1()
{
    //dtor
}

AbstractProductA * ConcreteFactory1::createProductA(){
	return new ProductA1();
}


AbstractProductB * ConcreteFactory1::createProductB(){
	return new ProductB1();
}
