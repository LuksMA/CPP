#include "StackIter.h"

void StackIter::operator++()
{
    index++;
}
bool StackIter::operator()()
{
    return index != stk.sp + 1;
}
int StackIter::operator *()
{
    return stk.items[index];
}
