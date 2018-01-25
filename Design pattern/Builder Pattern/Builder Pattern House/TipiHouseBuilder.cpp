#include "TipiHouseBuilder.h"

TipiHouseBuilder::TipiHouseBuilder()
{
    house = new House();
}

TipiHouseBuilder::~TipiHouseBuilder()
{
    //dtor
}

void TipiHouseBuilder::buildBasement(){
    house->setBasement("Wooden Poles");
}

void TipiHouseBuilder::buildStructure(){
    house->setStructur("Wood and Ice");
}

void TipiHouseBuilder::bulidRoof(){
    house->setRoof("Wood, caribou and seal skins");
}

void TipiHouseBuilder::buildInterior(){
    house->setInterior("Fire Wood");
}

House* TipiHouseBuilder::getHouse(){
    return house;
}
