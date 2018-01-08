#include <vector>
#include <iostream>

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
    vector<int> X = {2,2,1,3,3,5,5,7,7};
    Solution s;
    cout<<s.singleNumber(X);

}

// 1
