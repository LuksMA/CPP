#ifndef RECEIVER_H
#define RECEIVER_H

#include <iostream>
using namespace std;

class Receiver
{
    public:
        Receiver();
        virtual ~Receiver();

        void action();
};

#endif // RECEIVER_H
