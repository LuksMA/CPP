#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        int i = 0;
        while(i < s.size()){
            sum ^= s.at(i++);
        }
        i = 0;
        while(i < t.size()){
            sum ^= t.at(i++);
        }
        return (char)sum;
    }
};


int main(){
    Solution s;
    cout<<s.findTheDifference("abcd","abcde")<<endl;
}


