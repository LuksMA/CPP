#ifndef PACKING_H
#define PACKING_H

#include <string>

using namespace std;

class Packing
{
    public:
        Packing();
        ~Packing();

        virtual string pack()=0;

};

#endif // PACKING_H
