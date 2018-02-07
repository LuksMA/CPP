#include "Handler1.h"


void Handler1::handle(int i)
{
    if (rand() % 3)
    {
        cout << "H1 passed " << i << "  ";
        Base::handle(i); // 3. Delegate to the base class
    }
    else
        cout << "H1 handled " << i << "  ";
}
