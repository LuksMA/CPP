#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n=10;
    vector<int> v(n);
//initialize the vector with values from 10 to 1
    for(int i = n - 1, j = 0; i >= 0; i--, j++) v[j] = i + 1;
//print the unsorted vector
    for(int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
    //sort the vector
    sort(v.begin(),v.end(),[](int i, int j) -> bool{ return (i < j);});
//print the sorted vector
    for(int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;

    return 0;
}
