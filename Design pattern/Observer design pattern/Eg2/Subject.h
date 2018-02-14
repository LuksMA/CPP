#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <iostream>
#include "Observer.h"
using namespace std;

class Observer;

class Subject
{
private:
    vector <Observer * > views;
    int value;

public:
    void attach(Observer *obs);
    void setVal(int val);
    int getVal();
    void notify();
};

#endif // SUBJECT_H
