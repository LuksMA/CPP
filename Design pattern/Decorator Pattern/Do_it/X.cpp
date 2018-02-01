#include "X.h"


X::~X()
{
    cout << "X dtor" << "   ";
}
void X::do_it(){
    D::do_it();
    cout << 'X';
}
