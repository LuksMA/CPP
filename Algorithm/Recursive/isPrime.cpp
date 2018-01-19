#include <iostream>

using namespace std;

bool factorInRange(int k, int n) {
    if(k >= n){
        return true;
    }else if( (n%k) == 0){
        return false;
    }else{
        return factorInRange(++k, n);
    }
}

bool isPrime(int n){
    return ((n>1) && factorInRange(2,n));
}



int main(){
    cout<<isPrime(5)<<endl;
    cout<<isPrime(16)<<endl;

}
