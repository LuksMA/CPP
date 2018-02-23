#ifndef IMPLEMENTOR_H
#define IMPLEMENTOR_H

#include <iostream>
using namespace std;

class Implementor
{
public:
    Implementor();
    virtual ~Implementor();

    virtual void operationImp();
};

#endif // IMPLEMENTOR_H
