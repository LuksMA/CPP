#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int var_Size = 35;
    int cut_size = 10;
    bitset<3000>** table_X = new bitset<3000>*[var_Size];
    for(int i=0; i<var_Size; ++i){
        table_X[i] = new bitset<3000>[cut_size];
    }
    cout<<table_X[1][1][1];
}
