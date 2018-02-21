#include "Factory.h"

Factory::Factory()
{
    //ctor
}

Factory::~Factory()
{
    //dtor
}
Product* Factory::createProduct(string proname){
	if ( "A" == proname )
	{
		return new ConcreteProductA();
	}
	else if("B" == proname)
	{
		return new ConcreteProductB();
	}
	return  NULL;
}
