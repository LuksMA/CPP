#include <vector>
#include <iostream>
using namespace std;

template<class T>
void print1DVector(vector<T> const &vectIn){
    cout<<"[ ";
    for(const auto &row : vectIn){
        cout<<row<<' ';
    }
    cout<<']';
}


int main(){
    vector<vector<int>> result;
    for(int i=1;i<10;++i){
        for(int j=i+1;j<10;++j){
            for(int k=j+1;k<10;++k){
                vector<int> temp;
                temp.push_back(i);temp.push_back(j);temp.push_back(k);
                result.push_back(temp);
            }
        }
    }
    int i = 0;
    for(auto x:result){
        cout<<i++<<": ";print1DVector(x);cout<<endl;
    }

}


//0: [ 1 2 3 ]
//1: [ 1 2 4 ]
//2: [ 1 2 5 ]
//3: [ 1 2 6 ]
//4: [ 1 2 7 ]
//5: [ 1 2 8 ]
//6: [ 1 2 9 ]
//7: [ 1 3 4 ]
//8: [ 1 3 5 ]
//9: [ 1 3 6 ]
//10: [ 1 3 7 ]
//11: [ 1 3 8 ]
//12: [ 1 3 9 ]
//13: [ 1 4 5 ]
//14: [ 1 4 6 ]
//15: [ 1 4 7 ]
//16: [ 1 4 8 ]
//17: [ 1 4 9 ]
//18: [ 1 5 6 ]
//19: [ 1 5 7 ]
//20: [ 1 5 8 ]
//21: [ 1 5 9 ]
//22: [ 1 6 7 ]
//23: [ 1 6 8 ]
//24: [ 1 6 9 ]
//25: [ 1 7 8 ]
//26: [ 1 7 9 ]
//27: [ 1 8 9 ]
//28: [ 2 3 4 ]
//29: [ 2 3 5 ]
//30: [ 2 3 6 ]
//31: [ 2 3 7 ]
//32: [ 2 3 8 ]
//33: [ 2 3 9 ]
//34: [ 2 4 5 ]
//35: [ 2 4 6 ]
//36: [ 2 4 7 ]
//37: [ 2 4 8 ]
//38: [ 2 4 9 ]
//39: [ 2 5 6 ]
//40: [ 2 5 7 ]
//41: [ 2 5 8 ]
//42: [ 2 5 9 ]
//43: [ 2 6 7 ]
//44: [ 2 6 8 ]
//45: [ 2 6 9 ]
//46: [ 2 7 8 ]
//47: [ 2 7 9 ]
//48: [ 2 8 9 ]
//49: [ 3 4 5 ]
//50: [ 3 4 6 ]
//51: [ 3 4 7 ]
//52: [ 3 4 8 ]
//53: [ 3 4 9 ]
//54: [ 3 5 6 ]
//55: [ 3 5 7 ]
//56: [ 3 5 8 ]
//57: [ 3 5 9 ]
//58: [ 3 6 7 ]
//59: [ 3 6 8 ]
//60: [ 3 6 9 ]
//61: [ 3 7 8 ]
//62: [ 3 7 9 ]
//63: [ 3 8 9 ]
//64: [ 4 5 6 ]
//65: [ 4 5 7 ]
//66: [ 4 5 8 ]
//67: [ 4 5 9 ]
//68: [ 4 6 7 ]
//69: [ 4 6 8 ]
//70: [ 4 6 9 ]
//71: [ 4 7 8 ]
//72: [ 4 7 9 ]
//73: [ 4 8 9 ]
//74: [ 5 6 7 ]
//75: [ 5 6 8 ]
//76: [ 5 6 9 ]
//77: [ 5 7 8 ]
//78: [ 5 7 9 ]
//79: [ 5 8 9 ]
//80: [ 6 7 8 ]
//81: [ 6 7 9 ]
//82: [ 6 8 9 ]
//83: [ 7 8 9 ]