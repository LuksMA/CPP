#include "Base.h"

Base::Base()
{
    next = 0;
}
void Base::setNext(Base *n)
{
    next = n;
}
void Base::add(Base *n)
{
    if (next)
        next->add(n);
    else
        next = n;
}
void Base::handle(int i)
{
    next->handle(i);
}
