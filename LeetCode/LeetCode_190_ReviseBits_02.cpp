#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> x(n);

        bitset<32> y;

        int j = 31;
        for (int i = 0; i < 32; i++) {
            y[i] = x[j--];
        }

        return y.to_ulong();
    }
};

int main()
{
    uint32_t x= 43261596;
    Solution s;
    cout<<s.reverseBits(x);
}

//964176192
