#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        while(n>1){
            if(n%2!=0) return false;
            n=n/2;
        }
        return n==1;
    }
};

int main(){
    Solution s;
    cout<<s.isPowerOfTwo(10)<<endl;
    cout<<s.isPowerOfTwo(16)<<endl;

}
