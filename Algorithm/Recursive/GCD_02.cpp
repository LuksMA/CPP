//Dijkstra's Algorithm
// If m>n, GCD(m,n) is the same as GCD(m-n,n).


#include <iostream>

using namespace std;



int GCD(int m, int n){
   if(m == n)
      return m;
   else if (m > n)
      return GCD(m-n, n);
   else
      return GCD(m, n-m);
}


int main(){
    cout<<GCD(18,36)<<endl;
    cout<<GCD(36,18)<<endl;
    cout<<GCD(40,24)<<endl;
}
