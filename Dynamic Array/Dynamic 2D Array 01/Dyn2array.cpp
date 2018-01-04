#include "Dyn2array.h"

Dyn2array::Dyn2array(int row, int column)
{
    rowL = row;
    columnL = column;
    var = new int*[row];
    for(int i=0; i<row; ++i){
        var[i] = new int[column];
    }
}

Dyn2array::~Dyn2array()
{
    delete [] var;
}
