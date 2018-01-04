#include "ITR.h"

ITR::ITR()
{
    //ctor
}

ITR::~ITR()
{
    //dtor
}









ITR :: Dyn2array :: Dyn2array(int row, int column)
{
    rowL = row;
    columnL = column;
    var = new int*[row];
    for(int i=0; i<row; ++i)
    {
        var[i] = new int[column];
    }
}

ITR :: Dyn2array :: ~Dyn2array()
{
    delete [] var;
}

int ITR :: Dyn2array :: getRow(){
    return rowL;
}
int ITR :: Dyn2array :: getColumn(){
    return columnL;
}
int** ITR :: Dyn2array :: getArray(){
    return var;
}

void ITR::Dyn2array :: printArray()
{
    for(int i=0; i<rowL; ++i)
    {
        for(int j=0; j<columnL; ++j)
        {
            cout<<var[i][j]<<' ';
        }
        cout<<endl;
    }
}
