#include "DivObserver.h"

void DivObserver :: update()
{
    int v = getSubject()->getVal(), d = getDivisor();
    cout << v << " div " << d << " is " << v / d << '\n';
}
