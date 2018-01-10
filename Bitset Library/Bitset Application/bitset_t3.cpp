// 2 level
#include <iostream>
#include <bitset>

using namespace std;

int main(){
    bitset<5> x1("01110");
    bitset<5> x2("01101");

    // Part 1.
    cout<<"x1:"<<x1<<" x2:"<<x2<<endl;

    // Part 2.
    cout<<"x1 <  c1:\t";
    for (size_t i=0; i<x1.size(); ++i)
        if(x1[i]==1){
            cout<<i<<' ';
        }

    cout<<"\nx1 >= c1:\t";
    for (size_t i=0; i<x1.size(); ++i)
        if(x1[i]==0){
            cout<<i<<' ';
        }

    cout<<"\nx2 <  c2:\t";
    for (size_t i=0; i<x2.size(); ++i)
        if(x2[i]==1){
            cout<<i<<' ';
        }

    cout<<"\nx2 >= c2:\t";
    for (size_t i=0; i<x2.size(); ++i)
        if(x2[i]==0){
            cout<<i<<' ';
        }
    cout<<endl;

    // Part 3.
    bitset<5>* v4 = new bitset<5>[4];
    v4[0] = x1 & x2;
    v4[1] = x1 & ~x2;
    v4[2] = ~x1 & x2;
    v4[3] = ~x1 & ~x2;

    for(size_t i=0; i<4; ++i){
        cout<<"v"<<i<<": \t\t";
        for(size_t j=0; j<5; ++j){
            if(v4[i][j]==1){
                cout<<j<<' ';
            }
        }
        cout<<'\t'<<v4[i]<<endl;
    }

    // Part 4.
    int sum[4] = {0};
    int arr[5] = {5,3,2,1,4};
    for(size_t i=0; i<4; ++i){
        cout<<"sum"<<i<<": \t";
        for(size_t j=0; j<5; ++j){
            if(v4[i][j]==1){
                sum[i]+=arr[j];
            }
        }
        cout<<'\t'<<sum[i]<<endl;
    }
    delete[] v4;
}




//x1:01110 x2:01101
//x1 <  c1:       1 2 3
//x1 >= c1:       0 4
//x2 <  c2:       0 2 3
//x2 >= c2:       1 4
//v0:             2 3     01100
//v1:             1       00010
//v2:             0       00001
//v3:             4       10000
//sum0:           3
//sum1:           3
//sum2:           5
//sum3:           4

//    5 3 2 1 4
// v0     * *   =>3  (sum0)
// v1   *       =>3  (sum1)
// v2 *         =>5  (sum2)
// v3         * =>4  (sum3)
//    0 1 2 3 4
