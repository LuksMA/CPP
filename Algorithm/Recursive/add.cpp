#include <iostream>

using namespace std;

int add(int x, int y){
    if(x == 0){
        return y;
    }else{
        return add(--x,++y);
    }
}

int main(){
    cout<<add(3,4); // 6
}
