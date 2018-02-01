#include "FreshTomato.h"

FreshTomato::~FreshTomato()
{
    //dtor
}

string FreshTomato::getDescription(){
    return ToppingsDecorator::pizza->getDescription() + ", Fresh Tomato ";
}

int FreshTomato::getCost(){
    return 40 + pizza->getCost();
}
