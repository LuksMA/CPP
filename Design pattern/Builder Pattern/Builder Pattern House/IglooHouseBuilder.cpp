#include "IglooHouseBuilder.h"

IglooHouseBuilder::IglooHouseBuilder()
{
    house = new House();
}

IglooHouseBuilder::~IglooHouseBuilder()
{
    //dtor
}

void IglooHouseBuilder::buildBasement(){
    house->setBasement("Ice Bars");
}

void IglooHouseBuilder::buildStructure(){
    house->setStructur("Ice Blocks");
}

void IglooHouseBuilder::bulidRoof(){
    house->setRoof("Ice Dome");
}

void IglooHouseBuilder::buildInterior(){
    house->setInterior("Ice Carvings");
}

House* IglooHouseBuilder::getHouse(){
    return house;
}
