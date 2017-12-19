// array passed by pointer
#include <iostream>
using namespace std;
const int MAX = 5; //number of array elements
int main()
{
    void centimize(double*); //prototype
    double varray[MAX] = { 10.0, 43.1, 95.9, 59.7, 87.3 };
    centimize(varray); //change elements of varray to cm
    for(int j=0; j<MAX; j++) //display new array values
        cout << "varray[" << j << "]="
             << varray[j] << " centimeters" << endl;
    return 0;
}
//--------------------------------------------------------------
void centimize(double* ptrd)
{
    for(int j=0; j<MAX; j++)
        *ptrd++ *= 2.54; //ptrd points to elements of varray
}

//varray[0]=25.4 centimeters
//varray[1]=109.474 centimeters
//varray[2]=243.586 centimeters
//varray[3]=151.638 centimeters
//varray[4]=221.742 centimeters
