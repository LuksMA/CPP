#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int carry = a & b;
            a ^= b;
            b = carry << 1;
        }
        return a;
    }
};

int main(){
    Solution s;
    cout<<s.getSum(1,2)<<endl;
}
