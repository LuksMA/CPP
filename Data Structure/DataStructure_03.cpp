#include "half.hpp"
#include<iostream>

using namespace std;
using half_float::half;

int main(){

    half a(3.1415);
    half b(3.1426);
    half c(3.1425);

    cout<<"3.1415 < 3.1426 ? "<<(a<b)<<endl;
    cout<<"3.1415 < 3.1425 ? "<<(a<c)<<endl;

    return 0;
}
