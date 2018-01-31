#include "BorderDecorator.h"

void BorderDecorator :: draw()
{
    Decorator::draw();
    cout << "   BorderDecorator" << '\n';
}
