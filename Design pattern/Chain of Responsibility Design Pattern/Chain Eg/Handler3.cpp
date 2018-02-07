#include "Handler3.h"


void Handler3::handle(int i)
{
    if (rand() % 3)
    {
        cout << "H3 passed " << i << "  ";
        Base::handle(i); // 3. Delegate to the base class
    }
    else
        cout << "H3 handled " << i << "  ";
}
