#ifndef TIPIHOUSEBUILDER_H
#define TIPIHOUSEBUILDER_H

#include "HouseBuilder.h"
class TipiHouseBuilder : public HouseBuilder
{

    private:
        House* house;

    public:
        TipiHouseBuilder();
        ~TipiHouseBuilder();

        void buildBasement();
        void buildStructure();
        void bulidRoof();
        void buildInterior();
        House* getHouse();
};

#endif // TIPIHOUSEBUILDER_H
