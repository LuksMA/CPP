#include "CivilEngineer.h"

CivilEngineer::CivilEngineer(HouseBuilder* h)
{
    houseBuilder = h;
}

CivilEngineer::~CivilEngineer()
{
    //dtor
}

House* CivilEngineer::getHouse(){
    return houseBuilder->getHouse();
}

void CivilEngineer::constructHouse(){
    houseBuilder->buildBasement();
    houseBuilder->buildStructure();
    houseBuilder->bulidRoof();
    houseBuilder->buildInterior();
}
