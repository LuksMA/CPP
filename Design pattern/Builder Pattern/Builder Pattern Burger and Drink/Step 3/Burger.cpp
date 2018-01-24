#include "Burger.h"

Burger::Burger()
{
    //ctor
}

Burger::~Burger()
{
    //dtor
}
Packing* Burger::packing(){
    return new Wrapper();
}
