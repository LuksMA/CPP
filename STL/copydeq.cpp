//demonstrates normal copy with queues
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
    int arr1[] = { 1, 3, 5, 7, 9 };
    int arr2[] = { 2, 4, 6, 8, 10 };
    deque<int> d1;
    deque<int> d2;
    for(int i=0; i<5; i++) //transfer arrays to deques
    {
        d1.push_back( arr1[i] );
        d2.push_back( arr2[i] );
    } //copy d1 to d2
    copy( d1.begin(), d1.end(), d2.begin() );
    for(int k=0; k<d2.size(); k++) //display d2
        cout << d2[k] << ' ';
    cout << endl;
    return 0;
}


//1 3 5 7 9
