#include "Z.h"

Z::~Z()
{
    cout << "Z dtor" << "   ";
}
void Z::do_it(){
    D::do_it();
    cout << 'Z';
}
