#ifndef EXHAUSTFAN_H
#define EXHAUSTFAN_H

#include "IFan.h"
class ExhaustFan : public IFan
{
    public:
        ExhaustFan();
        virtual ~ExhaustFan();
        void SwitchOn();
        void SwitchOff();
};

#endif // EXHAUSTFAN_H
