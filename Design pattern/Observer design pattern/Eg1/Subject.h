#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>
#include <iostream>
using namespace std;

class Subject
{
public:
    void attach(Observer *obs);
    void set_val(int value);
    void notify();


private:
    int m_value;
    vector<Observer*> m_views;
};

#endif // SUBJECT_H
