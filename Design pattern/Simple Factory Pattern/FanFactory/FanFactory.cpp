#include "FanFactory.h"


FanFactory::FanFactory()
{
    //ctor
}

FanFactory::~FanFactory()
{
    //dtor
}
IFan* FanFactory::createFan(FanType type)
{
    switch (type)
    {
    case tablefan:
        return new TableFan();
    case ceilingfan:
        return new CeilingFan();
    case exhaustfan:
        return new ExhaustFan();
    default:
        return new TableFan();
    }
}
