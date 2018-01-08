#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int lowbit = 0, highbit = 0;
        for (auto num: nums) {
            highbit ^= lowbit&num;
            lowbit ^= num;
            int mask = ~(lowbit&highbit);
            highbit &= mask;
            lowbit &= mask;
        }
        return lowbit;
    }
};

int main()
{
    vector<int> X = {2,2,2,10,3,3,3,5,5,5,7,7,7};
    Solution s;
    cout<<s.singleNumber(X);


}

// 10

