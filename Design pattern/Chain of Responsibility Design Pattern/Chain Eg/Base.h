#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Base
{
public:
    Base();
    void setNext(Base *n);
    void add(Base *n);
    virtual void handle(int i);

private:
    Base *next;
};

#endif // BASE_H
