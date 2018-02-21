#ifndef FANFACTORY_H
#define FANFACTORY_H

#include "IFan.h"
#include "TableFan.h"
#include "CeilingFan.h"
#include "ExhaustFan.h"

enum FanType
{
    tablefan,
    ceilingfan,
    exhaustfan
};



class FanFactory
{
    public:
        FanFactory();
        virtual ~FanFactory();
        static IFan* createFan(FanType type);
};

#endif // FANFACTORY_H
