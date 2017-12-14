/// char            1 byte      -127 to 128
/// unsigned char   1 byte      0 to 255
/// short           2 bytes     -32768 to 32767
/// unsigned short  2 bytes     0 to 65,535
/// int             4 bytes     -2147483648 to 2147483647
/// float           4 bytes
/// double          8 bytes
/// int64_t         8 bytes
/// int32_t         4 bytes
/// int16_t         2 bytes

#include<iostream>
#include "half.hpp"

using namespace std;
using half_float::half;

class Results
{
private:
    half exp;
    unsigned short index0;
    unsigned short index1;
    unsigned short index2;
public:
    setExp(half e){    exp = e;    }
    half getExp(){ return exp; }
    setIndex0(unsigned short varA, unsigned short cutA, unsigned short directionA){
        index0 = varA*1000 + cutA*10 + directionA;
    }
    unsigned short getIndex0(){  return index0;  }
};

int main(){
    uint64_t x;
    Results * r = reinterpret_cast<Results*>(&x);
    r->setExp(half(11.2));
    cout<<r->getExp()<<endl;

    r->setIndex0(12,9,1);
    cout<<r->getIndex0()<<endl;


    return 0;
}
