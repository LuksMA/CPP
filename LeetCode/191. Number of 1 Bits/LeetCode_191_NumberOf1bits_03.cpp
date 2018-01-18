#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while(n)
        {
            n = n &=(n-1);
            count++;
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
