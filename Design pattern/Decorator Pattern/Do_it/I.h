#ifndef I_H
#define I_H

#include <iostream>
using namespace std;

class I
{
    public:
        virtual ~I();
        virtual void do_it() = 0;

};

#endif // I_H
