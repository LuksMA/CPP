#include "Paneer.h"


Paneer::~Paneer()
{
    //dtor
}
string Paneer::getDescription(){
    return ToppingsDecorator::pizza->getDescription() + ", Paneer ";
}

int Paneer::getCost(){
    return 70 + pizza->getCost();
}
