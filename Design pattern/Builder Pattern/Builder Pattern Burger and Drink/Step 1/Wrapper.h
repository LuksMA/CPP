#ifndef WRAPPER_H
#define WRAPPER_H

#include "Packing.h"

class Wrapper: public Packing
{
    public:
        Wrapper();
        ~Wrapper();
        string pack(){ return "Wrapper";}
};



#endif // WRAPPER_H
