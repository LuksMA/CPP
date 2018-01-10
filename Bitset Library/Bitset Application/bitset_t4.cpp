// 4 level
#include <iostream>
#include <bitset>
#include <numeric>      // std::inner_product

using namespace std;

int main(){
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


    for(size_t i=0; i<16; ++i){
        if(v16[i]!=0){
            cout<<"v"<<i<<": \t";
            for(size_t j=0; j<10; ++j){   // bitsetSize
                if(v16[i][j]==1){
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

    for(size_t i=0; i<16; ++i){
        if(v16[i]!=0){
            cout<<"sum"<<i<<":";
            for(size_t j=0; j<10; ++j){
                if(v16[i][j]==1){
                    sum[i]+=arr[j];
                }
            }
            cout<<'\t'<<sum[i]<<endl;
        }
    }


    delete[] v16;
}




//x1: 0111001100
//x2: 0110110010
//x3: 1111100101
//x4: 0110101101
//
//v0:     7 8     0110000000
//v4:     2       0000000100
//v5:     6       0001000000
//v6:     3       0000001000
//v8:     5       0000100000
//v11:    1 4     0000010010
//v12:    0       0000000001
//v13:    9       1000000000
//
//sum0:   3
//sum4:   2
//sum5:   3
//sum6:   1
//sum8:   5
//sum11:  7
//sum12:  5
//sum13:  4
