#include <iostream>
#include "Dynarray.h"

using namespace std;

int main()
{
    Dynarray da(5); // create an array object, size 10
    da.add(1); // add values to the end
    da.add(2);
    da.add(3);
    da[3] = 4; // use LHV for assignment

    cout<<'[';
        for (int i = 0; i < da.size(); i++) // get length of array using size()
            cout << da[i] << ' '; // print out using RHV
    cout<<"]\n";


    da[12] = 5; // assign element past end of array
    cout<<'[';
        for (int j = 0; j < da.size(); j++) // size is now 22
            cout << da[j] << ' '; // print out all elements again in
    cout<<"]\n";

    return 0;
}
