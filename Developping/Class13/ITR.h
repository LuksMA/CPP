#ifndef ITR_H
#define ITR_H

#include <iostream>
using namespace std;

class ITR
{
private:
    int** var_X;

public:
    ITR();
    ~ITR();
    class Dyn2array
    {
    private:
        int** var;
        int rowL;
        int columnL;


    public:
        Dyn2array(int row, int column);
        ~Dyn2array();
        int getRow();
        int getColumn();
        int** getArray();
        void printArray();

    };






};

#endif // ITR_H
