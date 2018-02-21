#ifndef IFAN_H
#define IFAN_H

#include <iostream>
using namespace std;

class IFan
{
    public:
        IFan();
        virtual ~IFan();
        virtual void SwitchOn() = 0;
        virtual void SwitchOff() = 0;
};

#endif // IFAN_H
