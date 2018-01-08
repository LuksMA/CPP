#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int last = 0;

        while(n > 0)
        {
            last = n & 1;
            last == 1 ? count++: 0;
            n = n >> 1;
        }

        return count;
    }
};

int main()
{
    uint32_t x= 11;
    Solution s;
    cout<<s.hammingWeight(x);
}

// 3
