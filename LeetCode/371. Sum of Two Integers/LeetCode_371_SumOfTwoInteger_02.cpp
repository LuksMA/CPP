#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {

        int carry = 1;
        int sum = 0;
        while(carry)
        {
            sum = a ^ b;

            carry = a & b;

            carry <<= 1;

            a = sum;
            b = carry;
        }

        return sum;
    }
};


int main(){
    Solution s;
    cout<<s.getSum(1,2)<<endl;
}
