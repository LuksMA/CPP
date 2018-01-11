// 4 level
#include <iostream>
#include <bitset>
#include <numeric>      // std::inner_product

using namespace std;

int main()
{
    bitset<10> x1("0111001100");
    bitset<10> x2("0110110010");
    bitset<10> x3("1111100101");
    bitset<10> x4("0110101101");

    // Part 1.
    cout<<"x1: "<<x1<<endl;
    cout<<"x2: "<<x2<<endl;
    cout<<"x3: "<<x3<<endl;
    cout<<"x4: "<<x4<<endl;

    // Part 2.
    cout<<endl;
    bitset<10>* v16 = new bitset<10>[16];
    v16[0] = x1 & x2 & x3 & x4;     // 1111
    v16[1] = x1 & x2 & x3 & ~x4;    // 1110
    v16[2] = x1 & x2 & ~x3 & x4;    // 1101
    v16[3] = x1 & x2 & ~x3 & ~x4;   // 1100
    v16[4] = x1 & ~x2 & x3 & x4;    // 1011
    v16[5] = x1 & ~x2 & x3 & ~x4;   // 1010
    v16[6] = x1 & ~x2 & ~x3 & x4;   // 1001
    v16[7] = x1 & ~x2 & ~x3 & ~x4;  // 1000
    v16[8] = ~x1 & x2 & x3 & x4;    // 0111
    v16[9] = ~x1 & x2 & x3 & ~x4;   // 0110
    v16[10] = ~x1 & x2 & ~x3 & x4;  // 0101
    v16[11] = ~x1 & x2 & ~x3 & ~x4; // 0100
    v16[12] = ~x1 & ~x2 & x3 & x4;  // 0011
    v16[13] = ~x1 & ~x2 & x3 & ~x4; // 0010
    v16[14] = ~x1 & ~x2 & ~x3 & x4; // 0001
    v16[15] = ~x1 & ~x2 & ~x3 & ~x4;// 0000

//    for(size_t i=0; i<16; ++i){
//        cout<<"v"<<i<<": \t";
//        for(size_t j=0; j<10; ++j){   // bitsetSize
//            if(v16[i][j]==1){
//                cout<<j<<' ';
//            }
//        }
//        cout<<'\t'<<v16[i]<<endl;
//    }


    for(size_t i=0; i<16; ++i)
    {
        if(v16[i]!=0)
        {
            cout<<"v"<<i<<": \t";
            for(size_t j=0; j<10; ++j)    // bitsetSize
            {
                if(v16[i][j]==1)
                {
                    cout<<j<<' ';
                }
            }
            cout<<'\t'<<v16[i]<<endl;
        }
    }



//     Part 3.
    cout<<endl;
    int sum[16] = {0};
    int arr[10] = {5,3,2,1,4,5,3,2,1,4};

//    for(size_t i=0; i<16; ++i){
//        cout<<"sum"<<i<<": \t";
//        for(size_t j=0; j<10; ++j){
//            if(v16[i][j]==1){
//                sum[i]+=arr[j];
//            }
//        }
//        cout<<'\t'<<sum[i]<<endl;
//    }

    for(size_t i=0; i<16; ++i)
    {
        if(v16[i]!=0)
        {
            cout<<"sum"<<i<<":";
            for(size_t j=0; j<10; ++j)
            {
                if(v16[i][j]==1)
                {
                    sum[i]+=arr[j];
                }
            }
            cout<<'\t'<<sum[i]<<endl;
        }
    }


//    int sum1=0;
//    for (size_t i=v16[0].size(); i; i--, v16[0]>>=1)
//        if (v16[0][0])
//            sum1+=arr[i];
//    cout<<sum1;

    for(size_t i=0; i<16; ++i)
    {
        if(v16[i]!=0)
        {
            cout<<"sum"<<i<<":";
            for(size_t j=v16[i].size(); j; j--, v16[i]>>=1)
            {
                if(v16[i][j])
                {
                    sum[i]+=arr[i];
                }
            }
            cout<<'\t'<<sum[i]<<endl;
        }
    }


    delete[] v16;
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
