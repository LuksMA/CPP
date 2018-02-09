#include "Result.h"

Result:: Result(double v, unsigned short varI, unsigned short cutI, unsigned short dirI, unsigned short varJ, unsigned short cutJ, unsigned short dirJ, unsigned short varK, unsigned short cutK, unsigned short dirK)
{
    value = (float)v;
    info[0] = cutI + varI*100 + dirI*10000;
    info[1] = cutJ + varJ*100 + dirJ*10000;
    info[2] = cutK + varK*100 + dirK*10000;
}

Result::~Result()
{
    //dtor
}
