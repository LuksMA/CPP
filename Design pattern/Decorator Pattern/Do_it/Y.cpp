#include "Y.h"

Y::~Y()
{
    cout << "Y dtor" << "   ";
}
void Y::do_it(){
    D::do_it();
    cout << 'Y';
}
