// demonstrates reverse iterator
#include <iostream>
#include <list>
using namespace std;

int main()
{
    int arr[] = { 2, 4, 6, 8, 10 }; //array of ints
    list<int> theList;
    for(int j=0; j<5; j++) //transfer array
        theList.push_back( arr[j] ); //to list
    list<int>::reverse_iterator revit; //reverse iterator
    revit = theList.rbegin(); //iterate backward
    while( revit != theList.rend() ) //through list,
        cout << *revit++ << ' '; //displaying output
    cout << endl;
    return 0;
}

//10 8 6 4 2
