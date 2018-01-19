// GCD:  The greatest common divisor  of m and n
// Brute Force

#include <iostream>

using namespace std;

int tryGCD(int m, int n, int s){
    if((m%s==0) && (n%s==0)){
        return s;
    }else{
        return tryGCD(m, n, s-1);
    }
}

int GCD(int m, int n){
    return (m<n)?tryGCD(m,n,m):tryGCD(m,n,n);
}


int main(){
    cout<<GCD(18,36)<<endl;
    cout<<GCD(36,18)<<endl;
    cout<<GCD(40,24)<<endl;
}
