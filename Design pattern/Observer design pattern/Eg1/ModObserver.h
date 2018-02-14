#ifndef MODOBSERVER_H
#define MODOBSERVER_H

#include "Subject.h"
#include "Observer.h"

class ModObserver: public Observer
{
public:
    ModObserver(Subject *model, int mod);
    void update(int v);

private:
    int m_mod;
};

#endif // MODOBSERVER_H
