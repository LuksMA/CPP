#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        return accumulate(s.cbegin(), s.cend(), 0, std::bit_xor<int>()) ^
               accumulate(t.cbegin(), t.cend(), 0, std::bit_xor<int>());
    }
};


int main(){
    Solution s;
    cout<<s.findTheDifference("abcd","abcde")<<endl;
}


