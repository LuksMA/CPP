#ifndef X_H
#define X_H

#include "D.h"
class X: public D
{
    public:
        X(I *core): D(core){};
        ~X();
        void do_it();
};

#endif // X_H
