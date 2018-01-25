#include <iostream>

using namespace std;

#include "CivilEngineer.h"
#include "IglooHouseBuilder.h"

int main()
{
    HouseBuilder* iglooBuilder = new IglooHouseBuilder();
    CivilEngineer* engineer = new CivilEngineer(iglooBuilder);

    engineer->constructHouse();
    House* house = engineer->getHouse();

    cout<<"Builder constructed: "<< house;
}
