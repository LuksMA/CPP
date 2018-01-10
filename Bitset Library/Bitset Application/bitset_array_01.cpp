#include <iostream>
#include <bitset>

using namespace std;

int main(){
    bitset<3> array_x[5];
    cout<<array_x[0]<<endl;
    cout<<array_x[1].flip(1)<<endl;
    cout<<array_x[1][1]<<endl;
}

//000
//010
//1
