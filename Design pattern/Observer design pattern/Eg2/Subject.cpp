#include "Subject.h"


void Subject::attach(Observer *obs)
{
    views.push_back(obs);
}
void Subject::setVal(int val)
{
    value = val;
    notify();
}
int Subject::getVal()
{
    return value;
}
void Subject::notify()
{
    for (unsigned i = 0; i < views.size(); i++)
        views[i]->update();
}
