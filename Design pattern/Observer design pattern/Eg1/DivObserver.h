#ifndef DIVOBSERVER_H
#define DIVOBSERVER_H

#include "Subject.h"
#include "Observer.h"


class DivObserver: public Observer
{
public:
    DivObserver(Subject *model, int div);
    void update(int v);

private:
    int m_div;
};

#endif // DIVOBSERVER_H
