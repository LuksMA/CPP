#include <iostream>
#include "Dyn2array.h"
using namespace std;

int main()
{
    Dyn2array d2a(2,2);
    int** array1 = d2a.getArray();
    array1[0][0] = 10;
    array1[0][1] = 11;
    array1[1][0] = 12;
    array1[1][1] = 13;
//    cout<<array1[0][0];
    cout<<d2a[0][1];

}
