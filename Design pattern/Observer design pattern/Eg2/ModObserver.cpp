#include "ModObserver.h"


void ModObserver::update()
{
    int v = getSubject()->getVal(), d = getDivisor();
    cout << v << " mod " << d << " is " << v % d << '\n';
}
