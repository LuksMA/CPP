#ifndef Y_H
#define Y_H

#include "D.h"

class Y: public D
{
    public:
        Y(I *core): D(core){};
        ~Y();
        void do_it();
};


#endif // Y_H
