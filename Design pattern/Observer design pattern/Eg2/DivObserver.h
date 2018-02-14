#ifndef DIVOBSERVER_H
#define DIVOBSERVER_H

#include "Subject.h"
#include "Observer.h"

class DivObserver: public Observer
{
    public:
        DivObserver(Subject *mod, int div): Observer(mod, div){};
        void update();
};

#endif // DIVOBSERVER_H
