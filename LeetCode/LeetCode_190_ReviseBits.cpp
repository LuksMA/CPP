#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int count = 32;
        while (count--) {
            result <<= 1;
            result |= n & 1;
            n >>= 1;
        }
        return result;
    }
};

int main()
{
    uint32_t x= 43261596;
    Solution s;
    cout<<s.reverseBits(x);
}

//964176192
