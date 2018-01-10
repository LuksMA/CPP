#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int x = 5;
    bitset<3>* arr = new bitset<3>[x];
    cout<<arr[0]<<endl;
    cout<<arr[1].flip(1)<<endl;
    cout<<arr[1][1]<<endl;
    cout<<arr[1]<<endl;
    cout<<arr[2]<<endl;
    cout<<arr[3]<<endl;
    cout<<arr[4]<<endl;
}
