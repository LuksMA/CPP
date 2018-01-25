#ifndef IGLOOHOUSEBUILDER_H
#define IGLOOHOUSEBUILDER_H

#include "HouseBuilder.h"

class IglooHouseBuilder : public HouseBuilder
{
    private:
        House* house;
    public:
        IglooHouseBuilder();
        ~IglooHouseBuilder();

        void buildBasement();
        void buildStructure();
        void bulidRoof();
        void buildInterior();
        House* getHouse();

};

#endif // IGLOOHOUSEBUILDER_H
