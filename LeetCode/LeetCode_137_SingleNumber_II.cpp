#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;

        for (const auto& i : nums) {
            int new_one = (~i & one) | (i & ~one & ~two);
            int new_two = (~i & two) | (i & one);
            one = new_one, two = new_two;
        }

        return one;
    }
};

int main()
{
    vector<int> X = {2,2,2,10,3,3,3,5,5,5,7,7,7};
    Solution s;
    cout<<s.singleNumber(X);


}

// 10

