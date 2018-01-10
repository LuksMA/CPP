#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    bitset<5> x1("01110");
    bitset<5> x2("01101");

    cout<<"x1:"<<x1<<" x2:"<<x2<<endl;

    cout<<"x1 <  c1:\t\t";
    for (size_t i=0; i<x1.size(); ++i)
        if(x1[i]==1){
            cout<<i<<' ';
        }

    cout<<"\nx1 >= c1:\t\t";
    for (size_t i=0; i<x1.size(); ++i)
        if(x1[i]==0){
            cout<<i<<' ';
        }

    cout<<"\nx2 <  c2:\t\t";
    for (size_t i=0; i<x2.size(); ++i)
        if(x2[i]==1){
            cout<<i<<' ';
        }

    cout<<"\nx2 >= c2:\t\t";
    for (size_t i=0; i<x2.size(); ++i)
        if(x2[i]==0){
            cout<<i<<' ';
        }

    /// Case 1: 11
    auto x1x2 = x1 & x2;
    cout<<"\nx1 < c1, x2 < c2:\t";
    for (size_t i=0; i<x1x2.size(); ++i)
        if(x1x2[i]==1){
            cout<<i<<' ';
        }
    cout<<'\t'<<x1x2<<endl;
    /// Case 2: 10
    auto x1Nx2 = x1 & ~x2;
        cout<<"x1 < c1, x2 >= c2:\t";
    for (size_t i=0; i<x1Nx2.size(); ++i)
        if(x1Nx2[i]==1){
            cout<<i<<' ';
        }
    cout<<'\t'<<x1Nx2<<endl;
    /// Case 3: 01
    auto Nx1x2 = ~x1 & x2;
        cout<<"x1 < c1, x2 >= c2:\t";
    for (size_t i=0; i<Nx1x2.size(); ++i)
        if(Nx1x2[i]==1){
            cout<<i<<' ';
        }
    cout<<'\t'<<Nx1x2<<endl;
    /// Case 4: 00
    auto Nx1Nx2 = ~x1 & ~x2;
        cout<<"x1 < c1, x2 >= c2:\t";
    for (size_t i=0; i<Nx1Nx2.size(); ++i)
        if(Nx1Nx2[i]==1){
            cout<<i<<' ';
        }
    cout<<'\t'<<Nx1Nx2<<endl;
}


//x1:01110 x2:01101
//x1 <  c1:               1 2 3
//x1 >= c1:               0 4
//x2 <  c2:               0 2 3
//x2 >= c2:               1 4
//x1 < c1, x2 < c2:       2 3     01100
//x1 < c1, x2 >= c2:      1       00010
//x1 < c1, x2 >= c2:      0       00001
//x1 < c1, x2 >= c2:      4       10000
