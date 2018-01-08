#include <vector>
#include <iostream>

// x^x = x
// x^0 = 0

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};

int main()
{
    vector<int> X = {2,2,10,3,3,5,5,7,7};
    Solution s;
    cout<<s.singleNumber(X);


}

// 10
