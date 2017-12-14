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

using namespace std;

class Results
{
private:
    float exp;
    unsigned char index0;
    unsigned char index1;
    unsigned char index2;
    unsigned char direction;


public:
    setExp(float e){    exp = e;    }
    setIndex(unsigned char a, unsigned char aCut, unsigned char b, unsigned char bCut, unsigned char c, unsigned char cCut){
        index0 = a*100+aCut;
        index1 = b*100+bCut;
        index2 = c*100+cCut;
    }


    float getExp(){ return exp; }
    getIndex0(){    return index0;  }
    getIndex1(){    return index1;  }
    getIndex2(){    return index2;  }

    printIndex(){
        cout<<'['<<getIndex0()<<' '<<getIndex1()<<' '<<getIndex2()<<']'<<endl;
    }
};

int main()
{
    uint64_t x;
    Results * r = reinterpret_cast<Results*>(&x);
    r->setExp(11.2);
    cout<<r->getExp()<<endl;

    r->setIndex(1,9,3,10,35,11);
    cout<<r->getIndex0()<<endl;
    r->printIndex();





    return 0;
}
