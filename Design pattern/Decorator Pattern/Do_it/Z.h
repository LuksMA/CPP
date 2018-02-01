#ifndef Z_H
#define Z_H


#include "D.h"

class Z: public D
{
    public:
        Z(I *core): D(core){};
        ~Z();
        void do_it();
};

#endif // Z_H
