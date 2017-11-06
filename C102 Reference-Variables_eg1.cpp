#include <iostream>

using namespace std;

int main(){
    int nr1 = 5, nr2 = 7;

    int &nickname = nr1;
    cout<<nickname<<" Address: "<<&nickname<<endl;     // 5, 0x28ff08
    cout<<nr1<<" Address: "<<&nr1<<endl;               // 5, 0x28ff08
    cout<<nr2<<" Address: "<<&nr2<<endl;               // 7, 0x28ff04

    nickname = nr2;
    cout<<"Change"<<endl;
    cout<<nickname<<" Address: "<<&nickname<<endl;     // 7, 0x28ff08
    cout<<nr1<<" Address: "<<&nr1<<endl;               // 7, 0x28ff08
    cout<<nr2<<" Address: "<<&nr2<<endl;               // 7, 0x28ff08

}

