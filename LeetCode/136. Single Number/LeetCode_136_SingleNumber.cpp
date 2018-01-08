#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.cbegin(), nums.cend(),
                          0, std::bit_xor<int>());
    }
};



int main()
{
    vector<int> X = {2,2,1,3,3,5,5,7,7};
    Solution s;
    cout<<s.singleNumber(X);

}

// 1
