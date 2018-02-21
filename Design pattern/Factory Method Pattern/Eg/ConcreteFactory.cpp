#include "ConcreteFactory.h"

ConcreteFactory::ConcreteFactory()
{
    //ctor
}

ConcreteFactory::~ConcreteFactory()
{
    //dtor
}

Product* ConcreteFactory::factoryMethod(){
	return  new ConcreteProduct();
}
