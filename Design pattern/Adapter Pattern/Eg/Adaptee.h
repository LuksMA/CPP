#ifndef ADAPTEE_H
#define ADAPTEE_H

#include <iostream>
using namespace std;

class Adaptee
{
    public:
        Adaptee();
        virtual ~Adaptee();

        void specificRequest();
};

#endif // ADAPTEE_H
