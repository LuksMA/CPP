#ifndef CEILINGFAN_H
#define CEILINGFAN_H

#include "IFan.h"
class CeilingFan : public IFan
{
    public:
        CeilingFan();
        virtual ~CeilingFan();
        void SwitchOn();
        void SwitchOff();
};

#endif // CEILINGFAN_H
