#ifndef CIVILENGINEER_H
#define CIVILENGINEER_H

#include "HouseBuilder.h"
class CivilEngineer
{
    private:
        HouseBuilder* houseBuilder;
    public:
        CivilEngineer(HouseBuilder* h);
        ~CivilEngineer();

        House* getHouse();
        void constructHouse();
};

#endif // CIVILENGINEER_H
