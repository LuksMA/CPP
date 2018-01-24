#include "ColdDrink.h"

ColdDrink::ColdDrink()
{
    //ctor
}

ColdDrink::~ColdDrink()
{
    //dtor
}
Packing* ColdDrink::packing(){
    return new Bottle();
}
