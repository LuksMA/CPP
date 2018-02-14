#ifndef MODOBSERVER_H
#define MODOBSERVER_H


#include "Subject.h"
#include "Observer.h"

class ModObserver: public Observer
{
    public:
        ModObserver(Subject *mod, int div): Observer(mod, div){};
        void update();
};

#endif // MODOBSERVER_H
