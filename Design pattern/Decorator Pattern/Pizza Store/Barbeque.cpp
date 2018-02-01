#include "Barbeque.h"

//Barbeque::Barbeque(Pizza* _pizza)
//{
//    pizza = _pizza;
//}

Barbeque::~Barbeque()
{
    //dtor
}

string Barbeque::getDescription(){
    return pizza->getDescription() + ", Barbeque ";
}

int Barbeque::getCost(){
    return 90 + pizza->getCost();
}
