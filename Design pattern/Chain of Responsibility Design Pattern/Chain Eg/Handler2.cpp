#include "Handler2.h"


void Handler2::handle(int i)
{
    if (rand() % 3)
    {
        cout << "H2 passed " << i << "  ";
        Base::handle(i); // 3. Delegate to the base class
    }
    else
        cout << "H2 handled " << i << "  ";
}
