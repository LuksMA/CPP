/// char            1 byte      -127 to 128
/// unsigned char   1 byte      0 to 255
/// short int       2 bytes     -32768 to 32767
/// int             4 bytes
/// float           4 bytes
/// double          8 bytes
/// int64_t         8 bytes
/// int32_t         4 bytes
/// int16_t         2 bytes

#include<cstdint>
#include<iostream>

using namespace std;

class Features
{
  private:
    unsigned char _n_continuous;
    unsigned char _n_nominal;
    unsigned char _f0;
    char _c0;
    unsigned char _f1;
    char _c1;
    unsigned char _f2;
    char _c2;

  public:
    set_N_Cont(unsigned char x){
        _n_continuous = x;
    }
    get_N_Cont(){
        return _n_continuous;
    }
};

int main(){
    uint64_t x;
    Features * f = reinterpret_cast<Features*>(&x);
    f->set_N_Cont(11);
    cout<<f->get_N_Cont();
}
